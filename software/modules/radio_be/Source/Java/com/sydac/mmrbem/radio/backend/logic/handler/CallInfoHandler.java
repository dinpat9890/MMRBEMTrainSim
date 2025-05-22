/*
 * ==================================================================
 * 
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.radio.backend.logic.handler;

import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import com.sydac.foundation.IPropertySetter;
import com.sydac.foundation.PropertyKey;
import com.sydac.mmrbem.radio.backend.comms.CommsBinding;
import com.sydac.mmrbem.radio.backend.logic.AbstractFunctionalLogic;
import com.sydac.mmrbem.radio.backend.logic.SharedDataModel;
import com.sydac.mmrbem.radio.backend.logic.annotation.FunctionalLogicHandler;
import com.sydac.mmrbem.radio.backend.radiointercom.io.models.IRadioIntercomOutputsModel;
import com.sydac.mmrbem.radio.backend.radiointercom.properties.IRadioIntercomInputProperties;
import com.sydac.mmrbem.radio.backend.radiointercom.properties.IRadioIntercomOutputProperties;
import com.sydac.mmrbem.radio.backend.vehicle.io.models.ICBTCOnboardOutputsModel;
import com.sydac.mmrbem.radio.backend.vehicle.io.models.properties.ICBTCOnboardOutputsProperties;
import com.sydac.mmrbem.radio.backend.vehicle.io.models.properties.IPISBEOutputsProperties;
import com.sydac.mmrbem.radio.common.data.ContactDO;
import com.sydac.mmrbem.radio.common.io.GroupName;
import com.sydac.mmrbem.radio.common.io.RadioPropertiesReader;
import com.sydac.mmrbem.radio.common.io.XMLParser;
import com.sydac.mmrbem.radio.common.io.properties.IAppInputsCallRequestAndNavigationPanelProperties;
import com.sydac.mmrbem.radio.common.io.properties.IAppOutputCallInfoProperties;
import com.sydac.mmrbem.radio.common.state.ApplicationConstants;
import com.sydac.mmrbem.radio.common.state.CallGroup;
import com.sydac.mmrbem.radio.common.state.CallType;

/**
 * This handler class is used for call request and navigation logic
 * 
 * @author ext-tambet
 *
 */
@Service
@FunctionalLogicHandler(arguments = { CommsBinding.class, SharedDataModel.class })
public class CallInfoHandler extends AbstractFunctionalLogic
{
  private XMLParser routeParser;

  private List<ContactDO> groupList = new ArrayList<>();

  @Autowired
  private SharedDataModel sharedDataModel;

  private CommsBinding commsBinding;

  private List<ContactDO> contactList = new ArrayList<>();

  private ICBTCOnboardOutputsModel cbtcOutputModel;
  
  int routeId;
  
  @Autowired
  private StartupSequenceHandler startupSequenceHandler;

  public CallInfoHandler(CommsBinding commsBinding)
  {
    super(commsBinding, IRadioIntercomOutputProperties.class, IPISBEOutputsProperties.class,
        ICBTCOnboardOutputsProperties.class, IAppInputsCallRequestAndNavigationPanelProperties.class);
    this.commsBinding = commsBinding;
    routeParser = new XMLParser();
    initMessageList();
  }

  @Override
  public <T> void radioIntercomOutputPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue,
      Integer vehicleIndex)
  {

    if (vehicleIndex == getActiveVehicleIndex())
    {
      setApplicationOutputsProperty(IAppOutputCallInfoProperties.INPUT_SSI_ID,
          getActiveVehicleIndex() == 0 ? getActiveVehicleIndex() : 1);

      Integer newVal = (Integer)newValue;
      if (IRadioIntercomOutputProperties.RADIO_INTERCOM_STATE.equals(key))
      {
        setApplicationOutputsProperty(IAppOutputCallInfoProperties.CALL_GROUP_STATUS, newVal);
      }
      else if (IRadioIntercomOutputProperties.SELECTED_RADIO_CALL_TYPE.equals(key)
          || IRadioIntercomOutputProperties.SELECTED_RADIO_GROUP_CALL.equals(key))
      {
        IRadioIntercomOutputsModel model = (IRadioIntercomOutputsModel)getRadioIntercomOutputsModels(
            getActiveVehicleIndex());

        if (model.getSelectedRadioGroupCall() == 0)
        {
          if (model.getCabScc() == 1)
          {
            setCallingText(model.getSelectedRadioDialledNo());

            setApplicationOutputsProperty(IAppOutputCallInfoProperties.INCOMING_CALL_TYPE,
                model.getSelectedRadioCallType());
          }
          else
          {
            setApplicationOutputsProperty(IAppOutputCallInfoProperties.INCOMING_CALL_NAME,
                CallType.valueOf(model.getSelectedRadioCallType()).getText().getBytes());

            setApplicationOutputsProperty(IAppOutputCallInfoProperties.INCOMING_CALL_TYPE,
                model.getSelectedRadioCallType());
          }
        }
        else
        {
          setApplicationOutputsProperty(IAppOutputCallInfoProperties.INCOMING_CALL_NAME,
              CallGroup.valueOf(model.getSelectedRadioGroupCall()).getText().getBytes());
        }

      }
      else if (IRadioIntercomOutputProperties.SELECTED_RADIO_DIALLED_NO.equals(key))
      {

        setApplicationOutputsProperty(IAppOutputCallInfoProperties.CALL_SSI_ID, newVal);

      }
    }
  }

  @Override
  public <T> void pisBeOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue, int vehicleIndex)
  {
    if (IPISBEOutputsProperties.SELECTED_ROUTE_ID_PSD.equals(key) && (Integer)newValue > 0)
    {
      routeId = (Integer)newValue;
      updateLine(routeId);
    }
  }

  @Override
  public <T> void cbtcOnboardOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue,
      int vehicleIndex)
  {
    initalizeCbtcOutputModel();

    if (getActiveVehicleIndex() == vehicleIndex)
    {
      if (key.equals(ICBTCOnboardOutputsProperties.DEPOT_INDICATION))
      {

        setApplicationOutputsProperty(IAppOutputCallInfoProperties.DEPOT_INDICATION, (Integer)newValue);

      }
    }
  }

  /**
   * Get the route Code from route id .Based on the routecode set the screenId
   * 
   * @param routeId
   */
  private void updateLine(int routeId)
  {
    if (routeId > 0)
    {
      String lineCode = routeParser.getLineCode(routeId);
      if (lineCode != null && !lineCode.trim().isEmpty())
      {
        String groupName = GroupName.valueByRouteCode(lineCode).getName();
        setApplicationOutputsProperty(IAppOutputCallInfoProperties.CALL_GROUP_NAME, groupName.getBytes());
      }
    }
  }

  private void initMessageList()
  {

    groupList = RadioPropertiesReader.getInstance().getGroupsMap().entrySet().stream()
        .map(m -> new ContactDO(m.getValue().getContactText(), m.getKey())).collect(Collectors.toList());

    contactList = RadioPropertiesReader.getInstance().getContactsMap().entrySet().stream()
        .map(m -> new ContactDO(m.getValue().getContactText(), m.getKey())).collect(Collectors.toList());

  }

  private String getContactIdText(int contactId, List<ContactDO> contactList)
  {
    String contactText = null;
    ContactDO contact = contactList.stream().filter(m -> m.getContactId() == contactId).findFirst()
        .orElse(null);
    if (contact != null)
    {
      contactText = contact.getContactText();

    }
    return contactText;
  }

  /**
   * If calling from Contact Screen ,this method helps to set the caller text.
   * 
   * @param dialledNo
   *          dialed number
   */
  public void setCallingText(int dialledNo)
  {
    String contactText = null;
    if (sharedDataModel.getCallCatagory() == ApplicationConstants.GROUP_BTN)
    {
      contactText = getContactIdText(dialledNo, groupList);
    }
    else if (sharedDataModel.getCallCatagory() == ApplicationConstants.CONTACT_BTN)
    {
      contactText = getContactIdText(dialledNo, contactList);
    }

    if (contactText != null && !contactText.trim().isEmpty())
    {

      setApplicationOutputsProperty(IAppOutputCallInfoProperties.INCOMING_CALL_NAME, contactText.getBytes());
    }
    else
    {
      setApplicationOutputsProperty(IAppOutputCallInfoProperties.INCOMING_CALL_NAME,
          String.valueOf(dialledNo).getBytes());
    }
  }

  private void initalizeCbtcOutputModel()
  {
    if (this.cbtcOutputModel == null)
    {

      this.cbtcOutputModel = (ICBTCOnboardOutputsModel)commsBinding.getCbtcOnboardOutputsModels()
          .get(getActiveVehicleIndex());
    }

  }

  
  @Override
  public <T> void appInputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue, int vehicleIndex)
  {

    if (vehicleIndex == getActiveVehicleIndex() && (Integer)newValue > 0
        && startupSequenceHandler.isRadioPowerOn())
    {
   

      if (IAppInputsCallRequestAndNavigationPanelProperties.MAIN_GROUP_BTN_REQUEST.equals(key))
      {
        updateLine(routeId);
      }
      else if (IAppInputsCallRequestAndNavigationPanelProperties.DEPOT_GROUP_BTN_REQUEST.equals(key))
      {
       
        setApplicationOutputsProperty(IAppOutputCallInfoProperties.CALL_GROUP_NAME,  GroupName.ROUTE_DEPOT.getName().getBytes());
      }
    }
  }
}

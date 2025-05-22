/*
 * ==================================================================
 * 
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.papis.backend.logic.handler;

import java.util.List;

import org.springframework.stereotype.Service;

import com.sydac.foundation.IPropertySetter;
import com.sydac.foundation.PropertyKey;
import com.sydac.mmrbem.papis.backend.comms.CommsBinding;
import com.sydac.mmrbem.papis.backend.logic.AbstractFunctionalLogic;
import com.sydac.mmrbem.papis.backend.logic.SharedDataModel;
import com.sydac.mmrbem.papis.backend.logic.annotation.FunctionalLogicHandler;
import com.sydac.mmrbem.papis.backend.vehicle.io.properties.IPISBEInputsEmgInfoScreenProperties;
import com.sydac.mmrbem.papis.backend.vehicle.io.properties.IPISBEInputsProperties;
import com.sydac.mmrbem.papis.common.ScreenId;
import com.sydac.mmrbem.papis.common.data.EmergencyInfoDetailModel;
import com.sydac.mmrbem.papis.common.io.properties.IAppInputsEmergencyInformationScreenProperties;
import com.sydac.mmrbem.papis.common.io.properties.IAppInputsPassengerAlarmScreenProperties;
import com.sydac.mmrbem.papis.common.io.properties.IAppInputsProperties;
import com.sydac.mmrbem.papis.common.io.properties.IAppInputsScreenChangeProperties;
import com.sydac.mmrbem.papis.common.io.properties.IAppOutputsCommonProperties;
import com.sydac.mmrbem.papis.common.io.properties.IAppOutputsEmergencyInformationScreenProperties;
import com.sydac.mmrbem.papis.common.io.properties.XMLParser;
import com.sydac.mmrbem.papis.common.protos.PAPISProtos;
import com.sydac.mmrbem.papis.common.state.ApplicationConstants;

import javafx.beans.property.ListProperty;
import javafx.beans.property.SimpleListProperty;
import javafx.collections.FXCollections;

/**
 * This handler class is used for Emergency Information Handling
 * 
 */
@Service
@FunctionalLogicHandler(arguments = { CommsBinding.class, SharedDataModel.class })
public class EmergencyInformationScreenHandler extends AbstractFunctionalLogic
    implements IScreenChangeListener
{

  CommsBinding commsBinding;

  private XMLParser xmlParser;

  SharedDataModel sharedDataModel;

  private int startIndex = 0;

  private int endIndex = 0;

  private int listSizePerPage = 8;

  private int emergencyInformationIndex = 0;

  private int selectedSpcEmgInfoId;

  private ListProperty<EmergencyInfoDetailModel> emgInfoList = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  protected EmergencyInformationScreenHandler(CommsBinding commsBinding, Class<?>[] propertyKeyDefinitions,
      SharedDataModel sharedDataModel)
  {
    super(commsBinding, IAppInputsProperties.class, IPISBEInputsProperties.class);
    this.commsBinding = commsBinding;
    this.sharedDataModel = sharedDataModel;
    xmlParser = new XMLParser();
  }

  @Override
  public <T> void appInputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue, int vehicleIndex)
  {
    IPropertySetter propertySetter = getPISBEInputsSetter(vehicleIndex);
    if (sharedDataModel.getScreenId() == ScreenId.EMERGENCY_INFORMATION_SCREEN.getId())
    {
      if (IAppInputsScreenChangeProperties.SCREEN_CHANGE_REQUEST.equals(key))
      {
        updateEmgInfoList();
      }
      else if (IAppInputsEmergencyInformationScreenProperties.EMG_INFO_ID_REQ.equals(key)
          && (Integer)newValue > -1)
      {
        selectedSpcEmgInfoId = (Integer)newValue;

      }
      else if (IAppInputsEmergencyInformationScreenProperties.EMG_INFO_SCREEN_OK_BUTTON_PRESSED.equals(key)
          && (Integer)newValue > -1)
      {
        setInputData(propertySetter, IPISBEInputsEmgInfoScreenProperties.EMERGENCY_ANNOUNCEMNT_ID,
            selectedSpcEmgInfoId);
      }
      else if (IAppInputsEmergencyInformationScreenProperties.EMG_INFO_NO_OF_TIMES.equals(key)
          && (Integer)newValue > 0)
      {
        int noOfTimesPlayed = (Integer)newValue;
        setInputData(propertySetter, IPISBEInputsEmgInfoScreenProperties.EMERGENCY_ANNONCMNT_COUNT,
            noOfTimesPlayed);
      }
      else if (IAppInputsEmergencyInformationScreenProperties.EMG_INFO_SCREEN_UP_BUTTON_PRESSED.equals(key)
          && (Integer)newValue > 0)
      {
        prevPage();
      }
      else if (IAppInputsEmergencyInformationScreenProperties.EMG_INFO_SCREEN_DOWN_BUTTON_PRESSED.equals(key)
          && (Integer)newValue > 0)
      {
        nextPage();
      }
      else if (IAppInputsEmergencyInformationScreenProperties.EMG_INFO_SCREEN_STOP_BUTTON_PRESSED.equals(key))
      {
        setInputData(propertySetter, IPISBEInputsEmgInfoScreenProperties.STOP_EMERGENCY_ANNOUNCEMNT,
            (Integer)newValue);
        setInputData(propertySetter, IPISBEInputsEmgInfoScreenProperties.EMERGENCY_ANNOUNCEMNT_ID, 0);
      }
      else if (IAppInputsPassengerAlarmScreenProperties.UP_ARROW_BUTTON.equals(key) && (Integer)newValue > 0)
      {
        decrementCounterMethod();
      }
      else if (IAppInputsPassengerAlarmScreenProperties.DOWN_ARROW_BUTTON.equals(key)
          && (Integer)newValue > 0)
      {
        incrementCounterMethod();
      }
      else if (IAppInputsEmergencyInformationScreenProperties.CURRENT_EMERGENCY_MESSAGE.equals(key)
          && (Integer)newValue > 0)
      {
        emergencyInformationIndex = (Integer)newValue;
      }
    }
  }

  private void decrementCounterMethod()
  {
    if (emergencyInformationIndex > 0)
    {
      emergencyInformationIndex--;

    }
    else if (startIndex != 0)
    {
      emergencyInformationIndex = listSizePerPage - 1;
      prevPage();

    }
    setApplicationOutputsProperty(IAppOutputsCommonProperties.EMERGENCY_MESSAGE_SELECTED,
        emergencyInformationIndex);
  }

  private void incrementCounterMethod()
  {
    if (emergencyInformationIndex == listSizePerPage - 1)
    {
      emergencyInformationIndex = 0;
      nextPage();
    }
    else if (emergencyInformationIndex < emgInfoList.size() - 1)
    {
      emergencyInformationIndex++;
    }
    setApplicationOutputsProperty(IAppOutputsCommonProperties.EMERGENCY_MESSAGE_SELECTED,
        emergencyInformationIndex);
  }

  private List<EmergencyInfoDetailModel> getEmgInfoList()
  {
    return xmlParser.getEmgInfoList();
  }

  private void updateEmgInfoList()
  {
    startIndex = 0;
    endIndex = 0;
    if (getEmgInfoList() == null || getEmgInfoList().isEmpty())
    {
      setList();
    }
    else
    {
      if (getEmgInfoList().size() < listSizePerPage)
      {
        endIndex = getEmgInfoList().size();
      }
      else
      {
        endIndex = endIndex + listSizePerPage;
        // set Down Button enabled
      }
      setList();
    }
  }

  private void nextPage()
  {
    endIndex = endIndex + listSizePerPage;
    if (getEmgInfoList().size() < endIndex)
    {
      endIndex = getEmgInfoList().size();
      if (startIndex + listSizePerPage < endIndex)
      {
        startIndex = startIndex + listSizePerPage;
      }
      // Down Btn disabled
    }
    else
    {
      startIndex = startIndex + listSizePerPage;
    }
    // Up Button enabled
    setList();
  }

  private void prevPage()
  {
    if (startIndex > 0)
    {
      endIndex = startIndex;
      startIndex = startIndex - listSizePerPage;
    }
    else
    {
      // Up Btn disabled
    }
    setList();
  }

  private void setList()
  {
    PAPISProtos.EmgInfoList.Builder emgInfoListBuilder = PAPISProtos.EmgInfoList.newBuilder();
    this.emgInfoList.clear();
    for (int i = startIndex; i < endIndex; i++)
    {
      this.emgInfoList.add(getEmgInfoList().get(i));
    }
    for (EmergencyInfoDetailModel emgInfo : this.emgInfoList)
    {
      PAPISProtos.EmgInfoList.EmgInfoDetail.Builder emgInfoDetail = PAPISProtos.EmgInfoList.EmgInfoDetail
          .newBuilder();
      emgInfoDetail.setEmgInfoId(emgInfo.getEmgInfoId());
      emgInfoDetail.setEmgInfoCode(emgInfo.getEmgInfoCode());
      emgInfoListBuilder.addEmgInfoDetail(emgInfoDetail);
    }
    setApplicationOutputsProperty(IAppOutputsEmergencyInformationScreenProperties.EMG_INFO_LIST,
        emgInfoListBuilder.build().toByteArray());
  }

  @Override
  public void onEnteringScreen(int screenId)
  {
    emergencyInformationIndex = ApplicationConstants.RESET_SELECTED_INDEX;

  }

  @Override
  public void onLeavingScreen(int screenId)
  {
    // No Action Required
  }
}

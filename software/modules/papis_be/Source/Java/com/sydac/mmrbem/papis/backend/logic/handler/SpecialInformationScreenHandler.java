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
import com.sydac.mmrbem.papis.backend.vehicle.io.properties.IPISBEInputsProperties;
import com.sydac.mmrbem.papis.backend.vehicle.io.properties.IPISBEInputsSpcInfoScreenProperties;
import com.sydac.mmrbem.papis.common.ScreenId;
import com.sydac.mmrbem.papis.common.data.SpecialInfoDetailModel;
import com.sydac.mmrbem.papis.common.io.properties.IAppInputsPassengerAlarmScreenProperties;
import com.sydac.mmrbem.papis.common.io.properties.IAppInputsProperties;
import com.sydac.mmrbem.papis.common.io.properties.IAppInputsScreenChangeProperties;
import com.sydac.mmrbem.papis.common.io.properties.IAppInputsSpecialInformationScreenProperties;
import com.sydac.mmrbem.papis.common.io.properties.IAppOutputsCommonProperties;
import com.sydac.mmrbem.papis.common.io.properties.IAppOutputsSpecialInformationScreenProperties;
import com.sydac.mmrbem.papis.common.io.properties.XMLParser;
import com.sydac.mmrbem.papis.common.protos.PAPISProtos;
import com.sydac.mmrbem.papis.common.state.ApplicationConstants;

import javafx.beans.property.ListProperty;
import javafx.beans.property.SimpleListProperty;
import javafx.collections.FXCollections;

/**
 * This handler class is used for Special Information Handling
 * 
 */
@Service
@FunctionalLogicHandler(arguments = { CommsBinding.class, SharedDataModel.class })
public class SpecialInformationScreenHandler extends AbstractFunctionalLogic implements IScreenChangeListener
{

  CommsBinding commsBinding;

  SharedDataModel sharedDataModel;

  private XMLParser xmlParser;

  private int startIndex = 0;

  private int endIndex = 0;

  private int listSizePerPage = 8;

  private int specialInformationIndex = 0;

  private int selectedSpcInfoId;

  private ListProperty<SpecialInfoDetailModel> spcInfoList = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  protected SpecialInformationScreenHandler(CommsBinding commsBinding, SharedDataModel sharedDataModel)
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
    if (sharedDataModel.getScreenId() == ScreenId.SPECIAL_INFORMATION_SCREEN.getId())
    {
      if (IAppInputsScreenChangeProperties.SCREEN_CHANGE_REQUEST.equals(key))
      {
        updateSpcInfoList();
      }
      else if (IAppInputsSpecialInformationScreenProperties.SPC_INFO_ID_REQ.equals(key)
          && (Integer)newValue > -1)
      {
        selectedSpcInfoId = (Integer)newValue;
      }
      else if (IAppInputsSpecialInformationScreenProperties.SPC_INFO_SCREEN_OK_BUTTON_PRESSED.equals(key)
          && (Integer)newValue > -1)
      {
        setInputData(propertySetter, IPISBEInputsSpcInfoScreenProperties.SPECIAL_ANNOUNCEMNT_ID,
            selectedSpcInfoId);
      }
      else if (IAppInputsSpecialInformationScreenProperties.SPC_INFO_NO_OF_TIMES.equals(key)
          && (Integer)newValue > 0)
      {
        int noOfTimesPlayed = (Integer)newValue;
        setInputData(propertySetter, IPISBEInputsSpcInfoScreenProperties.SPECIAL_ANNONCMNT_COUNT,
            noOfTimesPlayed);
      }
      else if (IAppInputsSpecialInformationScreenProperties.SPC_INFO_SCREEN_UP_BUTTON_PRESSED.equals(key)
          && (Integer)newValue > 0)
      {
        prevPage();
      }
      else if (IAppInputsSpecialInformationScreenProperties.SPC_INFO_SCREEN_DOWN_BUTTON_PRESSED.equals(key)
          && (Integer)newValue > 0)
      {
        nextPage();
      }
      else if (IAppInputsSpecialInformationScreenProperties.SPC_INFO_SCREEN_STOP_BUTTON_PRESSED.equals(key))
      {
        setInputData(propertySetter, IPISBEInputsSpcInfoScreenProperties.STOP_SPECIAL_ANNOUNCEMNT,
            (Integer)newValue);
        setInputData(propertySetter, IPISBEInputsSpcInfoScreenProperties.SPECIAL_ANNOUNCEMNT_ID, 0);
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
      else if (IAppInputsSpecialInformationScreenProperties.CURRENT_SPECIAL_MESSAGE.equals(key)
          && (Integer)newValue > 0)
      {
        specialInformationIndex = (Integer)newValue;
      }
    }
  }

  private void decrementCounterMethod()
  {
    if (specialInformationIndex > 0)
    {
      specialInformationIndex--;

    }
    else if (startIndex != 0)
    {
      specialInformationIndex = listSizePerPage - 1;
      prevPage();

    }
    setApplicationOutputsProperty(IAppOutputsCommonProperties.SPECIAL_MESSAGE_SELECTED,
        specialInformationIndex);
  }

  private void incrementCounterMethod()
  {
    if (specialInformationIndex == listSizePerPage - 1)
    {
      specialInformationIndex = 0;
      nextPage();
    }
    else if (specialInformationIndex < spcInfoList.size() - 1)
    {
      specialInformationIndex++;
    }
    setApplicationOutputsProperty(IAppOutputsCommonProperties.SPECIAL_MESSAGE_SELECTED,
        specialInformationIndex);
  }

  private List<SpecialInfoDetailModel> getSpcInfoList()
  {
    return xmlParser.getSpcInfoList();
  }

  private void updateSpcInfoList()
  {
    startIndex = 0;
    endIndex = 0;
    if (getSpcInfoList() == null || getSpcInfoList().isEmpty())
    {
      setList();
    }
    else
    {
      if (getSpcInfoList().size() < listSizePerPage)
      {
        endIndex = getSpcInfoList().size();
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
    if (getSpcInfoList().size() < endIndex)
    {
      endIndex = getSpcInfoList().size();
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
    PAPISProtos.SpcInfoList.Builder spcInfoListBuilder = PAPISProtos.SpcInfoList.newBuilder();
    this.spcInfoList.clear();
    for (int i = startIndex; i < endIndex; i++)
    {
      this.spcInfoList.add(getSpcInfoList().get(i));
    }
    for (SpecialInfoDetailModel spcInfo : this.spcInfoList)
    {
      PAPISProtos.SpcInfoList.SpcInfoDetail.Builder spcInfoDetail = PAPISProtos.SpcInfoList.SpcInfoDetail
          .newBuilder();
      spcInfoDetail.setSpcInfoId(spcInfo.getSpecialInfoId());
      spcInfoDetail.setSpcInfoCode(spcInfo.getSpecialInfoCode());
      spcInfoListBuilder.addSpcInfoDetail(spcInfoDetail);
    }
    setApplicationOutputsProperty(IAppOutputsSpecialInformationScreenProperties.SPC_INFO_LIST,
        spcInfoListBuilder.build().toByteArray());
  }

  @Override
  public void onEnteringScreen(int screenId)
  {
    specialInformationIndex = ApplicationConstants.RESET_SELECTED_INDEX;

  }

  @Override
  public void onLeavingScreen(int screenId)
  {
    // No Action Required
  }
}

/*
 * ==================================================================
 * (C)Copyright 2023 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * ==================================================================
 */
package com.sydac.mmrbem.tcms.backend.logic.handler;

import java.util.HashMap;
import java.util.Map;
import java.util.Objects;

import org.springframework.stereotype.Service;

import com.sydac.foundation.PropertyKey;
import com.sydac.mmrbem.tcms.backend.app.io.handlers.IAppOutputsEventDisplayAreaHandler;
import com.sydac.mmrbem.tcms.backend.app.io.handlers.IAppOutputsFaultDetailsScreenHandler;
import com.sydac.mmrbem.tcms.backend.app.io.handlers.IAppOutputsLoggedFaultsScreenHandler;
import com.sydac.mmrbem.tcms.backend.comms.CommsBinding;
import com.sydac.mmrbem.tcms.backend.logic.AbstractFunctionalLogic;
import com.sydac.mmrbem.tcms.backend.logic.DateTimeModel;
import com.sydac.mmrbem.tcms.backend.logic.SharedDataModel;
import com.sydac.mmrbem.tcms.backend.logic.annotation.FunctionalLogicHandler;
import com.sydac.mmrbem.tcms.backend.vehicle.io.properties.IEventProperties;
import com.sydac.mmrbem.tcms.backend.vehicle.io.properties.ITCMSVehicleOutputsActiveFaultsScreenProperties;
import com.sydac.mmrbem.tcms.common.ScreenId;
import com.sydac.mmrbem.tcms.common.data.TCMSEventsDO;
import com.sydac.mmrbem.tcms.common.io.TCMSEventsPropertiesReader;
import com.sydac.mmrbem.tcms.common.io.properties.IAppInputsLoggedFaultsScreenProperties;
import com.sydac.mmrbem.tcms.common.io.properties.IAppInputsProperties;
import com.sydac.mmrbem.tcms.common.io.properties.IAppInputsScreenChangeProperties;
import com.sydac.mmrbem.tcms.common.io.properties.IAppOutputsFaultDetailsScreenProperties;
import com.sydac.mmrbem.tcms.common.io.properties.IAppOutputsLoggedFaultsScreenProperties;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.ActiveFaultsList;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.LoggedFaultsList;
import com.sydac.mmrbem.tcms.common.state.ActiveFaultsCarFilterEnum;
import com.sydac.mmrbem.tcms.common.state.ActiveFaultsPriorityFilterEnum;
import com.sydac.mmrbem.tcms.common.state.ActiveFaultsSystemFilterEnum;
import com.sydac.mmrbem.tcms.common.state.ApplicationConstants;
import com.sydac.mmrbem.tcms.common.state.CarType;
import com.sydac.mmrbem.tcms.common.state.TCMSConstants;

import javafx.beans.property.ListProperty;
import javafx.beans.property.SimpleListProperty;
import javafx.collections.FXCollections;

/**
 * This handler class is used for handling Logged Faults screen data
 * 
 */
@Service
@FunctionalLogicHandler(arguments = { CommsBinding.class })
public class LoggedFaultsLogicHandler extends AbstractFunctionalLogic
{
  private LoggedFaultsList.Builder builder;

  private ActiveFaultsList.Builder faultDetailBuilder;

  private IAppOutputsLoggedFaultsScreenHandler appOutputsActiveFaultsScreenHandler;

  private IAppOutputsEventDisplayAreaHandler eventDisplayAreaHandler;

  private IAppOutputsFaultDetailsScreenHandler faultDetailsScreenHandler;

  private CommsBinding commsBinding;

  private SharedDataModel sharedDataModel;

  private int numberOfData = 10;

  private int totalPage = 0;

  private int currentPage = 1;

  private int startIndex = 0;

  private int endIndex = 0;

  private int messageIndex = 0;

  private int resetValue = -1;

  private ActiveFaultsSystemFilterEnum appliedSystemFilter = ActiveFaultsSystemFilterEnum.ANY;

  private ActiveFaultsCarFilterEnum appliedCarFilter = ActiveFaultsCarFilterEnum.ANY;

  private ActiveFaultsPriorityFilterEnum appliedPriorityFilter = ActiveFaultsPriorityFilterEnum.ANY;

  private Map<Integer, TCMSEventsDO> eventsMap;

  private Map<Integer, TCMSEventsDO> eventIndexFaultMap = new HashMap<>();

  private ListProperty<TCMSEventsDO> currentFaultDOList = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  private ListProperty<TCMSEventsDO> currentFaultDOSubList = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  private ListProperty<TCMSEventsDO> filteredFaultList = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  private ListProperty<TCMSEventsDO> activeFaultDOSubList = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  protected LoggedFaultsLogicHandler(CommsBinding commsBinding, SharedDataModel sharedDataModel)
  {
    super(commsBinding, ITCMSVehicleOutputsActiveFaultsScreenProperties.class, IEventProperties.class,
        IAppInputsProperties.class);
    this.commsBinding = commsBinding;
    this.sharedDataModel = sharedDataModel;
    initializeAppOutputHandler();
    this.eventsMap = TCMSEventsPropertiesReader.getInstance().getEventsMap();
  }

  @Override
  public <T> void appInputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue, int vehicleIndex)
  {
    if (IAppInputsLoggedFaultsScreenProperties.LOGGED_FAULTS_PAGE_DOWN_BUTTON_REQUEST.equals(key)
        && (Integer)newValue > 0)
    {
      updateNewPage();
    }
    else if (IAppInputsLoggedFaultsScreenProperties.LOGGED_FAULTS_PAGE_UP_BUTTON_REQUEST.equals(key)
        && (Integer)newValue > 0)
    {
      backToOld();
    }
    else if (IAppInputsScreenChangeProperties.TCMS_SCREEN_CHANGE_REQUEST.equals(key))
    {
      if ((Integer)newValue == ScreenId.LOGGED_FAULTS_SCREEN.getId())
      {
        appOutputsActiveFaultsScreenHandler.setLoggedFaultsStatus(updateCurrentFaultStatus());
      }
    }
    else if (IAppInputsLoggedFaultsScreenProperties.LOGGED_FAULT_LIST_SELECTED_INDEX.equals(key)
        && (Integer)newValue > 0)
    {
      faultDetailsScreenHandler.setFaultDetailsInfo(updateFaultDetail((Integer)newValue));
      setApplicationOutputsProperty(
          IAppOutputsFaultDetailsScreenProperties.PREVIOUS_SCREEN_ID_TO_FAULT_DETAILS,
          ScreenId.LOGGED_FAULTS_SCREEN.getId());
    }
    else if (IAppInputsLoggedFaultsScreenProperties.LOGGED_FAULTS_SYSTEM_FILTER_BUTTON_REQUEST.equals(key)
        && (Integer)newValue > resetValue)
    {
      appliedSystemFilter = ActiveFaultsSystemFilterEnum.valueOf((Integer)newValue);
      appOutputsActiveFaultsScreenHandler.setLoggedFaultsStatus(updateCurrentFaultStatus());
      setApplicationOutputsProperty(IAppOutputsLoggedFaultsScreenProperties.LOGGED_FAULT_SYS_FILTER_APPLIED,
          appliedSystemFilter.getSysFilterId());
    }
    else if (IAppInputsLoggedFaultsScreenProperties.LOGGED_FAULTS_CAR_FILTER_BUTTON_REQUEST.equals(key)
        && (Integer)newValue > resetValue)
    {
      appliedCarFilter = ActiveFaultsCarFilterEnum.valueOf((Integer)newValue);
      appOutputsActiveFaultsScreenHandler.setLoggedFaultsStatus(updateCurrentFaultStatus());
      setApplicationOutputsProperty(IAppOutputsLoggedFaultsScreenProperties.LOGGED_FAULT_CAR_FILTER_APPLIED,
          appliedCarFilter.getCarFilterId());
    }
    else if (IAppInputsLoggedFaultsScreenProperties.LOGGED_FAULTS_PRIORITY_FILTER_BUTTON_REQUEST.equals(key)
        && (Integer)newValue > resetValue)
    {
      appliedPriorityFilter = ActiveFaultsPriorityFilterEnum.valueOf((Integer)newValue);
      appOutputsActiveFaultsScreenHandler.setLoggedFaultsStatus(updateCurrentFaultStatus());
      setApplicationOutputsProperty(
          IAppOutputsLoggedFaultsScreenProperties.LOGGED_FAULT_PRIORITY_FILTER_APPLIED,
          appliedPriorityFilter.getPriorityFilterId());
    }
  }

  @Override
  public <T> void eventsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue, int vehicleIndex,
      int eventIndex)
  {
    initializeAppOutputHandler();
    if (IEventProperties.MESSAGE_ID.equals(key) && (Integer)newValue > 0)
    {
      for (Map.Entry<Integer, TCMSEventsDO> entry : eventsMap.entrySet())
      {
        if (entry.getValue().getFaultId().equals(newValue)
            && ((entry.getValue().getFaultVehicleId() == vehicleIndex + 1)
                || (entry.getValue().getFaultVehicleId() == 0)))
        {
          this.eventIndexFaultMap.put(eventIndex, entry.getValue());
        }
      }
    }
    else if (IEventProperties.MESSAGE_STATUS.equals(key))
    {
      handleFaultUpdate((Integer)newValue, eventIndex);
    }
  }

  private void handleFaultUpdate(Integer status, Integer eventIndex)
  {
    TCMSEventsDO eventDO = this.eventIndexFaultMap.get(eventIndex);
    if (eventDO != null)
    {
      if (status != 0)
      {
        eventDO.setActive(true);
        eventDO.setEventTime(DateTimeModel.getInstance().getTime());
        eventDO.setOccuranceCount(eventDO.getOccuranceCount() == null ? 0 : eventDO.getOccuranceCount() + 1);
        eventDO.setEventResolutionTime(null);
        this.currentFaultDOList.add(eventDO);
      }
      else
      {
        TCMSEventsDO tcmsEventsDO = new TCMSEventsDO(eventDO);
        eventDO.setActive(false);
        eventDO.setAcknowledged(false);
        this.currentFaultDOList.remove(eventDO);
        tcmsEventsDO.setEventResolutionTime(DateTimeModel.getInstance().getTime());
        this.currentFaultDOList.add(tcmsEventsDO);
      }
      setApplicationOutputsProperty(IAppOutputsLoggedFaultsScreenProperties.NO_OF_LOGGED_FAULTS,
          getCurrentFaultDOList().size());
    }
  }

  private void currentFaultTotalPage(int checkSize)
  {
    totalPage = (checkSize - 1) / numberOfData;
    setApplicationOutputsProperty(IAppOutputsLoggedFaultsScreenProperties.NO_OF_LOGGED_FAULTS_PAGE,
        totalPage + 1);
    setApplicationOutputsProperty(IAppOutputsLoggedFaultsScreenProperties.CURRENT_LOGGED_FAULTS_PAGE,
        currentPage);
    if (totalPage == 0 && currentPage == 1)
    {
      setApplicationOutputsProperty(IAppOutputsLoggedFaultsScreenProperties.LOGGED_FAULT_PAGE_UP_ACTIVE,
          TCMSConstants.NOT_ACTIVE);
      setApplicationOutputsProperty(IAppOutputsLoggedFaultsScreenProperties.LOGGED_FAULT_PAGE_DOWN_ACTIVE,
          TCMSConstants.NOT_ACTIVE);
    }
    else
    {
      if (currentPage <= totalPage)
      {
        setApplicationOutputsProperty(IAppOutputsLoggedFaultsScreenProperties.LOGGED_FAULT_PAGE_DOWN_ACTIVE,
            TCMSConstants.ACTIVE);
      }
      else
      {
        setApplicationOutputsProperty(IAppOutputsLoggedFaultsScreenProperties.LOGGED_FAULT_PAGE_DOWN_ACTIVE,
            TCMSConstants.NOT_ACTIVE);
      }
      if (currentPage == 1)
      {
        setApplicationOutputsProperty(IAppOutputsLoggedFaultsScreenProperties.LOGGED_FAULT_PAGE_UP_ACTIVE,
            TCMSConstants.NOT_ACTIVE);
      }
      else
      {
        setApplicationOutputsProperty(IAppOutputsLoggedFaultsScreenProperties.LOGGED_FAULT_PAGE_UP_ACTIVE,
            TCMSConstants.ACTIVE);
      }
    }
  }

  private void updateNewPage()
  {
    if (currentFaultDOSubList.size() > numberOfData)
    {
      if (currentPage == totalPage + 1)
      {
        if (startIndex + numberOfData < currentFaultDOSubList.size())
        {
          startIndex = startIndex + numberOfData;
          endIndex = currentFaultDOSubList.size();
        }
      }
      else if (currentPage < totalPage + 1)
      {
        currentPage++;
        startIndex = startIndex + numberOfData;
        endIndex = endIndex + numberOfData;
      }
    }
    setApplicationOutputsProperty(IAppOutputsLoggedFaultsScreenProperties.CURRENT_LOGGED_FAULTS_PAGE,
        currentPage);
    setApplicationOutputsProperty(IAppOutputsLoggedFaultsScreenProperties.LOGGED_FAULTS_STATUS,
        updateCurrentFaultStatus());
  }

  private void backToOld()
  {
    if (currentFaultDOSubList.size() > numberOfData && currentPage > 1)
    {
      currentPage--;
      endIndex = startIndex;
      startIndex = startIndex - numberOfData;
    }
    setApplicationOutputsProperty(IAppOutputsLoggedFaultsScreenProperties.CURRENT_LOGGED_FAULTS_PAGE,
        currentPage);
    setApplicationOutputsProperty(IAppOutputsLoggedFaultsScreenProperties.LOGGED_FAULTS_STATUS,
        updateCurrentFaultStatus());
  }

  public ListProperty<TCMSEventsDO> getCurrentFaultDOList()
  {
    return currentFaultDOList;
  }

  private ListProperty<TCMSEventsDO> getFilteredFaultList()
  {
    filteredFaultList.clear();
    for (int i = 0; i < currentFaultDOList.size(); i++)
    {
      filteredFaultList.add(currentFaultDOList.get(i));
      if (appliedSystemFilter != ActiveFaultsSystemFilterEnum.ANY && !Objects
          .equals(currentFaultDOList.get(i).getFaultSystem().toLowerCase(), appliedSystemFilter.getSysName()))
      {
        filteredFaultList.remove(currentFaultDOList.get(i));
      }
      if (appliedCarFilter != ActiveFaultsCarFilterEnum.ANY
          && currentFaultDOList.get(i).getFaultVehicleId() != appliedCarFilter.getCarFilterId())
      {
        filteredFaultList.remove(currentFaultDOList.get(i));
      }
      if (appliedPriorityFilter != ActiveFaultsPriorityFilterEnum.ANY
          && currentFaultDOList.get(i).getFaultpriority() != appliedPriorityFilter.getPriorityFilterId())
      {
        filteredFaultList.remove(currentFaultDOList.get(i));
      }
    }
    if (filteredFaultList.size() < startIndex)
    {
      startIndex = 0;
      endIndex = 0;
      totalPage = 0;
      currentPage = 1;
    }
    return filteredFaultList;
  }

  private byte[] updateCurrentFaultStatus()
  {
    byte[] currentFaultByteList;
    builder = TCMSProto.LoggedFaultsList.newBuilder();
    activeFaultDOSubList.clear();
    currentFaultDOSubList = getFilteredFaultList();
    int checkIndex = currentFaultDOSubList.size();
    currentFaultTotalPage(checkIndex);
    if (checkIndex - startIndex <= numberOfData)
    {
      endIndex = currentFaultDOSubList.size();
    }
    else
    {
      endIndex = numberOfData;
    }
    setApplicationOutputsProperty(IAppOutputsLoggedFaultsScreenProperties.LOGGED_FAULTS_TOTAL_LIST_COUNT,
        checkIndex);
    if (currentFaultDOSubList != null && startIndex >= 0 && (endIndex - startIndex) <= numberOfData)
    {
      for (int i = startIndex; i < endIndex; i++)
      {
        activeFaultDOSubList.add(currentFaultDOSubList.get(i));
      }
      for (TCMSEventsDO message : activeFaultDOSubList)
      {
        TCMSProto.LoggedFaultsList.LoggedFaultsStatus.Builder faultBuilder = TCMSProto.LoggedFaultsList.LoggedFaultsStatus
            .newBuilder();
        faultBuilder.setCarIndex(getCarCodeLabel(message.getFaultVehicleId()));
        faultBuilder.setId(messageIndex);
        faultBuilder.setFaultId(message.getEventId());
        faultBuilder.setFaultCode(message.getEventId().toString());
        faultBuilder.setFaultSystemName(message.getFaultSystem());
        faultBuilder.setFaultLevel(message.getFaultpriority());
        faultBuilder.setFaultDescription(message.getFaultDescription());
        faultBuilder.setFaultComponenet(message.getFaultComponenet());
        faultBuilder.setOperatorGuide(message.getOperatorGuide());
        faultBuilder.setFaultOccurrenceDateTime(message.getEventTime());
        if (message.getEventResolutionTime() != null)
        {
          faultBuilder.setFaultClearanceDateTime(message.getEventResolutionTime());
        }
        else
        {
          faultBuilder.setFaultClearanceDateTime(0);
        }

        builder.addFaults(faultBuilder.build());
        messageIndex++;
      }
    }
    currentFaultByteList = builder.build().toByteArray();
    return currentFaultByteList;
  }

  private String getCarCodeLabel(Integer faultVehicleId)
  {
    String carCode = ApplicationConstants.BLANK;
    if (faultVehicleId == 0)
    {
      carCode = ApplicationConstants.VEHICLE;
    }
    else if (sharedDataModel.getTotalCar() < 8)
    {
      if (faultVehicleId == TCMSConstants.CAB_1 || faultVehicleId == TCMSConstants.CAB_6)
      {
        carCode = CarType.DM.getCarTypeCode().concat(faultVehicleId.toString());
      }
      else if (faultVehicleId == TCMSConstants.CAB_2 || faultVehicleId == TCMSConstants.CAB_5)
      {
        carCode = CarType.T.getCarTypeCode().concat(faultVehicleId.toString());
      }
      else if (faultVehicleId == TCMSConstants.CAB_3 || faultVehicleId == TCMSConstants.CAB_4)
      {
        carCode = CarType.M.getCarTypeCode().concat(faultVehicleId.toString());
      }
    }
    else
    {
      if (faultVehicleId == TCMSConstants.CAB_1 || faultVehicleId == TCMSConstants.CAB_8)
      {
        carCode = CarType.DM.getCarTypeCode().concat(faultVehicleId.toString());
      }
      else if (faultVehicleId == TCMSConstants.CAB_2 || faultVehicleId == TCMSConstants.CAB_4
          || faultVehicleId == TCMSConstants.CAB_7)
      {
        carCode = CarType.T.getCarTypeCode().concat(faultVehicleId.toString());
      }
      else if (faultVehicleId == TCMSConstants.CAB_3 || faultVehicleId == TCMSConstants.CAB_5
          || faultVehicleId == TCMSConstants.CAB_6)
      {
        carCode = CarType.M.getCarTypeCode().concat(faultVehicleId.toString());
      }
    }
    return carCode;
  }

  private byte[] updateFaultDetail(Integer faultCode)
  {
    byte[] faultDetail;
    faultDetailBuilder = TCMSProto.ActiveFaultsList.newBuilder();
    if (getCurrentFaultDOList() != null)
    {
      for (TCMSEventsDO message : currentFaultDOList)
      {
        TCMSProto.ActiveFaultsList.FaultsStatus.Builder faultBuilder = TCMSProto.ActiveFaultsList.FaultsStatus
            .newBuilder();
        if (message.getEventId().equals(faultCode))
        {
          faultBuilder.setCarIndex(getCarCodeLabel(message.getFaultVehicleId()));
          faultBuilder.setId(messageIndex);
          faultBuilder.setFaultId(message.getEventId());
          faultBuilder.setFaultCode(message.getEventId().toString());
          faultBuilder.setFaultSystemName(message.getFaultSystem());
          faultBuilder.setFaultLevel(message.getFaultpriority());
          faultBuilder.setFaultDescription(message.getFaultDescription());
          faultBuilder.setFaultComponenet(message.getFaultComponenet());
          faultBuilder.setOperatorGuide(message.getOperatorGuide());
          faultBuilder.setFaultOccurrenceDateTime(message.getEventTime());
          faultBuilder.setAcknowledged(true);
          faultDetailBuilder.addFaults(faultBuilder.build());
        }
      }
    }
    faultDetail = faultDetailBuilder.build().toByteArray();
    return faultDetail;
  }

  private void initializeAppOutputHandler()
  {
    if (appOutputsActiveFaultsScreenHandler == null)
    {
      appOutputsActiveFaultsScreenHandler = (IAppOutputsLoggedFaultsScreenHandler)commsBinding
          .getAppOutputsSetter();
    }
    if (eventDisplayAreaHandler == null)
    {
      eventDisplayAreaHandler = (IAppOutputsEventDisplayAreaHandler)commsBinding.getAppOutputsSetter();
    }
    if (faultDetailsScreenHandler == null)
    {
      faultDetailsScreenHandler = (IAppOutputsFaultDetailsScreenHandler)commsBinding.getAppOutputsSetter();
    }
  }
}

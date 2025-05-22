/*
 * ==================================================================
 * (C)Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * ==================================================================
 */
package com.sydac.mmrbem.tcms.backend.logic.handler;

import java.util.HashMap;
import java.util.Map;
import java.util.Objects;

import org.springframework.stereotype.Service;

import com.sydac.foundation.IPropertySetter;
import com.sydac.foundation.PropertyKey;

import com.sydac.mmrbem.tcms.backend.app.io.handlers.IAppOutputsActiveFaultsScreenHandler;
import com.sydac.mmrbem.tcms.backend.app.io.handlers.IAppOutputsEventDisplayAreaHandler;
import com.sydac.mmrbem.tcms.backend.app.io.handlers.IAppOutputsFaultDetailsScreenHandler;
import com.sydac.mmrbem.tcms.backend.comms.CommsBinding;
import com.sydac.mmrbem.tcms.backend.logic.AbstractFunctionalLogic;
import com.sydac.mmrbem.tcms.backend.logic.DateTimeModel;
import com.sydac.mmrbem.tcms.backend.logic.SharedDataModel;
import com.sydac.mmrbem.tcms.backend.logic.annotation.FunctionalLogicHandler;
import com.sydac.mmrbem.tcms.backend.vehicle.io.handlers.ICBTCVehicleInputsProperties;
import com.sydac.mmrbem.tcms.backend.vehicle.io.properties.IEventProperties;
import com.sydac.mmrbem.tcms.backend.vehicle.io.properties.ITCMSVehicleOutputsActiveFaultsScreenProperties;
import com.sydac.mmrbem.tcms.common.ScreenId;
import com.sydac.mmrbem.tcms.common.data.TCMSEventsDO;
import com.sydac.mmrbem.tcms.common.io.TCMSEventsPropertiesReader;
import com.sydac.mmrbem.tcms.common.io.properties.IAppInputsActiveFaultsScreenProperties;
import com.sydac.mmrbem.tcms.common.io.properties.IAppInputsProperties;
import com.sydac.mmrbem.tcms.common.io.properties.IAppInputsScreenChangeProperties;
import com.sydac.mmrbem.tcms.common.io.properties.IAppOutputsActiveFaultsScreenProperties;
import com.sydac.mmrbem.tcms.common.io.properties.IAppOutputsFaultDetailsScreenProperties;
import com.sydac.mmrbem.tcms.common.io.properties.IAppOutputsTrainSideViewComponentProperties;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.ActiveFaultsList;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.CabFaultStatusList;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.CabFaultStatusList.CabFaultSate;
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
 * This handler class is used for handling Active Faults screen data
 * 
 */
@Service
@FunctionalLogicHandler(arguments = { CommsBinding.class })
public class ActiveFaultsLogicHandler extends AbstractFunctionalLogic
{
  private ActiveFaultsList.Builder builder;

  private IAppOutputsActiveFaultsScreenHandler appOutputsActiveFaultsScreenHandler;

  private IAppOutputsEventDisplayAreaHandler eventDisplayAreaHandler;

  private IAppOutputsFaultDetailsScreenHandler faultDetailsScreenHandler;

  private CommsBinding commsBinding;

  private SharedDataModel sharedDataModel;

  private int numberOfData = 8;

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

  protected ActiveFaultsLogicHandler(CommsBinding commsBinding, SharedDataModel sharedDataModel)
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
    if (IAppInputsActiveFaultsScreenProperties.ACTIVE_FAULTS_PAGE_DOWN_BUTTON_REQUEST.equals(key)
        && (Integer)newValue > 0)
    {
      updateNewPage();
    }
    else if (IAppInputsActiveFaultsScreenProperties.ACTIVE_FAULTS_PAGE_UP_BUTTON_REQUEST.equals(key)
        && (Integer)newValue > 0)
    {
      backToOld();
    }
    else if (IAppInputsScreenChangeProperties.TCMS_SCREEN_CHANGE_REQUEST.equals(key))
    {
      if ((Integer)newValue == ScreenId.ACTIVE_FAULTS_SCREEN.getId())
      {
        appOutputsActiveFaultsScreenHandler.setActiveFaultsStatus(updateCurrentFaultStatus());
        setApplicationOutputsProperty(IAppOutputsActiveFaultsScreenProperties.ACTIVE_FAULT_LIST_UPDATED, 0);
      }
      else if ((Integer)newValue == ScreenId.OPERATING_SCREEN.getId())
      {
        updateCabFaultStatus();
      }
    }
    else if (IAppInputsActiveFaultsScreenProperties.ACTIVE_FAULTS_UPDATE_BUTTON_REQUEST.equals(key)
        && (Integer)newValue > 0)
    {
      appOutputsActiveFaultsScreenHandler.setActiveFaultsStatus(updateCurrentFaultStatus());
      setApplicationOutputsProperty(IAppOutputsActiveFaultsScreenProperties.ACTIVE_FAULT_LIST_UPDATED, 0);
    }
    else if (IAppInputsActiveFaultsScreenProperties.ACTIVE_FAULTS_ACKNOWLEDGE_BUTTON_REQUEST.equals(key)
        && (Integer)newValue > 0)
    {
      for (TCMSEventsDO event : currentFaultDOList)
      {
        if (event.getEventId().equals(newValue))
        {
          event.setAcknowledged(true);
        }
      }
      updateEventAreaStatus();
    }
    else if (IAppInputsActiveFaultsScreenProperties.ACTIVE_FAULT_LIST_SELECTED_INDEX.equals(key)
        && (Integer)newValue > 0)
    {
      faultDetailsScreenHandler.setFaultDetailsInfo(updateFaultDetail((Integer)newValue));
      setApplicationOutputsProperty(
          IAppOutputsFaultDetailsScreenProperties.PREVIOUS_SCREEN_ID_TO_FAULT_DETAILS,
          ScreenId.ACTIVE_FAULTS_SCREEN.getId());
    }
    else if (IAppInputsActiveFaultsScreenProperties.EVENT_AREA_FAULT_DETAIL_REQUEST.equals(key)
        && (Integer)newValue > 0)
    {
      faultDetailsScreenHandler.setFaultDetailsInfo(updateFaultDetail((Integer)newValue));
      setApplicationOutputsProperty(
          IAppOutputsFaultDetailsScreenProperties.PREVIOUS_SCREEN_ID_TO_FAULT_DETAILS,
          ScreenId.OPERATING_SCREEN.getId());
    }
    else if (IAppInputsActiveFaultsScreenProperties.ACTIVE_FAULTS_SYSTEM_FILTER_BUTTON_REQUEST.equals(key)
        && (Integer)newValue > resetValue)
    {
      appliedSystemFilter = ActiveFaultsSystemFilterEnum.valueOf((Integer)newValue);
      appOutputsActiveFaultsScreenHandler.setActiveFaultsStatus(updateCurrentFaultStatus());
      setApplicationOutputsProperty(IAppOutputsActiveFaultsScreenProperties.ACTIVE_FAULT_SYS_FILTER_APPLIED,
          appliedSystemFilter.getSysFilterId());
    }
    else if (IAppInputsActiveFaultsScreenProperties.ACTIVE_FAULTS_CAR_FILTER_BUTTON_REQUEST.equals(key)
        && (Integer)newValue > resetValue)
    {
      appliedCarFilter = ActiveFaultsCarFilterEnum.valueOf((Integer)newValue);
      appOutputsActiveFaultsScreenHandler.setActiveFaultsStatus(updateCurrentFaultStatus());
      setApplicationOutputsProperty(IAppOutputsActiveFaultsScreenProperties.ACTIVE_FAULT_CAR_FILTER_APPLIED,
          appliedCarFilter.getCarFilterId());
    }
    else if (IAppInputsActiveFaultsScreenProperties.ACTIVE_FAULTS_PRIORITY_FILTER_BUTTON_REQUEST.equals(key)
        && (Integer)newValue > resetValue)
    {
      appliedPriorityFilter = ActiveFaultsPriorityFilterEnum.valueOf((Integer)newValue);
      appOutputsActiveFaultsScreenHandler.setActiveFaultsStatus(updateCurrentFaultStatus());
      setApplicationOutputsProperty(
          IAppOutputsActiveFaultsScreenProperties.ACTIVE_FAULT_PRIORITY_FILTER_APPLIED,
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
        eventDO.setActive(false);
        eventDO.setAcknowledged(false);
        this.currentFaultDOList.remove(eventDO);
        eventDO.setEventResolutionTime(DateTimeModel.getInstance().getTime());
      }
      setApplicationOutputsProperty(IAppOutputsActiveFaultsScreenProperties.NO_OF_ACTIVE_FAULTS,
          getCurrentFaultDOList().size());
      updateEventAreaStatus();
      updateCabFaultStatus();
      setApplicationOutputsProperty(IAppOutputsActiveFaultsScreenProperties.ACTIVE_FAULT_LIST_UPDATED,
          TCMSConstants.ACTIVE);
    }
  }

  private void currentFaultTotalPage(int checkSize)
  {
    totalPage = (checkSize - 1) / numberOfData;
    setApplicationOutputsProperty(IAppOutputsActiveFaultsScreenProperties.NO_OF_ACTIVE_FAULTS_PAGE,
        totalPage + 1);
    setApplicationOutputsProperty(IAppOutputsActiveFaultsScreenProperties.CURRENT_ACTIVE_FAULTS_PAGE,
        currentPage);
    if (totalPage == 0 && currentPage == 1)
    {
      setApplicationOutputsProperty(IAppOutputsActiveFaultsScreenProperties.ACTIVE_FAULT_PAGE_UP_ACTIVE,
          TCMSConstants.NOT_ACTIVE);
      setApplicationOutputsProperty(IAppOutputsActiveFaultsScreenProperties.ACTIVE_FAULT_PAGE_DOWN_ACTIVE,
          TCMSConstants.NOT_ACTIVE);
    }
    else
    {
      if (currentPage <= totalPage)
      {
        setApplicationOutputsProperty(IAppOutputsActiveFaultsScreenProperties.ACTIVE_FAULT_PAGE_DOWN_ACTIVE,
            TCMSConstants.ACTIVE);
      }
      else
      {
        setApplicationOutputsProperty(IAppOutputsActiveFaultsScreenProperties.ACTIVE_FAULT_PAGE_DOWN_ACTIVE,
            TCMSConstants.NOT_ACTIVE);
      }
      if (currentPage == 1)
      {
        setApplicationOutputsProperty(IAppOutputsActiveFaultsScreenProperties.ACTIVE_FAULT_PAGE_UP_ACTIVE,
            TCMSConstants.NOT_ACTIVE);
      }
      else
      {
        setApplicationOutputsProperty(IAppOutputsActiveFaultsScreenProperties.ACTIVE_FAULT_PAGE_UP_ACTIVE,
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
    setApplicationOutputsProperty(IAppOutputsActiveFaultsScreenProperties.CURRENT_ACTIVE_FAULTS_PAGE,
        currentPage);
    setApplicationOutputsProperty(IAppOutputsActiveFaultsScreenProperties.ACTIVE_FAULTS_STATUS,
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
    setApplicationOutputsProperty(IAppOutputsActiveFaultsScreenProperties.CURRENT_ACTIVE_FAULTS_PAGE,
        currentPage);
    setApplicationOutputsProperty(IAppOutputsActiveFaultsScreenProperties.ACTIVE_FAULTS_STATUS,
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
    builder = TCMSProto.ActiveFaultsList.newBuilder();
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
    setApplicationOutputsProperty(IAppOutputsActiveFaultsScreenProperties.ACTIVE_FAULTS_TOTAL_LIST_COUNT,
        checkIndex);
    if (currentFaultDOSubList != null && startIndex >= 0 && (endIndex - startIndex) <= numberOfData)
    {
      for (int i = startIndex; i < endIndex; i++)
      {
        activeFaultDOSubList.add(currentFaultDOSubList.get(i));
      }
      for (TCMSEventsDO message : activeFaultDOSubList)
      {
        TCMSProto.ActiveFaultsList.FaultsStatus.Builder faultBuilder = TCMSProto.ActiveFaultsList.FaultsStatus
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
        faultBuilder.setAcknowledged(message.isAcknowledged());

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

  private void updateEventAreaStatus()
  {
    byte[] currentFaultByteList;
    int highestFaultPriority = TCMSConstants.FAULT_PRIORITY_3;
    builder = TCMSProto.ActiveFaultsList.newBuilder();
    if (getCurrentFaultDOList() != null)
    {
      for (TCMSEventsDO message : currentFaultDOList)
      {
        TCMSProto.ActiveFaultsList.FaultsStatus.Builder faultBuilder = TCMSProto.ActiveFaultsList.FaultsStatus
            .newBuilder();
        if (highestFaultPriority > message.getFaultpriority())
        {
          highestFaultPriority = message.getFaultpriority();
        }
        if (!message.isAcknowledged())
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
          faultBuilder.setAcknowledged(message.isAcknowledged());

          builder.addFaults(faultBuilder.build());
        }
      }
    }
    setApplicationOutputsProperty(IAppOutputsActiveFaultsScreenProperties.FAULTS_BUTTON_PRIORITY_STATE,
        highestFaultPriority);
    updateAudioInformation(highestFaultPriority);

    currentFaultByteList = builder.build().toByteArray();
    eventDisplayAreaHandler.setEventAreaActiveFaultsStatus(currentFaultByteList);
  }

  private void updateAudioInformation(int highestFaultPriority)
  {
    IPropertySetter onboardInputSetter = getCBTCVehicleInputsSetter(getActiveVehicleIndex());
    if (onboardInputSetter != null)
    {
      if (highestFaultPriority == TCMSConstants.FAULT_PRIORITY_1)
      {
        setInputData(onboardInputSetter, ICBTCVehicleInputsProperties.AUDIO_TCMS_HIGH_PRIORITY_FAULT,
            ApplicationConstants.SET_VALUE);
      }else
      {
        setInputData(onboardInputSetter, ICBTCVehicleInputsProperties.AUDIO_TCMS_HIGH_PRIORITY_FAULT,
            ApplicationConstants.RESET_VALUE);
      }
    }
  }

  private void updateCabFaultStatus()
  {
    byte[] cabFaultStatusList;
    Map<Integer, Integer> prevCabFaultStatusMap = new HashMap<>();
    CabFaultStatusList.Builder cabFaultStatusListBuilder = TCMSProto.CabFaultStatusList.newBuilder();
    if (sharedDataModel.getTotalCar() > 0)
    {
      for (int carIndex = 1; carIndex <= sharedDataModel.getTotalCar(); carIndex++)
      {
        TCMSProto.CabFaultStatusList.CabFaultStatus.Builder cabFaultStatusBuilder = TCMSProto.CabFaultStatusList.CabFaultStatus
            .newBuilder();
        for (TCMSEventsDO message : currentFaultDOList)
        {
          if (message.getFaultVehicleId() == carIndex)
          {
            if (message.getFaultpriority() == TCMSConstants.FAULT_PRIORITY_1)
            {
              cabFaultStatusBuilder.setCabFaultSate(CabFaultSate.PRIORITY_1_FAULT);
              cabFaultStatusBuilder.setCarIndex(carIndex - 1);
            }
            else if (message.getFaultpriority() == TCMSConstants.FAULT_PRIORITY_2)
            {
              if (!prevCabFaultStatusMap.isEmpty() && prevCabFaultStatusMap.get(carIndex) != null
                  && prevCabFaultStatusMap.get(carIndex) == CabFaultSate.PRIORITY_1_FAULT_VALUE)
              {
                cabFaultStatusBuilder.setCabFaultSate(CabFaultSate.PRIORITY_1_FAULT);
                cabFaultStatusBuilder.setCarIndex(carIndex - 1);
              }
              else
              {
                cabFaultStatusBuilder.setCabFaultSate(CabFaultSate.PRIORITY_2_FAULT);
                cabFaultStatusBuilder.setCarIndex(carIndex - 1);
              }
            }
            else
            {
              cabFaultStatusBuilder.setCabFaultSate(CabFaultSate.NO_ACTIVE_FAULT);
              cabFaultStatusBuilder.setCarIndex(carIndex - 1);
            }
            prevCabFaultStatusMap.put(carIndex, cabFaultStatusBuilder.getCabFaultSate().getNumber());
          }
        }
        if (!cabFaultStatusBuilder.hasCarIndex())
        {
          cabFaultStatusBuilder.setCabFaultSate(CabFaultSate.NO_ACTIVE_FAULT);
          cabFaultStatusBuilder.setCarIndex(carIndex - 1);
        }
        cabFaultStatusListBuilder.addCabFaultStatus(cabFaultStatusBuilder);
      }
      cabFaultStatusList = cabFaultStatusListBuilder.build().toByteArray();
      setApplicationOutputsProperty(IAppOutputsTrainSideViewComponentProperties.CAB_FAULT_STATE,
          cabFaultStatusList);
    }
  }

  private byte[] updateFaultDetail(Integer faultCode)
  {
    byte[] faultDetail;
    builder = TCMSProto.ActiveFaultsList.newBuilder();
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
          faultBuilder.setAcknowledged(message.isAcknowledged());
          builder.addFaults(faultBuilder.build());
        }
      }
    }
    faultDetail = builder.build().toByteArray();
    return faultDetail;
  }

  private void initializeAppOutputHandler()
  {
    if (appOutputsActiveFaultsScreenHandler == null)
    {
      appOutputsActiveFaultsScreenHandler = (IAppOutputsActiveFaultsScreenHandler)commsBinding
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

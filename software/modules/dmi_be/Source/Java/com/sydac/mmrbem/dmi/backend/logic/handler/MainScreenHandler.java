/*
 * 
 * ================================================================== (C)
 * Copyright 2020 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * ==================================================================
 */
package com.sydac.mmrbem.dmi.backend.logic.handler;

import org.springframework.stereotype.Service;

import com.google.protobuf.InvalidProtocolBufferException;
import com.sydac.common.log.Tracer;
import com.sydac.foundation.PropertyKey;
import com.sydac.mmrbem.cbtc.common.protos.CBTCProtos;
import com.sydac.mmrbem.dmi.backend.comms.CommsBinding;
import com.sydac.mmrbem.dmi.backend.logic.AbstractFunctionalLogic;
import com.sydac.mmrbem.dmi.backend.logic.annotation.FunctionalLogicHandler;
import com.sydac.mmrbem.dmi.backend.vehicle.io.models.ICBTCOnboardOutputsModel;
import com.sydac.mmrbem.dmi.backend.vehicle.io.models.ICBTCPlatformOutputsModel;
import com.sydac.mmrbem.dmi.backend.vehicle.io.models.IDMIVehicleOutputsModel;
import com.sydac.mmrbem.dmi.backend.vehicle.io.properties.ICBTCOnboardOutputsProperties;
import com.sydac.mmrbem.dmi.backend.vehicle.io.properties.ICBTCPlatformOutputsProperties;
import com.sydac.mmrbem.dmi.backend.vehicle.io.properties.IDMIVehicleOutputsStartupScreenProperties;
import com.sydac.mmrbem.dmi.backend.vehicle.io.properties.IPISBEOutputsProperties;
import com.sydac.mmrbem.dmi.common.io.properties.IAppInputsProperties;
import com.sydac.mmrbem.dmi.common.io.properties.IAppInputsTextMessageProperties;
import com.sydac.mmrbem.dmi.common.io.properties.IAppOutputsCrewIdPopupProperties;
import com.sydac.mmrbem.dmi.common.io.properties.IAppOutputsMainScreenAreaAProperties;
import com.sydac.mmrbem.dmi.common.io.properties.IAppOutputsMainScreenAreaBLeftProperties;
import com.sydac.mmrbem.dmi.common.io.properties.IAppOutputsMainScreenAreaCRightProperties;
import com.sydac.mmrbem.dmi.common.io.properties.IAppOutputsMainScreenAreaDMiddleProperties;
import com.sydac.mmrbem.dmi.common.io.properties.IAppOutputsMainScreenAreaETopProperties;
import com.sydac.mmrbem.dmi.common.io.properties.IAppOutputsMainScreenProperties;
import com.sydac.mmrbem.dmi.common.state.DMIConstants;
import com.sydac.mmrbem.dmi.common.state.DMIDepartureInformation;
import com.sydac.mmrbem.dmi.common.state.DMITrainDockingStatus;
import com.sydac.mmrbem.dmi.common.state.DrivingModeStatus;
import com.sydac.mmrbem.dmi.common.utils.SpeedUnitConverter;
import com.sydac.mmrbem.dmi.common.utils.XMLParser;

/**
 * This handler class is responsible for managing all the areas of the main
 * screen other than Text message area, Crew Id Pop up and Menu Pop up.
 *
 * @author Bigi P
 */
@Service
@FunctionalLogicHandler(arguments = { CommsBinding.class })
public class MainScreenHandler extends AbstractFunctionalLogic
{

  private SpeedUnitConverter speedUnitConverter = new SpeedUnitConverter();

  private static final Tracer LOGGER = Tracer.getInstance();

  private ICBTCOnboardOutputsModel cbtcOutputModel;

  private ICBTCPlatformOutputsModel cbtcPlatformOutputsModel;

  private IDMIVehicleOutputsModel dmiVehicleOutputModel;

  private CommsBinding commsBinding;

  private XMLParser xmlParser;

  public MainScreenHandler(CommsBinding commsBinding)
  {
    super(commsBinding, IAppInputsProperties.class, ICBTCOnboardOutputsProperties.class,
        ICBTCPlatformOutputsProperties.class, IPISBEOutputsProperties.class,
        IDMIVehicleOutputsStartupScreenProperties.class);
    this.commsBinding = commsBinding;
    initalizeCbtcOutputModel();
    xmlParser = new XMLParser();
  }

  @Override
  public <T> void pisBeOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue, int vehicleIndex)
  {

    if (IPISBEOutputsProperties.SELECTED_TERMINAL_STATION_ID.equals(key) && (Integer)newValue > -1)
    {
      setApplicationOutputsProperty(IAppOutputsMainScreenProperties.DESTINATION_CODE, (Integer)newValue);
      setApplicationOutputsProperty(IAppOutputsMainScreenProperties.FINAL_DESTINATION_NAME,
          (xmlParser.getStationCode((Integer)newValue)).getBytes());
    }
  }

  @Override
  public <T> void appInputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue, int vehicleIndex)
  {
    if (IAppInputsTextMessageProperties.CREW_BUTTON_PRESS_REQUEST.equals(key) && (Integer)newValue > 0)
    {
      setApplicationOutputsProperty(IAppOutputsCrewIdPopupProperties.CREW_ID_PANEL_STATUS, true);
    }
  }

  @Override
  public <T> void cbtcOnboardOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue,
      int vehicleIndex)
  {
    initalizeCbtcOutputModel();

    if (getActiveVehicleIndex() == vehicleIndex)
    {
      if (key.equals(ICBTCOnboardOutputsProperties.WARNING_STATUS))
      {
        setApplicationOutputsProperty(IAppOutputsMainScreenAreaAProperties.WARNING_STATUS, (Integer)newValue);
      }
      else if (key.equals(ICBTCOnboardOutputsProperties.CURRENT_DRIVING_MODE))
      {

        if ((Integer)newValue >= 0)
        {
          updateDriverEventChangeEnds(this.cbtcOutputModel.getDriverEventChangeEnds());
          updateDriverEventSkipStation(this.cbtcOutputModel.getDriverEventSkipStation());
          updateDriverEventWorkZone(this.cbtcOutputModel.getDriverEventWorkZone());
          updateTargetDistance(this.cbtcOutputModel.getTargetDistance());
        }

        setApplicationOutputsProperty(IAppOutputsMainScreenProperties.CURRENT_DRIVING_MODE,
            (Integer)newValue);
        setTargetDistanceBarGraphStatus();

      }
      else if (key.equals(ICBTCOnboardOutputsProperties.CURRENT_TRAIN_SPEED))
      {
        setApplicationOutputsProperty(IAppOutputsMainScreenAreaBLeftProperties.CURRENT_TRAIN_SPEED,
            getSpeedInKMPHDouble((Double)newValue));
      }
      else if (key.equals(ICBTCOnboardOutputsProperties.CBTC_TARGET_SPEED))
      {
        setApplicationOutputsProperty(IAppOutputsMainScreenAreaBLeftProperties.CBTC_TARGET_SPEED,
            getSpeedInKMPH((Double)newValue).intValue());
      }
      else if (key.equals(ICBTCOnboardOutputsProperties.CBTC_PERMITTED_SPEED))
      {
        setApplicationOutputsProperty(IAppOutputsMainScreenAreaBLeftProperties.CBTC_PERMITTED_SPEED,
            getSpeedInKMPH((Double)newValue).intValue());
      }
      else if (key.equals(ICBTCOnboardOutputsProperties.SAFETY_BRAKE_STATUS))
      {
        setApplicationOutputsProperty(IAppOutputsMainScreenProperties.SAFETY_BRAKE_STATUS, (Integer)newValue);
      }
      else if (key.equals(ICBTCOnboardOutputsProperties.ATC_STATUS))
      {
        setApplicationOutputsProperty(IAppOutputsMainScreenAreaETopProperties.ATC_STATUS, (Integer)newValue);
      }
      else if (key.equals(ICBTCOnboardOutputsProperties.ATC_BYPASS_STATE))
      {
        setDepartureProperties();
        updateDockingInfo();
        setApplicationOutputsProperty(IAppOutputsMainScreenProperties.ATC_BYPASS_STATE,
            getBooleanValue((Integer)newValue));
      }
      else if (key.equals(ICBTCOnboardOutputsProperties.TARGET_DISTANCE))
      {
        updateTargetDistance((Integer)newValue);
      }
      else if (key.equals(ICBTCOnboardOutputsProperties.LOCALISATION_STATUS))
      {
        setApplicationOutputsProperty(IAppOutputsMainScreenAreaCRightProperties.LOCALISATION_STATUS,
            (Integer)newValue);
      }
      else if (key.equals(ICBTCOnboardOutputsProperties.ADVISORY_SPEED))
      {
        if (Boolean.TRUE.equals(isATPModeActive()))
        {
          setApplicationOutputsProperty(IAppOutputsMainScreenProperties.ADVISORY_SPEED,
              getSpeedInKMPHDouble((Double)newValue));
        }
        else
        {
          setApplicationOutputsProperty(IAppOutputsMainScreenProperties.ADVISORY_SPEED, 0.0);
        }
      }
      else if (key.equals(ICBTCOnboardOutputsProperties.WARNING_SPEED))
      {
        if (Boolean.TRUE.equals(isATPModeActive()))
        {
          setApplicationOutputsProperty(IAppOutputsMainScreenProperties.WARNING_SPEED,
              getSpeedInKMPHDouble((Double)newValue));
        }
        else
        {
          setApplicationOutputsProperty(IAppOutputsMainScreenProperties.WARNING_SPEED, 0.0);
        }
      }
      else if (key.equals(ICBTCOnboardOutputsProperties.DRIVER_EVENT_SKIP_STATION))
      {
        updateDriverEventSkipStation((Integer)newValue);
      }
      else if (key.equals(ICBTCOnboardOutputsProperties.DRIVER_EVENT_CHANGE_ENDS))
      {
        updateDriverEventChangeEnds((Integer)newValue);
      }
      else if (key.equals(ICBTCOnboardOutputsProperties.DRIVER_EVENT_WORK_ZONE))
      {
        updateDriverEventWorkZone((Integer)newValue);
      }
      else if (key.equals(ICBTCOnboardOutputsProperties.RADIO_COMMUNICATION_STATUS))
      {
        setApplicationOutputsProperty(IAppOutputsMainScreenAreaETopProperties.RADIO_COMMUNICATION_STATUS,
            (Integer)newValue);
      }
      else if (key.equals(ICBTCOnboardOutputsProperties.AVAILABLE_MODES))
      {
        setApplicationOutputsProperty(IAppOutputsMainScreenAreaCRightProperties.AVAILABLE_MODES,
            (byte[])newValue);
      }
      else if (key.equals(ICBTCOnboardOutputsProperties.DEPOT_INDICATION))
      {
        setApplicationOutputsProperty(IAppOutputsMainScreenAreaETopProperties.DEPOT_INDICATION,
            (Integer)newValue);
      }
      else if (key.equals(ICBTCOnboardOutputsProperties.ATP_ZONE_STATUS))
      {
        setApplicationOutputsProperty(IAppOutputsMainScreenAreaETopProperties.ATP_ZONE_STATUS,
            (Integer)newValue);
      }
      else if (key.equals(ICBTCOnboardOutputsProperties.DETRAINMENT_DOOR_STATUS)
          && ((Integer)newValue == 0 || (Integer)newValue == 1))
      {
        setApplicationOutputsProperty(IAppOutputsMainScreenAreaDMiddleProperties.DETRAINMENT_DOOR_STATUS,
            (Integer)newValue);
      }
    }
  }

  @Override
  public <T> void dmiVehicleOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue,
      int vehicleIndex)
  {
    initalizeDmiVehicleOutputModel();

    if (key.equals(IDMIVehicleOutputsStartupScreenProperties.NEUTRAL_SECTION))
    {
      setApplicationOutputsProperty(IAppOutputsMainScreenAreaBLeftProperties.NEUTRAL_ZONE_STATUS,
          (Integer)newValue);
    }
  }

  private void initalizeDmiVehicleOutputModel()
  {
    if (this.dmiVehicleOutputModel == null)
    {
      this.dmiVehicleOutputModel = (IDMIVehicleOutputsModel)commsBinding.getDmivehicleoutputsmodels()
          .get(getActiveVehicleIndex());
    }
  }

  private void setTargetDistanceBarGraphStatus()
  {
    setApplicationOutputsProperty(IAppOutputsMainScreenAreaAProperties.TARGET_DISTANCE_BAR_GRAPH_STATUS,
        this.cbtcOutputModel.getTargetDistance() >= 0 && isATPModeActive());
  }

  private void initalizeCbtcOutputModel()
  {
    if (this.cbtcOutputModel == null)
    {

      this.cbtcOutputModel = (ICBTCOnboardOutputsModel)commsBinding.getCbtconboardoutputsmodels()
          .get(getActiveVehicleIndex());
    }

    if (this.cbtcPlatformOutputsModel == null)
    {
      this.cbtcPlatformOutputsModel = (ICBTCPlatformOutputsModel)commsBinding.getCbtcPlatformOutputsModels()
          .get(getActiveVehicleIndex());
    }
  }

  private void updateTargetDistance(Integer targetDistance)
  {

    if (Boolean.TRUE.equals(isATPModeActive()))
    {
      setApplicationOutputsProperty(IAppOutputsMainScreenAreaAProperties.TARGET_DISTANCE, targetDistance);
      setTargetDistanceBarGraphStatus();
    }
    else
    {
      setApplicationOutputsProperty(IAppOutputsMainScreenAreaAProperties.TARGET_DISTANCE, 0);
    }
  }

  public Double getSpeedInKMPH(double newValue)
  {
    Long result = Math.round(speedUnitConverter.convertTo(newValue));
    return result.doubleValue();
  }

  public Double getSpeedInKMPHDouble(double newValue)
  {
    Double result = speedUnitConverter.convertTo(newValue);
    return result.doubleValue();
  }

  private <T> void updateDriverEventSkipStation(Integer newValue)
  {
    if (isATPModeActive() || isATOModeActive())
    {
      setApplicationOutputsProperty(IAppOutputsMainScreenAreaBLeftProperties.DRIVER_EVENT_SKIP_STATION,
          getBooleanValue(newValue));
    }
    else
    {
      setApplicationOutputsProperty(IAppOutputsMainScreenAreaBLeftProperties.DRIVER_EVENT_SKIP_STATION,
          false);
    }
  }

  private boolean getBooleanValue(Integer value)
  {
    return value != 0;
  }

  private <T> void updateDriverEventChangeEnds(Integer newValue)
  {
    if (isATPModeActive() || isATOModeActive())
    {
      setApplicationOutputsProperty(IAppOutputsMainScreenAreaBLeftProperties.DRIVER_EVENT_CHANGE_ENDS,
          getBooleanValue(newValue));
    }
    else
    {
      setApplicationOutputsProperty(IAppOutputsMainScreenAreaBLeftProperties.DRIVER_EVENT_CHANGE_ENDS, false);
    }
  }

  private <T> void updateDriverEventWorkZone(Integer newValue)
  {
    if (isATPModeActive() || isATOModeActive())
    {
      setApplicationOutputsProperty(IAppOutputsMainScreenAreaBLeftProperties.DRIVER_EVENT_WORK_ZONE,
          getBooleanValue(newValue));
    }
    else
    {
      setApplicationOutputsProperty(IAppOutputsMainScreenAreaBLeftProperties.DRIVER_EVENT_WORK_ZONE, false);
    }
  }

  @Override
  public <T> void cbtcPlatformOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue,
      int vehicleIndex)
  {
    initalizeCbtcOutputModel();

    if (getActiveVehicleIndex() == vehicleIndex && this.cbtcOutputModel != null)
    {
      if (key.equals(ICBTCPlatformOutputsProperties.TRAIN_DOOR_STATUS))
      {
        setApplicationOutputsProperty(IAppOutputsMainScreenAreaDMiddleProperties.TRAIN_DOOR_STATUS,
            (Integer)newValue);
      }
      else if (key.equals(ICBTCPlatformOutputsProperties.PSD_DOOR_STATUS))
      {
        setApplicationOutputsProperty(IAppOutputsMainScreenAreaDMiddleProperties.PSD_DOOR_STATUS,
            (Integer)newValue);
      }
      else if (key.equals(ICBTCPlatformOutputsProperties.DEPARTURE_ORDER))
      {
        setApplicationOutputsProperty(IAppOutputsMainScreenAreaDMiddleProperties.DEPARTURE_ORDER,
            (Integer)newValue);
      }
      else if (key.equals(ICBTCPlatformOutputsProperties.DEPARTURE_INFORMATION))
      {
        setDepartureProperties();
      }
      else if (key.equals(ICBTCPlatformOutputsProperties.TRAIN_DOCKING_INFO))
      {
        updateDockingInfo();
      }
    }
  }

  private void setDepartureProperties()
  {

    initalizeCbtcOutputModel();

    Integer atcBypassStatus = this.cbtcOutputModel.getATCBypassState();

    byte[] departureInfo = atcBypassStatus == 1 || this.cbtcPlatformOutputsModel == null ? new byte[0]
        : this.cbtcPlatformOutputsModel.getDepartureInformation();

    String remainingDepartureTime = ""; //$NON-NLS-1$
    Boolean remainingTimeMinuteStatus = false;

    try
    {
      if (departureInfo.length != 0)
      {
        CBTCProtos.DepartureInformation depInfo = CBTCProtos.DepartureInformation.parseFrom(departureInfo);
        int departureStatus = depInfo.getDepartureStatus().getNumber();

        setApplicationOutputsProperty(IAppOutputsMainScreenAreaDMiddleProperties.DEPARTURE_INFORMATION_STATUS,
            departureStatus);

        if (departureStatus == DMIDepartureInformation.REMAINING_TIME.getValue())
        {
          int remainingTime = depInfo.getRemainingTimeBeforeDeparture();
          if (remainingTime > DMIConstants.REMAINING_COUNTDOWN_TIME)
          {
            remainingTimeMinuteStatus = true;
            remainingDepartureTime = calculateRemainingTimeInMinutes(remainingTime);
          }
          else
          {
            remainingTimeMinuteStatus = false;
            remainingDepartureTime = Integer.toString(remainingTime);
          }
        }
        setApplicationOutputsProperty(
            IAppOutputsMainScreenAreaDMiddleProperties.REMAINING_TIME_IN_MINUTE_STATUS,
            remainingTimeMinuteStatus);
        setApplicationOutputsProperty(
            IAppOutputsMainScreenAreaDMiddleProperties.REMAINING_TIME_BEFORE_DEPARTURE,
            remainingDepartureTime.getBytes());
      }
      else
      {
        setApplicationOutputsProperty(IAppOutputsMainScreenAreaDMiddleProperties.DEPARTURE_INFORMATION_STATUS,
            DMIDepartureInformation.NO_INDICATION.getValue());

      }
    }
    catch (InvalidProtocolBufferException e)
    {
      Tracer.getInstance().error(e);
    }
  }

  private String calculateRemainingTimeInMinutes(int remainingT)
  {
    double remainingTime = remainingT;
    remainingTime /= DMIConstants.SECONDS;
    int minute = (int)Math.round(remainingTime);
    return Integer.toString(minute);
  }

  private void updateDockingInfo()
  {

    Integer atcBypassStatus = this.cbtcOutputModel.getATCBypassState();

    byte[] dockingInfo = atcBypassStatus == 1 || this.cbtcPlatformOutputsModel == null ? new byte[0]
        : this.cbtcPlatformOutputsModel.getTrainDockingInfo();

    int trainDockingStatus = DMITrainDockingStatus.UNKNOWN.getValue();
    String operationalServiceStoppingDistance = ""; //$NON-NLS-1$

    if (dockingInfo.length != 0 && (isATPModeActive() || isATOModeActive() || isRmrModeActive()))
    {

      try
      {
        CBTCProtos.TrainDockingInfo trainDockingInfo = CBTCProtos.TrainDockingInfo.parseFrom(dockingInfo);

        if ((isATPModeActive() || isRmrModeActive()) && trainDockingInfo.getTrainDockingStatus()
            .equals(CBTCProtos.TrainDockingInfo.TrainDockingStatus.OPERATIONAL_SERVICE_STOPPING_DISTANCE))
        {
          operationalServiceStoppingDistance = String.valueOf(trainDockingInfo.getStoppingPointDisatnce());
        }
        trainDockingStatus = trainDockingInfo.getTrainDockingStatus().getNumber();
      }
      catch (InvalidProtocolBufferException e)
      {
        LOGGER.info(e);
      }
    }

    setApplicationOutputsProperty(IAppOutputsMainScreenAreaDMiddleProperties.TRAIN_DOCKING_STATUS,
        trainDockingStatus);
    setApplicationOutputsProperty(
        IAppOutputsMainScreenAreaDMiddleProperties.OPERATIONAL_SERVICE_STOPPING_DISTANCE,
        operationalServiceStoppingDistance.getBytes());

  }

  private Boolean isRmrModeActive()
  {
    return DrivingModeStatus.RMR_MODE.getValue() == this.cbtcOutputModel.getCurrentDrivingMode();
  }

  private Boolean isATOModeActive()
  {
    return DrivingModeStatus.ATO_MODE.getValue() == this.cbtcOutputModel.getCurrentDrivingMode();
  }

  private Boolean isATPModeActive()
  {
    return DrivingModeStatus.ATP_MODE.getValue() == this.cbtcOutputModel.getCurrentDrivingMode();
  }

}
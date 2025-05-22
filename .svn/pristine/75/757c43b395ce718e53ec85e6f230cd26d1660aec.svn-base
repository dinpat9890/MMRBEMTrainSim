/*
 * ==================================================================
 * (C)Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * ==================================================================
 */
package com.sydac.mmrbem.tcms.backend.logic.handler;

import java.util.HashMap;
import java.util.List;
import java.util.Map;

import org.springframework.stereotype.Service;

import com.sydac.common.log.Tracer;
import com.sydac.foundation.IModelListener;
import com.sydac.foundation.PropertyKey;
import com.sydac.mmrbem.tcms.backend.app.io.handlers.IAppOutputsFireDetectionSystemScreenHandler;
import com.sydac.mmrbem.tcms.backend.comms.CommsBinding;
import com.sydac.mmrbem.tcms.backend.logic.AbstractFunctionalLogic;
import com.sydac.mmrbem.tcms.backend.logic.SharedDataModel;
import com.sydac.mmrbem.tcms.backend.logic.SharedDataModel.Change;
import com.sydac.mmrbem.tcms.backend.logic.annotation.FunctionalLogicHandler;
import com.sydac.mmrbem.tcms.backend.vehicle.io.handlers.ITCMSVehicleInputsFireHandler;
import com.sydac.mmrbem.tcms.backend.vehicle.io.properties.ITCMSVehicleOutputsFireDetectionSystemProperties;
import com.sydac.mmrbem.tcms.backend.vehicle.io.properties.ITCMSVehicleOutputsProperties;
import com.sydac.mmrbem.tcms.backend.vehicle.request.handler.ExternalSmokeStatusVehicleOutputsRequestHandler;
import com.sydac.mmrbem.tcms.backend.vehicle.request.handler.FDUStatusVehicleOutputsRequestHandler;
import com.sydac.mmrbem.tcms.backend.vehicle.request.handler.FireSensorAlarmStatusVehicleOutputsRequestHandler;
import com.sydac.mmrbem.tcms.backend.vehicle.request.handler.ITCMSVehicleOutputsRequestHandler;
import com.sydac.mmrbem.tcms.backend.vehicle.request.handler.InternalFireStatusVehicleOutputsRequestHandler;
import com.sydac.mmrbem.tcms.backend.vehicle.request.handler.SFARStatusVehicleOutputsRequestHandler;
import com.sydac.mmrbem.tcms.backend.vehicle.request.handler.TCMSOutputsFireDetectionSystemScreenImpl;
import com.sydac.mmrbem.tcms.backend.vehicle.request.handler.UFARStatusVehicleOutputsRequestHandler;
import com.sydac.mmrbem.tcms.common.data.VehicleDetailModel;
import com.sydac.mmrbem.tcms.common.io.properties.IAppInputsFireDetailsScreenProperties;
import com.sydac.mmrbem.tcms.common.io.properties.IAppInputsFireScreenProperties;
import com.sydac.mmrbem.tcms.common.io.properties.IAppInputsProperties;
import com.sydac.mmrbem.tcms.common.io.properties.IAppOutputsFireDetailsScreenProperties;
import com.sydac.mmrbem.tcms.common.state.ApplicationConstants;

/**
 * This handler class is used for handling Fire Detection System Status screen
 * data
 * 
 */
@Service
@FunctionalLogicHandler(arguments = { CommsBinding.class, SharedDataModel.class })
public class FireDetectionSystemStatusScreenHandler extends AbstractFunctionalLogic
{
  private static final Tracer LOGGER = Tracer.getInstance();

  private CommsBinding commsBinding;

  private SharedDataModel sharedModel;

  private IAppOutputsFireDetectionSystemScreenHandler appOutputsHandler;

  private List<VehicleDetailModel> vehicleDetailModelList;

  private static Map<PropertyKey<Integer>, ITCMSVehicleOutputsRequestHandler<TCMSOutputsFireDetectionSystemScreenImpl<Integer, IAppOutputsFireDetectionSystemScreenHandler>>> requestHandlerMap = new HashMap<>();

  private final FDUStatusVehicleOutputsRequestHandler fduStatusVehicleOutputsRequestHandler = new FDUStatusVehicleOutputsRequestHandler();

  private final FireSensorAlarmStatusVehicleOutputsRequestHandler fireSensorAlarmStatusVehicleOutputsRequestHandler = new FireSensorAlarmStatusVehicleOutputsRequestHandler();

  private final UFARStatusVehicleOutputsRequestHandler ufarStatusVehicleOutputsRequestHandler = new UFARStatusVehicleOutputsRequestHandler();

  private final SFARStatusVehicleOutputsRequestHandler sfarStatusVehicleOutputsRequestHandler = new SFARStatusVehicleOutputsRequestHandler();

  private final ExternalSmokeStatusVehicleOutputsRequestHandler externalSmokeStatusVehicleOutputsRequestHandler = new ExternalSmokeStatusVehicleOutputsRequestHandler();

  private final InternalFireStatusVehicleOutputsRequestHandler internalFireStatusVehicleOutputsRequestHandler = new InternalFireStatusVehicleOutputsRequestHandler();

  private ITCMSVehicleInputsFireHandler vehicleInputsHandler;

  private int selectedCarIndex = 0;

  protected FireDetectionSystemStatusScreenHandler(CommsBinding commsBinding, SharedDataModel sharedModel)
  {
    super(commsBinding, IAppInputsProperties.class, ITCMSVehicleOutputsFireDetectionSystemProperties.class);
    this.commsBinding = commsBinding;
    this.sharedModel = sharedModel;
    initalizeOutputHandler();
    initializeRequestHandlers();
    initalizeVehicleInputHandler();
  }

  /**
   * Listener to update vehicleDetailModelList
   */
  IModelListener trainConfigListener = (arg0,
      arg1) -> vehicleDetailModelList = sharedModel.getVehicleDetailModelList();

  private void initializeRequestHandlers()
  {
    requestHandlerMap.put(ITCMSVehicleOutputsFireDetectionSystemProperties.FIRE_DETECTION_UNIT,
        fduStatusVehicleOutputsRequestHandler);
    requestHandlerMap.put(ITCMSVehicleOutputsFireDetectionSystemProperties.FDU_FAULT,
        fduStatusVehicleOutputsRequestHandler);
    requestHandlerMap.put(ITCMSVehicleOutputsFireDetectionSystemProperties.SENSOR_FIRE_ALARM_STATUS,
        fireSensorAlarmStatusVehicleOutputsRequestHandler);
    requestHandlerMap.put(ITCMSVehicleOutputsProperties.DUMMY_FAULT_SIGNAL,
        fireSensorAlarmStatusVehicleOutputsRequestHandler);
    requestHandlerMap.put(ITCMSVehicleOutputsFireDetectionSystemProperties.EXTERNAL_SMOKE,
        externalSmokeStatusVehicleOutputsRequestHandler);
    requestHandlerMap.put(ITCMSVehicleOutputsProperties.DUMMY_FAULT_SIGNAL,
        externalSmokeStatusVehicleOutputsRequestHandler);
    requestHandlerMap.put(ITCMSVehicleOutputsFireDetectionSystemProperties.SALOON_FIRE_ALARM_STATUS,
        sfarStatusVehicleOutputsRequestHandler);
    requestHandlerMap.put(ITCMSVehicleOutputsFireDetectionSystemProperties.SFAR_FAULT,
        sfarStatusVehicleOutputsRequestHandler);
    requestHandlerMap.put(ITCMSVehicleOutputsFireDetectionSystemProperties.UNDERFRAME_FIRE_ALARM_STATUS,
        ufarStatusVehicleOutputsRequestHandler);
    requestHandlerMap.put(ITCMSVehicleOutputsProperties.DUMMY_FAULT_SIGNAL,
        ufarStatusVehicleOutputsRequestHandler);
    requestHandlerMap.put(ITCMSVehicleOutputsFireDetectionSystemProperties.INTERNAL_FIRE,
        internalFireStatusVehicleOutputsRequestHandler);
    requestHandlerMap.put(ITCMSVehicleOutputsProperties.DUMMY_FAULT_SIGNAL,
        internalFireStatusVehicleOutputsRequestHandler);
  }

  private void initalizeOutputHandler()
  {
    if (appOutputsHandler == null)
    {
      appOutputsHandler = (IAppOutputsFireDetectionSystemScreenHandler)this.commsBinding
          .getAppOutputsSetter();
    }
  }

  public <T> void appInputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue, int vehicleIndex)
  {
    if (getActiveVehicleIndex() == vehicleIndex)
    {
      if (key.equals(IAppInputsFireScreenProperties.RESET_FIRE_ALARM_REQ) && (Integer)newValue > -1)
      {
        updateTCMSFireAlarmReset((Integer)newValue);
      }
      else if (key.equals(IAppInputsFireScreenProperties.RESET_FDU_REQ) && (Integer)newValue > -1)
      {
        updateTCMSFduReset((Integer)newValue);
      }
      else if (key.equals(IAppInputsFireDetailsScreenProperties.FIRE_DETECTION_SELECTED_CAR_INDEX_REQ))
      {
        setApplicationOutputsProperty(
            IAppOutputsFireDetailsScreenProperties.FIRE_DETECTION_SELECTED_CAR_INDEX, (Integer)newValue);
      }
      else if (key.equals(IAppInputsFireDetailsScreenProperties.HVAC_1_FIRE_DETECTOR_DISABLE_VDU_REQ))
      {
        setApplicationOutputsProperty(IAppOutputsFireDetailsScreenProperties.HVAC_1_BUTTON_STATUS,
            (Integer)newValue);
        updateHVAC1FireDetectorDisableVduReq((Integer)newValue, selectedCarIndex);
      }
      else if (key.equals(IAppInputsFireDetailsScreenProperties.EDB_HEAT_ALARM_DISABLE_VDU_REQ))
      {
        setApplicationOutputsProperty(IAppOutputsFireDetailsScreenProperties.EDB_HEAT_BUTTON_STATUS,
            (Integer)newValue);
        updateEdbHeatAlarmDisableVduReq((Integer)newValue, selectedCarIndex);
      }
      else if (key.equals(IAppInputsFireDetailsScreenProperties.CAB_SMOKE_DETECTOR_DISABLE_VDU_REQ))
      {
        setApplicationOutputsProperty(IAppOutputsFireDetailsScreenProperties.CAB_SMOKE_BUTTON_STATUS,
            (Integer)newValue);
        updateCabSmokeDetectorDisableVduReq((Integer)newValue, selectedCarIndex);
      }
      else if (key.equals(IAppInputsFireDetailsScreenProperties.SHD_SALOON_L1_BUTTON_REQ))
      {
        setApplicationOutputsProperty(IAppOutputsFireDetailsScreenProperties.SHD_SALOON_L1_BUTTON_STATUS,
            (Integer)newValue);
      }
      else if (key.equals(IAppInputsFireDetailsScreenProperties.SHD_SALOON_L2_BUTTON_REQ))
      {
        setApplicationOutputsProperty(IAppOutputsFireDetailsScreenProperties.SHD_SALOON_L2_BUTTON_STATUS,
            (Integer)newValue);
      }
      else if (key.equals(IAppInputsFireDetailsScreenProperties.SHD_SALOON_L3_BUTTON_REQ))
      {
        setApplicationOutputsProperty(IAppOutputsFireDetailsScreenProperties.SHD_SALOON_L3_BUTTON_STATUS,
            (Integer)newValue);
      }
      else if (key.equals(IAppInputsFireDetailsScreenProperties.SHD_SALOON_R1_BUTTON_REQ))
      {
        setApplicationOutputsProperty(IAppOutputsFireDetailsScreenProperties.SHD_SALOON_R1_BUTTON_STATUS,
            (Integer)newValue);
        updateSaloonR1FireDetectorDisableVduReq((Integer)newValue, selectedCarIndex);
      }
      else if (key.equals(IAppInputsFireDetailsScreenProperties.SHD_SALOON_R2_BUTTON_REQ))
      {
        setApplicationOutputsProperty(IAppOutputsFireDetailsScreenProperties.SHD_SALOON_R2_BUTTON_STATUS,
            (Integer)newValue);
        updateSaloonR2FireDetectorDisableVduReq((Integer)newValue, selectedCarIndex);
      }
      else if (key.equals(IAppInputsFireDetailsScreenProperties.SHD_SALOON_R3_BUTTON_REQ))
      {
        setApplicationOutputsProperty(IAppOutputsFireDetailsScreenProperties.SHD_SALOON_R3_BUTTON_STATUS,
            (Integer)newValue);
      }
      else if (key.equals(IAppInputsFireDetailsScreenProperties.HD_HVAC_2_BUTTON_REQ))
      {
        setApplicationOutputsProperty(IAppOutputsFireDetailsScreenProperties.HD_HVAC_2_BUTTON_STATUS,
            (Integer)newValue);
      }
      else if (key.equals(IAppInputsFireDetailsScreenProperties.AUXILLARY_DESK_BUTTON_REQ))
      {
        setApplicationOutputsProperty(IAppOutputsFireDetailsScreenProperties.AUXILLARY_DESK_BUTTON_STATUS,
            (Integer)newValue);
        updateAuxillaryDeskFireDetectorDisableVduReq((Integer)newValue, selectedCarIndex);
      }
      else if (key.equals(IAppInputsFireDetailsScreenProperties.END_CUBICLE_RL1_BUTTON_REQ))
      {
        setApplicationOutputsProperty(IAppOutputsFireDetailsScreenProperties.END_CUBICLE_RL1_BUTTON_STATUS,
            (Integer)newValue);
        updateEndCubicleRL1ButtonReq((Integer)newValue, selectedCarIndex);
      }
      else if (key.equals(IAppInputsFireDetailsScreenProperties.END_CUBICLE_RL2_BUTTON_REQ))
      {
        setApplicationOutputsProperty(IAppOutputsFireDetailsScreenProperties.END_CUBICLE_RL2_BUTTON_STATUS,
            (Integer)newValue);
        updateEndCubicleRL2ButtonReq((Integer)newValue, selectedCarIndex);
      }
      else if (key.equals(IAppInputsFireDetailsScreenProperties.END_CUBICLE_RR1_BUTTON_REQ))
      {
        setApplicationOutputsProperty(IAppOutputsFireDetailsScreenProperties.END_CUBICLE_RR1_BUTTON_STATUS,
            (Integer)newValue);
        updateEndCubicleRR1ButtonReq((Integer)newValue, selectedCarIndex);
      }
      else if (key.equals(IAppInputsFireDetailsScreenProperties.END_CUBICLE_RR2_BUTTON_REQ))
      {
        setApplicationOutputsProperty(IAppOutputsFireDetailsScreenProperties.END_CUBICLE_RR2_BUTTON_STATUS,
            (Integer)newValue);
        updateEndCubicleRR2ButtonReq((Integer)newValue, selectedCarIndex);
      }
      else if (key.equals(IAppInputsFireDetailsScreenProperties.LHD_CI_DISABLE_VDU_REQ))
      {
        setApplicationOutputsProperty(IAppOutputsFireDetailsScreenProperties.LHD_CI_DISABLE_STATUS,
            (Integer)newValue);
        updateLhdCIDisableVduReq((Integer)newValue, selectedCarIndex);
      }
      else if (key.equals(IAppInputsFireDetailsScreenProperties.LHD_DRIVER_DESK_DISABLE_VDU_REQ))
      {
        setApplicationOutputsProperty(IAppOutputsFireDetailsScreenProperties.LHD_DRIVER_DESK_DISABLE_STATUS,
            (Integer)newValue);
        updateLhdDriverDeskDisableVduReq((Integer)newValue, selectedCarIndex);
      }
      else if (key.equals(IAppInputsFireDetailsScreenProperties.LHD_LTJB_DISABLE_VDU_REQ))
      {
        setApplicationOutputsProperty(IAppOutputsFireDetailsScreenProperties.LHD_LTJB_DISABLE_STATUS,
            (Integer)newValue);
        updateLhdLTJBDisableVduReq((Integer)newValue, selectedCarIndex);
      }
    }
  }

  private void updateLhdLTJBDisableVduReq(Integer newValue, int vehicleIndex)
  {
    vehicleInputsHandler = (ITCMSVehicleInputsFireHandler)getTCMSVehicleInputsSetter(vehicleIndex);
    vehicleInputsHandler.setLhdLtjbDisableVduReq((Integer)newValue);
  }

  private void updateLhdDriverDeskDisableVduReq(Integer newValue, int vehicleIndex)
  {
    vehicleInputsHandler = (ITCMSVehicleInputsFireHandler)getTCMSVehicleInputsSetter(vehicleIndex);
    vehicleInputsHandler.setLhdDriverDeskDisableVduReq((Integer)newValue);
  }

  private void updateLhdCIDisableVduReq(Integer newValue, int vehicleIndex)
  {
    vehicleInputsHandler = (ITCMSVehicleInputsFireHandler)getTCMSVehicleInputsSetter(vehicleIndex);
    vehicleInputsHandler.setLhdCiDisableVduReq((Integer)newValue);
  }

  private void updateSaloonR2FireDetectorDisableVduReq(Integer newValue, int vehicleIndex)
  {
    vehicleInputsHandler = (ITCMSVehicleInputsFireHandler)getTCMSVehicleInputsSetter(vehicleIndex);
    vehicleInputsHandler.setSaloonR2FireDetectorDisableVduReq((Integer)newValue);
  }

  private void updateSaloonR1FireDetectorDisableVduReq(Integer newValue, int vehicleIndex)
  {
    vehicleInputsHandler = (ITCMSVehicleInputsFireHandler)getTCMSVehicleInputsSetter(vehicleIndex);
    vehicleInputsHandler.setSaloonR1FireDetectorDisableVduReq((Integer)newValue);
  }

  private void updateAuxillaryDeskFireDetectorDisableVduReq(Integer newValue, int vehicleIndex)
  {
    vehicleInputsHandler = (ITCMSVehicleInputsFireHandler)getTCMSVehicleInputsSetter(vehicleIndex);
    vehicleInputsHandler.setAuxiliaryDeskFireDetectorDisableVduReq((Integer)newValue);
  }

  private void updateEndCubicleRL1ButtonReq(Integer newValue, int vehicleIndex)
  {
    vehicleInputsHandler = (ITCMSVehicleInputsFireHandler)getTCMSVehicleInputsSetter(vehicleIndex);
    vehicleInputsHandler.setShdEndCubicleRearLeft1DisableVduReq((Integer)newValue);
  }

  private void updateEndCubicleRR1ButtonReq(Integer newValue, int vehicleIndex)
  {
    vehicleInputsHandler = (ITCMSVehicleInputsFireHandler)getTCMSVehicleInputsSetter(vehicleIndex);
    vehicleInputsHandler.setShdEndCubicleRearRight1DisableVduReq((Integer)newValue);
  }

  private void updateEndCubicleRR2ButtonReq(Integer newValue, int vehicleIndex)
  {
    vehicleInputsHandler = (ITCMSVehicleInputsFireHandler)getTCMSVehicleInputsSetter(vehicleIndex);
    vehicleInputsHandler.setShdEndCubicleRearRight2DisableVduReq((Integer)newValue);
  }

  private void updateCabSmokeDetectorDisableVduReq(Integer newValue, int vehicleIndex)
  {
    vehicleInputsHandler = (ITCMSVehicleInputsFireHandler)getTCMSVehicleInputsSetter(vehicleIndex);
    vehicleInputsHandler.setCabSmokeDetectorDisableVduReq((Integer)newValue);
  }

  private void updateEdbHeatAlarmDisableVduReq(Integer newValue, int vehicleIndex)
  {
    vehicleInputsHandler = (ITCMSVehicleInputsFireHandler)getTCMSVehicleInputsSetter(vehicleIndex);
    vehicleInputsHandler.setShdEndCubicleRearLeft2DisableVduReq((Integer)newValue);
  }
  
  private void updateEndCubicleRL2ButtonReq(Integer newValue, int vehicleIndex)
  {
    vehicleInputsHandler = (ITCMSVehicleInputsFireHandler)getTCMSVehicleInputsSetter(vehicleIndex);
    vehicleInputsHandler.setEdbHeatAlarmDisableVduReq((Integer)newValue);
  }

  private void updateHVAC1FireDetectorDisableVduReq(Integer newValue, int vehicleIndex)
  {
    vehicleInputsHandler = (ITCMSVehicleInputsFireHandler)getTCMSVehicleInputsSetter(vehicleIndex);
    vehicleInputsHandler.setHvac1FireDetectorDisableVduReq((Integer)newValue);
  }

  @Override
  public <T> void tcmsVehicleOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue,
      int vehicleIndex)
  {
    initalizeOutputHandler();
    @SuppressWarnings("unchecked")
    PropertyKey<Integer> propertyKey = (PropertyKey<Integer>)key;
    try
    {
      ITCMSVehicleOutputsRequestHandler<TCMSOutputsFireDetectionSystemScreenImpl<Integer, IAppOutputsFireDetectionSystemScreenHandler>> handler = requestHandlerMap
          .get(key);
      if (handler != null)
      {
        handler.handleRequest(new TCMSOutputsFireDetectionSystemScreenImpl<>(propertyKey, (Integer)oldValue,
            (Integer)newValue, vehicleIndex, appOutputsHandler, vehicleDetailModelList));
      }
      else
      {
        LOGGER.debug(String.format("Cannot update, request Handler for key %S is not found", //$NON-NLS-1$
            propertyKey.toString()));
      }

      if (ITCMSVehicleOutputsProperties.POWER_OFF_PRESSED.equals(key) && Boolean.TRUE.equals(newValue))
      {
        resetInputCommands();
      }
    }
    catch (Exception e)
    {
      LOGGER.debug(e.getMessage());
      LOGGER.info(e);
    }

    if (getActiveVehicleIndex() == vehicleIndex)
    {
      if (key.equals(ITCMSVehicleOutputsFireDetectionSystemProperties.HVAC_1_FIRE_SMOKE_ACTIVE))
      {
        setApplicationOutputsProperty(IAppOutputsFireDetailsScreenProperties.HVAC_1_FIRE_SMOKE_ACTIVE_STATUS,
            (Integer)newValue);
      }
      else if (key.equals(ITCMSVehicleOutputsFireDetectionSystemProperties.EDB_HEAT_ALARM_ACTIVE))
      {
        setApplicationOutputsProperty(IAppOutputsFireDetailsScreenProperties.EDB_HEAT_ALARM_ACTIVE_STATUS,
            (Integer)newValue);
      }
      else if (key.equals(ITCMSVehicleOutputsFireDetectionSystemProperties.CAB_SMOKE_ALARM_ACTIVE))
      {
        setApplicationOutputsProperty(IAppOutputsFireDetailsScreenProperties.CAB_SMOKE_ALARM_ACTIVE_STATUS,
            (Integer)newValue);
      }
    }
  }

  /**
   * Attach listeners.
   */
  @Override
  public void attachListeners()
  {
    super.attachListeners();
    sharedModel.addModelListener(trainConfigListener, Change.TRAIN_CONFIGURED, true);
    initalizeVehicleInputHandler();
  }

  /**
   * Detach listeners.
   */
  @Override
  public void detachListeners()
  {
    super.detachListeners();
    sharedModel.removeModelListener(trainConfigListener, Change.TRAIN_CONFIGURED);
  }

  private <T> void updateTCMSFduReset(int newValue)
  {
    for (int carIndex = 0; carIndex < sharedModel.getTotalCar(); carIndex++)
    {
      vehicleInputsHandler = (ITCMSVehicleInputsFireHandler)getTCMSVehicleInputsSetter(carIndex);
      vehicleInputsHandler.setTcmsFduResetReq(newValue);
    }
  }

  private <T> void updateTCMSFireAlarmReset(int newValue)
  {

    for (int carIndex = 0; carIndex < sharedModel.getTotalCar(); carIndex++)
    {
      vehicleInputsHandler = (ITCMSVehicleInputsFireHandler)getTCMSVehicleInputsSetter(carIndex);

      vehicleInputsHandler.setTcmsFireAlarmResetReq(newValue);
    }
  }

  private void initalizeVehicleInputHandler()
  {
    if (vehicleInputsHandler == null)
    {
      vehicleInputsHandler = (ITCMSVehicleInputsFireHandler)getTCMSVehicleInputsSetter(
          getActiveVehicleIndex());
    }
  }

  private void resetInputCommands()
  {
    for (int carIndex = 0; carIndex < sharedModel.getTotalCar(); carIndex++)
    {
      vehicleInputsHandler = (ITCMSVehicleInputsFireHandler)getTCMSVehicleInputsSetter(carIndex);

      vehicleInputsHandler.setTcmsFireAlarmResetReq(ApplicationConstants.RESET_VALUE);
      vehicleInputsHandler.setTcmsFduResetReq(ApplicationConstants.RESET_VALUE);
    }

  }

}

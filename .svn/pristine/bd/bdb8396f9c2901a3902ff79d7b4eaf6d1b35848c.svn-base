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
import com.sydac.mmrbem.tcms.backend.app.io.handlers.IAppOutputsBrakeScreenHandler;
import com.sydac.mmrbem.tcms.backend.comms.CommsBinding;
import com.sydac.mmrbem.tcms.backend.logic.AbstractFunctionalLogic;
import com.sydac.mmrbem.tcms.backend.logic.SharedDataModel;
import com.sydac.mmrbem.tcms.backend.logic.SharedDataModel.Change;
import com.sydac.mmrbem.tcms.backend.logic.annotation.FunctionalLogicHandler;
import com.sydac.mmrbem.tcms.backend.vehicle.io.properties.ITCMSVehicleOutputsBrakeSystemProperties;
import com.sydac.mmrbem.tcms.backend.vehicle.request.handler.AirSuspensionPressureVehicleOutputRequestHandler;
import com.sydac.mmrbem.tcms.backend.vehicle.request.handler.BrakeControlUnitVehicleOutputsRequestHandler;
import com.sydac.mmrbem.tcms.backend.vehicle.request.handler.BrakeCylinderPressureVehicleOutputRequestHandler;
import com.sydac.mmrbem.tcms.backend.vehicle.request.handler.CarWeightVehicleOutputRequestHandler;
import com.sydac.mmrbem.tcms.backend.vehicle.request.handler.EdBrakeRequestedVehicleOutputRequestHandler;
import com.sydac.mmrbem.tcms.backend.vehicle.request.handler.EdCutoutRpessIsolationVehicleOutputRequestHandler;
import com.sydac.mmrbem.tcms.backend.vehicle.request.handler.EmergencyBrakeLineStatusVehicleOutputRequestHandler;
import com.sydac.mmrbem.tcms.backend.vehicle.request.handler.EpBrakeDeliveredVehicleOutputRequestHandler;
import com.sydac.mmrbem.tcms.backend.vehicle.request.handler.FSBVehicleOutputsRequestHandler;
import com.sydac.mmrbem.tcms.backend.vehicle.request.handler.HoldingBrakeEpicIsolationVehicleOutputRequestHandler;
import com.sydac.mmrbem.tcms.backend.vehicle.request.handler.ITCMSVehicleOutputsRequestHandler;
import com.sydac.mmrbem.tcms.backend.vehicle.request.handler.MainPipePressureVehicleOutputRequestHandler;
import com.sydac.mmrbem.tcms.backend.vehicle.request.handler.ParkingBrakeVehicleOutputsRequestHandler;
import com.sydac.mmrbem.tcms.backend.vehicle.request.handler.ServiceBrakeVehicleOutputsRequestHandler;
import com.sydac.mmrbem.tcms.backend.vehicle.request.handler.SuspVehicleOutputsRequestHandler;
import com.sydac.mmrbem.tcms.backend.vehicle.request.handler.TCMSOutputsBrakeSystemScreenImpl;
import com.sydac.mmrbem.tcms.backend.vehicle.request.handler.TrainLineVehicleOutputsRequestHandler;
import com.sydac.mmrbem.tcms.backend.vehicle.request.handler.WspVehicleOutputsRequestHandler;
import com.sydac.mmrbem.tcms.common.data.VehicleDetailModel;

/**
 * This handler class is used for handling Brake System Status screen data
 * 
 */
@Service
@FunctionalLogicHandler(arguments = { CommsBinding.class, SharedDataModel.class })
public class BrakeSystemScreenLogicHandler extends AbstractFunctionalLogic
{
  private static final Tracer LOGGER = Tracer.getInstance();

  private CommsBinding commsBinding;

  private SharedDataModel sharedModel;

  private IAppOutputsBrakeScreenHandler appOutputsHandler;

  private List<VehicleDetailModel> vehicleDetailModelList;

  private static Map<PropertyKey<Integer>, ITCMSVehicleOutputsRequestHandler<TCMSOutputsBrakeSystemScreenImpl<Integer, IAppOutputsBrakeScreenHandler>>> requestHandlerMap = new HashMap<>();

  private final ServiceBrakeVehicleOutputsRequestHandler serviceBrakeOutputHandler = new ServiceBrakeVehicleOutputsRequestHandler();

  private final ParkingBrakeVehicleOutputsRequestHandler parkingBrakeOutputHandler = new ParkingBrakeVehicleOutputsRequestHandler();

  private final WspVehicleOutputsRequestHandler wspVehicleOutputsRequestHandler = new WspVehicleOutputsRequestHandler();

  private final SuspVehicleOutputsRequestHandler suspVehicleOutputsRequestHandler = new SuspVehicleOutputsRequestHandler();

  private final BrakeControlUnitVehicleOutputsRequestHandler brakeControlUnitVehicleOutputsRequestHandler = new BrakeControlUnitVehicleOutputsRequestHandler();

  private final TrainLineVehicleOutputsRequestHandler trainLineVehicleOutputsRequestHandler = new TrainLineVehicleOutputsRequestHandler();

  private final FSBVehicleOutputsRequestHandler fsbVehicleOutputsRequestHandler = new FSBVehicleOutputsRequestHandler();

  private final EmergencyBrakeLineStatusVehicleOutputRequestHandler emergencyBrakeLineStatusVehicleOutputRequestHandler = new EmergencyBrakeLineStatusVehicleOutputRequestHandler();

  private final HoldingBrakeEpicIsolationVehicleOutputRequestHandler holdingBrakeEpicIsolationVehicleOutputRequestHandler = new HoldingBrakeEpicIsolationVehicleOutputRequestHandler();

  private final EdCutoutRpessIsolationVehicleOutputRequestHandler edCutoutRpessIsolationVehicleOutputRequestHandler = new EdCutoutRpessIsolationVehicleOutputRequestHandler();

  private final MainPipePressureVehicleOutputRequestHandler mainPipePressureVehicleOutputRequestHandler = new MainPipePressureVehicleOutputRequestHandler();

  private final BrakeCylinderPressureVehicleOutputRequestHandler brakeCylinderPressureVehicleOutputRequestHandler = new BrakeCylinderPressureVehicleOutputRequestHandler();

  private final AirSuspensionPressureVehicleOutputRequestHandler airSuspensionPressureVehicleOutputRequestHandler = new AirSuspensionPressureVehicleOutputRequestHandler();

  private final EpBrakeDeliveredVehicleOutputRequestHandler epBrakeDeliveredVehicleOutputRequestHandler = new EpBrakeDeliveredVehicleOutputRequestHandler();

  private final EdBrakeRequestedVehicleOutputRequestHandler edBrakeRequestedVehicleOutputRequestHandler = new EdBrakeRequestedVehicleOutputRequestHandler();

  private final CarWeightVehicleOutputRequestHandler carWeightVehicleOutputRequestHandler = new CarWeightVehicleOutputRequestHandler();

  protected BrakeSystemScreenLogicHandler(CommsBinding commsBinding, SharedDataModel sharedModel)
  {
    super(commsBinding, ITCMSVehicleOutputsBrakeSystemProperties.class);
    this.commsBinding = commsBinding;
    this.sharedModel = sharedModel;
    initalizeOutputHandler();
    initializeRequestHandlers();
  }

  /**
   * Listener to update vehicleDetailModelList
   */
  IModelListener trainConfigListener = (arg0, arg1) -> {
    vehicleDetailModelList = sharedModel.getVehicleDetailModelList();
  };

  private void initializeRequestHandlers()
  {
    requestHandlerMap.put(ITCMSVehicleOutputsBrakeSystemProperties.BOGIE_1_SERVICE_BRAKE_STATUS,
        serviceBrakeOutputHandler);
    requestHandlerMap.put(ITCMSVehicleOutputsBrakeSystemProperties.BOGIE_1_SERVICE_BRAKE_ISOLATED,
        serviceBrakeOutputHandler);
    requestHandlerMap.put(ITCMSVehicleOutputsBrakeSystemProperties.BOGIE_1_SERV_BRAKE_FAULT,
        serviceBrakeOutputHandler);
    requestHandlerMap.put(ITCMSVehicleOutputsBrakeSystemProperties.BOGIE_2_SERVICE_BRAKE_STATUS,
        serviceBrakeOutputHandler);
    requestHandlerMap.put(ITCMSVehicleOutputsBrakeSystemProperties.BOGIE_2_SERVICE_BRAKE_ISOLATED,
        serviceBrakeOutputHandler);
    requestHandlerMap.put(ITCMSVehicleOutputsBrakeSystemProperties.BOGIE_2_SERV_BRAKE_FAULT,
        serviceBrakeOutputHandler);
    requestHandlerMap.put(ITCMSVehicleOutputsBrakeSystemProperties.BOGIE_1_PARKING_BRAKE_STATUS,
        parkingBrakeOutputHandler);
    requestHandlerMap.put(ITCMSVehicleOutputsBrakeSystemProperties.BOGIE_1_PARKING_BRAKE_ISOLATED,
        parkingBrakeOutputHandler);
    requestHandlerMap.put(ITCMSVehicleOutputsBrakeSystemProperties.BOGIE_2_PARKING_BRAKE_STATUS,
        parkingBrakeOutputHandler);
    requestHandlerMap.put(ITCMSVehicleOutputsBrakeSystemProperties.BOGIE_2_PARKING_BRAKE_ISOLATED,
        parkingBrakeOutputHandler);
    requestHandlerMap.put(ITCMSVehicleOutputsBrakeSystemProperties.BOGIE_1_WSP_STATUS,
        wspVehicleOutputsRequestHandler);
    requestHandlerMap.put(ITCMSVehicleOutputsBrakeSystemProperties.BOGIE_2_WSP_STATUS,
        wspVehicleOutputsRequestHandler);
    requestHandlerMap.put(ITCMSVehicleOutputsBrakeSystemProperties.BOGIE_1_SUSP_STATUS,
        suspVehicleOutputsRequestHandler);
    requestHandlerMap.put(ITCMSVehicleOutputsBrakeSystemProperties.BOGIE_2_SUSP_STATUS,
        suspVehicleOutputsRequestHandler);
    requestHandlerMap.put(ITCMSVehicleOutputsBrakeSystemProperties.BECU_STATUS,
        brakeControlUnitVehicleOutputsRequestHandler);
    requestHandlerMap.put(ITCMSVehicleOutputsBrakeSystemProperties.BECU_MAJOR_FAULT,
        brakeControlUnitVehicleOutputsRequestHandler);
    requestHandlerMap.put(ITCMSVehicleOutputsBrakeSystemProperties.BECU_MINOR_FAULT,
        brakeControlUnitVehicleOutputsRequestHandler);
    requestHandlerMap.put(ITCMSVehicleOutputsBrakeSystemProperties.BRAKE_TRAIN_LINE_STATUS,
        trainLineVehicleOutputsRequestHandler);
    requestHandlerMap.put(ITCMSVehicleOutputsBrakeSystemProperties.MOTOR_TRAIN_LINE_STATUS,
        trainLineVehicleOutputsRequestHandler);
    requestHandlerMap.put(ITCMSVehicleOutputsBrakeSystemProperties.FSB_1_LINE_STATUS,
        fsbVehicleOutputsRequestHandler);
    requestHandlerMap.put(ITCMSVehicleOutputsBrakeSystemProperties.FSB_2_LINE_STATUS,
        fsbVehicleOutputsRequestHandler);
    requestHandlerMap.put(ITCMSVehicleOutputsBrakeSystemProperties.EB_1_LINE_STATUS,
        emergencyBrakeLineStatusVehicleOutputRequestHandler);
    requestHandlerMap.put(ITCMSVehicleOutputsBrakeSystemProperties.EB_2_LINE_STATUS,
        emergencyBrakeLineStatusVehicleOutputRequestHandler);
    requestHandlerMap.put(ITCMSVehicleOutputsBrakeSystemProperties.HOLDING_BRAKE_STATUS,
        holdingBrakeEpicIsolationVehicleOutputRequestHandler);
    requestHandlerMap.put(ITCMSVehicleOutputsBrakeSystemProperties.EPIC_ISOLATION_STATUS,
        holdingBrakeEpicIsolationVehicleOutputRequestHandler);
    requestHandlerMap.put(ITCMSVehicleOutputsBrakeSystemProperties.ED_CUTOUT_STATUS,
        edCutoutRpessIsolationVehicleOutputRequestHandler);
    requestHandlerMap.put(ITCMSVehicleOutputsBrakeSystemProperties.RPRESS_ISOLATION_STATUS,
        edCutoutRpessIsolationVehicleOutputRequestHandler);
    requestHandlerMap.put(ITCMSVehicleOutputsBrakeSystemProperties.MAIN_PIPE_PRESSURE,
        mainPipePressureVehicleOutputRequestHandler);
    requestHandlerMap.put(ITCMSVehicleOutputsBrakeSystemProperties.BOGIE_1_BRAKE_CYLINDER_PRESSURE,
        brakeCylinderPressureVehicleOutputRequestHandler);
    requestHandlerMap.put(ITCMSVehicleOutputsBrakeSystemProperties.BOGIE_2_BRAKE_CYLINDER_PRESSURE,
        brakeCylinderPressureVehicleOutputRequestHandler);
    requestHandlerMap.put(ITCMSVehicleOutputsBrakeSystemProperties.AIR_SUSPENSION_PRESSURE,
        airSuspensionPressureVehicleOutputRequestHandler);
    requestHandlerMap.put(ITCMSVehicleOutputsBrakeSystemProperties.EP_BRAKE_DELIVERED,
        epBrakeDeliveredVehicleOutputRequestHandler);
    requestHandlerMap.put(ITCMSVehicleOutputsBrakeSystemProperties.ED_BRAKE_REQUESTED,
        edBrakeRequestedVehicleOutputRequestHandler);
    requestHandlerMap.put(ITCMSVehicleOutputsBrakeSystemProperties.CAR_WEIGHT,
        carWeightVehicleOutputRequestHandler);
    requestHandlerMap.put(ITCMSVehicleOutputsBrakeSystemProperties.BOGIE_1_SUSP_FAULT,
        suspVehicleOutputsRequestHandler);
    requestHandlerMap.put(ITCMSVehicleOutputsBrakeSystemProperties.BOGIE_2_SUSP_FAULT,
        suspVehicleOutputsRequestHandler);
  }

  private void initalizeOutputHandler()
  {
    if (appOutputsHandler == null)
    {
      appOutputsHandler = (IAppOutputsBrakeScreenHandler)this.commsBinding.getAppOutputsSetter();
    }
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
      ITCMSVehicleOutputsRequestHandler<TCMSOutputsBrakeSystemScreenImpl<Integer, IAppOutputsBrakeScreenHandler>> handler = requestHandlerMap
          .get(key);
      if (handler != null)
      {
        handler.handleRequest(new TCMSOutputsBrakeSystemScreenImpl<>(propertyKey, (Integer)oldValue,
            (Integer)newValue, vehicleIndex, appOutputsHandler, vehicleDetailModelList));
      }
      else
      {
        LOGGER.debug(String.format("Cannot update, request Handler for key %S is not found", //$NON-NLS-1$
            propertyKey.toString()));
      }
    }
    catch (Exception e)
    {
      LOGGER.debug(e.getMessage());
      LOGGER.info(e);
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

}

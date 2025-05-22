/*
 * ================================================================== (C)
 * Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
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
import com.sydac.mmrbem.tcms.backend.app.io.handlers.IAppOutputsOperationScreenHandler;
import com.sydac.mmrbem.tcms.backend.comms.CommsBinding;
import com.sydac.mmrbem.tcms.backend.logic.AbstractFunctionalLogic;
import com.sydac.mmrbem.tcms.backend.logic.SharedDataModel;
import com.sydac.mmrbem.tcms.backend.logic.SharedDataModel.Change;
import com.sydac.mmrbem.tcms.backend.logic.annotation.FunctionalLogicHandler;
import com.sydac.mmrbem.tcms.backend.vehicle.io.properties.ITCMSVehicleOutputsOperationScreenProperties;
import com.sydac.mmrbem.tcms.backend.vehicle.io.properties.ITCMSVehicleOutputsPropulsionSystemProperties;
import com.sydac.mmrbem.tcms.backend.vehicle.request.handler.CIStatusVehicleOutputRequestHandler;
import com.sydac.mmrbem.tcms.backend.vehicle.request.handler.ITCMSVehicleOutputsRequestHandler;
import com.sydac.mmrbem.tcms.backend.vehicle.request.handler.PantoVehicleOutputRequestHandler;
import com.sydac.mmrbem.tcms.backend.vehicle.request.handler.ParkBrakeStatusVehicleOutputRequestHandler;
import com.sydac.mmrbem.tcms.backend.vehicle.request.handler.PropulsionStatusVehicleOutputRequestHandler;
import com.sydac.mmrbem.tcms.backend.vehicle.request.handler.ServiceBrakeStatusVehicleOutputRequestHandler;
import com.sydac.mmrbem.tcms.backend.vehicle.request.handler.TCMSOutputsTrainViewScreenImpl;
import com.sydac.mmrbem.tcms.backend.vehicle.request.handler.TrainSideViewVehicleOutputRequestHandler;
import com.sydac.mmrbem.tcms.backend.vehicle.request.handler.VcbVehicleOutputRequestHandler;
import com.sydac.mmrbem.tcms.common.data.VehicleDetailModel;

/**
 * This handler class handle the Train View screen data.
 */
@Service
@FunctionalLogicHandler(arguments = { CommsBinding.class, SharedDataModel.class })
public class TrainViewScreenHandler extends AbstractFunctionalLogic
{
  private static final Tracer LOGGER = Tracer.getInstance();

  private CommsBinding commsBinding;

  private SharedDataModel sharedModel;

  private IAppOutputsOperationScreenHandler appOutputsHandler;

  private List<VehicleDetailModel> vehicleDetailModelList;

  private static Map<PropertyKey<Integer>, ITCMSVehicleOutputsRequestHandler<TCMSOutputsTrainViewScreenImpl<Integer, IAppOutputsOperationScreenHandler>>> requestHandlerMap = new HashMap<>();

  private final PantoVehicleOutputRequestHandler pantographRequestHandler = new PantoVehicleOutputRequestHandler();

  private final VcbVehicleOutputRequestHandler vcbRequestHandler = new VcbVehicleOutputRequestHandler();

  private final TrainSideViewVehicleOutputRequestHandler sideViewRequestHandler = new TrainSideViewVehicleOutputRequestHandler();

  private final PropulsionStatusVehicleOutputRequestHandler propulsionRequestHandler = new PropulsionStatusVehicleOutputRequestHandler();

  private final ServiceBrakeStatusVehicleOutputRequestHandler serviceBrakeRequestHandler = new ServiceBrakeStatusVehicleOutputRequestHandler();

  private final ParkBrakeStatusVehicleOutputRequestHandler parkBrakeRequestHandler = new ParkBrakeStatusVehicleOutputRequestHandler();
  
  private final CIStatusVehicleOutputRequestHandler ciRequestHandler = new CIStatusVehicleOutputRequestHandler();

  public TrainViewScreenHandler(CommsBinding commsBinding, SharedDataModel sharedModel)
  {
    super(commsBinding, ITCMSVehicleOutputsOperationScreenProperties.class);
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
    requestHandlerMap.put(ITCMSVehicleOutputsOperationScreenProperties.PANTOGRAPH_POSITION,
        pantographRequestHandler);
    requestHandlerMap.put(ITCMSVehicleOutputsOperationScreenProperties.PANTOGRAPH_FAULT,
        pantographRequestHandler);
    requestHandlerMap.put(ITCMSVehicleOutputsOperationScreenProperties.PANTOGRAPH_ISOLATED,
        pantographRequestHandler);
    requestHandlerMap.put(ITCMSVehicleOutputsOperationScreenProperties.VCB_STATE, vcbRequestHandler);
    requestHandlerMap.put(ITCMSVehicleOutputsOperationScreenProperties.VCB_ISOLATED, vcbRequestHandler);
    requestHandlerMap.put(ITCMSVehicleOutputsOperationScreenProperties.VCB_FAULT, vcbRequestHandler);
    requestHandlerMap.put(ITCMSVehicleOutputsOperationScreenProperties.CAB_ACTIVE, sideViewRequestHandler);
    requestHandlerMap.put(ITCMSVehicleOutputsOperationScreenProperties.BOGIE_1_ISOLATION_STATUS,
        sideViewRequestHandler);
    requestHandlerMap.put(ITCMSVehicleOutputsOperationScreenProperties.BOGIE_2_ISOLATION_STATUS,
        sideViewRequestHandler);
    requestHandlerMap.put(ITCMSVehicleOutputsOperationScreenProperties.FORWARD_DIRECTION,
        sideViewRequestHandler);
    requestHandlerMap.put(ITCMSVehicleOutputsOperationScreenProperties.REVERSE_DIRECTION,
        sideViewRequestHandler);
    requestHandlerMap.put(ITCMSVehicleOutputsOperationScreenProperties.PROPULSION_ACTIVE,
        propulsionRequestHandler);
    requestHandlerMap.put(ITCMSVehicleOutputsOperationScreenProperties.PROPULSION_FAULT,
        propulsionRequestHandler);
    requestHandlerMap.put(ITCMSVehicleOutputsOperationScreenProperties.PROPULSION_ISOLATED,
        propulsionRequestHandler);
    requestHandlerMap.put(ITCMSVehicleOutputsOperationScreenProperties.SERVICE_BRAKE_ACTIVE,
        serviceBrakeRequestHandler);
    requestHandlerMap.put(ITCMSVehicleOutputsOperationScreenProperties.BOGIE_1_SERVICE_BRAKE_FAULT,
        serviceBrakeRequestHandler);
    requestHandlerMap.put(ITCMSVehicleOutputsOperationScreenProperties.BOGIE_2_SERVICE_BRAKE_FAULT,
        serviceBrakeRequestHandler);
    requestHandlerMap.put(ITCMSVehicleOutputsOperationScreenProperties.PARK_BRAKE_APPLIED,
        parkBrakeRequestHandler);
    requestHandlerMap.put(ITCMSVehicleOutputsOperationScreenProperties.PARK_BRAKE_ISOLATED,
        parkBrakeRequestHandler);
    requestHandlerMap.put(ITCMSVehicleOutputsOperationScreenProperties.CI_STATUS,
        ciRequestHandler);
    requestHandlerMap.put(ITCMSVehicleOutputsOperationScreenProperties.CI_ISOLATED,
        ciRequestHandler);
    
    requestHandlerMap.put(ITCMSVehicleOutputsOperationScreenProperties.CI_FAULT,
            ciRequestHandler);
    
  }

  private void initalizeOutputHandler()
  {
    if (appOutputsHandler == null)
    {
      appOutputsHandler = (IAppOutputsOperationScreenHandler)this.commsBinding.getAppOutputsSetter();
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
      ITCMSVehicleOutputsRequestHandler<TCMSOutputsTrainViewScreenImpl<Integer, IAppOutputsOperationScreenHandler>> handler = requestHandlerMap
          .get(key);
      if (handler != null)
      {
        handler.handleRequest(new TCMSOutputsTrainViewScreenImpl<>(propertyKey, (Integer)oldValue,
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

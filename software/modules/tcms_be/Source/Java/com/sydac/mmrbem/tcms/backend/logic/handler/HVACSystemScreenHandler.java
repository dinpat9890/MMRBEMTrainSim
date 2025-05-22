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
import com.sydac.mmrbem.tcms.backend.app.io.handlers.IAppOutputsHVACSystemScreenHandler;
import com.sydac.mmrbem.tcms.backend.comms.CommsBinding;
import com.sydac.mmrbem.tcms.backend.logic.AbstractFunctionalLogic;
import com.sydac.mmrbem.tcms.backend.logic.SharedDataModel;
import com.sydac.mmrbem.tcms.backend.logic.SharedDataModel.Change;
import com.sydac.mmrbem.tcms.backend.logic.annotation.FunctionalLogicHandler;
import com.sydac.mmrbem.tcms.backend.vehicle.io.properties.ITCMSVehicleOutputsHVACSystemScreenProperties;
import com.sydac.mmrbem.tcms.backend.vehicle.request.handler.HVAC1ExternalTemperatureVehicleOutputRequestHandler;
import com.sydac.mmrbem.tcms.backend.vehicle.request.handler.HVAC1InternalTemperatureVehicleOutputRequestHandler;
import com.sydac.mmrbem.tcms.backend.vehicle.request.handler.HVAC1SetPointTemperatureVehicleOutputRequestHandler;
import com.sydac.mmrbem.tcms.backend.vehicle.request.handler.HVAC2ExternalTemperatureVehicleOutputRequestHandler;
import com.sydac.mmrbem.tcms.backend.vehicle.request.handler.HVAC2InternalTemperatureVehicleOutputRequestHandler;
import com.sydac.mmrbem.tcms.backend.vehicle.request.handler.HVAC2SetPointTemperatureVehicleOutputRequestHandler;
import com.sydac.mmrbem.tcms.backend.vehicle.request.handler.HVACOpModeStatus1VehicleOutputsRequestHandler;
import com.sydac.mmrbem.tcms.backend.vehicle.request.handler.HVACOpModeStatus2VehicleOutputsRequestHandler;
import com.sydac.mmrbem.tcms.backend.vehicle.request.handler.ITCMSVehicleOutputsRequestHandler;
import com.sydac.mmrbem.tcms.backend.vehicle.request.handler.TCMSOutputsHVACSystemScreenImpl;
import com.sydac.mmrbem.tcms.common.data.VehicleDetailModel;

/**
 * This handler class is used for handling HVAC System Status screen data
 * 
 */
@Service
@FunctionalLogicHandler(arguments = { CommsBinding.class, SharedDataModel.class })
public class HVACSystemScreenHandler extends AbstractFunctionalLogic
{
  private static final Tracer LOGGER = Tracer.getInstance();

  private CommsBinding commsBinding;

  private SharedDataModel sharedModel;

  private IAppOutputsHVACSystemScreenHandler appOutputsHandler;

  private List<VehicleDetailModel> vehicleDetailModelList;

  private static Map<PropertyKey<Integer>, ITCMSVehicleOutputsRequestHandler<TCMSOutputsHVACSystemScreenImpl<Integer, IAppOutputsHVACSystemScreenHandler>>> requestHandlerMap = new HashMap<>();

  private final HVACOpModeStatus1VehicleOutputsRequestHandler hvacOpModeStatus1VehicleOutputsRequestHandler = new HVACOpModeStatus1VehicleOutputsRequestHandler();

  private final HVACOpModeStatus2VehicleOutputsRequestHandler hvacOpModeStatus2VehicleOutputsRequestHandler = new HVACOpModeStatus2VehicleOutputsRequestHandler();

  private final HVAC1SetPointTemperatureVehicleOutputRequestHandler hvac1SetPointTemperatureVehicleOutputRequestHandler = new HVAC1SetPointTemperatureVehicleOutputRequestHandler();

  private final HVAC2SetPointTemperatureVehicleOutputRequestHandler hvac2SetPointTemperatureVehicleOutputRequestHandler = new HVAC2SetPointTemperatureVehicleOutputRequestHandler();

  private final HVAC1InternalTemperatureVehicleOutputRequestHandler hvac1InternalTemperatureVehicleOutputRequestHandler = new HVAC1InternalTemperatureVehicleOutputRequestHandler();

  private final HVAC2InternalTemperatureVehicleOutputRequestHandler hvac2InternalTemperatureVehicleOutputRequestHandler = new HVAC2InternalTemperatureVehicleOutputRequestHandler();

  private final HVAC1ExternalTemperatureVehicleOutputRequestHandler hvac1ExternalTemperatureVehicleOutputRequestHandler = new HVAC1ExternalTemperatureVehicleOutputRequestHandler();

  private final HVAC2ExternalTemperatureVehicleOutputRequestHandler hvac2ExternalTemperatureVehicleOutputRequestHandler = new HVAC2ExternalTemperatureVehicleOutputRequestHandler();

  protected HVACSystemScreenHandler(CommsBinding commsBinding, SharedDataModel sharedModel)
  {
    super(commsBinding, ITCMSVehicleOutputsHVACSystemScreenProperties.class);
    this.commsBinding = commsBinding;
    this.sharedModel = sharedModel;
    initalizeOutputHandler();
    initializeRequestHandlers();
  }

  /**
   * Listener to update vehicleDetailModelList
   */
  IModelListener trainConfigListener = (arg0,
      arg1) -> vehicleDetailModelList = sharedModel.getVehicleDetailModelList();

  private void initializeRequestHandlers()
  {
    requestHandlerMap.put(ITCMSVehicleOutputsHVACSystemScreenProperties.HVAC_1_STATUS,
        hvacOpModeStatus1VehicleOutputsRequestHandler);
    requestHandlerMap.put(ITCMSVehicleOutputsHVACSystemScreenProperties.HVAC_1_FAULT,
        hvacOpModeStatus1VehicleOutputsRequestHandler);
    requestHandlerMap.put(ITCMSVehicleOutputsHVACSystemScreenProperties.HVAC_1_ISOLATED,
        hvacOpModeStatus1VehicleOutputsRequestHandler);
    requestHandlerMap.put(ITCMSVehicleOutputsHVACSystemScreenProperties.HVAC_2_STATUS,
        hvacOpModeStatus2VehicleOutputsRequestHandler);
    requestHandlerMap.put(ITCMSVehicleOutputsHVACSystemScreenProperties.HVAC_2_FAULT,
        hvacOpModeStatus2VehicleOutputsRequestHandler);
    requestHandlerMap.put(ITCMSVehicleOutputsHVACSystemScreenProperties.HVAC_2_ISOLATED,
        hvacOpModeStatus2VehicleOutputsRequestHandler);
    requestHandlerMap.put(ITCMSVehicleOutputsHVACSystemScreenProperties.HVAC_1_SET_POINT_TEMPERATURE,
        hvac1SetPointTemperatureVehicleOutputRequestHandler);
    requestHandlerMap.put(ITCMSVehicleOutputsHVACSystemScreenProperties.HVAC_2_SET_POINT_TEMPERATURE,
        hvac2SetPointTemperatureVehicleOutputRequestHandler);
    requestHandlerMap.put(ITCMSVehicleOutputsHVACSystemScreenProperties.HVAC_1_INTERNAL_TEMPERATURE,
        hvac1InternalTemperatureVehicleOutputRequestHandler);
    requestHandlerMap.put(ITCMSVehicleOutputsHVACSystemScreenProperties.HVAC_2_INTERNAL_TEMPERATURE,
        hvac2InternalTemperatureVehicleOutputRequestHandler);
    requestHandlerMap.put(ITCMSVehicleOutputsHVACSystemScreenProperties.HVAC_1_EXTERNAL_TEMPERATURE,
        hvac1ExternalTemperatureVehicleOutputRequestHandler);
    requestHandlerMap.put(ITCMSVehicleOutputsHVACSystemScreenProperties.HVAC_2_EXTERNAL_TEMPERATURE,
        hvac2ExternalTemperatureVehicleOutputRequestHandler);
    requestHandlerMap.put(ITCMSVehicleOutputsHVACSystemScreenProperties.HVAC_1_REDUCED_MODE,
        hvacOpModeStatus1VehicleOutputsRequestHandler);
    
    requestHandlerMap.put(ITCMSVehicleOutputsHVACSystemScreenProperties.HVAC_2_REDUCED_MODE,
        hvacOpModeStatus2VehicleOutputsRequestHandler);
  }

  private void initalizeOutputHandler()
  {
    if (appOutputsHandler == null)
    {
      appOutputsHandler = (IAppOutputsHVACSystemScreenHandler)this.commsBinding.getAppOutputsSetter();
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
      ITCMSVehicleOutputsRequestHandler<TCMSOutputsHVACSystemScreenImpl<Integer, IAppOutputsHVACSystemScreenHandler>> handler = requestHandlerMap
          .get(key);
      if (handler != null)
      {
        handler.handleRequest(new TCMSOutputsHVACSystemScreenImpl<>(propertyKey, (Integer)oldValue,
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

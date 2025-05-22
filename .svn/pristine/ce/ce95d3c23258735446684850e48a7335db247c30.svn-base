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
import com.sydac.mmrbem.tcms.backend.app.io.handlers.IAppOutputsBatteryScreenHandler;
import com.sydac.mmrbem.tcms.backend.comms.CommsBinding;
import com.sydac.mmrbem.tcms.backend.logic.AbstractFunctionalLogic;
import com.sydac.mmrbem.tcms.backend.logic.SharedDataModel;
import com.sydac.mmrbem.tcms.backend.logic.SharedDataModel.Change;
import com.sydac.mmrbem.tcms.backend.logic.annotation.FunctionalLogicHandler;
import com.sydac.mmrbem.tcms.backend.vehicle.io.properties.ITCMSVehicleOutputsBatterySystemProperties;
import com.sydac.mmrbem.tcms.backend.vehicle.request.handler.BatteryCurrentVehicleOutputsRequestHandler;
import com.sydac.mmrbem.tcms.backend.vehicle.request.handler.BatteryTemperatureVehicleOutputsRequestHandler;
import com.sydac.mmrbem.tcms.backend.vehicle.request.handler.BatteryVoltageVehicleOutputsRequestHandler;
import com.sydac.mmrbem.tcms.backend.vehicle.request.handler.BcgOutputVoltageVehicleOutputsRequestHandler;
import com.sydac.mmrbem.tcms.backend.vehicle.request.handler.BcgStatusVehicleOutputsRequestHandler;
import com.sydac.mmrbem.tcms.backend.vehicle.request.handler.ITCMSVehicleOutputsRequestHandler;
import com.sydac.mmrbem.tcms.backend.vehicle.request.handler.OutputCurrentVehicleOutputsRequestHandler;
import com.sydac.mmrbem.tcms.backend.vehicle.request.handler.TCMSOutputsBatterySystemScreenImpl;
import com.sydac.mmrbem.tcms.backend.vehicle.request.handler.TotalOutputCurrentVehicleOutputsRequestHandler;
import com.sydac.mmrbem.tcms.common.data.VehicleDetailModel;

/**
 * This handler class is used for handling Battery System Status screen data
 * 
 */
@Service
@FunctionalLogicHandler(arguments = { CommsBinding.class, SharedDataModel.class })
public class BatterySystemLogicHandler extends AbstractFunctionalLogic
{
  private static final Tracer LOGGER = Tracer.getInstance();

  private CommsBinding commsBinding;

  private SharedDataModel sharedModel;

  private IAppOutputsBatteryScreenHandler appOutputsHandler;

  private List<VehicleDetailModel> vehicleDetailModelList;

  private static Map<PropertyKey<Integer>, ITCMSVehicleOutputsRequestHandler<TCMSOutputsBatterySystemScreenImpl<Integer, IAppOutputsBatteryScreenHandler>>> requestHandlerMap = new HashMap<>();

  private final BcgStatusVehicleOutputsRequestHandler bcgStatusVehicleOutputsRequestHandler = new BcgStatusVehicleOutputsRequestHandler();

  private final BcgOutputVoltageVehicleOutputsRequestHandler bcgOutputVoltageVehicleOutputsRequestHandler = new BcgOutputVoltageVehicleOutputsRequestHandler();

  private final BatteryVoltageVehicleOutputsRequestHandler batteryVoltageVehicleOutputsRequestHandler = new BatteryVoltageVehicleOutputsRequestHandler();

  private final OutputCurrentVehicleOutputsRequestHandler outputCurrentVehicleOutputsRequestHandler = new OutputCurrentVehicleOutputsRequestHandler();

  private final TotalOutputCurrentVehicleOutputsRequestHandler totalOutputCurrentVehicleOutputsRequestHandler = new TotalOutputCurrentVehicleOutputsRequestHandler();

  private final BatteryCurrentVehicleOutputsRequestHandler batteryCurrentVehicleOutputsRequestHandler = new BatteryCurrentVehicleOutputsRequestHandler();

  private final BatteryTemperatureVehicleOutputsRequestHandler batteryTemperatureVehicleOutputsRequestHandler = new BatteryTemperatureVehicleOutputsRequestHandler();

  protected BatterySystemLogicHandler(CommsBinding commsBinding, SharedDataModel sharedModel)
  {
    super(commsBinding, ITCMSVehicleOutputsBatterySystemProperties.class);
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
    requestHandlerMap.put(ITCMSVehicleOutputsBatterySystemProperties.BCG_1_FAULT,
        bcgStatusVehicleOutputsRequestHandler);
    requestHandlerMap.put(ITCMSVehicleOutputsBatterySystemProperties.BCG_1_ISOLATED,
        bcgStatusVehicleOutputsRequestHandler);
    requestHandlerMap.put(ITCMSVehicleOutputsBatterySystemProperties.BCG_1_STATUS,
        bcgStatusVehicleOutputsRequestHandler);
    requestHandlerMap.put(ITCMSVehicleOutputsBatterySystemProperties.BCG_2_FAULT,
        bcgStatusVehicleOutputsRequestHandler);
    requestHandlerMap.put(ITCMSVehicleOutputsBatterySystemProperties.BCG_2_ISOLATED,
        bcgStatusVehicleOutputsRequestHandler);
    requestHandlerMap.put(ITCMSVehicleOutputsBatterySystemProperties.BCG_2_STATUS,
        bcgStatusVehicleOutputsRequestHandler);
    requestHandlerMap.put(ITCMSVehicleOutputsBatterySystemProperties.BCG_OUTPUT_VOLTAGE,
        bcgOutputVoltageVehicleOutputsRequestHandler);
    requestHandlerMap.put(ITCMSVehicleOutputsBatterySystemProperties.BATTERY_VOLTAGE,
        batteryVoltageVehicleOutputsRequestHandler);
    requestHandlerMap.put(ITCMSVehicleOutputsBatterySystemProperties.BCG_1_OUTPUT_CURRENT,
        outputCurrentVehicleOutputsRequestHandler);
    requestHandlerMap.put(ITCMSVehicleOutputsBatterySystemProperties.BCG_2_OUTPUT_CURRENT,
        outputCurrentVehicleOutputsRequestHandler);
    requestHandlerMap.put(ITCMSVehicleOutputsBatterySystemProperties.TOTAL_OUTPUT_CURRENT,
        totalOutputCurrentVehicleOutputsRequestHandler);
    requestHandlerMap.put(ITCMSVehicleOutputsBatterySystemProperties.BATTERY_CURRENT,
        batteryCurrentVehicleOutputsRequestHandler);
    requestHandlerMap.put(ITCMSVehicleOutputsBatterySystemProperties.BATTERY_TEMPERATURE,
        batteryTemperatureVehicleOutputsRequestHandler);
  }

  private void initalizeOutputHandler()
  {
    if (appOutputsHandler == null)
    {
      appOutputsHandler = (IAppOutputsBatteryScreenHandler)this.commsBinding.getAppOutputsSetter();
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
      ITCMSVehicleOutputsRequestHandler<TCMSOutputsBatterySystemScreenImpl<Integer, IAppOutputsBatteryScreenHandler>> handler = requestHandlerMap
          .get(key);
      if (handler != null)
      {
        handler.handleRequest(new TCMSOutputsBatterySystemScreenImpl<>(propertyKey, (Integer)oldValue,
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

/*
 * ==================================================================
 * 
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
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
import com.sydac.mmrbem.tcms.backend.app.io.handlers.IAppOutputsApsScreenHandler;
import com.sydac.mmrbem.tcms.backend.comms.CommsBinding;
import com.sydac.mmrbem.tcms.backend.logic.AbstractFunctionalLogic;
import com.sydac.mmrbem.tcms.backend.logic.SharedDataModel;
import com.sydac.mmrbem.tcms.backend.logic.SharedDataModel.Change;
import com.sydac.mmrbem.tcms.backend.logic.annotation.FunctionalLogicHandler;
import com.sydac.mmrbem.tcms.backend.vehicle.io.properties.ITCMSVehicleOutputsAPSSystemProperties;
import com.sydac.mmrbem.tcms.backend.vehicle.request.handler.AkStatusVehicleOutputsRequestHandler;
import com.sydac.mmrbem.tcms.backend.vehicle.request.handler.ApsControlUnitStatusVehicleOutputsRequestHandler;
import com.sydac.mmrbem.tcms.backend.vehicle.request.handler.ApsOutputVoltageVehicleOutputsRequestHandler;
import com.sydac.mmrbem.tcms.backend.vehicle.request.handler.ITCMSVehicleOutputsRequestHandler;
import com.sydac.mmrbem.tcms.backend.vehicle.request.handler.KStatusVehicleOutputsRequestHandler;
import com.sydac.mmrbem.tcms.backend.vehicle.request.handler.TCMSOutputsApsSystemScreenImpl;
import com.sydac.mmrbem.tcms.common.data.VehicleDetailModel;

/**
 * This handler class is used for handling APS System Status screen data
 * 
 */
@Service
@FunctionalLogicHandler(arguments = { CommsBinding.class, SharedDataModel.class })
public class AuxPowerSupplySystemLogicHandler extends AbstractFunctionalLogic
{
  private static final Tracer LOGGER = Tracer.getInstance();

  private CommsBinding commsBinding;

  private SharedDataModel sharedModel;

  private IAppOutputsApsScreenHandler appOutputsHandler;

  private List<VehicleDetailModel> vehicleDetailModelList;

  private static Map<PropertyKey<Integer>, ITCMSVehicleOutputsRequestHandler<TCMSOutputsApsSystemScreenImpl<Integer, IAppOutputsApsScreenHandler>>> requestHandlerMap = new HashMap<>();

  private final ApsControlUnitStatusVehicleOutputsRequestHandler apsControlUnitStatusVehicleOutputsRequestHandler = new ApsControlUnitStatusVehicleOutputsRequestHandler();

  private final AkStatusVehicleOutputsRequestHandler akStatusVehicleOutputsRequestHandler = new AkStatusVehicleOutputsRequestHandler();

  private final KStatusVehicleOutputsRequestHandler kStatusVehicleOutputsRequestHandler = new KStatusVehicleOutputsRequestHandler();

  private final ApsOutputVoltageVehicleOutputsRequestHandler apsOutputVoltageVehicleOutputsRequestHandler = new ApsOutputVoltageVehicleOutputsRequestHandler();

  protected AuxPowerSupplySystemLogicHandler(CommsBinding commsBinding, SharedDataModel sharedModel)
  {
    super(commsBinding, ITCMSVehicleOutputsAPSSystemProperties.class);
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
    requestHandlerMap.put(ITCMSVehicleOutputsAPSSystemProperties.APS_1_STATUS,
        apsControlUnitStatusVehicleOutputsRequestHandler);
    requestHandlerMap.put(ITCMSVehicleOutputsAPSSystemProperties.APS_2_STATUS,
        apsControlUnitStatusVehicleOutputsRequestHandler);
    requestHandlerMap.put(ITCMSVehicleOutputsAPSSystemProperties.APS_1_FAULT,
        apsControlUnitStatusVehicleOutputsRequestHandler);
    requestHandlerMap.put(ITCMSVehicleOutputsAPSSystemProperties.APS_2_FAULT,
        apsControlUnitStatusVehicleOutputsRequestHandler);
    requestHandlerMap.put(ITCMSVehicleOutputsAPSSystemProperties.APS_1_ISOLATED,
        apsControlUnitStatusVehicleOutputsRequestHandler);
    requestHandlerMap.put(ITCMSVehicleOutputsAPSSystemProperties.APS_2_ISOLATED,
        apsControlUnitStatusVehicleOutputsRequestHandler);
    requestHandlerMap.put(ITCMSVehicleOutputsAPSSystemProperties.AK_1_STATUS,
        akStatusVehicleOutputsRequestHandler);
    requestHandlerMap.put(ITCMSVehicleOutputsAPSSystemProperties.AK_2_STATUS,
        akStatusVehicleOutputsRequestHandler);
    requestHandlerMap.put(ITCMSVehicleOutputsAPSSystemProperties.K_1_STATUS,
        kStatusVehicleOutputsRequestHandler);
    requestHandlerMap.put(ITCMSVehicleOutputsAPSSystemProperties.K_2_STATUS,
        kStatusVehicleOutputsRequestHandler);
    requestHandlerMap.put(ITCMSVehicleOutputsAPSSystemProperties.APS_1_OUTPUT_VOLTAGE,
        apsOutputVoltageVehicleOutputsRequestHandler);
    requestHandlerMap.put(ITCMSVehicleOutputsAPSSystemProperties.APS_2_OUTPUT_VOLTAGE,
        apsOutputVoltageVehicleOutputsRequestHandler);
  }

  private void initalizeOutputHandler()
  {
    if (appOutputsHandler == null)
    {
      appOutputsHandler = (IAppOutputsApsScreenHandler)this.commsBinding.getAppOutputsSetter();
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
      ITCMSVehicleOutputsRequestHandler<TCMSOutputsApsSystemScreenImpl<Integer, IAppOutputsApsScreenHandler>> handler = requestHandlerMap
          .get(key);
      if (handler != null)
      {
        handler.handleRequest(new TCMSOutputsApsSystemScreenImpl<>(propertyKey, (Integer)oldValue,
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

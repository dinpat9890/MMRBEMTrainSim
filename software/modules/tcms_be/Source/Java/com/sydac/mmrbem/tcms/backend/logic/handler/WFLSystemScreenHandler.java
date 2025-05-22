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

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import com.sydac.common.log.Tracer;
import com.sydac.foundation.IModelListener;
import com.sydac.foundation.PropertyKey;
import com.sydac.mmrbem.tcms.backend.app.io.handlers.IAppOutputsWFLSystemScreenHandler;
import com.sydac.mmrbem.tcms.backend.comms.CommsBinding;
import com.sydac.mmrbem.tcms.backend.logic.AbstractFunctionalLogic;
import com.sydac.mmrbem.tcms.backend.logic.SharedDataModel;
import com.sydac.mmrbem.tcms.backend.logic.SharedDataModel.Change;
import com.sydac.mmrbem.tcms.backend.logic.annotation.FunctionalLogicHandler;
import com.sydac.mmrbem.tcms.backend.vehicle.io.handlers.ITCMSVehicleInputsHVACCommandHandler;
import com.sydac.mmrbem.tcms.backend.vehicle.io.properties.ITCMSVehicleOutputsProperties;
import com.sydac.mmrbem.tcms.backend.vehicle.io.properties.ITCMSVehicleOutputsWFLSystemProperties;
import com.sydac.mmrbem.tcms.backend.vehicle.request.handler.ITCMSVehicleOutputsRequestHandler;
import com.sydac.mmrbem.tcms.backend.vehicle.request.handler.TCMSOutputsWFLSystemScreenImpl;
import com.sydac.mmrbem.tcms.backend.vehicle.request.handler.WFLOilLevelStatusVehicleOutputsRequestHandler;
import com.sydac.mmrbem.tcms.backend.vehicle.request.handler.WFLPumpStatus1VehicleOutputsRequestHandler;
import com.sydac.mmrbem.tcms.backend.vehicle.request.handler.WFLPumpStatus2VehicleOutputsRequestHandler;
import com.sydac.mmrbem.tcms.backend.vehicle.request.handler.WFLStatusVehicleOutputsRequestHandler;
import com.sydac.mmrbem.tcms.common.data.VehicleDetailModel;
import com.sydac.mmrbem.tcms.common.io.properties.IAppInputWFLScreenProperties;
import com.sydac.mmrbem.tcms.common.io.properties.IAppInputsProperties;
import com.sydac.mmrbem.tcms.common.io.properties.IAppOutputsWheelFlangeLubricatorScreenProperties;
import com.sydac.mmrbem.tcms.common.state.ApplicationConstants;

/**
 * This handler class is used for handling WFL System Status screen data
 * 
 */
@Service
@FunctionalLogicHandler(arguments = { CommsBinding.class, SharedDataModel.class })
public class WFLSystemScreenHandler extends AbstractFunctionalLogic
{
  private ITCMSVehicleInputsHVACCommandHandler vehicleInputsHandler;

  @Autowired
  private SharedDataModel sharedDataModel;

  private static final Tracer LOGGER = Tracer.getInstance();

  private CommsBinding commsBinding;

  private SharedDataModel sharedModel;

  private IAppOutputsWFLSystemScreenHandler appOutputsHandler;

  private List<VehicleDetailModel> vehicleDetailModelList;

  private static Map<PropertyKey<Integer>, ITCMSVehicleOutputsRequestHandler<TCMSOutputsWFLSystemScreenImpl<Integer, IAppOutputsWFLSystemScreenHandler>>> requestHandlerMap = new HashMap<>();

  private final WFLStatusVehicleOutputsRequestHandler wflStatusVehicleOutputsRequestHandler = new WFLStatusVehicleOutputsRequestHandler();

  private final WFLOilLevelStatusVehicleOutputsRequestHandler wflOilLevelStatusVehicleOutputsRequestHandler = new WFLOilLevelStatusVehicleOutputsRequestHandler();

  private final WFLPumpStatus1VehicleOutputsRequestHandler wflPumpStatus1VehicleOutputsRequestHandler = new WFLPumpStatus1VehicleOutputsRequestHandler();

  private final WFLPumpStatus2VehicleOutputsRequestHandler wflPumpStatus2VehicleOutputsRequestHandler = new WFLPumpStatus2VehicleOutputsRequestHandler();

  protected WFLSystemScreenHandler(CommsBinding commsBinding, SharedDataModel sharedModel)
  {
    super(commsBinding, ITCMSVehicleOutputsWFLSystemProperties.class, IAppInputsProperties.class);
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
    requestHandlerMap.put(ITCMSVehicleOutputsWFLSystemProperties.WFL_STATUS,
        wflStatusVehicleOutputsRequestHandler);
    requestHandlerMap.put(ITCMSVehicleOutputsWFLSystemProperties.WFL_FAULT,
        wflStatusVehicleOutputsRequestHandler);
    requestHandlerMap.put(ITCMSVehicleOutputsWFLSystemProperties.WFL_OIL_LEVEL_STATUS,
        wflOilLevelStatusVehicleOutputsRequestHandler);
    requestHandlerMap.put(ITCMSVehicleOutputsWFLSystemProperties.WFL_PUMP_1,
        wflPumpStatus1VehicleOutputsRequestHandler);
    requestHandlerMap.put(ITCMSVehicleOutputsWFLSystemProperties.WFL_PUMP_2,
        wflPumpStatus2VehicleOutputsRequestHandler);
  }

  private void initalizeOutputHandler()
  {
    if (appOutputsHandler == null)
    {
      appOutputsHandler = (IAppOutputsWFLSystemScreenHandler)this.commsBinding.getAppOutputsSetter();
    }
  }

  @Override
  public <T> void appInputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue, int vehicleIndex)
  {
    if ((Integer)newValue > -1 && getActiveVehicleIndex() == vehicleIndex)
    {
      if (key.equals(IAppInputWFLScreenProperties.WFL_ISOLATED_REQ_FRONT_CAR))
      {
        vehicleInputsHandler = (ITCMSVehicleInputsHVACCommandHandler)getTCMSVehicleInputsSetter(vehicleIndex);
        vehicleInputsHandler.setTcmsWflIsolationReq((Integer)newValue);
      }
      if (key.equals(IAppInputWFLScreenProperties.WFL_ISOLATED_REQ_REAR_CAR))
      {
        vehicleInputsHandler = (ITCMSVehicleInputsHVACCommandHandler)getTCMSVehicleInputsSetter(
            sharedDataModel.getTotalCar() - 1);
        vehicleInputsHandler.setTcmsWflIsolationReq((Integer)newValue);
      }
    }
  }

  @Override
  public <T> void tcmsVehicleOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue,
      int vehicleIndex)
  {
    initalizeOutputHandler();

    if (ITCMSVehicleOutputsProperties.WFL_ISOLATED.equals(key))
    {
      if (vehicleIndex == 0)
      {
        setApplicationOutputsProperty(
            IAppOutputsWheelFlangeLubricatorScreenProperties.WFL_ISOLATED_STATUS_FRONT_CAR,
            (Integer)newValue);
      }
      else if (vehicleIndex == (sharedDataModel.getTotalCar() - 1))
      {
        setApplicationOutputsProperty(
            IAppOutputsWheelFlangeLubricatorScreenProperties.WFL_ISOLATED_STATUS_REAR_CAR, (Integer)newValue);
      }
    }

    if (ITCMSVehicleOutputsProperties.POWER_OFF_PRESSED.equals(key) && Boolean.TRUE.equals(newValue))
    {
      resetInputCommands();
    }

    @SuppressWarnings("unchecked")
    PropertyKey<Integer> propertyKey = (PropertyKey<Integer>)key;
    try
    {
      ITCMSVehicleOutputsRequestHandler<TCMSOutputsWFLSystemScreenImpl<Integer, IAppOutputsWFLSystemScreenHandler>> handler = requestHandlerMap
          .get(key);
      if (handler != null)
      {
        handler.handleRequest(new TCMSOutputsWFLSystemScreenImpl<>(propertyKey, (Integer)oldValue,
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

  private void resetInputCommands()
  {
    for (int carIndex = 0; carIndex < sharedDataModel.getTotalCar(); carIndex++)
    {
      vehicleInputsHandler = (ITCMSVehicleInputsHVACCommandHandler)getTCMSVehicleInputsSetter(carIndex);
      vehicleInputsHandler.setTcmsWflIsolationReq(ApplicationConstants.RESET_VALUE);
    }
  }

  private void initalizeVehicleInputHandler()
  {
    if (vehicleInputsHandler == null)
    {
      vehicleInputsHandler = (ITCMSVehicleInputsHVACCommandHandler)getTCMSVehicleInputsSetter(
          getActiveVehicleIndex());
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

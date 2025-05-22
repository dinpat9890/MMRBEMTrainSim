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
import com.sydac.mmrbem.tcms.backend.app.io.handlers.IAppOutputsMediumVoltageSystemScreenHandler;
import com.sydac.mmrbem.tcms.backend.comms.CommsBinding;
import com.sydac.mmrbem.tcms.backend.logic.AbstractFunctionalLogic;
import com.sydac.mmrbem.tcms.backend.logic.SharedDataModel;
import com.sydac.mmrbem.tcms.backend.logic.SharedDataModel.Change;
import com.sydac.mmrbem.tcms.backend.logic.annotation.FunctionalLogicHandler;
import com.sydac.mmrbem.tcms.backend.vehicle.io.properties.ITCMSVehicleOutputsMediumVoltageSystemProperties;
import com.sydac.mmrbem.tcms.backend.vehicle.request.handler.AuxCompStatusVehicleOutputsRequestHandler;
import com.sydac.mmrbem.tcms.backend.vehicle.request.handler.ITCMSVehicleOutputsRequestHandler;
import com.sydac.mmrbem.tcms.backend.vehicle.request.handler.MainCompStatusVehicleOutputsRequestHandler;
import com.sydac.mmrbem.tcms.backend.vehicle.request.handler.PECStatusVehicleOutputsRequestHandler;
import com.sydac.mmrbem.tcms.backend.vehicle.request.handler.TCMSOutputsMediumVoltageSystemScreenImpl;
import com.sydac.mmrbem.tcms.common.data.VehicleDetailModel;

/**
 * This handler class is used for handling Medium Voltage System Screen data
 * 
 */
@Service
@FunctionalLogicHandler(arguments = { CommsBinding.class, SharedDataModel.class })
public class MediumVoltageSystemScreenHandler extends AbstractFunctionalLogic
{
  private static final Tracer LOGGER = Tracer.getInstance();

  private CommsBinding commsBinding;

  private SharedDataModel sharedModel;

  private IAppOutputsMediumVoltageSystemScreenHandler appOutputsHandler;

  private List<VehicleDetailModel> vehicleDetailModelList;

  private static Map<PropertyKey<Integer>, ITCMSVehicleOutputsRequestHandler<TCMSOutputsMediumVoltageSystemScreenImpl<Integer, IAppOutputsMediumVoltageSystemScreenHandler>>> requestHandlerMap = new HashMap<>();

  private final PECStatusVehicleOutputsRequestHandler pecStatusVehicleOutputsRequestHandler = new PECStatusVehicleOutputsRequestHandler();

  private final AuxCompStatusVehicleOutputsRequestHandler auxCompStatusVehicleOutputsRequestHandler = new AuxCompStatusVehicleOutputsRequestHandler();

  private final MainCompStatusVehicleOutputsRequestHandler mainCompStatusVehicleOutputsRequestHandler = new MainCompStatusVehicleOutputsRequestHandler();

  protected MediumVoltageSystemScreenHandler(CommsBinding commsBinding, SharedDataModel sharedModel)
  {
    super(commsBinding, ITCMSVehicleOutputsMediumVoltageSystemProperties.class);
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
    requestHandlerMap.put(ITCMSVehicleOutputsMediumVoltageSystemProperties.POWER_EXTENSION_CONTACTOR,
        pecStatusVehicleOutputsRequestHandler);
    requestHandlerMap.put(ITCMSVehicleOutputsMediumVoltageSystemProperties.AUX_COMPRESSOR,
        auxCompStatusVehicleOutputsRequestHandler);
    requestHandlerMap.put(ITCMSVehicleOutputsMediumVoltageSystemProperties.MAIN_COMPRESSOR,
        mainCompStatusVehicleOutputsRequestHandler);
  }

  private void initalizeOutputHandler()
  {
    if (appOutputsHandler == null)
    {
      appOutputsHandler = (IAppOutputsMediumVoltageSystemScreenHandler)this.commsBinding
          .getAppOutputsSetter();
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
      ITCMSVehicleOutputsRequestHandler<TCMSOutputsMediumVoltageSystemScreenImpl<Integer, IAppOutputsMediumVoltageSystemScreenHandler>> handler = requestHandlerMap
          .get(key);
      if (handler != null)
      {
        handler.handleRequest(new TCMSOutputsMediumVoltageSystemScreenImpl<>(propertyKey, (Integer)oldValue,
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

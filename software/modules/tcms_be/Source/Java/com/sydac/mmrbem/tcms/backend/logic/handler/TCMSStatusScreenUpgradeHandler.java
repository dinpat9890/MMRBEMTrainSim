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
import com.sydac.mmrbem.tcms.backend.app.io.handlers.IAppOutputsTcmsStatusScreenHandler;
import com.sydac.mmrbem.tcms.backend.comms.CommsBinding;
import com.sydac.mmrbem.tcms.backend.logic.AbstractFunctionalLogic;
import com.sydac.mmrbem.tcms.backend.logic.SharedDataModel;
import com.sydac.mmrbem.tcms.backend.logic.SharedDataModel.Change;
import com.sydac.mmrbem.tcms.backend.logic.annotation.FunctionalLogicHandler;
import com.sydac.mmrbem.tcms.backend.vehicle.io.properties.ITCMSVehicleOutputsStatusScreenProperties;
import com.sydac.mmrbem.tcms.backend.vehicle.request.handler.ITCMSVehicleOutputsRequestHandler;
import com.sydac.mmrbem.tcms.backend.vehicle.request.handler.TCMSOutputsTcmsSystemScreenImpl;
import com.sydac.mmrbem.tcms.backend.vehicle.request.handler.TcmsStatusRI01VehicleOutputsRequestHandler;
import com.sydac.mmrbem.tcms.backend.vehicle.request.handler.TcmsStatusRI02VehicleOutputsRequestHandler;
import com.sydac.mmrbem.tcms.backend.vehicle.request.handler.VehicleStatusIntegerOutPutsRequestHandler;
import com.sydac.mmrbem.tcms.common.data.Entry;
import com.sydac.mmrbem.tcms.common.data.VehicleDetailModel;
import com.sydac.mmrbem.tcms.common.data.VehicleIntegerDataDO;

/**
 * This handler class is used for handling TCMS Status screen after upgrade data
 * 
 */
@Service
@FunctionalLogicHandler(arguments = { CommsBinding.class, SharedDataModel.class })
public class TCMSStatusScreenUpgradeHandler extends AbstractFunctionalLogic
{
  private SharedDataModel sharedModel;

  private static final Tracer LOGGER = Tracer.getInstance();

  private CommsBinding commsBinding;

  private List<VehicleDetailModel> vehicleDetailModelList;

  private IAppOutputsTcmsStatusScreenHandler appOutputsHandler;

  private static Map<PropertyKey<Integer>, ITCMSVehicleOutputsRequestHandler<TCMSOutputsTcmsSystemScreenImpl<Integer, IAppOutputsTcmsStatusScreenHandler>>> requestHandlerMap = new HashMap<>();

 
  /**
   * This map holds request handles for TCMS Status related parameters.
   */

  private final TcmsStatusRI01VehicleOutputsRequestHandler ri01StatusVehicleOutputsRequestHandler = new TcmsStatusRI01VehicleOutputsRequestHandler();
  private final TcmsStatusRI02VehicleOutputsRequestHandler ri02StatusVehicleOutputsRequestHandler = new TcmsStatusRI02VehicleOutputsRequestHandler();

  public TCMSStatusScreenUpgradeHandler(CommsBinding commsBinding, SharedDataModel aSharedModel)
  {
    super(commsBinding, ITCMSVehicleOutputsStatusScreenProperties.class);
    sharedModel = aSharedModel;
    this.commsBinding = commsBinding;
    initalizeOutputHandler();
    initHandlerMap();
  }

  /**
   * Listener to update vehicleDetailModelList
   */
  IModelListener trainConfigListener = (arg0, arg1) -> {
    vehicleDetailModelList = sharedModel.getVehicleDetailModelList();
  };

  private void initHandlerMap()
  {
    requestHandlerMap.put(ITCMSVehicleOutputsStatusScreenProperties.RIO1_FAULT,
        ri01StatusVehicleOutputsRequestHandler);

    requestHandlerMap.put(ITCMSVehicleOutputsStatusScreenProperties.RIO1_STATUS,
        ri01StatusVehicleOutputsRequestHandler);
    
    requestHandlerMap.put(ITCMSVehicleOutputsStatusScreenProperties.RIO2_FAULT,
        ri02StatusVehicleOutputsRequestHandler);

    requestHandlerMap.put(ITCMSVehicleOutputsStatusScreenProperties.RIO2_STATUS,
        ri02StatusVehicleOutputsRequestHandler);

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

  /**
   * use this class to instantiate TCMS Status parameter request handler.
   * 
   */
  class VehicleTCMSStatusIntegerOutPutsRequestHandler extends VehicleStatusIntegerOutPutsRequestHandler
  {

    private VehicleTCMSStatusIntegerOutPutsRequestHandler(Runnable aRunnable,
        List<Entry<VehicleIntegerDataDO>> aList)
    {
      super(aRunnable, aList);
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
      ITCMSVehicleOutputsRequestHandler<TCMSOutputsTcmsSystemScreenImpl<Integer, IAppOutputsTcmsStatusScreenHandler>> handler = requestHandlerMap
          .get(key);
      if (handler != null)
      {
        handler.handleRequest(new TCMSOutputsTcmsSystemScreenImpl<>(propertyKey, (Integer)oldValue,
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

  private void initalizeOutputHandler()
  {
    if (appOutputsHandler == null)
    {
      appOutputsHandler = (IAppOutputsTcmsStatusScreenHandler)this.commsBinding.getAppOutputsSetter();
    }
  }

}

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
import com.sydac.mmrbem.tcms.backend.app.io.handlers.IAppOutputsECNScreenHandler;
import com.sydac.mmrbem.tcms.backend.comms.CommsBinding;
import com.sydac.mmrbem.tcms.backend.logic.AbstractFunctionalLogic;
import com.sydac.mmrbem.tcms.backend.logic.SharedDataModel;
import com.sydac.mmrbem.tcms.backend.logic.SharedDataModel.Change;
import com.sydac.mmrbem.tcms.backend.logic.annotation.FunctionalLogicHandler;
import com.sydac.mmrbem.tcms.backend.vehicle.io.properties.ITCMSVehicleOutputsECNScreenProperties;
import com.sydac.mmrbem.tcms.backend.vehicle.io.properties.ITCMSVehicleOutputsProperties;
import com.sydac.mmrbem.tcms.backend.vehicle.request.handler.ECNAlgStatusVehicleOutputsRequestHandler;
import com.sydac.mmrbem.tcms.backend.vehicle.request.handler.ECNComponentSwitchAStatusVehicleOutputsRequestHandler;
import com.sydac.mmrbem.tcms.backend.vehicle.request.handler.ECNComponentSwitchBStatusVehicleOutputsRequestHandler;
import com.sydac.mmrbem.tcms.backend.vehicle.request.handler.ECNComponentSwitchCStatusVehicleOutputsRequestHandler;
import com.sydac.mmrbem.tcms.backend.vehicle.request.handler.ECNTrainBackboneNodeStatusVehicleOutputsRequestHandler;
import com.sydac.mmrbem.tcms.backend.vehicle.request.handler.ECNTrainEthernetResistStatusVehicleOutputsRequestHandler;
import com.sydac.mmrbem.tcms.backend.vehicle.request.handler.ITCMSVehicleOutputsRequestHandler;
import com.sydac.mmrbem.tcms.backend.vehicle.request.handler.TCMSOutputsECNScreenImpl;
import com.sydac.mmrbem.tcms.common.data.VehicleDetailModel;

/**
 * This handler class is used for handling TCMS ECN screen data
 * 
 */
@Service
@FunctionalLogicHandler(arguments = { CommsBinding.class, SharedDataModel.class })
public class TCMSEthernetConsistNetworkScreenHandler extends AbstractFunctionalLogic
{
  private static final Tracer LOGGER = Tracer.getInstance();

  private CommsBinding commsBinding;

  private SharedDataModel sharedModel;

  private IAppOutputsECNScreenHandler appOutputsHandler;

  private List<VehicleDetailModel> vehicleDetailModelList;

  private static Map<PropertyKey<Integer>, ITCMSVehicleOutputsRequestHandler<TCMSOutputsECNScreenImpl<Integer, IAppOutputsECNScreenHandler>>> requestHandlerMap = new HashMap<>();

  private final ECNComponentSwitchAStatusVehicleOutputsRequestHandler ecnCsAStatusVehicleOutputsRequestHandler = new ECNComponentSwitchAStatusVehicleOutputsRequestHandler();

  private final ECNComponentSwitchBStatusVehicleOutputsRequestHandler ecnCsBStatusVehicleOutputsRequestHandler = new ECNComponentSwitchBStatusVehicleOutputsRequestHandler();

  private final ECNComponentSwitchCStatusVehicleOutputsRequestHandler ecnCsCStatusVehicleOutputsRequestHandler = new ECNComponentSwitchCStatusVehicleOutputsRequestHandler();

  private final ECNTrainBackboneNodeStatusVehicleOutputsRequestHandler ecnTBNStatusVehicleOutputsRequestHandler = new ECNTrainBackboneNodeStatusVehicleOutputsRequestHandler();

  private final ECNTrainEthernetResistStatusVehicleOutputsRequestHandler ecnTERStatusVehicleOutputsRequestHandler = new ECNTrainEthernetResistStatusVehicleOutputsRequestHandler();

  private final ECNAlgStatusVehicleOutputsRequestHandler ecnAlgStatusVehicleOutputsRequestHandler = new ECNAlgStatusVehicleOutputsRequestHandler();

  protected TCMSEthernetConsistNetworkScreenHandler(CommsBinding commsBinding, SharedDataModel sharedModel)
  {
    super(commsBinding, ITCMSVehicleOutputsProperties.class);
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
    requestHandlerMap.put(ITCMSVehicleOutputsECNScreenProperties.CONSIST_SWITCH_STATUS_A,
        ecnCsAStatusVehicleOutputsRequestHandler);
    requestHandlerMap.put(ITCMSVehicleOutputsProperties.DUMMY_FAULT_SIGNAL,
        ecnCsAStatusVehicleOutputsRequestHandler);
    requestHandlerMap.put(ITCMSVehicleOutputsECNScreenProperties.CONSIST_SWITCH_STATUS_B,
        ecnCsBStatusVehicleOutputsRequestHandler);
    requestHandlerMap.put(ITCMSVehicleOutputsProperties.DUMMY_FAULT_SIGNAL,
        ecnCsBStatusVehicleOutputsRequestHandler);
    requestHandlerMap.put(ITCMSVehicleOutputsECNScreenProperties.CONSIST_SWITCH_STATUS_C,
        ecnCsCStatusVehicleOutputsRequestHandler);
    requestHandlerMap.put(ITCMSVehicleOutputsProperties.DUMMY_FAULT_SIGNAL,
        ecnCsCStatusVehicleOutputsRequestHandler);
    requestHandlerMap.put(ITCMSVehicleOutputsECNScreenProperties.TRAIN_BACKBONE_NODE_STATUS,
        ecnTBNStatusVehicleOutputsRequestHandler);
    requestHandlerMap.put(ITCMSVehicleOutputsProperties.DUMMY_FAULT_SIGNAL,
        ecnTBNStatusVehicleOutputsRequestHandler);
    requestHandlerMap.put(ITCMSVehicleOutputsECNScreenProperties.TRAIN_ETHERNET_REPEATER_STATUS,
        ecnTERStatusVehicleOutputsRequestHandler);
    requestHandlerMap.put(ITCMSVehicleOutputsProperties.DUMMY_FAULT_SIGNAL,
        ecnTERStatusVehicleOutputsRequestHandler);
    requestHandlerMap.put(ITCMSVehicleOutputsECNScreenProperties.ECN_ALG_STATUS,
        ecnAlgStatusVehicleOutputsRequestHandler);
    requestHandlerMap.put(ITCMSVehicleOutputsProperties.DUMMY_FAULT_SIGNAL,
        ecnAlgStatusVehicleOutputsRequestHandler);
  }

  private void initalizeOutputHandler()
  {
    if (appOutputsHandler == null)
    {
      appOutputsHandler = (IAppOutputsECNScreenHandler)this.commsBinding.getAppOutputsSetter();
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
      ITCMSVehicleOutputsRequestHandler<TCMSOutputsECNScreenImpl<Integer, IAppOutputsECNScreenHandler>> handler = requestHandlerMap
          .get(key);
      if (handler != null)
      {
        handler.handleRequest(new TCMSOutputsECNScreenImpl<>(propertyKey, (Integer)oldValue,
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

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
import java.util.concurrent.CopyOnWriteArrayList;
import java.util.function.Consumer;

import org.springframework.stereotype.Service;

import com.sydac.common.log.Tracer;
import com.sydac.foundation.IModelListener;
import com.sydac.foundation.PropertyKey;
import com.sydac.mmrbem.tcms.backend.comms.CommsBinding;
import com.sydac.mmrbem.tcms.backend.logic.AbstractFunctionalLogic;
import com.sydac.mmrbem.tcms.backend.logic.SharedDataModel;
import com.sydac.mmrbem.tcms.backend.logic.SharedDataModel.Change;
import com.sydac.mmrbem.tcms.backend.logic.annotation.FunctionalLogicHandler;
import com.sydac.mmrbem.tcms.backend.vehicle.io.properties.ITCMSVehicleOutputsStatusScreenProperties;
import com.sydac.mmrbem.tcms.backend.vehicle.request.handler.CommonVehicleOutputsRequest;
import com.sydac.mmrbem.tcms.backend.vehicle.request.handler.VehicleStatusIntegerOutPutsRequestHandler;
import com.sydac.mmrbem.tcms.common.data.Entry;
import com.sydac.mmrbem.tcms.common.data.VehicleDetailModel;
import com.sydac.mmrbem.tcms.common.data.VehicleIntegerDataDO;
import com.sydac.mmrbem.tcms.common.io.properties.IAppOutputsTCMSStatusScreenProperties;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.CCUStatusList.CCUState;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.ERStatusList.ERState;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.RIO12LineStatusList.RIO12LineState;

/**
 * This handler class is used for handling TCMS Status screen data
 * 
 */
@Service
@FunctionalLogicHandler(arguments = { CommsBinding.class, SharedDataModel.class })
public class TCMSStatusScreenHandler extends AbstractFunctionalLogic
{
  private SharedDataModel sharedModel;

  private List<VehicleDetailModel> vehicleDetailModelList;

  private List<Entry<VehicleIntegerDataDO>> ccuFaultStatusList = new CopyOnWriteArrayList<>();

  private List<Entry<VehicleIntegerDataDO>> rio12LineFaultStatusList = new CopyOnWriteArrayList<>();

  private List<Entry<VehicleIntegerDataDO>> erFaultStatusList = new CopyOnWriteArrayList<>();

  /**
   * Listener to update vehicleDetailModelList
   */
  IModelListener trainConfigListener = (arg0, arg1) -> {
    vehicleDetailModelList = sharedModel.getVehicleDetailModelList();
    // Write the initial state of propulsion status
    if (!vehicleDetailModelList.isEmpty())
    {
      updateCCUFaultStatusList();

      updateRio12LineFaultStatusList();
      updateERFaultStatusList();

    }
  };

  /**
   * This map holds request handles for TCMS Status related parameters.
   */
  private final Map<PropertyKey<Integer>, VehicleTCMSStatusIntegerOutPutsRequestHandler> requestHandlerMap = new HashMap<>();

  public TCMSStatusScreenHandler(CommsBinding commsBinding, SharedDataModel aSharedModel)
  {
    super(commsBinding, ITCMSVehicleOutputsStatusScreenProperties.class);
    sharedModel = aSharedModel;

    initHandlerMap();
  }

  private void initHandlerMap()
  {
    requestHandlerMap.put(ITCMSVehicleOutputsStatusScreenProperties.CCU_FAULT,
        new VehicleTCMSStatusIntegerOutPutsRequestHandler(this::updateCCUFaultStatusList,
            ccuFaultStatusList));
   
    requestHandlerMap.put(ITCMSVehicleOutputsStatusScreenProperties.RIO1_RIO2_FAULT,
        new VehicleTCMSStatusIntegerOutPutsRequestHandler(this::updateRio12LineFaultStatusList,
            rio12LineFaultStatusList));
    requestHandlerMap.put(ITCMSVehicleOutputsStatusScreenProperties.ER_FAULT,
        new VehicleTCMSStatusIntegerOutPutsRequestHandler(this::updateERFaultStatusList, erFaultStatusList));

   
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

  private void updateCCUFaultStatusList()
  {
    updateAppCCUFaultIntegerValueList(ccuFaultStatusList,
        builder -> setApplicationOutputsProperty(IAppOutputsTCMSStatusScreenProperties.CCU_STATUS,
            builder.build().toByteArray()));
  }

 
  private void updateRio12LineFaultStatusList()
  {
    updateAppRio12LineFaultIntegerValueList(rio12LineFaultStatusList,
        builder -> setApplicationOutputsProperty(IAppOutputsTCMSStatusScreenProperties.RIO_1_2_LINE_STATUS,
            builder.build().toByteArray()));
  }

  private void updateERFaultStatusList()
  {
    updateAppERFaultIntegerValueList(erFaultStatusList,
        builder -> setApplicationOutputsProperty(IAppOutputsTCMSStatusScreenProperties.ER_STATUS,
            builder.build().toByteArray()));
  }

  private void updateAppCCUFaultIntegerValueList(List<Entry<VehicleIntegerDataDO>> parameterEntryList,
      Consumer<TCMSProto.CCUStatusList.Builder> consumer)
  {
    TCMSProto.CCUStatusList.Builder builder = TCMSProto.CCUStatusList.newBuilder();
    TCMSProto.CCUStatusList.CCUStatus.Builder vehicleBuilder = TCMSProto.CCUStatusList.CCUStatus.newBuilder();
    parameterEntryList.forEach(entry -> {
      int carIndex = entry.getIndex();
      vehicleBuilder.setCarIndex(carIndex);
      vehicleBuilder.setCcuState(entry.getData().getValue() == 0 ? CCUState.CCU_OK : CCUState.CCU_FAULTY);
      builder.addCcuStatus(vehicleBuilder.build());
    });
    consumer.accept(builder);
  }

 

  private void updateAppRio12LineFaultIntegerValueList(List<Entry<VehicleIntegerDataDO>> parameterEntryList,
      Consumer<TCMSProto.RIO12LineStatusList.Builder> consumer)
  {
    TCMSProto.RIO12LineStatusList.Builder builder = TCMSProto.RIO12LineStatusList.newBuilder();
    TCMSProto.RIO12LineStatusList.RIO12LineStatus.Builder vehicleBuilder = TCMSProto.RIO12LineStatusList.RIO12LineStatus
        .newBuilder();
    parameterEntryList.forEach(entry -> {
      int carIndex = entry.getIndex();
      vehicleBuilder.setCarIndex(carIndex);
      vehicleBuilder.setRio12LineState(
          entry.getData().getValue() == 1 ? RIO12LineState.RIO12LINE_FAULTY : RIO12LineState.RIO12LINE_OK);
      builder.addRio12LineStatus(vehicleBuilder.build());
    });
    consumer.accept(builder);
  }

  private void updateAppERFaultIntegerValueList(List<Entry<VehicleIntegerDataDO>> parameterEntryList,
      Consumer<TCMSProto.ERStatusList.Builder> consumer)
  {
    TCMSProto.ERStatusList.Builder builder = TCMSProto.ERStatusList.newBuilder();
    TCMSProto.ERStatusList.ERStatus.Builder vehicleBuilder = TCMSProto.ERStatusList.ERStatus.newBuilder();
    parameterEntryList.forEach(entry -> {
      int carIndex = entry.getIndex();
      vehicleBuilder.setCarIndex(carIndex);
      vehicleBuilder.setErState(entry.getData().getValue() == 1 ? ERState.ER_FAULTY : ERState.ER_OK);
      builder.addErStatus(vehicleBuilder.build());
    });
    consumer.accept(builder);
  }

  @Override
  public <T> void tcmsVehicleOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue,
      int vehicleIndex)
  {
    @SuppressWarnings("unchecked")
    PropertyKey<Integer> propertyKey = (PropertyKey<Integer>)key;

    VehicleTCMSStatusIntegerOutPutsRequestHandler handler = requestHandlerMap.get(key);
    if (handler != null)
    {
      handler.handleRequest(
          new CommonVehicleOutputsRequest<>(propertyKey, (Integer)oldValue, (Integer)newValue, vehicleIndex));
    }
    else
    {
      Tracer.getInstance().debug(
          String.format("Cannot update, request Handler for key %S is not found", propertyKey.toString())); //$NON-NLS-1$
    }
  }

  
 



}

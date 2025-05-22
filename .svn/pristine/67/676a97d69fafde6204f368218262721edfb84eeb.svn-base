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
import com.sydac.mmrbem.tcms.backend.vehicle.io.properties.ITCMSVehicleOutputsLowVoltageSystemProperties;
import com.sydac.mmrbem.tcms.backend.vehicle.request.handler.CommonVehicleOutputsRequest;
import com.sydac.mmrbem.tcms.backend.vehicle.request.handler.VehicleStatusIntegerOutPutsRequestHandler;
import com.sydac.mmrbem.tcms.common.data.Entry;
import com.sydac.mmrbem.tcms.common.data.VehicleDetailModel;
import com.sydac.mmrbem.tcms.common.data.VehicleIntegerDataDO;
import com.sydac.mmrbem.tcms.common.io.properties.IAppOutputsLowVoltageSystemScreenProperties;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.LVBatteryIsolationContactorStatusList.LVBatteryIsolationContactorState;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.LVTrainControlContactorStatusList.LVTrainControlContactorState;
import com.sydac.mmrbem.tcms.common.state.ApplicationConstants;
import com.sydac.mmrbem.tcms.common.state.TCMSConstants;

/**
 * This handler class is used for handling Low Voltage System Status screen data
 * 
 */
@Service
@FunctionalLogicHandler(arguments = { CommsBinding.class, SharedDataModel.class })
public class LowVoltageSystemScreenHandler extends AbstractFunctionalLogic
{
  private SharedDataModel sharedModel;

  private List<VehicleDetailModel> vehicleDetailModelList;

  // BIC - Battery Isolation Contactor
  private List<Entry<VehicleIntegerDataDO>> bicStatusList = new CopyOnWriteArrayList<>();

  // TCC - Train Control Contactor
  private List<Entry<VehicleIntegerDataDO>> tccStatusList = new CopyOnWriteArrayList<>();

  /**
   * Listener to update vehicleDetailModelList
   */
  IModelListener trainConfigListener = (arg0, arg1) -> {
    vehicleDetailModelList = sharedModel.getVehicleDetailModelList();
    // Write the initial state of propulsion status
    if (!vehicleDetailModelList.isEmpty())
    {
      updateBICStatusList();
      updateTCCStatusList();

    }
  };

  /**
   * This map holds request handles for Low Voltage System Status related
   * parameters.
   */
  private final Map<PropertyKey<Integer>, VehicleLowVoltageSystemStatusIntegerOutPutsRequestHandler> requestHandlerMap = new HashMap<>();

  public LowVoltageSystemScreenHandler(CommsBinding commsBinding, SharedDataModel aSharedModel)
  {
    super(commsBinding, ITCMSVehicleOutputsLowVoltageSystemProperties.class);
    sharedModel = aSharedModel;

    initHandlerMap();
  }

  private void initHandlerMap()
  {
    requestHandlerMap.put(ITCMSVehicleOutputsLowVoltageSystemProperties.BATTERY_ISOLATION_CONTACTOR,
        new VehicleLowVoltageSystemStatusIntegerOutPutsRequestHandler(this::updateBICStatusList,
            bicStatusList));
    requestHandlerMap.put(ITCMSVehicleOutputsLowVoltageSystemProperties.TRAIN_CONTROL_CONTACTOR,
        new VehicleLowVoltageSystemStatusIntegerOutPutsRequestHandler(this::updateTCCStatusList,
            tccStatusList));
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
   * use this class to instantiate Propulsion Status parameter request handler.
   *
   */
  class VehicleLowVoltageSystemStatusIntegerOutPutsRequestHandler
      extends VehicleStatusIntegerOutPutsRequestHandler
  {

    private VehicleLowVoltageSystemStatusIntegerOutPutsRequestHandler(Runnable aRunnable,
        List<Entry<VehicleIntegerDataDO>> aList)
    {
      super(aRunnable, aList);
    }

  }

  private void updateBICStatusList()
  {
    updateAppBICIntegerValueList(bicStatusList,
        builder -> setApplicationOutputsProperty(
            IAppOutputsLowVoltageSystemScreenProperties.LV_BIC_SWITCH_STATUS_LIST,
            builder.build().toByteArray()));
  }

  private void updateTCCStatusList()
  {
    updateAppTCCIntegerValueList(tccStatusList,
        builder -> setApplicationOutputsProperty(
            IAppOutputsLowVoltageSystemScreenProperties.LV_TCC_SWITCH_STATUS_LIST,
            builder.build().toByteArray()));
  }

  private void updateAppBICIntegerValueList(List<Entry<VehicleIntegerDataDO>> parameterEntryList,
      Consumer<TCMSProto.LVBatteryIsolationContactorStatusList.Builder> consumer)
  {
    TCMSProto.LVBatteryIsolationContactorStatusList.Builder builder = TCMSProto.LVBatteryIsolationContactorStatusList
        .newBuilder();
    TCMSProto.LVBatteryIsolationContactorStatusList.LVBatteryIsolationContactorStatus.Builder vehicleBuilder = TCMSProto.LVBatteryIsolationContactorStatusList.LVBatteryIsolationContactorStatus
        .newBuilder();
    parameterEntryList.forEach(entry -> {
      int carIndex = entry.getIndex();
      vehicleBuilder.setCarIndex(carIndex);
      String carClassCode = vehicleDetailModelList != null
          ? vehicleDetailModelList.get(carIndex).getCarClassCode()
          : ApplicationConstants.BLANK;
      if (TCMSConstants.M_CAR.equals(carClassCode))
      {
        vehicleBuilder.setLvBatteryIsolationContactorState(
            entry.getData().getValue() == LVBatteryIsolationContactorState.BIC_OPEN_VALUE
                ? LVBatteryIsolationContactorState.BIC_OPEN
                : LVBatteryIsolationContactorState.BIC_CLOSED);
      }
      else
      {
        vehicleBuilder.setLvBatteryIsolationContactorState(LVBatteryIsolationContactorState.BIC_OPEN);
      }
      builder.addLvBatteryIsolationContactorStatus(vehicleBuilder.build());
    });
    consumer.accept(builder);
  }

  private void updateAppTCCIntegerValueList(List<Entry<VehicleIntegerDataDO>> parameterEntryList,
      Consumer<TCMSProto.LVTrainControlContactorStatusList.Builder> consumer)
  {
    TCMSProto.LVTrainControlContactorStatusList.Builder builder = TCMSProto.LVTrainControlContactorStatusList
        .newBuilder();
    TCMSProto.LVTrainControlContactorStatusList.LVTrainControlContactorStatus.Builder vehicleBuilder = TCMSProto.LVTrainControlContactorStatusList.LVTrainControlContactorStatus
        .newBuilder();
    parameterEntryList.forEach(entry -> {
      int carIndex = entry.getIndex();
      vehicleBuilder.setCarIndex(carIndex);
      String carClassCode = vehicleDetailModelList != null
          ? vehicleDetailModelList.get(carIndex).getCarClassCode()
          : ApplicationConstants.BLANK;
      if (TCMSConstants.M_CAR.equals(carClassCode))
      {
        vehicleBuilder.setLvTrainControlContactorState(
            entry.getData().getValue() == LVTrainControlContactorState.TCC_CLOSED_VALUE
                ? LVTrainControlContactorState.TCC_CLOSED
                : LVTrainControlContactorState.TCC_OPEN);
      }
      else
      {
        vehicleBuilder.setLvTrainControlContactorState(LVTrainControlContactorState.TCC_OPEN);
      }
      builder.addLvTrainControlContactorStatus(vehicleBuilder.build());
    });
    consumer.accept(builder);
  }

  @Override
  public <T> void tcmsVehicleOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue,
      int vehicleIndex)
  {
    @SuppressWarnings("unchecked")
    PropertyKey<Integer> propertyKey = (PropertyKey<Integer>)key;

    VehicleLowVoltageSystemStatusIntegerOutPutsRequestHandler handler = requestHandlerMap.get(key);
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

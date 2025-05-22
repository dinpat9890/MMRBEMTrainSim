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
import com.sydac.mmrbem.tcms.backend.vehicle.io.properties.ITCMSVehicleOutputsBrakeLoopInterlockScreenProperties;
import com.sydac.mmrbem.tcms.backend.vehicle.io.properties.ITCMSVehicleOutputsMisceProperties;
import com.sydac.mmrbem.tcms.backend.vehicle.request.handler.CommonVehicleOutputsRequest;
import com.sydac.mmrbem.tcms.backend.vehicle.request.handler.VehicleStatusIntegerOutPutsRequestHandler;
import com.sydac.mmrbem.tcms.common.data.Entry;
import com.sydac.mmrbem.tcms.common.data.VehicleDetailModel;
import com.sydac.mmrbem.tcms.common.data.VehicleIntegerDataDO;
import com.sydac.mmrbem.tcms.common.io.properties.IAppOutputsEnableToRunScreenProperties;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.BrakeLoopState;
import com.sydac.mmrbem.tcms.common.state.ApplicationConstants;
import com.sydac.mmrbem.tcms.common.state.TCMSConstants;

/**
 * This handler class is used for handling Brake Loop Interlock Screen data
 * 
 */
@Service
@FunctionalLogicHandler(arguments = { CommsBinding.class, SharedDataModel.class })
public class BrakeLoopInterlockScreenHandler extends AbstractFunctionalLogic
{
  private SharedDataModel sharedModel;

  private List<VehicleDetailModel> vehicleDetailModelList;

  private List<Entry<VehicleIntegerDataDO>> mainReserviorList = new CopyOnWriteArrayList<>();

  private List<Entry<VehicleIntegerDataDO>> automaticDropList = new CopyOnWriteArrayList<>();

  private List<Entry<VehicleIntegerDataDO>> brakeLoopCbList = new CopyOnWriteArrayList<>();

  private final Map<PropertyKey<Integer>, VehicleBrakeLoopIntegerOutPutsRequestHandler> requestHandlerMap = new HashMap<>();

  /**
   * Listener to update vehicleDetailModelList
   */
  IModelListener trainConfigListener = (arg0, arg1) -> {
    vehicleDetailModelList = sharedModel.getVehicleDetailModelList();

    // Write the initial state of VCB status
    if (!vehicleDetailModelList.isEmpty())
    {
      updateMainReserviorStatusList();
      updateAutomaticDropStatusList();
      updateBrakeLoopCbStatusList();
    }
  };

  protected BrakeLoopInterlockScreenHandler(CommsBinding commsBinding, SharedDataModel aSharedModel)
  {
    super(commsBinding, ITCMSVehicleOutputsBrakeLoopInterlockScreenProperties.class,
        ITCMSVehicleOutputsMisceProperties.class);
    sharedModel = aSharedModel;
    initHandlerMap();
  }

  private void initHandlerMap()
  {

    requestHandlerMap.put(ITCMSVehicleOutputsBrakeLoopInterlockScreenProperties.MAIN_RESERVOIR_PRESSURE_LOW,
        new VehicleBrakeLoopIntegerOutPutsRequestHandler(this::updateMainReserviorStatusList,
            mainReserviorList));
    requestHandlerMap.put(ITCMSVehicleOutputsBrakeLoopInterlockScreenProperties.ADD_INTERVENTION,
        new VehicleBrakeLoopIntegerOutPutsRequestHandler(this::updateAutomaticDropStatusList,
            automaticDropList));

    requestHandlerMap.put(ITCMSVehicleOutputsBrakeLoopInterlockScreenProperties.BRAKE_LOOP_CB_TRIPPED,
        new VehicleBrakeLoopIntegerOutPutsRequestHandler(this::updateBrakeLoopCbStatusList, brakeLoopCbList));

  }

  private void updateMainReserviorStatusList()
  {
    updateMainReserviorIntegerValueList(mainReserviorList,
        builder -> setApplicationOutputsProperty(
            IAppOutputsEnableToRunScreenProperties.MAIN_RESERVOIR_PRESSURE_LOW_STATUS,
            builder.build().toByteArray()));
  }

  private void updateMainReserviorIntegerValueList(List<Entry<VehicleIntegerDataDO>> parameterEntryList,
      Consumer<TCMSProto.MainReserviorPressureLowList.Builder> consumer)
  {
    TCMSProto.MainReserviorPressureLowList.Builder builder = TCMSProto.MainReserviorPressureLowList
        .newBuilder();
    TCMSProto.MainReserviorPressureLowList.MainReserviorStatus.Builder vehicleBuilder = TCMSProto.MainReserviorPressureLowList.MainReserviorStatus
        .newBuilder();
    parameterEntryList.forEach(entry -> {
      int carIndex = entry.getIndex();
      vehicleBuilder.setCarIndex(carIndex);
      String carClassCode = vehicleDetailModelList != null
          ? vehicleDetailModelList.get(carIndex).getCarClassCode()
          : ApplicationConstants.BLANK;
      if (TCMSConstants.DM_CAR.equals(carClassCode) || TCMSConstants.M_CAR.equals(carClassCode))
      {
        vehicleBuilder.setMainReseerviorState(
            entry.getData().getValue() == 0 ? BrakeLoopState.NOT_ACTIVE : BrakeLoopState.ACTIVE);
      }
      else
      {
        vehicleBuilder.setMainReseerviorState(BrakeLoopState.NOT_ACTIVE);
      }
      builder.addMainReserviorStatus(vehicleBuilder.build());
    });
    consumer.accept(builder);
  }

  private void updateAutomaticDropStatusList()
  {
    updatAutomaticDropIntegerValueList(automaticDropList, builder -> setApplicationOutputsProperty(
        IAppOutputsEnableToRunScreenProperties.ADD_INTERVENTION_STATUS, builder.build().toByteArray()));
  }

  private void updatAutomaticDropIntegerValueList(List<Entry<VehicleIntegerDataDO>> parameterEntryList,
      Consumer<TCMSProto.AutomaticDropList.Builder> consumer)
  {
    TCMSProto.AutomaticDropList.Builder builder = TCMSProto.AutomaticDropList.newBuilder();
    TCMSProto.AutomaticDropList.AutomaticDropStatus.Builder vehicleBuilder = TCMSProto.AutomaticDropList.AutomaticDropStatus
        .newBuilder();
    parameterEntryList.forEach(entry -> {
      int carIndex = entry.getIndex();
      vehicleBuilder.setCarIndex(carIndex);
     

      vehicleBuilder.setAutomaticDropState(
          entry.getData().getValue() == 0 ? BrakeLoopState.NOT_ACTIVE : BrakeLoopState.ACTIVE);

      builder.addAutomaticDropStatus(vehicleBuilder.build());
    });
    consumer.accept(builder);
  }

  private void updateBrakeLoopCbStatusList()
  {
    updateBrakeLoopCbIntegerValueList(brakeLoopCbList,
        builder -> setApplicationOutputsProperty(
            IAppOutputsEnableToRunScreenProperties.BRAKE_LOOP_CB_TRIPED_STATUS,
            builder.build().toByteArray()));
  }

  private void updateBrakeLoopCbIntegerValueList(List<Entry<VehicleIntegerDataDO>> parameterEntryList,
      Consumer<TCMSProto.BrakeLoopCbTripedList.Builder> consumer)
  {
    TCMSProto.BrakeLoopCbTripedList.Builder builder = TCMSProto.BrakeLoopCbTripedList.newBuilder();
    TCMSProto.BrakeLoopCbTripedList.BrakeLoopCbTripedStatus.Builder vehicleBuilder = TCMSProto.BrakeLoopCbTripedList.BrakeLoopCbTripedStatus
        .newBuilder();
    parameterEntryList.forEach(entry -> {
      int carIndex = entry.getIndex();
      vehicleBuilder.setCarIndex(carIndex);
      String carClassCode = vehicleDetailModelList != null
          ? vehicleDetailModelList.get(carIndex).getCarClassCode()
          : ApplicationConstants.BLANK;
      if (TCMSConstants.M_CAR.equals(carClassCode))
      {
        vehicleBuilder.setBrakeLoopCbTripedState(
            entry.getData().getValue() == 0 ? BrakeLoopState.NOT_ACTIVE : BrakeLoopState.ACTIVE);
      }
      else
      {
        vehicleBuilder.setBrakeLoopCbTripedState(BrakeLoopState.NOT_ACTIVE);
      }
      builder.addBrakeLoopCbTripedStatus(vehicleBuilder.build());
    });
    consumer.accept(builder);
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

  @Override
  public <T> void tcmsVehicleOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue,
      int vehicleIndex)
  {
    @SuppressWarnings("unchecked")
    PropertyKey<Integer> propertyKey = (PropertyKey<Integer>)key;

    VehicleBrakeLoopIntegerOutPutsRequestHandler handler = requestHandlerMap.get(key);
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

 

  /**
   * use this class to instantiate Propulsion Status parameter request handler.
   * 
   */
  class VehicleBrakeLoopIntegerOutPutsRequestHandler extends VehicleStatusIntegerOutPutsRequestHandler
  {

    private VehicleBrakeLoopIntegerOutPutsRequestHandler(Runnable aRunnable,
        List<Entry<VehicleIntegerDataDO>> aList)
    {
      super(aRunnable, aList);
    }

  }

}

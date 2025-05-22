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
import com.sydac.mmrbem.tcms.backend.vehicle.io.properties.ITCMSVehicleOutputsPropulsionSystemProperties;
import com.sydac.mmrbem.tcms.backend.vehicle.request.handler.CommonVehicleOutputsRequest;
import com.sydac.mmrbem.tcms.backend.vehicle.request.handler.VehicleStatusIntegerOutPutsRequestHandler;
import com.sydac.mmrbem.tcms.common.data.Entry;
import com.sydac.mmrbem.tcms.common.data.VehicleDetailModel;
import com.sydac.mmrbem.tcms.common.data.VehicleIntegerDataDO;
import com.sydac.mmrbem.tcms.common.io.properties.IAppOutputsPropulsionSystemScreenProperties;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.AKContactorStatusList.AKContactorState;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.DynamicBrakeStatusList.DynamicBrakeState;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.KContactorStatusList.KContactorState;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.PropulsionEnabledStatusList.PropulsionEnabledState;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.VCBTripCommandStatusList.VCBTripCommandState;
import com.sydac.mmrbem.tcms.common.state.ApplicationConstants;
import com.sydac.mmrbem.tcms.common.state.TCMSConstants;
import com.sydac.mmrbem.tcms.common.utils.UnitConverterHelper;

/**
 * This handler class is used for handling Propulsion System Status screen data
 * 
 */
@Service
@FunctionalLogicHandler(arguments = { CommsBinding.class, SharedDataModel.class })
public class PropulsionSystemScreenHandler extends AbstractFunctionalLogic
{
  private SharedDataModel sharedModel;

  private List<VehicleDetailModel> vehicleDetailModelList;

  private List<Entry<VehicleIntegerDataDO>> propulsionEnabledStatusList = new CopyOnWriteArrayList<>();

  private List<Entry<VehicleIntegerDataDO>> akContactorStatusList = new CopyOnWriteArrayList<>();

  private List<Entry<VehicleIntegerDataDO>> kContactorStatusList = new CopyOnWriteArrayList<>();

  private List<Entry<VehicleIntegerDataDO>> dynamicBrakeStatusList = new CopyOnWriteArrayList<>();

  private List<Entry<VehicleIntegerDataDO>> vcbTripCommandStatusList = new CopyOnWriteArrayList<>();

  private List<Entry<VehicleIntegerDataDO>> filterVoltageValueList = new CopyOnWriteArrayList<>();

  private List<Entry<VehicleIntegerDataDO>> tractiveEffortValueList = new CopyOnWriteArrayList<>();

  /**
   * Listener to update vehicleDetailModelList
   */
  IModelListener trainConfigListener = (arg0, arg1) -> {
    vehicleDetailModelList = sharedModel.getVehicleDetailModelList();
    // Write the initial state of propulsion status
    if (!vehicleDetailModelList.isEmpty())
    {
      updatePropulsionEnabledStatusList();
      updateAkContactorStatusList();
      updateKContactorStatusList();
      updateDynamicBrakeStatusList();
      updateVcbTripCommandStatusList();
      updateFilterVoltValueList();
      updateTractiveEffortValueList();

    }
  };

  /**
   * This map holds request handles for Propulsion Status related parameters.
   */
  private final Map<PropertyKey<Integer>, VehiclePropulsionStatusIntegerOutPutsRequestHandler> requestHandlerMap = new HashMap<>();

  public PropulsionSystemScreenHandler(CommsBinding commsBinding, SharedDataModel aSharedModel)
  {
    super(commsBinding, ITCMSVehicleOutputsPropulsionSystemProperties.class);
    sharedModel = aSharedModel;

    initHandlerMap();
  }

  private void initHandlerMap()
  {
    requestHandlerMap.put(ITCMSVehicleOutputsPropulsionSystemProperties.PROPULSION_ENABLE_STATUS,
        new VehiclePropulsionStatusIntegerOutPutsRequestHandler(this::updatePropulsionEnabledStatusList,
            propulsionEnabledStatusList));
    requestHandlerMap.put(ITCMSVehicleOutputsPropulsionSystemProperties.AK_CONTACTOR_STATUS,
        new VehiclePropulsionStatusIntegerOutPutsRequestHandler(this::updateAkContactorStatusList,
            akContactorStatusList));
    requestHandlerMap.put(ITCMSVehicleOutputsPropulsionSystemProperties.K_CONTACTOR_STATUS,
        new VehiclePropulsionStatusIntegerOutPutsRequestHandler(this::updateKContactorStatusList,
            kContactorStatusList));
    requestHandlerMap.put(ITCMSVehicleOutputsPropulsionSystemProperties.ED_BRAKE_STATUS,
        new VehiclePropulsionStatusIntegerOutPutsRequestHandler(this::updateDynamicBrakeStatusList,
            dynamicBrakeStatusList));
    requestHandlerMap.put(ITCMSVehicleOutputsPropulsionSystemProperties.VCB_TRIP_COMMAND_STATUS,
        new VehiclePropulsionStatusIntegerOutPutsRequestHandler(this::updateVcbTripCommandStatusList,
            vcbTripCommandStatusList));
    requestHandlerMap.put(ITCMSVehicleOutputsPropulsionSystemProperties.FILTER_VOLTAGE,
        new VehiclePropulsionStatusIntegerOutPutsRequestHandler(this::updateFilterVoltValueList,
            filterVoltageValueList));
    requestHandlerMap.put(ITCMSVehicleOutputsPropulsionSystemProperties.TRACTIVE_EFFORT,
        new VehiclePropulsionStatusIntegerOutPutsRequestHandler(this::updateTractiveEffortValueList,
            tractiveEffortValueList));

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
  class VehiclePropulsionStatusIntegerOutPutsRequestHandler extends VehicleStatusIntegerOutPutsRequestHandler
  {

    private VehiclePropulsionStatusIntegerOutPutsRequestHandler(Runnable aRunnable,
        List<Entry<VehicleIntegerDataDO>> aList)
    {
      super(aRunnable, aList);
    }

  }

  private void updatePropulsionEnabledStatusList()
  {
    updateAppPropulsionEnabledIntegerValueList(propulsionEnabledStatusList,
        builder -> setApplicationOutputsProperty(
            IAppOutputsPropulsionSystemScreenProperties.PROPULSION_ENABLED_STATUS,
            builder.build().toByteArray()));
  }

  private void updateAkContactorStatusList()
  {
    updateAppAkContactorIntegerValueList(akContactorStatusList, builder -> setApplicationOutputsProperty(
        IAppOutputsPropulsionSystemScreenProperties.AK_CONTACTOR_STATUS, builder.build().toByteArray()));
  }

  private void updateDynamicBrakeStatusList()
  {
    updateAppDynamicBrakeIntegerValueList(dynamicBrakeStatusList, builder -> setApplicationOutputsProperty(
        IAppOutputsPropulsionSystemScreenProperties.DYNAMIC_BRAKE_STATUS, builder.build().toByteArray()));
  }

  private void updateVcbTripCommandStatusList()
  {
    updateAppVcbTripCommandIntegerValueList(vcbTripCommandStatusList,
        builder -> setApplicationOutputsProperty(
            IAppOutputsPropulsionSystemScreenProperties.VCB_TRIP_COMMAND_STATUS,
            builder.build().toByteArray()));
  }

  private void updateFilterVoltValueList()
  {
    updateAppFilterVoltIntegerValueList(filterVoltageValueList,
        builder -> setApplicationOutputsProperty(
            IAppOutputsPropulsionSystemScreenProperties.FILTER_VOLTAGE_STATUS,
            builder.build().toByteArray()));
  }

  private void updateTractiveEffortValueList()
  {
    updateAppTractiveEffortIntegerValueList(tractiveEffortValueList,
        builder -> setApplicationOutputsProperty(
            IAppOutputsPropulsionSystemScreenProperties.TRACTIVE_EFFORT_STATUS,
            builder.build().toByteArray()));
  }

  private void updateKContactorStatusList()
  {
    updateAppKContactorIntegerValueList(kContactorStatusList, builder -> setApplicationOutputsProperty(
        IAppOutputsPropulsionSystemScreenProperties.K_CONTACTOR_STATUS, builder.build().toByteArray()));
  }

  private void updateAppPropulsionEnabledIntegerValueList(
      List<Entry<VehicleIntegerDataDO>> parameterEntryList,
      Consumer<TCMSProto.PropulsionEnabledStatusList.Builder> consumer)
  {
    TCMSProto.PropulsionEnabledStatusList.Builder builder = TCMSProto.PropulsionEnabledStatusList
        .newBuilder();
    TCMSProto.PropulsionEnabledStatusList.PropulsionEnabledStatus.Builder vehicleBuilder = TCMSProto.PropulsionEnabledStatusList.PropulsionEnabledStatus
        .newBuilder();
    parameterEntryList.forEach(entry -> {
      int carIndex = entry.getIndex();
      vehicleBuilder.setCarIndex(carIndex);
      String carClassCode = vehicleDetailModelList != null
          ? vehicleDetailModelList.get(carIndex).getCarClassCode()
          : ApplicationConstants.BLANK;
      if (TCMSConstants.DM_CAR.equals(carClassCode) || TCMSConstants.M_CAR.equals(carClassCode))
      {
        vehicleBuilder
            .setPropulsionEnabledState(entry.getData().getValue() == 0 ? PropulsionEnabledState.NOT_ENABLED
                : PropulsionEnabledState.ENABLED);
      }
      else
      {
        vehicleBuilder.setPropulsionEnabledState(PropulsionEnabledState.UNKNOWN);
      }
      builder.addPropulsionEnabledStatus(vehicleBuilder.build());
    });
    consumer.accept(builder);
  }

  private void updateAppAkContactorIntegerValueList(List<Entry<VehicleIntegerDataDO>> parameterEntryList,
      Consumer<TCMSProto.AKContactorStatusList.Builder> consumer)
  {
    TCMSProto.AKContactorStatusList.Builder builder = TCMSProto.AKContactorStatusList.newBuilder();
    TCMSProto.AKContactorStatusList.AKContactorStatus.Builder vehicleBuilder = TCMSProto.AKContactorStatusList.AKContactorStatus
        .newBuilder();
    parameterEntryList.forEach(entry -> {
      int carIndex = entry.getIndex();
      vehicleBuilder.setCarIndex(carIndex);
      String carClassCode = vehicleDetailModelList != null
          ? vehicleDetailModelList.get(carIndex).getCarClassCode()
          : ApplicationConstants.BLANK;
      if (TCMSConstants.DM_CAR.equals(carClassCode) || TCMSConstants.M_CAR.equals(carClassCode))
      {
        vehicleBuilder.setAkContactorState(
            entry.getData().getValue() == 1 ? AKContactorState.CLOSED : AKContactorState.OPEN);
      }
      else
      {
        vehicleBuilder.setAkContactorState(AKContactorState.UNKNOWN);
      }
      builder.addAkContactorStatus(vehicleBuilder.build());
    });
    consumer.accept(builder);
  }

  private void updateAppKContactorIntegerValueList(List<Entry<VehicleIntegerDataDO>> parameterEntryList,
      Consumer<TCMSProto.KContactorStatusList.Builder> consumer)
  {
    TCMSProto.KContactorStatusList.Builder builder = TCMSProto.KContactorStatusList.newBuilder();
    TCMSProto.KContactorStatusList.KContactorStatus.Builder vehicleBuilder = TCMSProto.KContactorStatusList.KContactorStatus
        .newBuilder();
    parameterEntryList.forEach(entry -> {
      int carIndex = entry.getIndex();
      vehicleBuilder.setCarIndex(carIndex);
      String carClassCode = vehicleDetailModelList != null
          ? vehicleDetailModelList.get(carIndex).getCarClassCode()
          : ApplicationConstants.BLANK;
      if (TCMSConstants.DM_CAR.equals(carClassCode) || TCMSConstants.M_CAR.equals(carClassCode))
      {
        vehicleBuilder.setKContactorState(
            entry.getData().getValue() == 1 ? KContactorState.CLOSED : KContactorState.OPEN);
      }
      else
      {
        vehicleBuilder.setKContactorState(KContactorState.UNKNOWN);
      }
      builder.addKContactorStatus(vehicleBuilder.build());
    });
    consumer.accept(builder);
  }

  private void updateAppDynamicBrakeIntegerValueList(List<Entry<VehicleIntegerDataDO>> parameterEntryList,
      Consumer<TCMSProto.DynamicBrakeStatusList.Builder> consumer)
  {
    TCMSProto.DynamicBrakeStatusList.Builder builder = TCMSProto.DynamicBrakeStatusList.newBuilder();
    TCMSProto.DynamicBrakeStatusList.DynamicBrakeStatus.Builder vehicleBuilder = TCMSProto.DynamicBrakeStatusList.DynamicBrakeStatus
        .newBuilder();
    parameterEntryList.forEach(entry -> {
      int carIndex = entry.getIndex();
      vehicleBuilder.setCarIndex(carIndex);
      String carClassCode = vehicleDetailModelList != null
          ? vehicleDetailModelList.get(carIndex).getCarClassCode()
          : ApplicationConstants.BLANK;
      if (TCMSConstants.DM_CAR.equals(carClassCode) || TCMSConstants.M_CAR.equals(carClassCode))
      {
        vehicleBuilder.setDynamicBrakeState(
            entry.getData().getValue() == 1 ? DynamicBrakeState.AVAILABLE : DynamicBrakeState.UNAVAILABLE);
      }
      else
      {
        vehicleBuilder.setDynamicBrakeState(DynamicBrakeState.UNKNOWN);
      }
      builder.addDynamicBrakeStatus(vehicleBuilder.build());
    });
    consumer.accept(builder);
  }

  private void updateAppVcbTripCommandIntegerValueList(List<Entry<VehicleIntegerDataDO>> parameterEntryList,
      Consumer<TCMSProto.VCBTripCommandStatusList.Builder> consumer)
  {
    TCMSProto.VCBTripCommandStatusList.Builder builder = TCMSProto.VCBTripCommandStatusList.newBuilder();
    TCMSProto.VCBTripCommandStatusList.VCBTripCommandStatus.Builder vehicleBuilder = TCMSProto.VCBTripCommandStatusList.VCBTripCommandStatus
        .newBuilder();
    parameterEntryList.forEach(entry -> {
      int carIndex = entry.getIndex();
      vehicleBuilder.setCarIndex(carIndex);
      String carClassCode = vehicleDetailModelList != null
          ? vehicleDetailModelList.get(carIndex).getCarClassCode()
          : ApplicationConstants.BLANK;
      if (TCMSConstants.DM_CAR.equals(carClassCode) || TCMSConstants.M_CAR.equals(carClassCode))
      {
        vehicleBuilder.setVcbTripCommandState(
            entry.getData().getValue() == 0 ? VCBTripCommandState.NORMAL : VCBTripCommandState.TRIP_FORCED);
      }
      else
      {
        vehicleBuilder.setVcbTripCommandState(VCBTripCommandState.UNKNOWN);
      }
      builder.addVcbTripCommandStatus(vehicleBuilder.build());
    });
    consumer.accept(builder);
  }

  private void updateAppFilterVoltIntegerValueList(List<Entry<VehicleIntegerDataDO>> parameterEntryList,
      Consumer<TCMSProto.FilterVoltageStatusList.Builder> consumer)
  {
    TCMSProto.FilterVoltageStatusList.Builder builder = TCMSProto.FilterVoltageStatusList.newBuilder();
    TCMSProto.FilterVoltageStatusList.FilterVoltage.Builder vehicleBuilder = TCMSProto.FilterVoltageStatusList.FilterVoltage
        .newBuilder();
    parameterEntryList.forEach(entry -> {
      int carIndex = entry.getIndex();
      vehicleBuilder.setCarIndex(carIndex);
      String carClassCode = vehicleDetailModelList != null
          ? vehicleDetailModelList.get(carIndex).getCarClassCode()
          : ApplicationConstants.BLANK;
      if (TCMSConstants.DM_CAR.equals(carClassCode) || TCMSConstants.M_CAR.equals(carClassCode))
      {
        vehicleBuilder.setFilterVoltage(entry.getData().getValue());
      }
      else
      {
        // Passing -99 through constant to determine value not applicable in FE
        // for corresponding cars.
        vehicleBuilder.setFilterVoltage(ApplicationConstants.VALUE_NOT_APPLICABLE);
      }
      builder.addFilterVoltage(vehicleBuilder.build());
    });
    consumer.accept(builder);
  }

  private void updateAppTractiveEffortIntegerValueList(List<Entry<VehicleIntegerDataDO>> parameterEntryList,
      Consumer<TCMSProto.TractiveEffortStatusList.Builder> consumer)
  {
    TCMSProto.TractiveEffortStatusList.Builder builder = TCMSProto.TractiveEffortStatusList.newBuilder();
    TCMSProto.TractiveEffortStatusList.TractiveEffort.Builder vehicleBuilder = TCMSProto.TractiveEffortStatusList.TractiveEffort
        .newBuilder();
    parameterEntryList.forEach(entry -> {
      int carIndex = entry.getIndex();
      vehicleBuilder.setCarIndex(carIndex);
      String carClassCode = vehicleDetailModelList != null
          ? vehicleDetailModelList.get(carIndex).getCarClassCode()
          : ApplicationConstants.BLANK;
      if (TCMSConstants.DM_CAR.equals(carClassCode) || TCMSConstants.M_CAR.equals(carClassCode))
      {
        int tractiveEffort = UnitConverterHelper.convertNToKN(entry.getData().getValue());
        vehicleBuilder.setTractiveEffort(tractiveEffort);
      }
      else
      {
        // Passing -99 through constant to determine value not applicable in FE
        // for corresponding cars.
        vehicleBuilder.setTractiveEffort(ApplicationConstants.VALUE_NOT_APPLICABLE);
      }
      builder.addTractiveEffort(vehicleBuilder.build());
    });
    consumer.accept(builder);
  }

  @Override
  public <T> void tcmsVehicleOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue,
      int vehicleIndex)
  {
    @SuppressWarnings("unchecked")
    PropertyKey<Integer> propertyKey = (PropertyKey<Integer>)key;

    VehiclePropulsionStatusIntegerOutPutsRequestHandler handler = requestHandlerMap.get(key);
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

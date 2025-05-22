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
import com.sydac.mmrbem.tcms.backend.vehicle.io.properties.ITCMSVehicleOutputsLightSystemProperties;
import com.sydac.mmrbem.tcms.backend.vehicle.request.handler.CommonVehicleOutputsRequest;
import com.sydac.mmrbem.tcms.backend.vehicle.request.handler.VehicleStatusIntegerOutPutsRequestHandler;
import com.sydac.mmrbem.tcms.common.data.Entry;
import com.sydac.mmrbem.tcms.common.data.VehicleDetailModel;
import com.sydac.mmrbem.tcms.common.data.VehicleIntegerDataDO;
import com.sydac.mmrbem.tcms.common.io.properties.IAppOutputsLightSystemScreenProperties;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.LightStatusList.LightState;
import com.sydac.mmrbem.tcms.common.state.ApplicationConstants;
import com.sydac.mmrbem.tcms.common.state.TCMSConstants;

/**
 * This handler class is used for handling Light System Status screen data
 * 
 */
@Service
@FunctionalLogicHandler(arguments = { CommsBinding.class, SharedDataModel.class })
public class LightSystemScreenHandler extends AbstractFunctionalLogic
{
  private SharedDataModel sharedModel;

  private List<VehicleDetailModel> vehicleDetailModelList;

  private List<Entry<VehicleIntegerDataDO>> saloonLightGroupStatus1List = new CopyOnWriteArrayList<>();

  private List<Entry<VehicleIntegerDataDO>> saloonLightGroupStatus2List = new CopyOnWriteArrayList<>();

  private List<Entry<VehicleIntegerDataDO>> flasherLightStatusList = new CopyOnWriteArrayList<>();

  /**
   * Listener to update vehicleDetailModelList
   */
  IModelListener trainConfigListener = (arg0, arg1) -> {
    vehicleDetailModelList = sharedModel.getVehicleDetailModelList();
    // Write the initial state of propulsion status
    if (!vehicleDetailModelList.isEmpty())
    {
      updateSaloonLightGroupStatus1List();
      updateSaloonLightGroupStatus2List();
      updateFlasherLightStatusList();
    }
  };

  /**
   * This map holds request handles for Propulsion Status related parameters.
   */
  private final Map<PropertyKey<Integer>, VehicleLightSystemStatusIntegerOutPutsRequestHandler> requestHandlerMap = new HashMap<>();

  public LightSystemScreenHandler(CommsBinding commsBinding, SharedDataModel aSharedModel)
  {
    super(commsBinding, ITCMSVehicleOutputsLightSystemProperties.class);
    sharedModel = aSharedModel;

    initHandlerMap();
  }

  private void initHandlerMap()
  {
    requestHandlerMap.put(ITCMSVehicleOutputsLightSystemProperties.SALOON_LIGHT_GROUP_STATUS_1,
        new VehicleLightSystemStatusIntegerOutPutsRequestHandler(this::updateSaloonLightGroupStatus1List,
            saloonLightGroupStatus1List));
    requestHandlerMap.put(ITCMSVehicleOutputsLightSystemProperties.SALOON_LIGHT_GROUP_STATUS_2,
        new VehicleLightSystemStatusIntegerOutPutsRequestHandler(this::updateSaloonLightGroupStatus2List,
            saloonLightGroupStatus2List));
    requestHandlerMap.put(ITCMSVehicleOutputsLightSystemProperties.FLASHER_LIGHT_STATUS,
        new VehicleLightSystemStatusIntegerOutPutsRequestHandler(this::updateFlasherLightStatusList,
            flasherLightStatusList));
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
  class VehicleLightSystemStatusIntegerOutPutsRequestHandler extends VehicleStatusIntegerOutPutsRequestHandler
  {

    private VehicleLightSystemStatusIntegerOutPutsRequestHandler(Runnable aRunnable,
        List<Entry<VehicleIntegerDataDO>> aList)
    {
      super(aRunnable, aList);
    }

  }

  private void updateSaloonLightGroupStatus1List()
  {
    updateAppLightGroupStatusIntegerValueList(saloonLightGroupStatus1List,
        builder -> setApplicationOutputsProperty(
            IAppOutputsLightSystemScreenProperties.SALOON_LIGHT_GROUP_STATUS_1,
            builder.build().toByteArray()));
  }

  private void updateSaloonLightGroupStatus2List()
  {
    updateAppLightGroupStatusIntegerValueList(saloonLightGroupStatus2List,
        builder -> setApplicationOutputsProperty(
            IAppOutputsLightSystemScreenProperties.SALOON_LIGHT_GROUP_STATUS_2,
            builder.build().toByteArray()));
  }

  private void updateFlasherLightStatusList()
  {
    updateAppFlasherLightGroupStatusIntegerValueList(flasherLightStatusList,
        builder -> setApplicationOutputsProperty(IAppOutputsLightSystemScreenProperties.FLASHER_LIGHT_STATUS,
            builder.build().toByteArray()));
  }

  private void updateAppLightGroupStatusIntegerValueList(List<Entry<VehicleIntegerDataDO>> parameterEntryList,
      Consumer<TCMSProto.LightStatusList.Builder> consumer)
  {
    TCMSProto.LightStatusList.Builder builder = TCMSProto.LightStatusList.newBuilder();
    TCMSProto.LightStatusList.LightStatus.Builder vehicleBuilder = TCMSProto.LightStatusList.LightStatus
        .newBuilder();
    parameterEntryList.forEach(entry -> {
      int carIndex = entry.getIndex();
      vehicleBuilder.setCarIndex(carIndex);
      if (entry.getData().getValue() == LightState.LIGHT_SYSTEM_UNKNOWN_VALUE)
      {
        vehicleBuilder.setLightState(LightState.LIGHT_SYSTEM_UNKNOWN);
      }
      else if (entry.getData().getValue() == LightState.LIGHT_SYSTEM_OFF_VALUE)
      {
        vehicleBuilder.setLightState(LightState.LIGHT_SYSTEM_OFF);
      }
      else if (entry.getData().getValue() == LightState.LIGHT_SYSTEM_ON_VALUE)
      {
        vehicleBuilder.setLightState(LightState.LIGHT_SYSTEM_ON);
      }
      builder.addLightStatus(vehicleBuilder.build());
    });
    consumer.accept(builder);
  }

  private void updateAppFlasherLightGroupStatusIntegerValueList(
      List<Entry<VehicleIntegerDataDO>> parameterEntryList,
      Consumer<TCMSProto.LightStatusList.Builder> consumer)
  {
    TCMSProto.LightStatusList.Builder builder = TCMSProto.LightStatusList.newBuilder();
    TCMSProto.LightStatusList.LightStatus.Builder vehicleBuilder = TCMSProto.LightStatusList.LightStatus
        .newBuilder();
    parameterEntryList.forEach(entry -> {
      int carIndex = entry.getIndex();
      vehicleBuilder.setCarIndex(carIndex);
      String carClassCode = vehicleDetailModelList != null
          ? vehicleDetailModelList.get(carIndex).getCarClassCode()
          : ApplicationConstants.BLANK;
      if (TCMSConstants.DM_CAR.equals(carClassCode))
      {
        if (entry.getData().getValue() == LightState.LIGHT_SYSTEM_UNKNOWN_VALUE)
        {
          vehicleBuilder.setLightState(LightState.LIGHT_SYSTEM_UNKNOWN);
        }
        else if (entry.getData().getValue() == LightState.LIGHT_SYSTEM_OFF_VALUE)
        {
          vehicleBuilder.setLightState(LightState.LIGHT_SYSTEM_OFF);
        }
        else if (entry.getData().getValue() == LightState.LIGHT_SYSTEM_ON_VALUE)
        {
          vehicleBuilder.setLightState(LightState.LIGHT_SYSTEM_ON);
        }
      }
      else
      {
        vehicleBuilder.setLightState(LightState.LIGHT_SYSTEM_UNAVAILABLE);
      }
      builder.addLightStatus(vehicleBuilder.build());
    });
    consumer.accept(builder);
  }

  @Override
  public <T> void tcmsVehicleOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue,
      int vehicleIndex)
  {
    @SuppressWarnings("unchecked")
    PropertyKey<Integer> propertyKey = (PropertyKey<Integer>)key;

    VehicleLightSystemStatusIntegerOutPutsRequestHandler handler = requestHandlerMap.get(key);
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

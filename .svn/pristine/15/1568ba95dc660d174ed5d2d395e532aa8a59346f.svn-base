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
import com.sydac.mmrbem.tcms.backend.vehicle.io.handlers.ITCMSVehicleInputsMiscellaniaScreenHandler;
import com.sydac.mmrbem.tcms.backend.vehicle.io.properties.ITCMSVehicleOutputsMisceProperties;
import com.sydac.mmrbem.tcms.backend.vehicle.io.properties.ITCMSVehicleOutputsProperties;
import com.sydac.mmrbem.tcms.backend.vehicle.request.handler.CommonVehicleOutputsRequest;
import com.sydac.mmrbem.tcms.backend.vehicle.request.handler.VehicleStatusIntegerOutPutsRequestHandler;
import com.sydac.mmrbem.tcms.common.data.Entry;
import com.sydac.mmrbem.tcms.common.data.VehicleDetailModel;
import com.sydac.mmrbem.tcms.common.data.VehicleIntegerDataDO;
import com.sydac.mmrbem.tcms.common.io.properties.IAppInputsMiscellaniaScreenProperties;
import com.sydac.mmrbem.tcms.common.io.properties.IAppInputsProperties;
import com.sydac.mmrbem.tcms.common.io.properties.IAppOutputsMiscellaniaScreenProperties;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.MiscState;
import com.sydac.mmrbem.tcms.common.state.ApplicationConstants;
import com.sydac.mmrbem.tcms.common.state.TCMSConstants;

/**
 * This handler class is used for Miscellania screen handling.
 * 
 */

@Service
@FunctionalLogicHandler(arguments = { CommsBinding.class, SharedDataModel.class })
public class MiscellaniaScreenHandler extends AbstractFunctionalLogic
{
  private SharedDataModel shareDataModel;

  private ITCMSVehicleInputsMiscellaniaScreenHandler vehicleInputsHandler;
  
  private List<Entry<VehicleIntegerDataDO>> derailmentLeftStatusList = new CopyOnWriteArrayList<>();
  private List<Entry<VehicleIntegerDataDO>> derailmentRightStatusList = new CopyOnWriteArrayList<>();
  
  private List<Entry<VehicleIntegerDataDO>> obstructionLeftStatusList = new CopyOnWriteArrayList<>();
  private List<Entry<VehicleIntegerDataDO>> obstructionRightStatusList = new CopyOnWriteArrayList<>();

  private List<VehicleDetailModel> vehicleDetailModelList;

  /**
   * This map holds request handles for Propulsion Status related parameters.
   */
  private final Map<PropertyKey<Integer>, VehicleMiscStatusIntegerOutPutsRequestHandler> requestHandlerMap = new HashMap<>();

  /**
   * Listener to update vehicleDetailModelList
   */
  IModelListener trainConfigListener = (arg0, arg1) -> {
    vehicleDetailModelList = shareDataModel.getVehicleDetailModelList();
    // Write the initial state of propulsion status
    if (!vehicleDetailModelList.isEmpty())
    {
      updateDerailementLeftStatusList();
      updateDerailementRightStatusList();
      updateObstructionLeftStatusList();
      updateObstructionRightStatusList();

    }
  };

  protected MiscellaniaScreenHandler(CommsBinding commsBinding, SharedDataModel aShareDataModel)
  {
    super(commsBinding, IAppInputsProperties.class, ITCMSVehicleOutputsProperties.class);
    shareDataModel = aShareDataModel;

    initHandlerMap();
    initalizeVehicleInputHandler();
  }

  @Override
  public <T> void tcmsVehicleOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue,
      int vehicleIndex)
  {
    if (ITCMSVehicleOutputsProperties.POWER_OFF_PRESSED.equals(key) && Boolean.TRUE.equals(newValue))
    {
      resetInputCommands();
    }

    @SuppressWarnings("unchecked")
    PropertyKey<Integer> propertyKey = (PropertyKey<Integer>)key;

    VehicleMiscStatusIntegerOutPutsRequestHandler handler = requestHandlerMap.get(key);
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

  private void resetInputCommands()
  {
    for (int carIndex = 0; carIndex < shareDataModel.getTotalCar(); carIndex++)
    {
      vehicleInputsHandler = (ITCMSVehicleInputsMiscellaniaScreenHandler)getTCMSVehicleInputsSetter(carIndex);

      vehicleInputsHandler.setHornIsolate(ApplicationConstants.RESET_VALUE);
      setApplicationOutputsProperty(
          IAppOutputsMiscellaniaScreenProperties.HORN_ISOLATE_RESINSERT_FRONT_STATUS,
          ApplicationConstants.RESET_VALUE);
      setApplicationOutputsProperty(IAppOutputsMiscellaniaScreenProperties.HORN_ISOLATE_RESINSERT_REAR_STATUS,
          ApplicationConstants.RESET_VALUE);
    }
  }

  @Override
  public <T> void appInputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue, int vehicleIndex)
  {
    if (getActiveVehicleIndex() == vehicleIndex)
    {
      if (key.equals(IAppInputsMiscellaniaScreenProperties.LOW_SOUND_HORN_FRONT_REQ))
      {
        setLowSoundHornReq(newValue, TCMSConstants.DM1_CAR);
      }
      else if (key.equals(IAppInputsMiscellaniaScreenProperties.LOW_SOUND_HORN_REAR_REQ))
      {
        if (shareDataModel.getTotalCar() == TCMSConstants.CAB_6)
        {
          setLowSoundHornReq(newValue, TCMSConstants.DM6_CAR);
        }
        else
        {
          setLowSoundHornReq(newValue, TCMSConstants.DM8_CAR);
        }
      }
      else if (key.equals(IAppInputsMiscellaniaScreenProperties.HIGH_SOUND_HORN_FRONT_REQ))
      {
        setHighSoundHornReq(newValue, TCMSConstants.DM1_CAR);
      }
      else if (key.equals(IAppInputsMiscellaniaScreenProperties.HIGH_SOUND_HORN_REAR_REQ))
      {
        if (shareDataModel.getTotalCar() == TCMSConstants.CAB_6)
        {
          setHighSoundHornReq(newValue, TCMSConstants.DM6_CAR);
        }
        else
        {
          setHighSoundHornReq(newValue, TCMSConstants.DM8_CAR);
        }
      }
      else if (key.equals(IAppInputsMiscellaniaScreenProperties.HORN_ISOLATE_RESINSERT_FRONT_REQ)
          && (Integer)newValue > -1)
      {
        setApplicationOutputsProperty(
            IAppOutputsMiscellaniaScreenProperties.HORN_ISOLATE_RESINSERT_FRONT_STATUS, (Integer)newValue);
        setHornIsolateReinsertReq(newValue, TCMSConstants.DM1_CAR);
      }
      else if (key.equals(IAppInputsMiscellaniaScreenProperties.HORN_ISOLATE_RESINSERT_REAR_REQ)
          && (Integer)newValue > -1)
      {
        setApplicationOutputsProperty(
            IAppOutputsMiscellaniaScreenProperties.HORN_ISOLATE_RESINSERT_REAR_STATUS, (Integer)newValue);
        if (shareDataModel.getTotalCar() == TCMSConstants.CAB_6)
        {
          setHornIsolateReinsertReq(newValue, TCMSConstants.DM6_CAR);
        }
        else
        {
          setHornIsolateReinsertReq(newValue, TCMSConstants.DM8_CAR);
        }
      }
    }
  }

  private <T> void setLowSoundHornReq(T newValue, int vehicleIndex)
  {

    if (vehicleInputsHandler != null)
    {
      vehicleInputsHandler = (ITCMSVehicleInputsMiscellaniaScreenHandler)getTCMSVehicleInputsSetter(
          vehicleIndex);

      vehicleInputsHandler.setHornLow((Integer)newValue);
    }
  }

  private <T> void setHighSoundHornReq(T newValue, int vehicleIndex)
  {

    if (vehicleInputsHandler != null)
    {
      vehicleInputsHandler = (ITCMSVehicleInputsMiscellaniaScreenHandler)getTCMSVehicleInputsSetter(
          vehicleIndex);

      vehicleInputsHandler.setHornHigh((Integer)newValue);
    }
  }

  private <T> void setHornIsolateReinsertReq(T newValue, int vehicleIndex)
  {

    if (vehicleInputsHandler != null)
    {
      vehicleInputsHandler = (ITCMSVehicleInputsMiscellaniaScreenHandler)getTCMSVehicleInputsSetter(
          vehicleIndex);

      vehicleInputsHandler.setHornIsolate((Integer)newValue);
    }
  }

  private void initalizeVehicleInputHandler()
  {
    if (vehicleInputsHandler == null)
    {
      vehicleInputsHandler = (ITCMSVehicleInputsMiscellaniaScreenHandler)getTCMSVehicleInputsSetter(
          getActiveVehicleIndex());
    }
  }

  @Override
  public void attachListeners()
  {
    super.attachListeners();
    shareDataModel.addModelListener(trainConfigListener, Change.TRAIN_CONFIGURED, true);
    initalizeVehicleInputHandler();
  }

  /**
   * Detach listeners.
   */
  @Override
  public void detachListeners()
  {
    super.detachListeners();
    shareDataModel.removeModelListener(trainConfigListener, Change.TRAIN_CONFIGURED);
  }

  class VehicleMiscStatusIntegerOutPutsRequestHandler extends VehicleStatusIntegerOutPutsRequestHandler
  {

    private VehicleMiscStatusIntegerOutPutsRequestHandler(Runnable aRunnable,
        List<Entry<VehicleIntegerDataDO>> aList)
    {
      super(aRunnable, aList);
    }

  }

  private void initHandlerMap()
  {
    requestHandlerMap.put(ITCMSVehicleOutputsMisceProperties.DERAILMENT_DETECTED_LEFT,
        new VehicleMiscStatusIntegerOutPutsRequestHandler(this::updateDerailementLeftStatusList,
            derailmentLeftStatusList));
    
    requestHandlerMap.put(ITCMSVehicleOutputsMisceProperties.DERAILMENT_DETECTED_RIGHT,
        new VehicleMiscStatusIntegerOutPutsRequestHandler(this::updateDerailementRightStatusList,
            derailmentRightStatusList));
    
    requestHandlerMap.put(ITCMSVehicleOutputsMisceProperties.OBSTRUCTION_DETECTED_LEFT,
        new VehicleMiscStatusIntegerOutPutsRequestHandler(this::updateObstructionLeftStatusList,
            obstructionLeftStatusList));
    
    requestHandlerMap.put(ITCMSVehicleOutputsMisceProperties.OBSTRUCTION_DETECTED_RIGHT,
        new VehicleMiscStatusIntegerOutPutsRequestHandler(this::updateObstructionRightStatusList,
            obstructionRightStatusList));
    
  }

  private void updateDerailementLeftStatusList()
  {
    updateDerailementIntegerValueList(derailmentLeftStatusList,
        builder -> setApplicationOutputsProperty(
            IAppOutputsMiscellaniaScreenProperties.MISC_DERAILMENT_DETECTED_LEFT,
            builder.build().toByteArray()));
  }
  
  
  
  
  
  private void updateDerailementRightStatusList()
  {
    updateDerailementIntegerValueList(derailmentRightStatusList,
        builder -> setApplicationOutputsProperty(
            IAppOutputsMiscellaniaScreenProperties.MISC_DERAILMENT_DETECTED_RIGHT,
            builder.build().toByteArray()));
  }

 
  private void updateObstructionLeftStatusList()
  {
    updateObstructionIntegerValueList(obstructionLeftStatusList,
        builder -> setApplicationOutputsProperty(
            IAppOutputsMiscellaniaScreenProperties.MISC_OBSTRUCTION_DETECTED_LEFT,
            builder.build().toByteArray()));
  }
  
  private void updateObstructionRightStatusList()
  {
    updateObstructionIntegerValueList(obstructionRightStatusList,
        builder -> setApplicationOutputsProperty(
            IAppOutputsMiscellaniaScreenProperties.MISC_OBSTRUCTION_DETECTED_RIGHT,
            builder.build().toByteArray()));
  }
  
  
  private void updateDerailementIntegerValueList(List<Entry<VehicleIntegerDataDO>> parameterEntryList,
      Consumer<TCMSProto.DerailmentStatusList.Builder> consumer)
  {
    TCMSProto.DerailmentStatusList.Builder builder = TCMSProto.DerailmentStatusList.newBuilder();
    TCMSProto.DerailmentStatusList.DerailmentStatus.Builder vehicleBuilder = TCMSProto.DerailmentStatusList.DerailmentStatus
        .newBuilder();
    parameterEntryList.forEach(entry -> {
      int carIndex = entry.getIndex();
      vehicleBuilder.setCarIndex(carIndex);
      String carClassCode = vehicleDetailModelList != null
          ? vehicleDetailModelList.get(carIndex).getCarClassCode()
          : ApplicationConstants.BLANK;
      if (TCMSConstants.DM_CAR.equals(carClassCode))
      {

        vehicleBuilder.setMiscState(
            entry.getData().getValue() == 0 ? MiscState.MISC_NOT_ACTIVE : MiscState.MISC_ACTIVE);

      }
      else
      {
        vehicleBuilder.setMiscState(MiscState.MISC_NOT_ACTIVE);
      }
      builder.addDerailmentStatus(vehicleBuilder.build());
    });
    consumer.accept(builder);
  }
  
  
  private void updateObstructionIntegerValueList(List<Entry<VehicleIntegerDataDO>> parameterEntryList,
      Consumer<TCMSProto.ObstrectionStatusList.Builder> consumer)
  {
    TCMSProto.ObstrectionStatusList.Builder builder = TCMSProto.ObstrectionStatusList.newBuilder();
    TCMSProto.ObstrectionStatusList.ObstrectionStatus.Builder vehicleBuilder = TCMSProto.ObstrectionStatusList.ObstrectionStatus
        .newBuilder();
    parameterEntryList.forEach(entry -> {
      int carIndex = entry.getIndex();
      vehicleBuilder.setCarIndex(carIndex);
      String carClassCode = vehicleDetailModelList != null
          ? vehicleDetailModelList.get(carIndex).getCarClassCode()
          : ApplicationConstants.BLANK;
      if (TCMSConstants.DM_CAR.equals(carClassCode))
      {

        vehicleBuilder.setMiscState(
            entry.getData().getValue() == 0 ? MiscState.MISC_NOT_ACTIVE : MiscState.MISC_ACTIVE);

      }
      else
      {
        vehicleBuilder.setMiscState(MiscState.MISC_NOT_ACTIVE);
      }
      builder.addObstrectionStatus(vehicleBuilder.build());
    });
    consumer.accept(builder);
  }
}

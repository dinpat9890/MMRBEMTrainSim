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
import com.sydac.foundation.PropertyKey;
import com.sydac.mmrbem.tcms.backend.comms.CommsBinding;
import com.sydac.mmrbem.tcms.backend.logic.AbstractFunctionalLogic;
import com.sydac.mmrbem.tcms.backend.logic.SharedDataModel;
import com.sydac.mmrbem.tcms.backend.logic.annotation.FunctionalLogicHandler;
import com.sydac.mmrbem.tcms.backend.vehicle.io.handlers.ITCMSVehicleInputsRBCommandHandler;
import com.sydac.mmrbem.tcms.backend.vehicle.io.properties.ITCMSVehicleOutputsProperties;
import com.sydac.mmrbem.tcms.backend.vehicle.io.properties.IVehicleInputProperties;
import com.sydac.mmrbem.tcms.backend.vehicle.request.handler.CommonVehicleOutputsRequest;
import com.sydac.mmrbem.tcms.backend.vehicle.request.handler.VehicleStatusIntegerOutPutsRequestHandler;
import com.sydac.mmrbem.tcms.common.data.Entry;
import com.sydac.mmrbem.tcms.common.data.VehicleIntegerDataDO;
import com.sydac.mmrbem.tcms.common.io.properties.IAppInputsProperties;
import com.sydac.mmrbem.tcms.common.io.properties.IAppInputsRBCommandScreenProperties;
import com.sydac.mmrbem.tcms.common.io.properties.IAppOutputsRBScreenProperties;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.APSCIBStatusList.APSCIBState;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.FDUCBStatusList.FDUCBState;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.HVAC1StatusList.HVAC1State;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.HVAC2StatusList.HVAC2State;
import com.sydac.mmrbem.tcms.common.state.ApplicationConstants;

/**
 * This handler class is used for High Voltage System Command screen handling.
 * 
 */

@Service
@FunctionalLogicHandler(arguments = { CommsBinding.class, SharedDataModel.class })
public class RBCommandScreenHandler extends AbstractFunctionalLogic
{
  private ITCMSVehicleInputsRBCommandHandler tcmsVehicleInputsHandler;

  private Map<Integer, Integer> fdscbSelectedMap = new HashMap<>();

  private SharedDataModel sharedDataModel;

  private int fduOpen = 0;

  private int fduClose = 0;

  private int hvac1Open = 0;

  private int hvac1Close = 0;

  private int hvac2Open = 0;

  private int hvac2Close = 0;

  private int apsicbOpen = 0;

  private int apsicbClose = 0;

  private List<Entry<VehicleIntegerDataDO>> sac1ccbList = new CopyOnWriteArrayList<>();

  private List<Entry<VehicleIntegerDataDO>> sac2ccbList = new CopyOnWriteArrayList<>();

  private List<Entry<VehicleIntegerDataDO>> fducbStatusList = new CopyOnWriteArrayList<>();

  private List<Entry<VehicleIntegerDataDO>> apsicStatusList = new CopyOnWriteArrayList<>();

  private final Map<PropertyKey<Integer>, VehicleRBStatusIntegerOutPutsRequestHandler> requestHandlerMap = new HashMap<>();

  protected RBCommandScreenHandler(CommsBinding commsBinding, SharedDataModel aShareDataModel)
  {
    super(commsBinding, IAppInputsProperties.class, ITCMSVehicleOutputsProperties.class,
        IVehicleInputProperties.class);
    sharedDataModel = aShareDataModel;
    initHandlerMap();
    initalizeVehicleInputHandler();
  }

  private void resetInputCommands()
  {
    for (int carIndex = 0; carIndex < sharedDataModel.getTotalCar(); carIndex++)
    {
      tcmsVehicleInputsHandler = (ITCMSVehicleInputsRBCommandHandler)getTCMSVehicleInputsSetter(carIndex);
      tcmsVehicleInputsHandler.setTcmsFdscbOpen(ApplicationConstants.RESET_VALUE);
      tcmsVehicleInputsHandler.setTcmsFdscbClose(ApplicationConstants.RESET_VALUE);
      tcmsVehicleInputsHandler.setTcmsApsicbClose(ApplicationConstants.RESET_VALUE);
      tcmsVehicleInputsHandler.setTcmsApsicbOpen(ApplicationConstants.RESET_VALUE);

      tcmsVehicleInputsHandler.setTcmsHvac1Open(ApplicationConstants.RESET_VALUE);
      tcmsVehicleInputsHandler.setTcmsHvac2Open(ApplicationConstants.RESET_VALUE);

      tcmsVehicleInputsHandler.setTcmsHvac1Close(ApplicationConstants.RESET_VALUE);
      tcmsVehicleInputsHandler.setTcmsHvac2Close(ApplicationConstants.RESET_VALUE);
    }
  }

  private void initializeMap()
  {
    for (int i = 0; i < sharedDataModel.getTotalCar(); i++)
    {
      fdscbSelectedMap.put(i, 0);
    }
  }

  private void initHandlerMap()
  {
    requestHandlerMap.put(IVehicleInputProperties.SAC1CCB,
        new VehicleRBStatusIntegerOutPutsRequestHandler(this::updateSac1ccbStatusList, sac1ccbList));

    requestHandlerMap.put(IVehicleInputProperties.SAC2CCB,
        new VehicleRBStatusIntegerOutPutsRequestHandler(this::updateSac2ccbStatusList, sac2ccbList));

    requestHandlerMap.put(IVehicleInputProperties.APSICB,
        new VehicleRBStatusIntegerOutPutsRequestHandler(this::updateAPSICCBStatusList, apsicStatusList));

    requestHandlerMap.put(IVehicleInputProperties.FDSCB,
        new VehicleRBStatusIntegerOutPutsRequestHandler(this::updateFDUCBStatusList, fducbStatusList));

  }

  @Override
  public <T> void tcmsVehicleOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue,
      int vehicleIndex)
  {
    if (key.equals(ITCMSVehicleOutputsProperties.HMI_POWER) && Boolean.TRUE.equals(newValue))
    {
      initializeMap();
    }
    else if (ITCMSVehicleOutputsProperties.POWER_OFF_PRESSED.equals(key) && Boolean.TRUE.equals(newValue))
    {
      resetInputCommands();
    }
  }

  @Override
  public <T> void appInputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue, int vehicleIndex)
  {
    if (getActiveVehicleIndex() == vehicleIndex)
    {
      if (key.equals(IAppInputsRBCommandScreenProperties.RB_FDU_OPEN_REQ))
      {
        fduOpen = (Integer)newValue;
      }
      else if (key.equals(IAppInputsRBCommandScreenProperties.RB_FDU_OPEN_REQ_CAR) && (Integer)newValue > -1)
      {
        openFduReq((Integer)newValue, fduOpen);
      }
      else if (key.equals(IAppInputsRBCommandScreenProperties.RB_FDU_COSE_REQ))
      {
        fduClose = (Integer)newValue;
      }
      else if (key.equals(IAppInputsRBCommandScreenProperties.RB_FDU_CLOSE_REQ_CAR) && (Integer)newValue > -1)
      {
        closeFduReq((Integer)newValue, fduClose);
      }
      else if (key.equals(IAppInputsRBCommandScreenProperties.RB_HAVC1_OPEN_REQ))
      {
        hvac1Open = (Integer)newValue;

       
      }
      else if (key.equals(IAppInputsRBCommandScreenProperties.RB_HAVC1_OPEN_REQ_CAR)
          && (Integer)newValue > -1)
      {
        openHvac1Req((Integer)newValue, hvac1Open);
      }
      else if (key.equals(IAppInputsRBCommandScreenProperties.RB_HAVC2_OPEN_REQ))
      {
        hvac2Open = (Integer)newValue;
      }
      else if (key.equals(IAppInputsRBCommandScreenProperties.RB_HAVC2_OPEN_REQ_CAR)
          && (Integer)newValue > -1)
      {
        openHvac2Req((Integer)newValue,hvac2Open);
      }
      else if (key.equals(IAppInputsRBCommandScreenProperties.RB_APSIC_OPEN_REQ))
      {
        apsicbOpen = (Integer)newValue;
      }
      else if (key.equals(IAppInputsRBCommandScreenProperties.RB_APSIC_OPEN_REQ_CAR)
          && (Integer)newValue > -1)
      {
        openAPSICReq((Integer)newValue, apsicbOpen);
      }
      else if (key.equals(IAppInputsRBCommandScreenProperties.RB_APSIC_COSE_REQ))
      {
        apsicbClose = (Integer)newValue;
      }
      else if (key.equals(IAppInputsRBCommandScreenProperties.RB_APSIC_CLOSE_REQ_CAR)
          && (Integer)newValue > -1)
      {
        closeAPSICReq((Integer)newValue, apsicbClose);
      }
      else if (key.equals(IAppInputsRBCommandScreenProperties.RB_HVAC1_CLOSE_REQ))
      {
        hvac1Close = (Integer)newValue;
      }
      else if (key.equals(IAppInputsRBCommandScreenProperties.RB_HAVC1_CLOSE_REQ_CAR)
          && (Integer)newValue > -1)
      {
        closeHvac1Req((Integer)newValue, hvac1Close);
      }
      else if (key.equals(IAppInputsRBCommandScreenProperties.RB_HVAC2_CLOSE_REQ))
      {
        hvac2Close = (Integer)newValue;
      }
      else if (key.equals(IAppInputsRBCommandScreenProperties.RB_HAVC2_CLOSE_REQ_CAR)
          && (Integer)newValue > -1)
      {
        closeHvac2Req((Integer)newValue,hvac2Close);
      }
    }
  }

  private void openFduReq(int carIndex, int fduValue)
  {
    if (tcmsVehicleInputsHandler != null)
    {

      tcmsVehicleInputsHandler = (ITCMSVehicleInputsRBCommandHandler)getTCMSVehicleInputsSetter(carIndex);
      tcmsVehicleInputsHandler.setTcmsFdscbOpen(fduValue);
    }
  }

  private void closeFduReq(int carIndex, int fduValue)
  {
    if (tcmsVehicleInputsHandler != null)
    {

      tcmsVehicleInputsHandler = (ITCMSVehicleInputsRBCommandHandler)getTCMSVehicleInputsSetter(carIndex);
      tcmsVehicleInputsHandler.setTcmsFdscbClose(fduValue);
    }
  }

  private void openHvac1Req(int carIndex, int hvac1Value)
  {
    if (tcmsVehicleInputsHandler != null)
    {
     
      tcmsVehicleInputsHandler = (ITCMSVehicleInputsRBCommandHandler)getTCMSVehicleInputsSetter(carIndex);
      tcmsVehicleInputsHandler.setTcmsHvac1Open(hvac1Value);
    }
  }

  private void openHvac2Req(int carIndex, int havac2)
  {
    if (tcmsVehicleInputsHandler != null)
    {
      tcmsVehicleInputsHandler = (ITCMSVehicleInputsRBCommandHandler)getTCMSVehicleInputsSetter(carIndex);
      tcmsVehicleInputsHandler.setTcmsHvac2Open(havac2);
    }
  }

  private void openAPSICReq(int carIndex, int openVal)
  {
    if (tcmsVehicleInputsHandler != null)
    {
      tcmsVehicleInputsHandler = (ITCMSVehicleInputsRBCommandHandler)getTCMSVehicleInputsSetter(carIndex);
      tcmsVehicleInputsHandler.setTcmsApsicbOpen(openVal);
    }
  }

  private void closeAPSICReq(int carIndex, int closeVal)
  {
    if (tcmsVehicleInputsHandler != null)
    {
      tcmsVehicleInputsHandler = (ITCMSVehicleInputsRBCommandHandler)getTCMSVehicleInputsSetter(carIndex);
      tcmsVehicleInputsHandler.setTcmsApsicbClose(closeVal);
    }
  }

  private void closeHvac1Req(int carIndex, int closeVal)
  {
    if (tcmsVehicleInputsHandler != null)
    {
      tcmsVehicleInputsHandler = (ITCMSVehicleInputsRBCommandHandler)getTCMSVehicleInputsSetter(carIndex);
      tcmsVehicleInputsHandler.setTcmsHvac1Close(closeVal);
    }
  }

  private void closeHvac2Req(int carIndex, int closeHavc2Val)
  {
    if (tcmsVehicleInputsHandler != null)
    {
      tcmsVehicleInputsHandler = (ITCMSVehicleInputsRBCommandHandler)getTCMSVehicleInputsSetter(carIndex);
      tcmsVehicleInputsHandler.setTcmsHvac2Close(closeHavc2Val);
    }
  }

  private void initalizeVehicleInputHandler()
  {
    if (tcmsVehicleInputsHandler == null)
    {
      tcmsVehicleInputsHandler = (ITCMSVehicleInputsRBCommandHandler)getTCMSVehicleInputsSetter(
          getActiveVehicleIndex());
    }
  }

  @Override
  public <T> void vehicleInputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue, int vehicleIndex)
  {
    @SuppressWarnings("unchecked")
    PropertyKey<Integer> propertyKey = (PropertyKey<Integer>)key;

    VehicleRBStatusIntegerOutPutsRequestHandler handler = requestHandlerMap.get(key);
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

  @Override
  public void attachListeners()
  {
    super.attachListeners();

    initalizeVehicleInputHandler();
  }

  private void updateHvac1ValueList(List<Entry<VehicleIntegerDataDO>> parameterEntryList,
      Consumer<TCMSProto.HVAC1StatusList.Builder> consumer)
  {
    TCMSProto.HVAC1StatusList.Builder builder = TCMSProto.HVAC1StatusList.newBuilder();
    TCMSProto.HVAC1StatusList.HVAC1Status.Builder vehicleBuilder = TCMSProto.HVAC1StatusList.HVAC1Status
        .newBuilder();
    parameterEntryList.forEach(entry -> {
      int carIndex = entry.getIndex();
      vehicleBuilder.setCarIndex(carIndex);

      vehicleBuilder.setHavac1State(entry.getData().getValue() == 1 ? HVAC1State.OPEN : HVAC1State.CLOSED);
      
      if (entry.getData().getValue() == 1)
      {

        closeHvac1Req(carIndex, 0);
        openHvac1Req(carIndex, 0);
      }


      builder.addHvac1Status(vehicleBuilder.build());
    });
    consumer.accept(builder);
  }
  
  
  
  private void updateHvac2ValueList(List<Entry<VehicleIntegerDataDO>> parameterEntryList,
      Consumer<TCMSProto.HVAC2StatusList.Builder> consumer)
  {
    TCMSProto.HVAC2StatusList.Builder builder = TCMSProto.HVAC2StatusList.newBuilder();
    TCMSProto.HVAC2StatusList.HVAC2Status.Builder vehicleBuilder = TCMSProto.HVAC2StatusList.HVAC2Status
        .newBuilder();
    parameterEntryList.forEach(entry -> {
      int carIndex = entry.getIndex();
      vehicleBuilder.setCarIndex(carIndex);

      vehicleBuilder.setHavac2State(entry.getData().getValue() == 1 ? HVAC2State.OPEN : HVAC2State.CLOSED);
      
      if (entry.getData().getValue() == 1)
      {

        closeHvac2Req(carIndex, 0);
        openHvac2Req(carIndex, 0);
      }


      builder.addHvac2Status(vehicleBuilder.build());
    });
    consumer.accept(builder);
  }

  private void updateApscibValueList(List<Entry<VehicleIntegerDataDO>> parameterEntryList,
      Consumer<TCMSProto.APSCIBStatusList.Builder> consumer)
  {
    TCMSProto.APSCIBStatusList.Builder builder = TCMSProto.APSCIBStatusList.newBuilder();
    TCMSProto.APSCIBStatusList.APSCIBStatus.Builder vehicleBuilder = TCMSProto.APSCIBStatusList.APSCIBStatus
        .newBuilder();
    parameterEntryList.forEach(entry -> {
      int carIndex = entry.getIndex();
      vehicleBuilder.setCarIndex(carIndex);

      vehicleBuilder.setApscibState(entry.getData().getValue() == 1 ? APSCIBState.OPEN : APSCIBState.CLOSED);

      if (entry.getData().getValue() == 1)
      {

        closeAPSICReq(carIndex, 0);
        openAPSICReq(carIndex, 0);
      }

      builder.addApscibStatus(vehicleBuilder.build());
    });
    consumer.accept(builder);
  }

  private void updateFducbValueList(List<Entry<VehicleIntegerDataDO>> parameterEntryList,
      Consumer<TCMSProto.FDUCBStatusList.Builder> consumer)
  {
    TCMSProto.FDUCBStatusList.Builder builder = TCMSProto.FDUCBStatusList.newBuilder();
    TCMSProto.FDUCBStatusList.FDUCBStatus.Builder vehicleBuilder = TCMSProto.FDUCBStatusList.FDUCBStatus
        .newBuilder();
    parameterEntryList.forEach(entry -> {
      int carIndex = entry.getIndex();
      vehicleBuilder.setCarIndex(carIndex);

      vehicleBuilder.setFducbState(entry.getData().getValue() == 1 ? FDUCBState.OPEN : FDUCBState.CLOSED);

      if (entry.getData().getValue() == 1)
      {
        closeFduReq(carIndex, 0);
        openFduReq(carIndex, 0);
      }

      builder.addFducbStatus(vehicleBuilder.build());
    });
    consumer.accept(builder);
  }

  private void updateSac1ccbStatusList()
  {
    updateHvac1ValueList(sac1ccbList,
        builder -> setApplicationOutputsProperty(IAppOutputsRBScreenProperties.RB_HVAC1_STATUS,
            builder.build().toByteArray()));
  }

  private void updateSac2ccbStatusList()
  {
    updateHvac2ValueList(sac2ccbList,
        builder -> setApplicationOutputsProperty(IAppOutputsRBScreenProperties.RB_HVAC2_STATUS,
            builder.build().toByteArray()));
  }

  private void updateFDUCBStatusList()
  {
    updateFducbValueList(fducbStatusList,
        builder -> setApplicationOutputsProperty(IAppOutputsRBScreenProperties.RB_FDSCB_STATUS,
            builder.build().toByteArray()));
  }

  private void updateAPSICCBStatusList()
  {
    updateApscibValueList(apsicStatusList,
        builder -> setApplicationOutputsProperty(IAppOutputsRBScreenProperties.RB_APSICB_STATUS,
            builder.build().toByteArray()));
  }

  class VehicleRBStatusIntegerOutPutsRequestHandler extends VehicleStatusIntegerOutPutsRequestHandler
  {

    private VehicleRBStatusIntegerOutPutsRequestHandler(Runnable aRunnable,
        List<Entry<VehicleIntegerDataDO>> aList)
    {
      super(aRunnable, aList);
    }

  }
}
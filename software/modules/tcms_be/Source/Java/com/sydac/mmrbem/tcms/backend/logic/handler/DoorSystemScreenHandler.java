/*
 * ================================================================== (C)
 * Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * ==================================================================
 */
package com.sydac.mmrbem.tcms.backend.logic.handler;

import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.function.Consumer;
import java.util.function.Function;

import org.springframework.stereotype.Service;

import com.sydac.common.log.Tracer;
import com.sydac.foundation.PropertyKey;
import com.sydac.mmrbem.tcms.backend.comms.CommsBinding;
import com.sydac.mmrbem.tcms.backend.logic.AbstractFunctionalLogic;
import com.sydac.mmrbem.tcms.backend.logic.annotation.FunctionalLogicHandler;
import com.sydac.mmrbem.tcms.backend.vehicle.io.models.ITCMSVehicleOutputsDoorDcuModel;
import com.sydac.mmrbem.tcms.backend.vehicle.io.properties.ITCMSVehicleOutputsDoorSystemProperties;
import com.sydac.mmrbem.tcms.backend.vehicle.request.handler.ITCMSVehicleOutputsRequest;
import com.sydac.mmrbem.tcms.backend.vehicle.request.handler.ITCMSVehicleOutputsRequestHandler;
import com.sydac.mmrbem.tcms.common.data.Entry;
import com.sydac.mmrbem.tcms.common.io.properties.IAppOutputsDoorSystemScreenProperties;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.DCUStatusList.DCUState;

/**
 * This handler class handle the Door System status of vehicle and set to COMMS.
 */
@Service
@FunctionalLogicHandler(arguments = { CommsBinding.class })
public class DoorSystemScreenHandler extends AbstractFunctionalLogic
{
  DcuStatusUpdateRequestHandler dcu1StateHandler = new DcuStatusUpdateRequestHandler(this::getDcu1State,
      this::setAppOutputDcuStatus1);

  DcuStatusUpdateRequestHandler dcu2StateHandler = new DcuStatusUpdateRequestHandler(this::getDcu2State,
      this::setAppOutputDcuStatus2);

  DcuStatusUpdateRequestHandler dcu3StateHandler = new DcuStatusUpdateRequestHandler(this::getDcu3State,
      this::setAppOutputDcuStatus3);

  DcuStatusUpdateRequestHandler dcu4StateHandler = new DcuStatusUpdateRequestHandler(this::getDcu4State,
      this::setAppOutputDcuStatus4);

  DcuStatusUpdateRequestHandler dcu5StateHandler = new DcuStatusUpdateRequestHandler(this::getDcu5State,
      this::setAppOutputDcuStatus5);

  DcuStatusUpdateRequestHandler dcu6StateHandler = new DcuStatusUpdateRequestHandler(this::getDcu6State,
      this::setAppOutputDcuStatus6);

  DcuStatusUpdateRequestHandler dcu7StateHandler = new DcuStatusUpdateRequestHandler(this::getDcu7State,
      this::setAppOutputDcuStatus7);

  DcuStatusUpdateRequestHandler dcu8StateHandler = new DcuStatusUpdateRequestHandler(this::getDcu8State,
      this::setAppOutputDcuStatus8);

  /**
   * This map holds request handles for DCU Status related parameters.
   */
  private final Map<PropertyKey<? extends Number>, DcuStatusUpdateRequestHandler> handlerMap = new HashMap<>();

  public DoorSystemScreenHandler(CommsBinding commsBinding)
  {
    super(commsBinding, ITCMSVehicleOutputsDoorSystemProperties.class);
    initializeMap();
  }

  private void initializeMap()
  {
    // DCU x Status
    handlerMap.put(ITCMSVehicleOutputsDoorSystemProperties.DCU_1_STATUS, dcu1StateHandler);
    handlerMap.put(ITCMSVehicleOutputsDoorSystemProperties.DCU_2_STATUS, dcu2StateHandler);
    handlerMap.put(ITCMSVehicleOutputsDoorSystemProperties.DCU_3_STATUS, dcu3StateHandler);
    handlerMap.put(ITCMSVehicleOutputsDoorSystemProperties.DCU_4_STATUS, dcu4StateHandler);
    handlerMap.put(ITCMSVehicleOutputsDoorSystemProperties.DCU_5_STATUS, dcu5StateHandler);
    handlerMap.put(ITCMSVehicleOutputsDoorSystemProperties.DCU_6_STATUS, dcu6StateHandler);
    handlerMap.put(ITCMSVehicleOutputsDoorSystemProperties.DCU_7_STATUS, dcu7StateHandler);
    handlerMap.put(ITCMSVehicleOutputsDoorSystemProperties.DCU_8_STATUS, dcu8StateHandler);
    // DCU x Fault
    handlerMap.put(ITCMSVehicleOutputsDoorSystemProperties.DCU_1_FAULT, dcu1StateHandler);
    handlerMap.put(ITCMSVehicleOutputsDoorSystemProperties.DCU_2_FAULT, dcu2StateHandler);
    handlerMap.put(ITCMSVehicleOutputsDoorSystemProperties.DCU_3_FAULT, dcu3StateHandler);
    handlerMap.put(ITCMSVehicleOutputsDoorSystemProperties.DCU_4_FAULT, dcu4StateHandler);
    handlerMap.put(ITCMSVehicleOutputsDoorSystemProperties.DCU_5_FAULT, dcu5StateHandler);
    handlerMap.put(ITCMSVehicleOutputsDoorSystemProperties.DCU_6_FAULT, dcu6StateHandler);
    handlerMap.put(ITCMSVehicleOutputsDoorSystemProperties.DCU_7_FAULT, dcu7StateHandler);
    handlerMap.put(ITCMSVehicleOutputsDoorSystemProperties.DCU_8_FAULT, dcu8StateHandler);
  }

  class DcuStatusUpdateRequestHandler implements ITCMSVehicleOutputsRequestHandler<DcuStatusRequest>
  {
    private final List<Entry<DCUState>> dcuStatusList = new ArrayList<>();

    private final Function<ITCMSVehicleOutputsDoorDcuModel, DCUState> dcuModelFunction;

    private final Consumer<TCMSProto.DCUStatusList.Builder> applicationConsumer;

    DcuStatusUpdateRequestHandler(
        Function<ITCMSVehicleOutputsDoorDcuModel, DCUState> dcuStatusSupplierFunction,
        Consumer<TCMSProto.DCUStatusList.Builder> consumer)
    {
      dcuModelFunction = dcuStatusSupplierFunction;
      applicationConsumer = consumer;
    }

    @Override
    public void handleRequest(DcuStatusRequest request)
    {
      ITCMSVehicleOutputsDoorDcuModel model = (ITCMSVehicleOutputsDoorDcuModel)getTCMSVehicleOutputsModels()
          .get(request.getCarIndex());
      DCUState state = dcuModelFunction.apply(model);
      setDcuStatus(dcuStatusList, state, request.getCarIndex());
      applicationConsumer.accept(getVehicleDoorDcuStatusBuilder());
    }

    private void setDcuStatus(List<Entry<DCUState>> dcuState, DCUState state, int index)
    {
      synchronized (dcuStatusList)
      {
        if (dcuState.stream().anyMatch(entry -> entry.getIndex() == index))
        {
          dcuState.stream().filter(entry -> entry.getIndex() == index).forEach(entry -> entry.setData(state));
        }
        else
        {
          dcuState.add(new Entry<>(index, state));
          Collections.sort(dcuState);
        }
      }
    }

    private TCMSProto.DCUStatusList.Builder getVehicleDoorDcuStatusBuilder()
    {
      TCMSProto.DCUStatusList.Builder builder = TCMSProto.DCUStatusList.newBuilder();
      synchronized (dcuStatusList)
      {
        for (Entry<DCUState> entry : dcuStatusList)
        {
          TCMSProto.DCUStatusList.DCUStatus.Builder doorBuilder = TCMSProto.DCUStatusList.DCUStatus
              .newBuilder();
          doorBuilder.setCarIndex(entry.getIndex());
          doorBuilder.setDcuState(entry.getData());
          builder.addDcuStatus(doorBuilder.build());
        }
      }
      return builder;
    }
  }

  private void setAppOutputDcuStatus1(TCMSProto.DCUStatusList.Builder builder)
  {
    setApplicationOutputsProperty(IAppOutputsDoorSystemScreenProperties.DCU_STATUS_1,
        builder.build().toByteArray());
  }
  
  private void setAppOutputDcuStatus2(TCMSProto.DCUStatusList.Builder builder)
  {
    setApplicationOutputsProperty(IAppOutputsDoorSystemScreenProperties.DCU_STATUS_2,
        builder.build().toByteArray());
  }
  
  private void setAppOutputDcuStatus3(TCMSProto.DCUStatusList.Builder builder)
  {
    setApplicationOutputsProperty(IAppOutputsDoorSystemScreenProperties.DCU_STATUS_3,
        builder.build().toByteArray());
  }
  
  private void setAppOutputDcuStatus4(TCMSProto.DCUStatusList.Builder builder)
  {
    setApplicationOutputsProperty(IAppOutputsDoorSystemScreenProperties.DCU_STATUS_4,
        builder.build().toByteArray());
  }
  
  private void setAppOutputDcuStatus5(TCMSProto.DCUStatusList.Builder builder)
  {
    setApplicationOutputsProperty(IAppOutputsDoorSystemScreenProperties.DCU_STATUS_5,
        builder.build().toByteArray());
  }
  
  private void setAppOutputDcuStatus6(TCMSProto.DCUStatusList.Builder builder)
  {
    setApplicationOutputsProperty(IAppOutputsDoorSystemScreenProperties.DCU_STATUS_6,
        builder.build().toByteArray());
  }
  
  private void setAppOutputDcuStatus7(TCMSProto.DCUStatusList.Builder builder)
  {
    setApplicationOutputsProperty(IAppOutputsDoorSystemScreenProperties.DCU_STATUS_7,
        builder.build().toByteArray());
  }
  
  private void setAppOutputDcuStatus8(TCMSProto.DCUStatusList.Builder builder)
  {
    setApplicationOutputsProperty(IAppOutputsDoorSystemScreenProperties.DCU_STATUS_8,
        builder.build().toByteArray());
  }

  public DCUState getDcu1State(ITCMSVehicleOutputsDoorDcuModel model)
  {
    return getDcuState(model.getDcu1Status(), model.getDcu1Fault());
  }
  
  public DCUState getDcu2State(ITCMSVehicleOutputsDoorDcuModel model)
  {
    return getDcuState(model.getDcu2Status(), model.getDcu2Fault());
  }
  
  public DCUState getDcu3State(ITCMSVehicleOutputsDoorDcuModel model)
  {
    return getDcuState(model.getDcu3Status(), model.getDcu3Fault());
  }
  
  public DCUState getDcu4State(ITCMSVehicleOutputsDoorDcuModel model)
  {
    return getDcuState(model.getDcu4Status(), model.getDcu4Fault());
  }
  
  public DCUState getDcu5State(ITCMSVehicleOutputsDoorDcuModel model)
  {
    return getDcuState(model.getDcu5Status(), model.getDcu5Fault());
  }
  
  public DCUState getDcu6State(ITCMSVehicleOutputsDoorDcuModel model)
  {
    return getDcuState(model.getDcu6Status(), model.getDcu6Fault());
  }
  
  public DCUState getDcu7State(ITCMSVehicleOutputsDoorDcuModel model)
  {
    return getDcuState(model.getDcu7Status(), model.getDcu7Fault());
  }
  
  public DCUState getDcu8State(ITCMSVehicleOutputsDoorDcuModel model)
  {
    return getDcuState(model.getDcu8Status(), model.getDcu8Fault());
  }

  private DCUState getDcuState(int dcuStatus, int dcuFault)
  {
    DCUState dcuState;
    if (dcuFault == 1)
    {
      dcuState = DCUState.DCU_FAULTY;
    }
    else if (dcuStatus == 1)
    {
      dcuState = DCUState.DCU_OK;
    }
    else
    {
      dcuState = DCUState.DCU_NOT_AVAILABLE;
    }
    return dcuState;
  }

  @Override
  public <T> void tcmsVehicleOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue,
      int vehicleIndex)
  {
    DcuStatusUpdateRequestHandler handler = handlerMap.get(key);
    if (handler != null)
    {
      handler.handleRequest(new DcuStatusRequest(vehicleIndex));
    }
    else
    {
      Tracer.getInstance()
          .debug(String.format("Cannot update, request Handler for key %S is not found", key.toString())); //$NON-NLS-1$
    }
  }

  class DcuStatusRequest implements ITCMSVehicleOutputsRequest<Integer>
  {
    private final int carIndex;

    DcuStatusRequest(int aCarIndex)
    {
      carIndex = aCarIndex;
    }

    @Override
    public PropertyKey<Integer> getPropertyKey()
    {
      throw new UnsupportedOperationException();
    }

    @Override
    public Integer getOldValue()
    {
      throw new UnsupportedOperationException();
    }

    @Override
    public Integer getNewValue()
    {
      throw new UnsupportedOperationException();
    }

    @Override
    public int getCarIndex()
    {
      return carIndex;
    }
  }
}

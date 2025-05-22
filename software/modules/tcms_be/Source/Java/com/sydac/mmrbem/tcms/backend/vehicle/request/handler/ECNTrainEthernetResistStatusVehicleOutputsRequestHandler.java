/*
 * ==================================================================
 * 
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.tcms.backend.vehicle.request.handler;

import java.util.ArrayList;
import java.util.List;
import java.util.function.Consumer;

import com.sydac.common.log.Tracer;
import com.sydac.foundation.PropertyKey;
import com.sydac.mmrbem.tcms.backend.app.io.handlers.IAppOutputsECNScreenHandler;
import com.sydac.mmrbem.tcms.backend.vehicle.io.properties.ITCMSVehicleOutputsECNScreenProperties;
import com.sydac.mmrbem.tcms.backend.vehicle.io.properties.ITCMSVehicleOutputsProperties;
import com.sydac.mmrbem.tcms.common.data.Entry;
import com.sydac.mmrbem.tcms.common.data.VehicleDetailModel;
import com.sydac.mmrbem.tcms.common.data.VehicleTrainEthernetResistStatusDO;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.TrainEthernetRepeaterStatusList.TrainEthernetRepeaterState;
import com.sydac.mmrbem.tcms.common.state.TCMSConstants;

/**
 * This class handles ECN Train Ethernet Resist (TER) Status update from vehicle
 * outputs
 * 
 */
public class ECNTrainEthernetResistStatusVehicleOutputsRequestHandler implements
    ITCMSVehicleOutputsRequestHandler<TCMSOutputsECNScreenImpl<Integer, IAppOutputsECNScreenHandler>>
{

  protected final List<Entry<VehicleTrainEthernetResistStatusDO>> trainEthernetResistStatus = new ArrayList<>();

  @Override
  public void handleRequest(TCMSOutputsECNScreenImpl<Integer, IAppOutputsECNScreenHandler> request)
  {
    try
    {
      VehicleTrainEthernetResistStatusDO vehicleTrainEthernetResistStatusDO = ITCMSVehicleOutputsRequestHandler
          .getVehicleStatusDo(trainEthernetResistStatus, request.getCarIndex(),
              VehicleTrainEthernetResistStatusDO.class);
      setStatus(request.getPropertyKey(), request.getNewValue(), vehicleTrainEthernetResistStatusDO);
      ITCMSVehicleOutputsRequestHandler.updateVehicleStatusDOList(trainEthernetResistStatus,
          vehicleTrainEthernetResistStatusDO, request.getCarIndex());
      setComponentSwitchStatus(trainEthernetResistStatus, request.getVehicleDetailModelList(),
          builder -> request.getHandler().setEcnTerStatusList(builder.build().toByteArray()));
    }
    catch (InstantiationException e)
    {
      Tracer.getInstance().info(e);
    }
  }

  private void setStatus(PropertyKey<Integer> propertyKey, Integer newvalue,
      VehicleTrainEthernetResistStatusDO vehicleTrainEthernetResistStatusDO)
  {
    if (propertyKey.equals(ITCMSVehicleOutputsProperties.DUMMY_FAULT_SIGNAL))
    {
      vehicleTrainEthernetResistStatusDO.setTrainEthernetResistFault(newvalue);
    }
    else if (propertyKey.equals(ITCMSVehicleOutputsECNScreenProperties.TRAIN_ETHERNET_REPEATER_STATUS))
    {
      vehicleTrainEthernetResistStatusDO.setTrainEthernetResistStatus(newvalue);
    }
  }

  private void setComponentSwitchStatus(List<Entry<VehicleTrainEthernetResistStatusDO>> componentSwitchStatus,
      List<VehicleDetailModel> vehicleDetailModelList,
      Consumer<TCMSProto.TrainEthernetRepeaterStatusList.Builder> builderConsumer)
  {
    TCMSProto.TrainEthernetRepeaterStatusList.Builder builder = TCMSProto.TrainEthernetRepeaterStatusList
        .newBuilder();
    TCMSProto.TrainEthernetRepeaterStatusList.TrainEthernetRepeaterStatus.Builder vehicleBuilder = TCMSProto.TrainEthernetRepeaterStatusList.TrainEthernetRepeaterStatus
        .newBuilder();

    VehicleTrainEthernetResistStatusDO data;
    for (int index = 0; index < componentSwitchStatus.size(); index++)
    {
      int carIndex = componentSwitchStatus.get(index).getIndex();
      TrainEthernetRepeaterState trainEthernetRepeaterState = TrainEthernetRepeaterState.TER_NOT_AVAILABLE;
      if (vehicleDetailModelList != null && vehicleDetailModelList.size() > carIndex)
      {
        data = componentSwitchStatus.get(index).getData();
        trainEthernetRepeaterState = getTrainEthernetResistState(data);
      }
      vehicleBuilder.setCarIndex(componentSwitchStatus.get(index).getIndex());
      vehicleBuilder.setTrainEthernetRepeaterState(trainEthernetRepeaterState);
      builder.addTrainEthernetRepeaterStatus(vehicleBuilder.build());
    }
    builderConsumer.accept(builder);
  }

  private TrainEthernetRepeaterState getTrainEthernetResistState(VehicleTrainEthernetResistStatusDO data)
  {
    TrainEthernetRepeaterState trainEthernetRepeaterState;
    if (data.getTrainEthernetResistFault() == TCMSConstants.ECN_COMPONENT_FAULTY)
    {
      trainEthernetRepeaterState = TrainEthernetRepeaterState.TER_FAULTY;
    }
    else if (data.getTrainEthernetResistStatus() == TCMSConstants.ECN_COMPONENT_OK)
    {
      trainEthernetRepeaterState = TrainEthernetRepeaterState.TER_OK;
    }
    else
    {
      trainEthernetRepeaterState = TrainEthernetRepeaterState.TER_NOT_AVAILABLE;
    }
    return trainEthernetRepeaterState;
  }
}

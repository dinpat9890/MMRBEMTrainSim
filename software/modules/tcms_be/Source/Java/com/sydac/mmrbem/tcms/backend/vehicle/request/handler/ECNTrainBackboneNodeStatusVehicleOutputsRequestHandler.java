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
import com.sydac.mmrbem.tcms.common.data.VehicleTrainBackboneNodeStatusDO;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.TrainBackboneNodeStatusList.TrainBackboneNodeState;
import com.sydac.mmrbem.tcms.common.state.TCMSConstants;

/**
 * This class handles ECN Train Backbone Node (TBN) Status update from vehicle
 * outputs
 * 
 */
public class ECNTrainBackboneNodeStatusVehicleOutputsRequestHandler implements
    ITCMSVehicleOutputsRequestHandler<TCMSOutputsECNScreenImpl<Integer, IAppOutputsECNScreenHandler>>
{

  protected final List<Entry<VehicleTrainBackboneNodeStatusDO>> trainBackboneNodeStatus = new ArrayList<>();

  @Override
  public void handleRequest(TCMSOutputsECNScreenImpl<Integer, IAppOutputsECNScreenHandler> request)
  {
    try
    {
      VehicleTrainBackboneNodeStatusDO vehicleTrainBackboneNodeStatusDO = ITCMSVehicleOutputsRequestHandler
          .getVehicleStatusDo(trainBackboneNodeStatus, request.getCarIndex(),
              VehicleTrainBackboneNodeStatusDO.class);
      setStatus(request.getPropertyKey(), request.getNewValue(), vehicleTrainBackboneNodeStatusDO);
      ITCMSVehicleOutputsRequestHandler.updateVehicleStatusDOList(trainBackboneNodeStatus,
          vehicleTrainBackboneNodeStatusDO, request.getCarIndex());
      setComponentSwitchStatus(trainBackboneNodeStatus, request.getVehicleDetailModelList(),
          builder -> request.getHandler().setEcnTbnStatusList(builder.build().toByteArray()));
    }
    catch (InstantiationException e)
    {
      Tracer.getInstance().info(e);
    }
  }

  private void setStatus(PropertyKey<Integer> propertyKey, Integer newvalue,
      VehicleTrainBackboneNodeStatusDO vehicleTrainBackboneNodeStatusDO)
  {
    if (propertyKey.equals(ITCMSVehicleOutputsProperties.DUMMY_FAULT_SIGNAL))
    {
      vehicleTrainBackboneNodeStatusDO.setTrainBackboneFaultStatus(newvalue);
    }
    else if (propertyKey.equals(ITCMSVehicleOutputsECNScreenProperties.TRAIN_BACKBONE_NODE_STATUS))
    {
      vehicleTrainBackboneNodeStatusDO.setTrainBackboneNodeStatus(newvalue);
    }
  }

  private void setComponentSwitchStatus(List<Entry<VehicleTrainBackboneNodeStatusDO>> componentSwitchStatus,
      List<VehicleDetailModel> vehicleDetailModelList,
      Consumer<TCMSProto.TrainBackboneNodeStatusList.Builder> builderConsumer)
  {
    TCMSProto.TrainBackboneNodeStatusList.Builder builder = TCMSProto.TrainBackboneNodeStatusList
        .newBuilder();
    TCMSProto.TrainBackboneNodeStatusList.TrainBackboneNodeStatus.Builder vehicleBuilder = TCMSProto.TrainBackboneNodeStatusList.TrainBackboneNodeStatus
        .newBuilder();

    VehicleTrainBackboneNodeStatusDO data;
    for (int index = 0; index < componentSwitchStatus.size(); index++)
    {
      int carIndex = componentSwitchStatus.get(index).getIndex();
      TrainBackboneNodeState trainBackboneNodeState = TrainBackboneNodeState.TBN_NOT_AVAILABLE;
      if (vehicleDetailModelList != null && vehicleDetailModelList.size() > carIndex)
      {
        data = componentSwitchStatus.get(index).getData();
        trainBackboneNodeState = getTrainBackboneNodeState(data);
      }
      vehicleBuilder.setCarIndex(componentSwitchStatus.get(index).getIndex());
      vehicleBuilder.setTrainBackboneNodeState(trainBackboneNodeState);
      builder.addTrainBackboneNodeStatus(vehicleBuilder.build());
    }
    builderConsumer.accept(builder);
  }

  private TrainBackboneNodeState getTrainBackboneNodeState(VehicleTrainBackboneNodeStatusDO data)
  {
    TrainBackboneNodeState trainBackboneNodeState;
    if (data.getTrainBackboneFaultStatus() == TCMSConstants.ECN_COMPONENT_FAULTY)
    {
      trainBackboneNodeState = TrainBackboneNodeState.TBN_FAULTY;
    }
    else if (data.getTrainBackboneNodeStatus() == TCMSConstants.ECN_COMPONENT_OK)
    {
      trainBackboneNodeState = TrainBackboneNodeState.TBN_OK;
    }
    else
    {
      trainBackboneNodeState = TrainBackboneNodeState.TBN_NOT_AVAILABLE;
    }
    return trainBackboneNodeState;
  }
}

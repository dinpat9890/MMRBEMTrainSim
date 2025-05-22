/*
 * ================================================================== (C)
 * Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * ==================================================================
 */

package com.sydac.mmrbem.tcms.backend.vehicle.request.handler;

import java.util.Collections;
import java.util.List;

import com.sydac.mmrbem.tcms.common.data.Entry;
import com.sydac.mmrbem.tcms.common.data.VehicleIntegerDataDO;

/**
 * This class handles Vehicle Condition status parameters related update
 * requests from vehicle outputs. Instance of subclass is meant to be work on
 * only single state. Make sure the instance of sub class shall not escape the
 * scope of handler class in which it is instantiated.
 * 
 * @author walbeg
 */
public abstract class VehicleStatusIntegerOutPutsRequestHandler
    implements ITCMSVehicleOutputsRequestHandler<CommonVehicleOutputsRequest<Integer>>
{
  /**
   * {@link Runnable} is the only function interface provided by java lang with
   * no method argument and void return type. Here this interface is used to
   * abstract out each parameter separately.
   */
  private final Runnable runnable;

  private final List<Entry<VehicleIntegerDataDO>> parameterDataList;

  protected VehicleStatusIntegerOutPutsRequestHandler(Runnable aRunnable,
      List<Entry<VehicleIntegerDataDO>> aList)
  {
    runnable = aRunnable;
    parameterDataList = aList;
  }

  @Override
  public void handleRequest(CommonVehicleOutputsRequest<Integer> command)
  {
    updateVehicleStatusDetails(parameterDataList, command.getNewValue(), command.getCarIndex());
    runnable.run();
  }

  /**
   * Checks and updates the latest data status details in given list.
   * 
   * @param Data
   *          List List of {@link VehicleIntegerDataDO} to update vehicle status
   *          data
   * @param vehicleConditionStatus
   *          data to update
   * @param carIndex
   *          the car index where data need to update
   */
  private void updateVehicleStatusDetails(List<Entry<VehicleIntegerDataDO>> dataList, int newValue,
      int carIndex)
  {
    synchronized (dataList)
    {
      if (dataList.stream().anyMatch(entry -> entry.getIndex() == carIndex))
      {
        dataList.stream().filter(entry -> entry.getIndex() == carIndex)
            .forEach(entry -> entry.getData().setValue(newValue));
      }
      else
      {
        VehicleIntegerDataDO singleValueDo = new VehicleIntegerDataDO(carIndex, newValue);
        dataList.add(new Entry<>(carIndex, singleValueDo));
        Collections.sort(dataList);
      }
    }

  }

}

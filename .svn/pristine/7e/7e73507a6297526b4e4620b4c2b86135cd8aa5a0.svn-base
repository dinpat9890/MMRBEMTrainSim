/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.tcms.fe.gui.model;

import com.google.protobuf.InvalidProtocolBufferException;
import com.sydac.common.log.Tracer;
import com.sydac.mmrbem.cabscreens.fe.gui.model.AbstractScreenModel;
import com.sydac.mmrbem.tcms.common.data.SpeedLimitStatusDO;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.SpeedLimitData;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.SpeedLimitData.SpeedLimitDataStatus;

import javafx.beans.property.ListProperty;
import javafx.beans.property.SimpleListProperty;
import javafx.collections.FXCollections;

public class SpeedLimitInterlockScreenModel extends AbstractScreenModel
{

  private ListProperty<SpeedLimitStatusDO> speedLimitDoList = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  private SpeedLimitData speedLimitData;

  public SpeedLimitInterlockScreenModel(int carIndex)
  {
    super(carIndex);
  }

  public void setSpeedLimitStatus(byte[] newValue)
  {
    if (newValue.length != 0)
    {
      try
      {
        speedLimitData = TCMSProto.SpeedLimitData.parseFrom(newValue);
        updateSpeedLimitList();
      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
    }
  }

  private void updateSpeedLimitList()
  {
    if (speedLimitData != null)
    {
      speedLimitDoList.clear();
      for (SpeedLimitDataStatus status : speedLimitData.getSpeedLimitDataStatusList())
      {
        speedLimitDoList.add(new SpeedLimitStatusDO(status.getSpeedLimitState(), status.getLimitId()));
      }
    }
  }

  public ListProperty<SpeedLimitStatusDO> getSpeedLimitDoList()
  {
    return speedLimitDoList;
  }

}

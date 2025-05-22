/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.papis.fe.gui.model;

import java.util.HashMap;
import java.util.Map;

import com.google.protobuf.InvalidProtocolBufferException;
import com.sydac.common.log.Tracer;
import com.sydac.mmrbem.cabscreens.fe.gui.model.AbstractScreenModel;
import com.sydac.mmrbem.papis.common.data.StationDetailModel;
import com.sydac.mmrbem.papis.common.protos.PAPISProtos;
import com.sydac.mmrbem.papis.common.protos.PAPISProtos.StationList;
import com.sydac.mmrbem.papis.common.protos.PAPISProtos.StationList.StationDetail;

import javafx.beans.property.IntegerProperty;
import javafx.beans.property.ListProperty;
import javafx.beans.property.SimpleIntegerProperty;
import javafx.beans.property.SimpleListProperty;
import javafx.collections.FXCollections;

public class ManualModeSettingScreenModel extends AbstractScreenModel
{

  private ListProperty<StationDetailModel> stationDetailList = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  private Map<Integer, String> allStationDetailMap = new HashMap<>();

  private IntegerProperty lastStationId = new SimpleIntegerProperty();

  private StationList stationList;

  private StationList allStationList;

  public ManualModeSettingScreenModel(int carIndex)
  {
    super(carIndex);

  }

  public StationList getStationList()
  {
    return stationList;
  }

  public void setStationList(byte[] stationList)
  {
    if (stationList.length != 0)
    {
      try
      {
        this.stationList = PAPISProtos.StationList.parseFrom(stationList);

        updateStationList();
      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
    }
    else
    {
      stationDetailList.clear();
    }
  }

  public ListProperty<StationDetailModel> getStationDetailList()
  {
    return stationDetailList;
  }

  private void updateStationList()
  {
    if (stationList != null)
    {
      stationDetailList.clear();
      for (StationDetail stationDetail : this.stationList.getStationDetailList())
      {
        stationDetailList.add(new StationDetailModel(stationDetail.getStationId(),
            stationDetail.getStationCode(), stationDetail.getStationName()));
      }
    }
  }

  public void setAllStationList(byte[] stationList)
  {
    if (stationList.length != 0)
    {
      try
      {
        this.allStationList = PAPISProtos.StationList.parseFrom(stationList);
      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
    }
    else
    {
      allStationDetailMap.clear();
    }
  }

  public String getStationName(int id)
  {
    allStationDetailMap.clear();

    allStationList.getStationDetailList()
        .forEach(t -> allStationDetailMap.put(t.getStationId(), t.getStationName()));

    return allStationDetailMap.get(id) != null ? allStationDetailMap.get(id) : " "; //$NON-NLS-1$
  }

  public void setLastStationId(Integer stationId)
  {
    this.lastStationId.set(stationId);
  }

  public IntegerProperty getLastStationId()
  {
    return lastStationId;
  }

}

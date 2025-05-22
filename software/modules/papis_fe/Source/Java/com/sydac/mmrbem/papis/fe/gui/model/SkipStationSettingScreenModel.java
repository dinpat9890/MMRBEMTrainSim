/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.papis.fe.gui.model;

import com.google.protobuf.InvalidProtocolBufferException;
import com.sydac.common.log.Tracer;
import com.sydac.mmrbem.cabscreens.fe.gui.model.AbstractScreenModel;
import com.sydac.mmrbem.papis.common.data.StationDetailModel;
import com.sydac.mmrbem.papis.common.protos.PAPISProtos;
import com.sydac.mmrbem.papis.common.protos.PAPISProtos.StationList;
import com.sydac.mmrbem.papis.common.protos.PAPISProtos.StationList.StationDetail;

import javafx.beans.property.ListProperty;
import javafx.beans.property.SimpleListProperty;
import javafx.collections.FXCollections;

public class SkipStationSettingScreenModel extends AbstractScreenModel
{

  private ListProperty<StationDetailModel> stationDetailList = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  private ListProperty<StationDetailModel> skipStationDetailList = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  private StationList stationList;

  private StationList skipStationList;

  public SkipStationSettingScreenModel(int carIndex)
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

  public void setSkipStationList(byte[] skipStationList)
  {
    if (skipStationList.length != 0)
    {
      try
      {
        this.skipStationList = PAPISProtos.StationList.parseFrom(skipStationList);

        updateSkipStationList();
      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
    }
    else
    {
      skipStationDetailList.clear();
    }
  }

  public ListProperty<StationDetailModel> getStationDetailList()
  {
    return stationDetailList;
  }

  public ListProperty<StationDetailModel> getSkipStationDetailList()
  {
    return skipStationDetailList;
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

  private void updateSkipStationList()
  {
    skipStationDetailList.clear();
    if (skipStationList != null)
    {
      for (StationDetail skipStationDetail : this.skipStationList.getStationDetailList())
      {
        skipStationDetailList.add(new StationDetailModel(skipStationDetail.getStationId(),
            skipStationDetail.getStationCode(), skipStationDetail.getStationName()));
      }
    }
  }

}

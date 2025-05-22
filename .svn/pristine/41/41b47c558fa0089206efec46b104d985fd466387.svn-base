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

import javafx.beans.property.IntegerProperty;
import javafx.beans.property.ListProperty;
import javafx.beans.property.SimpleIntegerProperty;
import javafx.beans.property.SimpleListProperty;
import javafx.beans.property.SimpleStringProperty;
import javafx.beans.property.StringProperty;
import javafx.collections.FXCollections;

public class NextStationSelectionScreenModel extends AbstractScreenModel
{

  private StringProperty nextStationNameProperty = new SimpleStringProperty();

  private ListProperty<StationDetailModel> stationDetailList = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  private StationList stationList;

  private IntegerProperty nextStationSelected = new SimpleIntegerProperty();

  public NextStationSelectionScreenModel(int carIndex)
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

  public StringProperty getNextStationNameProperty()
  {
    return nextStationNameProperty;
  }

  public void setNextStationNameProperty(byte[] nextStationNameProperty)
  {
    this.nextStationNameProperty.set(new String(nextStationNameProperty));
  }

  public void setNextStationSelected(Integer newValue)
  {
    nextStationSelected.set(newValue);
  }

  public IntegerProperty getNextStationSelected()
  {
    return nextStationSelected;
  }

}

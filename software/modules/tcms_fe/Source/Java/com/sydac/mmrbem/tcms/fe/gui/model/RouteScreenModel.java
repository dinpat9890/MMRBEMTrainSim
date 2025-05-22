/*
 * ==================================================================
 * 
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.tcms.fe.gui.model;

import java.util.HashMap;
import java.util.Map;

import com.google.protobuf.InvalidProtocolBufferException;
import com.sydac.common.log.Tracer;
import com.sydac.mmrbem.cabscreens.fe.gui.model.AbstractScreenModel;

import com.sydac.mmrbem.tcms.common.data.StationDetailModel;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.StationList;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.StationList.StationDetail;
import com.sydac.mmrbem.tcms.common.state.TCMSConstants;

import javafx.beans.property.BooleanProperty;
import javafx.beans.property.IntegerProperty;
import javafx.beans.property.ListProperty;
import javafx.beans.property.SimpleBooleanProperty;
import javafx.beans.property.SimpleIntegerProperty;
import javafx.beans.property.SimpleListProperty;
import javafx.beans.property.SimpleStringProperty;
import javafx.beans.property.StringProperty;
import javafx.collections.FXCollections;

public class RouteScreenModel extends AbstractScreenModel
{

  private IntegerProperty papisSelectedMode = new SimpleIntegerProperty();

  private StringProperty startStation = new SimpleStringProperty(TCMSConstants.NO_STATION_SELECTED);

  private StringProperty destinationStation = new SimpleStringProperty(TCMSConstants.NO_STATION_SELECTED);

  private StringProperty trainId = new SimpleStringProperty(TCMSConstants.NO_TRAIN_ID_SELECTED);

  private StringProperty semiAutoTrainId = new SimpleStringProperty(TCMSConstants.NO_TRAIN_ID_SELECTED);

  private ListProperty<StationDetailModel> stationDetailList = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  private ListProperty<StationDetailModel> line2StationDetailList = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  private ListProperty<StationDetailModel> line7StationDetailList = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  private BooleanProperty stationListChanged = new SimpleBooleanProperty();

  private BooleanProperty line7StationListChanged = new SimpleBooleanProperty();

  private BooleanProperty line2StationListChanged = new SimpleBooleanProperty();

  private StringProperty selectedStationName = new SimpleStringProperty();

  private StationList stationList;

  private IntegerProperty trainEvacState = new SimpleIntegerProperty();

  private IntegerProperty outOfServiceState = new SimpleIntegerProperty();

  private IntegerProperty trainDelayState = new SimpleIntegerProperty();

  private IntegerProperty trainHoldState = new SimpleIntegerProperty();

  private IntegerProperty serviceState = new SimpleIntegerProperty();

  public RouteScreenModel(int carIndex)
  {
    super(carIndex);
  }

  public IntegerProperty getPapisSelectedMode()
  {
    return papisSelectedMode;
  }

  public void setPapisSelectedMode(Integer papisSelectedMode)
  {
    this.papisSelectedMode.set(papisSelectedMode);
  }

  public StringProperty getStartStation()
  {
    return startStation;
  }

  public void setStartStation(byte[] startStation)
  {
    this.startStation.set(new String(startStation));
  }

  public StringProperty getDestinationStation()
  {
    return destinationStation;
  }

  public void setDestinationStation(byte[] destinationStation)
  {
    this.destinationStation.set(new String(destinationStation));
  }

  public StringProperty getTrainId()
  {
    return trainId;
  }

  public void setTrainId(byte[] trainId)
  {
    this.trainId.set(new String(trainId));
  }

  public void setSemiAutoTrainId(byte[] newValue)
  {
    semiAutoTrainId.set(new String(newValue));

  }

  public StringProperty getSemiAutoTrainId()
  {
    return semiAutoTrainId;
  }

  public void setStationList(byte[] stationList)
  {
    if (stationList.length != 0)
    {
      try
      {
        stationListChanged.set(false);
        this.stationList = TCMSProto.StationList.parseFrom(stationList);

        updateStationList();
        stationListChanged.set(true);
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

  public ListProperty<StationDetailModel> getStationDetailList()
  {
    return stationDetailList;
  }

  public BooleanProperty getStationListChangedProperty()
  {
    return stationListChanged;
  }

  public void setSelectedStationName(byte[] stationName)
  {
    this.selectedStationName.set(new String(stationName));
  }

  public StringProperty getSelectedStationName()
  {
    return selectedStationName;
  }

  public IntegerProperty getTrainEvac()
  {
    return trainEvacState;
  }

  public void setTrainEvac(Integer newValue)
  {

    this.trainEvacState.set(newValue);

  }

  public IntegerProperty getTrainOutOfService()
  {
    return outOfServiceState;
  }

  public void setTrainOutOfService(Integer newValue)
  {
    this.outOfServiceState.set(newValue);

  }

  public IntegerProperty getTrainHoldState()
  {
    return trainHoldState;
  }

  public void setTrainHoldState(Integer newValue)
  {
    this.trainHoldState.set(newValue);

  }

  public IntegerProperty getTrainDelayState()
  {
    return trainDelayState;
  }

  public void setTrainDelayState(Integer newValue)
  {
    this.trainDelayState.set(newValue);

  }

  public IntegerProperty getServiceState()
  {
    return serviceState;
  }

  public void setServiceState(Integer newValue)
  {
    this.serviceState.set(newValue);

  }

  public void setLine2StationList(byte[] newValue)
  {

    if (newValue.length != 0)
    {
      try
      {
        line2StationListChanged.set(false);
        this.stationList = TCMSProto.StationList.parseFrom(newValue);

        updateLine2StationList(stationList);
        line2StationListChanged.set(true);
      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
    }
    else
    {
      line2StationDetailList.clear();
    }

  }

  private void updateLine2StationList(StationList stList)
  {
    if (stList != null)
    {
      line2StationDetailList.clear();
      for (StationDetail stationDetail : this.stationList.getStationDetailList())
      {
        line2StationDetailList.add(new StationDetailModel(stationDetail.getStationId(),
            stationDetail.getStationCode(), stationDetail.getStationName()));
      }
    }
  }

  public ListProperty<StationDetailModel> getLine2StationDetailList()
  {
    return line2StationDetailList;
  }
  
  public BooleanProperty getLine2StationListChangedProperty()
  {
    return line2StationListChanged;
  }
  
  public void setLine7StationList(byte[] newValue)
  {

    if (newValue.length != 0)
    {
      try
      {
        line7StationListChanged.set(false);
        this.stationList = TCMSProto.StationList.parseFrom(newValue);

        updateLine7StationList(stationList);
        line7StationListChanged.set(true);
      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
    }
    else
    {
      line7StationDetailList.clear();
    }

  }

  
  private void updateLine7StationList(StationList stList)
  {
    if (stList != null)
    {
      line7StationDetailList.clear();
      for (StationDetail stationDetail : this.stationList.getStationDetailList())
      {
        line7StationDetailList.add(new StationDetailModel(stationDetail.getStationId(),
            stationDetail.getStationCode(), stationDetail.getStationName()));
      }
    }
  }
  
  
  public BooleanProperty getLine7StationListChangedProperty()
  {
    return line7StationListChanged;
  }
  
  public ListProperty<StationDetailModel> getLine7StationDetailList()
  {
    return line7StationDetailList;
  }
  
  
}

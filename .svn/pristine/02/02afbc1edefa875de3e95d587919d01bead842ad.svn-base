/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.tcms.fe.gui.model;

import com.sydac.mmrbem.cabscreens.fe.gui.model.AbstractScreenModel;
import com.sydac.mmrbem.tcms.common.state.ApplicationConstants;
import com.sydac.mmrbem.tcms.common.state.TrainIndicatorStatusEnum;

import javafx.beans.property.DoubleProperty;
import javafx.beans.property.IntegerProperty;
import javafx.beans.property.SimpleDoubleProperty;
import javafx.beans.property.SimpleIntegerProperty;
import javafx.beans.property.SimpleStringProperty;
import javafx.beans.property.StringProperty;

public class OperatingScreenModel extends AbstractScreenModel
{
  private IntegerProperty trainNumber = new SimpleIntegerProperty();

  private DoubleProperty lineVoltage = new SimpleDoubleProperty();

  private IntegerProperty batteryVoltage = new SimpleIntegerProperty();

  private DoubleProperty odometerValue = new SimpleDoubleProperty();

  private IntegerProperty totalTrainWeight = new SimpleIntegerProperty();

  private StringProperty startStation = new SimpleStringProperty();

  private StringProperty currentStation = new SimpleStringProperty();

  private StringProperty destinationStation = new SimpleStringProperty();

  private StringProperty nextStation = new SimpleStringProperty();

  private StringProperty doorOpeningNextStation = new SimpleStringProperty();

  private StringProperty rescueMode = new SimpleStringProperty();

  private StringProperty jogMode = new SimpleStringProperty();

  private StringProperty enableToRun = new SimpleStringProperty();

  private StringProperty atcBypass = new SimpleStringProperty();

  private StringProperty shoreSupply = new SimpleStringProperty();

  private StringProperty coupled = new SimpleStringProperty();

  private StringProperty tcmsMode = new SimpleStringProperty(ApplicationConstants.BLANK);

  private IntegerProperty notchValue = new SimpleIntegerProperty();
  
  private IntegerProperty tbcFeedBackValue = new SimpleIntegerProperty();

  public OperatingScreenModel(int carIndex)
  {
    super(carIndex);
  }

  public IntegerProperty getTrainNumber()
  {
    return trainNumber;
  }

  public void setTrainNumber(Integer trainNumber)
  {
    this.trainNumber.set(trainNumber);
  }

  public DoubleProperty getLineVoltage()
  {
    return lineVoltage;
  }

  public void setLineVoltage(Double lineVoltage)
  {
    this.lineVoltage.set(lineVoltage);
  }

  public IntegerProperty getBatteryVoltage()
  {
    return batteryVoltage;
  }

  public void setBatteryVoltage(Integer batteryVoltage)
  {
    this.batteryVoltage.set(batteryVoltage);
  }

  public DoubleProperty getOdometerValue()
  {
    return odometerValue;
  }

  public void setOdometerValue(Double odometerValue)
  {
    this.odometerValue.set(odometerValue);
  }

  public IntegerProperty getTotalTrainWeight()
  {
    return totalTrainWeight;
  }

  public void setTotalTrainWeight(Integer totalTrainWeight)
  {
    this.totalTrainWeight.set(totalTrainWeight);
  }

  public StringProperty getRescueMode()
  {
    return rescueMode;
  }

  public void setRescueMode(Integer rescueMode)
  {
    this.rescueMode.set(TrainIndicatorStatusEnum.valueOf(rescueMode).getStatus());
  }

  public StringProperty getJogMode()
  {
    return jogMode;
  }

  public void setJogMode(Integer jogMode)
  {
    this.jogMode.set(TrainIndicatorStatusEnum.valueOf(jogMode).getStatus());
  }

  public StringProperty getEnableToRun()
  {
    return enableToRun;
  }

  public void setEnableToRun(Integer enableToRun)
  {
    this.enableToRun.set(TrainIndicatorStatusEnum.valueOf(enableToRun).getStatus());
  }

  public StringProperty getAtcBypass()
  {
    return atcBypass;
  }

  public void setAtcBypass(Integer atcBypass)
  {
    this.atcBypass.set(TrainIndicatorStatusEnum.valueOf(atcBypass).getStatus());
  }

  public StringProperty getShoreSupply()
  {
    return shoreSupply;
  }

  public void setShoreSupply(Integer shoreSupply)
  {
    this.shoreSupply.set(TrainIndicatorStatusEnum.valueOf(shoreSupply).getStatus());
  }

  public StringProperty getCoupled()
  {
    return coupled;
  }

  public void setCoupled(Integer coupled)
  {
    this.coupled.set(TrainIndicatorStatusEnum.valueOf(coupled).getStatus());
  }

  public StringProperty getTcmsMode()
  {
    return tcmsMode;
  }

  public void setTcmsMode(byte[] mode)
  {
    this.tcmsMode.set(new String(mode));
  }

  public IntegerProperty getNotchValue()
  {
    return notchValue;
  }

  public void setNotchValue(Integer notchValue)
  {
    this.notchValue.set(notchValue);
  }

  public StringProperty getStartStation()
  {
    return startStation;
  }

  public void setStartStation(byte[] startStation)
  {
    System.out.println(startStation);
    System.out.println(new String(startStation));
    this.startStation.set(new String(startStation));
  }

  public StringProperty getCurrentStation()
  {
    return currentStation;
  }

  public void setCurrentStation(byte[] currentStation)
  {
    this.currentStation.set(new String(currentStation));
  }

  public StringProperty getDestinationStation()
  {
    return destinationStation;
  }

  public void setDestinationStation(byte[] destinationStation)
  {
    this.destinationStation.set(new String(destinationStation));
  }

  public StringProperty getNextStation()
  {
    return nextStation;
  }

  public void setNextStation(byte[] nextStation)
  {
    this.nextStation.set(new String(nextStation));
  }

  public StringProperty getDoorOpeningNextStation()
  {
    return doorOpeningNextStation;
  }

  public void setDoorOpeningNextStation(byte[] doorOpeningNextStation)
  {
    this.doorOpeningNextStation.set(new String(doorOpeningNextStation));
  }

  public void setTcmsTbcFeedBackValue(Integer tbcFeedBack)
  {
    this.tbcFeedBackValue.set(tbcFeedBack);
    
  }
  
  public IntegerProperty getTcmsTbcFeedBackValue()
  {
    return tbcFeedBackValue;
  }

}

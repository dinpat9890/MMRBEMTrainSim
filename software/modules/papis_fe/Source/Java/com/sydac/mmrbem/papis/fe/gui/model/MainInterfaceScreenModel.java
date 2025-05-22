/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.papis.fe.gui.model;

import com.sydac.mmrbem.cabscreens.fe.gui.model.AbstractScreenModel;

import javafx.beans.property.IntegerProperty;
import javafx.beans.property.SimpleIntegerProperty;
import javafx.beans.property.SimpleStringProperty;
import javafx.beans.property.StringProperty;

public class MainInterfaceScreenModel extends AbstractScreenModel
{

  private IntegerProperty activeMode = new SimpleIntegerProperty();

  private StringProperty currentStation = new SimpleStringProperty();

  private StringProperty terminalStation = new SimpleStringProperty();

  private StringProperty nextStation = new SimpleStringProperty();

  private StringProperty doorOpenSide = new SimpleStringProperty();

  private StringProperty currentLine = new SimpleStringProperty();

  private StringProperty currentConnection = new SimpleStringProperty();

  private IntegerProperty ccButtonProperty = new SimpleIntegerProperty();

  private IntegerProperty pcButtonProperty = new SimpleIntegerProperty();

  private IntegerProperty doorStatus = new SimpleIntegerProperty();

  private IntegerProperty selectedButton = new SimpleIntegerProperty();

  public MainInterfaceScreenModel(int carIndex)
  {
    super(carIndex);
  }

  public IntegerProperty getDoorStatus()
  {
    return doorStatus;
  }

  public IntegerProperty getActiveMode()
  {
    return activeMode;
  }

  public void setActiveMode(Integer activeMode)
  {
    this.activeMode.set(activeMode);
  }

  public StringProperty getCurrentStation()
  {
    return currentStation;
  }

  public void setCurrentStation(byte[] currentStation)
  {
    this.currentStation.set(new String(currentStation));
  }

  public StringProperty getTerminalStation()
  {
    return terminalStation;
  }

  public void setTerminalStation(byte[] terminalStation)
  {
    this.terminalStation.set(new String(terminalStation));
  }

  public StringProperty getNextStation()
  {
    return nextStation;
  }

  public void setNextStation(byte[] newValue)
  {
    this.nextStation.set(new String(newValue));
  }

  public StringProperty getDoorOpenSide()
  {
    return doorOpenSide;
  }

  public void setDoorOpenSide(byte[] doorOpenSide)
  {
    this.doorOpenSide.set(new String(doorOpenSide));
  }

  public StringProperty getCurrentLine()
  {
    return currentLine;
  }

  public void setCurrentLine(byte[] line)
  {
    this.currentLine.set(new String(line));
  }

  public StringProperty getCurrentConnection()
  {
    return currentConnection;
  }

  public void setCurrentConnection(byte[] connectionType)
  {
    this.currentConnection.set(new String(connectionType));
  }

  public IntegerProperty getCcButtonProperty()
  {
    return ccButtonProperty;
  }

  public void setCcButtonProperty(Integer ccButtonProperty)
  {
    this.ccButtonProperty.set(ccButtonProperty);
  }

  public IntegerProperty getPcButtonProperty()
  {
    return pcButtonProperty;
  }

  public void setPcButtonProperty(Integer pcButtonProperty)
  {
    this.pcButtonProperty.set(pcButtonProperty);
  }

  public void setDoorStatus(Integer doorState)
  {
    this.doorStatus.set(doorState);
  }

  public IntegerProperty getSelectedButton()
  {
    return selectedButton;
  }

  public void setSelectedButton(Integer newValue)
  {
    selectedButton.set(newValue);

  }
}

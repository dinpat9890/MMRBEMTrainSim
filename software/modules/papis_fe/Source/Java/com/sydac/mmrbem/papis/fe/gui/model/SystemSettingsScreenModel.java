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

public class SystemSettingsScreenModel extends AbstractScreenModel
{

  private StringProperty trainIdproperty = new SimpleStringProperty();

  private StringProperty routeProperty = new SimpleStringProperty();

  private StringProperty startStationProperty = new SimpleStringProperty();

  private StringProperty terminalStationProperty = new SimpleStringProperty();

  private StringProperty nextStationProperty = new SimpleStringProperty();

  private IntegerProperty modeSelectionProperty = new SimpleIntegerProperty();

  public SystemSettingsScreenModel(int carIndex)
  {
    super(carIndex);
  }

  public StringProperty getTrainIdproperty()
  {
    return trainIdproperty;
  }

  public void setTrainIdproperty(byte[] trainIdproperty)
  {
    this.trainIdproperty.set(new String(trainIdproperty));
  }

  public StringProperty getRouteProperty()
  {
    return routeProperty;
  }

  public void setRouteProperty(byte[] routeProperty)
  {
    this.routeProperty.set(new String(routeProperty));
  }

  public StringProperty getStartStationProperty()
  {
    return startStationProperty;
  }

  public void setStartStationProperty(byte[] startStation)
  {
    this.startStationProperty.set(new String(startStation));
  }

  public StringProperty getTerminalStationProperty()
  {
    return terminalStationProperty;
  }

  public void setTerminalStationProperty(byte[] terminalStationProperty)
  {
    this.terminalStationProperty.set(new String(terminalStationProperty));
  }

  public StringProperty getNextStationProperty()
  {
    return nextStationProperty;
  }

  public void setNextStationProperty(byte[] nextStationProperty)
  {
    this.nextStationProperty.set(new String(nextStationProperty));
  }

  public IntegerProperty getModeSelectionProperty()
  {
    return modeSelectionProperty;
  }

  public void setModeSelectionProperty(Integer modeSelectionProperty)
  {
    this.modeSelectionProperty.set(modeSelectionProperty);
  }
}

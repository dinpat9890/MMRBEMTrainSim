/*
 * ================================================================== (C)
 * Copyright 2020 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.dmi.fe.gui.model;

import com.sydac.mmrbem.cabscreens.fe.gui.model.AbstractScreenModel;

import javafx.beans.property.IntegerProperty;
import javafx.beans.property.SimpleIntegerProperty;

/**
 * A model to Main Screen Area D Top
 * 
 * @author mulukg
 *
 */
public class MainScreenAreaETopModel extends AbstractScreenModel
{
  private final IntegerProperty radioCommsStatus = new SimpleIntegerProperty();

  private final IntegerProperty atcStatus = new SimpleIntegerProperty();
  
  private final IntegerProperty atpZoneStatus = new SimpleIntegerProperty();
  
  private IntegerProperty depotIndication = new SimpleIntegerProperty();

  public MainScreenAreaETopModel(int carIndex)
  {
    super(carIndex);
  }

  public IntegerProperty getRadioCommsStatus()
  {
    return radioCommsStatus;
  }

  public void setRadioCommunicationStatus(Integer value)
  {
    radioCommsStatus.setValue(value);
  }

  public void setAtcStatus(Integer value)
  {
    atcStatus.setValue(value);
  }

  /**
   * @return the atcStatus
   */
  public IntegerProperty getAtcStatus()
  {
    return atcStatus;
  }

  public IntegerProperty getAtpZoneStatus() 
  {
	return atpZoneStatus;
  }

  public void setAtpZoneStatus(Integer value) 
  {
	  atpZoneStatus.setValue(value);
  }

  public IntegerProperty getDepotIndication() 
  {
	return depotIndication;
  }

  public void setDepotIndication(Integer value) 
  {
	  depotIndication.setValue(value);
  }

}

/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.tcms.fe.gui.model;

import com.sydac.mmrbem.cabscreens.fe.gui.model.AbstractScreenModel;

import javafx.beans.property.IntegerProperty;
import javafx.beans.property.SimpleIntegerProperty;

public class OdometerScreenModel extends AbstractScreenModel
{

  private IntegerProperty odometerValue = new SimpleIntegerProperty();

  public OdometerScreenModel(int carIndex)
  {
    super(carIndex);
  }

  public IntegerProperty getOdometerValue()
  {
    return odometerValue;
  }

  public void setOdometerValue(Integer odometer)
  {
    this.odometerValue.set(odometer);
  }

}

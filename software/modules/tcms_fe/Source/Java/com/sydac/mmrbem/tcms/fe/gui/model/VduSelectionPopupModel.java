/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.tcms.fe.gui.model;

import com.sydac.mmrbem.cabscreens.fe.gui.model.AbstractScreenModel;

import javafx.beans.property.IntegerProperty;
import javafx.beans.property.SimpleIntegerProperty;

public class VduSelectionPopupModel extends AbstractScreenModel
{

  private IntegerProperty currentVduMode = new SimpleIntegerProperty();

  private IntegerProperty currentCctvVduMode = new SimpleIntegerProperty();

  public VduSelectionPopupModel(int carIndex)
  {
    super(carIndex);
  }

  public IntegerProperty getVduSelected()
  {
    return currentVduMode;
  }

  public void setVduSelected(int vduSelected)
  {
    this.currentVduMode.set(vduSelected);
  }

  public IntegerProperty getCurrentCctvVduMode()
  {
    return currentCctvVduMode;
  }

  public void setCurrentCctvVduMode(Integer currentCctvVduMode)
  {
    this.currentCctvVduMode.set(currentCctvVduMode);
  }
}

/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.tcms.fe.gui.model;

import com.sydac.mmrbem.cabscreens.fe.gui.model.AbstractScreenModel;

import javafx.beans.property.IntegerProperty;
import javafx.beans.property.SimpleIntegerProperty;

public class HybridModeScreenModel extends AbstractScreenModel
{

  private IntegerProperty hybridPanelActiveSide = new SimpleIntegerProperty();

  private IntegerProperty currentImageId = new SimpleIntegerProperty();

  public HybridModeScreenModel(int carIndex)
  {
    super(carIndex);
  }

  public IntegerProperty getHybridPanelActiveSide()
  {
    return hybridPanelActiveSide;
  }

  public void setHybridPanelActiveSide(Integer hybridPanelActiveSide)
  {
    this.hybridPanelActiveSide.set(hybridPanelActiveSide);
  }

  public IntegerProperty getCurrentImageId()
  {
    return currentImageId;
  }

  public void setCurrentImageId(Integer currentImageId)
  {
    this.currentImageId.set(currentImageId);
  }

}

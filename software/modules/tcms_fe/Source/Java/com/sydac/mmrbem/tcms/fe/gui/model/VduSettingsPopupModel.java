/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.tcms.fe.gui.model;

import com.sydac.mmrbem.cabscreens.fe.gui.model.AbstractScreenModel;

import javafx.beans.property.IntegerProperty;
import javafx.beans.property.SimpleIntegerProperty;

public class VduSettingsPopupModel extends AbstractScreenModel
{

  private IntegerProperty currentBrightnessSetting = new SimpleIntegerProperty();

  public VduSettingsPopupModel(int carIndex)
  {
    super(carIndex);
  }

  public IntegerProperty getCurrentBrightnessSetting()
  {
    return currentBrightnessSetting;
  }

  public void setCurrentBrightnessSetting(int currentBrightnessSetting)
  {
    this.currentBrightnessSetting.set(currentBrightnessSetting);
  }

}

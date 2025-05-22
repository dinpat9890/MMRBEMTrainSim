/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.psd.fe.gui.model;

import com.sydac.mmrbem.cabscreens.fe.gui.model.AbstractScreenModel;

import javafx.beans.property.BooleanProperty;
import javafx.beans.property.IntegerProperty;
import javafx.beans.property.SimpleBooleanProperty;
import javafx.beans.property.SimpleIntegerProperty;

public class PsdPanelModel extends AbstractScreenModel
{
  private BooleanProperty pseEnableButtonState = new SimpleBooleanProperty();

  private IntegerProperty interlockOverrideStatus = new SimpleIntegerProperty();

  private IntegerProperty lampStatus = new SimpleIntegerProperty();

  private IntegerProperty doorStatus = new SimpleIntegerProperty();

  public PsdPanelModel(int carIndex)
  {
    super(carIndex);
  }

  public void setPseEnableState(Integer state)
  {
    pseEnableButtonState.set(state!= 0);

  }

  public void setInterlockOverrideStatus(Integer newValue)
  {
    interlockOverrideStatus.set(newValue);

  }

  public BooleanProperty isPseEnable()
  {
    return pseEnableButtonState;
  }

  public IntegerProperty getInterlockOverrideStatus()
  {
    return interlockOverrideStatus;
  }

  public void setLampStatus(Integer newValue)
  {
    lampStatus.set(newValue);

  }

  public IntegerProperty getLampStatus()
  {
    return lampStatus;
  }

  public void setPsdDoorStatus(Integer newValue)
  {
    doorStatus.set(newValue);

  }

  public IntegerProperty getDoorStatus()
  {
    return doorStatus;
  }
}

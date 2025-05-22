/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.tcms.fe.gui.model;

import com.sydac.mmrbem.cabscreens.fe.gui.model.AbstractScreenModel;

import javafx.beans.property.IntegerProperty;
import javafx.beans.property.SimpleIntegerProperty;

public class FooterPanelModel extends AbstractScreenModel
{

  private IntegerProperty currentScreenId = new SimpleIntegerProperty();

  private IntegerProperty currentPopupId = new SimpleIntegerProperty();

  private IntegerProperty noOfFaults = new SimpleIntegerProperty();

  private IntegerProperty faultPriorityState = new SimpleIntegerProperty();

  public FooterPanelModel(int carIndex)
  {
    super(carIndex);
  }

  public IntegerProperty getCurrentScreenId()
  {
    return currentScreenId;
  }

  public void setCurrentScreenId(int currentScreenId)
  {
    this.currentScreenId.set(currentScreenId);
  }

  public IntegerProperty getCurrentPopupId()
  {
    return currentPopupId;
  }

  public void setCurrentPopupId(int currentPopupId)
  {
    this.currentPopupId.set(currentPopupId);
  }

  public IntegerProperty getNoOfFaults()
  {
    return noOfFaults;
  }

  public void setNoOfFaults(Integer noOfFaults)
  {
    this.noOfFaults.set(noOfFaults);
  }

  public IntegerProperty getFaultPriorityState()
  {
    return faultPriorityState;
  }

  public void setFaultPriorityState(Integer faultPriorityState)
  {
    this.faultPriorityState.set(faultPriorityState);
  }

}

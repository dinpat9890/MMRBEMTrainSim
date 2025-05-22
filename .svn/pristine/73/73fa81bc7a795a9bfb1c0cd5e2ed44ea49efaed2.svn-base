/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/

package com.sydac.mmrbem.radio.fe.gui.model;

import com.sydac.mmrbem.cabscreens.fe.gui.model.AbstractScreenModel;

import javafx.beans.property.IntegerProperty;
import javafx.beans.property.SimpleIntegerProperty;

/**
 * A model to Power Menu and Nav Panel
 * 
 * @author mulukg
 *
 */
public class MainMenuModel extends AbstractScreenModel
{
  private IntegerProperty callType = new SimpleIntegerProperty();

  public MainMenuModel(int carIndex)
  {
    super(carIndex);
  }

  public void setCallType(Integer status)
  {
    this.callType.set(status);
  }

  public IntegerProperty getCallType()
  {
    return callType;
  }

}

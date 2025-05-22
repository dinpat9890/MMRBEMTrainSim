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
public class PowerMenuAndNavPanelModel extends AbstractScreenModel
{
  private IntegerProperty contactNavBtnStatus = new SimpleIntegerProperty();

  public PowerMenuAndNavPanelModel(int carIndex)
  {
    super(carIndex);
  }

  public void setContactNavBtnStatus(Integer status)
  {
    this.contactNavBtnStatus.set(status);
  }

  public IntegerProperty getContactNavBtnStatus()
  {
    return contactNavBtnStatus;
  }

}

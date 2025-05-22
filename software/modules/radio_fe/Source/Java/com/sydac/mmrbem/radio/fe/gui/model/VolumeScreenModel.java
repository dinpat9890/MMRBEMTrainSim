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
 * A model to Volume screen
 * 
 * @author ext-jadhalp
 *
 */
public class VolumeScreenModel extends AbstractScreenModel
{
  private IntegerProperty upBtnStatus = new SimpleIntegerProperty();

  private IntegerProperty downBtnStatus = new SimpleIntegerProperty();

  public VolumeScreenModel(int carIndex)
  {
    super(carIndex);
  }

  public IntegerProperty getUpBtnStatus()
  {
    return upBtnStatus;
  }

  public void setUpBtnStatus(Integer upBtnStatus)
  {
    this.upBtnStatus.set(upBtnStatus);
  }

  public IntegerProperty getDownBtnStatus()
  {
    return downBtnStatus;
  }

  public void setDownBtnStatus(Integer downBtnStatus)
  {
    this.downBtnStatus.set(downBtnStatus);
  }

}

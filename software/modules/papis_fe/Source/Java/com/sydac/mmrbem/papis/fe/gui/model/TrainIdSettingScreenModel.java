/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.papis.fe.gui.model;

import com.sydac.mmrbem.cabscreens.fe.gui.model.AbstractScreenModel;

import javafx.beans.property.SimpleStringProperty;
import javafx.beans.property.StringProperty;

public class TrainIdSettingScreenModel extends AbstractScreenModel
{

  private StringProperty trainIdproperty = new SimpleStringProperty();

  public TrainIdSettingScreenModel(int carIndex)
  {
    super(carIndex);
  }

  public StringProperty getTrainIdproperty()
  {
    return trainIdproperty;
  }

  public void setTrainIdproperty(byte[] trainIdproperty)
  {
    this.trainIdproperty.set(new String(trainIdproperty));
  }

}

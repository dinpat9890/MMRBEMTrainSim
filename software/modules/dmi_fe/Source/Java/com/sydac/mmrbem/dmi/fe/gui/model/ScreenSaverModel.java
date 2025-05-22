/*
 * ==================================================================
 * 
 * (C) Copyright 2020 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.dmi.fe.gui.model;

import com.sydac.mmrbem.cabscreens.fe.gui.model.AbstractScreenModel;

import javafx.beans.property.SimpleStringProperty;
import javafx.beans.property.StringProperty;

public class ScreenSaverModel extends AbstractScreenModel
{

  private final StringProperty softwateVersionText = new SimpleStringProperty();

  public ScreenSaverModel(int carIndex)
  {
    super(carIndex);
  }

  public void setSoftwareVersion(String softwateVersion)
  {
    softwateVersionText.set(softwateVersion);
  }

  public StringProperty getSoftwateVersionText()
  {
    return softwateVersionText;
  }
}

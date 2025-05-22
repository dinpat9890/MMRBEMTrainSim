/*
 * ================================================================== (C)
 * Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.radio.fe.gui.model;

import com.sydac.mmrbem.cabscreens.fe.gui.model.AbstractScreenModel;

import javafx.beans.property.IntegerProperty;
import javafx.beans.property.SimpleIntegerProperty;
import javafx.beans.property.SimpleStringProperty;
import javafx.beans.property.StringProperty;

/**
 * A model to Header Panel
 * 
 * @author ext-tambet
 *
 */
public class HeaderPanelModel extends AbstractScreenModel
{

  private StringProperty lineName = new SimpleStringProperty();

  private IntegerProperty messageCount = new SimpleIntegerProperty();

  private IntegerProperty radioSignal = new SimpleIntegerProperty();

  public HeaderPanelModel(int carIndex)
  {
    super(carIndex);
  }

  public void setLineName(String lineName)
  {
    this.lineName.set(lineName);
  }

  public void setMessageCount(Integer messageCount)
  {
    this.messageCount.set(messageCount);
  }

  public void setRadioSignal(Integer radioSignal)
  {
    this.radioSignal.set(radioSignal);
  }

  public StringProperty getLineName()
  {
    return lineName;
  }

  public IntegerProperty getMessageCount()
  {
    return messageCount;
  }

  public IntegerProperty getRadioSignal()
  {
    return radioSignal;
  }

}
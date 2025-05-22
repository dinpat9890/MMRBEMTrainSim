/*
 * ==================================================================
 * 
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.tcms.fe.gui.data;

import javafx.beans.property.IntegerProperty;
import javafx.beans.property.SimpleStringProperty;
import javafx.beans.property.StringProperty;

/**
 * Class to hold information for tables having information in row wise format
 * 
 * @author ext-vp
 *
 */
public class EnergyConsumpCountersTableDO
{

  private StringProperty counterName = new SimpleStringProperty();

  private StringProperty counterDescription = new SimpleStringProperty();

  private StringProperty currentValue = new SimpleStringProperty();

  private StringProperty measureUnit = new SimpleStringProperty();

  public EnergyConsumpCountersTableDO(String counterName, String counterDescription,
      String currentValue, String measureUnit)
  {
    super();
    this.counterName.set(counterName);
    this.counterDescription.set(counterDescription);
    this.currentValue.set(currentValue);
    this.measureUnit.set(measureUnit);
  }

  public String getCounterName()
  {
    return counterName.get();
  }

  public String getCounterDescription()
  {
    return counterDescription.get();
  }

  public String getCurrentValue()
  {
    return currentValue.get();
  }

  public String getMeasureUnit()
  {
    return measureUnit.get();
  }
}

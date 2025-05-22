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

import javafx.beans.property.BooleanProperty;
import javafx.beans.property.IntegerProperty;
import javafx.beans.property.LongProperty;
import javafx.beans.property.SimpleBooleanProperty;
import javafx.beans.property.SimpleIntegerProperty;
import javafx.beans.property.SimpleLongProperty;
import javafx.beans.property.SimpleStringProperty;
import javafx.beans.property.StringProperty;

/**
 * Class to hold information for tables having information in row wise format
 * 
 * @author ext-vp
 *
 */
public class EventAreaDO
{
  private StringProperty carCode = new SimpleStringProperty();

  private StringProperty faultCode = new SimpleStringProperty();

  private IntegerProperty faultLevel = new SimpleIntegerProperty();

  private StringProperty faultSystemName = new SimpleStringProperty();

  private StringProperty faultDescription = new SimpleStringProperty();

  private LongProperty faultOccuranceDateTime = new SimpleLongProperty();

  private BooleanProperty faultAcknowledged = new SimpleBooleanProperty();

  public EventAreaDO(String carCode, String faultCode, Integer faultLevel, String faultSystemName,
      String faultDescription, Long faultOccuranceDateTime, Boolean faultAcknowledged)
  {
    super();
    this.carCode.set(carCode);
    setFaultCode(faultCode);
    this.faultLevel.set(faultLevel);
    this.faultSystemName.set(faultSystemName);
    this.faultDescription.set(faultDescription);
    this.faultOccuranceDateTime.set(faultOccuranceDateTime);
    this.faultAcknowledged.set(faultAcknowledged);
  }

  private void setFaultCode(String code)
  {
    String tempFaultCode = code;
    if (code.length() == 6)
    {
      this.faultCode.set(code);
    }
    else
    {
      do
      {
        tempFaultCode = "0".concat(tempFaultCode); //$NON-NLS-1$
      } while (tempFaultCode.length() < 6);
      this.faultCode.set(tempFaultCode);
    }
  }

  public StringProperty getCarCode()
  {
    return carCode;
  }

  public void setCarCode(StringProperty carCode)
  {
    this.carCode = carCode;
  }

  public StringProperty getFaultCode()
  {
    return faultCode;
  }

  public void setFaultCode(StringProperty faultCode)
  {
    this.faultCode = faultCode;
  }

  public Integer getFaultLevel()
  {
    return faultLevel.get();
  }

  public void setFaultLevel(IntegerProperty faultLevel)
  {
    this.faultLevel = faultLevel;
  }

  public StringProperty getFaultSystemName()
  {
    return faultSystemName;
  }

  public void setFaultSystemName(StringProperty faultSystemName)
  {
    this.faultSystemName = faultSystemName;
  }

  public StringProperty getFaultDescription()
  {
    return faultDescription;
  }

  public void setFaultDescription(StringProperty faultDescription)
  {
    this.faultDescription = faultDescription;
  }

  public Long getFaultOccuranceDateTime()
  {
    return faultOccuranceDateTime.get();
  }

  public void setFaultOccuranceDateTime(LongProperty faultOccuranceDateTime)
  {
    this.faultOccuranceDateTime = faultOccuranceDateTime;
  }

  public BooleanProperty getFaultAcknowledged()
  {
    return faultAcknowledged;
  }

  public void setFaultAcknowledged(BooleanProperty faultAcknowledged)
  {
    this.faultAcknowledged = faultAcknowledged;
  }

}

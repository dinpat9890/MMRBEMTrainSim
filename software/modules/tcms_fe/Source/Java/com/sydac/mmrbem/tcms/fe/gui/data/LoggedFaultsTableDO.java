/*
 * ==================================================================
 * 
 * (C) Copyright 2023 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.tcms.fe.gui.data;

import javafx.beans.property.BooleanProperty;
import javafx.beans.property.IntegerProperty;
import javafx.beans.property.SimpleBooleanProperty;
import javafx.beans.property.SimpleIntegerProperty;
import javafx.beans.property.SimpleStringProperty;
import javafx.beans.property.StringProperty;

/**
 * Class to hold information for tables having information in row wise format
 * 
 * @author ext-vp
 *
 */
public class LoggedFaultsTableDO
{

  private IntegerProperty orderId = new SimpleIntegerProperty();

  private IntegerProperty faultId = new SimpleIntegerProperty();

  private StringProperty carCode = new SimpleStringProperty();

  private StringProperty faultCode = new SimpleStringProperty();

  private IntegerProperty faultLevel = new SimpleIntegerProperty();

  private StringProperty faultSystemName = new SimpleStringProperty();

  private StringProperty faultDescription = new SimpleStringProperty();

  private StringProperty faultOccuranceDateTime = new SimpleStringProperty();

  private StringProperty faultClearanceDateTime = new SimpleStringProperty();

  private StringProperty faultComponenet = new SimpleStringProperty();

  private StringProperty operatorGuide = new SimpleStringProperty();

  private BooleanProperty faultAcknowledged = new SimpleBooleanProperty();

  public LoggedFaultsTableDO(Integer orderId, Integer faultId, String carCode, String faultCode,
      Integer faultLevel, String faultSystemName, String faultDescription, String faultOccuranceDateTime,
      String faultClearanceDateTime, String faultComponent, String operatorGuide)
  {
    super();
    this.orderId.set(orderId);
    this.faultId.set(faultId);
    this.carCode.set(carCode);
    setFaultCode(faultCode);
    this.faultLevel.set(faultLevel);
    this.faultSystemName.set(faultSystemName);
    this.faultDescription.set(faultDescription);
    this.faultOccuranceDateTime.set(faultOccuranceDateTime);
    this.faultClearanceDateTime.set(faultClearanceDateTime);
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

  public Integer getOrderId()
  {
    return orderId.get();
  }

  public Integer getFaultId()
  {
    return faultId.get();
  }

  public String getCarCode()
  {
    return carCode.get();
  }

  public String getFaultCode()
  {
    return faultCode.get();
  }

  public Integer getFaultLevel()
  {
    return faultLevel.get();
  }

  public String getFaultSystemName()
  {
    return faultSystemName.get();
  }

  public String getFaultDescription()
  {
    return faultDescription.get();
  }

  public String getFaultOccuranceDateTime()
  {
    return faultOccuranceDateTime.get();
  }

  public String getFaultClearanceDateTime()
  {
    return faultClearanceDateTime.get();
  }

  public String getFaultComponenet()
  {
    return faultComponenet.get();
  }

  public String getOperatorGuide()
  {
    return operatorGuide.get();
  }

  public Boolean getFaultAcknowledged()
  {
    return faultAcknowledged.get();
  }
}

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
import javafx.beans.property.SimpleIntegerProperty;
import javafx.beans.property.SimpleStringProperty;
import javafx.beans.property.StringProperty;

public class TestScreenTableDO
{

  private IntegerProperty orderId = new SimpleIntegerProperty();

  private StringProperty carCode = new SimpleStringProperty();

  private StringProperty componentName = new SimpleStringProperty();

  private StringProperty testStatus = new SimpleStringProperty();

  private StringProperty lastUpdateDate = new SimpleStringProperty();

  private StringProperty lastUpdateTime = new SimpleStringProperty();

  public TestScreenTableDO(Integer orderId, String carCode, String componentName, String testStatus,
      String lastUpdateDate, String lastUpdateTime)
  {
    super();
    this.orderId.set(orderId);
    this.carCode.set(carCode);
    this.componentName.set(componentName);
    this.testStatus.set(testStatus);
    this.lastUpdateDate.set(lastUpdateDate);
    this.lastUpdateTime.set(lastUpdateTime);
  }

  public Integer getOrderId()
  {
    return orderId.get();
  }

  public void setOrderId(IntegerProperty orderId)
  {
    this.orderId = orderId;
  }

  public String getCarCode()
  {
    return carCode.get();
  }

  public void setCarCode(StringProperty carCode)
  {
    this.carCode = carCode;
  }

  public String getComponentName()
  {
    return componentName.get();
  }

  public void setComponentName(StringProperty componentName)
  {
    this.componentName = componentName;
  }

  public String getTestStatus()
  {
    return testStatus.get();
  }

  public void setTestStatus(StringProperty testStatus)
  {
    this.testStatus = testStatus;
  }

  public String getLastUpdateDate()
  {
    return lastUpdateDate.get();
  }

  public void setLastUpdateDate(StringProperty lastUpdateDate)
  {
    this.lastUpdateDate = lastUpdateDate;
  }

  public String getLastUpdateTime()
  {
    return lastUpdateTime.get();
  }

  public void setLastUpdateTime(StringProperty lastUpdateTime)
  {
    this.lastUpdateTime = lastUpdateTime;
  }

}

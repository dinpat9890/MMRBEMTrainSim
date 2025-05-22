/*
 * ==================================================================
 * 
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.radio.common.data;

import javafx.beans.property.IntegerProperty;
import javafx.beans.property.LongProperty;
import javafx.beans.property.SimpleIntegerProperty;
import javafx.beans.property.SimpleLongProperty;
import javafx.beans.property.SimpleStringProperty;
import javafx.beans.property.StringProperty;

/**
 * Class to hold information for tables having information in row wise format
 * 
 * @author mulukg
 *
 */
public class MessageTableDO
{

  private StringProperty msgText = new SimpleStringProperty();

  private StringProperty statusCode = new SimpleStringProperty();

  private IntegerProperty msgId = new SimpleIntegerProperty();

  private LongProperty dateTime = new SimpleLongProperty();

  public MessageTableDO()
  {}

  public MessageTableDO(String msgTxt, Integer msgId, Long dateTime)
  {
    this.msgText.set(msgTxt);
    this.msgId.set(msgId);
    this.dateTime.set(dateTime);
  }

  public MessageTableDO(String msgTxt, int msgId, String statusCode, Long dateTime)
  {
    this.msgText.set(msgTxt);
    this.msgId.set(msgId);
    this.statusCode.set(statusCode);
    this.dateTime.set(dateTime);
  }

  public String getMsgText()
  {
    return msgText.get();
  }

  public Integer getMsgId()
  {
    return msgId.get();
  }

  public String getStatusCode()
  {
    return statusCode.get();
  }

  public Long getDateTime()
  {
    return dateTime.get();
  }

}

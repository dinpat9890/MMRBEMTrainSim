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

/**
 * Class to hold information for tables having information in row wise format
 * 
 * @author tambet
 *
 */
public class MessageDO
{

  private String msgText;

  private String statusCode;

  private int msgId;

  private long dateTime;

  public MessageDO()
  {}

  public MessageDO(String msgTxt, int msgId, long dateTime)
  {
    this.msgText = msgTxt;
    this.msgId = msgId;
    this.dateTime = dateTime;
  }

  public MessageDO(String msgTxt, int msgId, String statusCode, long dateTime)
  {
    this.msgText = msgTxt;
    this.msgId = msgId;
    this.statusCode = statusCode;
    this.dateTime = dateTime;
  }

  public String getMsgText()
  {
    return msgText;
  }

  public Integer getMsgId()
  {
    return msgId;
  }

  public String getStatusCode()
  {
    return statusCode;
  }

  public void setMsgText(String msgText)
  {
    this.msgText = msgText;
  }

  public void setStatusCode(String statusCode)
  {
    this.statusCode = statusCode;
  }

  public void setMsgId(Integer msgId)
  {
    this.msgId = msgId;
  }

  public Long getDateTime()
  {
    return dateTime;
  }

  public void setDateTime(Long dateTime)
  {
    this.dateTime = dateTime;
  }

}

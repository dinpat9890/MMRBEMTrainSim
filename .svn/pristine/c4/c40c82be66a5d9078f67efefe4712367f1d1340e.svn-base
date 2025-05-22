/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.tcms.common.state;

public enum ManualAnnouncementMessageType
{
  ARRIVAL(0, "arrival"), //$NON-NLS-1$
  DEPARTURE(1, "departure"); //$NON-NLS-1$

  private int messageTypeId;

  private String messageType;

  ManualAnnouncementMessageType(int messageTypeId, String messageType)
  {
    this.messageTypeId = messageTypeId;
    this.messageType = messageType;
  }

  public int getMessageTypeId()
  {
    return messageTypeId;
  }

  public void setMessageTypeId(int messageTypeId)
  {
    this.messageTypeId = messageTypeId;
  }

  public String getMessageType()
  {
    return messageType;
  }

  public void setMessageType(String messageType)
  {
    this.messageType = messageType;
  }

  public static ManualAnnouncementMessageType valueOf(int intValue)
  {
    for (ManualAnnouncementMessageType messageType : values())
    {
      if (messageType.getMessageTypeId() == intValue)
      {
        return messageType;
      }
    }
    return null;
  }
}

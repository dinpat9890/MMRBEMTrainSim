/*******************************************************************************
 * (C) Copyright 2023 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.papis.common.state;

/**
 * This enum can be used for different Header Panel Status Label inputs.
 * 
 * @author ext-vp
 *
 */
public enum HeaderStatusLabelEnum
{
  EMPTY(0, ""), //$NON-NLS-1$
  MUTE(1, "Mute"); //$NON-NLS-1$

  private int statusTypeId;

  private String statusText;

  HeaderStatusLabelEnum(int statusTypeId, String statusText)
  {
    this.statusTypeId = statusTypeId;
    this.statusText = statusText;
  }

  public int getStatusTypeId()
  {
    return statusTypeId;
  }

  public void setStatusTypeId(int messageTypeId)
  {
    this.statusTypeId = messageTypeId;
  }

  public String getStatusText()
  {
    return statusText;
  }

  public void setStatusText(String messageType)
  {
    this.statusText = messageType;
  }

  public static HeaderStatusLabelEnum valueOf(int intValue)
  {
    for (HeaderStatusLabelEnum messageType : values())
    {
      if (messageType.getStatusTypeId() == intValue)
      {
        return messageType;
      }
    }
    return null;
  }
}

/*
 * ==================================================================
 * 
 * (C) Copyright 2018 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.dmi.common.data;

import java.util.Objects;

import com.sydac.mmrbem.cbtc.common.protos.CBTCProtos.TextId;
import com.sydac.mmrbem.cbtc.common.protos.CBTCProtos.TextMessagePriority;
import com.sydac.mmrbem.dmi.common.protos.DMIProtos.TextMessages.AckState;

public class TextMessageDO
{
  private TextId id;

  private AckState ackState;

  private long timeStamp;

  private TextMessagePriority priority;

  private int uniqueId;

  private String displayText;

  public TextMessageDO()
  {
    // NO-OP
  }

  public String getDisplayText()
  {
    return displayText;
  }

  public void setDisplayText(String displayText)
  {
    this.displayText = displayText;
  }

  public void setUniqueId(int uniqueId)
  {
    this.uniqueId = uniqueId;
  }

  public int getUniqueId()
  {
    return uniqueId;
  }

  public void setId(TextId id)
  {
    this.id = id;
  }

  public TextId getId()
  {
    return id;
  }

  public void setAckState(AckState ackState)
  {
    this.ackState = ackState;
  }

  public AckState getAckState()
  {
    return ackState;
  }

  public long getTimeStamp()
  {
    return timeStamp;
  }

  public void setTimeStamp(long timestamp)
  {
    this.timeStamp = timestamp;
  }

  public TextMessagePriority getPriority()
  {
    return priority;
  }

  public void setPriority(TextMessagePriority textMessagePriority)
  {
    this.priority = textMessagePriority;
  }

  @Override
  public boolean equals(Object obj)
  {
    if (obj instanceof TextMessageDO)
    {
      return ((TextMessageDO)obj).getUniqueId() == this.getUniqueId();
    }
    return false;
  }

  @Override
  public int hashCode()
  {
    return Objects.hash(ackState, timeStamp, priority, displayText);
  }

  @Override
  public String toString()
  {
    return "TextMessageDO [Time=" + timeStamp + ", messageString=" + displayText + ", ack type=" + ackState //$NON-NLS-1$ //$NON-NLS-2$ //$NON-NLS-3$
        + "]";
  }
}

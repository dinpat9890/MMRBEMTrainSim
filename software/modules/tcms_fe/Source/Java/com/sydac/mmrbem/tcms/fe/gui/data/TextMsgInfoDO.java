/*
 * ==================================================================
 * 
 * (C) Copyright 2020 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.tcms.fe.gui.data;

import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.TimeZone;

import javafx.beans.property.DoubleProperty;
import javafx.beans.property.SimpleDoubleProperty;
import javafx.beans.property.SimpleStringProperty;
import javafx.beans.property.StringProperty;

/**
 * Class to hold information for text messages
 * 
 * @author ext-savanjin
 *
 */
public class TextMsgInfoDO
{
  private static final String UTC = "UTC"; //$NON-NLS-1$

  /** The message unique id */
  private DoubleProperty uniqueId = new SimpleDoubleProperty();

  /** The timestamp */
  private DoubleProperty messageTimeStamp = new SimpleDoubleProperty();

  /** The message name */
  private StringProperty displayText = new SimpleStringProperty();

  /** The message priority */
  private DoubleProperty priority = new SimpleDoubleProperty();

//  private AckState ackState;

  private StringProperty hourAndMinuteTimestamp = new SimpleStringProperty();

  private SimpleDateFormat timeFormat = new SimpleDateFormat("HH:mm"); //$NON-NLS-1$

	public TextMsgInfoDO(double uniqueId, String messageText, double timeStamp/*, AckState ackState*/,
      double priority)
  {
    formatTimestamp(timeStamp);
    this.uniqueId.set(uniqueId);
    displayText.set(messageText);
    messageTimeStamp.set(timeStamp);
//    this.ackState = ackState;
    this.priority.set(priority);
  }

  private void formatTimestamp(double timeStamp)
  {
    Date date = new Date((long)timeStamp);
    timeFormat.setTimeZone(TimeZone.getTimeZone(UTC));
    hourAndMinuteTimestamp.set(timeFormat.format(date));
  }

  public DoubleProperty getUniqueId()
  {
    return uniqueId;
  }

  public double getMessageTimeStamp()
  {
    return messageTimeStamp.get();
  }

  public String getDisplayText()
  {
    return displayText.get();
  }

  public DoubleProperty getPriority()
  {
    return priority;
  }

  public String getHourAndMinuteTimestamp()
  {
    return hourAndMinuteTimestamp.get();
  }

//  public AckState getAckState()
//  {
//    return ackState;
//  }

}

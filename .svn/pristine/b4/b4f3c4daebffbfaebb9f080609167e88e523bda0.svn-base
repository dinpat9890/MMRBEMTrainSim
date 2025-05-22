/*
 * ================================================================== (C)
 * Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.radio.fe.gui.model;

import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.TimeZone;

import com.sydac.gui.i18n.CommonStrings;
import com.sydac.mmrbem.cabscreens.fe.common.DateTimeModel;
import com.sydac.mmrbem.radio.common.state.ApplicationConstants;

import javafx.beans.property.SimpleStringProperty;
import javafx.beans.property.StringProperty;

/**
 * A model to get Simulated Date and Time
 * 
 * @author ext-tambet
 *
 */
public class DayDateTimeModel
{

  private final StringProperty day = new SimpleStringProperty(CommonStrings.BLANK);

  private final StringProperty date = new SimpleStringProperty(CommonStrings.BLANK);

  private final StringProperty time = new SimpleStringProperty(CommonStrings.BLANK);

  private final SimpleDateFormat dateFormat = new SimpleDateFormat("dd-MM-yyyy"); //$NON-NLS-1$

  private final SimpleDateFormat dayFormat = new SimpleDateFormat("EEEE", java.util.Locale.ENGLISH); //$NON-NLS-1$

  private final SimpleDateFormat timeFormat = new SimpleDateFormat("HH:mm"); //$NON-NLS-1$

  private Date dateTime = new Date();

  public DayDateTimeModel()
  {
    processDateAndTime();
  }

  private void processDateAndTime()
  {
    dateFormat.setTimeZone(TimeZone.getTimeZone(ApplicationConstants.UTC));
    dayFormat.setTimeZone(TimeZone.getTimeZone(ApplicationConstants.UTC));
    timeFormat.setTimeZone(TimeZone.getTimeZone(ApplicationConstants.UTC));
    DateTimeModel.getSimTimeProperty().addListener((observable, oldValue, newValue) -> {
      dateTime.setTime((long)newValue.doubleValue());
      date.set(dateFormat.format(dateTime));
      time.set(timeFormat.format(dateTime));
      day.set(dayFormat.format(dateTime));
    });

  }

  public StringProperty getDay()
  {
    return day;
  }

  public StringProperty getDate()
  {
    return date;
  }

  public StringProperty getTime()
  {
    return time;
  }

}

package com.sydac.mmrbem.tcms.fe.gui.model;

import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.TimeZone;

import com.sydac.mmrbem.cabscreens.fe.common.DateTimeModel;
import com.sydac.mmrbem.tcms.common.state.ApplicationConstants;

import javafx.beans.property.SimpleStringProperty;
import javafx.beans.property.StringProperty;

public class DayDateTimeModel
{

  private final StringProperty day = new SimpleStringProperty(ApplicationConstants.BLANK_STRING);

  private final StringProperty date = new SimpleStringProperty(ApplicationConstants.BLANK_STRING);

  private final StringProperty feedDate = new SimpleStringProperty(ApplicationConstants.BLANK_STRING);

  private final StringProperty time = new SimpleStringProperty(ApplicationConstants.BLANK_STRING);

  private final SimpleDateFormat dateFormat = new SimpleDateFormat("yyyy-MM-dd"); //$NON-NLS-1$

  private final SimpleDateFormat feedDateFormat = new SimpleDateFormat("MM-dd-yyyy"); //$NON-NLS-1$

  private final SimpleDateFormat dayFormat = new SimpleDateFormat("EEEE", java.util.Locale.ENGLISH); //$NON-NLS-1$

  private final SimpleDateFormat timeFormat = new SimpleDateFormat("HH:mm:ss"); //$NON-NLS-1$

  private Date dateTime = new Date();

  public DayDateTimeModel()
  {
    processDateAndTime();
  }

  private void processDateAndTime()
  {
    feedDateFormat.setTimeZone(TimeZone.getTimeZone(ApplicationConstants.UTC));
    dateFormat.setTimeZone(TimeZone.getTimeZone(ApplicationConstants.UTC));
    dayFormat.setTimeZone(TimeZone.getTimeZone(ApplicationConstants.UTC));
    timeFormat.setTimeZone(TimeZone.getTimeZone(ApplicationConstants.UTC));
    DateTimeModel.getSimTimeProperty().addListener((observable, oldValue, newValue) -> {
      dateTime.setTime((long)newValue.doubleValue());
      feedDate.set(feedDateFormat.format(dateTime));
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

  public StringProperty getfeedDate()
  {
    return feedDate;
  }

  public StringProperty getTime()
  {
    return time;
  }

}

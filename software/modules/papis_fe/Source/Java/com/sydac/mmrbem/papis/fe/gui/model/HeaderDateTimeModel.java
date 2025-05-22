/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.papis.fe.gui.model;

import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.TimeZone;

import com.sydac.mmrbem.cabscreens.fe.common.DateTimeModel;
import com.sydac.mmrbem.cabscreens.fe.gui.model.AbstractScreenModel;

import javafx.beans.property.IntegerProperty;
import javafx.beans.property.SimpleIntegerProperty;
import javafx.beans.property.SimpleStringProperty;
import javafx.beans.property.StringProperty;

public class HeaderDateTimeModel extends AbstractScreenModel
{

  private StringProperty currentTime = new SimpleStringProperty();

  private StringProperty currentDate = new SimpleStringProperty();
  
  private IntegerProperty headerStatusLabelId = new SimpleIntegerProperty();

  private static final String UTC = "UTC"; //$NON-NLS-1$

  private SimpleDateFormat timeFormat = new SimpleDateFormat("HH:mm"); //$NON-NLS-1$

  private SimpleDateFormat dateFormat = new SimpleDateFormat("d MMM yyyy"); //$NON-NLS-1$
  
  private IntegerProperty totalCar = new SimpleIntegerProperty();

  public HeaderDateTimeModel(int carIndex)
  {
    super(carIndex);
    processDateAndTime();
  }

  /**
   * Process date and time fetched from {@link DateTimeModel} and formats it to
   * required format for header panel.
   */
  private void processDateAndTime()
  {
    DateTimeModel.getSimTimeProperty().addListener((observable, oldValue, newValue) -> {
      Date date = new Date((long)newValue.doubleValue());
      timeFormat.setTimeZone(TimeZone.getTimeZone(UTC));
      dateFormat.setTimeZone(TimeZone.getTimeZone(UTC));

      currentTime.set(timeFormat.format(date));
      currentDate.set(dateFormat.format(date));
    });
  }

  public StringProperty getCurrentTime()
  {
    return currentTime;
  }

  public StringProperty getCurrentDate()
  {
    return currentDate;
  }

  public IntegerProperty getHeaderStatusLabelId()
  {
    return headerStatusLabelId;
  }

  public void setHeaderStatusLabelId(Integer headerStatusLabelId)
  {
    this.headerStatusLabelId.set(headerStatusLabelId);
  }

  public void setTotalCar(Integer newValue)
  {
    this. totalCar.set(newValue);
    
  }
  
  public IntegerProperty getTotalCar()
  {
    return totalCar;
  }
}

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

import javafx.beans.property.IntegerProperty;
import javafx.beans.property.SimpleIntegerProperty;
import javafx.beans.property.SimpleStringProperty;
import javafx.beans.property.StringProperty;

/**
 * Class to hold information for available driving mode
 * 
 * @author potdars
 *
 */
public class AvailableDrivingModesDO
{

  /** The driving id */
  private IntegerProperty drivingId = new SimpleIntegerProperty();

  /** The available driving mode name */
  private StringProperty availableDrivingModeName = new SimpleStringProperty();

  public AvailableDrivingModesDO(Integer id, String name)
  {
    drivingId.set(id);
    availableDrivingModeName.set(name);
  }

  /**
   * Gets the available driving mode name
   *
   * @return the available driving mode name
   */
  public String getAvailableDrivingModeName()
  {
    return availableDrivingModeName.get();
  }

  public Integer getDrivingId()
  {
    return drivingId.get();
  }

  public void setDrivingId(Integer id)
  {
    this.drivingId.set(id);
  }

  /**
   * Sets the available driving mode name.
   *
   * @param name
   *          the new available driving mode name
   */
  public void setAvailableDrivingModeName(String name)
  {
    this.availableDrivingModeName.set(name);
  }
}

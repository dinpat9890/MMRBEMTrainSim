/*
 * ==================================================================
 * 
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.tcms.fe.gui.data;

import com.sydac.mmrbem.tcms.fe.gui.state.CCTVCameraId;

import javafx.beans.property.IntegerProperty;
import javafx.beans.property.SimpleIntegerProperty;
import javafx.beans.property.SimpleStringProperty;
import javafx.beans.property.StringProperty;

public class CameraViewButtonDO implements Comparable<CameraViewButtonDO>
{

  /** The button id. */
  private IntegerProperty buttonId = new SimpleIntegerProperty();

  /** The button display name */
  private StringProperty buttonName = new SimpleStringProperty();

  /** The button id. */
  private StringProperty buttonState = new SimpleStringProperty();

  private IntegerProperty associatedView = new SimpleIntegerProperty();

  private IntegerProperty selectedCameraId = new SimpleIntegerProperty();

  private IntegerProperty alarmType = new SimpleIntegerProperty();

  private IntegerProperty selectedVehicleIndex = new SimpleIntegerProperty();

  public Integer getSelectedCameraId()
  {
    return selectedCameraId.get();
  }

  public void setSelectedCameraId(Integer cameraType)
  {
    this.selectedCameraId.set(cameraType);
  }

  public Integer getSelectedVehicleIndex()
  {
    return selectedVehicleIndex.get();
  }

  public void setSelectedVehicleIndex(Integer selectedVehicleIndex)
  {
    this.selectedVehicleIndex.set(selectedVehicleIndex);
  }

  private static final int INIT_HASH_CODE = CameraViewButtonDO.class.getSimpleName().hashCode();

  /**
   * Button id property.
   *
   * @return the integer property
   */
  public IntegerProperty buttonIdProperty()
  {
    return buttonId;
  }

  /**
   * Sets the button id.
   *
   * @param id
   *          the new button id
   */
  public void setButtonId(int id)
  {
    this.buttonId.set(id);
  }

  /**
   * Button display name property.
   *
   * @return the string property
   */
  public StringProperty buttonNameProperty()
  {
    return buttonName;
  }

  /**
   * Sets the button display name.
   *
   * @param buttonName
   *          the new button display name
   */
  public void setButtonName(String buttonName)
  {
    this.buttonName.set(buttonName);
    String[] cameraTypeVehicleIndex = buttonName.split("_"); //$NON-NLS-1$
    if (!(buttonName.equals("")))
    {
      this.setSelectedCameraId(
          (CCTVCameraId.getCameraIdOf((cameraTypeVehicleIndex[0]).toUpperCase())).getCameraEnumId());
      this.setSelectedVehicleIndex((Integer.valueOf(cameraTypeVehicleIndex[1])));
    }
    else
    {
      this.setSelectedCameraId(0);
      this.setSelectedVehicleIndex(0);
    }
  }

  /**
   * Button state property.
   *
   * @return the string property
   */
  public StringProperty buttonStateProperty()
  {
    return buttonState;
  }

  /**
   * Sets the button state.
   *
   * @param state
   *          the new button state
   */
  public void setButtonState(String state)
  {
    this.buttonState.set(state);
  }

  /**
   * Camera associated view property.
   *
   * @return the camera associated view property
   */
  public IntegerProperty cameraAssociatedViewProperty()
  {
    return associatedView;
  }

  public StringProperty getButtonName()
  {
    return buttonName;
  }

  public StringProperty getButtonState()
  {
    return buttonState;
  }

  /**
   * Sets camera associated view id.
   *
   * @param id
   *          the new camera associated view id
   */
  public void setAssociatedView(int id)
  {
    this.associatedView.set(id);
  }

  @Override
  public int compareTo(CameraViewButtonDO arg0)
  {
    return this.buttonId.get() - arg0.buttonId.get();
  }

  @Override
  public int hashCode()
  {
    return INIT_HASH_CODE + buttonId.get();
  }

  public IntegerProperty getAlarmType()
  {
    return alarmType;
  }

  public void setAlarmType(int alarmType)
  {
    this.alarmType.set(alarmType);
  }

  @Override
  public boolean equals(Object obj)
  {
    return this == obj;
  }

}

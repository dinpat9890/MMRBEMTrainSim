package com.sydac.mmrbem.dmi.common.state;

import com.sydac.project.runtimedata.ProjectObjectConstants.TypeValue.DetrainmentDoorStatus;

public enum DMIDetrainmentDoorStatus
{
  DOOR_CLOSED("detrainment-door-closed-status", DetrainmentDoorStatus.DOOR_CLOSED), //$NON-NLS-1$
  DOOR_OPEN("detrainment-door-open-status", DetrainmentDoorStatus.DOOR_OPEN); //$NON-NLS-1$

  private final int value;

  private final String text;

  private DMIDetrainmentDoorStatus(String text, int value)
  {
    this.text = text;
    this.value = value;
  }

  public int getValue()
  {
    return value;
  }

  /**
   * Get text to display
   * 
   * @return text
   */
  public String getText()
  {
    return text;
  }

  public static DMIDetrainmentDoorStatus valueOf(int intValue)
  {
    for (DMIDetrainmentDoorStatus i : values())
    {
      if (i.getValue() == intValue)
      {
        return i;
      }
    }
    throw new IllegalArgumentException("Invalid value for DMIDetrainmentDoorStatus:" + intValue); //$NON-NLS-1$
  }
}

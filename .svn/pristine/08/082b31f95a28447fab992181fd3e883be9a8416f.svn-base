package com.sydac.mmrbem.tcms.common.state;

/**
 * This enum provides the different modes for the header panel driving mode
 * label
 **/

public enum DrivingModeEnum
{
  OFF("OFF", 0), //$NON-NLS-1$
  UTO("UTO", 1), //$NON-NLS-1$
  ATO("ATO", 2), //$NON-NLS-1$
  ATP("ATP", 3), //$NON-NLS-1$
  ROS("ROS", 4), //$NON-NLS-1$
  RMF("RMF", 5), //$NON-NLS-1$
  ATC_BYPASS("ATC BYPASS", 6), //$NON-NLS-1$
  RMR("RMR", 7), //$NON-NLS-1$
  ATB("ATB", 8), //$NON-NLS-1$
  STANDBY("STANDBY", 9); //$NON-NLS-1$

  private final int value;

  private final String text;

  DrivingModeEnum(String text, int value)
  {
    this.text = text;
    this.value = value;
  }

  public int getValue()
  {
    return value;
  }

  public String getText()
  {
    return text;
  }

  public static DrivingModeEnum valueOf(int intValue)
  {
    for (DrivingModeEnum i : values())
    {
      if (i.getValue() == intValue)
      {
        return i;
      }
    }
    throw new IllegalArgumentException("Invalid value for Driving Mode:" + intValue); //$NON-NLS-1$
  }

}

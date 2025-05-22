package com.sydac.mmrbem.dmi.common.state;

import com.sydac.project.runtimedata.ProjectObjectConstants.TypeValue.ATPZoneStatus;

public enum DMIATPZoneStatus
{
  OTHERWISE("otherwise-atp-zone-status", ATPZoneStatus.OTHERWISE), // $NON-NLS-1
  NON_ATP_ZONE("non-atp-zone-status", ATPZoneStatus.NON_ATP_ZONE), // $NON-NLS-1
  ABOUT_TO_LEAVE_ATP_ZONE("about-to-leave-atp-zone-status", ATPZoneStatus.ABOUT_TO_LEAVE_ATP_ZONE); // $NON-NLS-1

  private final int value;

  private final String text;

  private DMIATPZoneStatus(String text, int value)
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

  public static DMIATPZoneStatus valueOf(int intValue)
  {
    for (DMIATPZoneStatus i : values())
    {
      if (i.getValue() == intValue)
      {
        return i;
      }
    }
    throw new IllegalArgumentException("Invalid value for DMIATPZoneStatus : " + intValue); //$NON-NLS-1$
  }
}

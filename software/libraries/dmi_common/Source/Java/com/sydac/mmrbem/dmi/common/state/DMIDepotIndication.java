package com.sydac.mmrbem.dmi.common.state;

import com.sydac.project.runtimedata.ProjectObjectConstants.TypeValue.DepotIndication;

public enum DMIDepotIndication
{
  NO_DISPLAY("no-display", DepotIndication.NO_DISPLAY), // $NON-NLS-1
  DEPOT("depot-indication", DepotIndication.DEPOT); // $NON-NLS-1

  private final int value;

  private final String text;

  private DMIDepotIndication(String text, int value)
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

  public static DMIDepotIndication valueOf(int intValue)
  {
    for (DMIDepotIndication i : values())
    {
      if (i.getValue() == intValue)
      {
        return i;
      }
    }
    throw new IllegalArgumentException("Invalid value for DMIDepotIndication : " + intValue); //$NON-NLS-1$
  }
}

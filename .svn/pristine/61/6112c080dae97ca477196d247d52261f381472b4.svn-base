package com.sydac.mmrbem.tcms.common.state;

/**
 * This enum provides the different modes for the header panel driving mode
 * label
 **/

public enum PabrStateEnum
{
  BLACK(0,"not_active"), //$NON-NLS-1$
  GREEN(1,"active"), //$NON-NLS-1$
  GREY(2,"not_known"); //$NON-NLS-1$


  private final int value;

  private final String css;

  PabrStateEnum( int value, String text)
  {
    this.value = value;
    this.css = text;
   
  }

  public int getValue()
  {
    return value;
  }

  public String getCss()
  {
    return css;
  }

  public static PabrStateEnum valueOf(int intValue)
  {
    for (PabrStateEnum i : values())
    {
      if (i.getValue() == intValue)
      {
        return i;
      }
    }
    throw new IllegalArgumentException("Invalid value for Driving Mode:" + intValue); //$NON-NLS-1$
  }

}

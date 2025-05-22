package com.sydac.mmrbem.tcms.common.state;

public enum KeyPadEnum
{
  NO_0("0", 0), //$NON-NLS-1$
  NO_1("1", 1), //$NON-NLS-1$
  NO_2("2", 2), //$NON-NLS-1$
  NO_3("3", 3), //$NON-NLS-1$
  NO_4("4", 4), //$NON-NLS-1$
  NO_5("5", 5), //$NON-NLS-1$
  NO_6("6", 6), //$NON-NLS-1$
  NO_7("7", 7), //$NON-NLS-1$
  NO_8("8", 8), //$NON-NLS-1$
  NO_9("9", 9), //$NON-NLS-1$
  DELETE("Delete", 10), //$NON-NLS-1$
  CLEAR("Clear", 11), //$NON-NLS-1$
  ENTER("Enter", 12); //$NON-NLS-1$
 
  
  private final int value;

  private final String text;

  private KeyPadEnum(String text, int value)
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

  public static KeyPadEnum valueOf(int intValue)
  {
    for (KeyPadEnum i : values())
    {
      if (i.getValue() == intValue)
      {
        return i;
      }
    }
    return null;
  }
}

package com.sydac.mmrbem.tcms.common.state;

public enum OperatingModeEnum
{
  OFF("OFF", 0), //$NON-NLS-1$
  POWER_ON("POWER ON", 1), //$NON-NLS-1$
  WAKEUP("WAKEUP", 2), //$NON-NLS-1$
  RUNNING("RUNNING", 3), //$NON-NLS-1$
  POWER_SAVING("POWER SAVING", 4), //$NON-NLS-1$
  EXTERNAL_SOCKET("EXTERNAL SOCKET", 5), //$NON-NLS-1$
  DOZING_MODE("DOZING MODE", 6), //$NON-NLS-1$
  SLEEPING("SLEEPING", 7), //$NON-NLS-1$
  RUN_NOT_READY("RUN NOT \n  READY", 8), //$NON-NLS-1$
  RUN_READY("RUN READY", 9), //$NON-NLS-1$
  RUN_UTO("RUN UTO", 10), //$NON-NLS-1$
  RUN_ATO("RUN ATO", 11), //$NON-NLS-1$
  RUN_ATB("RUN ATB", 12), //$NON-NLS-1$
  RUN_ATP("RUN ATP", 13), //$NON-NLS-1$
  RUN_RMF("RUN RMF", 14), //$NON-NLS-1$
  RUN_RMR("RUN RMR", 15), //$NON-NLS-1$
  RUN_TCBYP("RUN TCBYP", 16), //$NON-NLS-1$
  RUN_STANDBY("RUN STANDBY", 17), //$NON-NLS-1$
  RUN_WASH("RUN WASH", 18), //$NON-NLS-1$
  RUN_SPEEDCUT("RUN SPEEDCUT", 19), //$NON-NLS-1$
  RUN_THE("RUN THE", 20), //$NON-NLS-1$
  RUN_HOSTLER("RUN HOSTLER", 21);//$NON-NLS-1$

  private final int value;

  private final String text;

  private OperatingModeEnum(String text, int value)
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

  public static OperatingModeEnum valueOf(int intValue)
  {
    for (OperatingModeEnum i : values())
    {
      if (i.getValue() == intValue)
      {
        return i;
      }
    }
    throw new IllegalArgumentException("Invalid value for Operating Mode:" + intValue); //$NON-NLS-1$
  }
}

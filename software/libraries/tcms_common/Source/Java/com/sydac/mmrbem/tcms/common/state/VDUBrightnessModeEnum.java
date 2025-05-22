package com.sydac.mmrbem.tcms.common.state;

public enum VDUBrightnessModeEnum
{
  BRIGHTNESS_AUTO(5, "AUTO"), BRIGHTNESS_20(0, "20%"), BRIGHTNESS_40(1, "40%"), BRIGHTNESS_60(2, //$NON-NLS-1$ //$NON-NLS-2$ //$NON-NLS-3$
      "60%"), BRIGHTNESS_80(3, "80%"), BRIGHTNESS_100(4, "100%"); //$NON-NLS-1$ //$NON-NLS-2$ //$NON-NLS-3$

  private final int id;

  private final String brightnessMode;

  VDUBrightnessModeEnum(int id, String brightnessMode)
  {
    this.id = id;
    this.brightnessMode = brightnessMode;
  }

  public int getId()
  {
    return id;
  }

  public String getBrightnessMode()
  {
    return brightnessMode;
  }
}

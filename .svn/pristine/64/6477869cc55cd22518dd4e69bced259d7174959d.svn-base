/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.tcms.common.state;

public enum TCMSModeEnum
{
  AUTO(1, "TCMS AUTO", "mode-auto-selected"), SEMI_AUTO(2, "SEMI AUTO", "mode-semi-auto-selected"), MANUAL(3, //$NON-NLS-1$ //$NON-NLS-2$ //$NON-NLS-3$ //$NON-NLS-4$
      "MANUAL", "mode-manual-selected"); //$NON-NLS-1$ //$NON-NLS-2$

  private final int modeId;

  private final String modeName;

  private final String modeCssClass;

  TCMSModeEnum(int modeId, String modeName, String modeCssClass)
  {
    this.modeId = modeId;
    this.modeName = modeName;
    this.modeCssClass = modeCssClass;
  }

  public int getModeId()
  {
    return modeId;
  }

  public String getModeName()
  {
    return modeName;
  }

  public String getModeCssClass()
  {
    return modeCssClass;
  }

  public static TCMSModeEnum valueOf(int intValue)
  {
    for (TCMSModeEnum i : values())
    {
      if (i.getModeId() == intValue)
      {
        return i;
      }
    }
    return null;
  }
}

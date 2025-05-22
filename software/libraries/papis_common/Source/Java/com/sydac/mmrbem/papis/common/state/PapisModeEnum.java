/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.papis.common.state;

public enum PapisModeEnum
{
  AUTO(1, "Auto", "mode-auto-selected"), SEMI_AUTO(2, "Semi-auto", "mode-semi-auto-selected"), MANUAL(3, //$NON-NLS-1$ //$NON-NLS-2$ //$NON-NLS-3$ //$NON-NLS-4$
      "Manual", "mode-manual-selected"); //$NON-NLS-1$ //$NON-NLS-2$

  private final int modeId;

  private final String modeName;

  private final String modeCssClass;

  PapisModeEnum(int modeId, String modeName, String modeCssClass)
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

  public static PapisModeEnum valueOf(int intValue)
  {
    for (PapisModeEnum i : values())
    {
      if (i.getModeId() == intValue)
      {
        return i;
      }
    }
    return null;
  }
}

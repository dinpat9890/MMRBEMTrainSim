/*
 * ==================================================================
 *
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *
 * ==================================================================
 */
package com.sydac.mmrbem.psd.fe.common;

import com.sydac.mmrbem.cabscreens.fe.common.IFrontend;

public enum Frontend implements IFrontend
{
  TCMS("tcms", "TCMS"), CCTV("cctv", "CCTV"); //$NON-NLS-1$ //$NON-NLS-2$ //$NON-NLS-3$ //$NON-NLS-4$

  private final String key;

  private final String displayName;

  private Frontend(String key, String displayName)
  {
    this.key = key;
    this.displayName = displayName;
  }

  /**
   * @return the key
   */
  public String getKey()
  {
    return key;
  }

  @Override
  public String toString()
  {
    return displayName;
  }
}

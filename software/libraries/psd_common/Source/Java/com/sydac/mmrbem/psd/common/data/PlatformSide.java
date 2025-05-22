/*
 * ==================================================================
 * 
 * 
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.psd.common.data;

/**
 * PlatformSide represent the platform side
 * 
 * @author ext-jadhalp
 *
 */
public enum PlatformSide
{
  INVALID(-1), LEFT(1), RIGHT(2);
  private int value;

  private PlatformSide(final int aValue)
  {
    value = aValue;
  }

  public static PlatformSide getStatusOf(int aValue)
  {
    for (PlatformSide status : values())
    {
      if (status.value == aValue)
      {
        return status;
      }
    }
    return null;
  }

  public int getValue()
  {
    return value;
  }
  
}

/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.tcms.common.utils;

import java.text.SimpleDateFormat;
import java.util.Date;

public class UnitConverterHelper
{
  private UnitConverterHelper()
  {
    // helper class
  }

  public static String convertTime(long time)
  {
    Date date = new Date(time);
    SimpleDateFormat format = new SimpleDateFormat("yyyy/MM/dd HH:mm:ss"); //$NON-NLS-1$
    return format.format(date);
  }

  public static int convertNToKN(int value)
  {
    return value / 1000;
  }

  public static float getWeightInTon(float weight)
  {
    return weight / 1000;
  }

  public static float convertPascalToBar(float value)
  {
    return value / 100000;
  }
}

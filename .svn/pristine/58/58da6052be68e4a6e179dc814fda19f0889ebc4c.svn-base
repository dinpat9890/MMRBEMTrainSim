/*******************************************************************************
 * (C) Copyright 2016 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.dmi.common.utils;

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
    SimpleDateFormat format = new SimpleDateFormat("dd/MM/yyyy  HH:mm:ss");
    return format.format(date);
  }

}

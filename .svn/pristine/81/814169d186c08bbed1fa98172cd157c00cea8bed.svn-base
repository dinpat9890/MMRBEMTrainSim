/*
 * ==================================================================
 * 
 * 
 * (C) Copyright 2020 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.dmi.common.state;
import com.sydac.project.runtimedata.ProjectObjectConstants.TypeValue.LocalisationStatus;
/**
 * This enum for DMILocalisationStatus
 * 
 * @author potdars
 *
 */
public enum DMILocalisationStatus
{

  UNAVAILABLE("localisation-unavailable",LocalisationStatus.UNAVAILABLE), // $NON-NLS-1
  ATC_NOT_LOCALIZED("atc-not-localised",LocalisationStatus.NOT_LOCALISED), // $NON-NLS-1
  ATC_LOCALIZED("atc-localised", LocalisationStatus.LOCALISED), // $NONNLS-1
  ATC_MEMORISED_LOCALISATION("atc-memorised-localised", LocalisationStatus.MEMORISED_LOCALISATION); // $NON-NLS-1

  private final int value;

  private final String text;

  private DMILocalisationStatus(String text, int value)
  {    
	this.text = text;
    this.value = value;
  }


  public int getValue()
  {
    return value;
  }

  /**
   * Get text to display
   * 
   * @return text
   */
  public String getText()
  {
    return text;
  }

  public static DMILocalisationStatus valueOf(int intValue)
  {
    for (DMILocalisationStatus i : values())
    {
      if (i.getValue() == intValue)
      {
        return i;
      }
    }
    throw new IllegalArgumentException("Invalid value for DMILocalisationStatus:" + intValue); //$NON-NLS-1$
  }

}


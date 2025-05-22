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

import com.sydac.project.runtimedata.ProjectObjectConstants.TypeValue.CurrentDrivingMode;

/**
 * This enum for DrivingModeStatus
 * 
 * @author mulukg
 *
 */

public enum DrivingModeStatus
{

  UNAVAILABLE("driving-mode-unavailable", "driving-mode-unavailable", "driving-mode-unavailable", //$NON-NLS-1$ //$NON-NLS-2$ //$NON-NLS-3$
      "speedo-meter-img", CurrentDrivingMode.NO_MODE), // $NON-NLS-1 //$NON-NLS-1$
  ATP_MODE("driving-mode-unavailable", "driving-mode-unavailable", "driving-mode-atp-available", //$NON-NLS-1$ //$NON-NLS-2$ //$NON-NLS-3$
      "speedo-meter-img", CurrentDrivingMode.ATP), // $NON-NLS-1 //$NON-NLS-1$
  RMF_MODE("driving-mode-unavailable", "driving-mode-unavailable", "driving-mode-rm-available", //$NON-NLS-1$ //$NON-NLS-2$ //$NON-NLS-3$
      "speedo-meter-img-rmf", CurrentDrivingMode.RMF), // $NON-NLS-1 //$NON-NLS-1$
  RMR_MODE("driving-mode-unavailable", "driving-mode-unavailable", "driving-mode-rm-available", //$NON-NLS-1$ //$NON-NLS-2$ //$NON-NLS-3$
      "speedo-meter-img-rmr", CurrentDrivingMode.RMR), // $NON-NLS-1 //$NON-NLS-1$
  ATO_MODE("driving-mode-unavailable", "driving-mode-unavailable", "driving-mode-ato-available", //$NON-NLS-1$ //$NON-NLS-2$ //$NON-NLS-3$
      "speedo-meter-img", CurrentDrivingMode.ATO), // $NON-NLS-1 //$NON-NLS-1$
  ATB_MODE("driving-mode-unavailable", "driving-mode-unavailable", "driving-mode-atb-available", //$NON-NLS-1$ //$NON-NLS-2$ //$NON-NLS-3$
      "speedo-meter-img", CurrentDrivingMode.ATB), // $NON-NLS-1 //$NON-NLS-1$
  ROS_MODE("driving-mode-unavailable", "driving-mode-unavailable", "driving-mode-ros-available", //$NON-NLS-1$ //$NON-NLS-2$ //$NON-NLS-3$
      "speedo-meter-img-ros", CurrentDrivingMode.ROS), // $NON-NLS-1 //$NON-NLS-1$
  UTO_MODE("driving-mode-unavailable", "driving-mode-unavailable", "driving-mode-uto-available", //$NON-NLS-1$ //$NON-NLS-2$ //$NON-NLS-3$
      "speedo-meter-img", CurrentDrivingMode.UTO), // $NON-NLS-1 //$NON-NLS-1$
  ATC_ENABLED_MODE("atc-bypass-speed-dial", "atc-bypass-speed-dial", "atc-bypass-speed-dial", //$NON-NLS-1$ //$NON-NLS-2$ //$NON-NLS-3$
      "atc-bypass-speed-dial", -99); // $NON-NLS-1 //$NON-NLS-1$

  private final int value;

  private final String unAvailableStateCSS;

  private final String defaultCSS;

  private final String selectedCSS;

  private final String speedDialCss;

  private DrivingModeStatus(String unAvailableStateCSS, String defaultCSS, String selectedCSS,
      String speedDialCss, int value)
  {
    this.unAvailableStateCSS = unAvailableStateCSS;
    this.defaultCSS = defaultCSS;
    this.selectedCSS = selectedCSS;
    this.value = value;
    this.speedDialCss = speedDialCss;
  }

  public int getValue()
  {
    return value;
  }

  public String getDefaultCSS()
  {
    return defaultCSS;
  }

  public String getSelectedCSS()
  {
    return selectedCSS;
  }

  public String getSpeedDialCss()
  {
    return speedDialCss;
  }

  public String getUnAvailableStateCSS()
  {
    return unAvailableStateCSS;
  }

  public static DrivingModeStatus valueOf(int intValue)
  {
    for (DrivingModeStatus i : values())
    {
      if (i.getValue() == intValue)
      {
        return i;
      }
    }
    throw new IllegalArgumentException("Invalid value for DrivingModeStatus:" + intValue); //$NON-NLS-1$
  }

}

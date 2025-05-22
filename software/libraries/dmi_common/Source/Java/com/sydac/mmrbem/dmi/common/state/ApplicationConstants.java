package com.sydac.mmrbem.dmi.common.state;
/*
 * ==================================================================
 * 
 * (C) Copyright 2020 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */

/**
 * This class will be used for common constants
 * 
 */
public class ApplicationConstants
{
  // we will be doing the code cleanup to remove all the variables which are not
  // used
  public static final String BLANK = ""; //$NON-NLS-1$

  public static final String SPACE = " "; //$NON-NLS-1$

  public static final String APP_NAME = "DMI"; //$NON-NLS-1$

  public static final String FRAME_TITLE_PREFIX = APP_NAME + " - Car # "; //$NON-NLS-1$

  public static final String HUB_DOMAIN = "hub";//$NON-NLS-1$

  public static final String HUB_NAME_PROPERTY = "hubName";//$NON-NLS-1$

  public static final String SIM_NAME_PROPERTY = "simName";//$NON-NLS-1$

  public static final String DOMAIN_NAME = "dmi"; //$NON-NLS-1$

  public static final String CREATOR_ID_KEY = "creatorId"; //$NON-NLS-1$

  public static final String TRAIN_ID_KEY = "trainId"; //$NON-NLS-1$

  public static final String SERVICE_NUMBER = "serviceNumber";//$NON-NLS-1$

  public static final String SOFTWARE_VERSION = "softwareVersion";//$NON-NLS-1$

  public static final String STRATUP_SCREEN_TIME = "startupScreenDisplayTime"; //$NON-NLS-1$

  public static final String NEW_MESSAGE_INDICATION_DURATION = "newMessageIndicationDuration"; //$NON-NLS-1$

  public static final String ACK_DISABLE_DURATION = "ackDisableDuration"; //$NON-NLS-1$

  public static final String PROGRESS_BAR_COUNTER_STATES = "progressBarCounterStates"; //$NON-NLS-1$

  public static final String WIDTH = "width"; //$NON-NLS-1$

  public static final String HEIGHT = "height"; //$NON-NLS-1$

  public static final int BRIGHTNESS_MAX_VALUE = 5;

  public static final int BRIGHTNESS_MIN_VALUE = 0;

  public static final Double DEFAULT_APP_WIDTH = 1024.0;// $NON-NLS-1$

  public static final Double DEFAULT_APP_HEIGHT = 768.0;// $NON-NLS-1$

  public static final Double MENU_GRID_LAYOUT_X = 575.0;

  public static final Double CREW_GRID_LAYOUT_X = 575.0;

  public static final Double AREA_A_LAYOUT_X = 50.0;

  public static final Double AREA_A_LAYOUT_Y = 35.0;

  public static final String PIS_STATION_LIST_PATH = "pisFolderPath"; //$NON-NLS-1$

  private ApplicationConstants()
  {
    // constant class
  }

}

package com.sydac.mmrbem.papis.common.state;
/*
 * ==================================================================
 * 
 * (C) Copyright 2020 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */

import com.sydac.common.registry.Registry;

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

  public static final String APP_NAME = "PAPIS"; //$NON-NLS-1$

  public static final String FRAME_TITLE_PREFIX = APP_NAME + " - Car # "; //$NON-NLS-1$

  public static final String HUB_DOMAIN = "hub";//$NON-NLS-1$

  public static final String HUB_NAME_PROPERTY = "hubName";//$NON-NLS-1$

  public static final String SIM_NAME_PROPERTY = "simName";//$NON-NLS-1$

  public static final String DOMAIN_NAME = "papis"; //$NON-NLS-1$

  public static final String CREATOR_ID_KEY = "creatorId"; //$NON-NLS-1$

  public static final String TRAIN_ID_KEY = "trainId"; //$NON-NLS-1$

  public static final String USER_ID = "userId"; //$NON-NLS-1$

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

  public static final int DIGIT_LENGTH = 5;

  public static final int TWO_SECOND = 2;

  public static final String DOOR_OPEN = "Open"; //$NON-NLS-1$

  public static final String DOOR_CLOSE = "Close"; //$NON-NLS-1$

  public static final String MODE_UNSELECTED = "mode-unselected-label"; //$NON-NLS-1$

  public static final String DIRECTION_UNSELECTED = "train-direction-unselected"; //$NON-NLS-1$

  public static final String DIRECTION_SELECTED = "train-direction-selected"; //$NON-NLS-1$

  public static final int UP_PRESSED = 1;

  public static final int DOWN_PRESSED = 1;

  public static final int OK_PRESSED = 1;

  public static final int BACK_PRESSED = 1;

  public static final int STOP_ANNOUNCEMENT = 1;

  public static final String LINE_OPTIONS_UNSELECTED_CSS = "line-options-label"; //$NON-NLS-1$

  public static final String LINE_OPTIONS_SELECTED_CSS = "line-options-label-selected"; //$NON-NLS-1$

  public static final String OPTIONS_UNSELECTED_CSS = "station-options-label"; //$NON-NLS-1$

  public static final String OPTIONS_SELECTED_CSS = "station-options-label-selected"; //$NON-NLS-1$

  public static final String NO_LINE = "No Line"; //$NON-NLS-1$

  public static final String STATION_LIST_OPTIONS_UNSELECTED_CSS = "skip-options-unselected"; //$NON-NLS-1$

  public static final String STATION_LIST_OPTIONS_SELECTED_CSS = "skip-options-selected"; //$NON-NLS-1$

  public static final String SELECTED_CSS = "selected"; //$NON-NLS-1$

  public static final String UNSELECTED_CSS = "unselected"; //$NON-NLS-1$

  public static final String ID_UNSELECTED_CSS = "button-default"; //$NON-NLS-1$

  public static final String ID_SELECTED_CSS = "button-default-selected"; //$NON-NLS-1$

  public static final int PASSENGER_CALLING = 2;

  public static final int CALL_REQUEST = 1;

  public static final int CALL_CONNECTED = 2;

  public static final int CALL_TYPE_OHP = 2;

  public static final int CALL_TYPE_CTC = 3;

  public static final String RIGHT_ARROW_UNSELECTED_CSS = "skip-screen-right-arrow"; //$NON-NLS-1$

  public static final String RIGHT_ARROW_SELECTED_CSS = "skip-screen-right-arrow-selected"; //$NON-NLS-1$

  public static final String LEFT_ARROW_UNSELECTED_CSS = "skip-screen-left-arrow-btn"; //$NON-NLS-1$

  public static final String LEFT_ARROW_SELECTED_CSS = "skip-screen-left-arrow-btn-selected"; //$NON-NLS-1$

  public static final int PLAY = 1;

  public static final int SET_VALUE = 1;

  public static final int RESET_VALUE = 0;

  public static final int RESET_SELECTED_INDEX = 0;

  public static final boolean IS_TOUCH_ENABLED = Registry.getInstance().getBoolean("gui", "istouchenabled", //$NON-NLS-1$ //$NON-NLS-2$
      false);

  public static final String PIS_STATION_LIST_PATH = "pisFolderPath"; //$NON-NLS-1$

  public static final int PECU_CALL_CONNECTED = 3;

  public static final String PECU_CONNECTED_CSS = "connected"; //$NON-NLS-1$

  public static final String PECU_DISCONNECTED_CSS = "disconnected"; //$NON-NLS-1$

  public static final int NO_PECU_ID_SELECTED = 0;

  public static final int MULTIPLE_PECU_CALL_ID = 40;

  public static final String PECU_ALARM_UNSELECTED_CSS = "unselected"; //$NON-NLS-1$

  public static final String PECU_ALARM_SELECTED_CSS = "selected"; //$NON-NLS-1$

  public static final String PECU_ALARM_DEFAULT_CSS = "default"; //$NON-NLS-1$

  private ApplicationConstants()
  {
    // constant class
  }

}

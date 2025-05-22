package com.sydac.mmrbem.tcms.common.state;
/*
 * ==================================================================
 * 
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
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

  public static final String TCMS_APP_NAME = "TCMS"; //$NON-NLS-1$

  public static final String CCTV_APP_NAME = "CCTV"; //$NON-NLS-1$

  public static final String TCMS_FRAME_TITLE_PREFIX = TCMS_APP_NAME + " - Car # "; //$NON-NLS-1$

  public static final String CCTV_FRAME_TITLE_PREFIX = CCTV_APP_NAME + " - Car # "; //$NON-NLS-1$

  public static final String HUB_DOMAIN = "hub";//$NON-NLS-1$

  public static final String HUB_NAME_PROPERTY = "hubName";//$NON-NLS-1$

  public static final String SIM_NAME_PROPERTY = "simName";//$NON-NLS-1$

  public static final String DOMAIN_NAME = "tcms"; //$NON-NLS-1$

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

  public static final String TRAIN_SET_NUMBER = "001"; //$NON-NLS-1$

  public static final String LINE_IDENTIFICATION = "7"; //$NON-NLS-1$

  public static final String NOT_APPLICABLE_CSS = "not-applicable"; //$NON-NLS-1$

  public static final int VALUE_NOT_APPLICABLE = -99;

  public static final int SIX_CAR_CONFIG = 6;

  public static final int EIGHT_CAR_CONFIG = 8;

  public static final String SELECTED_PSEUDO_CLASS = "selected"; //$NON-NLS-1$

  public static final String UNSELECTED_PSEUDO_CLASS = "unselected"; //$NON-NLS-1$

  public static final String INACTIVE_PSUEDO_CLASS = "inactive"; //$NON-NLS-1$

  public static final String BLANK_STRING = ""; //$NON-NLS-1$

  public static final String UTC = "UTC"; //$NON-NLS-1$

  public static final String C_LOCATION_LABEL = "C:"; //$NON-NLS-1$

  public static final String N_LOCATION_LABEL = "N:"; //$NON-NLS-1$

  public static final int DOUBLE_CLICK = 2;

  public static final String SPLASH_SCREEN_TIME = "powerUpSplashScreenTime"; //$NON-NLS-1$

  public static final String BLUE_SCREEN_TIME = "powerUpDataLoadingScreenTime"; //$NON-NLS-1$

  public static final String DOOR_LEFT = "Left"; //$NON-NLS-1$

  public static final String DOOR_CLOSE = "Close"; //$NON-NLS-1$

  public static final String DOOR_OPEN = "Open"; //$NON-NLS-1$

  public static final String STATION_DETAIL_NO_DATA = "--"; //$NON-NLS-1$

  public static final String EVENT_INI_FILE_PATH = "../Environment/Event.ini"; //$NON-NLS-1$

  public static final String EVENT_ID = "EventId "; //$NON-NLS-1$

  public static final String FAULT_ID = "FaultId"; //$NON-NLS-1$

  public static final String FAULT_SYSTEM = "FaultSystem"; //$NON-NLS-1$

  public static final String FAULT_DESCRIPTION = "FaultDescription"; //$NON-NLS-1$

  public static final String FAULT_LEVEL = "FaultLevel"; //$NON-NLS-1$

  public static final String FAULT_COMPONENET = "FaultComponent"; //$NON-NLS-1$

  public static final String OPERATOR_GUIDANCE = "OperatorGuidance"; //$NON-NLS-1$

  public static final String FAULT_VEHICLE_ID = "FaultVehicleId"; //$NON-NLS-1$

  public static final String STAND_BY_SCREEN_TIME = "standByScreenTime";//$NON-NLS-1$

  public static final String ALARM_IS_ACTIVE = "active";//$NON-NLS-1$

  public static final String ALARM_IS_NOT_ACTIVE = "not_active";//$NON-NLS-1$

  public static final int ACTIVE = 1;

  public static final String HVAC_MODE_OK_CSS = "hvac_ok"; //$NON-NLS-1$
  
  public static final String HVAC_CONTROL_MODE_AUTO_CSS = "hvac_auto"; //$NON-NLS-1$
  
  public static final String HVAC_DAMPER_CSS = "damper_status"; //$NON-NLS-1$

  public static final int AK_STATE_OPEN = 0;

  public static final int AK_STATE_CLOSED = 1;

  public static final int K_STATE_OPEN = 0;

  public static final int K_STATE_CLOSED = 1;

  public static final int T4_EIGHT_CAR_CONFIG = 3;

  public static final int T5_SIX_CAR_CONFIG = 4;

  public static final int T7_EIGHT_CAR_CONFIG = 6;

  public static final int T2_EIGHT_AND_SIX_CAR_CONFIG = 1;

  public static final boolean IS_TOUCH_ENABLED = Registry.getInstance().getBoolean("gui", "istouchenabled", //$NON-NLS-1$ //$NON-NLS-2$
      false);

  public static final int USER_ID_LENGTH = 5;

  public static final String VEHICLE = "VEHICLE"; //$NON-NLS-1$

  public static final String STATION_LIST_PATH = "pisFolderPath"; //$NON-NLS-1$

  public static final String TEST_DATA_PATH = "testScreenDataPath"; //$NON-NLS-1$

  public static final String EXT_CAM_1 = "DMC1-ECAM1"; //$NON-NLS-1$

  public static final String EXT_CAM_2 = "DMC1-ECAM2"; //$NON-NLS-1$

  public static final String EXT_CAM_3 = "DMC1-ECAM3"; //$NON-NLS-1$

  public static final String EXT_CAM_4 = "DMC1-ECAM4"; //$NON-NLS-1$

  public static final String EXT_CAM_5 = "MC2-ECAM1"; //$NON-NLS-1$

  public static final String EXT_CAM_6 = "MC2-ECAM2"; //$NON-NLS-1$

  public static final String EXT_CAM_7 = "MC2-ECAM3"; //$NON-NLS-1$

  public static final String EXT_CAM_8 = "MC2-ECAM4"; //$NON-NLS-1$

  public static final String INT_CAM_1 = "DMC1-SCAM1"; //$NON-NLS-1$

  public static final String INT_CAM_2 = "DMC1-SCAM2"; //$NON-NLS-1$

  public static final String INT_CAM_3 = "DMC1-SCAM3"; //$NON-NLS-1$

  public static final String INT_CAM_4 = "DMC1-SCAM4"; //$NON-NLS-1$

  public static final String INT_CAM_5 = "MC2-SCAM1"; //$NON-NLS-1$

  public static final String INT_CAM_6 = "MC2-SCAM2"; //$NON-NLS-1$

  public static final String INT_CAM_7 = "MC2-SCAM3"; //$NON-NLS-1$

  public static final String INT_CAM_8 = "MC2-SCAM4"; //$NON-NLS-1$

  public static final String INT_CAM_9 = "TC3-SCAM1"; //$NON-NLS-1$

  public static final String INT_CAM_10 = "TC3-SCAM2"; //$NON-NLS-1$

  public static final String INT_CAM_11 = "TC3-SCAM3"; //$NON-NLS-1$

  public static final String INT_CAM_12 = "TC3-SCAM4"; //$NON-NLS-1$

  public static final String NO_LINE = " - "; //$NON-NLS-1$

  public static final String DMC1_DCAM = "DMC1-DCAM"; //$NON-NLS-1$

  public static final String DMC6_DCAM = "DMC6-DCAM"; //$NON-NLS-1$

  public static final String DMC8_DCAM = "DMC8-DCAM"; //$NON-NLS-1$

  public static final String DETRANMENT_DOOR_OPEN_CSS = "detrainment_door_open"; //$NON-NLS-1$

  public static final String TRANSPARENT_CSS = "transparent_grid"; //$NON-NLS-1$
  
  public static final String PECU_RESET_DISABLE_CSS = "button-reset-disable"; //$NON-NLS-1$

  public static final String PECU_RESET_ENABLE_CSS = "button-reset-enable"; //$NON-NLS-1$

  public static final int RESET_VALUE = 0;
  public static final int SET_VALUE = 1;

  public static final int TRAIN_UNDER_EVAC = 303; //$NON-NLS-1$
  public static final int TRAIN_OUT_OF_SERVICE = 301; //$NON-NLS-1$
  public static final int DELAY_IN_SERVICE = 306; //$NON-NLS-1$
  public static final int TRAIN_HOLD =302;

  private ApplicationConstants()
  {
    // constant class
  }

}

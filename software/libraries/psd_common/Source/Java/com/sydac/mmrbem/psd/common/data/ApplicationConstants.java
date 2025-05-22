package com.sydac.mmrbem.psd.common.data;
/*
 * ==================================================================
 * 
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
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

  public static final String PSD_APP_NAME = "PSD"; //$NON-NLS-1$
  public static final String LEFT_PSD_APP_NAME = "LEFT PSD"; //$NON-NLS-1$

  public static final String RIGHT_PSD_APP_NAME = "RIGHT PSD"; //$NON-NLS-1$


  public static final String PSD_FRAME_TITLE_PREFIX = PSD_APP_NAME + " - Car # "; //$NON-NLS-1$

  public static final String HUB_DOMAIN = "hub";//$NON-NLS-1$

  public static final String HUB_NAME_PROPERTY = "hubName";//$NON-NLS-1$

  public static final String SIM_NAME_PROPERTY = "simName";//$NON-NLS-1$

  public static final String DOMAIN_NAME = "psd"; //$NON-NLS-1$

  public static final String CREATOR_ID_KEY = "creatorId"; //$NON-NLS-1$

  public static final String TRAIN_ID_KEY = "trainId"; //$NON-NLS-1$

  public static final String USER_ID = "userId"; //$NON-NLS-1$

  public static final String WIDTH = "width"; //$NON-NLS-1$

  public static final String HEIGHT = "height"; //$NON-NLS-1$

  public static final int BRIGHTNESS_MAX_VALUE = 5;

  public static final int BRIGHTNESS_MIN_VALUE = 0;

  public static final int DIGIT_LENGTH = 5;

  public static final int TWO_SECOND = 2;

  public static final String NOT_APPLICABLE_CSS = "not-applicable"; //$NON-NLS-1$

  public static final int VALUE_NOT_APPLICABLE = -99;

  public static final int SIX_CAR_CONFIG = 6;

  public static final int EIGHT_CAR_CONFIG = 8;

  public static final String SELECTED_PSEUDO_CLASS = "selected"; //$NON-NLS-1$

  public static final String UNSELECTED_PSEUDO_CLASS = "unselected"; //$NON-NLS-1$

  public static final String INACTIVE_PSUEDO_CLASS = "inactive"; //$NON-NLS-1$

  public static final String BLANK_STRING = ""; //$NON-NLS-1$

  public static final String UTC = "UTC"; //$NON-NLS-1$

  public static final String PLATFORM_SIDE = "platformSide"; 
  
  public static final int PSD_OPENING = 3;
  public static final int PSD_CLOSING = 5;
  public static final int PSD_FAULT = 6;
  public static final int PSD_OPENED = 4;
  public static final int PSD_CLOSED = 2;
  
  public static final int CORRECTLY_DOCKED=1;
  
  public static final String LIT_PSEUDO_CLASS = "lit"; //$NON-NLS-1$

  public static final String UNLIT_PSEUDO_CLASS = "unlit"; //$NON-NLS-1$
  
  public static final int SET_VALUE = 1;

  public static final int RESET_VALUE = 0;

  private ApplicationConstants()
  {
    // constant class
  }

}

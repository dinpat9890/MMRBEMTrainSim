/*
 * ==================================================================
 * 
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */

package com.sydac.mmrbem.tcms.common.state;

public enum BackNavigationScreenEnum
{
  OPERATING_SCREEN(5, 5),
  OPERATING_HELP_SCREEN(6, 5),
  VDU_SETTINGS_POPUP(7, 0),
  VDU_SELECTION_POPUP(8, 0),
  FOOTER_SUBMENU_POPUP(9, 0),
  PROPULSION_SYSTEM_SCREEN(10, 5),
  DOOR_SYSTEM_SCREEN(11, 5),
  BATTERY_SYSTEM_SCREEN(12, 5),
  APS_SYSTEM_SCREEN(13, 5),
  BRAKE_SYSTEM_SCREEN(14, 5), 
  FIRE_DETECTION_SYSTEM_STATUS_SCREEN(15, 5), 
  HVAC_SYSTEM_STATUS_SCREEN(16, 5), 
  WHEEL_FLANG_LUBRICATOR_SYSTEM_STATUS_SCREEN(17, 5), 
  ACTIVE_FAULTS_SCREEN(18, 5), 
  FAULT_DETAILS_SCREEN(19, 18), 
  LIGHT_SYSTEM_STATUS_SCREEN(20, 5), 
  LOW_VOLTAGE_SYSTEM_COMMAND_SCREEN(21, 35), 
  ENERGY_CONSUMPTION_COUNTERS_SCREEN(22, 5),
  ROUTE_SCREEN(23, 5),
  ODOMETER_SCREEN(24, 5),
  FIRE_SYSTEM_TEST_SCREEN(25, 5),
  BRAKE_SYSTEM_TEST_SCREEN(26, 5),
  DOOR_SYSTEM_TEST_SCREEN(27, 5),
  HVAC_SYSTEM_TEST_SCREEN(28, 5),
  PIS_SYSTEM_TEST_SCREEN(29, 5),
  BATTERY_SYSTEM_TEST_SCREEN(30, 5),
  SYSTEM_TEST_SCREEN(31, 5),
  HIGH_VOLTAGE_SYSTEM_SCREEN(32, 5),
  LOW_VOLTAGE_SYSTEM_SCREEN(35, 5),
  REMOTE_IO_SCREEN(36, 5),
  EVENT_RECORDERS_SCREEN(37, 5),
  SOFTWARE_VERSION_SCREEN(38, 5),
  TCMS_ECN_SCREEN(39, 5),
  SYSTEM_STATUS_SCREEN(40, 5),
  MEDIUM_VOLTAGE_SYSTEM_SCREEN(41, 5),
  SPEED_LIMIT_SCREEN(42, 5),
  PANTO_INTERLOCK_SCREEN(43, 5),
  VCB_INTERLOCK_SCREEN(44, 5),
  EB_INTERLOCK_SCREEN(45, 5),
  DOOR_LOOP_INTERLOCKS_SCREEN(46, 5),
  PROPULSION_TEMPERATURES_SCREEN(48, 10),
  SPECIAL_MODES_SCREEN(49, 10),
  BRAKE_SYSTEM_COMMANDS_SCREEN(50, 14), 
  DOORS_SYTEM_COMMANDS_SCREEN(51, 11),
  MISCELLANIA_SCREEN(52, 5),
  LOGIN_PANEL(3, 0),
  LOGIN_PANEL_POPUP(4, 0),
  HV_COMMANDS_SCREEN(53,32),
  HVAC_COMMANDS_SCREEN(61, 16), 
  HVAC_TEMPRETURE_SCREEN(59, 16),
  PIS_SYSTEM_SCREEN(60,5 ),
  ENABLERUN_INTERLOCK_SCREEN(58, 5),
  BRAKE_LOOP_INTERLOCKS_SCREEN(55, 5),
  SKIP_STTAION_SCREEN(62, 23),
  REMOTE_CB_COMMANDS_SCREEN(57,21);
  private final int currentScreenId;

  private final int backScreenId;

  private BackNavigationScreenEnum(int currentScreenId, int backScreenId)
  {
    this.currentScreenId = currentScreenId;
    this.backScreenId = backScreenId;
  }

  public int getCurrentScreenId()
  {
    return currentScreenId;
  }

  public int getBackScreenId()
  {
    return backScreenId;
  }

  public static int backToScreenId(int currentId)
  {
    int navigateToScreenId = 0;
    for (BackNavigationScreenEnum screenIdEnum : BackNavigationScreenEnum.values())
    {
      if (screenIdEnum.getCurrentScreenId() == currentId)
      {
        navigateToScreenId = screenIdEnum.getBackScreenId();
      }
    }
    return navigateToScreenId == 0 ? currentId : navigateToScreenId;
  }

}

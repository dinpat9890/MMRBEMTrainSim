/*
 * ==================================================================
 *
 * (C) Copyright 2020 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *
 * ==================================================================
 */
package com.sydac.mmrbem.tcms.common;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 * All Screens in TCMS will be associated with a ScreenId. The entities /
 * generalizations in the front-end and back-end will operate using ScreenIds.
 * <br>
 *
 * @author ext-vp
 */
public enum ScreenId
{
  BLANK_SCREEN(0, "BlankScreen", ""), //$NON-NLS-1$ //$NON-NLS-2$
  STARTUP_SCREEN(1, "StartupScreen", ""), //$NON-NLS-1$ //$NON-NLS-2$
  DATA_LOADING_SCREEN(2, "DataLoadingScreen", ""), //$NON-NLS-1$ //$NON-NLS-2$
  LOGIN_PANEL(3, "LoginPanel", ""), //$NON-NLS-1$ //$NON-NLS-2$
  LOGIN_PANEL_POPUP(4, "LoginPanelPopup", ""), //$NON-NLS-1$ //$NON-NLS-2$
  OPERATING_SCREEN(5, "OperatingScreen", "OPERATING SCREEN"), //$NON-NLS-1$ //$NON-NLS-2$
  OPERATING_HELP_SCREEN(6, "OperatingHelpScreen", "OPERATING SCREEN"), //$NON-NLS-1$ //$NON-NLS-2$
  VDU_SETTINGS_POPUP(7, "VduSettingsPopup", ""), //$NON-NLS-1$ //$NON-NLS-2$
  VDU_SELECTION_POPUP(8, "VduSelectionPopup", ""), //$NON-NLS-1$ //$NON-NLS-2$
  FOOTER_SUBMENU_POPUP(9, "FooterSubmenuPopup", ""), //$NON-NLS-1$ //$NON-NLS-2$
  PROPULSION_SYSTEM_SCREEN(10, "PropulsionSystemScreen", "PROPULSION SYSTEM"), //$NON-NLS-1$ //$NON-NLS-2$
  DOOR_SYSTEM_SCREEN(11, "DoorSystemScreen", "DOOR SYSTEM"), //$NON-NLS-1$ //$NON-NLS-2$
  BATTERY_SYSTEM_SCREEN(12, "BatterySystemScreen", "BATTERY SYSTEM"), //$NON-NLS-1$ //$NON-NLS-2$
  APS_SYSTEM_SCREEN(13, "APSSystemScreen", "APS SYSTEM"), //$NON-NLS-1$ //$NON-NLS-2$
  BRAKE_SYSTEM_SCREEN(14, "BrakeSystemScreen", "BRAKE SYSTEM"), //$NON-NLS-1$//$NON-NLS-2$
  FIRE_DETECTION_SYSTEM_STATUS_SCREEN(15, "FireDetectionSystemStatusScreen", "FIRE DETECTION SYSTEM"), //$NON-NLS-1$//$NON-NLS-2$
  HVAC_SYSTEM_STATUS_SCREEN(16, "HVACSystemStatusScreen", "HVAC SYSTEM"), //$NON-NLS-1$//$NON-NLS-2$
  WHEEL_FLANG_LUBRICATOR_SYSTEM_STATUS_SCREEN(17, "WheelFlangeLubricatorSystemStatusScreen", "WFL SYSTEM"), //$NON-NLS-1$//$NON-NLS-2$
  ACTIVE_FAULTS_SCREEN(18, "ActiveFaultsScreen", "ACTIVE FAULTS"), //$NON-NLS-1$//$NON-NLS-2$
  FAULT_DETAILS_SCREEN(19, "FaultDetailsScreen", "FAULT DETAILS"), //$NON-NLS-1$//$NON-NLS-2$
  LIGHT_SYSTEM_STATUS_SCREEN(20, "LightSystemStatusScreen", "LIGHT SYSTEM"), //$NON-NLS-1$//$NON-NLS-2$
  LOW_VOLTAGE_SYSTEM_COMMAND_SCREEN(21, "LowVoltageSystemCommandScreen", "LOW VOLTAGE SYSTEM COMMANDS"), //$NON-NLS-1$//$NON-NLS-2$
  ENERGY_CONSUMPTION_COUNTERS_SCREEN(22, "EnergyConsumptionCountersScreen", //$NON-NLS-1$
      "Energy Consumption Counters \n Screen"), //$NON-NLS-1$
  ROUTE_SCREEN(23, "RouteScreen", "Route Screen"), //$NON-NLS-1$ //$NON-NLS-2$
  ODOMETER_SCREEN(24, "OdometerScreen", "Odometer Screen"), //$NON-NLS-1$ //$NON-NLS-2$
  FIRE_SYSTEM_TEST_SCREEN(25, "FireSystemTestScreen", "FDU Detail Test Screen"), //$NON-NLS-1$ //$NON-NLS-2$
  BRAKE_SYSTEM_TEST_SCREEN(26, "BrakeSystemTestScreen", "System BCU Detail Test Screen"), //$NON-NLS-1$ //$NON-NLS-2$
  DOOR_SYSTEM_TEST_SCREEN(27, "DoorSystemTestScreen", "System DOORS Detail Test Screen"), //$NON-NLS-1$ //$NON-NLS-2$
  HVAC_SYSTEM_TEST_SCREEN(28, "HVACSystemTestScreen", "HVAC Detail Test Screen"), //$NON-NLS-1$ //$NON-NLS-2$
  PIS_SYSTEM_TEST_SCREEN(29, "PISSystemTestScreen", "PIS Detail Test Screen"), //$NON-NLS-1$ //$NON-NLS-2$
  BATTERY_SYSTEM_TEST_SCREEN(30, "BatterySystemTestScreen", "System Battery Detail Test Screen"), //$NON-NLS-1$ //$NON-NLS-2$
  SYSTEM_TEST_SCREEN(31, "SystemTestScreen", "System Test Screen"), //$NON-NLS-1$ //$NON-NLS-2$
  HIGH_VOLTAGE_SYSTEM_SCREEN(32, "HighVoltageSystemScreen", "HIGH VOLTAGE SYSTEM"), //$NON-NLS-1$ //$NON-NLS-2$
  CCTV_SINGLE_FEED_SCREEN(33, "CCTVSingleFeedScreen", "CCTV Screen"), //$NON-NLS-1$ //$NON-NLS-2$
  CCTV_FOUR_FEED_SCREEN(34, "CCTVFourFeedScreen", "CCTV Screen"), //$NON-NLS-1$ //$NON-NLS-2$
  LOW_VOLTAGE_SYSTEM_SCREEN(35, "LowVoltageSystemScreen", "LOW VOLTAGE SYSTEM"), //$NON-NLS-1$ //$NON-NLS-2$
  REMOTE_IO_SCREEN(36, "RemoteIOScreen", "TCMS REMOTE IO"), //$NON-NLS-1$ //$NON-NLS-2$
  EVENT_RECORDERS_SCREEN(37, "EventRecordersScreen", "TCMS EVENT RECORDERS"), //$NON-NLS-1$ //$NON-NLS-2$
  SOFTWARE_VERSION_SCREEN(38, "SoftwareVersionScreen", "BASELINE SOFTWARE VERSIONS"), //$NON-NLS-1$ //$NON-NLS-2$
  TCMS_ECN_SCREEN(39, "TCMSEthernetConsistNetworkScreen", "  TCMS ETHERNET CONSIST    NETWORK"), //$NON-NLS-1$ //$NON-NLS-2$
  SYSTEM_STATUS_SCREEN(40, "SystemStatusScreen", "TCMS SYSTEM"), //$NON-NLS-1$ //$NON-NLS-2$
  MEDIUM_VOLTAGE_SYSTEM_SCREEN(41, "MediumVoltageSystemScreen", "MEDIUM VOLTAGE SYSTEM"), //$NON-NLS-1$ //$NON-NLS-2$
  SPEED_LIMIT_SCREEN(42, "SpeedLimitInterlockScreen", "Speed Limitation Interlocks Screen"), //$NON-NLS-1$ //$NON-NLS-2$
  PANTO_INTERLOCK_SCREEN(43, "PantoInterlockScreen", "Panto Interlocks Screen"), //$NON-NLS-1$ //$NON-NLS-2$
  VCB_INTERLOCK_SCREEN(44, "VcbInterlockScreen", "VCB Interlocks Screen"), //$NON-NLS-1$ //$NON-NLS-2$
  EB_INTERLOCK_SCREEN(45, "EmergencyBrakeInterlockScreen", "EB Loop Interlocks Screen"), //$NON-NLS-1$ //$NON-NLS-2$
  DOOR_LOOP_INTERLOCKS_SCREEN(46, "DoorLoopInterlocksScreen", "DOORS Loop Interlocks Screen"), //$NON-NLS-1$ //$NON-NLS-2$
  CCTV_HYBRID_MODE_COMMON_SCREEN(47, "CCTVHybridModeCommonScreen", ""), //$NON-NLS-1$ //$NON-NLS-2$
  PROPULSION_TEMPERATURES_SCREEN(48, "PropulsionTemperaturesScreen", "TEMPERATURES"), //$NON-NLS-1$ //$NON-NLS-2$
  SPECIAL_MODES_SCREEN(49, "SpecialModesScreen", "SPECIAL MODES"), //$NON-NLS-1$ //$NON-NLS-2$
  BRAKE_SYSTEM_COMMANDS_SCREEN(50, "BrakeSystemCommandsScreen", "BRAKES SYSTEM COMMANDS"), //$NON-NLS-1$//$NON-NLS-2$
  DOORS_SYTEM_COMMANDS_SCREEN(51, "DoorSystemCommandsScreen", "DOORS SYSTEM COMMANDS"), //$NON-NLS-1$ //$NON-NLS-2$
  MISCELLANIA_SCREEN(52, "MiscellaniaScreen", "MISCELLANEA"), //$NON-NLS-1$ //$NON-NLS-2$
  HV_COMMANDS_SCREEN(53, "HVSystemCommandScreen", "HIGH VOLTAGE SYSTEM COMMANDS"), //$NON-NLS-1$ //$NON-NLS-2$
  LOGGED_FAULTS_SCREEN(54, "LoggedFaultsScreen", "LOGGED FAULTS"), //$NON-NLS-1$ //$NON-NLS-2$
  BRAKE_LOOP_INTERLOCKS_SCREEN(55, "BrakeLoopInterlockScreen", "Brake loop Interlocks Screen"), //$NON-NLS-1$ //$NON-NLS-2$
  MEDIUM_VOLTAGE_COMMANDS_SCREEN(56, "MediumVoltageSystemCommandScreen", "MEDIUM VOLTAGE SYSTEM COMMANDS"), //$NON-NLS-1$ //$NON-NLS-2$
  REMOTE_CB_COMMANDS_SCREEN(57, "RemoteCBCommandScreen", "REMOTE CBs COMMANDS"), //$NON-NLS-1$ //$NON-NLS-2$
  ENABLERUN_INTERLOCK_SCREEN(58, "EnableToRunInterlockScreen", "ENABLE TO RUN Interlocks Screen"),
  HVAC_TEMPRETURE_SCREEN(59, "HVACSystemTempretureScreen", "HVAC SYSTEM Temperatures"), //$NON-NLS-1$//$NON-NLS-2$//$NON-NLS-1$ //$NON-NLS-2$
  PIS_SYSTEM_SCREEN(60, "PISSystemStatusScreen", "PIS SYSTEM"),
  HVAC_COMMANDS_SCREEN(61, "HVACCommandScreen", "HVAC SYSTEM COMMANDS"), 
  SKIP_STATION_SCREEN(62, "SkipStationScreen", "Skip Stations Screen"),
  FIRE_DECTECTION_SYSTEM_DETAILS_SCREEN(63, "FireDetectionSystemDetailsScreen", "Fire Detection System Details Screen"),
  FDS_DETAILS_SCREEN_OTHER_CARS(64, "FDSDetailScreenOtherCars", "Fire Detection System Details Screen"); 
  // Always add new screens to the end

  private static final Map<Integer, ScreenId> mappedByValue = new HashMap<>();

  private static final List<ScreenId> fullScreenMap = new ArrayList<>();

  static
  {
    // Avoid duplicate values (which is a risk, since they are assigned
    // manually)
    for (ScreenId screenId : values())
    {
      if (mappedByValue.put(screenId.id, screenId) != null)
      {
        throw new IllegalArgumentException("Value " + screenId.id + " has already been assigned!"); //$NON-NLS-1$ //$NON-NLS-2$
      }
    }

    fullScreenMap.add(BLANK_SCREEN);
    fullScreenMap.add(STARTUP_SCREEN);
    fullScreenMap.add(DATA_LOADING_SCREEN);
    fullScreenMap.add(LOGIN_PANEL);
    fullScreenMap.add(LOGIN_PANEL_POPUP);
    fullScreenMap.add(VDU_SELECTION_POPUP);
    fullScreenMap.add(VDU_SETTINGS_POPUP);
    fullScreenMap.add(FOOTER_SUBMENU_POPUP);
    fullScreenMap.add(CCTV_FOUR_FEED_SCREEN);
    fullScreenMap.add(CCTV_SINGLE_FEED_SCREEN);
    fullScreenMap.add(CCTV_HYBRID_MODE_COMMON_SCREEN);
  }

  // The unique id for this screen.
  private final int id;

  // name of screen. Usually this should match with the screen fxml name
  private final String screenName;

  // Title of the screen. Displayed as title in the header title area.
  private final String screenTitle;

  /*
   * Constructs ScreenId
   */
  private ScreenId(int id, String screenName, String screenTitle)
  {
    this.id = id;
    this.screenName = screenName;
    this.screenTitle = screenTitle;
  }

  /**
   * Accessor for filed <code>id</code>
   *
   * @return The id of this screen
   */
  public int getId()
  {
    return id;
  }

  /**
   * Accessor for field<code>name</code>
   *
   * @return The name of car screen.
   */
  public String getScreenName()
  {
    return screenName;
  }

  /**
   * Accessor for field<code>name</code>
   *
   * @return The header title of the current screen.
   */
  public String getScreenTitle()
  {
    return screenTitle;
  }

  /**
   * Returns the {@link ScreenId} associated with this <code>id</code>
   *
   * @param id
   *          The id to find the associated {@link ScreenId}
   * @return The ScreenId
   */
  public static ScreenId valueOf(int id)
  {
    return mappedByValue.get(id);
  }

  /**
   * Check if given screen is full screen<br>
   * Note: Full screen means screen without Header and footer panel.
   *
   * @param screenName
   *          screen name
   *
   * @return true if supply screen is full screen
   */
  public static boolean isFullScreen(String screenName)
  {
    return fullScreenMap.stream().anyMatch(screenId -> screenId.getScreenName().equalsIgnoreCase(screenName));
  }

}

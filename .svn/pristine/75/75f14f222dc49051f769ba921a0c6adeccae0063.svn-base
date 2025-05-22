/*
 * ==================================================================
 *
 * (C) Copyright 2020 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *
 * ==================================================================
 */
package com.sydac.mmrbem.papis.common;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 * All Screens in TCMS will be associated with a ScreenId. The entities /
 * generalizations in the front-end and back-end will operate using ScreenIds.
 * <br>
 *
 */
public enum ScreenId
{
  BLANK_SCREEN(0, "BlankScreen", ""), //$NON-NLS-1$ //$NON-NLS-2$
  MAIN_INTERFACE_SCREEN(1, "MainInterfaceScreen", ""), //$NON-NLS-1$ //$NON-NLS-2$
  SYSTEM_SETTINGS_SCREEN(2, "SystemSettingsScreen", ""), //$NON-NLS-1$ //$NON-NLS-2$
  ROUTE_SETTINGS_SCREEN(3, "RouteSettingScreen", ""), //$NON-NLS-1$ //$NON-NLS-2$
  START_STATION_SELECTION_SCREEN(4, "StartStationSelectionScreen", ""), //$NON-NLS-1$ //$NON-NLS-2$
  TERMINAL_STATION_SELECTION_SCREEN(5, "TerminalStationSelectionScreen", ""), //$NON-NLS-1$ //$NON-NLS-2$
  NEXT_STATION_SELECTION_SCREEN(6, "NextStationSelectionScreen", ""), //$NON-NLS-1$ //$NON-NLS-2$
  SKIP_STATION_SETTING_SCREEN(7, "SkipStationSettingScreen", ""), //$NON-NLS-1$ //$NON-NLS-2$
  MANUAL_MODE_SETTING_SCREEN(8, "ManualModeSettingScreen", ""), //$NON-NLS-1$ //$NON-NLS-2$
  PASSENGER_ALARM_SCREEN(9, "PassengerAlarmScreen", ""), //$NON-NLS-1$ //$NON-NLS-2$
  SPECIAL_INFORMATION_SCREEN(10, "SpecialInformationScreen", ""), //$NON-NLS-1$ //$NON-NLS-2$
  EMERGENCY_INFORMATION_SCREEN(11, "EmergencyInformationScreen", ""), //$NON-NLS-1$ //$NON-NLS-2$
  TRAIN_ID_SETTING_SCREEN(12, "TrainIdSettingScreen", ""), //$NON-NLS-1$ //$NON-NLS-2$
  LANGUAGE_SETTING_SCREEN(13, "LanguageSettingScreen", ""), //$NON-NLS-1$ //$NON-NLS-2$
  VOLUME_SETTING_SCREEN(14, "VolumeSettingScreen", ""), //$NON-NLS-1$ //$NON-NLS-2$
  FAULT_SCREEN(15, "PapisFaultScreen", ""), //$NON-NLS-1$ //$NON-NLS-2$
  PECU_ISOLATE_SCREEN(16, "PecuIsolateScreen", ""); //$NON-NLS-1$ //$NON-NLS-2$

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

/*
 * ==================================================================
 *
 * (C) Copyright 2020 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *
 * ==================================================================
 */
package com.sydac.mmrbem.dmi.common;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 * All Screens in DMI will be associated with a ScreenId. The entities /
 * generalizations in the front-end and back-end will operate using ScreenIds.
 * <br>
 *
 */
public enum ScreenId
{
  BLANK_SCREEN(0, "BlankScreen"), //$NON-NLS-1$ //$NON-NLS-2$
  STARTUP_SCREEN(1, "StartupScreen"), //$NON-NLS-1$ //$NON-NLS-2$
  SCREEN_SAVER_SCREEN(2, "ScreenSaverScreen"), //$NON-NLS-1$ //$NON-NLS-2$
  MAIN_SCREEN(3, "MainScreen");//$NON-NLS-1$ //$NON-NLS-2$
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
    fullScreenMap.add(SCREEN_SAVER_SCREEN);
  }

  // The unique id for this screen.
  private final int id;

  // name of screen. Usually this should match with the screen fxml name
  private final String screenName;

  /*
   * Constructs ScreenId
   */
  private ScreenId(int id, String screenName)
  {
    this.id = id;
    this.screenName = screenName;
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

/*
 * ==================================================================
 *
 * (C) Copyright 2020 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *
 * ==================================================================
 */
package com.sydac.mmrbem.radio.common;

import java.util.HashMap;
import java.util.Map;

import com.sydac.mmrbem.radio.common.utils.DuplicateScreenIdException;

/**
 * All Screens in TCMS will be associated with a ScreenId. The entities /
 * generalizations in the front-end and back-end will operate using ScreenIds.
 * <br>
 *
 */
public enum ScreenId
{
  BLANK_SCREEN(0, "BlankScreen", ""), //$NON-NLS-1$ //$NON-NLS-2$
  STARTUP_SCREEN_1(1, "StartupScreen1", ""), //$NON-NLS-1$ //$NON-NLS-2$
  STARTUP_SCREEN_2(2, "StartupScreen2", ""), //$NON-NLS-1$ //$NON-NLS-2$
  STARTUP_SCREEN_3(3, "StartupScreen3", ""), //$NON-NLS-1$ //$NON-NLS-2$
  MAIN_SCREEN(4, "MainScreen", "Main Screen"), //$NON-NLS-1$ //$NON-NLS-2$
  MESSAGE_SCREEN(5, "MessageMainScreen", "Message Screen"), //$NON-NLS-1$ //$NON-NLS-2$
  CONTACT_SCREEN(6, "ContactsScreen", "Contact Screen"), //$NON-NLS-1$ //$NON-NLS-2$
  ALARM_SCREEN(7, "AlarmScreen", "Alarm Screen"), //$NON-NLS-1$ //$NON-NLS-2$
  MESSAGE_INBOX_LIST_SCREEN(8, "MessageInBoxListScreen", "Message Inbox Screen"), //$NON-NLS-1$ //$NON-NLS-2$
  MESSAGE_OUTBOX_LIST_SCREEN(9, "MessageOutBoxListScreen", "Message Outbox Screen"), //$NON-NLS-1$ //$NON-NLS-2$
  INBOX_MESSAGE_SCREEN(10, "MessageInBoxScreen", "Message Inbox Screen"), //$NON-NLS-1$ //$NON-NLS-2$
  OUTBOX_MESSAGE_SCREEN(11, "MessageOutBoxScreen", "Message Outbox Screen"), //$NON-NLS-1$ //$NON-NLS-2$
  VOLUME_SCREEN(12, "VolumeScreen", "Volume Screen"); //$NON-NLS-1$ //$NON-NLS-2$
  // Always add new screens to the end

  private static final Map<Integer, ScreenId> mappedByValue = new HashMap<>();

  static
  {
    // Avoid duplicate values (which is a risk, since they are assigned
    // manually)
    for (ScreenId screenId : values())
    {
      if (mappedByValue.put(screenId.id, screenId) != null)
      {
        throw new DuplicateScreenIdException("Value " + screenId.id + " has already been assigned!"); //$NON-NLS-1$ //$NON-NLS-2$
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

}

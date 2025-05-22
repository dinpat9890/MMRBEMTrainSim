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

public enum FooterSubmenuPopupEnum
{
  BLANK(0, "", "Level 1"), //$NON-NLS-1$ //$NON-NLS-2$
  SYSTEMS_BUTTON_POPUP(1, "subsystemsGrid", "Level 1"), //$NON-NLS-1$ //$NON-NLS-2$
  INTERLOCKS_BUTTON_POPUP(2, "interlocksGrid", "Level 1"), //$NON-NLS-1$ //$NON-NLS-2$
  FAULTS_BUTTON_POPUP(3, "faultsGrid", "Level 1"), //$NON-NLS-1$ //$NON-NLS-2$
  TESTS_BUTTON_POPUP(4, "testsGrid", "Level 1"), //$NON-NLS-1$ //$NON-NLS-2$
  COUNTERS_BUTTON_POPUP(5, "countersGrid", "Level 1"), //$NON-NLS-1$ //$NON-NLS-2$
  TCMS_BUTTON_POPUP(6, "tcmsSubmenuGrid", "Level 2"), //$NON-NLS-1$ //$NON-NLS-2$
  PERFORMANE_BUTTON_POPUP(7, "performanceSubmenuGrid", "Level 2"), //$NON-NLS-1$ //$NON-NLS-2$
  MAINTAINCE_BUTTON_POPUP(8, "testSubmenuGrid", "Level 2"); //$NON-NLS-1$ //$NON-NLS-2$ testSubmenuGrid

  private final int id;

  private final String gridName;

  private final String level;

  FooterSubmenuPopupEnum(int id, String gridName, String level)
  {
    this.id = id;
    this.gridName = gridName;
    this.level = level;
  }

  public int getId()
  {
    return id;
  }

  public String getGridName()
  {
    return gridName;
  }

  public String getLevel()
  {
    return level;
  }

  public static String valueOfLevel(int value)
  {
    for (FooterSubmenuPopupEnum i : values())
    {
      if (i.getId() == (value))
      {
        return i.level;
      }
    }

    throw new IllegalArgumentException("Invalid value for Footer Submenu Level:" + value); //$NON-NLS-1$
  }
}

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

public enum ActiveFaultsPriorityFilterEnum
{
  ANY(0, "any", "ANY PRIORITY"), //$NON-NLS-1$ //$NON-NLS-2$
  PRIOPRITY_1(1, "1", "PRIORITY: 1"), //$NON-NLS-1$ //$NON-NLS-2$
  PRIOPRITY_2(2, "2", "PRIORITY: 2"), //$NON-NLS-1$ //$NON-NLS-2$
  PRIOPRITY_3(3, "3", "PRIORITY: 3"), //$NON-NLS-1$ //$NON-NLS-2$
  PRIOPRITY_4(4, "4", "PRIORTIY: 4"), //$NON-NLS-1$ //$NON-NLS-2$
  PRIOPRITY_5(5, "5", "PRIORITY: 5"); //$NON-NLS-1$ //$NON-NLS-2$

  private final int priorityFilterId;

  private final String priorityName;

  private final String appliedFilterString;

  ActiveFaultsPriorityFilterEnum(int priorityFilterId, String priorityName, String appliedFilterString)
  {
    this.priorityFilterId = priorityFilterId;
    this.priorityName = priorityName;
    this.appliedFilterString = appliedFilterString;
  }

  public int getPriorityFilterId()
  {
    return priorityFilterId;
  }

  public String getPriorityName()
  {
    return priorityName;
  }

  public String getAppliedFilterString()
  {
    return appliedFilterString;
  }

  public static ActiveFaultsPriorityFilterEnum valueOf(int intValue)
  {
    for (ActiveFaultsPriorityFilterEnum i : values())
    {
      if (i.getPriorityFilterId() == intValue)
      {
        return i;
      }
    }
    return null;
  }
}

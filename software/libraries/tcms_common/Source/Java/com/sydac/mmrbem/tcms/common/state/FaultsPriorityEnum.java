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

public enum FaultsPriorityEnum
{
ANY_PRIORITY(0, "any_priority"), //$NON-NLS-1$
PRIORITY_1(1, "priority_1"), //$NON-NLS-1$
PRIORITY_2(2, "priority_2"); //$NON-NLS-1$

  private final int priorityId;
  private final String priorityCssName;
  
FaultsPriorityEnum(int priorityId, String priorityCssName)
{
  this.priorityId = priorityId;
  this.priorityCssName = priorityCssName;
}

public int getPriorityId()
{
  return priorityId;
}

public String getPriorityCssName()
{
  return priorityCssName;
}

public static FaultsPriorityEnum valueOf(int intValue)
{
  for (FaultsPriorityEnum i : values())
  {
    if (i.getPriorityId() == intValue)
    {
      return i;
    }
  }
  return null;
}

}

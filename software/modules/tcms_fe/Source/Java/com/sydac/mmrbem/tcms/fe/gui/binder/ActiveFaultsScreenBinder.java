/*
 * ==================================================================
 * 
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.tcms.fe.gui.binder;

import com.sydac.foundation.PropertyKey;
import com.sydac.mmrbem.tcms.common.io.properties.IAppOutputsActiveFaultsScreenProperties;
import com.sydac.mmrbem.tcms.fe.base.AbstractCommsListener;
import com.sydac.mmrbem.tcms.fe.gui.model.ActiveFaultsScreenModel;

public class ActiveFaultsScreenBinder extends AbstractCommsListener
{

  private ActiveFaultsScreenModel activeFaultsScreenModel;

  public ActiveFaultsScreenBinder(ActiveFaultsScreenModel activeFaultsScreenModel)
  {
    super();
    this.activeFaultsScreenModel = activeFaultsScreenModel;
    propertyKeyDefinitions.add(IAppOutputsActiveFaultsScreenProperties.class);
  }

  @Override
  protected <T> void appOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue)
  {
    if (IAppOutputsActiveFaultsScreenProperties.ACTIVE_FAULTS_STATUS.equals(key))
    {
      activeFaultsScreenModel.setActiveFaultsList((byte[])newValue);
    }
    else if (IAppOutputsActiveFaultsScreenProperties.NO_OF_ACTIVE_FAULTS_PAGE.equals(key))
    {
      activeFaultsScreenModel.setTotalPageNumber((Integer)newValue);
    }
    else if (IAppOutputsActiveFaultsScreenProperties.CURRENT_ACTIVE_FAULTS_PAGE.equals(key))
    {
      activeFaultsScreenModel.setCurrentPageNumber((Integer)newValue);
    }
    else if (IAppOutputsActiveFaultsScreenProperties.ACTIVE_FAULT_LIST_UPDATED.equals(key))
    {
      activeFaultsScreenModel.setFaultListUpdateAvailable((Integer)newValue);
    }
    else if (IAppOutputsActiveFaultsScreenProperties.ACTIVE_FAULTS_TOTAL_LIST_COUNT.equals(key))
    {
      activeFaultsScreenModel.setTotalActiveFaults((Integer)newValue);
    }
    else if (IAppOutputsActiveFaultsScreenProperties.ACTIVE_FAULT_PAGE_UP_ACTIVE.equals(key))
    {
      activeFaultsScreenModel.setPageUpActive((Integer)newValue);
    }
    else if (IAppOutputsActiveFaultsScreenProperties.ACTIVE_FAULT_PAGE_DOWN_ACTIVE.equals(key))
    {
      activeFaultsScreenModel.setPageDownActive((Integer)newValue);
    }
    else if (IAppOutputsActiveFaultsScreenProperties.ACTIVE_FAULT_SYS_FILTER_APPLIED.equals(key))
    {
      activeFaultsScreenModel.setAppliedSystemFilterId((Integer)newValue);
    }
    else if (IAppOutputsActiveFaultsScreenProperties.ACTIVE_FAULT_CAR_FILTER_APPLIED.equals(key))
    {
      activeFaultsScreenModel.setAppliedCarFilterId((Integer)newValue);
    }
    else if (IAppOutputsActiveFaultsScreenProperties.ACTIVE_FAULT_PRIORITY_FILTER_APPLIED.equals(key))
    {
      activeFaultsScreenModel.setAppliedPriorityFilterId((Integer)newValue);
    }
  }
}

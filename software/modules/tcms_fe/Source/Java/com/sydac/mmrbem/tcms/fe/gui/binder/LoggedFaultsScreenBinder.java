/*
 * ==================================================================
 * 
 * (C) Copyright 2023 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.tcms.fe.gui.binder;

import com.sydac.foundation.PropertyKey;
import com.sydac.mmrbem.tcms.common.io.properties.IAppOutputsLoggedFaultsScreenProperties;
import com.sydac.mmrbem.tcms.fe.base.AbstractCommsListener;
import com.sydac.mmrbem.tcms.fe.gui.model.LoggedFaultsScreenModel;

public class LoggedFaultsScreenBinder extends AbstractCommsListener
{

  private LoggedFaultsScreenModel loggedFaultsScreenModel;

  public LoggedFaultsScreenBinder(LoggedFaultsScreenModel loggedFaultsScreenModel)
  {
    super();
    this.loggedFaultsScreenModel = loggedFaultsScreenModel;
    propertyKeyDefinitions.add(IAppOutputsLoggedFaultsScreenProperties.class);
  }

  @Override
  protected <T> void appOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue)
  {
    if (IAppOutputsLoggedFaultsScreenProperties.LOGGED_FAULTS_STATUS.equals(key))
    {
      loggedFaultsScreenModel.setLoggedFaultsList((byte[])newValue);
    }
    else if (IAppOutputsLoggedFaultsScreenProperties.NO_OF_LOGGED_FAULTS_PAGE.equals(key))
    {
      loggedFaultsScreenModel.setTotalPageNumber((Integer)newValue);
    }
    else if (IAppOutputsLoggedFaultsScreenProperties.CURRENT_LOGGED_FAULTS_PAGE.equals(key))
    {
      loggedFaultsScreenModel.setCurrentPageNumber((Integer)newValue);
    }
    else if (IAppOutputsLoggedFaultsScreenProperties.LOGGED_FAULTS_TOTAL_LIST_COUNT.equals(key))
    {
      loggedFaultsScreenModel.setTotalActiveFaults((Integer)newValue);
    }
    else if (IAppOutputsLoggedFaultsScreenProperties.LOGGED_FAULT_PAGE_UP_ACTIVE.equals(key))
    {
      loggedFaultsScreenModel.setPageUpActive((Integer)newValue);
    }
    else if (IAppOutputsLoggedFaultsScreenProperties.LOGGED_FAULT_PAGE_DOWN_ACTIVE.equals(key))
    {
      loggedFaultsScreenModel.setPageDownActive((Integer)newValue);
    }
    else if (IAppOutputsLoggedFaultsScreenProperties.LOGGED_FAULT_SYS_FILTER_APPLIED.equals(key))
    {
      loggedFaultsScreenModel.setAppliedSystemFilterId((Integer)newValue);
    }
    else if (IAppOutputsLoggedFaultsScreenProperties.LOGGED_FAULT_CAR_FILTER_APPLIED.equals(key))
    {
      loggedFaultsScreenModel.setAppliedCarFilterId((Integer)newValue);
    }
    else if (IAppOutputsLoggedFaultsScreenProperties.LOGGED_FAULT_PRIORITY_FILTER_APPLIED.equals(key))
    {
      loggedFaultsScreenModel.setAppliedPriorityFilterId((Integer)newValue);
    }
  }
}

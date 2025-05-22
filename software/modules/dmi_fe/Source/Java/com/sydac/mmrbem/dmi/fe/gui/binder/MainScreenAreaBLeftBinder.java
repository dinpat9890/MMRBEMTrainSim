/*
 * ================================================================== (C)
 * Copyright 2020 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.dmi.fe.gui.binder;

import com.sydac.foundation.PropertyKey;
import com.sydac.mmrbem.dmi.common.io.properties.IAppOutputsMainScreenAreaAProperties;
import com.sydac.mmrbem.dmi.common.io.properties.IAppOutputsMainScreenAreaBLeftProperties;
import com.sydac.mmrbem.dmi.common.io.properties.IAppOutputsMainScreenProperties;
import com.sydac.mmrbem.dmi.fe.base.AbstractCommsListener;
import com.sydac.mmrbem.dmi.fe.gui.model.MainScreenAreaBLeftModel;

/**
 * The Class MainScreenAreaBLeftBinder used to read main screen Area B Left
 * values from comms and assign it to the model {@link MainScreenAreaBLeftModel}
 * 
 * @author mulukg
 */
public class MainScreenAreaBLeftBinder extends AbstractCommsListener
{
  MainScreenAreaBLeftModel mainScreenAreaBLeftModel;

  public MainScreenAreaBLeftBinder(MainScreenAreaBLeftModel mainScreenAreaBLeftModel)
  {
    propertyKeyDefinitions.add(IAppOutputsMainScreenProperties.class);
    propertyKeyDefinitions.add(IAppOutputsMainScreenAreaAProperties.class);
    propertyKeyDefinitions.add(IAppOutputsMainScreenAreaBLeftProperties.class);
    this.mainScreenAreaBLeftModel = mainScreenAreaBLeftModel;
  }

  @Override
  protected <T> void appInputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue)
  {
    if (key == IAppOutputsMainScreenProperties.CURRENT_DRIVING_MODE)
    {
      mainScreenAreaBLeftModel.setCurrentDrivingMode((Integer)newValue);
    }
    else if (key == IAppOutputsMainScreenAreaAProperties.WARNING_STATUS)
    {
      mainScreenAreaBLeftModel.setWarningStatus((Integer)newValue);
    }
    else if (key == IAppOutputsMainScreenAreaBLeftProperties.CURRENT_TRAIN_SPEED)
    {
      mainScreenAreaBLeftModel.setCurrentTrainSpeed((Double)newValue);
    }
    else if (key == IAppOutputsMainScreenAreaBLeftProperties.CBTC_TARGET_SPEED)
    {
      mainScreenAreaBLeftModel.setCbtcTargetSpeed((Integer)newValue);
    }
    else if (key == IAppOutputsMainScreenAreaBLeftProperties.CBTC_PERMITTED_SPEED)
    {
      mainScreenAreaBLeftModel.setCbtcPermittedSpeed((Integer)newValue);
    }
    else if (key == IAppOutputsMainScreenAreaBLeftProperties.DRIVER_EVENT_CHANGE_ENDS)
    {
      mainScreenAreaBLeftModel.setDriverEventChangeEnds((Boolean)newValue);
    }
    else if (key == IAppOutputsMainScreenAreaBLeftProperties.NEUTRAL_ZONE_STATUS)
    {
      mainScreenAreaBLeftModel.setNeutralZoneStatus((Integer)newValue);
    }
    else if (key == IAppOutputsMainScreenAreaBLeftProperties.DRIVER_EVENT_SKIP_STATION)
    {
      mainScreenAreaBLeftModel.setDriverEventSkipStation((Boolean)newValue);
    }
    else if (key == IAppOutputsMainScreenAreaBLeftProperties.DRIVER_EVENT_WORK_ZONE)
    {
      mainScreenAreaBLeftModel.setDriverEventWorkZone((Boolean)newValue);
    }
    else if (key == IAppOutputsMainScreenProperties.ATC_BYPASS_STATE)
    {
      mainScreenAreaBLeftModel.setAtcBypassState((Boolean)newValue);
    }
    else if (key == IAppOutputsMainScreenProperties.ADVISORY_SPEED)
    {
      mainScreenAreaBLeftModel.setAdvisorySpeed((Double)newValue);
    }
    else if (key == IAppOutputsMainScreenProperties.WARNING_SPEED)
    {
      mainScreenAreaBLeftModel.setWarningSpeed((Double)newValue);
    }
  }
}

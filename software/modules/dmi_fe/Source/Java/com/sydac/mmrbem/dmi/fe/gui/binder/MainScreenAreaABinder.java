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
import com.sydac.mmrbem.dmi.fe.base.AbstractCommsListener;
import com.sydac.mmrbem.dmi.fe.gui.model.MainScreenAreaAModel;

/**
 * The Class MainScreenAreaABinder used to read main screen Area A values from
 * comms and assign it to the model {@link MainScreenAreaAModel}
 * 
 * @author mulukg
 */
public class MainScreenAreaABinder extends AbstractCommsListener
{
  MainScreenAreaAModel mainScreenAreaAModel;

  public MainScreenAreaABinder(MainScreenAreaAModel mainScreenAreaAModel)
  {
    propertyKeyDefinitions.add(IAppOutputsMainScreenAreaAProperties.class);
    this.mainScreenAreaAModel = mainScreenAreaAModel;
  }

  @Override
  protected <T> void appInputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue)
  {
    if (key == IAppOutputsMainScreenAreaAProperties.WARNING_STATUS)
    {
      mainScreenAreaAModel.setWarningStatus((Integer)newValue);
    }
    else if (key == IAppOutputsMainScreenAreaAProperties.TARGET_DISTANCE)
    {
      mainScreenAreaAModel.setTargetDistance((Integer)newValue);
    }
    else if (key == IAppOutputsMainScreenAreaAProperties.TARGET_DISTANCE_BAR_GRAPH_STATUS)
    {
      mainScreenAreaAModel.setTargetDistanceBarGraphStatus((Boolean)newValue);
    }
  }
}

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
import com.sydac.mmrbem.dmi.common.io.properties.IAppOutputsMainScreenAreaETopProperties;
import com.sydac.mmrbem.dmi.fe.base.AbstractCommsListener;
import com.sydac.mmrbem.dmi.fe.gui.model.MainScreenAreaETopModel;

/**
 * The Class MainScreenAreaETopBinder used to read main screen Area E Top values
 * from comms and assign it to the model {@link MainScreenAreaETopModel}
 * 
 * @author mulukg
 */
public class MainScreenAreaETopBinder extends AbstractCommsListener
{
  MainScreenAreaETopModel mainScreenAreaETopModel;

  public MainScreenAreaETopBinder(MainScreenAreaETopModel mainScreenAreaETopModel)
  {
    propertyKeyDefinitions.add(IAppOutputsMainScreenAreaETopProperties.class);
    this.mainScreenAreaETopModel = mainScreenAreaETopModel;
  }

  @Override
  protected <T> void appInputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue)
  {
    if (key == IAppOutputsMainScreenAreaETopProperties.RADIO_COMMUNICATION_STATUS)
    {
      mainScreenAreaETopModel.setRadioCommunicationStatus((Integer)newValue);
    }
    else if (key == IAppOutputsMainScreenAreaETopProperties.ATC_STATUS)
    {
      mainScreenAreaETopModel.setAtcStatus((Integer)newValue);
    }
    else if (key == IAppOutputsMainScreenAreaETopProperties.ATP_ZONE_STATUS)
    {
      mainScreenAreaETopModel.setAtpZoneStatus((Integer)newValue);
    }
    else if (key == IAppOutputsMainScreenAreaETopProperties.DEPOT_INDICATION)
    {
      mainScreenAreaETopModel.setDepotIndication((Integer)newValue);
    }
  }
}

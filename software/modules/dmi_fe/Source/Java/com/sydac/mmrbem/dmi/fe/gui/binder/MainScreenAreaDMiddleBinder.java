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
import com.sydac.mmrbem.dmi.common.io.properties.IAppOutputsMainScreenAreaDMiddleProperties;
import com.sydac.mmrbem.dmi.common.io.properties.IAppOutputsMainScreenProperties;
import com.sydac.mmrbem.dmi.fe.base.AbstractCommsListener;
import com.sydac.mmrbem.dmi.fe.gui.model.MainScreenAreaDMiddleModel;

/**
 * The Class MainScreenAreaDMiddleBinder used to read main screen Area D Middle
 * values from comms and assign it to the model
 * {@link MainScreenAreaDMiddleModel}
 * 
 * @author mulukg
 */

public class MainScreenAreaDMiddleBinder extends AbstractCommsListener
{

  MainScreenAreaDMiddleModel mainScreenAreaDMiddleModel;

  public MainScreenAreaDMiddleBinder(MainScreenAreaDMiddleModel mainScreenAreaDMiddleModel)
  {
    propertyKeyDefinitions.add(IAppOutputsMainScreenAreaDMiddleProperties.class);
    propertyKeyDefinitions.add(IAppOutputsMainScreenProperties.class);
    this.mainScreenAreaDMiddleModel = mainScreenAreaDMiddleModel;
  }

  @Override
  protected <T> void appInputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue)
  {
    if (key == IAppOutputsMainScreenAreaDMiddleProperties.PSD_DOOR_STATUS)
    {
      mainScreenAreaDMiddleModel.setPsdDoorStatus((Integer)newValue);
    }
    else if (key == IAppOutputsMainScreenAreaDMiddleProperties.TRAIN_DOCKING_STATUS)
    {
      mainScreenAreaDMiddleModel.setTrainDockingStatus((Integer)newValue);
    }
    else if (key == IAppOutputsMainScreenAreaDMiddleProperties.OPERATIONAL_SERVICE_STOPPING_DISTANCE)
    {
      mainScreenAreaDMiddleModel.setOperationalServiceStoppingDistance((new String((byte[])newValue)));
    }
    else if (key == IAppOutputsMainScreenAreaDMiddleProperties.DEPARTURE_ORDER)
    {
      mainScreenAreaDMiddleModel.setDepartureOrder((Integer)newValue);
    }
    else if (key == IAppOutputsMainScreenAreaDMiddleProperties.DEPARTURE_INFORMATION_STATUS)
    {
      mainScreenAreaDMiddleModel.setDepartureInformationStatus((Integer)newValue);
    }
    else if (key == IAppOutputsMainScreenAreaDMiddleProperties.REMAINING_TIME_BEFORE_DEPARTURE)
    {
      mainScreenAreaDMiddleModel.setRemainingTimeBeforeDeparture(new String((byte[])newValue));
    }
    else if (key == IAppOutputsMainScreenAreaDMiddleProperties.REMAINING_TIME_IN_MINUTE_STATUS)
    {
      mainScreenAreaDMiddleModel.setRemainingTimeInMinuteStatus((Boolean)newValue);
    }
    else if (key == IAppOutputsMainScreenAreaDMiddleProperties.TRAIN_DOOR_STATUS)
    {
      mainScreenAreaDMiddleModel.setTrainDoorStatus((Integer)newValue);
    }
    else if (key == IAppOutputsMainScreenProperties.CURRENT_DATE_AND_TIME)
    {
      mainScreenAreaDMiddleModel.setFlashTime((Number)newValue);
    }
    else if (key == IAppOutputsMainScreenAreaDMiddleProperties.DETRAINMENT_DOOR_STATUS)
    {
      mainScreenAreaDMiddleModel.setDetrainmentDoorStatus((Integer)newValue);
    }
  }
}

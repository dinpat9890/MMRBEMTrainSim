/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.papis.fe.gui.binder;

import com.sydac.foundation.PropertyKey;
import com.sydac.mmrbem.papis.common.io.properties.IAppOutputsCommonProperties;
import com.sydac.mmrbem.papis.fe.base.AbstractCommsListener;
import com.sydac.mmrbem.papis.fe.gui.model.TrainIdSettingScreenModel;

public class TrainIdSettingsScreenBinder extends AbstractCommsListener
{

  private TrainIdSettingScreenModel trainIdSettingScreenModel;

  public TrainIdSettingsScreenBinder(TrainIdSettingScreenModel trainIdSettingScreenModel)
  {
    this.trainIdSettingScreenModel = trainIdSettingScreenModel;
    propertyKeyDefinitions.add(IAppOutputsCommonProperties.class);
  }

  @Override
  protected <T> void appOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue)
  {
    if (IAppOutputsCommonProperties.TRAIN_ID.equals(key))
    {
      trainIdSettingScreenModel.setTrainIdproperty((byte[])newValue);
    }
  }
}

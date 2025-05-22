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
import com.sydac.mmrbem.tcms.common.io.properties.IAppOutputsTrainConfigurationProperties;
import com.sydac.mmrbem.tcms.fe.base.AbstractCommsListener;
import com.sydac.mmrbem.tcms.fe.model.TrainConfigurationModel;

/**
 * The Class TrainConfigurationBinder.
 */
public class TrainConfigurationBinder extends AbstractCommsListener
{
  private TrainConfigurationModel configurationModel;

  public TrainConfigurationBinder(TrainConfigurationModel model)
  {
    super();
    configurationModel = model;
    propertyKeyDefinitions.add(IAppOutputsTrainConfigurationProperties.class);
  }

  @Override
  protected <T> void appOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue)
  {
    if (IAppOutputsTrainConfigurationProperties.TRAIN_CONFIGURATION_DATA.equals(key))
    {
      configurationModel.setTrainConfigurationData((byte[])newValue);
    }
  }
}
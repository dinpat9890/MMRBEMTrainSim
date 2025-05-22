/*
 * ==================================================================
 * 
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.papis.backend.logic.handler;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import com.sydac.common.registry.Registry;
import com.sydac.foundation.IPropertySetter;
import com.sydac.foundation.PropertyKey;
import com.sydac.mmrbem.papis.backend.comms.CommsBinding;
import com.sydac.mmrbem.papis.backend.logic.AbstractFunctionalLogic;
import com.sydac.mmrbem.papis.backend.logic.SharedDataModel;
import com.sydac.mmrbem.papis.backend.logic.annotation.FunctionalLogicHandler;
import com.sydac.mmrbem.papis.backend.vehicle.io.properties.IPISBEInputsProperties;
import com.sydac.mmrbem.papis.backend.vehicle.io.properties.IPISBEInputsSystemSettingScreenProperties;
import com.sydac.mmrbem.papis.backend.vehicle.io.properties.IPISBEOutputsProperties;
import com.sydac.mmrbem.papis.backend.vehicle.io.properties.IPISBEOutputsStartupScreenProperties;
import com.sydac.mmrbem.papis.common.ScreenId;
import com.sydac.mmrbem.papis.common.io.properties.IAppInputsProperties;
import com.sydac.mmrbem.papis.common.io.properties.IAppInputsScreenChangeProperties;
import com.sydac.mmrbem.papis.common.io.properties.IAppInputsTrainIdScreenProperties;
import com.sydac.mmrbem.papis.common.io.properties.IAppOutputsCommonProperties;
import com.sydac.mmrbem.papis.common.state.ApplicationConstants;
import com.sydac.mmrbem.papis.common.state.KeyPadEnum;

/**
 * This handler class is used for Train Id screen handling.
 * 
 */
@Service
@FunctionalLogicHandler(arguments = { CommsBinding.class, SharedDataModel.class })
public class TrainIdSettingScreenHandler extends AbstractFunctionalLogic
{
  private final SharedDataModel sharedDataModel;

  @Autowired
  CommsBinding commsBinding;

  private String trainId = ApplicationConstants.BLANK;

  private String defaultTrainId = Registry.getInstance().getString("papis", "trainId"); //$NON-NLS-1$ //$NON-NLS-2$

  protected TrainIdSettingScreenHandler(CommsBinding commsBinding, Class<?>[] propertyKeyDefinitions)
  {
    super(commsBinding, IPISBEOutputsProperties.class, IAppInputsProperties.class,
        IPISBEInputsProperties.class);
    this.commsBinding = commsBinding;
    this.sharedDataModel = new SharedDataModel();
    sharedDataModel.setTrainId(defaultTrainId);
    trainId = sharedDataModel.getTrainId();
  }

  @Override
  public <T> void appInputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue, int vehicleIndex)
  {
    IPropertySetter propertySetter = getPISBEInputsSetter(vehicleIndex);
    if (IAppInputsScreenChangeProperties.SCREEN_CHANGE_REQUEST.equals(key)
        && ScreenId.SYSTEM_SETTINGS_SCREEN.getId() == (Integer)newValue)
    {
      trainId = sharedDataModel.getTrainId();
    }
    else if (IAppInputsTrainIdScreenProperties.TRAIN_ID_KEYPAD_BUTTON_REQUEST.equals(key)
        && (Integer)newValue > -1)
    {
      updateTrainId((Integer)newValue);
    }
    else if (IAppInputsTrainIdScreenProperties.TRAIN_ID_SCREEN_OK_BUTTON.equals(key))
    {
      validateTrainId(propertySetter);
    }
    else if (IAppInputsTrainIdScreenProperties.TRAIN_ID_SCREEN_BACK_BUTTON.equals(key)
        && (Integer)newValue > 0)
    {
      trainId = sharedDataModel.getTrainId();
      setApplicationOutputsProperty(IAppOutputsCommonProperties.TRAIN_ID, trainId.getBytes());
    }
  }

  private void updateTrainId(Integer keyPress)
  {
    if (KeyPadEnum.valueOf(keyPress).getValue() == (KeyPadEnum.CLEAR.getValue()))
    {
      trainId = ApplicationConstants.BLANK;
      setApplicationOutputsProperty(IAppOutputsCommonProperties.TRAIN_ID, trainId.getBytes());
    }
    else
    {
      updateTrainIdText(keyPress);
    }
  }

  private void updateTrainIdText(Integer keyPress)
  {
    if (trainId.length() < 6)
    {
      trainId = trainId.concat(String.valueOf(keyPress));
      setApplicationOutputsProperty(IAppOutputsCommonProperties.TRAIN_ID, trainId.getBytes());
    }
  }

  private void validateTrainId(IPropertySetter propertySetter)
  {

    sharedDataModel.setTrainId(trainId);
    if (sharedDataModel.getTrainId().equals(defaultTrainId))
    {
      setApplicationOutputsProperty(IAppOutputsCommonProperties.TRAIN_ID, defaultTrainId.getBytes());
      setInputData(propertySetter, IPISBEInputsSystemSettingScreenProperties.TRAIN_ID_CHANGE_REQUEST,
          Integer.parseInt(defaultTrainId));
    }
    else
    {
      setApplicationOutputsProperty(IAppOutputsCommonProperties.TRAIN_ID,
          sharedDataModel.getTrainId().getBytes());
      setInputData(propertySetter, IPISBEInputsSystemSettingScreenProperties.TRAIN_ID_CHANGE_REQUEST,
          Integer.parseInt(sharedDataModel.getTrainId()));
    }
  }

  @Override
  public <T> void pisBeOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue, int vehicleIndex)
  {
    if (IPISBEOutputsStartupScreenProperties.POWER_STATE.equals(key))
    {
      setApplicationOutputsProperty(IAppOutputsCommonProperties.TRAIN_ID, defaultTrainId.getBytes());
    }
  }

}

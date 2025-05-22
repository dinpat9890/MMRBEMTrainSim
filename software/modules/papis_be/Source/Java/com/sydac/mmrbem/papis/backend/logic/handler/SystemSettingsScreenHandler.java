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

import com.sydac.foundation.IPropertySetter;
import com.sydac.foundation.PropertyKey;
import com.sydac.gui.i18n.CommonStrings;
import com.sydac.mmrbem.papis.backend.comms.CommsBinding;
import com.sydac.mmrbem.papis.backend.logic.AbstractFunctionalLogic;
import com.sydac.mmrbem.papis.backend.logic.SharedDataModel;
import com.sydac.mmrbem.papis.backend.logic.annotation.FunctionalLogicHandler;
import com.sydac.mmrbem.papis.backend.vehicle.io.properties.IPISBEInputsProperties;
import com.sydac.mmrbem.papis.backend.vehicle.io.properties.IPISBEInputsSystemSettingScreenProperties;
import com.sydac.mmrbem.papis.backend.vehicle.io.properties.IPISBEOutputsMainInterfaceScreenProperties;
import com.sydac.mmrbem.papis.backend.vehicle.io.properties.IPISBEOutputsProperties;
import com.sydac.mmrbem.papis.common.io.properties.IAppInputsProperties;
import com.sydac.mmrbem.papis.common.io.properties.IAppInputsSystemSettingScreenProperties;
import com.sydac.mmrbem.papis.common.io.properties.IAppOutputsCommonProperties;
import com.sydac.mmrbem.papis.common.io.properties.XMLParser;

/**
 * This handler class is used for handling System Settings Screen data
 * 
 */
@Service
@FunctionalLogicHandler(arguments = { CommsBinding.class, SharedDataModel.class })
public class SystemSettingsScreenHandler extends AbstractFunctionalLogic
{

  private static final int MODE_CHANGE_REQUEST = -1;

  @Autowired
  CommsBinding commsBinding;

  @Autowired
  SharedDataModel sharedDataModel;

  private XMLParser xmlParser;

  protected SystemSettingsScreenHandler(CommsBinding commsBinding, SharedDataModel sharedDataModel)
  {
    super(commsBinding, IAppInputsProperties.class, IPISBEOutputsProperties.class,
        IPISBEInputsProperties.class);
    this.commsBinding = commsBinding;
    this.sharedDataModel = sharedDataModel;
    this.xmlParser = new XMLParser();
  }

  @Override
  public <T> void appInputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue, int vehicleIndex)
  {
    IPropertySetter propertySetter = getPISBEInputsSetter(vehicleIndex);
    if (IAppInputsSystemSettingScreenProperties.MODE_SELECTION_REQUEST.equals(key))
    {
      setInputData(propertySetter, IPISBEInputsSystemSettingScreenProperties.STATION_ANNOUNCEMENT_MODE,
          (Integer)newValue);
    }else if (IAppInputsSystemSettingScreenProperties.SYSTEM_SCREEN_OK_BUTTON_REQ.equals(key))
    {
      setInputData(propertySetter, IPISBEInputsSystemSettingScreenProperties.ANNOUNCEMENT_MODE_CHANGED_BTN,
          (Integer)newValue);
    }
  }

  @Override
  public <T> void pisBeOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue, int vehicleIndex)
  {
    if (IPISBEOutputsMainInterfaceScreenProperties.SELECTED_START_STATION_ID.equals(key))
    {
      if ((Integer)newValue == MODE_CHANGE_REQUEST)
      {
        setApplicationOutputsProperty(IAppOutputsCommonProperties.START_STATION_NAME,
            CommonStrings.BLANK.getBytes());
      }
      else if ((Integer)newValue > 0)
      {
        setApplicationOutputsProperty(IAppOutputsCommonProperties.START_STATION_NAME,
            xmlParser.getStationName((Integer)newValue).getBytes());
        sharedDataModel.setStartStationId((Integer)newValue);
      }

    }
  }
}

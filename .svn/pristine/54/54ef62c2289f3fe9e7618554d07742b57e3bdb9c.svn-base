package com.sydac.mmrbem.dmi.fe.gui.binder;

import com.sydac.foundation.PropertyKey;
import com.sydac.mmrbem.dmi.common.io.properties.IAppOutputsMainScreenAreaTextMessageProperties;
import com.sydac.mmrbem.dmi.fe.base.AbstractCommsListener;
import com.sydac.mmrbem.dmi.fe.gui.model.MainScreenAreaTextMessageModel;

public class MainScreenAreaTextMessageBinder extends AbstractCommsListener
{

  MainScreenAreaTextMessageModel mainScreenAreaTextMessageModel;

  public MainScreenAreaTextMessageBinder(MainScreenAreaTextMessageModel mainScreenAreaTextMessageModel)
  {
    propertyKeyDefinitions.add(IAppOutputsMainScreenAreaTextMessageProperties.class);
    this.mainScreenAreaTextMessageModel = mainScreenAreaTextMessageModel;
  }

  @Override
  protected <T> void appInputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue)
  {
    if (key == IAppOutputsMainScreenAreaTextMessageProperties.ACTIVE_TEXT_MESSAGES)
    {
      mainScreenAreaTextMessageModel.setActiveTextMessages((byte[])newValue);
    }
    else if (key == IAppOutputsMainScreenAreaTextMessageProperties.TEXT_MESSAGE_UP_BUTTON_STATUS)
    {
      mainScreenAreaTextMessageModel.setTextMessageUpButtonStatus((Boolean)newValue);;
    }
    else if (key == IAppOutputsMainScreenAreaTextMessageProperties.TEXT_MESSAGE_DOWN_BUTTON_STATUS)
    {
      mainScreenAreaTextMessageModel.setTextMessageDownButtonStatus((Boolean)newValue);
    }
    else if (key == IAppOutputsMainScreenAreaTextMessageProperties.NEW_MESSGAE_INDICATION)
    {
      mainScreenAreaTextMessageModel.setNewMessageIndication((Boolean)newValue);
    }
  }

}

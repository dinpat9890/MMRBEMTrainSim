/*
 * ================================================================== (C)
 * Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.radio.fe.gui.binder;

import com.sydac.foundation.PropertyKey;
import com.sydac.mmrbem.radio.common.io.properties.IAppOutputMessageScreenProperties;
import com.sydac.mmrbem.radio.fe.base.AbstractCommsListener;
import com.sydac.mmrbem.radio.fe.gui.model.MessageScreenModel;

public class MessageScreenBinder extends AbstractCommsListener
{
  private MessageScreenModel messageScreenMoodel;

  public MessageScreenBinder(int scenarioCarIndex, MessageScreenModel messageScreenMoodel)
  {
    this.messageScreenMoodel = messageScreenMoodel;
    propertyKeyDefinitions.add(IAppOutputMessageScreenProperties.class);

  }

  @Override
  protected <T> void appOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue)
  {
    if (IAppOutputMessageScreenProperties.INBOX_MESSAGE_LIST.equals(key))
    {
      messageScreenMoodel.setInBoxMessageList((byte[])newValue);
    }
    else if (IAppOutputMessageScreenProperties.INBOX_MSG_LIST_SELECTED_ID.equals(key))
    {
      messageScreenMoodel.setSelectedInboxMessageId((Integer)newValue);
    }
    if (IAppOutputMessageScreenProperties.OUTBOX_MESSAGE_LIST.equals(key))
    {
      messageScreenMoodel.setOutBoxMessageList((byte[])newValue);
    }
    else if (IAppOutputMessageScreenProperties.OUTBOX_MSG_LIST_SELECTED_ID.equals(key))
    {
      messageScreenMoodel.setSelectedOutBoxMessageId((Integer)newValue);
    }
    else if (IAppOutputMessageScreenProperties.INBOX_OUTBOX_SELECTED_BTN.equals(key))
    {
      messageScreenMoodel.setSelectedInBoxOutBoxBtnId((Integer)newValue);
    }
    else if (IAppOutputMessageScreenProperties.INBOX_MESSAGE.equals(key))
    {
      messageScreenMoodel.setInBoxMessage((byte[])newValue);
    }
    else if (IAppOutputMessageScreenProperties.OUTBOX_MESSAGE.equals(key))
    {
      messageScreenMoodel.setOutBoxMessage((byte[])newValue);
    }
  }

}

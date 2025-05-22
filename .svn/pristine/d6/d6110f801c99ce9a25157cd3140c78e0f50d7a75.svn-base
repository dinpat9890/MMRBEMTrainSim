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
import com.sydac.mmrbem.radio.common.io.properties.IAppOutputContactScreenProperties;
import com.sydac.mmrbem.radio.fe.base.AbstractCommsListener;
import com.sydac.mmrbem.radio.fe.gui.model.ContactsScreenModel;

public class ContactsScreenBinder extends AbstractCommsListener
{
  private ContactsScreenModel contactsScreenModel;

  public ContactsScreenBinder(ContactsScreenModel contactsScreenModel)
  {
    this.contactsScreenModel = contactsScreenModel;
    propertyKeyDefinitions.add(IAppOutputContactScreenProperties.class);
  }

  @Override
  protected <T> void appOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue)
  {
    if (IAppOutputContactScreenProperties.CONTACT_LIST.equals(key))
    {
      contactsScreenModel.setContactList((byte[])newValue);
    }
    else if (IAppOutputContactScreenProperties.SELECTED_CONTACT_LIST_ID.equals(key))
    {
      contactsScreenModel.setSelectedContactId((Integer)newValue);
    }
    else if (IAppOutputContactScreenProperties.CONTACT_SCREEN_SELECTED_BTN.equals(key))
    {
      contactsScreenModel.setSelectedBtn((Integer)newValue);
    }
  }

}

/*
 * ================================================================== (C)
 * Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.radio.fe.gui.model;

import java.util.stream.Collectors;

import com.google.protobuf.InvalidProtocolBufferException;
import com.sydac.common.febe.frontend.gui.AbstractScreenModel;
import com.sydac.common.log.Tracer;
import com.sydac.mmrbem.radio.common.data.ContactDO;
import com.sydac.radio.proto.RadioProtos;

import javafx.beans.property.IntegerProperty;
import javafx.beans.property.ListProperty;
import javafx.beans.property.SimpleIntegerProperty;
import javafx.beans.property.SimpleListProperty;
import javafx.collections.FXCollections;

public class ContactsScreenModel extends AbstractScreenModel
{
  private IntegerProperty selectedContactId = new SimpleIntegerProperty();

  private ListProperty<ContactDO> contactList = new SimpleListProperty<>(FXCollections.observableArrayList());

  private IntegerProperty selectedBtnId = new SimpleIntegerProperty();

  public ContactsScreenModel(int carIndex)
  {
    super(carIndex);
  }

  public ListProperty<ContactDO> getContactList()
  {
    return contactList;
  }

  public void setSelectedContactId(Integer selectedContactId)
  {
    this.selectedContactId.set(selectedContactId);
  }

  public IntegerProperty getSelectedContactId()
  {
    return selectedContactId;
  }

  public void setContactList(byte[] cntList)
  {
    try
    {
      this.contactList.clear();
      if (cntList.length != 0)
      {
        this.contactList.addAll(RadioProtos.ContactList.parseFrom(cntList).getContactList().stream()
            .map(contact -> new ContactDO(contact.getContactText(), contact.getContactId()))
            .collect(Collectors.toList()));
      }
    }
    catch (InvalidProtocolBufferException e)
    {
      Tracer.getInstance().error(e);
    }

  }

  public void setSelectedBtn(Integer btn)
  {
    selectedBtnId.set(btn);
  }

  public IntegerProperty getSelectedBtnId()
  {
    return selectedBtnId;
  }

}

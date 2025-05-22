package com.sydac.mmrbem.radio.common.data;

import javafx.beans.property.IntegerProperty;
import javafx.beans.property.SimpleIntegerProperty;
import javafx.beans.property.SimpleStringProperty;
import javafx.beans.property.StringProperty;

public class ContactDO
{
  private StringProperty contactText = new SimpleStringProperty();

  private IntegerProperty contactId = new SimpleIntegerProperty();

  public ContactDO(String contactText, Integer contactId)
  {
    this.contactText.set(contactText);
    this.contactId.set(contactId);

  }

  public ContactDO()
  {}

  public String getContactText()
  {
    return contactText.get();
  }

  public Integer getContactId()
  {
    return contactId.get();
  }

  public void setContactText(String contactText)
  {
    this.contactText.set(contactText);
  }

  public void setContactId(Integer contactId)
  {
    this.contactId.set(contactId);
  }

}

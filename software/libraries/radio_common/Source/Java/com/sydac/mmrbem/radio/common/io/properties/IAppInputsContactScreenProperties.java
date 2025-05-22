package com.sydac.mmrbem.radio.common.io.properties;

import static com.sydac.foundation.PropertyKey.create;

import com.sydac.common.febe.binding.CommsBinding;
import com.sydac.foundation.PropertyKey;
import com.sydac.project.runtimedata.ProjectObjectConstants.RadioInputs;

public interface IAppInputsContactScreenProperties
{
  @CommsBinding(property = RadioInputs.SELECTED_CONTACT_LIST_ID)
  PropertyKey<Integer> SELECTED_CONTACT_LIST_ID = create();

  @CommsBinding(property = RadioInputs.CONTACTS_BTN_REQUEST)
  PropertyKey<Integer> CONTACTS_BTN_REQUEST = create();

  @CommsBinding(property = RadioInputs.GROUP_LIST_BTN_REQUEST)
  PropertyKey<Integer> GROUP_LIST_BTN_REQUEST = create();

}

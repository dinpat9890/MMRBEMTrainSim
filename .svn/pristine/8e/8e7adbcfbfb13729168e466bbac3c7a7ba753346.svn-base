/*
 * ================================================================== (C)
 * Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.radio.common.io.properties;

import static com.sydac.foundation.PropertyKey.create;

import com.sydac.common.febe.binding.CommsBinding;
import com.sydac.foundation.PropertyKey;
import com.sydac.project.runtimedata.ProjectObjectConstants.RadioOutputs;

public interface IAppOutputMessageScreenProperties
{
  @CommsBinding(property = RadioOutputs.INBOX_MESSAGE_LIST)
  PropertyKey<byte[]> INBOX_MESSAGE_LIST = create();

  @CommsBinding(property = RadioOutputs.INBOX_MESSAGE)
  PropertyKey<byte[]> INBOX_MESSAGE = create();

  @CommsBinding(property = RadioOutputs.OUTBOX_MESSAGE_LIST)
  PropertyKey<byte[]> OUTBOX_MESSAGE_LIST = create();

  @CommsBinding(property = RadioOutputs.INBOX_MSG_LIST_SELECTED_ID)
  PropertyKey<Integer> INBOX_MSG_LIST_SELECTED_ID = create();

  @CommsBinding(property = RadioOutputs.INBOX_OUTBOX_SELECTED_BTN)
  PropertyKey<Integer> INBOX_OUTBOX_SELECTED_BTN = create();

  @CommsBinding(property = RadioOutputs.OUTBOX_MSG_LIST_SELECTED_ID)
  PropertyKey<Integer> OUTBOX_MSG_LIST_SELECTED_ID = create();

  @CommsBinding(property = RadioOutputs.OUTBOX_MESSAGE)
  PropertyKey<byte[]> OUTBOX_MESSAGE = create();

}

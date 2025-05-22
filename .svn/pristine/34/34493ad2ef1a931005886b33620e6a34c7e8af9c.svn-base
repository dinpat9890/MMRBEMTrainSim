/*
 * ==================================================================
 * 
 * 
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.tcms.backend.vehicle.io.properties;

import static com.sydac.foundation.PropertyKey.create;

import com.sydac.common.febe.binding.CommsBinding;
import com.sydac.foundation.PropertyKey;
import com.sydac.project.runtimedata.ProjectObjectConstants.TCMSMessage;

/**
 * This interface contain crew message related properties
 */
public interface IEventProperties
{
  @CommsBinding(property = TCMSMessage.MESSAGE_ID)
  PropertyKey<Integer> MESSAGE_ID = create();
  
  @CommsBinding(property = TCMSMessage.MESSAGE_STATUS)
  PropertyKey<Integer> MESSAGE_STATUS = create();
  
  @CommsBinding(property = TCMSMessage.INDEX)
  PropertyKey<Integer> INDEX = create();
}

/*
 * ==================================================================
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
import com.sydac.project.runtimedata.ProjectObjectConstants.PISBEInputsValues;

public interface IPISBEInputsSystemSettingScreenProperties
{
  @CommsBinding(property = PISBEInputsValues.STATION_ANNOUNCEMENT_MODE)
  PropertyKey<Integer> STATION_ANNOUNCEMENT_MODE = create();

  @CommsBinding(property = PISBEInputsValues.INSTRUCTOR_ANNOUNCEMENT_ID)
  PropertyKey<Integer> INSTRUCTOR_ANNOUNCEMENT_ID = create();
  
  
  @CommsBinding(property = PISBEInputsValues.SKIP_STATION_LIST)
  PropertyKey<byte[]> SKIP_STATION_LIST = create();
  

  @CommsBinding(property = PISBEInputsValues.STOP_SPECIAL_ANNOUNCEMNT)
  PropertyKey<Integer> STOP_SPECIAL_ANNOUNCEMNT = create();
 
}

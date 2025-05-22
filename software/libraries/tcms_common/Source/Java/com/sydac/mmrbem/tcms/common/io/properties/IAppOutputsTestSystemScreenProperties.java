/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.tcms.common.io.properties;

import static com.sydac.foundation.PropertyKey.create;

import com.sydac.common.febe.binding.CommsBinding;
import com.sydac.foundation.PropertyKey;
import com.sydac.project.runtimedata.ProjectObjectConstants.VDUOutputs;

public interface IAppOutputsTestSystemScreenProperties
{
  /* Output Variables for Fire System Test Screen */
  @CommsBinding(property = VDUOutputs.FDS_CURRENT_PAGE)
  PropertyKey<Integer> FDS_CURRENT_PAGE = create();

  @CommsBinding(property = VDUOutputs.FDS_TOTAL_PAGE)
  PropertyKey<Integer> FDS_TOTAL_PAGE = create();

  @CommsBinding(property = VDUOutputs.FIRE_SYSTEM_TEST_STATUS)
  PropertyKey<byte[]> FIRE_SYSTEM_TEST_STATUS = create();

  /* Output Variables for Battery System Test Screen */
  @CommsBinding(property = VDUOutputs.BATTERY_TEST_CURRENT_PAGE)
  PropertyKey<Integer> BATTERY_TEST_CURRENT_PAGE = create();

  @CommsBinding(property = VDUOutputs.BATTERY_TEST_TOTAL_PAGE)
  PropertyKey<Integer> BATTERY_TEST_TOTAL_PAGE = create();

  @CommsBinding(property = VDUOutputs.BATTERY_SYSTEM_TEST_STATUS)
  PropertyKey<byte[]> BATTERY_SYSTEM_TEST_STATUS = create();

  /* Output Variables for Brake System Test Screen */
  @CommsBinding(property = VDUOutputs.BCU_TEST_CURRENT_PAGE)
  PropertyKey<Integer> BCU_TEST_CURRENT_PAGE = create();

  @CommsBinding(property = VDUOutputs.BCU_TEST_TOTAL_PAGE)
  PropertyKey<Integer> BCU_TEST_TOTAL_PAGE = create();

  @CommsBinding(property = VDUOutputs.BRAKE_SYSTEM_TEST_STATUS)
  PropertyKey<byte[]> BRAKE_SYSTEM_TEST_STATUS = create();

  /* Output Variables for Door System Test Screen */
  @CommsBinding(property = VDUOutputs.DOOR_TEST_CURRENT_PAGE)
  PropertyKey<Integer> DOOR_TEST_CURRENT_PAGE = create();

  @CommsBinding(property = VDUOutputs.DOOR_TEST_TOTAL_PAGE)
  PropertyKey<Integer> DOOR_TEST_TOTAL_PAGE = create();

  @CommsBinding(property = VDUOutputs.DOOR_SYSTEM_TEST_STATUS)
  PropertyKey<byte[]> DOOR_SYSTEM_TEST_STATUS = create();

  /* Output Variables for HVAC System Test Screen */
  @CommsBinding(property = VDUOutputs.HCVAC_TEST_CURRENT_PAGE)
  PropertyKey<Integer> HCVAC_TEST_CURRENT_PAGE = create();

  @CommsBinding(property = VDUOutputs.HVAC_TEST_TOTAL_PAGE)
  PropertyKey<Integer> HVAC_TEST_TOTAL_PAGE = create();

  @CommsBinding(property = VDUOutputs.HVAC_SYSTEM_TEST_STATUS)
  PropertyKey<byte[]> HVAC_SYSTEM_TEST_STATUS = create();

  /* Output Variables for PIS System Test Screen */
  @CommsBinding(property = VDUOutputs.PIS_TEST_CURRENT_PAGE)
  PropertyKey<Integer> PIS_TEST_CURRENT_PAGE = create();

  @CommsBinding(property = VDUOutputs.PIS_TEST_TOTAL_PAGE)
  PropertyKey<Integer> PIS_TEST_TOTAL_PAGE = create();

  @CommsBinding(property = VDUOutputs.PIS_TEST_STATUS)
  PropertyKey<byte[]> PIS_TEST_STATUS = create();

  /* Output Variables for PIS System Test Screen */
  @CommsBinding(property = VDUOutputs.SYSTEM_TEST_CURRENT_PAGE)
  PropertyKey<Integer> SYSTEM_TEST_CURRENT_PAGE = create();

  @CommsBinding(property = VDUOutputs.SYSTEM_TEST_TOTAL_PAGE)
  PropertyKey<Integer> SYSTEM_TEST_TOTAL_PAGE = create();

  @CommsBinding(property = VDUOutputs.SYSTEM_TEST_STATUS)
  PropertyKey<byte[]> SYSTEM_TEST_STATUS = create();

}

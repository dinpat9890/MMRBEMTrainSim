/*
 * *****************************************************************************
 * * (C) Copyright 2020 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.dmi.backend.vehicle.io.properties;

import static com.sydac.foundation.PropertyKey.create;

import com.sydac.common.febe.binding.CommsBinding;
import com.sydac.foundation.PropertyKey;
import com.sydac.project.runtimedata.ProjectObjectConstants.CBTCOnboardOutputs;

/**
 * This interface holds variable for CBTCOnboardOutputs.
 * 
 */
public interface ICBTCOnboardOutputsProperties
{

  @CommsBinding(property = CBTCOnboardOutputs.WARNING_STATUS)
  PropertyKey<Integer> WARNING_STATUS = create();

  @CommsBinding(property = CBTCOnboardOutputs.CURRENT_DRIVING_MODE)
  PropertyKey<Integer> CURRENT_DRIVING_MODE = create();

  @CommsBinding(property = CBTCOnboardOutputs.CURRENT_TRAIN_SPEED)
  PropertyKey<Double> CURRENT_TRAIN_SPEED = create();

  @CommsBinding(property = CBTCOnboardOutputs.CBTC_TARGET_SPEED)
  PropertyKey<Double> CBTC_TARGET_SPEED = create();

  @CommsBinding(property = CBTCOnboardOutputs.CBTC_PERMITTED_SPEED)
  PropertyKey<Double> CBTC_PERMITTED_SPEED = create();

  @CommsBinding(property = CBTCOnboardOutputs.DETRAINMENT_DOOR_STATUS)
  PropertyKey<Integer> DETRAINMENT_DOOR_STATUS = create();

  @CommsBinding(property = CBTCOnboardOutputs.SAFETY_BRAKE_STATUS)
  PropertyKey<Integer> SAFETY_BRAKE_STATUS = create();

  @CommsBinding(property = CBTCOnboardOutputs.ATC_STATUS)
  PropertyKey<Integer> ATC_STATUS = create();

  @CommsBinding(property = CBTCOnboardOutputs.ATC_BYPASS_STATE)
  PropertyKey<Integer> ATC_BYPASS_STATE = create();

  @CommsBinding(property = CBTCOnboardOutputs.TARGET_DISTANCE)
  PropertyKey<Integer> TARGET_DISTANCE = create();

  @CommsBinding(property = CBTCOnboardOutputs.LOCALISATION_STATUS)
  PropertyKey<Integer> LOCALISATION_STATUS = create();

  @CommsBinding(property = CBTCOnboardOutputs.ADVISORY_SPEED)
  PropertyKey<Double> ADVISORY_SPEED = create();

  @CommsBinding(property = CBTCOnboardOutputs.DRIVER_EVENT_SKIP_STATION)
  PropertyKey<Integer> DRIVER_EVENT_SKIP_STATION = create();

  @CommsBinding(property = CBTCOnboardOutputs.DRIVER_EVENT_CHANGE_ENDS)
  PropertyKey<Integer> DRIVER_EVENT_CHANGE_ENDS = create();

  @CommsBinding(property = CBTCOnboardOutputs.DRIVER_EVENT_WORK_ZONE)
  PropertyKey<Integer> DRIVER_EVENT_WORK_ZONE = create();

  @CommsBinding(property = CBTCOnboardOutputs.RADIO_COMMUNICATION_STATUS)
  PropertyKey<Integer> RADIO_COMMUNICATION_STATUS = create();

  @CommsBinding(property = CBTCOnboardOutputs.DEPOT_INDICATION)
  PropertyKey<Integer> DEPOT_INDICATION = create();

  @CommsBinding(property = CBTCOnboardOutputs.AVAILABLE_MODES)
  PropertyKey<byte[]> AVAILABLE_MODES = create();

  @CommsBinding(property = CBTCOnboardOutputs.CBTC_TEXT_MESSAGES)
  PropertyKey<byte[]> CBTC_TEXT_MESSAGES = create();

  @CommsBinding(property = CBTCOnboardOutputs.WARNING_SPEED)
  PropertyKey<Double> WARNING_SPEED = create();

  @CommsBinding(property = CBTCOnboardOutputs.ATP_ZONE_STATUS)
  PropertyKey<Integer> ATP_ZONE_STATUS = create();
}

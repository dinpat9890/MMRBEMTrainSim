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

public interface IAppOutputsCCTVScreenProperties
{
  @CommsBinding(property = VDUOutputs.AUTO_ROTATION_ON)
  PropertyKey<Integer> AUTO_ROTATION_ON = create();

  @CommsBinding(property = VDUOutputs.EXTERNAL_OR_INTERNAL_VIEW)
  PropertyKey<Integer> EXTERNAL_OR_INTERNAL_VIEW = create();

  @CommsBinding(property = VDUOutputs.SELECTED_VEHICLE_IDX)
  PropertyKey<Integer> SELECTED_VEHICLE_IDX = create();

  @CommsBinding(property = VDUOutputs.TRAIN_ID)
  PropertyKey<Integer> TRAIN_ID = create();

  @CommsBinding(property = VDUOutputs.CAMERA_VIEW_BUTTONS_STATE)
  PropertyKey<byte[]> CAMERA_VIEW_BUTTONS_STATE = create();

  @CommsBinding(property = VDUOutputs.SELECTED_EXT_CAM_TYP)
  PropertyKey<Integer> SELECTED_EXT_CAM_TYP = create();

  @CommsBinding(property = VDUOutputs.NORMAL_OR_EVENT_VIEW)
  PropertyKey<Integer> NORMAL_OR_EVENT_VIEW = create();

  @CommsBinding(property = VDUOutputs.ALARM_ACTIVE_TYPE_INDEX)
  PropertyKey<Integer> ALARM_ACTIVE_TYPE_INDEX = create();

  @CommsBinding(property = VDUOutputs.FIRE_ALARM_1)
  PropertyKey<Integer> FIRE_ALARM_1 = create();

  @CommsBinding(property = VDUOutputs.OBSTCL_SALOON_DR_ALARM_2)
  PropertyKey<Integer> OBSTCL_SALOON_DR_ALARM_2 = create();

  @CommsBinding(property = VDUOutputs.PECU_ALARM_3)
  PropertyKey<Integer> PECU_ALARM_3 = create();

  @CommsBinding(property = VDUOutputs.DR_UNLK_ALARM_4)
  PropertyKey<Integer> DR_UNLK_ALARM_4 = create();

  @CommsBinding(property = VDUOutputs.EMRG_DR_OPN_ALARM_5)
  PropertyKey<Integer> EMRG_DR_OPN_ALARM_5 = create();

  @CommsBinding(property = VDUOutputs.DRVR_DSK_ALARM_6)
  PropertyKey<Integer> DRVR_DSK_ALARM_6 = create();

  @CommsBinding(property = VDUOutputs.OBSTRUCTION_DEFLCT_ALARM_7)
  PropertyKey<Integer> OBSTRUCTION_DEFLCT_ALARM_7 = create();

  @CommsBinding(property = VDUOutputs.TRACK_EVENT_ALARM_8)
  PropertyKey<Integer> TRACK_EVENT_ALARM_8 = create();

  @CommsBinding(property = VDUOutputs.EMRG_CCTV_ALARM_9)
  PropertyKey<Integer> EMRG_CCTV_ALARM_9 = create();

  @CommsBinding(property = VDUOutputs.OHE_ALARM_10)
  PropertyKey<Integer> OHE_ALARM_10 = create();

  @CommsBinding(property = VDUOutputs.PANTO_ALARM_11)
  PropertyKey<Integer> PANTO_ALARM_11 = create();

  @CommsBinding(property = VDUOutputs.CCTV_DISPLAY_HANGED_FAULT)
  PropertyKey<Integer> CCTV_DISPLAY_HANGED_FAULT = create();

  @CommsBinding(property = VDUOutputs.DETRAINMENT_CAMERA_STATE)
  PropertyKey<Integer> DETRAINMENT_CAMERA_STATE = create();
  
  @CommsBinding(property = VDUOutputs.CCTV_SETTING_QUIT_BUTTON_STATE)
  PropertyKey<Integer> CCTV_SETTING_QUIT_BUTTON_STATE = create();
  
  @CommsBinding(property = VDUOutputs.CCTV_SETTING_PANEL_STATE)
  PropertyKey<Integer> CCTV_SETTING_PANEL_STATE = create();
  
  @CommsBinding(property = VDUOutputs.CCTV_NORMAl_EVENT_SWITCH_STATE)
  PropertyKey<Integer> CCTV_NORMAl_EVENT_SWITCH_STATE = create();
  
  @CommsBinding(property = VDUOutputs.CCTV_DETRAINMENT_CAMERA_ID)
  PropertyKey<Integer> CCTV_DETRAINMENT_CAMERA_ID = create();
}

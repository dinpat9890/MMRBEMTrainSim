/*
 * ==================================================================
 *
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *
 * ==================================================================
 */
package com.sydac.mmrbem.tcms.fe.gui.binder;

import com.sydac.foundation.PropertyKey;
import com.sydac.mmrbem.tcms.common.io.properties.IAppOutputsCCTVScreenProperties;
import com.sydac.mmrbem.tcms.common.io.properties.IAppOutputsOperatingScreenProperties;
import com.sydac.mmrbem.tcms.common.io.properties.IAppOutputsTrainConfigurationProperties;
import com.sydac.mmrbem.tcms.fe.base.AbstractCommsListener;
import com.sydac.mmrbem.tcms.fe.gui.model.CCTVFooterPanelModel;

public class CCTVFooterPanelBinder extends AbstractCommsListener
{

  private CCTVFooterPanelModel cctvFooterPanelModel;

  public CCTVFooterPanelBinder(CCTVFooterPanelModel cctvFooterPanelModel)
  {
    this.cctvFooterPanelModel = cctvFooterPanelModel;
    propertyKeyDefinitions.add(IAppOutputsTrainConfigurationProperties.class);
    propertyKeyDefinitions.add(IAppOutputsCCTVScreenProperties.class);
    propertyKeyDefinitions.add(IAppOutputsOperatingScreenProperties.class);
  }

  @Override
  protected <T> void appOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue)
  {
    if (key.equals(IAppOutputsTrainConfigurationProperties.NUMBER_OF_CARS))
    {
      cctvFooterPanelModel.setNumberOfCars((Integer)newValue);
    }
    else if (key.equals(IAppOutputsCCTVScreenProperties.AUTO_ROTATION_ON))
    {
      cctvFooterPanelModel.setAutoRotationState((Integer)newValue);
    }
    else if (key.equals(IAppOutputsCCTVScreenProperties.EXTERNAL_OR_INTERNAL_VIEW))
    {
      cctvFooterPanelModel.setExternalOrInternalView((Integer)newValue);
    }
    else if (key.equals(IAppOutputsCCTVScreenProperties.SELECTED_VEHICLE_IDX))
    {
      cctvFooterPanelModel.setSelectedVehicleIndexProperty((Integer)newValue);
    }
    else if (key.equals(IAppOutputsOperatingScreenProperties.TRAIN_NUMBER))
    {
      cctvFooterPanelModel.setTrainId((Integer)newValue);
    }
    else if (key.equals(IAppOutputsCCTVScreenProperties.CAMERA_VIEW_BUTTONS_STATE))
    {
      cctvFooterPanelModel.updateCameraButtonList((byte[])newValue);
    }
    else if (key.equals(IAppOutputsCCTVScreenProperties.SELECTED_EXT_CAM_TYP))
    {
      cctvFooterPanelModel.setSelectedExternalCameraType((Integer)newValue);
    }
    else if (key.equals(IAppOutputsCCTVScreenProperties.NORMAL_OR_EVENT_VIEW))
    {
      cctvFooterPanelModel.setAlarmModeProperty((Integer)newValue);
    }
    else if (key.equals(IAppOutputsCCTVScreenProperties.ALARM_ACTIVE_TYPE_INDEX))
    {
      cctvFooterPanelModel.setAlarmTypeActive((Integer)newValue);
    }
    else if (key.equals(IAppOutputsCCTVScreenProperties.FIRE_ALARM_1))
    {
      cctvFooterPanelModel.setAlarmFire((Integer)newValue);
    }
    else if (key.equals(IAppOutputsCCTVScreenProperties.OBSTCL_SALOON_DR_ALARM_2))
    {
      cctvFooterPanelModel.setAlarmObstacle((Integer)newValue);
    }
    else if (key.equals(IAppOutputsCCTVScreenProperties.PECU_ALARM_3))
    {
      cctvFooterPanelModel.setAlarmPecu((Integer)newValue);
    }
    else if (key.equals(IAppOutputsCCTVScreenProperties.DR_UNLK_ALARM_4))
    {
      cctvFooterPanelModel.setAlarmDoorUnlock((Integer)newValue);
    }
    else if (key.equals(IAppOutputsCCTVScreenProperties.EMRG_DR_OPN_ALARM_5))
    {
      cctvFooterPanelModel.setAlarmEmergencyDoorOpen((Integer)newValue);
    }
    else if (key.equals(IAppOutputsCCTVScreenProperties.DRVR_DSK_ALARM_6))
    {
      cctvFooterPanelModel.setAlarmDriverDesk((Integer)newValue);
    }
    else if (key.equals(IAppOutputsCCTVScreenProperties.OBSTRUCTION_DEFLCT_ALARM_7))
    {
      cctvFooterPanelModel.setAlarmObstructionDeflection((Integer)newValue);
    }
    else if (key.equals(IAppOutputsCCTVScreenProperties.TRACK_EVENT_ALARM_8))
    {
      cctvFooterPanelModel.setAlarmTrackEvent((Integer)newValue);
    }
    else if (key.equals(IAppOutputsCCTVScreenProperties.EMRG_CCTV_ALARM_9))
    {
      cctvFooterPanelModel.setAlarmEmergency((Integer)newValue);
    }
    else if (key.equals(IAppOutputsCCTVScreenProperties.OHE_ALARM_10))
    {
      cctvFooterPanelModel.setAlarmOheEvent((Integer)newValue);
    }
    else if (key.equals(IAppOutputsCCTVScreenProperties.PANTO_ALARM_11))
    {
      cctvFooterPanelModel.setAlarmPantographEvent((Integer)newValue);
    }
    else if (key.equals(IAppOutputsOperatingScreenProperties.CURRENT_STATION))
    {
      cctvFooterPanelModel.setCurrentLocation((byte[])newValue);
    }
    else if (key.equals(IAppOutputsOperatingScreenProperties.NEXT_STATION))
    {
      cctvFooterPanelModel.setNextLocation((byte[])newValue);
    }
    else if (key.equals(IAppOutputsOperatingScreenProperties.LINE_DIRECTION_DETAIL))
    {
      cctvFooterPanelModel.setLineDetail((byte[])newValue);
    }
    else if (key.equals(IAppOutputsCCTVScreenProperties.CCTV_DISPLAY_HANGED_FAULT))
    {
      cctvFooterPanelModel.setCctvDisplayHangedFault((Integer)newValue);
    }else if (key.equals(IAppOutputsCCTVScreenProperties.DETRAINMENT_CAMERA_STATE))
    {
      cctvFooterPanelModel.setDetrainmentDoorFault((Integer)newValue);
    }
    else if (key.equals(IAppOutputsCCTVScreenProperties.CCTV_SETTING_QUIT_BUTTON_STATE))
    {
      cctvFooterPanelModel.setSettingQuitButtonState((Integer)newValue);
    }
    else if (key.equals(IAppOutputsCCTVScreenProperties.CCTV_SETTING_PANEL_STATE))
    {
      cctvFooterPanelModel.setSettingPanelState((Integer)newValue);
    }
    else if (key.equals(IAppOutputsCCTVScreenProperties.CCTV_NORMAl_EVENT_SWITCH_STATE))
    {
      cctvFooterPanelModel.setNormalEventSwitchState((Integer)newValue);
    }
    else if (key.equals(IAppOutputsCCTVScreenProperties.CCTV_DETRAINMENT_CAMERA_ID))
    {
      cctvFooterPanelModel.setDetraimentCameraId((Integer)newValue);
    }
  }

}

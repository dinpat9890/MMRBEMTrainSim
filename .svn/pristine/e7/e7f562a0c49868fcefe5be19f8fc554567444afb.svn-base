/*
 * ==================================================================
 * 
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.tcms.backend.logic.handler;

import org.springframework.stereotype.Service;

import com.sydac.foundation.PropertyKey;
import com.sydac.mmrbem.tcms.backend.comms.CommsBinding;
import com.sydac.mmrbem.tcms.backend.logic.AbstractFunctionalLogic;
import com.sydac.mmrbem.tcms.backend.logic.SharedDataModel;
import com.sydac.mmrbem.tcms.backend.logic.annotation.FunctionalLogicHandler;
import com.sydac.mmrbem.tcms.common.io.properties.IAppInputsProperties;
import com.sydac.mmrbem.tcms.common.io.properties.IAppInputsVDUSelectionPopupProperties;
import com.sydac.mmrbem.tcms.common.io.properties.IAppOutputsVduSelectionPopupProperties;
import com.sydac.mmrbem.tcms.common.state.VDUModeEnum;

/**
 * This handler class is used for VDU Selection handling.
 * 
 */
@Service
@FunctionalLogicHandler(arguments = { CommsBinding.class, SharedDataModel.class })
public class VduSelectionChangeHandler extends AbstractFunctionalLogic
{

  private SharedDataModel sharedDataModel;

  protected VduSelectionChangeHandler(CommsBinding commsBinding, SharedDataModel sharedDataModel)
  {
    super(commsBinding, IAppInputsProperties.class);
    this.sharedDataModel = sharedDataModel;
  }

  @Override
  public <T> void appInputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue, int vehicleIndex)
  {
    if (getActiveVehicleIndex() == vehicleIndex
        && key.equals(IAppInputsVDUSelectionPopupProperties.TCMS_VDU_BUTTON_REQUEST)
        && (Integer)newValue > -1)
    {
      if ((VDUModeEnum.VDU_HYBRID_MODE.getId() == (Integer)newValue
          && sharedDataModel.getVduSelectedMode() == VDUModeEnum.VDU_TCMS_MODE.getId())
          || VDUModeEnum.VDU_TCMS_MODE.getId() == (Integer)newValue)
      {
        setApplicationOutputsProperty(IAppOutputsVduSelectionPopupProperties.TCMS_VDU_BUTTON_SELECTED,
            (Integer)newValue);
      }
      else
      {
        setApplicationOutputsProperty(IAppOutputsVduSelectionPopupProperties.TCMS_VDU_BUTTON_SELECTED,
            (Integer)VDUModeEnum.VDU_CCTV_MODE.getId());
      }
      sharedDataModel.setVduSelectedMode((Integer)newValue);
    }
    else if (getActiveVehicleIndex() == vehicleIndex
        && key.equals(IAppInputsVDUSelectionPopupProperties.CCTV_VDU_BUTTON_REQUEST)
        && (Integer)newValue > -1)
    {
      if ((VDUModeEnum.VDU_HYBRID_MODE.getId() == (Integer)newValue
          && sharedDataModel.getCctvVduSelectedMode() == VDUModeEnum.VDU_TCMS_MODE.getId())
          || VDUModeEnum.VDU_TCMS_MODE.getId() == (Integer)newValue)
      {
        setApplicationOutputsProperty(IAppOutputsVduSelectionPopupProperties.CCTV_VDU_BUTTON_SELECTED,
            (Integer)newValue);
      }
      else
      {
        setApplicationOutputsProperty(IAppOutputsVduSelectionPopupProperties.CCTV_VDU_BUTTON_SELECTED,
            (Integer)VDUModeEnum.VDU_CCTV_MODE.getId());
      }
      sharedDataModel.setCctvVduSelectedMode((Integer)newValue);
    }
  }
}

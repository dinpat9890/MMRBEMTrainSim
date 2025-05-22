/*
 * 
 * ================================================================== (C)
 * Copyright 2020 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * ==================================================================
 */
package com.sydac.mmrbem.tcms.backend.logic.handler;

import org.springframework.stereotype.Service;

import com.sydac.foundation.PropertyKey;
import com.sydac.mmrbem.tcms.backend.comms.CommsBinding;
import com.sydac.mmrbem.tcms.backend.logic.AbstractFunctionalLogic;
import com.sydac.mmrbem.tcms.backend.logic.SharedDataModel;
import com.sydac.mmrbem.tcms.backend.logic.annotation.FunctionalLogicHandler;
import com.sydac.mmrbem.tcms.backend.vehicle.io.properties.IPISBEOutputsHybridPanelProperties;
import com.sydac.mmrbem.tcms.common.io.properties.IAppInputHybridModeScreenProperties;
import com.sydac.mmrbem.tcms.common.io.properties.IAppInputsProperties;
import com.sydac.mmrbem.tcms.common.io.properties.IAppInputsVDUSelectionPopupProperties;
import com.sydac.mmrbem.tcms.common.io.properties.IAppOutputsHybridModeScreenProperties;
import com.sydac.mmrbem.tcms.common.state.HybridPanelImageIdEnum;
import com.sydac.mmrbem.tcms.common.state.VDUModeEnum;
import com.sydac.mmrbem.tcms.common.utils.timer.CommsTimer;

/**
 * This handler class is used for handling Hybrid Mode screen data
 * 
 */
@Service
@FunctionalLogicHandler(arguments = { CommsBinding.class, SharedDataModel.class })
public class HybridModeScreenHandler extends AbstractFunctionalLogic
{

  private boolean trainInPlatformArea;

  private int currentImageId;

  private static final int TRAIN_INSIDE_PLATFORM_AREA = 1;

  private CommsTimer autoRotateTimer;

  private Runnable autoRotateRunnable = () -> {
    if (autoRotateTimer != null)
    {
      autoRotateTimer.safeCancel();
      setNextImageId();
      if (!autoRotateTimer.isRunning())
      {
        autoRotateTimer.start();
      }
    }
  };

  public HybridModeScreenHandler(CommsBinding commsBinding)
  {
    super(commsBinding, IAppInputsProperties.class, IPISBEOutputsHybridPanelProperties.class);
    updateHybridPanelImageId();
    autoRotateTimer = CommsTimer.newScheduledTimer(autoRotateRunnable, 5000);
  }

  /**
   * Update the initial image id to be set on Hybrid Panel by checking whether
   * train is in platform area or not.
   */
  private void updateHybridPanelImageId()
  {
    if (trainInPlatformArea)
    {
      setImageId(HybridPanelImageIdEnum.EXTERNAL_CAM_1.getImageId());
    }
    else
    {
      setImageId(HybridPanelImageIdEnum.INTERNAL_CAM_1.getImageId());
    }
  }

  /**
   * Sets the imageId to the FE variable
   * 
   * @param id
   */
  private void setImageId(int id)
  {
    currentImageId = id;
    setApplicationOutputsProperty(IAppOutputsHybridModeScreenProperties.HYBRID_PANEL_DISPLAY_IMAGE_ID,
        currentImageId);
  }

  @Override
  public <T> void appInputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue, int vehicleIndex)
  {
    if (IAppInputsVDUSelectionPopupProperties.TCMS_VDU_BUTTON_REQUEST.equals(key) && (Integer)newValue > -1)
    {
      if ((Integer)newValue == VDUModeEnum.VDU_HYBRID_MODE.getId())
      {
        if (!autoRotateTimer.isRunning())
        {
          autoRotateTimer.start();
        }
      }
      else
      {
        autoRotateTimer.safeCancel();
      }
    }
    if (key.equals(IAppInputHybridModeScreenProperties.ACTIVE_HYBRID_PANEL_SIDE_REQ))
    {
      setApplicationOutputsProperty(IAppOutputsHybridModeScreenProperties.ACTIVE_HYBRID_PANEL_SIDE,
          (Integer)newValue);
    }
    else if (key.equals(IAppInputHybridModeScreenProperties.HYBRID_PANEL_NEXT_IMAGE_BUTTON)
        && (Integer)newValue > -1)
    {
      autoRotateTimer.safeCancel();
      setNextImageId();
      autoRotateTimer.start();
    }
    else if (key.equals(IAppInputHybridModeScreenProperties.HYBRID_PANEL_PREV_IMAGE_BUTTON)
        && (Integer)newValue > -1)
    {
      autoRotateTimer.safeCancel();
      setPrevImageId();
      autoRotateTimer.start();
    }
  }

  private void setPrevImageId()
  {
    // if - else if blocks to change/navigate between the image id's on
    // Previous Arrow Button press
    if (currentImageId == HybridPanelImageIdEnum.INTERNAL_CAM_1.getImageId())
    {
      setImageId(HybridPanelImageIdEnum.INTERNAL_CAM_3.getImageId());
    }
    else if (currentImageId == HybridPanelImageIdEnum.EXTERNAL_CAM_1.getImageId())
    {
      setImageId(HybridPanelImageIdEnum.EXTERNAL_CAM_2.getImageId());
    }
    else if (currentImageId == HybridPanelImageIdEnum.EXTERNAL_CAM_2.getImageId())
    {
      setImageId(HybridPanelImageIdEnum.EXTERNAL_CAM_1.getImageId());
    }
    else
    {
      setImageId(currentImageId - 1);
    }
  }

  private void setNextImageId()
  {
    // if - else if blocks to change/navigate the image id's on Next Arrow
    // Button press
    if (currentImageId == HybridPanelImageIdEnum.INTERNAL_CAM_3.getImageId())
    {
      setImageId(HybridPanelImageIdEnum.INTERNAL_CAM_1.getImageId());
    }
    else if (currentImageId == HybridPanelImageIdEnum.EXTERNAL_CAM_1.getImageId())
    {
      setImageId(HybridPanelImageIdEnum.EXTERNAL_CAM_2.getImageId());
    }
    else if (currentImageId == HybridPanelImageIdEnum.EXTERNAL_CAM_2.getImageId())
    {
      setImageId(HybridPanelImageIdEnum.EXTERNAL_CAM_1.getImageId());
    }
    else
    {
      setImageId(currentImageId + 1);
    }
  }

  @Override
  public <T> void pisBeOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue, int vehicleIndex)
  {
    if (key.equals(IPISBEOutputsHybridPanelProperties.TCMS_TRAIN_NEAR_STATION))
    {
      trainInPlatformArea = (Integer)newValue == TRAIN_INSIDE_PLATFORM_AREA;
      // Calls update to change default int / ext image id as the train has
      // shifted its position between in and out of platform area.
      updateHybridPanelImageId();
    }
  }

}
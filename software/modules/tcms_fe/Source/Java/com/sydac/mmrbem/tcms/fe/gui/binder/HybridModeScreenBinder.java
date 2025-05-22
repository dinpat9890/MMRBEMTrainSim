/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.tcms.fe.gui.binder;

import com.sydac.foundation.PropertyKey;
import com.sydac.mmrbem.tcms.common.io.properties.IAppOutputsHybridModeScreenProperties;
import com.sydac.mmrbem.tcms.fe.base.AbstractCommsListener;
import com.sydac.mmrbem.tcms.fe.gui.model.HybridModeScreenModel;

public class HybridModeScreenBinder extends AbstractCommsListener
{

  private HybridModeScreenModel hybridModeScreenModel;

  public HybridModeScreenBinder(HybridModeScreenModel hybridModeScreenModel)
  {
    super();
    this.hybridModeScreenModel = hybridModeScreenModel;
    propertyKeyDefinitions.add(IAppOutputsHybridModeScreenProperties.class);
  }

  @Override
  protected <T> void appOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue)
  {
    if (key.equals(IAppOutputsHybridModeScreenProperties.ACTIVE_HYBRID_PANEL_SIDE))
    {
      hybridModeScreenModel.setHybridPanelActiveSide((Integer)newValue);
    }
    else if (key.equals(IAppOutputsHybridModeScreenProperties.HYBRID_PANEL_DISPLAY_IMAGE_ID))
    {
      hybridModeScreenModel.setCurrentImageId((Integer)newValue);
    }
  }
}

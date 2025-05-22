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
import com.sydac.mmrbem.tcms.common.io.properties.IAppOutputsFaultDetailsScreenProperties;
import com.sydac.mmrbem.tcms.fe.base.AbstractCommsListener;
import com.sydac.mmrbem.tcms.fe.gui.model.FaultDetailsScreenModel;

public class FaultDetailsScreenBinder extends AbstractCommsListener
{

  private FaultDetailsScreenModel faultDetailsScreenModel;

  public FaultDetailsScreenBinder(FaultDetailsScreenModel faultDetailsScreenModel)
  {
    super();
    this.faultDetailsScreenModel = faultDetailsScreenModel;
    propertyKeyDefinitions.add(IAppOutputsFaultDetailsScreenProperties.class);
  }

  @Override
  protected <T> void appOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue)
  {
    if (IAppOutputsFaultDetailsScreenProperties.FAULT_DETAILS_INFO.equals(key))
    {
      faultDetailsScreenModel.setFaultDetailsInfo((byte[])newValue);
    }
    else if (IAppOutputsFaultDetailsScreenProperties.PREVIOUS_SCREEN_ID_TO_FAULT_DETAILS.equals(key))
    {
      faultDetailsScreenModel.setCloseToPreviousScreenId((Integer)newValue);
    }
  }
}

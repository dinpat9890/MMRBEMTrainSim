/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.tcms.fe.gui.binder;

import com.sydac.foundation.PropertyKey;
import com.sydac.mmrbem.tcms.common.io.properties.IAppOutputsMiscellaniaScreenProperties;
import com.sydac.mmrbem.tcms.fe.base.AbstractCommsListener;
import com.sydac.mmrbem.tcms.fe.gui.model.MiscellaniaScreenModel;

public class MiscellaniaScreenBinder extends AbstractCommsListener
{
  private MiscellaniaScreenModel miscellaniaScreenModel;

  public MiscellaniaScreenBinder(MiscellaniaScreenModel miscellaniaScreenModel)
  {
    // super();
    this.miscellaniaScreenModel = miscellaniaScreenModel;
    propertyKeyDefinitions.add(IAppOutputsMiscellaniaScreenProperties.class);

  }

  @Override
  protected <T> void appOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue)
  {
    if (key.equals(IAppOutputsMiscellaniaScreenProperties.HORN_ISOLATE_RESINSERT_FRONT_STATUS))
    {
      miscellaniaScreenModel.setHornIsolateReinsertFrontStatus((Integer)newValue);
    }
    else if (key.equals(IAppOutputsMiscellaniaScreenProperties.HORN_ISOLATE_RESINSERT_REAR_STATUS))
    {
      miscellaniaScreenModel.setHornIsolateReinsertRearStatus((Integer)newValue);
    }
    else if (key.equals(IAppOutputsMiscellaniaScreenProperties.MISC_DERAILMENT_DETECTED_LEFT))
    {

      miscellaniaScreenModel.setDerailmentDetectedLeftState((byte[])newValue);
    }
    else if (key.equals(IAppOutputsMiscellaniaScreenProperties.MISC_DERAILMENT_DETECTED_RIGHT))
    {
      miscellaniaScreenModel.setDerailmentDetectedRightState((byte[])newValue);
    }
    else if (key.equals(IAppOutputsMiscellaniaScreenProperties.MISC_OBSTRUCTION_DETECTED_LEFT))
    {
      miscellaniaScreenModel.setObstructionDetectedLeftState((byte[])newValue);
    }
    else if (key.equals(IAppOutputsMiscellaniaScreenProperties.MISC_OBSTRUCTION_DETECTED_RIGHT))
    {
      miscellaniaScreenModel.setObstructionDetectedRightState((byte[])newValue);
    }

  }
}

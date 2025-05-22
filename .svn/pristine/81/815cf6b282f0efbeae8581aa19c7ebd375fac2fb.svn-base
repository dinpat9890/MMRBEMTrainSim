/*
 * ==================================================================
 * 
 * (C) Copyright 2024 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.tcms.fe.gui.binder;

import com.sydac.foundation.PropertyKey;
import com.sydac.mmrbem.tcms.common.io.properties.IAppOutputsPISScreenProperties;
import com.sydac.mmrbem.tcms.fe.base.AbstractCommsListener;
import com.sydac.mmrbem.tcms.fe.gui.model.PISSystemScreenModel;

public class PISSystemScreenBinder extends AbstractCommsListener
{

  private PISSystemScreenModel pisSystemScreenModel;

  public PISSystemScreenBinder(PISSystemScreenModel systemScreenModel)
  {
    super();
    this.pisSystemScreenModel = systemScreenModel;
    propertyKeyDefinitions.add(IAppOutputsPISScreenProperties.class);
  }

  @Override
  protected <T> void appOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue)
  {
    if (IAppOutputsPISScreenProperties.PECU_CALL_VEHICLE_INDEX.equals(key))
    {
      pisSystemScreenModel.setPecuCallVehicleIndex((Integer)newValue);
    }
    else if (IAppOutputsPISScreenProperties.PECU_CALL_INDEX.equals(key))
    {
      pisSystemScreenModel.setPecuCallId((Integer)newValue);
    }
    else if (IAppOutputsPISScreenProperties.PECU_CALL_STATUS.equals(key))
    {
      pisSystemScreenModel.setPecuCallStatus((Integer)newValue);
    }
    else if (IAppOutputsPISScreenProperties.PECU_CALL_RESET_STATUS.equals(key))
    {
      pisSystemScreenModel.setPecuCallResetStatus((Integer)newValue);
    }
    else if (IAppOutputsPISScreenProperties.TCMS_ISOLATION_DEISOLATION_LIST.equals(key))
    {
      pisSystemScreenModel.setIsolationDeState((byte[])newValue);
    }
    else if (IAppOutputsPISScreenProperties.PABR_STATUS_DM1.equals(key))
    {
      pisSystemScreenModel.setPabrStatus((Integer)newValue);
    }
    else if (IAppOutputsPISScreenProperties.PABR_STATUS_DM2.equals(key))
    {
      pisSystemScreenModel.setPabrStatusDm2((Integer)newValue);
    }
    else if (IAppOutputsPISScreenProperties.PABOR_STATUS_DM1.equals(key))
    {
      pisSystemScreenModel.setPaborStatusDm1((Integer)newValue);
    }
    else if (IAppOutputsPISScreenProperties.PABOR_STATUS_DM2.equals(key))
    {
      pisSystemScreenModel.setPaborStatusDm2((Integer)newValue);
    }

  }
}

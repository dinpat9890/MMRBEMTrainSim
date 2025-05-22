/*
 * ================================================================== (C)
 * Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.radio.fe.gui.binder;

import com.sydac.foundation.PropertyKey;
import com.sydac.mmrbem.radio.common.io.properties.IAppOutputCabSignalProperties;
import com.sydac.mmrbem.radio.fe.base.AbstractCommsListener;
import com.sydac.mmrbem.radio.fe.gui.model.CabSignalPanelModel;

/**
 * The Class CabSignalPanelBinder used to read cab signal info values from comms
 * and assign it to the model {@link CabSignalPanelModel}
 * 
 * @author ext-tambet
 */
public class CabSignalPanelBinder extends AbstractCommsListener
{
  private CabSignalPanelModel cabSignalPanelModel;

  public CabSignalPanelBinder(CabSignalPanelModel cabSignalPanelModel)
  {
    propertyKeyDefinitions.add(IAppOutputCabSignalProperties.class);
    this.cabSignalPanelModel = cabSignalPanelModel;
  }

  @Override
  protected <T> void appOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue)
  {
    if (IAppOutputCabSignalProperties.TRIU_A_STATUS.equals(key))
    {
      cabSignalPanelModel.setTriuAStatus((Integer)newValue);
    }
    else if (IAppOutputCabSignalProperties.OCC_PA_STATUS.equals(key))
    {
      cabSignalPanelModel.setOccPaStatus((Integer)newValue);
    }
    else if (IAppOutputCabSignalProperties.TRIU_B_STATUS.equals(key))
    {
      cabSignalPanelModel.setTriuBStatus((Integer)newValue);
    }
    else if (IAppOutputCabSignalProperties.TCMS_A_STATUS.equals(key))
    {
      cabSignalPanelModel.setTcmsAStatus((Integer)newValue);
    }
    else if (IAppOutputCabSignalProperties.TCMS_B_STATUS.equals(key))
    {
      cabSignalPanelModel.setTcmsBStatus((Integer)newValue);
    }
    else if (IAppOutputCabSignalProperties.REMOTE_STATUS.equals(key))
    {
      cabSignalPanelModel.setRemoteStatus((Integer)newValue);
    }
    else if (IAppOutputCabSignalProperties.CAB_A_STATUS.equals(key))
    {
      cabSignalPanelModel.setCabAStatus((Integer)newValue);
    }
    else if (IAppOutputCabSignalProperties.CAB_B_STATUS.equals(key))
    {
      cabSignalPanelModel.setCabBStatus((Integer)newValue);
    }
    else if (IAppOutputCabSignalProperties.PA_PIS_A_STATUS.equals(key))
    {
      cabSignalPanelModel.setPaPisAStatus((Integer)newValue);
    }
    else if (IAppOutputCabSignalProperties.PA_PIS_B_STATUS.equals(key))
    {
      cabSignalPanelModel.setPaPisBStatus((Integer)newValue);
    }
    else if (IAppOutputCabSignalProperties.TR_A_STATUS.equals(key))
    {
      cabSignalPanelModel.setTrAStatus((Integer)newValue);
    }
    else if (IAppOutputCabSignalProperties.TR_B_STATUS.equals(key))
    {
      cabSignalPanelModel.setTrBStatus((Integer)newValue);
    }
  }
}

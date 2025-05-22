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
import com.sydac.mmrbem.tcms.common.io.properties.IAppOutputsAPSSystemScreenProperties;
import com.sydac.mmrbem.tcms.common.io.properties.IAppOutputsHighVolatageSystemCommandsScreenProperties;
import com.sydac.mmrbem.tcms.common.io.properties.IAppOutputsPropulsionSystemScreenProperties;
import com.sydac.mmrbem.tcms.common.io.properties.IAppOutputsTrainSideViewComponentProperties;
import com.sydac.mmrbem.tcms.common.io.properties.IAppOutputsTrainTopViewComponentProperties;
import com.sydac.mmrbem.tcms.fe.base.AbstractCommsListener;
import com.sydac.mmrbem.tcms.fe.gui.model.HighVoltageScreenModel;

public class HighVoltageScreenBinder extends AbstractCommsListener
{

  private HighVoltageScreenModel highVoltageScreenModel;

  public HighVoltageScreenBinder(HighVoltageScreenModel highVoltageScreenModel)
  {
    super();
    this.highVoltageScreenModel = highVoltageScreenModel;

    propertyKeyDefinitions.add(IAppOutputsTrainSideViewComponentProperties.class);
    propertyKeyDefinitions.add(IAppOutputsTrainTopViewComponentProperties.class);
    propertyKeyDefinitions.add(IAppOutputsPropulsionSystemScreenProperties.class);
    propertyKeyDefinitions.add(IAppOutputsAPSSystemScreenProperties.class);
    propertyKeyDefinitions.add(IAppOutputsHighVolatageSystemCommandsScreenProperties.class);
   
  }

  @Override
  protected <T> void appOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue)
  {
    if (IAppOutputsTrainSideViewComponentProperties.PANTOGRAPH_STATUS.equals(key))
    {
      highVoltageScreenModel.setPantographState((byte[])newValue);
    }
    else if (IAppOutputsTrainSideViewComponentProperties.VCB_STATUS.equals(key))
    {
      highVoltageScreenModel.setVcbState((byte[])newValue);
    }
    else if (IAppOutputsAPSSystemScreenProperties.AK_STATUS.equals(key))
    {
      highVoltageScreenModel.setAkState((byte[])newValue);
    }
    else if (IAppOutputsAPSSystemScreenProperties.K_STATUS.equals(key))
    {
      highVoltageScreenModel.setKState((byte[])newValue);
    }
    else if (IAppOutputsPropulsionSystemScreenProperties.AK_CONTACTOR_STATUS.equals(key))
    {
      highVoltageScreenModel.setAkContactorState((byte[])newValue);
    }
    else if (IAppOutputsTrainSideViewComponentProperties.CI_STATUS.equals(key))
    {
      highVoltageScreenModel.setCIState((byte[])newValue);
    }
    else if (IAppOutputsPropulsionSystemScreenProperties.K_CONTACTOR_STATUS.equals(key))
    {
      highVoltageScreenModel.setKContactorState((byte[])newValue);
    }
    else if (IAppOutputsAPSSystemScreenProperties.APS_CONTROL_UNIT_STATUS.equals(key))
    {
      highVoltageScreenModel.setAPSState((byte[])newValue);
    }
    else if (IAppOutputsHighVolatageSystemCommandsScreenProperties.RISE_SELECTED_PANTO.equals(key))
    {
      highVoltageScreenModel.setRiseSelectedState((Integer)newValue);
    }
    else if (IAppOutputsHighVolatageSystemCommandsScreenProperties.REQ_VCB_NS_STATUS.equals(key))
    {
      highVoltageScreenModel.setReqCtrlVcbNsStatusProperty((Integer)newValue);
    } else if (IAppOutputsHighVolatageSystemCommandsScreenProperties.HV_PANTO_LOW_ALL_CAR_STATE.equals(key))
    {
      highVoltageScreenModel.setPantoLowAllCarstate((Integer)newValue);
    }else if (IAppOutputsHighVolatageSystemCommandsScreenProperties.ISOLATE_CI_FRONT_CAR_STATE.equals(key))
    {
      highVoltageScreenModel.setIsolateCiFrontCarState((Integer)newValue);
    }else if (IAppOutputsHighVolatageSystemCommandsScreenProperties.ISOLATE_CI_REAR_CAR_STATE.equals(key))
    {
      highVoltageScreenModel.setIsolateCiRearCarState((Integer)newValue);
    }else if (IAppOutputsHighVolatageSystemCommandsScreenProperties.ISOLATE_CI_M1_STATE.equals(key))
    {
      highVoltageScreenModel.setIsolateM1State((Integer)newValue);
    }else if (IAppOutputsHighVolatageSystemCommandsScreenProperties.ISOLATE_CI_M2_STATE.equals(key))
    {
      highVoltageScreenModel.setIsolateM2State((Integer)newValue);
    }else if (IAppOutputsHighVolatageSystemCommandsScreenProperties.ISOLATE_CI_M3_STATE.equals(key))
    {
      highVoltageScreenModel.setIsolateM3State((Integer)newValue);
    }else if (IAppOutputsHighVolatageSystemCommandsScreenProperties.HV_COMMOND_SELECTED_CAR_INDEX_LIST
        .equals(key))
    {
      highVoltageScreenModel.setHvSelectedCarIndexList((byte[])newValue);
    }
    
  }

}

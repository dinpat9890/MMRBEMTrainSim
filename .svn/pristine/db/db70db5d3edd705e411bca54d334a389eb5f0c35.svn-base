/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.tcms.fe.gui.binder;

import com.sydac.foundation.PropertyKey;
import com.sydac.mmrbem.tcms.common.io.properties.IAppOutputsECNScreenProperties;
import com.sydac.mmrbem.tcms.fe.base.AbstractCommsListener;
import com.sydac.mmrbem.tcms.fe.gui.model.TCMSEthernetConsistNetworkScreenModel;

public class TCMSEthernetConsistNetworkScreenBinder extends AbstractCommsListener
{

  private TCMSEthernetConsistNetworkScreenModel tcmsEthernetConsistNetworkScreenModel;

  public TCMSEthernetConsistNetworkScreenBinder(
      TCMSEthernetConsistNetworkScreenModel tcmsEthernetConsistNetworkScreenModel)
  {
    this.tcmsEthernetConsistNetworkScreenModel = tcmsEthernetConsistNetworkScreenModel;
    propertyKeyDefinitions.add(IAppOutputsECNScreenProperties.class);
  }

  @Override
  protected <T> void appOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue)
  {
    if (IAppOutputsECNScreenProperties.ECN_CS_A_STATUS_LIST.equals(key))
    {
      tcmsEthernetConsistNetworkScreenModel.setComponentSwitchAState((byte[])newValue);
    }
    else if (IAppOutputsECNScreenProperties.ECN_CS_B_STATUS_LIST.equals(key))
    {
      tcmsEthernetConsistNetworkScreenModel.setComponentSwitchBState((byte[])newValue);
    }
    else if (IAppOutputsECNScreenProperties.ECN_CS_C_STATUS_LIST.equals(key))
    {
      tcmsEthernetConsistNetworkScreenModel.setComponentSwitchCState((byte[])newValue);
    }
    else if (IAppOutputsECNScreenProperties.ECN_TBN_STATUS_LIST.equals(key))
    {
      tcmsEthernetConsistNetworkScreenModel.setTrainBackboneNodeState((byte[])newValue);
    }
    else if (IAppOutputsECNScreenProperties.ECN_TER_STATUS_LIST.equals(key))
    {
      tcmsEthernetConsistNetworkScreenModel.setTrainEthernetRepeaterState((byte[])newValue);
    }
    else if (IAppOutputsECNScreenProperties.ECN_ALG_STATUS_LIST.equals(key))
    {
      tcmsEthernetConsistNetworkScreenModel.setALGState((byte[])newValue);
    }
  }
}

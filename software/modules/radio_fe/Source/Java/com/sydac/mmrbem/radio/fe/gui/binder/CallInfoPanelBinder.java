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
import com.sydac.mmrbem.radio.common.io.properties.IAppOutputCallInfoProperties;
import com.sydac.mmrbem.radio.fe.base.AbstractCommsListener;
import com.sydac.mmrbem.radio.fe.gui.model.CallInfoPanelModel;

/**
 * The Class CallInfoPanelBinder used to read call info values from comms and
 * assign it to the model {@link CallInfoPanelModel}
 * 
 * @author ext-tambet
 */
public class CallInfoPanelBinder extends AbstractCommsListener
{

  private CallInfoPanelModel callInfoPanelModel;

  public CallInfoPanelBinder(CallInfoPanelModel callInfoPanelModel)
  {
    this.callInfoPanelModel = callInfoPanelModel;
    propertyKeyDefinitions.add(IAppOutputCallInfoProperties.class);
  }

  @Override
  protected <T> void appOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue)
  {

    if (IAppOutputCallInfoProperties.CALL_GROUP_STATUS.equals(key))
    {
      callInfoPanelModel.setCallGroupStatus((Integer)newValue);
    }
    else if (IAppOutputCallInfoProperties.CALL_GROUP_NAME.equals(key))
    {
      callInfoPanelModel.setCallGroupName(new String((byte[])newValue));
    }
    else if (IAppOutputCallInfoProperties.CALL_SSI_ID.equals(key))
    {
      callInfoPanelModel.setCallSsiId((Integer)newValue);
    }
    else if (IAppOutputCallInfoProperties.INPUT_SSI_ID.equals(key))
    {
      callInfoPanelModel.setInputSsiId((Integer)newValue);
    }
    else if (IAppOutputCallInfoProperties.INCOMING_CALL_NAME.equals(key))
    {
      callInfoPanelModel.setIncomingCallGroupName(new String((byte[])newValue));
    } 
    else if (key == IAppOutputCallInfoProperties.DEPOT_INDICATION)
    {
      callInfoPanelModel.setDepotIndication((Integer)newValue);
    }
  }

}

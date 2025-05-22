/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.tcms.fe.gui.binder;

import com.sydac.foundation.PropertyKey;
import com.sydac.mmrbem.tcms.common.io.properties.IAppOutputsDataLoadingProperties;
import com.sydac.mmrbem.tcms.fe.base.AbstractCommsListener;
import com.sydac.mmrbem.tcms.fe.gui.model.DataLoadingModel;

public class DataLoadingBinder extends AbstractCommsListener
{
  private DataLoadingModel dataLoadingModel;

  public DataLoadingBinder(DataLoadingModel dataLoadingModel)
  {
    super();
    this.dataLoadingModel = dataLoadingModel;
    propertyKeyDefinitions.add(IAppOutputsDataLoadingProperties.class);
  }

  @Override
  protected <T> void appOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue)
  {
    if (IAppOutputsDataLoadingProperties.DATA_LOADING_SEQUENCE.equals(key))
    {
      dataLoadingModel.setProgressMessageId((Integer)newValue);
    }
  }
}

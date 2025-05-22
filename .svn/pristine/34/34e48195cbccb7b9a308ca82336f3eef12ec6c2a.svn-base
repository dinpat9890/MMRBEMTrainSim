/*******************************************************************************
 * (C) Copyright 2023 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.papis.fe.gui.binder;

import com.sydac.foundation.PropertyKey;
import com.sydac.mmrbem.papis.common.io.properties.IAppOutputsCommonProperties;
import com.sydac.mmrbem.papis.common.io.properties.IAppOutputsScreenChangeProperties;
import com.sydac.mmrbem.papis.fe.base.AbstractCommsListener;
import com.sydac.mmrbem.papis.fe.gui.model.HeaderDateTimeModel;

public class HeaderStatusBinder extends AbstractCommsListener
{

  private HeaderDateTimeModel headerStatusModel;

  public HeaderStatusBinder(HeaderDateTimeModel papisCommonPanelModel)
  {
    this.headerStatusModel = papisCommonPanelModel;
    propertyKeyDefinitions.add(IAppOutputsScreenChangeProperties.class);
    propertyKeyDefinitions.add(IAppOutputsCommonProperties.class);
  }

  @Override
  protected <T> void appOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue)
  {
    if (IAppOutputsScreenChangeProperties.HEADER_PANEL_STATUS_LABEL_ID.equals(key))
    {
      headerStatusModel.setHeaderStatusLabelId((Integer)newValue);
    }else if (IAppOutputsCommonProperties.NUMBER_OF_CARS.equals(key))
    {
      headerStatusModel.setTotalCar((Integer)newValue);
    }
  }

}

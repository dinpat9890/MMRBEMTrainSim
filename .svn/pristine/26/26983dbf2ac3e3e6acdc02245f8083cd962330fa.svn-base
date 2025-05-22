/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.papis.fe.gui.binder;

import com.sydac.foundation.PropertyKey;
import com.sydac.mmrbem.papis.common.io.properties.IAppOutputsCommonProperties;
import com.sydac.mmrbem.papis.common.io.properties.IAppOutputsRouteSettingScreenProperties;
import com.sydac.mmrbem.papis.fe.base.AbstractCommsListener;
import com.sydac.mmrbem.papis.fe.gui.model.RouteSettingScreenModel;

public class RouteSettingScreenBinder extends AbstractCommsListener
{

  private RouteSettingScreenModel routeSettingScreenModel;

  public RouteSettingScreenBinder(RouteSettingScreenModel routeSettingScreenModel)
  {
    this.routeSettingScreenModel = routeSettingScreenModel;
    propertyKeyDefinitions.add(IAppOutputsRouteSettingScreenProperties.class);
    propertyKeyDefinitions.add(IAppOutputsCommonProperties.class);
  }

  @Override
  protected <T> void appOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue)
  {
    if (IAppOutputsRouteSettingScreenProperties.LINE_LIST.equals(key))
    {
      routeSettingScreenModel.setLineList((byte[])newValue);
    }
    else if (IAppOutputsCommonProperties.CURRENT_LINE_NAME.equals(key))
    {
      routeSettingScreenModel.setLineNameProperty((byte[])newValue);
    }
  }

}

/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.tcms.fe.gui.binder;

import com.sydac.foundation.PropertyKey;
import com.sydac.mmrbem.tcms.common.io.properties.IAppOutputsFooterSubmenuPopupProperties;
import com.sydac.mmrbem.tcms.fe.base.AbstractCommsListener;
import com.sydac.mmrbem.tcms.fe.gui.model.FooterSubmenuPopupModel;

public class FooterSubmenuPopupBinder extends AbstractCommsListener
{
  FooterSubmenuPopupModel footerSubmenuPopupModel;

  public FooterSubmenuPopupBinder(FooterSubmenuPopupModel footerSubmenuPopupModel)
  {
    this.footerSubmenuPopupModel = footerSubmenuPopupModel;
    propertyKeyDefinitions.add(IAppOutputsFooterSubmenuPopupProperties.class);
  }

  @Override
  protected <T> void appOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue)
  {
    if (IAppOutputsFooterSubmenuPopupProperties.FOOTER_POPUP_ID.equals(key))
    {
      footerSubmenuPopupModel.setFooterSubmenuPopupId((Integer)newValue);
    }
  }

}

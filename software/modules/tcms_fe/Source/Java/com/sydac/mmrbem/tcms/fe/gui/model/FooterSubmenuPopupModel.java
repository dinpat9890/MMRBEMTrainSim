/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.tcms.fe.gui.model;

import com.sydac.mmrbem.cabscreens.fe.gui.model.AbstractScreenModel;

import javafx.beans.property.IntegerProperty;
import javafx.beans.property.SimpleIntegerProperty;

public class FooterSubmenuPopupModel extends AbstractScreenModel
{

  private IntegerProperty footerSubmenuPopupId = new SimpleIntegerProperty();

  public FooterSubmenuPopupModel(int carIndex)
  {
    super(carIndex);
  }

  public IntegerProperty getFooterSubmenuPopupId()
  {
    return footerSubmenuPopupId;
  }

  public void setFooterSubmenuPopupId(Integer footerSubmenuPopupId)
  {
    this.footerSubmenuPopupId.set(footerSubmenuPopupId);
  }

}

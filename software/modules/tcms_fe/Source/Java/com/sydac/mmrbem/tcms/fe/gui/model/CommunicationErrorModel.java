/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.tcms.fe.gui.model;

import com.sydac.mmrbem.cabscreens.fe.gui.model.AbstractScreenModel;
import com.sydac.mmrbem.tcms.common.io.properties.IAppDataCommunicationErrorOutputHandler;

import javafx.beans.property.SimpleStringProperty;
import javafx.beans.property.StringProperty;

public class CommunicationErrorModel extends AbstractScreenModel
    implements IAppDataCommunicationErrorOutputHandler
{

  private StringProperty topBtn = new SimpleStringProperty();

  public CommunicationErrorModel(int carIndex)
  {
    super(carIndex);
  }

  public StringProperty getTopBtn()
  {
    return topBtn;
  }

  public void setTopBtn(StringProperty topBtn)
  {
    this.topBtn = topBtn;
  }

  @Override
  public void getCommunicationError(String error)
  {
    // TODO Auto-generated method stub

  }

}

/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.tcms.fe.gui.presenter;

import com.sydac.mmrbem.cabscreens.fe.gui.AbstractController;
import com.sydac.mmrbem.tcms.fe.gui.model.CommunicationErrorModel;

import javafx.beans.value.ChangeListener;
import javafx.fxml.FXML;
import javafx.scene.control.Button;

public class CommunicationErrorController extends AbstractController
{

  @FXML
  private Button topBtn;

  private ChangeListener<Number> topBtnListener;

  private CommunicationErrorModel communicationErrorModel;

  @Override
  public void initializeImpl()
  {
    communicationErrorModel = new CommunicationErrorModel(scenarioCarIndex);
  }

  @Override
  public void removeListeners()
  {
    // TODO Auto-generated method stub
  }

}

/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.radio.fe.gui.presenter;

import com.sydac.mmrbem.radio.common.state.CallType;
import com.sydac.mmrbem.radio.fe.gui.AbstractRadioController;
import com.sydac.mmrbem.radio.fe.gui.binder.CallInfoPanelBinder;
import com.sydac.mmrbem.radio.fe.gui.binder.MainMenuBinder;
import com.sydac.mmrbem.radio.fe.gui.model.CallInfoPanelModel;
import com.sydac.mmrbem.radio.fe.gui.model.MainMenuModel;

import javafx.beans.value.ChangeListener;
import javafx.fxml.FXML;
import javafx.scene.layout.GridPane;

/**
 * Provides common infrastructure like grid pane containers and labels for Radio
 * Common Screen Screen Area
 * 
 * @author mulukg
 */
public class MainMenuController extends AbstractRadioController
{

  @FXML
  private GridPane mainGrid;

  private MainMenuModel mainMenuModel;

  private ChangeListener<Number> callTypeListener;

  @Override
  public void detachListeners()
  {
    mainMenuModel.getCallType().removeListener(callTypeListener);
  }

  @Override
  public void initializeImpl()
  {
    mainMenuModel = new MainMenuModel(scenarioCarIndex);
    radioScreenBinders.add(new MainMenuBinder(mainMenuModel));

    callTypeListener = (observable, oldVal, newVal) -> updateEmergencyLayout(newVal.intValue());
    mainMenuModel.getCallType().addListener(callTypeListener);
    updateEmergencyLayout( mainMenuModel.getCallType().get());
  }

  private void updateEmergencyLayout(int callType)
  {
    if (callType == CallType.RADIO_EMERGNECY.getValue())
    {
      mainGrid.setStyle("-fx-background-color: red");
    }
    else
    {
      mainGrid.setStyle("-fx-background-color: -fx-black-color");
    }

  }

}

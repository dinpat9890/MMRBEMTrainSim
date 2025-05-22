/*
 * ================================================================== (C)
 * Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.radio.fe.gui.presenter;

import com.sydac.mmrbem.radio.fe.gui.AbstractRadioController;
import com.sydac.mmrbem.radio.fe.gui.binder.VolumeScreenBinder;
import com.sydac.mmrbem.radio.fe.gui.model.VolumeScreenModel;

import javafx.beans.value.ChangeListener;
import javafx.fxml.FXML;
import javafx.scene.layout.StackPane;

public class VolumeScreenController extends AbstractRadioController
{

  @FXML
  private StackPane stackpane;

  private VolumeScreenModel volumeScreenModel;

  private ChangeListener<Number> upBtnListener;

  private ChangeListener<Number> downBtnListener;

  RingProgressIndicator indicator;

  @Override
  public void detachListeners()
  {
    volumeScreenModel.getUpBtnStatus().removeListener(upBtnListener);
    volumeScreenModel.getDownBtnStatus().removeListener(downBtnListener);
  }

  @Override
  public void initializeImpl()
  {
    volumeScreenModel = new VolumeScreenModel(scenarioCarIndex);
    radioScreenBinders.add(new VolumeScreenBinder(volumeScreenModel));

    indicator = new RingProgressIndicator();

    stackpane.getChildren().add(indicator);
    // indicator.getStylesheets().add("radio-application.css");

    indicator.setRingWidth(200);
    indicator.makeIndeterminate();
    indicator.setProgress(50);

    upBtnListener = ((observable, oldVal,
        newVal) -> updateUpProgress(volumeScreenModel.getUpBtnStatus().get()));
    volumeScreenModel.getUpBtnStatus().addListener(upBtnListener);

    downBtnListener = ((observable, oldVal,
        newVal) -> updateDownProgress(volumeScreenModel.getDownBtnStatus().get()));
    volumeScreenModel.getDownBtnStatus().addListener(downBtnListener);

  }

  private void updateDownProgress(int status)
  {
    if (indicator.progressProperty().get() > 0)
    {
      indicator.setProgress(indicator.progressProperty().get() - 10);
    }

  }

  private void updateUpProgress(int status)
  {

    indicator.setProgress(indicator.progressProperty().get() + 10);
  }

}

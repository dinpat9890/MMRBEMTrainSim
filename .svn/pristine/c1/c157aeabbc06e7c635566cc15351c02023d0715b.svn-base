/*
 * ==================================================================
 * 
 * (C) Copyright 2020 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.dmi.fe.gui.presenter;

import java.util.HashMap;
import java.util.Map;

import com.sydac.mmrbem.cabscreens.fe.common.NodePseudoClassProperty;
import com.sydac.mmrbem.dmi.common.state.DMIAudioModeEnum;
import com.sydac.mmrbem.dmi.common.state.DMIConstants;
import com.sydac.mmrbem.dmi.fe.base.DMIFactory;
import com.sydac.mmrbem.dmi.fe.gui.AbstractDMIController;
import com.sydac.mmrbem.dmi.fe.gui.binder.MainScreenBinder;
import com.sydac.mmrbem.dmi.fe.gui.model.MainScreenModel;
import com.sydac.project.runtimedata.ProjectObjectConstants.DMIInputs;

import javafx.beans.value.ChangeListener;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.Label;

/**
 * Controller for Audio Panel fxml
 * 
 * @author ext-vp
 */
public class DMIAudioPanelController extends AbstractDMIController
{

  @FXML
  private Button closeBtn;

  @FXML
  private Button minusBtn;

  @FXML
  private Button plusBtn;

  @FXML
  private Label progressLbl1;

  @FXML
  private Label progressLbl2;

  @FXML
  private Label progressLbl3;

  @FXML
  private Label progressLbl4;

  @FXML
  private Label progressLbl5;

  private ChangeListener<Number> selectedAudioValueListener;

  private NodePseudoClassProperty audio20LabelProperty;

  private NodePseudoClassProperty audio40LabelProperty;

  private NodePseudoClassProperty audio60LabelProperty;

  private NodePseudoClassProperty audio80LabelProperty;

  private NodePseudoClassProperty audio100LabelProperty;

  private Map<Integer, NodePseudoClassProperty> progressBarMap = new HashMap<>();

  private MainScreenModel mainScreenModel;

  @Override
  public void initializeImpl()
  {
    mainScreenModel = new MainScreenModel(scenarioCarIndex);
    dmiScreenBinders.add(new MainScreenBinder(mainScreenModel));

    selectedAudioValueListener = (observable, oldVal,
        newVal) -> updateAudioProgress(mainScreenModel.getSelectedAudioValue().get());
    mainScreenModel.getSelectedAudioValue().addListener(selectedAudioValueListener);

    audio20LabelProperty = new NodePseudoClassProperty(progressLbl1);
    audio40LabelProperty = new NodePseudoClassProperty(progressLbl2);
    audio60LabelProperty = new NodePseudoClassProperty(progressLbl3);
    audio80LabelProperty = new NodePseudoClassProperty(progressLbl4);
    audio100LabelProperty = new NodePseudoClassProperty(progressLbl5);

    initializeProgresslabelMap();

    updateAudioProgress(mainScreenModel.getSelectedAudioValue().get());
  }

  private void initializeProgresslabelMap()
  {
    progressBarMap.put(DMIAudioModeEnum.AUDIO_20.getId(), audio20LabelProperty);
    progressBarMap.put(DMIAudioModeEnum.AUDIO_40.getId(), audio40LabelProperty);
    progressBarMap.put(DMIAudioModeEnum.AUDIO_60.getId(), audio60LabelProperty);
    progressBarMap.put(DMIAudioModeEnum.AUDIO_80.getId(), audio80LabelProperty);
    progressBarMap.put(DMIAudioModeEnum.AUDIO_100.getId(), audio100LabelProperty);
  }

  private void updateAudioProgress(int audioValue)
  {
    for (Map.Entry<Integer, NodePseudoClassProperty> entry : progressBarMap.entrySet())
    {
      Integer key = entry.getKey();
      progressBarMap.get(key).set(DMIConstants.PROGRESS_LABEL_NO_FILL_CSS); // $NON-NLS-1$
    }

    for (Map.Entry<Integer, NodePseudoClassProperty> entry : progressBarMap.entrySet())
    {
      Integer key = entry.getKey();
      if (key <= audioValue)
      {
        progressBarMap.get(key).set(DMIConstants.PROGRESS_LABEL_FILL_CSS); // $NON-NLS-1$
      }
    }
  }

  @Override
  public void detachListeners()
  {
    mainScreenModel.getSelectedAudioValue().removeListener(selectedAudioValueListener);
  }

  @FXML
  private void onCloseButtonAction(ActionEvent event)
  {
    DMIFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendButtonClickRequest(DMIInputs.AUDIO_CLOSE_REQUEST);
  }

  @FXML
  private void onMinusButtonAction(ActionEvent event)
  {
    if (mainScreenModel.getSelectedAudioValue().get() > DMIAudioModeEnum.AUDIO_20.getId())
    {
      DMIFactory.getServiceRequestHandler(scenarioCarIndex).sendRequest(DMIInputs.AUDIO_CHANGE_REQUEST,
          mainScreenModel.getSelectedAudioValue().get() - 1);
    }
  }

  @FXML
  private void onPlusButtonAction(ActionEvent event)
  {
    if (mainScreenModel.getSelectedAudioValue().get() < DMIAudioModeEnum.AUDIO_100.getId())
    {
      DMIFactory.getServiceRequestHandler(scenarioCarIndex).sendRequest(DMIInputs.AUDIO_CHANGE_REQUEST,
          mainScreenModel.getSelectedAudioValue().get() + 1);
    }
  }
}

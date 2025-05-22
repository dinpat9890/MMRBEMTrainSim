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
import com.sydac.mmrbem.dmi.common.state.DMIBrightnessModeEnum;
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
 * Controller for Brightness Panel fxml
 * 
 * @author ext-vp
 */
public class DMIBrightnessPanelController extends AbstractDMIController
{

  @FXML
  private Button closeBtn;

  @FXML
  private Button autoBtn;

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

  private ChangeListener<Number> selectedBrightnessValueListener;

  private NodePseudoClassProperty brightness20LabelProperty;

  private NodePseudoClassProperty brightness40LabelProperty;

  private NodePseudoClassProperty brightness60LabelProperty;

  private NodePseudoClassProperty brightness80LabelProperty;

  private NodePseudoClassProperty brightness100LabelProperty;

  private MainScreenModel mainScreenModel;

  private Map<Integer, NodePseudoClassProperty> progressBarMap = new HashMap<>();

  @Override
  public void initializeImpl()
  {

    mainScreenModel = new MainScreenModel(scenarioCarIndex);
    dmiScreenBinders.add(new MainScreenBinder(mainScreenModel));

    selectedBrightnessValueListener = (observable, oldVal,
        newVal) -> updateBrightness(mainScreenModel.getSelectedBrightnessValue().get());
    mainScreenModel.getSelectedBrightnessValue().addListener(selectedBrightnessValueListener);

    brightness20LabelProperty = new NodePseudoClassProperty(progressLbl1);
    brightness40LabelProperty = new NodePseudoClassProperty(progressLbl2);
    brightness60LabelProperty = new NodePseudoClassProperty(progressLbl3);
    brightness80LabelProperty = new NodePseudoClassProperty(progressLbl4);
    brightness100LabelProperty = new NodePseudoClassProperty(progressLbl5);

    initializeProgresslabelMap();
    updateBrightness(mainScreenModel.getSelectedBrightnessValue().get());
  }

  private void initializeProgresslabelMap()
  {
    progressBarMap.put(DMIBrightnessModeEnum.BRIGHTNESS_20.getId(), brightness20LabelProperty);
    progressBarMap.put(DMIBrightnessModeEnum.BRIGHTNESS_40.getId(), brightness40LabelProperty);
    progressBarMap.put(DMIBrightnessModeEnum.BRIGHTNESS_60.getId(), brightness60LabelProperty);
    progressBarMap.put(DMIBrightnessModeEnum.BRIGHTNESS_80.getId(), brightness80LabelProperty);
    progressBarMap.put(DMIBrightnessModeEnum.BRIGHTNESS_100.getId(), brightness100LabelProperty);
  }

  private void updateBrightness(int brightnessValue)
  {
    // Un-select all button first
    for (Map.Entry<Integer, NodePseudoClassProperty> entry : progressBarMap.entrySet())
    {
      Integer key = entry.getKey();
      progressBarMap.get(key).set(DMIConstants.PROGRESS_LABEL_NO_FILL_CSS); // $NON-NLS-1$
    }

    // Apply selected pseudo class to select button
    for (Map.Entry<Integer, NodePseudoClassProperty> entry : progressBarMap.entrySet())
    {
      Integer key = entry.getKey();
      if (key <= brightnessValue)
      {
        progressBarMap.get(key).set(DMIConstants.PROGRESS_LABEL_FILL_CSS); // $NON-NLS-1$
      }
    }
  }

  @Override
  public void detachListeners()
  {
    mainScreenModel.getSelectedBrightnessValue().removeListener(selectedBrightnessValueListener);
  }

  @FXML
  private void onAutoButtonAction(ActionEvent event)
  {
    DMIFactory.getServiceRequestHandler(scenarioCarIndex).sendRequest(DMIInputs.BRIGHTNESS_CHANGE_REQUEST,
        DMIBrightnessModeEnum.BRIGHTNESS_AUTO.getId());
  }

  @FXML
  private void onCloseButtonAction(ActionEvent event)
  {
    DMIFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendButtonClickRequest(DMIInputs.BRIGHTNESS_CLOSE_REQUEST);
  }

  @FXML
  private void onMinusButtonAction(ActionEvent event)
  {
    if (mainScreenModel.getSelectedBrightnessValue().get() == DMIBrightnessModeEnum.BRIGHTNESS_AUTO.getId())
    {
      DMIFactory.getServiceRequestHandler(scenarioCarIndex).sendRequest(DMIInputs.BRIGHTNESS_CHANGE_REQUEST,
          DMIBrightnessModeEnum.BRIGHTNESS_100.getId() - 1);
    }
    else if (mainScreenModel.getSelectedBrightnessValue().get() > DMIBrightnessModeEnum.BRIGHTNESS_20.getId())
    {
      DMIFactory.getServiceRequestHandler(scenarioCarIndex).sendRequest(DMIInputs.BRIGHTNESS_CHANGE_REQUEST,
          mainScreenModel.getSelectedBrightnessValue().get() - 1);
    }
  }

  @FXML
  private void onPlusButtonAction(ActionEvent event)
  {
    if (mainScreenModel.getSelectedBrightnessValue().get() < DMIBrightnessModeEnum.BRIGHTNESS_100.getId())
    {
      DMIFactory.getServiceRequestHandler(scenarioCarIndex).sendRequest(DMIInputs.BRIGHTNESS_CHANGE_REQUEST,
          mainScreenModel.getSelectedBrightnessValue().get() + 1);
    }
  }
}

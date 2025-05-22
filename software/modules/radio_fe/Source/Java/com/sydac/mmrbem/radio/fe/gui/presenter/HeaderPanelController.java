/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.radio.fe.gui.presenter;

import com.sydac.mmrbem.cabscreens.fe.common.NodePseudoClassProperty;
import com.sydac.mmrbem.radio.common.state.RadioSignalState;
import com.sydac.mmrbem.radio.fe.gui.AbstractRadioController;
import com.sydac.mmrbem.radio.fe.gui.binder.HeaderPanelBinder;
import com.sydac.mmrbem.radio.fe.gui.model.DayDateTimeModel;
import com.sydac.mmrbem.radio.fe.gui.model.HeaderPanelModel;

import javafx.beans.value.ChangeListener;
import javafx.fxml.FXML;
import javafx.scene.control.Label;

/**
 * Provides common infrastructure like grid pane containers and labels for Radio
 * Header Panel
 * 
 * @author ext-tambet
 */
public class HeaderPanelController extends AbstractRadioController
{

  @FXML
  private Label lineNameLbl;

  @FXML
  private Label msgCountLbl;

  @FXML
  private Label radioSignal1Lbl;

  @FXML
  private Label radioSignal2Lbl;

  @FXML
  private Label radioSignal3Lbl;

  @FXML
  private Label timeLbl;

  private HeaderPanelModel headerPanelModel;

  private final DayDateTimeModel dayDateTimeModel = new DayDateTimeModel();

  private ChangeListener<String> timeListener;

  private ChangeListener<String> lineNameListener;

  private ChangeListener<Number> messageCountListener;

  private ChangeListener<Number> radioSignalListener;

  private NodePseudoClassProperty radioSignal1LabelProperty;

  private NodePseudoClassProperty radioSignal2LabelProperty;

  private NodePseudoClassProperty radioSignal3LabelProperty;

  @Override
  public void detachListeners()
  {
    dayDateTimeModel.getTime().removeListener(timeListener);
    headerPanelModel.getLineName().removeListener(lineNameListener);
    headerPanelModel.getMessageCount().removeListener(messageCountListener);
    headerPanelModel.getRadioSignal().removeListener(radioSignalListener);
  }

  @Override
  public void initializeImpl()
  {

    headerPanelModel = new HeaderPanelModel(scenarioCarIndex);
    radioScreenBinders.add(new HeaderPanelBinder(headerPanelModel));

    radioSignal1LabelProperty = new NodePseudoClassProperty(radioSignal1Lbl);
    radioSignal2LabelProperty = new NodePseudoClassProperty(radioSignal2Lbl);
    radioSignal3LabelProperty = new NodePseudoClassProperty(radioSignal3Lbl);

    timeListener = (observable, oldVal, newVal) -> updateTime(newVal);
    dayDateTimeModel.getTime().addListener(timeListener);

    lineNameListener = (observable, oldVal, newVal) -> updateLineName(newVal);
    headerPanelModel.getLineName().addListener(lineNameListener);

    messageCountListener = (observable, oldVal, newVal) -> updateMessageCount(newVal.intValue());
    headerPanelModel.getMessageCount().addListener(messageCountListener);

    radioSignalListener = (observable, oldVal, newVal) -> updateRadioSignalState(newVal.intValue());
    headerPanelModel.getRadioSignal().addListener(radioSignalListener);

    updateTime(dayDateTimeModel.getTime().get());
    updateLineName(headerPanelModel.getLineName().get());
    updateMessageCount(headerPanelModel.getMessageCount().get());
    updateRadioSignalState(headerPanelModel.getRadioSignal().intValue());

  }

  private void updateRadioSignalState(int radioSignal)
  {
    String radioSignalCss = RadioSignalState.valueOf(radioSignal).getRadioSignalCss();
    radioSignal1LabelProperty.set(radioSignalCss);
    radioSignal2LabelProperty.set(radioSignalCss);
    radioSignal3LabelProperty.set(radioSignalCss);
  }

  private void updateMessageCount(Integer messageCount)
  {
    msgCountLbl.setText(String.valueOf(messageCount));
  }

  private void updateLineName(String lineName)
  {
    lineNameLbl.setText(lineName);
  }

  private void updateTime(String newVal)
  {
    timeLbl.setText(newVal);
  }

}

/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/

/**
 * @author ext-tambet
 **/
package com.sydac.mmrbem.radio.fe.gui.presenter;

import com.sydac.mmrbem.cabscreens.fe.common.NodePseudoClassProperty;
import com.sydac.mmrbem.radio.common.state.CabSignalState;
import com.sydac.mmrbem.radio.fe.gui.AbstractRadioController;
import com.sydac.mmrbem.radio.fe.gui.binder.CabSignalPanelBinder;
import com.sydac.mmrbem.radio.fe.gui.model.CabSignalPanelModel;

import javafx.beans.value.ChangeListener;
import javafx.fxml.FXML;
import javafx.scene.control.Label;

public class CabSignalPanelController extends AbstractRadioController
{

  @FXML
  private Label cabAImageLbl;

  @FXML
  private Label cabBImageLbl;

  @FXML
  private Label occPaImageLbl;

  @FXML
  private Label papisAImageLbl;

  @FXML
  private Label papisBImageLbl;

  @FXML
  private Label remoteImageLbl;

  @FXML
  private Label tcmsAimageLbl;

  @FXML
  private Label tcmsBImageLbl;

  @FXML
  private Label trAImageLbl;

  @FXML
  private Label trBImageLbl;

  @FXML
  private Label triuAImageLbl;

  @FXML
  private Label triuBImageLbl;

  private CabSignalPanelModel cabSignalPanelModel;

  private ChangeListener<Number> cabAImageLblListener;

  private ChangeListener<Number> cabBimageLblListener;

  private ChangeListener<Number> occpAImageLblListener;

  private ChangeListener<Number> papisAImageLblListener;

  private ChangeListener<Number> papisBImageLblListener;

  private ChangeListener<Number> remoteImageLblListener;

  private ChangeListener<Number> tcmsAimageLblListener;

  private ChangeListener<Number> tcmsBImageLblListener;

  private ChangeListener<Number> trAImageLblListener;

  private ChangeListener<Number> trBImageLblListener;

  private ChangeListener<Number> triuAImageLblListener;

  private ChangeListener<Number> triuBImageLblListener;

  private ChangeListener<Number> radioSignalListener;

  private NodePseudoClassProperty triuALabelProperty;

  private NodePseudoClassProperty cabALabelProperty;

  private NodePseudoClassProperty cabBLabelProperty;

  private NodePseudoClassProperty triuBLabelProperty;

  private NodePseudoClassProperty papisALabelproperty;

  private NodePseudoClassProperty trALabelProperty;

  private NodePseudoClassProperty papisBLabelProperty;

  private NodePseudoClassProperty trBLabelProperty;

  private NodePseudoClassProperty tcmsALabelProperty;

  private NodePseudoClassProperty occpaLabelProperty;

  private NodePseudoClassProperty tcmsBLabelProperty;

  private NodePseudoClassProperty remoteLabelProperty;

  @Override
  public void detachListeners()
  {
    cabSignalPanelModel.getTriuAStatus().removeListener(triuAImageLblListener);
    cabSignalPanelModel.getCabAStatus().removeListener(cabAImageLblListener);
    cabSignalPanelModel.getCabBStatus().removeListener(cabBimageLblListener);
    cabSignalPanelModel.getOccPaStatus().removeListener(occpAImageLblListener);
    cabSignalPanelModel.getPaPisAStatus().removeListener(papisAImageLblListener);
    cabSignalPanelModel.getPaPisBStatus().removeListener(papisBImageLblListener);
    cabSignalPanelModel.getRemoteStatus().removeListener(remoteImageLblListener);
    cabSignalPanelModel.getTcmsAStatus().removeListener(tcmsAimageLblListener);
    cabSignalPanelModel.getTcmsBStatus().removeListener(tcmsBImageLblListener);
    cabSignalPanelModel.getTriuAStatus().removeListener(triuAImageLblListener);
    cabSignalPanelModel.getTriuBStatus().removeListener(triuBImageLblListener);
    cabSignalPanelModel.getTrBStatus().removeListener(trBImageLblListener);
    cabSignalPanelModel.getTrAStatus().removeListener(trAImageLblListener);
    cabSignalPanelModel.getRadioSignal().removeListener(radioSignalListener);
  }

  @Override
  public void initializeImpl()
  {
    cabSignalPanelModel = new CabSignalPanelModel(scenarioCarIndex);
    radioScreenBinders.add(new CabSignalPanelBinder(cabSignalPanelModel));

    triuALabelProperty = new NodePseudoClassProperty(triuAImageLbl);
    cabALabelProperty = new NodePseudoClassProperty(cabAImageLbl);
    cabBLabelProperty = new NodePseudoClassProperty(cabBImageLbl);
    triuBLabelProperty = new NodePseudoClassProperty(triuBImageLbl);
    papisALabelproperty = new NodePseudoClassProperty(papisAImageLbl);
    trALabelProperty = new NodePseudoClassProperty(trAImageLbl);
    papisBLabelProperty = new NodePseudoClassProperty(papisBImageLbl);
    trBLabelProperty = new NodePseudoClassProperty(trBImageLbl);
    tcmsALabelProperty = new NodePseudoClassProperty(tcmsAimageLbl);
    occpaLabelProperty = new NodePseudoClassProperty(occPaImageLbl);
    tcmsBLabelProperty = new NodePseudoClassProperty(tcmsBImageLbl);
    remoteLabelProperty = new NodePseudoClassProperty(remoteImageLbl);

    triuAImageLblListener = (observable, oldVal, newVal) -> updateCabSignalStatus(newVal.intValue(),triuALabelProperty);
    cabSignalPanelModel.getTriuAStatus().addListener(triuAImageLblListener);

    cabAImageLblListener = (observable, oldVal, newVal) -> updateCabSignalStatus(newVal.intValue(),cabALabelProperty);
    cabSignalPanelModel.getCabAStatus().addListener(cabAImageLblListener);

    cabBimageLblListener = (observable, oldVal, newVal) -> updateCabSignalStatus(newVal.intValue(),cabBLabelProperty);
    cabSignalPanelModel.getCabBStatus().addListener(cabBimageLblListener);

    occpAImageLblListener = (observable, oldVal, newVal) -> updateCabSignalStatus(newVal.intValue(),occpaLabelProperty);
    cabSignalPanelModel.getOccPaStatus().addListener(occpAImageLblListener);

    papisAImageLblListener = (observable, oldVal, newVal) -> updateCabSignalStatus(newVal.intValue(),papisALabelproperty);
    cabSignalPanelModel.getPaPisAStatus().addListener(papisAImageLblListener);

    papisBImageLblListener = (observable, oldVal, newVal) -> updateCabSignalStatus(newVal.intValue(),papisBLabelProperty);
    cabSignalPanelModel.getPaPisBStatus().addListener(papisBImageLblListener);

    remoteImageLblListener = (observable, oldVal, newVal) -> updateCabSignalStatus(newVal.intValue(),remoteLabelProperty);
    cabSignalPanelModel.getRemoteStatus().addListener(remoteImageLblListener);

    tcmsAimageLblListener = (observable, oldVal, newVal) -> updateCabSignalStatus(newVal.intValue(),tcmsALabelProperty);
    cabSignalPanelModel.getTcmsAStatus().addListener(tcmsAimageLblListener);

    tcmsBImageLblListener = (observable, oldVal, newVal) -> updateCabSignalStatus(newVal.intValue(),tcmsBLabelProperty);
    cabSignalPanelModel.getTcmsBStatus().addListener(tcmsBImageLblListener);

    triuBImageLblListener = (observable, oldVal, newVal) -> updateCabSignalStatus(newVal.intValue(),triuBLabelProperty);
    cabSignalPanelModel.getTriuBStatus().addListener(triuBImageLblListener);

    trAImageLblListener = (observable, oldVal, newVal) -> updateCabSignalStatus(newVal.intValue(),trALabelProperty);
    cabSignalPanelModel.getTrAStatus().addListener(trAImageLblListener);

    trBImageLblListener = (observable, oldVal, newVal) -> updateCabSignalStatus(newVal.intValue(),trBLabelProperty);
    cabSignalPanelModel.getTrBStatus().addListener(trBImageLblListener);

    updateCabSignalStatus(cabSignalPanelModel.getTriuAStatus().get(), triuALabelProperty);
    updateCabSignalStatus(cabSignalPanelModel.getCabAStatus().get(),cabALabelProperty);
    updateCabSignalStatus(cabSignalPanelModel.getOccPaStatus().get(),occpaLabelProperty);
    updateCabSignalStatus(cabSignalPanelModel.getPaPisAStatus().get(),papisALabelproperty);
    updateCabSignalStatus(cabSignalPanelModel.getPaPisBStatus().get(),papisBLabelProperty);
    updateCabSignalStatus(cabSignalPanelModel.getRemoteStatus().get(),remoteLabelProperty);
    updateCabSignalStatus(cabSignalPanelModel.getTcmsAStatus().get(),tcmsALabelProperty);
    updateCabSignalStatus(cabSignalPanelModel.getTcmsBStatus().get(),tcmsBLabelProperty);
    updateCabSignalStatus(cabSignalPanelModel.getTriuBStatus().get(),triuBLabelProperty);
    updateCabSignalStatus(cabSignalPanelModel.getTrAStatus().get(),trALabelProperty);
    updateCabSignalStatus(cabSignalPanelModel.getTrBStatus().get(),trBLabelProperty);
    updateCabSignalStatus(cabSignalPanelModel.getCabBStatus().get(),cabBLabelProperty);

  }

  private void updateCabSignalStatus(Integer status, NodePseudoClassProperty property)
  {
    property.set(CabSignalState.valueOf(status).getCabSignalCss());
  }



}

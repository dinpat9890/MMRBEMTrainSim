/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.psd.fe.gui.presenter;

import com.sydac.mmrbem.cabscreens.fe.base.CommsNumber;
import com.sydac.mmrbem.cabscreens.fe.common.NodePseudoClassProperty;
import com.sydac.mmrbem.psd.common.data.ApplicationConstants;
import com.sydac.mmrbem.psd.fe.base.PSDFactory;
import com.sydac.mmrbem.psd.fe.gui.AbstractPSDController;
import com.sydac.mmrbem.psd.fe.gui.binder.PsdPanelBinder;
import com.sydac.mmrbem.psd.fe.gui.model.PsdPanelModel;
import com.sydac.project.runtimedata.ProjectObjectConstants.PSDInputs;

import javafx.beans.value.ChangeListener;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.layout.GridPane;

/**
 * Common controller for components of line 7 and line 2.
 * 
 * @author ext-jadhalp
 *
 */
public class PsdScreenController extends AbstractPSDController
{

  @FXML
  private Label pseEnableLbl;

  @FXML
  private Label allDoorCLLbl;

  @FXML
  private Label interlockOverrideLbl;

  @FXML
  private Label fullyOpenLbl;

  private NodePseudoClassProperty pseEnableLblProperty;

  private NodePseudoClassProperty allDoorCLLblProperty;

  private NodePseudoClassProperty overrideLblProperty;

  private NodePseudoClassProperty pgFullyLblProperty;

  private NodePseudoClassProperty pgOpenButtonProperty;

  private NodePseudoClassProperty pgCloseButtonProperty;

  private NodePseudoClassProperty pseEnableButtonProperty;

  private NodePseudoClassProperty interlockOverrideButtonProperty;

  private NodePseudoClassProperty lampTestButtonProperty;

  @FXML
  @CommsNumber(PSDInputs.PG_OPEN_BUTTON)
  private Button pgOpenButton;

  @FXML
  @CommsNumber(PSDInputs.PG_CLOSE_BUTTON)
  private Button pgCloseButton;

  @FXML
  @CommsNumber(PSDInputs.PSE_ENABLE_BUTTON)
  private Button pseEnableButton;

  @FXML
  @CommsNumber(PSDInputs.INTERLOCK_OVERRIDE_BUTTON)
  private Button interlockOverrideButton;

  @FXML
  @CommsNumber(PSDInputs.LAMP_TEST_BUTTON)
  private Button lampTestButton;

  public PsdPanelModel psdPanelModel;
  
  @FXML
  private GridPane doorGrid;

  private ChangeListener<Boolean> pseEnableListener;

  private ChangeListener<Number> interLockListener;

  private ChangeListener<Number> lampListener;

  private boolean isPseEnable;

  private ChangeListener<Number> doorValueListener;

  @Override
  public void detachListeners()
  {
    psdPanelModel.isPseEnable().removeListener(pseEnableListener);
    psdPanelModel.getInterlockOverrideStatus().removeListener(interLockListener);
    psdPanelModel.getLampStatus().removeListener(lampListener);

    psdPanelModel.getDoorStatus().removeListener(doorValueListener);
  }

  @Override
  public void initializeImpl()
  {
    psdPanelModel = new PsdPanelModel(scenarioCarIndex);
    psdScreenBinders.add(new PsdPanelBinder(psdPanelModel));

    pgOpenButtonProperty = new NodePseudoClassProperty(pgOpenButton);
    pseEnableButtonProperty = new NodePseudoClassProperty(pseEnableButton);
    pgCloseButtonProperty = new NodePseudoClassProperty(pgCloseButton);

    interlockOverrideButtonProperty = new NodePseudoClassProperty(interlockOverrideButton);
    lampTestButtonProperty = new NodePseudoClassProperty(lampTestButton);

    allDoorCLLblProperty = new NodePseudoClassProperty(allDoorCLLbl);

    pseEnableLblProperty = new NodePseudoClassProperty(pseEnableLbl);

    pgFullyLblProperty = new NodePseudoClassProperty(fullyOpenLbl);
    overrideLblProperty = new NodePseudoClassProperty(interlockOverrideLbl);

    pseEnableListener = (obs, oldval, newVal) -> {
      updatePseStatus(psdPanelModel.isPseEnable().getValue());
      if (isPseEnable)
      {
        updateAllLampStatus(psdPanelModel.getLampStatus().getValue());
      }
      else
      {
        updateAllLampStatus(0);
      }
    };
    psdPanelModel.isPseEnable().addListener(pseEnableListener);

    doorValueListener = (obs, oldval, newVal) -> {

      updateDoorStatusStatus();
    };
    psdPanelModel.getDoorStatus().addListener(doorValueListener);

    interLockListener = (obs, oldval, newVal) -> {
      updateInterlockStatus(psdPanelModel.getInterlockOverrideStatus().getValue());
    };
    psdPanelModel.getInterlockOverrideStatus().addListener(interLockListener);

    lampListener = (obs, oldval, newVal) -> {
      updateAllLampStatus(psdPanelModel.getLampStatus().getValue());
    };
    psdPanelModel.getLampStatus().addListener(lampListener);

    updatePseStatus(psdPanelModel.isPseEnable().getValue());
    updateInterlockStatus(psdPanelModel.getInterlockOverrideStatus().getValue());
    updateAllLampStatus(psdPanelModel.getLampStatus().getValue());
    updateDoorStatusStatus();

  }

  /**
   * update the door status.
   */
  private void updateDoorStatusStatus()
  {
    if (psdPanelModel.getDoorStatus().getValue() == ApplicationConstants.PSD_OPENING)
    {
    //  doorGrid.setVisible(true);
    }
    else if (psdPanelModel.getDoorStatus().getValue() == ApplicationConstants.PSD_OPENED)
    {
      doorGrid.setVisible(true);
      pgFullyLblProperty.set(ApplicationConstants.LIT_PSEUDO_CLASS);
      allDoorCLLblProperty.set(ApplicationConstants.UNLIT_PSEUDO_CLASS);
    }
    else if (psdPanelModel.getDoorStatus().getValue() == ApplicationConstants.PSD_CLOSING)
    {
     //doorGrid.setVisible(true);
    }
    else if (psdPanelModel.getDoorStatus().getValue() == ApplicationConstants.PSD_CLOSED)
    {
      doorGrid.setVisible(false);
      allDoorCLLblProperty.set(ApplicationConstants.LIT_PSEUDO_CLASS);
      pgFullyLblProperty.set(ApplicationConstants.UNLIT_PSEUDO_CLASS);
    }
    else
    {
      doorGrid.setVisible(false);
    }
  }

  /**
   * Update all the indicator status.
   * 
   * @param value
   */
  private void updateAllLampStatus(Integer value)
  {

    lampTestButtonProperty.set(value == 1 ? ApplicationConstants.SELECTED_PSEUDO_CLASS
        : ApplicationConstants.UNSELECTED_PSEUDO_CLASS);

    allDoorCLLblProperty
        .set(value == 1 ? ApplicationConstants.LIT_PSEUDO_CLASS : ApplicationConstants.UNLIT_PSEUDO_CLASS);

    overrideLblProperty
        .set(value == 1 ? ApplicationConstants.LIT_PSEUDO_CLASS : ApplicationConstants.UNLIT_PSEUDO_CLASS);

    pgFullyLblProperty
        .set(value == 1 ? ApplicationConstants.LIT_PSEUDO_CLASS : ApplicationConstants.UNLIT_PSEUDO_CLASS);

    if(value==0)
    {
    updateDoorStatusStatus();
    }
  }

  private void updateInterlockStatus(Integer value)
  {
    overrideLblProperty
        .set(value == 1 ? ApplicationConstants.LIT_PSEUDO_CLASS : ApplicationConstants.UNLIT_PSEUDO_CLASS);
  }

  private void updatePseStatus(boolean pseEnable)
  {
    isPseEnable = pseEnable;

    pseEnableButtonProperty.set(pseEnable ? ApplicationConstants.SELECTED_PSEUDO_CLASS
        : ApplicationConstants.UNSELECTED_PSEUDO_CLASS);
    pseEnableLblProperty
        .set(pseEnable ? ApplicationConstants.LIT_PSEUDO_CLASS : ApplicationConstants.UNLIT_PSEUDO_CLASS);
    if (!pseEnable)
    {
      PSDFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendRequest(PSDInputs.PSE_ENABLE_BUTTON_PRESS_REQUEST, 0);
    }

  }

  @FXML
  void onPgOpenButtonAction(ActionEvent event)
  {
    if (isPseEnable)
    {
      PSDFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendButtonClickRequest(PSDInputs.PG_OPEN_BUTTON_PRESS_REQUEST);// (PSDInputs.PG_OPEN_BUTTON_PRESS_REQUEST,
                                                                          // 1);
    }
  }

  @FXML
  void onPgCloseButtonAction(ActionEvent event)
  {
    if (isPseEnable)
    {
      PSDFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendButtonClickRequest(PSDInputs.PG_CLOSE_BUTTON_PRESS_REQUEST);
    }
  }

  @FXML
  void onPseEnableButtonAction(ActionEvent event)
  {
    if (isPseEnable)
    {
      PSDFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendRequest(PSDInputs.PSE_ENABLE_BUTTON_PRESS_REQUEST, 0);
    }
    else
    {
      PSDFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendRequest(PSDInputs.PSE_ENABLE_BUTTON_PRESS_REQUEST, 1);
    }

  }

  @FXML
  void onInterlockButtonAction(ActionEvent event)
  {
    if (isPseEnable)
    {
      PSDFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendButtonClickRequest(PSDInputs.INTERLOCK_OVERRIDE_BUTTON_PRESS_REQUEST);
      
    }
  }

  @FXML
  void onLampTestButtonAction(ActionEvent event)
  {
    if (isPseEnable)
    {
      if (psdPanelModel.getLampStatus().getValue() == 1)
      {
        PSDFactory.getServiceRequestHandler(scenarioCarIndex)
            .sendRequest(PSDInputs.LAMP_TEST_BUTTON_PRESS_REQUEST, 0);
      }
      else
      {
        PSDFactory.getServiceRequestHandler(scenarioCarIndex)
            .sendRequest(PSDInputs.LAMP_TEST_BUTTON_PRESS_REQUEST, 1);
      }
    }
  }
}

/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.psd.fe.gui.presenter;

import com.sydac.mmrbem.cabscreens.fe.common.NodePseudoClassProperty;
import com.sydac.mmrbem.psd.common.data.ApplicationConstants;

import javafx.beans.value.ChangeListener;
import javafx.fxml.FXML;
import javafx.scene.control.Label;

/**
 *  This controller will take care of Line 2 specific components.
 * @author ext-jadhalp
 *
 */
public class PsdScreenLine2Controller extends PsdScreenController
{

  @FXML
  private Label pgOpeningLbl;

  @FXML
  private Label pgClosingLbl;

  @FXML
  private Label pgFaultLbl;

  private NodePseudoClassProperty pgFaultLblProperty;

  private NodePseudoClassProperty pgClosingLblProperty;

  private NodePseudoClassProperty pgOpeningLblProperty;

  private ChangeListener<Number> lampListener;

  private ChangeListener<Number> doorValueListener;

  @Override
  public void detachListeners()
  {

    psdPanelModel.getLampStatus().removeListener(lampListener);

    psdPanelModel.getDoorStatus().removeListener(doorValueListener);
  }

  @Override
  public void initializeImpl()
  {
    super.initializeImpl();

    pgFaultLblProperty = new NodePseudoClassProperty(pgFaultLbl);
    pgClosingLblProperty = new NodePseudoClassProperty(pgClosingLbl);
    pgOpeningLblProperty = new NodePseudoClassProperty(pgOpeningLbl);

    lampListener = (obs, oldval, newVal) -> {
      updateLine2LampStatus(psdPanelModel.getLampStatus().getValue());
    };
    psdPanelModel.getLampStatus().addListener(lampListener);

    doorValueListener = (obs, oldval, newVal) -> {

      updateLin2DoorStatus();
    };
    psdPanelModel.getDoorStatus().addListener(doorValueListener);

    updateLine2LampStatus(psdPanelModel.getLampStatus().getValue());
    updateLin2DoorStatus();
  }

  private void updateLin2DoorStatus()
  {

    if (psdPanelModel.getDoorStatus().getValue() == ApplicationConstants.PSD_CLOSING)
    {
      pgClosingLblProperty.set(ApplicationConstants.LIT_PSEUDO_CLASS);
      pgOpeningLblProperty.set(ApplicationConstants.UNLIT_PSEUDO_CLASS);
      pgFaultLblProperty.set(ApplicationConstants.UNLIT_PSEUDO_CLASS);

    }
    else if (psdPanelModel.getDoorStatus().getValue() == ApplicationConstants.PSD_OPENING)
    {
      pgOpeningLblProperty.set(ApplicationConstants.LIT_PSEUDO_CLASS);
      pgClosingLblProperty.set(ApplicationConstants.UNLIT_PSEUDO_CLASS);
      pgFaultLblProperty.set(ApplicationConstants.UNLIT_PSEUDO_CLASS);

    }
    else if (psdPanelModel.getDoorStatus().getValue() == ApplicationConstants.PSD_FAULT)
    {
      pgFaultLblProperty.set(ApplicationConstants.LIT_PSEUDO_CLASS);

    }else
    {
      pgClosingLblProperty.set(ApplicationConstants.UNLIT_PSEUDO_CLASS);
      pgOpeningLblProperty.set(ApplicationConstants.UNLIT_PSEUDO_CLASS);
      pgFaultLblProperty.set(ApplicationConstants.UNLIT_PSEUDO_CLASS);
    }

  }

  private void updateLine2LampStatus(Integer value)
  {

    pgClosingLblProperty
        .set(value == 1 ? ApplicationConstants.LIT_PSEUDO_CLASS : ApplicationConstants.UNLIT_PSEUDO_CLASS);

    pgOpeningLblProperty
        .set(value == 1 ? ApplicationConstants.LIT_PSEUDO_CLASS : ApplicationConstants.UNLIT_PSEUDO_CLASS);

    pgFaultLblProperty
        .set(value == 1 ? ApplicationConstants.LIT_PSEUDO_CLASS : ApplicationConstants.UNLIT_PSEUDO_CLASS);

   
  }

}

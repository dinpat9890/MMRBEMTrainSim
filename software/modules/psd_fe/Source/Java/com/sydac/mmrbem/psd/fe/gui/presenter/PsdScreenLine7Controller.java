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
 *  This controller will take care of Line 7 specific components.
 * @author ext-jadhalp
 *
 */
public class PsdScreenLine7Controller extends PsdScreenController
{

  @FXML
  private Label interlockLbl;
  
  @FXML
  private Label espEnableLbl;

  private NodePseudoClassProperty interlockLblProperty;
  
  private NodePseudoClassProperty espEnableLblProperty;

  private ChangeListener<Number> interLockListener;

  private ChangeListener<Number> lampListener;

  @Override
  public void detachListeners()
  {
    psdPanelModel.getLampStatus().removeListener(lampListener);
    psdPanelModel.getInterlockOverrideStatus().removeListener(interLockListener);

  }

  @Override
  public void initializeImpl()
  {
    super.initializeImpl();
    interlockLblProperty = new NodePseudoClassProperty(interlockLbl);
    
    espEnableLblProperty = new NodePseudoClassProperty(espEnableLbl);


    interLockListener = (obs, oldval, newVal) -> {
      updateInterlockLin7Status(psdPanelModel.getInterlockOverrideStatus().getValue());
    };
   // psdPanelModel.getInterlockOverrideStatus().addListener(interLockListener);

   // updateInterlockLin7Status(psdPanelModel.getInterlockOverrideStatus().getValue());

    lampListener = (obs, oldval, newVal) -> {
      updateLine7LampStatus(psdPanelModel.getLampStatus().getValue());
    };
    psdPanelModel.getLampStatus().addListener(lampListener);

  }

  private void updateLine7LampStatus(Integer value)
  {

    interlockLblProperty
        .set(value == 1 ? ApplicationConstants.LIT_PSEUDO_CLASS : ApplicationConstants.UNLIT_PSEUDO_CLASS);
    espEnableLblProperty
    .set(value == 1 ? ApplicationConstants.LIT_PSEUDO_CLASS : ApplicationConstants.UNLIT_PSEUDO_CLASS);

  }

  private void updateInterlockLin7Status(Integer value)
  {
    interlockLblProperty
        .set(value == 1 ? ApplicationConstants.LIT_PSEUDO_CLASS : ApplicationConstants.UNLIT_PSEUDO_CLASS); // $NON-NLS-1$

  }

}

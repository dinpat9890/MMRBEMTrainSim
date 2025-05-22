/*
 * ==================================================================
 *
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *
 * ==================================================================
 */
package com.sydac.mmrbem.tcms.fe.gui.presenter;

import com.sydac.mmrbem.tcms.fe.base.TCMSFactory;
import com.sydac.mmrbem.tcms.fe.gui.AbstractTCMSController;
import com.sydac.mmrbem.tcms.fe.gui.binder.CCTVFooterPanelBinder;
import com.sydac.mmrbem.tcms.fe.gui.model.CCTVFooterPanelModel;
import com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs;

import javafx.beans.value.ChangeListener;
import javafx.fxml.FXML;
import javafx.scene.control.Label;
import javafx.scene.input.MouseEvent;
import javafx.scene.input.TouchEvent;

public class CCTVSettingsPanelController extends AbstractTCMSController
{

  @FXML
  private Label quitLbl;

  private CCTVFooterPanelModel cctvFooterPanelModel;

  private ChangeListener<Number> quitListener;

  @Override
  public void detachListeners()
  {

    cctvFooterPanelModel.getSettingQuitButtonState().removeListener(quitListener);
  }

  @Override
  public void initializeImpl()
  {
    cctvFooterPanelModel = new CCTVFooterPanelModel(scenarioCarIndex);
    tcmsScreenBinders.add(new CCTVFooterPanelBinder(cctvFooterPanelModel));
    
    quitListener = (observable, oldVal,
        newVal) -> updateQuitButtonState(newVal.intValue());
    cctvFooterPanelModel.getSettingQuitButtonState().addListener(quitListener);
    
  }

  private void updateQuitButtonState(int intValue)
  {
    if(intValue==1)
    {
    CCTVFooterPanelModel.setSettingsPopupActive(false);
    }
  }

  /**
   * @param event
   */
  @FXML
  private void onQuitMouseClicked(MouseEvent event)
  {
    if (CCTVFooterPanelModel.getSettingsPopupActive().get()
        && cctvFooterPanelModel.getCctvDisplayHangedFault().get() != 1)
    {
      CCTVFooterPanelModel.setSettingsPopupActive(false);

      TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendRequest(VDUInputs.CCTV_SETTING_QUIT_BUTTON_REQUEST,1);
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
      .sendRequest(VDUInputs.CCTV_SETTING_PANEL_REQUEST,0);
    }
  }

  /**
   * @param event
   */
  @FXML
  private void onQuitTouchPressed(TouchEvent event)
  {
    if (CCTVFooterPanelModel.getSettingsPopupActive().get()
        && cctvFooterPanelModel.getCctvDisplayHangedFault().get() != 1)
    {
      CCTVFooterPanelModel.setSettingsPopupActive(false);

      TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendRequest(VDUInputs.CCTV_SETTING_QUIT_BUTTON_REQUEST,1);
      
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
      .sendRequest(VDUInputs.CCTV_SETTING_PANEL_REQUEST,0);
    }
  }

}

/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.tcms.fe.gui.presenter;

import com.sydac.mmrbem.tcms.fe.common.TCMSUIConstants;
import com.sydac.mmrbem.tcms.fe.gui.AbstractTCMSController;
import com.sydac.mmrbem.tcms.fe.gui.binder.HybridModeScreenBinder;
import com.sydac.mmrbem.tcms.fe.gui.model.HybridModeScreenModel;

import javafx.beans.value.ChangeListener;
import javafx.fxml.FXML;
import javafx.scene.layout.GridPane;

public class CCTVHybridModeCommonController extends AbstractTCMSController
{

  @FXML
  private GridPane mainGrid;

  @FXML
  private GridPane leftSideGrid;

  @FXML
  private GridPane rightSideGrid;

  private ChangeListener<Number> hybridPanelSideListener;

  private HybridModeScreenModel hybridModeScreenModel;

  @Override
  public void detachListeners()
  {
    hybridModeScreenModel.getHybridPanelActiveSide().removeListener(hybridPanelSideListener);
  }

  @Override
  public void initializeImpl()
  {
    hybridModeScreenModel = new HybridModeScreenModel(scenarioCarIndex);
    tcmsScreenBinders.add(new HybridModeScreenBinder(hybridModeScreenModel));

    hybridPanelSideListener = (observable, oldVal,
        newVal) -> updatePanelActiveSide(hybridModeScreenModel.getHybridPanelActiveSide().get());
    hybridModeScreenModel.getHybridPanelActiveSide().addListener(hybridPanelSideListener);

    updatePanelActiveSide(hybridModeScreenModel.getHybridPanelActiveSide().get());
  }

  private void updatePanelActiveSide(int panelActiveVal)
  {
    leftSideGrid.setVisible(panelActiveVal == TCMSUIConstants.LEFT_PANEL_ACTIVE);
    rightSideGrid.setVisible(panelActiveVal == TCMSUIConstants.RIGHT_PANEL_ACTIVE);
    leftSideGrid.getStyleClass().clear();
    rightSideGrid.getStyleClass().clear();
    if (panelActiveVal == TCMSUIConstants.LEFT_PANEL_ACTIVE)
    {
      rightSideGrid.getStyleClass().add(TCMSUIConstants.HYBRID_GRID_TRANSPARANT_CSS);
      leftSideGrid.getStyleClass().add(TCMSUIConstants.HYBRID_GRID_DEFAULT_CSS);
    }
    else if (panelActiveVal == TCMSUIConstants.RIGHT_PANEL_ACTIVE)
    {
      rightSideGrid.getStyleClass().add(TCMSUIConstants.HYBRID_GRID_DEFAULT_CSS);
      leftSideGrid.getStyleClass().add(TCMSUIConstants.HYBRID_GRID_TRANSPARANT_CSS);
    }
    else
    {
      rightSideGrid.getStyleClass().add(TCMSUIConstants.HYBRID_GRID_TRANSPARANT_CSS);
      leftSideGrid.getStyleClass().add(TCMSUIConstants.HYBRID_GRID_TRANSPARANT_CSS);
    }
  }
}
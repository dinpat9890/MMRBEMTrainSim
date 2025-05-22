/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.tcms.fe.gui.presenter;

import java.util.HashMap;
import java.util.Map;

import com.sydac.mmrbem.tcms.common.data.SpeedLimitStatusDO;
import com.sydac.mmrbem.tcms.common.state.TCMSConstants;
import com.sydac.mmrbem.tcms.fe.gui.AbstractTCMSController;
import com.sydac.mmrbem.tcms.fe.gui.binder.SpeedLimitInterlockScreenBinder;
import com.sydac.mmrbem.tcms.fe.gui.model.SpeedLimitInterlockScreenModel;

import javafx.beans.value.ChangeListener;
import javafx.collections.ObservableList;
import javafx.fxml.FXML;
import javafx.scene.control.Label;

public class SpeedLimitInterlockScreenController extends AbstractTCMSController
{

  private static final int ACTIVE_STATE = 1;

  private static final String SPEED_LIMIT_NOT_ACTIVE_STATE = "speed-limit-screen-text"; //$NON-NLS-1$

  private static final String SPEED_LIMIT_ACTIVE_STATE = "speed-limit-screen-selected-state"; //$NON-NLS-1$

  private SpeedLimitInterlockScreenModel speedLimitInterlockScreenModel;

  @FXML
  private Label speedLimit0Lbl;

  @FXML
  private Label speedLimit1Lbl;

  @FXML
  private Label speedLimit2Lbl;

  @FXML
  private Label speedLimit3Lbl;

  @FXML
  private Label speedLimit4Lbl;

  @FXML
  private Label speedLimit5Lbl;

  @FXML
  private Label speedLimit6Lbl;

  @FXML
  private Label speedLimit7Lbl;

  @FXML
  private Label speedLimit8Lbl;

  @FXML
  private Label speedLimit9Lbl;

  @FXML
  private Label speedLimit10Lbl;

  @FXML
  private Label speedLimit11Lbl;

  @FXML
  private Label speedLimit12Lbl;

  @FXML
  private Label speedLimit13Lbl;

  private ChangeListener<? super ObservableList<SpeedLimitStatusDO>> speedLimitListener;

  private Map<Integer, Label> speedLimitLblMap = new HashMap<>();

  @Override
  public void detachListeners()
  {
    speedLimitInterlockScreenModel.getSpeedLimitDoList().removeListener(speedLimitListener);
  }

  @Override
  public void initializeImpl()
  {
    speedLimitInterlockScreenModel = new SpeedLimitInterlockScreenModel(scenarioCarIndex);
    tcmsScreenBinders.add(new SpeedLimitInterlockScreenBinder(speedLimitInterlockScreenModel));

    speedLimitLblMap.put(TCMSConstants.SPEED_LIMIT_MAP_ID_1, speedLimit0Lbl);
    speedLimitLblMap.put(TCMSConstants.SPEED_LIMIT_MAP_ID_2, speedLimit1Lbl);
    speedLimitLblMap.put(TCMSConstants.SPEED_LIMIT_MAP_ID_3, speedLimit2Lbl);
    speedLimitLblMap.put(TCMSConstants.SPEED_LIMIT_MAP_ID_4, speedLimit3Lbl);
    speedLimitLblMap.put(TCMSConstants.SPEED_LIMIT_MAP_ID_5, speedLimit4Lbl);
    speedLimitLblMap.put(TCMSConstants.SPEED_LIMIT_MAP_ID_6, speedLimit7Lbl);
    speedLimitLblMap.put(TCMSConstants.SPEED_LIMIT_MAP_ID_7, speedLimit8Lbl);
    speedLimitLblMap.put(TCMSConstants.SPEED_LIMIT_MAP_ID_8, speedLimit9Lbl);
    speedLimitLblMap.put(TCMSConstants.SPEED_LIMIT_MAP_ID_9, speedLimit10Lbl);
    speedLimitLblMap.put(TCMSConstants.SPEED_LIMIT_MAP_ID_10, speedLimit11Lbl);
    speedLimitLblMap.put(TCMSConstants.SPEED_LIMIT_MAP_ID_11, speedLimit12Lbl);
    speedLimitLblMap.put(TCMSConstants.SPEED_LIMIT_MAP_ID_12, speedLimit13Lbl);

    speedLimitListener = (observable, oldValue, newValue) -> updateSpeedLimitState();
    speedLimitInterlockScreenModel.getSpeedLimitDoList().addListener(speedLimitListener);

  }

  private void updateSpeedLimitState()
  {
    for (int optionsCounter = 0; optionsCounter < speedLimitInterlockScreenModel.getSpeedLimitDoList()
        .size(); optionsCounter++)
    {
      int state = speedLimitInterlockScreenModel.getSpeedLimitDoList().get(optionsCounter)
          .getSpeedLimitState();
      speedLimitLblMap.get(optionsCounter).getStyleClass().clear();

      if (state == ACTIVE_STATE)
      {
        int speedLimitId = speedLimitInterlockScreenModel.getSpeedLimitDoList().get(optionsCounter)
            .getSpeedLimitId();
        speedLimitLblMap.get(speedLimitId).getStyleClass().add(SPEED_LIMIT_ACTIVE_STATE);
      }
      else
      {
        speedLimitLblMap.get(optionsCounter).getStyleClass().add(SPEED_LIMIT_NOT_ACTIVE_STATE);
      }
    }
  }

}

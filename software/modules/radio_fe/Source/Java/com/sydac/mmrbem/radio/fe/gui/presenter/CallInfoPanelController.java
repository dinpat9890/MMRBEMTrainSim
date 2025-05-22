/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.radio.fe.gui.presenter;

import com.sydac.gui.i18n.CommonStrings;
import com.sydac.mmrbem.cabscreens.fe.common.NodePseudoClassProperty;
import com.sydac.mmrbem.radio.common.io.GroupName;
import com.sydac.mmrbem.radio.common.state.ApplicationConstants;
import com.sydac.mmrbem.radio.common.state.CallInfoStatus;
import com.sydac.mmrbem.radio.fe.common.TCMSUIConstants;
import com.sydac.mmrbem.radio.fe.gui.AbstractRadioController;
import com.sydac.mmrbem.radio.fe.gui.binder.CallInfoPanelBinder;
import com.sydac.mmrbem.radio.fe.gui.binder.PowerMenuAndNavPanelBinder;
import com.sydac.mmrbem.radio.fe.gui.model.CallInfoPanelModel;
import com.sydac.mmrbem.radio.fe.gui.model.DayDateTimeModel;
import com.sydac.mmrbem.radio.fe.gui.model.PowerMenuAndNavPanelModel;

import javafx.beans.value.ChangeListener;
import javafx.fxml.FXML;
import javafx.scene.control.Label;

/**
 * Provides common infrastructure like grid pane containers and labels for Call
 * Info Panel
 * 
 * @author ext-tambet
 */

public class CallInfoPanelController extends AbstractRadioController
{

  @FXML
  private Label callStatusLbl;

  @FXML
  private Label callStatusIconLbl;

  @FXML
  private Label dateLbl;

  @FXML
  private Label groupLbl;

  @FXML
  private Label groupNameLbl;

  @FXML
  private Label incomingCallNameLbl;

  @FXML
  private Label inputSsiLbl;

  @FXML
  private Label callSsiIdLbl;

  @FXML
  private Label tidLbl;

  private CallInfoPanelModel calllnfoPanelModel;

  private final DayDateTimeModel dayDateTimeModel = new DayDateTimeModel();

  private ChangeListener<String> timeListener;

  private ChangeListener<Number> inputSSiIdListener;

  private ChangeListener<String> callGroupNameListener;

  private ChangeListener<Number> callGroupStatusListener;

  private ChangeListener<Number> callSSiIdListener;

  private ChangeListener<String> incomingCallGroupNameListener;

  private NodePseudoClassProperty callStatusIconLabelProperty;

  private NodePseudoClassProperty callStatusLabelProperty;

  private ChangeListener<Number> depotIndicationListener;

  private ChangeListener<Number> callCategoryListener;

  private PowerMenuAndNavPanelModel powerMenuAndNavPanelModel;

  @Override
  public void detachListeners()
  {
    dayDateTimeModel.getDate().removeListener(timeListener);
    calllnfoPanelModel.getInputSsiId().removeListener(inputSSiIdListener);
    calllnfoPanelModel.getCallGroupName().removeListener(callGroupNameListener);
    calllnfoPanelModel.getCallGroupStatus().removeListener(callGroupStatusListener);
    calllnfoPanelModel.getCallSsiId().removeListener(callSSiIdListener);
    calllnfoPanelModel.getIncomingCallGroupName().removeListener(incomingCallGroupNameListener);
    
  }

  @Override
  public void initializeImpl()
  {
    calllnfoPanelModel = new CallInfoPanelModel(scenarioCarIndex);
    radioScreenBinders.add(new CallInfoPanelBinder(calllnfoPanelModel));

    powerMenuAndNavPanelModel = new PowerMenuAndNavPanelModel(scenarioCarIndex);
    radioScreenBinders.add(new PowerMenuAndNavPanelBinder(powerMenuAndNavPanelModel));

    callStatusLabelProperty = new NodePseudoClassProperty(callStatusLbl);
    callStatusIconLabelProperty = new NodePseudoClassProperty(callStatusIconLbl);

    timeListener = (observable, oldVal, newVal) -> updateDate(newVal);
    dayDateTimeModel.getDate().addListener(timeListener);

    inputSSiIdListener = (observable, oldVal, newVal) -> updateInputSsiId(newVal.intValue());
    calllnfoPanelModel.getInputSsiId().addListener(inputSSiIdListener);

    callGroupNameListener = (observable, oldVal, newVal) -> updateCallGroupName(newVal);
    calllnfoPanelModel.getCallGroupName().addListener(callGroupNameListener);

    callGroupStatusListener = (observable, oldVal, newVal) -> updateCallGroupStatus(newVal.intValue());
    calllnfoPanelModel.getCallGroupStatus().addListener(callGroupStatusListener);

    callSSiIdListener = (observable, oldVal, newVal) -> updateCallSsiId(newVal.intValue());
    calllnfoPanelModel.getCallSsiId().addListener(callSSiIdListener);

    incomingCallGroupNameListener = (observable, oldVal, newVal) -> updateIncomingCallGroupName(newVal);
    calllnfoPanelModel.getIncomingCallGroupName().addListener(incomingCallGroupNameListener);

    depotIndicationListener = (observable, oldVal, newVal) -> updateDepotIndicator(newVal.intValue());
    calllnfoPanelModel.getDepotIndication().addListener(depotIndicationListener);
    
    callCategoryListener = ((observable, oldVal, newVal) -> updateForGroupCall());
    powerMenuAndNavPanelModel.getContactNavBtnStatus().addListener(callCategoryListener);

   
    updateDate(dayDateTimeModel.getDate().get());

    updateInputSsiId(calllnfoPanelModel.getInputSsiId().get());

    updateCallGroupName(calllnfoPanelModel.getCallGroupName().get());

    updateCallGroupStatus(calllnfoPanelModel.getCallGroupStatus().intValue());

    updateCallSsiId(calllnfoPanelModel.getCallSsiId().get());

    updateIncomingCallGroupName(calllnfoPanelModel.getIncomingCallGroupName().get());

    updateDepotIndicator(calllnfoPanelModel.getDepotIndication().get());

  }

  /**
   * When there is group call ,dont show incoming call name.
   * 
   */
  private void updateForGroupCall()
  {
   
    if (ApplicationConstants.GROUP_BTN == powerMenuAndNavPanelModel.getContactNavBtnStatus().get())
    {
      incomingCallNameLbl.setText("");
    }

  }

  private void updateIncomingCallGroupName(String incomingGroupName)
  {
    incomingCallNameLbl.setText(incomingGroupName);

    if (incomingGroupName != null && incomingGroupName.length() > 0)
    {

      groupNameLbl.setText(incomingGroupName);
    }
    else
    {
      groupNameLbl.setText(calllnfoPanelModel.getCallGroupName().get());
    }
    updateForGroupCall();
  }

  private void updateCallSsiId(int ssiId)
  {
    callSsiIdLbl.setText(ssiId == 0 ? CommonStrings.BLANK : String.valueOf(ssiId));
  }

  private void updateCallGroupStatus(int callGroup)
  {
    callStatusLbl.setText(CallInfoStatus.valueOf(callGroup).getText());
    callStatusLabelProperty.set(CallInfoStatus.valueOf(callGroup).getCss());
    callStatusIconLabelProperty.set(CallInfoStatus.valueOf(callGroup).getCss());
  }

  private void updateCallGroupName(String callGroupType)
  {
    if (calllnfoPanelModel.getDepotIndication().get() == 1)
    {
      groupNameLbl.setText(GroupName.ROUTE_DEPOT.getName());
    }
    else
    {
      groupNameLbl.setText(callGroupType);
    }

  }

  private void updateInputSsiId(int ssiId)
  {
    inputSsiLbl.setText(ApplicationConstants.SSI_ID);
    tidLbl.setText(ApplicationConstants.TID);
    callSsiIdLbl.setText(ssiId == 0 ? CommonStrings.BLANK : String.valueOf(ssiId));
  }

  private void updateDate(String date)
  {
    dateLbl.setText(date);
  }

  private void updateDepotIndicator(int indicator)
  {

    if (calllnfoPanelModel.getDepotIndication().get() == 1)
    {
      groupNameLbl.setText(GroupName.ROUTE_DEPOT.getName());
    }
    else
    {
      groupNameLbl.setText(calllnfoPanelModel.getCallGroupName().get());
    }

  }
}

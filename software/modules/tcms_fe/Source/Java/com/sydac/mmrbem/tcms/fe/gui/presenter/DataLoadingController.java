/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.tcms.fe.gui.presenter;

import java.util.HashMap;
import java.util.Map;

import com.sydac.mmrbem.cabscreens.fe.common.NodePseudoClassProperty;
import com.sydac.mmrbem.tcms.common.state.VDUDataCatagory;
import com.sydac.mmrbem.tcms.fe.common.TCMSUIConstants;
import com.sydac.mmrbem.tcms.fe.gui.AbstractTCMSController;
import com.sydac.mmrbem.tcms.fe.gui.binder.DataLoadingBinder;
import com.sydac.mmrbem.tcms.fe.gui.model.DataLoadingModel;

import javafx.beans.value.ChangeListener;
import javafx.fxml.FXML;
import javafx.scene.control.Label;

public class DataLoadingController extends AbstractTCMSController
{
  @FXML
  private Label LoadingsignalsLbl;

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

  @FXML
  private Label progressLbl6;

  @FXML
  private Label progressLbl7;

  private DataLoadingModel dataLoadingModel;

  private ChangeListener<Number> progressListener;

  // This map contain list label
  private Map<Integer, NodePseudoClassProperty> labelMap = new HashMap<>();

  private NodePseudoClassProperty progressLbl1Property;

  private NodePseudoClassProperty progressLbl2Property;

  private NodePseudoClassProperty progressLbl3Property;

  private NodePseudoClassProperty progressLbl4Property;

  private NodePseudoClassProperty progressLbl5Property;

  private NodePseudoClassProperty progressLbl6Property;

  private NodePseudoClassProperty progressLbl7Property;

  @Override
  public void initializeImpl()
  {
    dataLoadingModel = new DataLoadingModel(scenarioCarIndex);
    tcmsScreenBinders.add(new DataLoadingBinder(dataLoadingModel));
    progressListener = (observable, oldVal, newVal) -> updateProgressMessage((int)newVal);
    dataLoadingModel.getProgressMessageId().addListener(progressListener);
    progressLbl1Property = new NodePseudoClassProperty(progressLbl1);
    progressLbl2Property = new NodePseudoClassProperty(progressLbl2);
    progressLbl3Property = new NodePseudoClassProperty(progressLbl3);
    progressLbl4Property = new NodePseudoClassProperty(progressLbl4);
    progressLbl5Property = new NodePseudoClassProperty(progressLbl5);
    progressLbl6Property = new NodePseudoClassProperty(progressLbl6);
    progressLbl7Property = new NodePseudoClassProperty(progressLbl7);
    initializeLabelScreenStateList();
    updateProgressMessage(dataLoadingModel.getProgressMessageId().get());
  }

  private void initializeLabelScreenStateList()
  {
    labelMap.put(VDUDataCatagory.PROGRESS_1_MESSAGE.getValue(), progressLbl1Property);
    labelMap.put(VDUDataCatagory.PROGRESS_2_MESSAGE.getValue(), progressLbl2Property);
    labelMap.put(VDUDataCatagory.PROGRESS_3_MESSAGE.getValue(), progressLbl3Property);
    labelMap.put(VDUDataCatagory.PROGRESS_4_MESSAGE.getValue(), progressLbl4Property);
    labelMap.put(VDUDataCatagory.PROGRESS_5_MESSAGE.getValue(), progressLbl5Property);
    labelMap.put(VDUDataCatagory.PROGRESS_6_MESSAGE.getValue(), progressLbl6Property);
    labelMap.put(VDUDataCatagory.PROGRESS_7_MESSAGE.getValue(), progressLbl7Property);
  }

  private void updateProgressMessage(int messageId)
  {
    LoadingsignalsLbl.setText(VDUDataCatagory.valueOf(messageId).getText());
    // Un-select all Lebel first
    for (Map.Entry<Integer, NodePseudoClassProperty> entry : labelMap.entrySet())
    {
      Integer key = entry.getKey();
      labelMap.get(key).set(TCMSUIConstants.UNSELECTED_PSEUDO_CLASS);
    }

    // Apply selected progree to select label
    for (Map.Entry<Integer, NodePseudoClassProperty> entry : labelMap.entrySet())
    {
      Integer key = entry.getKey();
      if (key <= messageId)
      {
        labelMap.get(key).set(TCMSUIConstants.SELECTED_PSEUDO_CLASS);
      }
    }
  }

  @Override
  public void detachListeners()
  {
    dataLoadingModel.getProgressMessageId().removeListener(progressListener);
  }

}

/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/

/**
 * @author ext-tambet
 **/
package com.sydac.mmrbem.radio.fe.gui.model;

import com.sydac.common.febe.frontend.gui.AbstractScreenModel;

import javafx.beans.property.IntegerProperty;
import javafx.beans.property.SimpleIntegerProperty;
import javafx.beans.property.SimpleStringProperty;
import javafx.beans.property.StringProperty;

/**
 * A model to Call Info Panel
 * 
 * @author ext-tambet
 *
 */
public class CallInfoPanelModel extends AbstractScreenModel
{

  private IntegerProperty callGroupStatus = new SimpleIntegerProperty();

  private StringProperty callGroupName = new SimpleStringProperty();

  private IntegerProperty callSsiId = new SimpleIntegerProperty();

  private IntegerProperty inputSsiId = new SimpleIntegerProperty();

  private StringProperty incomingCallGroupName = new SimpleStringProperty();
  
  private IntegerProperty depotIndication = new SimpleIntegerProperty();

  public CallInfoPanelModel(int carIndex)
  {
    super(carIndex);
  }

  public IntegerProperty getCallGroupStatus()
  {
    return callGroupStatus;
  }

  public void setCallGroupStatus(Integer callGroupStatus)
  {
    this.callGroupStatus.set(callGroupStatus);
  }

  public StringProperty getCallGroupName()
  {
    return callGroupName;
  }

  public void setCallGroupName(String callGroupName)
  {
    this.callGroupName.set(callGroupName);
  }

  public IntegerProperty getCallSsiId()
  {
    return callSsiId;
  }

  public void setCallSsiId(Integer callSsiId)
  {
    this.callSsiId.set(callSsiId);
  }

  public IntegerProperty getInputSsiId()
  {
    return inputSsiId;
  }

  public void setInputSsiId(Integer inputSsiId)
  {
    this.inputSsiId.set(inputSsiId);
  }

  public StringProperty getIncomingCallGroupName()
  {
    return incomingCallGroupName;
  }

  public void setIncomingCallGroupName(String groupName)
  {
    this.incomingCallGroupName.set(groupName);
  }

  public IntegerProperty getDepotIndication() 
  {
    return depotIndication;
  }

  public void setDepotIndication(Integer value) 
  {
      depotIndication.setValue(value);
  } 
}
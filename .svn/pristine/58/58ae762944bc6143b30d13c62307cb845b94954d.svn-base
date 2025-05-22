/*
 * ==================================================================
 * 
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.tcms.fe.gui.model;

import com.sydac.mmrbem.cabscreens.fe.gui.model.AbstractScreenModel;

import javafx.beans.property.IntegerProperty;
import javafx.beans.property.SimpleIntegerProperty;

public class HighVoltageRightTCarScreenModel extends AbstractScreenModel
{

  private IntegerProperty rightPantoState = new SimpleIntegerProperty();
  
  private IntegerProperty rightPantoLowState = new SimpleIntegerProperty();
  
  private IntegerProperty resetPantoButtonState = new SimpleIntegerProperty();
  
  private IntegerProperty resetVcbButtonState = new SimpleIntegerProperty();



  private IntegerProperty isloateVcbButtonState = new SimpleIntegerProperty();

  private IntegerProperty aps5ButtonState = new SimpleIntegerProperty();

  private IntegerProperty aps6ButtonState = new SimpleIntegerProperty();
  
  private IntegerProperty confirmState = new SimpleIntegerProperty();
  

  public HighVoltageRightTCarScreenModel(int carIndex)
  {
    super(carIndex);
  }

  public void setRightPantoState(Integer newValue)
  {
    this.rightPantoState.set(newValue);    
  }

  
  public IntegerProperty getRightPantoState()
  {
    return rightPantoState;
  }

  public void setRightPantoLowState(Integer newValue)
  {
    this.rightPantoLowState.set(newValue);    
    
  }
  
  public IntegerProperty getRightPantoLowState()
  {
    return rightPantoLowState;
  }

  public void setRightResetPantoState(Integer newValue)
  {
     this.resetPantoButtonState.set(newValue);
    
  }

  public IntegerProperty getRightResetPantoState()
  {
    return resetPantoButtonState;
  }
  
  public void setRightVcbResetState(Integer newValue)
  {
    this.resetVcbButtonState.set(newValue);

  }

  public IntegerProperty getRightVcbResetState()
  {
    return resetVcbButtonState;
  }

 
  public void setRightVcbIsolateState(Integer newValue)
  {
    this.isloateVcbButtonState.set(newValue);

  }

  public IntegerProperty getRightVcbIsolateState()
  {
    return isloateVcbButtonState;
  }

  public void setAps5IsolateState(Integer newValue)
  {
    this.aps5ButtonState.set(newValue);

  }

  public IntegerProperty getAps5IsolateState()
  {
    return aps5ButtonState;
  }

  public void setAps6IsolateState(Integer newValue)
  {
    this.aps6ButtonState.set(newValue);

  }

  public IntegerProperty getAps6IsolateState()
  {
    return aps6ButtonState;
  }

  public void setConfirmState(Integer newValue)
  {
   this.confirmState.set(newValue);
    
  }
  
  public IntegerProperty getConfirmState()
  {
    return confirmState;
  }
}

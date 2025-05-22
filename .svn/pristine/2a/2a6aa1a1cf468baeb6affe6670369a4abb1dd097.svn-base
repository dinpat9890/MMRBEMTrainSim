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

public class HighVoltageMiddleTCarScreenModel extends AbstractScreenModel
{

  private IntegerProperty middlePantoState = new SimpleIntegerProperty();

  private IntegerProperty middlePantoLowState = new SimpleIntegerProperty();

  private IntegerProperty resetPantoButtonState = new SimpleIntegerProperty();

  private IntegerProperty resetVcbButtonState = new SimpleIntegerProperty();

  private IntegerProperty isloatePantoButtonState = new SimpleIntegerProperty();

  private IntegerProperty isloateVcbButtonState = new SimpleIntegerProperty();

  private IntegerProperty aps3ButtonState = new SimpleIntegerProperty();

  private IntegerProperty aps4ButtonState = new SimpleIntegerProperty();

  public HighVoltageMiddleTCarScreenModel(int carIndex)
  {
    super(carIndex);
  }

  public void setMiddlePantoState(Integer newValue)
  {
    this.middlePantoState.set(newValue);
  }

  public IntegerProperty getMiddlePantoState()
  {
    return middlePantoState;
  }

  public void setMiddlePantoLowState(Integer newValue)
  {
    this.middlePantoLowState.set(newValue);
  }

  /**
   * @return the middlePantoLowState
   */
  public IntegerProperty getMiddlePantoLowState()
  {
    return middlePantoLowState;
  }

  public void setMidResetPantoState(Integer newValue)
  {
    this.resetPantoButtonState.set(newValue);

  }

  public IntegerProperty getMidResetPantoState()
  {
    return resetPantoButtonState;
  }
  
  
  public void setMidVcbResetState(Integer newValue)
  {
    this.resetVcbButtonState.set(newValue);

  }

  public IntegerProperty getMidVcbResetState()
  {
    return resetVcbButtonState;
  }

  public void setMidPantoIsolateState(Integer newValue)
  {
    this.isloatePantoButtonState.set(newValue);

  }

  public IntegerProperty getMidPantoIsolateState()
  {
    return isloatePantoButtonState;
  }

  public void setMidVcbIsolateState(Integer newValue)
  {
    this.isloateVcbButtonState.set(newValue);

  }

  public IntegerProperty getMidVcbIsolateState()
  {
    return isloateVcbButtonState;
  }

  public void setAps3IsolateState(Integer newValue)
  {
    this.aps3ButtonState.set(newValue);

  }

  public IntegerProperty getAps3IsolateState()
  {
    return aps3ButtonState;
  }

  public void setAps4IsolateState(Integer newValue)
  {
    this.aps4ButtonState.set(newValue);

  }

  public IntegerProperty getAps4IsolateState()
  {
    return aps4ButtonState;
  }
}

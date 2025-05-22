/*
 * ==================================================================
 * 
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.tcms.common.data;

import com.sydac.mmrbem.tcms.common.proto.TCMSProto.TrainSideViewStatusList.ActiveCabState;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.TrainSideViewStatusList.BoogieIsolationState;

public class TrainSideViewStatusDO
{
  private BoogieIsolationState bogie1IsolationState = BoogieIsolationState.NOT_ISOLATED;

  private BoogieIsolationState bogie2IsolationState = BoogieIsolationState.NOT_ISOLATED;

  private ActiveCabState activeCabState = ActiveCabState.NOT_ACTIVE;

  public ActiveCabState getActiveCabState()
  {
    return activeCabState;
  }

  public void setActiveCabState(ActiveCabState activeCabState)
  {
    this.activeCabState = activeCabState;
  }

  public BoogieIsolationState getBogie1IsolationState()
  {
    return bogie1IsolationState;
  }

  public void setBogie1IsolationState(BoogieIsolationState bogie1IsolationState)
  {
    this.bogie1IsolationState = bogie1IsolationState;
  }

  public BoogieIsolationState getBogie2IsolationState()
  {
    return bogie2IsolationState;
  }

  public void setBogie2IsolationState(BoogieIsolationState bogie2IsolationState)
  {
    this.bogie2IsolationState = bogie2IsolationState;
  }
}

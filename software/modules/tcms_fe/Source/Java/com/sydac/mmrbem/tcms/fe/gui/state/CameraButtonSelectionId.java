/*
 * ==================================================================
 * 
 * 
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.tcms.fe.gui.state;

public enum CameraButtonSelectionId
{

  SIX_CAR_DMC_1(1), SIX_CAR_TC_2(2), SIX_CAR_MC_3(3), SIX_CAR_MC_4(4), SIX_CAR_TC_5(5), SIX_CAR_DMC_6(
      6), EIGHT_CAR_DMC_1(1), EIGHT_CAR_TC_2(2), EIGHT_CAR_MC_3(3), EIGHT_CAR_TC_4(4), EIGHT_CAR_MC_5(
          5), EIGHT_CAR_MC_6(6), EIGHT_CAR_TC_7(7), EIGHT_CAR_DMC_8(
              8), EXT_ECAM_L(1), EXT_FCAM(2), EXT_TCAM(3), EXT_OCAM(4), EXT_PCAM(5), EXT_ECAM_R(6);

  private int selectionId;

  CameraButtonSelectionId(int selectionId)
  {
    this.selectionId = selectionId;
  }

  public int getSelectionId()
  {
    return selectionId;
  }

  public static CameraButtonSelectionId getSelectionIdOf(int aValue)
  {
    for (CameraButtonSelectionId status : values())
    {
      if (status.selectionId == aValue)
      {
        return status;
      }
    }
    return null;
  }
}

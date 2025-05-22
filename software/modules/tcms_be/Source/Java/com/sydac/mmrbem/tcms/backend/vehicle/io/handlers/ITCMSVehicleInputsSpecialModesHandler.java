/*
 * *****************************************************************************
 * * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.tcms.backend.vehicle.io.handlers;

public interface ITCMSVehicleInputsSpecialModesHandler
{

  void setActivateHte(int value);

  void setActivateWashing3Kmph(int value);

  void setActivateWashing4Kmph(int value);

  void setActivateWashing5Kmph(int value);

  void setShuntModeMaxSpeed(int value);

  void setShuntModeMinSpeed(int value);

  void setAtpLowModeMaxSpeed(int value);
  
  void setAtpLowModeActivated(int value);
  
  void setShuntModeActivated(int value);

}

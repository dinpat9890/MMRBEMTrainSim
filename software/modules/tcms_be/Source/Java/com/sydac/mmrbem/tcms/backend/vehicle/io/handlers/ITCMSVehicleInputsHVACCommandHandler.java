/*
 * *****************************************************************************
 * * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.tcms.backend.vehicle.io.handlers;

public interface ITCMSVehicleInputsHVACCommandHandler
{

  void setTcmsHvac1ResetReq(int value);

  void setTcmsHvac2ResetReq(int value);

  void setTcmsHvac1IsolateReq(int value);

  void setTcmsHvac2IsolateReq(int value);

  void setTcmsHvacSmokeResetReq(int value);

  void setTcmsWflIsolationReq(int value);
}

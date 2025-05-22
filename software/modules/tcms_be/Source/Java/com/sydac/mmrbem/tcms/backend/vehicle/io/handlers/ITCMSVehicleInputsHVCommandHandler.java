/*
 * *****************************************************************************
 * * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.tcms.backend.vehicle.io.handlers;

public interface ITCMSVehicleInputsHVCommandHandler
{

  void setTcmsPantoLowerReq(int value);

  void setTcmsPantoResetReq(int value);

  void setTcmsPantoRiseReq(int value);

  void setTcmsVcbResetReq(int value);

  void setTcmsVcbOpenReq(int value);

  void setTcmsVcbCloseReq(int value);

  void setTcmsIsolateCi(int value);

  void setTcmsIsolatePanto(int value);

  void setTcmsIsolateVcb(int value);

  void setTcmsIsolateAps1(int value);

  void setTcmsIsolateAps2(int value);

  void setTcmsReqCtrlVcbNs(int value);
}

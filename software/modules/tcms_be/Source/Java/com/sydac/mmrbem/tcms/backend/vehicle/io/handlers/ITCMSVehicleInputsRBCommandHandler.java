/*
 * *****************************************************************************
 * * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.tcms.backend.vehicle.io.handlers;

public interface ITCMSVehicleInputsRBCommandHandler
{

  void setTcmsFdscbOpen(int value);

  void setTcmsFdscbClose(int value);

  void setTcmsApsicbClose(int value);

  void setTcmsApsicbOpen(int value);

  void setTcmsHvac1Open(int value);

  void setTcmsHvac2Open(int value);

  void setTcmsHvac1Close(int value);

  void setTcmsHvac2Close(int value);
}

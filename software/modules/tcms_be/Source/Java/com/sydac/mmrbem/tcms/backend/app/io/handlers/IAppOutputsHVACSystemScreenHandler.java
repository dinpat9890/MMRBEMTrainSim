/*
 * ==================================================================
 * (C)Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * ==================================================================
 */
package com.sydac.mmrbem.tcms.backend.app.io.handlers;

import com.sydac.foundation.IPropertySetter;

public interface IAppOutputsHVACSystemScreenHandler extends IPropertySetter
{
  void setHvacOperatingModeStatus1(byte[] byteArray);

  void setHvacOperatingModeStatus2(byte[] byteArray);

  void setSetPointTemperatureStatus1(byte[] byteArray);

  void setSetPointTemperatureStatus2(byte[] byteArray);

  void setInternalTemperatureStatus1(byte[] byteArray);

  void setInternalTemperatureStatus2(byte[] byteArray);

  void setExternalTemperatureStatus1(byte[] byteArray);

  void setExternalTemperatureStatus2(byte[] byteArray);
  
  void setHvacControlModeStatus1(byte[] byteArray);

  void setHvacControlModeStatus2(byte[] byteArray);
}

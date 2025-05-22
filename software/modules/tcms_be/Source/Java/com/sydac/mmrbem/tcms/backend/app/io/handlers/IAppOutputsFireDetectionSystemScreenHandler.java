/*
 * ==================================================================
 * (C)Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * ==================================================================
 */
package com.sydac.mmrbem.tcms.backend.app.io.handlers;

import com.sydac.foundation.IPropertySetter;

public interface IAppOutputsFireDetectionSystemScreenHandler extends IPropertySetter
{
  void setFduSystemFaultStatus(byte[] byteArray);

  void setFireSensorFaultStatus(byte[] byteArray);

  void setFireSensorAlarmStatus(byte[] byteArray);

  void setFireSensorDisabledStatus(byte[] byteArray);

  void setFireSystemInternalFireStatus(byte[] byteArray);

  void setFireSystemExternalSmokeStatus(byte[] byteArray);

  void setFireSystemUfarStatus(byte[] byteArray);

  void setFireSystemSfarStatus(byte[] byteArray);

  void setFireSystemUnderFrameFireStatus(byte[] byteArray);
}

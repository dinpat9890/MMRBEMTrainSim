/*
 * ==================================================================
 * (C)Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * ==================================================================
 */
package com.sydac.mmrbem.tcms.backend.app.io.handlers;

import com.sydac.foundation.IPropertySetter;

public interface IAppOutputsECNScreenHandler extends IPropertySetter
{
  void setEcnCsAStatusList(byte[] byteArray);

  void setEcnCsBStatusList(byte[] byteArray);

  void setEcnCsCStatusList(byte[] byteArray);

  void setEcnTbnStatusList(byte[] byteArray);

  void setEcnTerStatusList(byte[] byteArray);

  void setEcnAlgStatusList(byte[] byteArray);
}

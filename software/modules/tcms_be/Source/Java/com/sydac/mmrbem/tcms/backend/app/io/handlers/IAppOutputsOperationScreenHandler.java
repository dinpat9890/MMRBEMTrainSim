/*******************************************************************************
 * (C) Copyright 2022 Oktal-Sydac Pty Ltd., all rights reserved. This is
 * unpublished proprietary source code of Oktal-Sydac. The copyright notice
 * above does not evidence any actual or intended publication of such source
 * code.
 *******************************************************************************/
package com.sydac.mmrbem.tcms.backend.app.io.handlers;

import com.sydac.foundation.IPropertySetter;

public interface IAppOutputsOperationScreenHandler extends IPropertySetter
{
  void setPantographStatus(byte[] byteArray);

  void setVcbStatus(byte[] byteArray);

  void setTrainSideViewStatus(byte[] byteArray);

  void setDriverCabDirection(byte[] byteArray);

  void setPropulsionStatus(byte[] byteArray);

  void setServiceBrakeStatus(byte[] byteArray);
  
  void setParkingBrakeStatus(byte[] byteArray);
  
  void setCiStatus(byte[] byteArray);
}

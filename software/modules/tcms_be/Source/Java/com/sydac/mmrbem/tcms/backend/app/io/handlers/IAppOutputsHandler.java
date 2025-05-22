/*******************************************************************************
 * (C) Copyright 2022 Oktal-Sydac Pty Ltd., all rights reserved. This is
 * unpublished proprietary source code of Oktal-Sydac. The copyright notice
 * above does not evidence any actual or intended publication of such source
 * code.
 *******************************************************************************/
package com.sydac.mmrbem.tcms.backend.app.io.handlers;

import com.sydac.foundation.IPropertySetter;

/**
 * This interface supplies mutators for ApplicationOutputs variables.
 * 
 * @see IPropertySetter
 * @author joshian
 *
 */
public interface IAppOutputsHandler extends IAppOutputsOperationScreenHandler, IAppOutputsBrakeScreenHandler,
    IAppOutputsBatteryScreenHandler, IAppOutputsApsScreenHandler, IAppOutputsActiveFaultsScreenHandler,
    IAppOutputsFaultDetailsScreenHandler, IAppOutputsEventDisplayAreaHandler,
    IAppOutputsEnergyConsumptionCounterScreenHandler, IAppOutputsFireSystemTestScreenHandler,
    IAppOutputsBrakeSystemTestScreenHandler, IAppOutputsDoorSystemTestScreenHandler,
    IAppOutputsHVACSystemTestScreenHandler, IAppOutputsPISSystemTestScreenHandler,
    IAppOutputsBatterySystemTestScreenHandler, IAppOutputsSystemTestScreenHandler,
    IAppOutputsECNScreenHandler, IAppOutputsFireDetectionSystemScreenHandler,
    IAppOutputsHVACSystemScreenHandler, IAppOutputsMediumVoltageSystemScreenHandler,
    IAppOutputsWFLSystemScreenHandler, IAppOutputsLoggedFaultsScreenHandler,IAppOutputsTcmsStatusScreenHandler
{
  void setTcmsCurrentScreenId(Integer screenId);

  void setTcmsPopupScreenId(Integer popupId);

  void setCctvCurrentScreenId(Integer screenId);

  void setCctvPopupScreenId(Integer popupId);
}
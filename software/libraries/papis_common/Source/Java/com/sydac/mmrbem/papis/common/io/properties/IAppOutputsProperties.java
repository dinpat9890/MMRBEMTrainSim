/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.papis.common.io.properties;

import com.sydac.foundation.PropertyKey;

/**
 * This interface defines {@link PropertyKey} instances for ApplicaitonOutputs.
 *
 */
public interface IAppOutputsProperties extends IAppOutputsScreenChangeProperties, IAppOutputsCommonProperties,
    IAppOutputsSystemSettingsScreenProperties, IAppOutputsSkipStationSettingScreenProperties,
    IAppOutputsManualModeSettingScreenProperties, IAppOutputsPassengerAlarmScreenProperties,
    IAppOutputsRouteSettingScreenProperties, IAppOutputsSpecialInformationScreenProperties,
    IAppOutputsEmergencyInformationScreenProperties, IAppOutputsStationSettingScreensProperties

{

}

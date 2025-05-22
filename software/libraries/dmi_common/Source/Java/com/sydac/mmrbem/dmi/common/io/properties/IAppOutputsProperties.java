/*******************************************************************************
 * (C) Copyright 2020 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.dmi.common.io.properties;

import com.sydac.foundation.PropertyKey;

/**
 * This interface defines {@link PropertyKey} instances for ApplicaitonOutputs.
 *
 */
public interface IAppOutputsProperties extends IAppOutputsMainScreenAreaAProperties,
    IAppOutputsScreenChangeProperties, IAppOutputsCrewIdPopupProperties, IAppOutputsPopupMenuProperties,
    IAppOutputsMainScreenAreaDMiddleProperties, IAppOutputsMainScreenAreaTextMessageProperties,
    IAppOutputsMainScreenProperties, IAppOutputsStartupScreenProperties,
    IAppOutputsMainScreenAreaBLeftProperties, IAppOutputsMainScreenAreaCRightProperties,
    IAppOutputsMainScreenAreaETopProperties, IAppOutputsScreenSaverProperties,
    IAppOutputsMainScreenSettingsProperties
{

}

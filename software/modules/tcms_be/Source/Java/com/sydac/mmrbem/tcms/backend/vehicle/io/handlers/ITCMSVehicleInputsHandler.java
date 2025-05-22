/*
 * *****************************************************************************
 * * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.tcms.backend.vehicle.io.handlers;

import com.sydac.foundation.IPropertySetter;

public interface ITCMSVehicleInputsHandler extends IPropertySetter, ITCMSVehicleInputsLVCommandHandler,
    ITCMSVehicleInputsBrakeSystemCommandsHandler, ITCMSVehicleInputsDoorsSystemCommandsHandler,
    ITCMSVehicleInputsMiscellaniaScreenHandler, ITCMSVehicleInputsHVCommandHandler,
    ITCMSVehicleInputsSpecialModesHandler, ITCMSVehicleInputsRBCommandHandler,
    ITCMSVehicleInputsMVCommandHandler, ITCMSVehicleInputsHVACCommandHandler, ITCMSVehicleInputsFireHandler
{

}

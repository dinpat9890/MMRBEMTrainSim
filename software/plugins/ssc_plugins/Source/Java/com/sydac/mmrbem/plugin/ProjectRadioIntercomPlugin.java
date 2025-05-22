/* ==================================================================
 *
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved.
 *  This is unpublished proprietary source code of Sydac.
 *  The copyright notice above does not evidence any actual
 *  or intended publication of such source code.
 *
 * ==================================================================
 */
package com.sydac.mmrbem.plugin;

import com.sydac.mmrbem.radiointercomplugin.model.RadioDataModel;
import com.sydac.mmrbem.radiointercomplugin.model.ProjectRadioDataModel;

/**
 * Project specific {@link RadioIntercomPlugin}
 * @author mulukg
 *
 */
public class ProjectRadioIntercomPlugin extends RadioIntercomPlugin
{
  protected RadioDataModel getRadioDataModel(int scenarioTrainId, int vehicleIndex, int noOfVehicles)
  {
    return new ProjectRadioDataModel(scenarioTrainId, vehicleIndex, noOfVehicles);
  }
}
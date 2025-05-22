/* ==================================================================
 *
 *  (C) Copyright 2006 Sydac Pty Ltd., all rights reserved.
 *  This is unpublished proprietary source code of Sydac.
 *  The copyright notice above does not evidence any actual
 *  or intended publication of such source code.
 *
 * ==================================================================
 */
package com.sydac.project.runtimedata;

import com.sydac.common.runtimedata.ICommonObjects;
import com.sydac.project.featuredata.ProjectFeatureConstants;

/**
 * This class allows Core Software to access {@link ProjectObjectConstants}
 */
public class ProjectObjects implements ICommonObjects
{

  @Override
  public int getClassIdForObjectName(String aObjectName)
  {
    return ProjectObjectConstants.getClassIdForObjectName(aObjectName);
  } // getClassIdForObjectName

  @Override
  public String getInstanceNumberNameForClassId(int aClassId)
  {
    return ProjectObjectConstants.getInstanceNumberNameForClassId(aClassId);
  } // getInstanceNumberNameForClassId

  @Override
  public String getFeatureAutomatedUserStateName()
  {
    // In case the project does not have any features that are automated
    // return ProjectFeatureConstants.States.AUTOMATED;
    return "Automated";
  } // getFeatureAutomatedUserStateName

  @Override
  public String getTrainTrackAdhesionPropertyName()
  {
    // In case the train has not defined the track adhesion override
    //return ProjectObjectConstants.Train.OVI_TRACK_ADHESION;
    return "Track Adhesion Override";
  } // getTrainTrackAdhesionPropertyName

  @Override
  public String getTrainIgnoreVigilancePropertyName()
  {
    // In case the train has not defined the ignore vigilance override
    //return ProjectObjectConstants.Train.OVI_IGNORE_VIGILANCE;
    return "Ignore Vigilance Override";
  } // getTrainIgnoreVigilancePropertyName

  @Override
  public String getTrainPositionPropertyName()
  {
    return ProjectObjectConstants.Train.LLO_LEAD_LOCO_POSITION;
  } // getTrainPositionPropertyName

  @Override
  public String getTrainSpeedPropertyName()
  {
    return ProjectObjectConstants.Train.LLO_LEAD_LOCO_SPEED;
  } // getTrainSpeedPropertyName

  @Override
  public String getTrainTargetSpeedPropertyName()
  {
    return ProjectObjectConstants.Train.LLO_LEAD_LOCO_SPEED;
  } // getTrainTargetSpeedPropertyName

  @Override
  public String getVehiclePositionPropertyName()
  {
    return ProjectObjectConstants.Vehicle.TDO_VEHICLE_POSITION;
  } // getVehiclePositionPropertyName

  @Override
  public String getVehicleSpeedPropertyName()
  {
    return ProjectObjectConstants.Vehicle.TDO_SPEED;
  } // getVehicleSpeedPropertyName

} // class ProjectObjects

// -- EOF

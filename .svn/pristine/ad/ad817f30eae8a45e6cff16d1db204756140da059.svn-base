/*
 * ==================================================================
 *
 * (C) Copyright 2020 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *
 * ==================================================================
 */

package com.sydac.mmrbem.marshalling;

import static com.sydac.mmrbem.marshalling.i18n.ProjectTrainMarshallingI18N.t;

import java.text.MessageFormat;

import com.sydac.common.database.validation.ValidateFailMessages;
import com.sydac.common.dataobjects.DBTrain;
import com.sydac.common.dataobjects.DBTrainElement;
import com.sydac.common.log.Tracer;
import com.sydac.simulatormanager.marshalling.ITrainMarshallingRules;

/**
 * @author joshian.
 */
public class Mumbai_TrainSimMarshallingRules implements ITrainMarshallingRules
{
  private static final int MAX_MOTOR_COACHES_IN_TRAIN = 6;

  private static final int MAX_TRAILING_COACHES_IN_TRAIN = 2;

  private static final int MIN_MOTOR_COACHES_IN_TRAIN = 4;

  private static final int MIN_TRAILING_COACHES_IN_TRAIN = 1;

  // private static final String EMU_TRAIN_TYPE = "Chile_EMU";

  private String trainType;

  @Override
  public int getMaxTrailingCarsInTrain(DBTrain dbTrain)
  {
    return MAX_TRAILING_COACHES_IN_TRAIN;
  }

  @Override
  public int getMaxMotorCarsInTrain(DBTrain dbTrain)
  {
    return MAX_MOTOR_COACHES_IN_TRAIN;
  }

  @Override
  public int getMaxCarsInTrain(DBTrain dbTrain)
  {

    return MAX_MOTOR_COACHES_IN_TRAIN + MAX_TRAILING_COACHES_IN_TRAIN;
  }

  public int getMinCarsInTrain(DBTrain dbTrain)
  {

    return MIN_MOTOR_COACHES_IN_TRAIN + MIN_TRAILING_COACHES_IN_TRAIN;
  }

  @Override
  public boolean validateTrain(ValidateFailMessages validateFailMessages, DBTrain dbTrain)
  {

    int maxAllowedCarsInTrain = getMaxCarsInTrain(dbTrain);
    int minRequiredCarsInTrain = getMinCarsInTrain(dbTrain);
    int countElements = dbTrain.getElements().getCount();

    if (countElements > maxAllowedCarsInTrain)
    {
      validateFailMessages.addError(
          MessageFormat.format(t("The Tram cannot have more than {0} coaches."), maxAllowedCarsInTrain)); // $NON-NLS-1$
      return false;
    }
    else if (countElements < minRequiredCarsInTrain)
    {
      validateFailMessages.addError(
          MessageFormat.format(t("The Tram cannot have less than {0} coaches."), minRequiredCarsInTrain)); // $NON-NLS-1$
      return false;
    }
    Mumbai_TrainSim rake = Mumbai_TrainSim.getTramRake(countElements);
    if (null == rake)
    {
      validateFailMessages.addError(MessageFormat.format(
          t("This is not a valid Tram configuration. Unexpected number of coaches : {0}"), countElements)); // $NON-NLS-1$
      return false;
    }
    for (DBTrainElement el : dbTrain.getElements())
    {
      int position = el.getPosition();
      if (position > countElements)
      {
        Tracer.getInstance().errorFmt(
            "Vehicle Position %d of car is greater than the number of vehicles %d in the train : %s", //$NON-NLS-1$
            position, countElements, dbTrain.getDescription());
        validateFailMessages.addError(t("Internal Tram arrangement Error : Please Check the Logs")); //$NON-NLS-1$
        return false;
      }
      else
      {
        // Mumbai_TrainSim.Coaches expectedCoachType =
        // rake.getSixCarCoachType(position);
        Mumbai_TrainSim.Coaches expectedCoachType;
        if (Mumbai_TrainSim.SIX_CAR.getCoachesCount() == countElements)
        {
          expectedCoachType = rake.getSixCarCoachType(position);
        }
        else
        {
          expectedCoachType = rake.getEightCarCoachType(position);
        }
        String actualCoachType = el.getCar().getClassType().getClassCode();
        System.out.println(
            "expectedCoachType ---- " + expectedCoachType + "     actualCoachType ---- " + actualCoachType);
        if (!expectedCoachType.name().equals(actualCoachType))
        {
          validateFailMessages.addError(MessageFormat.format(
              t("The expected vehicle at position {0} is {1}."), position + 1, expectedCoachType.name())); // $NON-NLS-1$
          return false;
        }
        Mumbai_TrainSim.Orientation expectedOrientation;
        String actualOrientation = el.getCar().getOrientation().getCodeName();

        expectedOrientation = rake.getOrientationType(position);
        if (!expectedOrientation.getCode().equals(actualOrientation))
        {
          validateFailMessages
              .addError(MessageFormat.format(t("The expected orientation of coach at position {0} is {1}."),
                  position + 1, expectedOrientation.getCode())); // $NON-NLS-1$
          return false;
        }
      }

    }
    // }
    return true;
  }
}

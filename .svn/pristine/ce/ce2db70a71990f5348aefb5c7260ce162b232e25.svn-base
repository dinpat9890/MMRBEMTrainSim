/*
 * ==================================================================
 *
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *
 * ==================================================================
 */
package com.sydac.mmrbem.tcms.fe.gui.presenter;

import java.util.HashMap;
import java.util.Map;

import com.sydac.mmrbem.tcms.fe.base.TCMSFactory;
import com.sydac.mmrbem.tcms.fe.gui.binder.TrainConfigurationBinder;
import com.sydac.mmrbem.tcms.fe.model.TrainConfigurationModel;

/**
 * Class to hold {@link TrainConfigurationModel} against car index
 * (scenarioCarIndex)
 * 
 * @author walbeg
 *
 */
public class TrainConfigurationController
{
  private static final Map<Integer, TrainConfigurationController> INSTANCE_MAP = new HashMap<>();

  protected TrainConfigurationModel trainConfigurationModel;

  private TrainConfigurationController(int scenarioCarIndex)
  {
    trainConfigurationModel = new TrainConfigurationModel(scenarioCarIndex);
    TrainConfigurationBinder binder = new TrainConfigurationBinder(trainConfigurationModel);
    binder.attachToModel(TCMSFactory.getCommsBinding(scenarioCarIndex));
  }

  /**
   * Get the {@link TrainConfigurationModel} reference for the given car index.
   * Note: If {@link TrainConfigurationModel} is not created for given scenario
   * car index then first it will create {@link TrainConfigurationModel}
   * 
   * @param scenarioCarIndex
   *          scenario car index
   * @return {@link TrainConfigurationModel} reference for given scenario car
   *         index
   */
  public static TrainConfigurationModel getTrainConfigurationModelInstance(int scenarioCarIndex)
  {
    cleanup();
    synchronized (INSTANCE_MAP)
    {
      if (!INSTANCE_MAP.containsKey(scenarioCarIndex))
      {
        INSTANCE_MAP.put(scenarioCarIndex, new TrainConfigurationController(scenarioCarIndex));
      }
    }

    return INSTANCE_MAP.get(scenarioCarIndex).trainConfigurationModel;

  }

  /**
   * Flush the map off {@link TrainConfigurationModel}
   */
  public static void cleanup()
  {
    INSTANCE_MAP.clear();
  }

  public static String debugDump()
  {
    return INSTANCE_MAP.toString();
  }
}

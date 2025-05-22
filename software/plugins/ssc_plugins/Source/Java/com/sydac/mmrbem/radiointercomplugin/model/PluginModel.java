/*
 * ==================================================================
 *
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *
 * ==================================================================
 */
package com.sydac.mmrbem.radiointercomplugin.model;

import java.util.ArrayList;

import com.sydac.simulatorcontroller.model.DynamicModel;

/**
 * Plugin version of the SimulationModel for the SCC Radio. Allows the model to
 * be set and retrieved. Fires an event on change.
 */
public class PluginModel extends DynamicModel
{
  public enum Change
  {
    /** Identifies that the radio sub-model has changed */
    RADIO_DATA_MODEL_CHANGED,

  }

  /** The singleton instance */
  private static PluginModel instance = null;

  private RadioDataModel radioDataModel = null;

  private ArrayList<String> vehicleList = new ArrayList<>();

  /**
   * Returns the single instance of this class.
   * 
   * @return a <code>PluginModel</code>
   */
  public static synchronized PluginModel getInstance()
  {
    if (instance == null)
    {
      instance = new PluginModel();
      instance.create();
    }

    return instance;
  }

  /**
   * Default private constructor.
   */
  PluginModel()
  {}

  /**
   * Sets the radio model.
   * 
   * @param aModel
   *          an <code>RadioDataModel</code> object, or <code>null</code>
   */
  public void setRadioDataModel(RadioDataModel aModel)
  {
    if (radioDataModel != aModel)
    {
      radioDataModel = aModel;
      fireModelChangedEvent(Change.RADIO_DATA_MODEL_CHANGED);
    }
  }

  /**
   * Returns the environment model.
   * 
   * @return an <code>RadioDataModel</code> object, or <code>null</code>
   */
  public RadioDataModel getRadioDataModel()
  {
    return radioDataModel;
  }

  public ArrayList<String> getVehicleList()
  {
    return vehicleList;
  }

  public void setVehicleList(ArrayList<String> vehicleList)
  {
    this.vehicleList = vehicleList;
  }
}

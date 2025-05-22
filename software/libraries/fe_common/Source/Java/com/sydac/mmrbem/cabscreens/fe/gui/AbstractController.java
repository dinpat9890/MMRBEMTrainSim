/*
 * ==================================================================
 * 
 * (C) Copyright 2020 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.cabscreens.fe.gui;

import java.lang.reflect.Field;
import java.util.ArrayList;
import java.util.Map;
import java.util.Map.Entry;

import com.sydac.common.log.Tracer;
import com.sydac.mmrbem.cabscreens.fe.common.IFrontend;
import com.sydac.mmrbem.cabscreens.fe.gui.binder.AbstractScreenBinder;

import javafx.fxml.FXML;
import javafx.scene.Node;

/**
 * Abstract class for all FXML Controller classes in the TMS application.
 * 
 */
public abstract class AbstractController
{
  public static final String COMMS_NUMBER_KEY = "comms.number.key"; //$NON-NLS-1$

  private Map<String, String> mapping;

  protected int scenarioCarIndex;

  protected ArrayList<AbstractScreenBinder> screenBinders = new ArrayList<>();

  protected static Tracer logger = Tracer.getInstance();

  protected boolean isTenCar;

  protected IFrontend frontend;

  /**
   * @param scenarioCarIndex
   *          the scenarioCarIndex to set
   */
  public final void setScenarioCarIndex(int scenarioCarIndex)
  {
    this.scenarioCarIndex = scenarioCarIndex;
  }

  public final void setFrontend(IFrontend frontend)
  {
    this.frontend = frontend;
  }

  /**
   * Method that is called by the FMXL Loader during initialization of the FXML.
   */
  @FXML
  public void initialize()
  {
    /* Assign COMMS number to any @CommsNumber annotated JavaFx Controls */
    assignCommsNumberToFxControl();

    /* Initialize the controller */
    initializeImpl();

    /* Trigger doBinding on all models in the controller */
    triggerModelBindings();

  }

  /**
   * Set the Control to Comms mapping data for the controller
   * 
   * @param mapping
   *          map
   */
  public final void setFxControlToCommsMapping(Map<String, String> mapping)
  {
    this.mapping = mapping;
  }

  /*
   * Inject the CommsNumber property into the corresponding Controls.
   */
  protected void assignCommsNumberToFxControl()
  {
    // This is temporary hack to load fxml programmatically
    if (mapping == null)
    {
      return;
    }

    for (Entry<String, String> controlEntry : mapping.entrySet())
    {
      try
      {
        Field field = this.getClass().getDeclaredField(controlEntry.getKey());
        field.setAccessible(true);
        addProperty(controlEntry, field);
      }
      catch (NoSuchFieldException | SecurityException e)
      {
        Tracer.getInstance().error(e);
      }
    }
  }

  private void addProperty(Entry<String, String> controlEntry, Field field)
  {
    try
    {
      ((Node)field.get(this)).getProperties().put(COMMS_NUMBER_KEY, controlEntry.getValue());
    }
    catch (IllegalArgumentException | IllegalAccessException e)
    {
      Tracer.getInstance().error(e);
    }
    finally
    {
      field.setAccessible(false);
    }
  }

  /*
   * Find all models in the controller and invoke doBinding() on them.
   */
  private void triggerModelBindings()
  {
    for (AbstractScreenBinder screenBinder : screenBinders)
    {
      screenBinder.doBinding();
    }
  }

  /**
   * Method that gets called during initialization of the FMXL. Child classes
   * are expected to perform UI related initializations here.
   */
  public abstract void initializeImpl();

  public abstract void removeListeners();

  public void setIsTenCar(boolean isTenCar)
  {
    this.isTenCar = isTenCar;
  }
}

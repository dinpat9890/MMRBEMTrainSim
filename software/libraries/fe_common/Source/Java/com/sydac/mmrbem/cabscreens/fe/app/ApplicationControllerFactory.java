/*
 * ==================================================================
 * 
 * (C) Copyright 2020 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.cabscreens.fe.app;

import java.lang.reflect.Field;
import java.util.HashMap;
import java.util.Map;

import com.sydac.common.log.Tracer;
import com.sydac.mmrbem.cabscreens.fe.base.CommsNumber;
import com.sydac.mmrbem.cabscreens.fe.common.IFrontend;
import com.sydac.mmrbem.cabscreens.fe.gui.AbstractController;

import javafx.fxml.FXML;
import javafx.scene.control.ButtonBase;
import javafx.util.Callback;

/**
 * {@link Callback} implementation that is injected while loading the FXML to
 * intercept the creation of Controller classes for the FXMLs. <br>
 * 
 * @author Nazim Oliyath
 *
 */
public class ApplicationControllerFactory implements Callback<Class<?>, Object>
{

  private int scenarioCarIndex;

  private boolean isTenCar;

  private IFrontend frontend;

  /**
   * @return the scenarioCarIndex
   */
  public final int getScenarioCarIndex()
  {
    return scenarioCarIndex;
  }

  public final void setFrontend(IFrontend frontend)
  {
    this.frontend = frontend;
  }

  /**
   * @param scenarioCarIndex
   *          the scenarioCarIndex to set
   */
  public final void setScenarioCarIndex(int scenarioCarIndex)
  {
    this.scenarioCarIndex = scenarioCarIndex;
  }

  /**
   * Creates instance of the controller class
   */
  @Override
  public Object call(Class<?> type)
  {
    AbstractController controllerInstance = null;
    try
    {
      boolean isAssignable = AbstractController.class.isAssignableFrom(type);
      assert isAssignable : "Controller classes should be sub-class of com.sydac.mmrbem.cabscreens.fe.gui.AbstractController"; //$NON-NLS-1$

      if (isAssignable)
      {
        controllerInstance = (AbstractController)type.newInstance();

        setCommsNumberAttributeOnControl(controllerInstance);
        controllerInstance.setScenarioCarIndex(this.scenarioCarIndex);
        controllerInstance.setIsTenCar(this.isTenCar);
        controllerInstance.setFrontend(this.frontend);
      }
    }
    catch (InstantiationException | IllegalAccessException e)
    {
      Tracer.getInstance().error(e);
    }
    return controllerInstance;
  }

  /*
   * Looks up all the instance variables in the controller class and picks the
   * javafx.scene.control.Control(s) that have a @FXML and @CommsNumber
   * attribute.
   * 
   * Note: @CommsNumber value cannot be assigned into the Control at this point
   * because the FMXL Loader has not yet injected instance objects for them in
   * the Controller. Hence this is done in {@link
   * AbstractController#initialize()}.
   */
  private void setCommsNumberAttributeOnControl(AbstractController instance)
  {
    Map<String, String> mapping = new HashMap<>();

    for (Field field : instance.getClass().getDeclaredFields())
    {
      if (ButtonBase.class.isAssignableFrom(field.getType()) && field.isAnnotationPresent(FXML.class))
      {
        CommsNumber annotation = field.getAnnotation(CommsNumber.class);
        if (annotation != null)
        {
          mapping.put(field.getName(), annotation.value());
        }
        else
        {
          /*
           * Tracer.getInstance().error("WARNING: '" + field.getName() + "' in "
           * + instance.getClass().getSimpleName() //$NON-NLS-1$ //$NON-NLS-2$ +
           * " missing @CommsNumber annotation"); //$NON-NLS-1$
           */ }
      }
    }
    instance.setFxControlToCommsMapping(mapping);
  }

  public void setIsTenCar(boolean isTenCar)
  {
    this.isTenCar = isTenCar;
  }

}

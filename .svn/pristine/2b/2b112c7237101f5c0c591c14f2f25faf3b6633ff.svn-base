/*
 * ==================================================================
 * 
 * (C) Copyright 2020 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.psd.fe.gui;

import java.util.ArrayList;
import java.util.concurrent.TimeUnit;

import com.sydac.foundation.IPropertySetter;
import com.sydac.foundation.PropertyKey;
import com.sydac.mmrbem.cabscreens.fe.gui.AbstractController;
import com.sydac.mmrbem.psd.fe.base.AbstractCommsListener;
import com.sydac.mmrbem.psd.fe.base.PSDFactory;

import javafx.fxml.FXML;

/**
 * Abstract class for all FXML Controller classes in the TMS application.
 * 
 */
public abstract class AbstractPSDController extends AbstractController
{
  private static final int RESET_VALUE = 0;

  protected ArrayList<AbstractCommsListener> psdScreenBinders = new ArrayList<>();

  protected IPropertySetter appInputsSetter;

  /**
   * Method that is called by the FMXL Loader during initialization of the FXML.
   */
  @FXML
  @Override
  public final void initialize()
  {
    /* Assign COMMS number to any @CommsNumber annotated JavaFx Controls */
    assignCommsNumberToFxControl();

    /* Initialize the controller */
    initializeImpl();

    psdScreenBinders.forEach(b -> b.attachToModel(PSDFactory.getCommsBinding(scenarioCarIndex)));

    appInputsSetter = PSDFactory.getCommsBinding(scenarioCarIndex).getHubInputsValuesSetter();
  }

  protected void sendButtonRequest(final PropertyKey<Integer> propKey, int value)
  {
    appInputsSetter.setProperty(propKey, value);
    AbstractCommsListener.EXECUTOR.schedule(() -> appInputsSetter.setProperty(propKey, RESET_VALUE), 100,
        TimeUnit.MILLISECONDS);
  }

  @Override
  public void removeListeners()
  {
    psdScreenBinders.forEach(AbstractCommsListener::detachFromModel);
    detachListeners();
  }

  public abstract void detachListeners();
}
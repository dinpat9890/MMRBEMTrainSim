/*
 * ==================================================================
 * 
 * (C) Copyright 2016 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.cabscreens.fe.base.impl;

import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;
import java.util.function.Consumer;

import com.sydac.common.febe.SimplePropertySetter;
import com.sydac.core.runtimedata.HubIO;
import com.sydac.mmrbem.cabscreens.fe.base.ComponentManager;
import com.sydac.simcomms.CNumber;
import com.sydac.simcomms.CObject;
import com.sydac.simcomms.FacultyNumber;
import com.sydac.simcomms.PropertyCallbackBinder;
import com.sydac.simcomms.framework.GatewayProvider;

import javafx.application.Platform;

/**
 * The {@link ComponentManager} implementation that will be used to connect to
 * COMMS<br>
 * <br>
 * - All setNumbers will be done to HubInputsValues<br>
 * - All callbacks will be listening to HubInputs<br>
 * 
 * @author joshian
 *
 */
@SuppressWarnings("deprecation")
public class ComponentManagerImpl implements ComponentManager
{
  private static final double DEFAULT_FREQUENCY = 20;

  private CObject hubInputObject;

  private CObject hubValuesObject;

  @SuppressWarnings("deprecation")
  private SimplePropertySetter propertySetter;

  private PropertyCallbackBinder binder;

  private final Map<String, Set<Consumer<Double>>> callbackMap = Collections.synchronizedMap(new HashMap<>());

  @Override
  public void setHubInputObject(CObject hubInputObject)
  {
    this.hubInputObject = hubInputObject;
    bindToInputNumbers();
  }

  @SuppressWarnings("deprecation")
  @Override
  public void setHubValuesObject(CObject hubValuesObject, GatewayProvider gatewayProvider)
  {
    this.hubValuesObject = hubValuesObject;
    this.propertySetter = new SimplePropertySetter(gatewayProvider.getGateway(), this.hubValuesObject);
  }

  @SuppressWarnings("deprecation")
  @Override
  public void setNumber(String commsNumber, double value)
  {
    propertySetter.setNumber(HubIO.createIOPropertyName(commsNumber), value);
  }

  @Override
  public void register(String commsNumber, Consumer<Double> consumer)
  {
    String ioPropertyName = HubIO.createIOPropertyName(commsNumber);
    if (!callbackMap.containsKey(ioPropertyName))
    {
      callbackMap.put(ioPropertyName, new HashSet<>());
    }
    callbackMap.get(ioPropertyName).add(consumer);
  }

  /*
   * Bind on to all the numbers in HubInputs
   */
  private void bindToInputNumbers()
  {
    /* Create a PropertyCallbackBinder for HubInputs */
    this.binder = new PropertyCallbackBinder(this.hubInputObject);

    /*
     * Register internal callback on all the number in HubOutputs COMMS object
     */
    FacultyNumber numbers = this.hubInputObject.getNumbers();
    for (CNumber number : numbers.getStore())
    {
      String propertyName = numbers.getInfo().getInfo(number.getId()).getName();
      this.binder.registerCallback(propertyName,
          (CNumber aNum) -> notifyListener(propertyName, aNum.getValue()));
    }

    /* Bind the PropertyCallbackBinder with a default frequency */
    binder.bind(DEFAULT_FREQUENCY, true);
  }

  /*
   * Notify registered clients, if any, on the data change
   */
  private final void notifyListener(String propertyName, double value)
  {
    /*
     * Notification back to the client is done of the JavaFx-Application-Thread
     */
    if (callbackMap.containsKey(propertyName))
    {
      Platform.runLater(() -> {
        for (Consumer<Double> consumer : callbackMap.get(propertyName))
        {
          consumer.accept(value);
        }
      });
    }
  }
}

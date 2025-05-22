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

import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;

import com.sydac.common.febe.CommsUtils;
import com.sydac.core.runtimedata.HubIO;
import com.sydac.mmrbem.cabscreens.fe.base.IFrontendDataModel;
import com.sydac.simcomms.CNumber;
import com.sydac.simcomms.CObject;
import com.sydac.simcomms.CRaw;
import com.sydac.simcomms.FacultyNumber;
import com.sydac.simcomms.FacultyRaw;
import com.sydac.simcomms.PropertyCallbackBinder;
import com.sydac.simcomms.framework.GatewayProvider;

import javafx.application.Platform;

/**
 * Concrete implementation of {@link IFrontendDataModel} that interacts with the
 * HubOutputs in COMMS. Receives data updates from COMMS and notifies any
 * registered callbacks.
 * <p>
 * This implementation allows clients to register callbacks even before the
 * HubOutputs object is ready in COMMS (if required). Once the HubOutput becomes
 * ready, all the callbacks that have already been registered will still be
 * valid.
 *
 * @author joshian
 */
public class FrontendDataModelImpl implements IFrontendDataModel
{

  CObject hubOutput;

  GatewayProvider gatewayProvider;

  Binder binder = new CachedBinder();
  
  private static final double ZERO = 0.0d;

  @Override
  public void setHubOutputObject(CObject hubOutputObject, GatewayProvider gatewayProvider)
  {
    this.hubOutput = hubOutputObject;
    this.gatewayProvider = gatewayProvider;

    Binder oldBinder = this.binder;
    binder = new DataSourceBinder();
    oldBinder.release();
  }

  @Override
  public void bindIOData(String attribute, Consumer callback)
  {
    binder.bindIOData(attribute, callback);
  }

  @Override
  public void bindIORawData(String attribute, Consumer callback)
  {
    binder.bindIORawData(attribute, callback);
  }

  @Override
  public double getIOData(String attribute)
  {
    return binder.getIOData(attribute);
  }

  @Override
  public byte[] getIORawData(String attribute)
  {
    return binder.getIORawData(attribute);
  }

  @Override
  public boolean getIODataAsBoolean(String attribute)
  {
    return binder.getIODataAsBoolean(attribute);
  }

  /**
   * Binder interface to switch between registration before and after HubObjects
   * creation
   *
   * @author Nazim Oliyath
   */
  interface Binder
  {
    /**
     * Delegate for {@link IFrontendDataModel#bindIOData(String, Consumer)}
     *
     * @param attribute
     * @param callback
     */
    void bindIOData(String attribute, Consumer callback);

    /**
     * Delegate for {@link IFrontendDataModel#bindIORawData(String, Consumer)}
     *
     * @param attribute
     * @param callback
     */
    void bindIORawData(String attribute, Consumer callback);

    /**
     * Delegate for {@link IFrontendDataModel#getIOData(String)}
     *
     * @param attribute
     * @return double - default implementation returns value 0
     */
    default double getIOData(String attribute)
    {
      return ZERO;
    }

    /**
     * Delegate for {@link IFrontendDataModel#getIORawData(String)}
     *
     * @param attribute
     * @return byte[] - default implementation returns blank byte array
     */
    default byte[] getIORawData(String attribute)
    {
      return new byte[] {};
    }

    /**
     * Notifies the binder that this object has been released and will not be
     * used any more.
     */
    default void release()
    {
      /* do nothing */
    }

    /**
     * @param attribute
     * @return value as boolean
     */
    default boolean getIODataAsBoolean(String attribute)
    {
      return false;
    }
  }

  /**
   * {@link Binder} implementation that keeps track of any callbacks that are
   * registered before the HubOutputs COMMS object is ready.
   * <p>
   * On {@link Binder#release()}, this implementation binds all its registered
   * callbacks with the new binder.
   *
   * @author Nazim Oliyath
   */
  private final class CachedBinder implements Binder
  {
    Map<String, List<Consumer>> tempIOCallbackMap = new HashMap<>();

    Map<String, List<Consumer>> tempRawCallbackMap = new HashMap<>();

    @Override
    public void bindIOData(String attribute, Consumer callback)
    {
      if (!tempIOCallbackMap.containsKey(attribute))
      {
        tempIOCallbackMap.put(attribute, new ArrayList<>());
      }
      tempIOCallbackMap.get(attribute).add(callback);
    }

    @Override
    public void bindIORawData(String attribute, Consumer callback)
    {
      if (!tempRawCallbackMap.containsKey(attribute))
      {
        tempRawCallbackMap.put(attribute, new ArrayList<>());
      }
      tempRawCallbackMap.get(attribute).add(callback);
    }

    @Override
    public void release()
    {
      for (Entry<String, List<Consumer>> tmpIOCallback : tempIOCallbackMap.entrySet())
      {
        for (Consumer consumer : tmpIOCallback.getValue())
        {
          FrontendDataModelImpl.this.bindIOData(tmpIOCallback.getKey(), consumer);
        }
      }
      for (Entry<String, List<Consumer>> tmpIOCallback : tempRawCallbackMap.entrySet())
      {
        for (Consumer consumer : tmpIOCallback.getValue())
        {
          FrontendDataModelImpl.this.bindIOData(tmpIOCallback.getKey(), consumer);
        }
      }
    }
  }

  /**
   * {@link Binder} implementation that interacts with HubOutputs COMMS object
   * to be notified of changes via COMMS layer.
   *
   * @author Nazim Oliyath
   */
  private final class DataSourceBinder implements Binder
  {
    private static final double DEFAULT_FREQUENCY = 50;

    PropertyCallbackBinder binder;

    private final Map<String, List<Consumer>> callbackMap = Collections
        .synchronizedMap(new HashMap<String, List<Consumer>>());

    DataSourceBinder()
    {
      assert FrontendDataModelImpl.this.hubOutput != null : "HubOutputs not assigned !!"; //$NON-NLS-1$

      /* Create a PropertyCallbackBinder for HubObjects */
      this.binder = new PropertyCallbackBinder(FrontendDataModelImpl.this.hubOutput);

      /*
       * Register internal callback on all the number in HubOutputs COMMS object
       */
      FacultyNumber numbers = hubOutput.getNumbers();
      for (CNumber number : numbers.getStore())
      {
        String propertyName = numbers.getInfo().getInfo(number.getId()).getName();
        this.binder.registerCallback(propertyName, (CNumber aNum) ->

        notifyListener(propertyName));
      }

      /*
       * Register internal callback on all the raws in HubOutputs COMMS object
       */
      FacultyRaw raws = hubOutput.getRaws();
      for (CRaw raw : raws.getStore())
      {
        String propertyName = raws.getInfo().getInfo(raw.getId()).getName();
        this.binder.registerCallback(propertyName, (CRaw aRaw) -> notifyListener(propertyName));
      }

      /* Bind the PropertyCallbackBinder with a default frequency */
      binder.bind(DEFAULT_FREQUENCY, true);
    }

    /*
     * Notify registered clients, if any, on the data change
     */
    private final void notifyListener(String propertyName)
    {
      /*
       * Notification back to the client is done of the
       * JavaFx-Application-Thread
       */
      Platform.runLater(() -> {
        if (callbackMap.containsKey(propertyName))
        {
          Consumer[] consumers = callbackMap.get(propertyName).toArray(new Consumer[] {});
          for (Consumer consumer : consumers)
          {
            consumer.dataUpdated();
          }
        }
      });
    }

    @Override
    public void bindIOData(String attribute, Consumer callback)
    {
      registerBinding(attribute, callback);
    }

    @Override
    public void bindIORawData(String attribute, Consumer callback)
    {
      registerBinding(attribute, callback);
    }

    /*
     * Adds the binding for the attribute to the consumer callback.
     */
    private void registerBinding(String attribute, Consumer callback)
    {
      String ioPropertyName = HubIO.createIOPropertyName(attribute);
      if (!callbackMap.containsKey(ioPropertyName))
      {
        callbackMap.put(ioPropertyName, new ArrayList<>());
      }
      callbackMap.get(ioPropertyName).add(callback);
    }

    @Override
    public byte[] getIORawData(String attribute)
    {
      byte[] result = new byte[] {};
      if (gatewayProvider.hasGateway())
      {
        gatewayProvider.getGateway().lock();
        try
        {
          result = CommsUtils.getRawValue(FrontendDataModelImpl.this.hubOutput,
              HubIO.createIOPropertyName(attribute));
        }
        finally
        {
          gatewayProvider.getGateway().unlock();
        }

      }
      return result;
    }

    @Override
    public double getIOData(String attribute)
    {
      double result = 0.0;
      if (gatewayProvider.hasGateway())
      {
        gatewayProvider.getGateway().lock();
        try
        {
          result = CommsUtils.getNumberValue(FrontendDataModelImpl.this.hubOutput,
              HubIO.createIOPropertyName(attribute));
        }
        finally
        {
          gatewayProvider.getGateway().unlock();
        }
      }
      return result;
    }

    @Override
    public boolean getIODataAsBoolean(String attribute)
    {
      boolean result = false;
      if (gatewayProvider.hasGateway())
      {
        gatewayProvider.getGateway().lock();
        try
        {
          result = CommsUtils.getNumberBooleanValue(FrontendDataModelImpl.this.hubOutput,
              HubIO.createIOPropertyName(attribute));
        }
        finally
        {
          gatewayProvider.getGateway().unlock();
        }
      }
      return result;
    }
  }
}

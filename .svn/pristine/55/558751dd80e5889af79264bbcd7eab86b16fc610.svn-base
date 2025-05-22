/*
 * ==================================================================
 * 
 * (C) Copyright 2016 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.psd.fe.base;

import java.util.Collections;
import java.util.HashMap;
import java.util.Map;
import java.util.Observable;
import java.util.Observer;

import com.sydac.common.log.Tracer;
import com.sydac.mmrbem.cabscreens.fe.base.HubObjectProvider;
import com.sydac.mmrbem.psd.fe.comms.CommsBinding;

/**
 * TMSFactory provides implementation instances of
 * <ul>
 * <li>{@link ServiceRequestHandler}
 * </ul>
 * for the requested car index. <br>
 * <br>
 * Only cars registered using
 * {@link PSDFactory#register(int, HubObjectProvider)} will be addressed by the
 * TMSFactory.
 * 
 * @author Nazim Oliyath
 * 
 */
public final class PSDFactory
{
  private static final Map<Integer, ServiceRequestHandler> serviceRequestHandlerIndex = Collections
      .synchronizedMap(new HashMap<>());

  private static final Map<Integer, CommsBinding> commsBindingIndex = Collections
      .synchronizedMap(new HashMap<>());

  private static final String FRONTEND_SERVICE_HANDLER_IMPL_KEY = "frontend.service.handler.impl"; //$NON-NLS-1$

  private static final String SERVICE_HANDLER_IMPL = System.getProperty(FRONTEND_SERVICE_HANDLER_IMPL_KEY,
      "com.sydac.mmrbem.psd.fe.base.impl.ServiceRequestHandlerImpl"); //$NON-NLS-1$

  private PSDFactory()
  {

  }

  /**
   * Registers Hub Object with TMSFactory<br>
   * Once the hub object elements are created they are injected into the
   * elements supplied by this factory.
   * 
   * @param carIndex
   *          carIndex
   * @param hubObjectProvider
   *          hubObjectProvider
   */
  public static final void register(final int carIndex, HubObjectProvider hubObjectProvider)
  {
    hubObjectProvider.addObserver(new FactoryObserver(carIndex, hubObjectProvider));
  }

  /**
   * Provides the {@link ServiceRequestHandler} instance attached to the HUB
   * object for the incoming carIndex
   * 
   * @param carIndex
   *          carIndex
   * @return {@link ServiceRequestHandler} if
   *         {@link PSDFactory#register(int, HubObjectProvider)}-ed for this
   *         carIndex<br>
   *         null otherwise
   */
  public static final ServiceRequestHandler getServiceRequestHandler(int carIndex)
  {
    return serviceRequestHandlerIndex.get(carIndex);
  }

  public static final void register(final int carIndex, CommsBinding commsBinding)
  {
    commsBindingIndex.put(carIndex, commsBinding);
  }

  public static final CommsBinding getCommsBinding(int carIndex)
  {
    return commsBindingIndex.get(carIndex);
  }

  public static final Map<Integer, CommsBinding> getCommsBinding()
  {
    return commsBindingIndex;
  }

  /**
   * Should be called during session termination
   */
  public static final void flush()
  {
    serviceRequestHandlerIndex.clear();
    commsBindingIndex.clear();
  }

  private static final class FactoryObserver implements Observer
  {
    private final HubObjectProvider hubObjectProvider;

    private final ServiceRequestHandler serviceRequestHandlerInstance;

    private FactoryObserver(int carIndex, HubObjectProvider hubObjectProvider)
    {
      this.hubObjectProvider = hubObjectProvider;
      serviceRequestHandlerInstance = serviceRequestHandlerInstance(carIndex);
    }

    @Override
    public void update(Observable o, Object arg)
    {
      if (HubObjectProvider.HUB_VALUES_CHANGED.equals(arg.toString()))
      {
        serviceRequestHandlerInstance.setHubValuesObject(hubObjectProvider.getHubValues(),
            hubObjectProvider.getGatewayProvider());
      }
    }

    /*
     * Provides instance of ServiceRequestHandler if it already exists, else
     * creates a new instance and returns it.
     * 
     * @param carIndex
     * 
     * @return FrontendDataModel
     */
    private static ServiceRequestHandler serviceRequestHandlerInstance(final int carIndex)
    {
      if (!serviceRequestHandlerIndex.containsKey(carIndex))
      {
        try
        {
          serviceRequestHandlerIndex.put(carIndex,
              (ServiceRequestHandler)Class.forName(SERVICE_HANDLER_IMPL).newInstance());
        }
        catch (InstantiationException | IllegalAccessException | ClassNotFoundException e)
        {
          Tracer.getInstance().error(e);
        }
      }
      return serviceRequestHandlerIndex.get(carIndex);
    }
  }

}

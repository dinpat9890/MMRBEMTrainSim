/*
 * ==================================================================
 * 
 * (C) Copyright 2016 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.cabscreens.fe.base;

import java.util.Collections;
import java.util.HashMap;
import java.util.Map;
import java.util.Observable;
import java.util.Observer;

import com.sydac.common.log.Tracer;

/**
 * ApplicationFactory provides implementation instances of
 * <ul>
 * <li>{@link ComponentManager}
 * <li>{@link IFrontendDataModel}
 * </ul>
 * for the requested car index. <br>
 * <br>
 * Only cars registered using
 * {@link ApplicationFactory#register(int, HubObjectProvider)} will be addressed by
 * the ApplicationFactory.
 * 
 * @author Nazim Oliyath
 * 
 */
public final class ApplicationFactory
{
  private static final String FRONTEND_DATAMODEL_IMPL_KEY = "frontend.datamodel.impl"; //$NON-NLS-1$

  private static final String FRONTEND_COMPONENT_MANAGER_IMPL_KEY = "frontend.component.manager.impl"; //$NON-NLS-1$

  public static final String SCENARIO_CAR_INDEX = "frontend.scenario.car.index"; //$NON-NLS-1$

  private static final Map<Integer, ComponentManager> componentManagerIndex = Collections.synchronizedMap(new HashMap<>());

  private static final Map<Integer, IFrontendDataModel> frontendDataModelIndex = Collections.synchronizedMap(new HashMap<>());

  private static final String COMPONENT_MANAGER_IMPL = System.getProperty(FRONTEND_COMPONENT_MANAGER_IMPL_KEY, "com.sydac.mmrbem.cabscreens.fe.base.impl.ComponentManagerImpl"); //$NON-NLS-1$

  private static final String DATA_MODEL_IMPL = System.getProperty(FRONTEND_DATAMODEL_IMPL_KEY, "com.sydac.mmrbem.cabscreens.fe.base.impl.FrontendDataModelImpl"); //$NON-NLS-1$

  private ApplicationFactory()
  {
    // do nothing
  }
  /**
   * Registers Hub Object with TMSFactory<br>
   * Once the hub object elements are created they are injected into the
   * elements supplied by this factory.
   * 
   * @param carIndex carIndex
   * @param hubObjectProvider hubObjectProvider
   */
  public static final void register(final int carIndex, HubObjectProvider hubObjectProvider)
  {
    hubObjectProvider.addObserver(new FactoryObserver(carIndex, hubObjectProvider));
  }

  /**
   * Provides the {@link ComponentManager} instance attached to the HUB object
   * for the incoming carIndex
   * 
   * @param carIndex carIndex
   * @return {@link ComponentManager} if
   *         {@link ApplicationFactory#register(int, HubObjectProvider)}-ed for this
   *         carIndex<br>
   *         null otherwise
   */
  public static final ComponentManager getComponentManager(int carIndex)
  {
    return componentManagerIndex.get(carIndex);
  }

  /**
   * Provides the {@link IFrontendDataModel} instance attached to the HUB object
   * for the incoming carIndex
   * 
   * @param carIndex carIndex
   * @return {@link IFrontendDataModel} if
   *         {@link ApplicationFactory#register(int, HubObjectProvider)}-ed for this
   *         carIndex<br>
   *         null otherwise
   */
  public static final IFrontendDataModel getFrontendDataModel(int carIndex)
  {
    return frontendDataModelIndex.get(carIndex);
  }
  
  /**
   * Should be called during session termination
   */
  public static final void flush()
  {
    componentManagerIndex.clear();
    frontendDataModelIndex.clear();
  }
  
  private static final class FactoryObserver implements Observer
  {
    private final HubObjectProvider hubObjectProvider;

    private final ComponentManager componentManagerInstance;

    private final IFrontendDataModel frontendDataModelInstance;

    private FactoryObserver(int carIndex, HubObjectProvider hubObjectProvider)
    {
      this.hubObjectProvider = hubObjectProvider;
      componentManagerInstance = componentManagerInstance(carIndex);
      frontendDataModelInstance = frontendDataModelInstance(carIndex);
    }

    @Override
    public void update(Observable o, Object arg)
    {
      if (HubObjectProvider.HUB_INPUT_CHANGED.equals(arg.toString()))
      {
        componentManagerInstance.setHubInputObject(hubObjectProvider.getHubInput());
      }
      else if (HubObjectProvider.HUB_OUTPUT_CHANGED.equals(arg.toString()))
      {
        frontendDataModelInstance.setHubOutputObject(hubObjectProvider.getHubOutput(),
            hubObjectProvider.getGatewayProvider());
      }
      else if (HubObjectProvider.HUB_VALUES_CHANGED.equals(arg.toString()))
      {
        componentManagerInstance.setHubValuesObject(hubObjectProvider.getHubValues(),
            hubObjectProvider.getGatewayProvider());
      }
    }

    /*
     * Provides instance of ComponentManager if it already exists, else creates
     * a new instance and returns it.
     * 
     * @param carIndex
     * 
     * @return ComponentManager
     */
    private static ComponentManager componentManagerInstance(final int carIndex)
    {
      if (!componentManagerIndex.containsKey(carIndex))
      {
        try
        {
          componentManagerIndex.put(carIndex,
              (ComponentManager)Class.forName(COMPONENT_MANAGER_IMPL).newInstance());
        }
        catch (InstantiationException | IllegalAccessException | ClassNotFoundException e)
        {
          Tracer.getInstance().error(e);
        }
      }
      return componentManagerIndex.get(carIndex);
    }

    /*
     * Provides instance of FrontendDataModel if it already exists, else creates
     * a new instance and returns it.
     * 
     * @param carIndex
     * 
     * @return FrontendDataModel
     */
    private static IFrontendDataModel frontendDataModelInstance(final int carIndex)
    {
      if (!frontendDataModelIndex.containsKey(carIndex))
      {
        try
        {
          frontendDataModelIndex.put(carIndex,
              (IFrontendDataModel)Class.forName(DATA_MODEL_IMPL).newInstance());
        }
        catch (InstantiationException | IllegalAccessException | ClassNotFoundException e)
        {
          Tracer.getInstance().error(e);
        }
      }
      return frontendDataModelIndex.get(carIndex);
    }

  }

}

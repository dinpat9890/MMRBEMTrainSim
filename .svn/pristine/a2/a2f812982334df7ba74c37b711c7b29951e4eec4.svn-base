package com.sydac.mmrbem.tcms.backend.test.utils;

import java.util.Map;
import java.util.concurrent.ConcurrentHashMap;

import com.sydac.common.dataobjects.DBScenarioTrain;
import com.sydac.common.febe.binding.FeBeOutputHandlerFactory;
import com.sydac.common.febe.binding.FeBePropertyModelFactory;
import com.sydac.common.febe.binding.FeBePropertyModelFactory.FeBePropertyModelWrapper;
import com.sydac.foundation.IPropertyModel;
import com.sydac.foundation.IPropertySetter;
import com.sydac.mmrbem.tcms.backend.comms.CommsBinding;
import com.sydac.mmrbem.tcms.common.IEmptyHandler;
import com.sydac.mmrbem.tcms.common.io.properties.IAppInputsProperties;
import com.sydac.mmrbem.tcms.common.io.properties.IAppOutputsProperties;
import com.sydac.simcomms.CObject;
import com.sydac.simcomms.Gateway;

public class TestCommsBinding extends CommsBinding
{
  @SuppressWarnings("unused")
  private Gateway gateway;

  /** The vehicle index. */
  @SuppressWarnings("unused")
  private final int vehicleIndex;

  @SuppressWarnings("unused")
  private DBScenarioTrain train;

  private final Map<Integer, IPropertyModel> vehicleOutputsModels = new ConcurrentHashMap<Integer, IPropertyModel>();

  /** The application outputs setter. */
  private IPropertySetter appOutputsSetter;

  /** The application outputs setter. */
  private IPropertyModel appOutputsModel;

  /** The application inputs model */
  private IPropertyModel appInputsModel;

  private IPropertySetter appInputsSetter;

  public TestCommsBinding(Gateway aGateway, DBScenarioTrain aTrain, int aVehicleIndex)
  {
    super.initialize(aGateway, aTrain, aVehicleIndex);
    gateway = aGateway;
    train = aTrain;
    vehicleIndex = aVehicleIndex;
  }

  public void createVehicleIoObjectsList(CObject cObject)
  {
    // Created initially for 8 car only
    for (int i = 0; i < 8; i++)
    {
      onVehicleOutputsObjectCreation(cObject, i);
    }
  }

  @Override
  public void onApplicationOutputsObjectCreation(CObject aApplicationOutputsObject)
  {}

  @Override
  public void onVehicleOutputsObjectCreation(CObject cObject, int aVehicleIndex)
  {}

  @Override
  public void onApplicationInputsObjectCreation(CObject cObject)
  {}

  @Override
  public IPropertySetter getAppOutputsSetter()
  {
    return appOutputsSetter;
  }

  public IPropertyModel getAppOutputsModel()
  {
    return appOutputsModel;
  }

  @Override
  public IPropertyModel getAppInputsModel()
  {
    return appInputsModel;
  }

  public IPropertySetter getAppInputsSetter()
  {
    return appInputsSetter;
  }

}

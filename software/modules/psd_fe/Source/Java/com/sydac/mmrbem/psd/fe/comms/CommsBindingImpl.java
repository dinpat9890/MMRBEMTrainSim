/*
 * =======================================================================
 * 
 * (C) Copyright 2020 Oktal Sydac. all rights reserved. This is unpublished
 * proprietary source code. The copyright notice above does not evidence any
 * actual or intended publication of such source code.
 * 
 * =======================================================================
 */
package com.sydac.mmrbem.psd.fe.comms;

import java.util.function.Consumer;

import com.sydac.common.febe.binding.CommsInputBindingBuilder;
import com.sydac.common.febe.binding.CommsOutputBindingBuilder;
import com.sydac.common.febe.binding.FeBeOutputHandlerFactory;
import com.sydac.common.febe.binding.FeBePropertyModelFactory;
import com.sydac.common.febe.binding.FeBePropertyModelFactory.FeBePropertyModelWrapper;
import com.sydac.mmrbem.psd.common.IEmptyHandler;
import com.sydac.mmrbem.psd.common.io.properties.IAppInputsProperties;
import com.sydac.mmrbem.psd.common.io.properties.IAppOutputsProperties;
import com.sydac.mmrbem.psd.fe.app.io.model.IAppInputsHandler;
import com.sydac.mmrbem.psd.fe.app.io.model.IAppOutputsModel;
import com.sydac.simcomms.CObject;
import com.sydac.simcomms.Gateway;
import com.sydac.simcomms.PropertyCallbackBinder;

import javafx.application.Platform;

public class CommsBindingImpl extends CommsBinding
{
  private static final Consumer<Runnable> JFX_RUNNER = r -> {
    if (Platform.isFxApplicationThread())
    {
      r.run();
    }
    else
    {
      Platform.runLater(r);
    }
  };

  public CommsBindingImpl(Gateway aGateway, int aVehicleIndex)
  {
    super(aGateway, aVehicleIndex);
  }

  /**
   * Binds to Hub Inputs properties, {@code IPropertyModel} will be populated
   * with updated value.
   */
  @Override
  public void onHubOutputCreation(CObject hubOutputsObject)
  {
    FeBePropertyModelWrapper<IEmptyHandler, IAppOutputsModel> hubOutputsModelWrapper = FeBePropertyModelFactory
        .createWithInterfaces(IAppOutputsProperties.class, IEmptyHandler.class, IAppOutputsModel.class);

    hubOutputsModel = hubOutputsModelWrapper.asManageableModel();
    hubOutputsModel.create();

    CommsInputBindingBuilder commsInputBindingBuilder = new CommsInputBindingBuilder(hubOutputsObject,
        IAppOutputsProperties.class, hubOutputsModelWrapper.asHandler());
    commsInputBindingBuilder.setRunner(JFX_RUNNER);
    commsInputBindingBuilder.setRawConverter(byte[].class, r -> r.getValue()).build();

    PropertyCallbackBinder propertyBinder = commsInputBindingBuilder.forIODataBinding().build();
    propertyBinder.bind(DEFAULT_FREQUENCY, true);
  }

  /**
   * Creates an {@code IPropertySetter} which can be used to set properties in
   * Hub Values properties.
   */
  @Override
  public void onHubValuesCreation(CObject hubInputsValuesObject)
  {
    hubInputsValuesSetter = FeBeOutputHandlerFactory.createWithInterfaces(
        new CommsOutputBindingBuilder(gateway, hubInputsValuesObject, IAppInputsProperties.class)
            .forIODataBinding().build(),
        IAppInputsProperties.class, IAppInputsHandler.class);
  }
}

/*
 * ==================================================================
 *
 * (C) Copyright 2020 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *
 * ==================================================================
 */

package com.sydac.mmrbem.radio.backend.app;

import org.springframework.context.annotation.AnnotationConfigApplicationContext;

import com.sydac.common.dataobjects.DBScenarioTrain;
import com.sydac.simcomms.Gateway;

public class ApplicationContext
{
  private RadioVehicleBackend vehicleRadio;

  private Gateway gateway;

  private DBScenarioTrain aTrain;

  private AnnotationConfigApplicationContext context;

  public ApplicationContext()
  {
    super();
  }

  public void setVehicleTCMS(AnnotationConfigApplicationContext context)
  {
	  vehicleRadio = (RadioVehicleBackend)context.getBean("vehicleRadio");
	  vehicleRadio.initialize(this.gateway, this.aTrain);
  }

  public void loadContext(Gateway gateway, DBScenarioTrain aTrain, int aCarIndex,
		  RadioBackendModule tmsBackendModule)
  {
    this.gateway = gateway;
    this.aTrain = aTrain;
    context = new AnnotationConfigApplicationContext();
    AppConfig config = new AppConfig();
    config.setCarIndex(aCarIndex);
    config.setScenarioTrainId(aTrain.getScenarioTrainId());
    config.setBackendModule(tmsBackendModule);
    config.initialize(context);

    context.register(AppConfig.class);
    setPackageToScan(context);
    context.refresh();

    setVehicleTCMS(context);
  }

  public void setPackageToScan(AnnotationConfigApplicationContext context)
  {
    context.scan("com.sydac.mmrbem.radio.backend.comms");
    context.scan("com.sydac.mmrbem.radio.backend.io");
    context.scan("com.sydac.mmrbem.radio.backend.logic");
    context.scan("com.sydac.mmrbem.radio.backend.logic.handler");
  }

  protected RadioVehicleBackend getVehicleTCMS()
  {
    return vehicleRadio;
  }

  protected AnnotationConfigApplicationContext getAnnotationConfigApplicationContext()
  {
    return context;
  }
}
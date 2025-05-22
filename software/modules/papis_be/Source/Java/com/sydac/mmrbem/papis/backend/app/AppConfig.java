package com.sydac.mmrbem.papis.backend.app;

import java.util.HashMap;
import java.util.Map;

import org.springframework.beans.factory.config.ConfigurableListableBeanFactory;
import org.springframework.context.ApplicationContextInitializer;
import org.springframework.context.ConfigurableApplicationContext;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import org.springframework.core.env.ConfigurableEnvironment;
import org.springframework.core.env.MapPropertySource;
import org.springframework.core.env.MutablePropertySources;

import com.sydac.peer.application.PeerApplication;

@Configuration
public class AppConfig implements ApplicationContextInitializer<ConfigurableApplicationContext>
{
  private PeerApplication baseApplication;

  private int carIndex;

  private int scenarioTrainId;

  public AppConfig()
  {
    super();
  }

  @Bean("vehiclePAPIS")
  public PAPISVehicleBackend getTCMSVehicleBackend()
  {
    return new PAPISVehicleBackend();
  }

  public void setCarIndex(int aCarIndex)
  {
    this.carIndex = aCarIndex;
  }

  public void setScenarioTrainId(int scenarioTrainId)
  {
    this.scenarioTrainId = scenarioTrainId;
  }

  protected void setBackendModule(PeerApplication backendModule)
  {
    this.baseApplication = backendModule;
  }

  @Override
  public void initialize(ConfigurableApplicationContext configurableEnvironment)
  {
    ConfigurableEnvironment environment = configurableEnvironment.getEnvironment();
    Map<String, Object> props = new HashMap<>();
    props.put("carIndex", carIndex);
    props.put("scenarioTrainId", scenarioTrainId);
    MutablePropertySources sources = environment.getPropertySources();
    sources.addFirst(new MapPropertySource("sydac", props));

    ConfigurableListableBeanFactory factory = configurableEnvironment.getBeanFactory();
    factory.registerSingleton("baseApplication", baseApplication);
  }

}
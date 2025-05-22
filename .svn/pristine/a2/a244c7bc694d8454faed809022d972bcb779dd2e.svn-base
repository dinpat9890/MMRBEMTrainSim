/*
 * ==================================================================
 * 
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.radio.backend.logic.handler;

import java.util.ArrayList;
import java.util.Date;
import java.util.List;
import java.util.stream.Collectors;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import com.sydac.common.registry.Registry;
import com.sydac.foundation.IPropertySetter;
import com.sydac.foundation.PropertyKey;
import com.sydac.mmrbem.radio.backend.comms.CommsBinding;
import com.sydac.mmrbem.radio.backend.logic.AbstractFunctionalLogic;
import com.sydac.mmrbem.radio.backend.logic.DateTimeModel;
import com.sydac.mmrbem.radio.backend.logic.SharedDataModel;
import com.sydac.mmrbem.radio.backend.logic.annotation.FunctionalLogicHandler;
import com.sydac.mmrbem.radio.backend.radiointercom.properties.IRadioIntercomInputProperties;
import com.sydac.mmrbem.radio.backend.vehicle.io.models.IPAPISVehicleOutputsModel;
import com.sydac.mmrbem.radio.backend.vehicle.io.models.properties.IPAPISVehicleOutputsProperties;
import com.sydac.mmrbem.radio.backend.vehicle.io.models.properties.ITCMSVehicleOutputsProperties;
import com.sydac.mmrbem.radio.common.ScreenId;
import com.sydac.mmrbem.radio.common.data.MessageDO;
import com.sydac.mmrbem.radio.common.io.RadioPropertiesReader;
import com.sydac.mmrbem.radio.common.io.properties.IAppInputsPowerMenuNavPanelProperties;
import com.sydac.mmrbem.radio.common.io.properties.IAppOutputCabSignalProperties;
import com.sydac.mmrbem.radio.common.io.properties.IAppOutputsHeaderProperties;
import com.sydac.mmrbem.radio.common.state.ApplicationConstants;

/**
 * This handler class is used for startup screen sequence logic
 * 
 * @author mulukg
 *
 */
@Service
@FunctionalLogicHandler(arguments = { CommsBinding.class, SharedDataModel.class })
public class StartupSequenceHandler extends AbstractFunctionalLogic
{

  private static final Registry INSTANCE = Registry.getInstance();

  private static final int STARTUP_SCREEN1_TIME = INSTANCE.getInteger(ApplicationConstants.DOMAIN_NAME,
      ApplicationConstants.STARTUP_SCREEN1_KEY);

  private static final int STARTUP_SCREEN2_TIME = INSTANCE.getInteger(ApplicationConstants.DOMAIN_NAME,
      ApplicationConstants.STARTUP_SCREEN2_KEY);

  private static final int STARTUP_SCREEN3_TIME = INSTANCE.getInteger(ApplicationConstants.DOMAIN_NAME,
      ApplicationConstants.STARTUP_SCREEN3_KEY);

  private static final String LINE_NAME = INSTANCE.getString(ApplicationConstants.DOMAIN_NAME,
      ApplicationConstants.LINE_NAME);

  private CommsBinding commsBinding;

  private List<MessageDO> messageList = new ArrayList<>();

  @Autowired
  private ScreenChangeHandler screenChangeHandler;

  @Autowired
  private SharedDataModel sharedDataModel;

  private boolean isRadioPowerOn = false;

  private boolean isStartupSequenceInProgress = false;

  private long lastScreenChangeTime;

  public StartupSequenceHandler(CommsBinding commsBinding)
  {
    super(commsBinding, IAppInputsPowerMenuNavPanelProperties.class, IPAPISVehicleOutputsProperties.class,
        ITCMSVehicleOutputsProperties.class);

    this.commsBinding = commsBinding;
    initMessageList();
  }

  @Override
  public void process(long aSimTime)
  {
    if (isStartupSequenceInProgress)
    {
      processStartupSequence();
    }
  }

  private void processStartupSequence()
  {

    long seconds = (DateTimeModel.getInstance().getTime() - lastScreenChangeTime) / 1000L;
    if (ScreenId.STARTUP_SCREEN_1.getId() == sharedDataModel.getScreenId() && seconds > STARTUP_SCREEN1_TIME)
    {
      screenChangeHandler.requestScreenChange(ScreenId.STARTUP_SCREEN_2);
      lastScreenChangeTime = DateTimeModel.getInstance().getTime();
    }
    else if (ScreenId.STARTUP_SCREEN_2.getId() == sharedDataModel.getScreenId()
        && seconds > STARTUP_SCREEN2_TIME)
    {
      screenChangeHandler.requestScreenChange(ScreenId.STARTUP_SCREEN_3);
      lastScreenChangeTime = DateTimeModel.getInstance().getTime();
    }
    else if (ScreenId.STARTUP_SCREEN_3.getId() == sharedDataModel.getScreenId()
        && seconds > STARTUP_SCREEN3_TIME)
    {
      screenChangeHandler.requestScreenChange(ScreenId.MAIN_SCREEN);
      isStartupSequenceInProgress = false;
      isRadioPowerOn = true;
      sendPulseRequest(commsBinding.getAppOutputsSetter(), IAppOutputsHeaderProperties.RADIO_SIGNAL, 0, 1);
      setApplicationOutputsProperty(IAppOutputsHeaderProperties.LINE_NAME, LINE_NAME.getBytes());

      sendPulseRequest(commsBinding.getAppOutputsSetter(), IAppOutputCabSignalProperties.CAB_A_STATUS, 0, 1);
      sendPulseRequest(commsBinding.getAppOutputsSetter(), IAppOutputCabSignalProperties.OCC_PA_STATUS, 0, 1);
      sendPulseRequest(commsBinding.getAppOutputsSetter(), IAppOutputCabSignalProperties.PA_PIS_A_STATUS, 0,
          1);
      sendPulseRequest(commsBinding.getAppOutputsSetter(), IAppOutputCabSignalProperties.PA_PIS_B_STATUS, 0,
          1);
      sendPulseRequest(commsBinding.getAppOutputsSetter(), IAppOutputCabSignalProperties.REMOTE_STATUS, 0, 1);
      sendPulseRequest(commsBinding.getAppOutputsSetter(), IAppOutputCabSignalProperties.TCMS_A_STATUS, 0, 1);
      sendPulseRequest(commsBinding.getAppOutputsSetter(), IAppOutputCabSignalProperties.TCMS_B_STATUS, 0, 1);
      sendPulseRequest(commsBinding.getAppOutputsSetter(), IAppOutputCabSignalProperties.TR_A_STATUS, 0, 1);
      sendPulseRequest(commsBinding.getAppOutputsSetter(), IAppOutputCabSignalProperties.TR_B_STATUS, 0, 1);
      sendPulseRequest(commsBinding.getAppOutputsSetter(), IAppOutputCabSignalProperties.TRIU_A_STATUS, 0, 1);
      sendPulseRequest(commsBinding.getAppOutputsSetter(), IAppOutputCabSignalProperties.TRIU_B_STATUS, 0, 1);

      setApplicationOutputsProperty(IAppOutputsHeaderProperties.MESSAGE_COUNT, messageList.size());
    }

  }

  @Override
  public <T> void papisVehicleOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue,
      Integer vehicleIndex)
  {
    if (IPAPISVehicleOutputsProperties.PAPIS_CCTV_POWER.equals(key)
        && getPapisCctvPowerState() == ApplicationConstants.POWER_OFF)
    {
      screenChangeHandler.requestScreenChange(ScreenId.BLANK_SCREEN);
    }

  }

  @Override
  public <T> void appInputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue, int vehicleIndex)
  {
    if (IAppInputsPowerMenuNavPanelProperties.POWER_BTN_REQUEST.equals(key) && (Integer)newValue > 0)
    {
      IPropertySetter radioIntercomInputSetter = getRadioIntercomInputSetter(getActiveVehicleIndex());
      if (Boolean.TRUE.equals(isRadioPowerOn))
      {
        screenChangeHandler.requestScreenChange(ScreenId.MAIN_SCREEN);
        sendPulseRequest(radioIntercomInputSetter, IRadioIntercomInputProperties.RADIO_CAB_CANCEL,
            ApplicationConstants.SET_VALUE, ApplicationConstants.RESET_VALUE);
        screenChangeHandler.requestScreenChange(ScreenId.BLANK_SCREEN);
        isStartupSequenceInProgress = false;
        isRadioPowerOn = false;
      }
      else
      {
        if (getPapisCctvPowerState() == ApplicationConstants.POWER_ON)
        {
          screenChangeHandler.requestScreenChange(ScreenId.STARTUP_SCREEN_1);
          lastScreenChangeTime = DateTimeModel.getInstance().getTime();
          isStartupSequenceInProgress = true;
        }
      }
    }
  }

  private int getPapisCctvPowerState()
  {
    IPAPISVehicleOutputsModel papisVehicleModel = (IPAPISVehicleOutputsModel)commsBinding
        .getPAPISVehicleOutputsModel().get(getActiveVehicleIndex());

    return papisVehicleModel == null ? 0 : papisVehicleModel.getPapisCctvPower();
  }

  @Override
  public void detachListeners()
  {
    super.detachListeners();
    isRadioPowerOn = false;
    isStartupSequenceInProgress = false;
  }

  public boolean isRadioPowerOn()
  {
    return isRadioPowerOn;
  }

  private void initMessageList()
  {

    messageList = RadioPropertiesReader.getInstance().getOutboxMsgMap().entrySet().stream()
        .map(m -> new MessageDO(m.getValue().getMsgText(), m.getKey(), new Date().getTime()))
        .collect(Collectors.toList());

  }

  @Override
  public <T> void tcmsVehicleOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue,
      int vehicleIndex)
  {
    if (ITCMSVehicleOutputsProperties.HMI_POWER.equals(key))
    {

      if (Boolean.TRUE.equals(isRadioPowerOn))
      {

        screenChangeHandler.requestScreenChange(ScreenId.BLANK_SCREEN);
        isStartupSequenceInProgress = false;
        isRadioPowerOn = false;
      }
      else if (Boolean.TRUE.equals(newValue))
      {

        screenChangeHandler.requestScreenChange(ScreenId.STARTUP_SCREEN_1);
        lastScreenChangeTime = DateTimeModel.getInstance().getTime();
        isStartupSequenceInProgress = true;

      }
    }
  }

}

/*
 * ==================================================================
 *
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *
 * ==================================================================
 */
package com.sydac.mmrbem.plugin;

import java.awt.FlowLayout;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.Image;
import java.awt.Insets;
import java.io.IOException;
import java.util.Collection;
import java.util.Collections;
import java.util.concurrent.Executors;

import javax.imageio.ImageIO;
import javax.swing.BorderFactory;
import javax.swing.JPanel;

import com.sydac.common.dataobjects.DBScenarioTrain;
import com.sydac.common.log.Tracer;
import com.sydac.common.registry.Registry;
import com.sydac.common.sessiondata.BaseScenarioData;
import com.sydac.mmrbem.radio.enums.ApplicationConstants;
import com.sydac.mmrbem.radiointercomplugin.model.PluginModel;
import com.sydac.mmrbem.radiointercomplugin.model.RadioDataModel;
import com.sydac.mmrbem.radiointercomplugin.view.RadioCommunicationSetupPanel;
import com.sydac.mmrbem.utils.HubUtils;
import com.sydac.peer.application.PeerApplication;
import com.sydac.simcomms.Gateway;
import com.sydac.simcomms.GenericData;
import com.sydac.simcomms.SessionData;
import com.sydac.simcomms.framework.ScenarioProcessing;
import com.sydac.simcomms.framework.Unit;
import com.sydac.simcomms.framework.UnitCreator;
import com.sydac.simcomms.system.CSystem;
import com.sydac.simulatorcontroller.gui.model.NavigationPage;
import com.sydac.simulatorcontroller.gui.model.NavigationPageType;
import com.sydac.simulatorcontroller.model.SimulationModel;
import com.sydac.simulatorcontroller.plugin.IMainFramePlugin;

/**
 * <p>
 * Extending classes should implement {@link #getRadioDataModel(int, int, int)}
 *
 * @author mulukg
 *
 */
public abstract class RadioIntercomPlugin implements IMainFramePlugin
{

  private static final Tracer log = Tracer.getInstance();

  private JPanel sccRadioIntercomPluginPanel;

  private final NavigationPageType navigationPageType = new NavigationPageType(
      ApplicationConstants.RADIO_INTERCOM_PANEL_NAME, // $NON-NLS-1$
      ApplicationConstants.RADIO_INTERCOM_PANEL_DESCRIPTION); // $NON-NLS-1$

  @Override
  public Collection<UnitCreator> getScenarioUnitCreators(CSystem aSystem)
  {
    return Collections.singleton(() -> new RadioIntercomPluginUnit());
  }

  @Override
  public Collection<NavigationPage> getNavigationPages()
  {
    Image icon = getNavigationIcon(ApplicationConstants.NAVIGATION_ICON);
    createGui();
    return Collections.singleton(new NavigationPage(navigationPageType, sccRadioIntercomPluginPanel, icon));
  }

  private void createGui()
  {
    JPanel radioPanel = new JPanel();
    radioPanel.setLayout(new FlowLayout(FlowLayout.LEFT, 100, 100));
    radioPanel.setBorder(BorderFactory.createTitledBorder(ApplicationConstants.RADIO_INTERCOM_PANEL_TITLE));

    radioPanel.add(new RadioCommunicationSetupPanel());

    sccRadioIntercomPluginPanel = new JPanel(new GridBagLayout());
    sccRadioIntercomPluginPanel.add(radioPanel, new GridBagConstraints(0, 0, 1, 1, 1.0, 1.0,
        GridBagConstraints.NORTH, GridBagConstraints.HORIZONTAL, new Insets(0, 0, 0, 0), 0, 0));
  }

  private Image getNavigationIcon(String aLocation)
  {
    Image result = null;
    try
    {
      result = ImageIO.read(RadioIntercomPlugin.class.getResourceAsStream(aLocation));
    }
    catch (IOException ioX)
    {
      log.error(ioX);
    }
    return result;
  }

  /**
   * Returns RadioDataModel
   * 
   * @param scenarioTrainId
   *          scenario train id
   * @param vehicleIndex
   *          the vehicle index
   * @param noOfVehicles
   *          the number of vehicles
   * @return RadioDataModel the radio data model
   */
  protected abstract RadioDataModel getRadioDataModel(int scenarioTrainId, int vehicleIndex,
      int noOfVehicles);

  /**
   * Plugin Unit that gets notified of the simulator's session states and
   * transitions.<br>
   * 
   * @author Nazim Oliyath
   *
   */
  class RadioIntercomPluginUnit implements Unit, ScenarioProcessing
  {
    @Override
    public Collection<UnitCreator> defineSession(Gateway gateway)
    {
      try
      {
        SessionData<GenericData> sd = gateway.getSessionData();

        if (sd.isSimulation())
        {
          BaseScenarioData scenarioData = PeerApplication.deserialiseFromComms(gateway.getScenarioData());

          int scenarioTrainId = HubUtils.findScenarioTrainId(scenarioData,
              HubUtils.findLogicalHubId(scenarioData, Registry.getInstance()));
          int scenarioVehicleIndex = HubUtils.findVehicleIndex(scenarioData,
              HubUtils.findLogicalHubId(scenarioData, Registry.getInstance()));
          int noOfVehicles = new DBScenarioTrain(scenarioData.getScenarioId(), scenarioTrainId).getTrain()
              .getElements().getCount();

          Executors.newSingleThreadScheduledExecutor().submit(() -> {
            if (pollCommsManager())
            {
              RadioDataModel radioDataModel = getRadioDataModel(scenarioTrainId, scenarioVehicleIndex,
                  noOfVehicles);
              radioDataModel.create();
              PluginModel.getInstance().setRadioDataModel(radioDataModel);
            }
          });

        }
      }
      catch (IOException e)
      {

      }

      return null;
    }

    /**
     * Simple poll for SimulationManager.commsManager.
     * 
     * @return
     */
    private boolean pollCommsManager()
    {
      final int WAIT_TIME = 100;
      while (true)
      {
        if (SimulationModel.getInstance().getCommsManager() == null)
        {
          try
          {
            Thread.sleep(WAIT_TIME);
          }
          catch (InterruptedException e)
          {
            Tracer.getInstance().error(e);
          }
        }
        else
        {
          return true;
        }
      }
    }

    @Override
    public void resetSession()
    {
      RadioDataModel radioDataModel = PluginModel.getInstance().getRadioDataModel();
      if (radioDataModel != null)
      {
        radioDataModel.destroy();
        PluginModel.getInstance().setRadioDataModel(null);
      }

      ScenarioProcessing.super.resetSession();
    }

  }

}

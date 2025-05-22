/**
 * ==================================================================
 * 
 * (C) Copyright 2016 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.scc.plugin.sessionsetup.gui;

import static com.sydac.simulatorcontroller.i18n.SimulatorControllerI18N.t;

import java.util.Optional;

import javax.swing.BoxLayout;
import javax.swing.Icon;
import javax.swing.JPanel;
import javax.swing.JTabbedPane;

import com.sydac.common.registry.Registry;
import com.sydac.common.sessiondata.BaseSessionData;
import com.sydac.foundation.AsyncSwingModelListener;
import com.sydac.foundation.IModelListener;
import com.sydac.foundation.Model;
import com.sydac.gui.components.DarkenedTabbedPane;

import com.sydac.simulatorcontroller.common.RegistryConstants;
import com.sydac.simulatorcontroller.gui.icon.SessionIcons;
import com.sydac.simulatorcontroller.model.ILocalStateModel;
import com.sydac.simulatorcontroller.model.LocalStateModel;
import com.sydac.simulatorcontroller.model.SimulationModel;

/**
 * Helper class that takes {@link JPanel}s for the new, replay and preview
 * session screens and places them in tabs.
 * <p>
 * This class monitors session state and enables/disables tabs based on whether
 * a session is running and if so what type of session it is.
 *
 * @author Stanley Mladenov
 */
public final class SessionSetupTabPanel
  extends JPanel
{
  /** The New Session view within the tabbed pane. */
  private Optional<JPanel> newSessionPanel;
  /** The Resume Session view within the tabbed pane. */
  private Optional<JPanel> resumeSessionPanel;
  /** The Replay Session view within the tabbed pane. */
  private Optional<JPanel> replaySessionPanel;
  /** The Preview Session view within the tabbed pane. */
  private Optional<JPanel> previewSessionPanel;  
  /** The Preview Session view within the tabbed pane. */
  private Optional<JPanel> idealRunSessionPanel;

  /** The tab control */
  private final JTabbedPane tabbedPane = new DarkenedTabbedPane();

  private final SimulationModel simulationModel = SimulationModel.getInstance();

  private final IModelListener defineSessionListener =
      new AsyncSwingModelListener((Model m, Enum<?> e)->{defineSession();});

  private final IModelListener terminateSessionListener =
      new AsyncSwingModelListener((Model m, Enum<?> e)->{terminateSession();});

  /**
   * Creates a tab panel with the given panels as the tabs' contents.
   * Names and icons for the tabs are assigned automatically by screen type.
   * Individual panels may be set to null if not required.
   */
  public SessionSetupTabPanel(JPanel aNewSessionPanel, JPanel aResumeSessionPanel, JPanel aReplaySessionPanel, JPanel aPreviewSessionPanel)
  {
    // Discard the Resume panel if that functionality is disabled
    if (!Registry.getInstance().getBoolean(RegistryConstants.SCC.DOMAIN, RegistryConstants.SCC.ENABLE_RESUME, false))
    {
      aResumeSessionPanel = null;
    }

    newSessionPanel     = Optional.ofNullable(aNewSessionPanel);
    resumeSessionPanel  = Optional.ofNullable(aResumeSessionPanel);
    replaySessionPanel  = Optional.ofNullable(aReplaySessionPanel);
    previewSessionPanel = Optional.ofNullable(aPreviewSessionPanel);
    

    setLayout( new BoxLayout(this, BoxLayout.X_AXIS) );

    addTab(newSessionPanel,     t("New Session"),     SessionIcons.NEW); //$NON-NLS-1$
    addTab(resumeSessionPanel,  t("Resume Session"),  SessionIcons.RESUME); //$NON-NLS-1$
    addTab(replaySessionPanel,  t("Replay Session"),  SessionIcons.REPLAY); //$NON-NLS-1$
    addTab(previewSessionPanel, t("Preview Session"), SessionIcons.PREVIEW); //$NON-NLS-1$
   

    add(tabbedPane);

    ILocalStateModel localStateModel = LocalStateModel.getInstance();
    localStateModel.addModelListener(defineSessionListener, ILocalStateModel.SessionChange.DEFINE_SESSION, false);
    localStateModel.addModelListener(terminateSessionListener, ILocalStateModel.SessionChange.TERMINATE_SESSION, false);
  }

  private void addTab(Optional<JPanel> panel, String localisedName, Icon icon)
  {
    if (panel.isPresent())
    {
      tabbedPane.addTab(localisedName, icon, panel.get());
    }
  }

  // -----------------------
  // Callback Methods
  // -----------------------

  /**
   * Called back on {@code ILocalStateModel.SessionChange.DEFINE_SESSION}.
   */
  private void defineSession()
  {
    // Switch to the tab for the type of session we're seeing.
    int selectedIndex = 0;

    if (replaySessionPanel.isPresent() && simulationModel.isReplay())
    {
      selectedIndex = tabbedPane.indexOfComponent(replaySessionPanel.get());
    }
    else if (previewSessionPanel.isPresent() && simulationModel.isPreviewMode())
    {
      selectedIndex = tabbedPane.indexOfComponent(previewSessionPanel.get());
    }
    else if (resumeSessionPanel.isPresent() && simulationModel.getSessionData().getResumeSessionId() != BaseSessionData.NOT_SET)
    {
      selectedIndex = tabbedPane.indexOfComponent(resumeSessionPanel.get());
    }
   

    for (int i = 0; i < tabbedPane.getTabCount(); ++i)
    {
      tabbedPane.setEnabledAt(i, i == selectedIndex);
    }

    tabbedPane.setSelectedIndex(selectedIndex);

    setEnabled(newSessionPanel,     false);
    setEnabled(resumeSessionPanel,  false);
    setEnabled(replaySessionPanel,  false);
    setEnabled(previewSessionPanel, false);
    setEnabled(idealRunSessionPanel, false);
  }

  /**
   * Called back on {@code ILocalStateModel.SessionChange.TERMINATE_SESSION}.
   */
  private void terminateSession()
  {
    for (int i = 0; i < tabbedPane.getTabCount(); ++i)
    {
      tabbedPane.setEnabledAt(i, true);
    }

    setEnabled(newSessionPanel,     true);
    setEnabled(resumeSessionPanel,  true);
    setEnabled(replaySessionPanel,  true);
    setEnabled(previewSessionPanel, true);
    setEnabled(idealRunSessionPanel, true);
  }

  private static void setEnabled(Optional<JPanel> panel, boolean enabled)
  {
    if (panel.isPresent())
    {
      panel.get().setEnabled(enabled);
    }
  }

}

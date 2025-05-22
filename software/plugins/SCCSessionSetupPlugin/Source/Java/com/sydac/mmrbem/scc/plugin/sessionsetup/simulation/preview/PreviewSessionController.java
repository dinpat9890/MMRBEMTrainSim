/* ==================================================================
 *
 *  (C) Copyright 2010 Sydac Pty Ltd., all rights reserved.
 *  This is unpublished proprietary source code of Sydac.
 *  The copyright notice above does not evidence any actual
 *  or intended publication of such source code.
 *
 * ==================================================================
 */
package com.sydac.mmrbem.scc.plugin.sessionsetup.simulation.preview;

import com.sydac.common.dataobjects.DBScenarioTrain;
import com.sydac.common.sessiondata.BaseSessionData;
import com.sydac.simulatorcontroller.session.request.SessionRequester;
import com.sydac.simulatorcontroller.session.setup.plugin.basic.simulatedsession.preview.PreviewSessionModel;

/**
 * This class contains all of the methods used to handle input from the Preview
 * Session panel.
 * <p>
 * It may be extended to make project specific changes to the {@link BaseSessionData}
 * before requesting the session.
 */
public class PreviewSessionController
  extends com.sydac.simulatorcontroller.session.setup.plugin.basic.simulatedsession.preview.PreviewSessionController
{
  private PreviewSessionModel previewSessionModel;

  public PreviewSessionController(SessionRequester aSessionRequester, PreviewSessionModel aPreviewSessionModel)
  {
    super(aSessionRequester, aPreviewSessionModel);
    previewSessionModel = aPreviewSessionModel;
  } // PreviewSessionController  
  
  /**
   * Fetches a single simulated train from the scenario. 
   * @return
   */
  public DBScenarioTrain getScenarioTrain()
  {
    for (DBScenarioTrain train : previewSessionModel.getScenario().getScenarioTrains())
      if (train.isSimulated())
        return train;
    // I don't think users will see this - the SMC doesn't let you create a
    // scenario without a train
    throw new IllegalStateException("There aren't any simulated trains in this scenario"); //$NON-NLS-1$
  }

} // class PreviewSessionController

// -- EOF

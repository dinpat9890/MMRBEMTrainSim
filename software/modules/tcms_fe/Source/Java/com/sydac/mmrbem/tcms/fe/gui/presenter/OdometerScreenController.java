/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.tcms.fe.gui.presenter;

import com.sydac.mmrbem.tcms.fe.gui.AbstractTCMSController;
import com.sydac.mmrbem.tcms.fe.gui.binder.OdometerScreenBinder;
import com.sydac.mmrbem.tcms.fe.gui.model.OdometerScreenModel;

import javafx.beans.value.ChangeListener;
import javafx.fxml.FXML;
import javafx.scene.control.Label;

public class OdometerScreenController extends AbstractTCMSController
{

  private ChangeListener<Number> odometerValueListener;

  private OdometerScreenModel odometerScreenModel;

  @FXML
  private Label odometerLbl;

  @Override
  public void detachListeners()
  {
    odometerScreenModel.getOdometerValue().removeListener(odometerValueListener);
  }

  @Override
  public void initializeImpl()
  {
    odometerScreenModel = new OdometerScreenModel(scenarioCarIndex);
    tcmsScreenBinders.add(new OdometerScreenBinder(odometerScreenModel));

    odometerValueListener = (observable, oldVal, newVal) -> updateOdometerValue((int)newVal);
    odometerScreenModel.getOdometerValue().addListener(odometerValueListener);

    updateOdometerValue(odometerScreenModel.getOdometerValue().get());
  }

  private void updateOdometerValue(int odometerVal)
  {
    if (odometerVal >= 0)
    {
      odometerLbl.setText(String.valueOf(odometerVal).concat(" m")); //$NON-NLS-1$
    }
    else
    {
      odometerLbl.setText("0 m"); //$NON-NLS-1$
    }
  }
}

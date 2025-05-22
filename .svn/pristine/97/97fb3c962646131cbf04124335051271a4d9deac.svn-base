/*
 * ==================================================================
 *
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *
 * ==================================================================
 */
package com.sydac.mmrbem.radiointercomplugin.view;

import java.awt.Color;
import java.awt.Dimension;
import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.ItemEvent;
import java.awt.event.ItemListener;

import javax.swing.BorderFactory;
import javax.swing.JPanel;

import com.sydac.foundation.IModelListener;
import com.sydac.mmrbem.radio.enums.CabToCabCallStatus;
import com.sydac.mmrbem.radio.enums.CabToCabCallType;
import com.sydac.mmrbem.radio.enums.CallDirection;
import com.sydac.mmrbem.radio.enums.IntercomCallType;
import com.sydac.mmrbem.radio.enums.OHPCallStatus;
import com.sydac.mmrbem.radio.enums.RadioCallGroup;
import com.sydac.mmrbem.radio.enums.RadioCallStatus;
import com.sydac.mmrbem.radio.enums.RadioCallTypeState;
import com.sydac.mmrbem.radiointercomplugin.model.PluginModel;
import com.sydac.mmrbem.radiointercomplugin.model.RadioDataModel;

/**
 * <p>
 * Radio Communication Setup Panel
 *
 * @author mulukg
 *
 */
public class RadioCommunicationSetupPanel extends JPanel implements ItemListener, ActionListener
{

  private static final long serialVersionUID = 1L;

  protected PluginModel pluginModel;

  protected RadioDataModel model = null;

  private RadioIntercomPanel radioIntercomPanel;

  private StartRadioCallPanel startRadioCallPanel;

  private ActiveOHPPanel activeOHPPanel;

  private IncomingOutgoingCallPanel callPanel;

  private SelectCarOHPPanel selectCarOHPPanel;

  private RadioGroupCallPanel radioGroupCallPanel;

  private CallDirection radioCallDirection = CallDirection.OUTGOING;

  private CallDirection cabOrSccCallDirection = CallDirection.OUTGOING;

  private RadioCallStatus radioCallStatus = RadioCallStatus.IN_ACTIVE;

  private CabToCabCallStatus cabToCabCallStatus = CabToCabCallStatus.INACTIVE;

  private OHPCallStatus ohpCallStatus = OHPCallStatus.NORMAL;

  private RadioCallTypeState radioCallType = RadioCallTypeState.FULL_DUPLEX;

  private RadioCallGroup radioCallGroup = RadioCallGroup.NO_GROUP_CALL;

  private CabToCabCallType cabToCabCallType = CabToCabCallType.NO_ACTIVE_CALL;

  private IntercomCallType intercomCallType = IntercomCallType.NO_CALL;

  private int selectedDialedNo = 0;

  private int noOfVehicles = 0;

  int ohpVehicleId = 0;

  /**
   * Default constructor.
   */
  public RadioCommunicationSetupPanel()
  {
    pluginModel = PluginModel.getInstance();
    pluginModel.addModelListener(radioModelHandler, PluginModel.Change.RADIO_DATA_MODEL_CHANGED, true);

    Dimension size = new Dimension(500, 600);
    setMinimumSize(size);
    setPreferredSize(size);
    setLayout(new FlowLayout(FlowLayout.CENTER, 0, 0));

    setBorder(BorderFactory.createLineBorder(Color.black));

    radioIntercomPanel = new RadioIntercomPanel(this);

    startRadioCallPanel = new StartRadioCallPanel(this);
    startRadioCallPanel.setVisible(false);

    activeOHPPanel = new ActiveOHPPanel(this);
    activeOHPPanel.setVisible(false);

    callPanel = new IncomingOutgoingCallPanel(this);
    callPanel.setVisible(false);

    selectCarOHPPanel = new SelectCarOHPPanel(this);
    selectCarOHPPanel.setVisible(false);

    radioGroupCallPanel = new RadioGroupCallPanel(this);
    radioGroupCallPanel.setVisible(false);

    add(radioIntercomPanel);
    add(startRadioCallPanel);
    add(activeOHPPanel);
    add(callPanel);
    add(selectCarOHPPanel);
    add(radioGroupCallPanel);

  }

  private final IModelListener displayChangedHandler = (model, whatChanged) -> {
    if (model instanceof RadioDataModel)
    {
      if (whatChanged == RadioDataModel.Change.COMMS_VALUE_CHANGED)
      {
        updateCallStatus();
      }
    }
  };

  private final IModelListener radioModelHandler = (m, whatChanged) -> {

    model = pluginModel.getRadioDataModel();

    if (model != null)
    {
      noOfVehicles = model.getNoOfVehicles();
      model.addModelListener(displayChangedHandler, RadioDataModel.Change.COMMS_VALUE_CHANGED, true);

    }
    else
    {
      if (radioIntercomPanel != null)
      {
        radioIntercomPanel.setVisible(true);
      }
      if (startRadioCallPanel != null)
      {
        startRadioCallPanel.setVisible(false);
      }
      if (activeOHPPanel != null)
      {
        activeOHPPanel.setVisible(false);
      }
      if (callPanel != null)
      {
        callPanel.setVisible(false);
      }
      if (selectCarOHPPanel != null)
      {
        selectCarOHPPanel.setVisible(false);
      }

      if (radioGroupCallPanel != null)
      {
        radioGroupCallPanel.setVisible(false);
      }

      radioCallType = RadioCallTypeState.NONE;
      radioCallDirection = CallDirection.NONE;
      radioCallGroup = RadioCallGroup.NO_GROUP_CALL;
      radioCallStatus = RadioCallStatus.IN_ACTIVE;
      intercomCallType = IntercomCallType.NO_CALL;
      selectedDialedNo = 0;
      noOfVehicles = 0;
    }
  };

  private void updateCallStatus()
  {
    radioCallDirection = CallDirection.NONE;
    cabOrSccCallDirection = CallDirection.NONE;
    if (model != null)
    {
      radioCallType = RadioCallTypeState.valueOf(model.getSelectedCallType());
      cabToCabCallType = CabToCabCallType.valueOf(model.getCabToCabCallType());
      radioCallGroup = RadioCallGroup.valueOf(model.getSelectedRadioGroup());

      selectedDialedNo = model.getSelectedDialledNo();

      radioCallStatus = RadioCallStatus.valueOf(model.getSelectedCallStatus());
      cabToCabCallStatus = CabToCabCallStatus.valueOf(model.getCabToCabCallStatus());
      ohpCallStatus = OHPCallStatus.valueOf(model.getOhpCallStatus());

      radioCallDirection = CallDirection.valueOf(model.getRadioOrSccCallStatus());

      if (CabToCabCallType.CAB_TO_CAB_CALL == cabToCabCallType)
      {
        cabOrSccCallDirection = CallDirection.INCOMING;
      }
      else if (CabToCabCallType.SCC_TO_CAB_CALL == cabToCabCallType
          || CabToCabCallType.ACTIVE_OHP_CALL == cabToCabCallType)
      {
        cabOrSccCallDirection = CallDirection.OUTGOING;
      }

      if (CabToCabCallType.ACTIVE_OHP_CALL == cabToCabCallType)
      {
        intercomCallType = IntercomCallType.ACTIVE_OHP_CALL;
      }
      else if (CabToCabCallType.CAB_TO_CAB_CALL == cabToCabCallType)
      {
        intercomCallType = IntercomCallType.CAB_TO_CAB_CALL;
      }
      else if (CabToCabCallType.SCC_TO_CAB_CALL == cabToCabCallType)
      {
        intercomCallType = IntercomCallType.SCC_TO_CAB_CALL;
      }
      else
      {
        intercomCallType = IntercomCallType.RADIO_CALL;
      }

    }

    if (ohpCallStatus == OHPCallStatus.MUTIPLE_OHP_CALLS || radioCallType != RadioCallTypeState.NONE
        || CabToCabCallType.NO_ACTIVE_CALL != cabToCabCallType)
    {
      radioIntercomPanel.setVisible(false);
      startRadioCallPanel.setVisible(false);
      activeOHPPanel.setVisible(false);
      callPanel.setVisible(true);
      selectCarOHPPanel.setVisible(false);
      radioGroupCallPanel.setVisible(false);
      callPanel.refresh();
    }
    else
    {
      radioIntercomPanel.setVisible(true);
      startRadioCallPanel.setVisible(false);
      activeOHPPanel.setVisible(false);
      callPanel.setVisible(false);
      selectCarOHPPanel.setVisible(false);
      radioGroupCallPanel.setVisible(false);
    }

  }

  @Override
  public void itemStateChanged(ItemEvent e)
  {}

  @Override
  public void actionPerformed(ActionEvent e)
  {}

  public void onStartRadioCallBtnAction()
  {
    radioIntercomPanel.setVisible(false);
    startRadioCallPanel.setVisible(true);
    activeOHPPanel.setVisible(false);
    callPanel.setVisible(false);
    selectCarOHPPanel.setVisible(false);
    radioGroupCallPanel.setVisible(false);
  }

  public void onCabToCabIntercomBtnAction()
  {
    model.startSccCabToCabCall();
  }

  public void onActivateOHPBtnAction()
  {
    radioIntercomPanel.setVisible(false);
    startRadioCallPanel.setVisible(false);
    activeOHPPanel.setVisible(true);
    callPanel.setVisible(false);
    selectCarOHPPanel.setVisible(false);
    activeOHPPanel.refresh();
    radioGroupCallPanel.setVisible(false);
  }

  public void onStartHalfDuplexCallBtnAction()
  {
    radioCallType = RadioCallTypeState.HALF_DUPLEX;
    model.startRadioCall(radioCallType);
    onStartCallBtnAction();
  }

  public void onEmergencyCallBtnAction()
  {
    radioCallType = RadioCallTypeState.EMERGENCY;
    model.startRadioCall(radioCallType);
    onStartCallBtnAction();
  }

  public void onFullDuplexCallBtnAction()
  {
    radioCallType = RadioCallTypeState.FULL_DUPLEX;
    model.startRadioCall(radioCallType);
    onStartCallBtnAction();
  }

  public void startRadioGroupCall(int groupId)
  {
    radioCallType = RadioCallTypeState.GROUP;
    model.startRadioGroupCall(groupId);
    onStartCallBtnAction();
  }

  public void onGroupCallBtnAction()
  {

    radioIntercomPanel.setVisible(false);
    startRadioCallPanel.setVisible(false);
    activeOHPPanel.setVisible(false);
    callPanel.setVisible(false);
    selectCarOHPPanel.setVisible(false);
    radioGroupCallPanel.setVisible(true);

  }

  public void onStartCallBtnAction()
  {
    radioIntercomPanel.setVisible(false);
    startRadioCallPanel.setVisible(false);
    activeOHPPanel.setVisible(false);
    callPanel.setVisible(true);
    selectCarOHPPanel.setVisible(false);
    radioGroupCallPanel.setVisible(false);
    callPanel.refresh();
  }

  public void onAcceptCallBtnAction()
  {
    if (model != null)
    {
      if (intercomCallType == IntercomCallType.CAB_TO_CAB_CALL)
      {
        model.startSccCabToCabCall();
      }
      else if (intercomCallType == IntercomCallType.RADIO_CALL)
      {
        model.acceptIncomingRadioCall();
      }
    }
  }

  public void onEndOrCancelCallBtnAction()
  {
    if (model != null)
    {
      if (intercomCallType == IntercomCallType.SCC_TO_CAB_CALL
          || intercomCallType == IntercomCallType.ACTIVE_OHP_CALL
          || intercomCallType == IntercomCallType.CAB_TO_CAB_CALL)
      {
        model.endSccCabToCabCall();
      }
      else if (intercomCallType == IntercomCallType.RADIO_CALL)
      {
        model.endRadioCall();
      }
    }

    radioIntercomPanel.setVisible(true);
    startRadioCallPanel.setVisible(false);
    activeOHPPanel.setVisible(false);
    callPanel.setVisible(false);
    selectCarOHPPanel.setVisible(false);
    radioGroupCallPanel.setVisible(false);

  }

  public void onCarSelectionAction(int carId)
  {
    ohpVehicleId = carId;
    radioIntercomPanel.setVisible(false);
    startRadioCallPanel.setVisible(false);
    activeOHPPanel.setVisible(false);
    callPanel.setVisible(false);
    selectCarOHPPanel.setVisible(true);
    radioGroupCallPanel.setVisible(false);
  }

  public void onMultiplePecuCallSelectionAction()
  {
    radioIntercomPanel.setVisible(false);
    startRadioCallPanel.setVisible(false);
    activeOHPPanel.setVisible(false);
    callPanel.setVisible(true);
    selectCarOHPPanel.setVisible(false);
    radioGroupCallPanel.setVisible(false);
    callPanel.refresh();

    model.setOHPId(5);
    model.setOHPVehicleId(0);
  }

  public void onCarOHPSelectionAction(int ohpId)
  {
    radioIntercomPanel.setVisible(false);
    startRadioCallPanel.setVisible(false);
    activeOHPPanel.setVisible(false);
    callPanel.setVisible(true);
    selectCarOHPPanel.setVisible(false);
    radioGroupCallPanel.setVisible(false);
    callPanel.refresh();

    model.setOHPId(ohpId);
    model.setOHPVehicleId(ohpVehicleId);
    model.startOHPCall();
  }

  public CallDirection getCabOrSccCallDirection()
  {
    return cabOrSccCallDirection;
  }

  public CabToCabCallStatus getCabToCabCallStatus()
  {
    return cabToCabCallStatus;
  }

  public RadioCallTypeState getRadioCallType()
  {
    return radioCallType;
  }

  public CallDirection getRadioCallDirection()
  {
    return radioCallDirection;
  }

  public RadioCallStatus getRadioCallStatus()
  {
    return radioCallStatus;
  }

  public IntercomCallType getIntercomCallType()
  {
    return intercomCallType;
  }

  public int getSelectedDialedNo()
  {
    return selectedDialedNo;
  }

  public int getNoOfVehicles()
  {
    return noOfVehicles;
  }

  public CabToCabCallType getCabToCabCallType()
  {
    return cabToCabCallType;
  }

  public OHPCallStatus getOhpCallStatus()
  {
    return ohpCallStatus;
  }

  public RadioCallGroup getRadioCallGroup()
  {
    return radioCallGroup;
  }

  public void backToMainPanel()
  {

    radioIntercomPanel.setVisible(true);
    startRadioCallPanel.setVisible(false);
    activeOHPPanel.setVisible(false);
    callPanel.setVisible(false);
    selectCarOHPPanel.setVisible(false);
    radioGroupCallPanel.setVisible(false);

  }

  public void backToStartRadioCallPanel()
  {
    radioIntercomPanel.setVisible(false);
    startRadioCallPanel.setVisible(true);
    activeOHPPanel.setVisible(false);
    callPanel.setVisible(false);
    selectCarOHPPanel.setVisible(false);
    radioGroupCallPanel.setVisible(false);
  }

  public void backToActiveOHPPanel()
  {
    radioIntercomPanel.setVisible(false);
    startRadioCallPanel.setVisible(false);
    activeOHPPanel.setVisible(true);
    callPanel.setVisible(false);
    selectCarOHPPanel.setVisible(false);
    radioGroupCallPanel.setVisible(false);
  }
}

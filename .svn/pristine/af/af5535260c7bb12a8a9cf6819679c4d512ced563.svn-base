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

import java.awt.Dimension;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.Insets;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JPanel;

import com.sydac.mmrbem.radio.enums.CabToCabCallStatus;
import com.sydac.mmrbem.radio.enums.CallDirection;
import com.sydac.mmrbem.radio.enums.IntercomCallType;
import com.sydac.mmrbem.radio.enums.OHPCallStatus;
import com.sydac.mmrbem.radio.enums.RadioCallStatus;
import com.sydac.mmrbem.radiointercomplugin.components.CWButton;
import com.sydac.mmrbem.radiointercomplugin.components.CWLabel;

/**
 * <p>
 * Incoming and Outgoing Call Panel
 *
 * @author mulukg
 *
 */
public class IncomingOutgoingCallPanel extends JPanel
{

  private static final long serialVersionUID = 1L;

  private JLabel msgLabel;

  private JButton acceptCallBtn;

  private JButton endCallBtn;

  private RadioCommunicationSetupPanel radioCommunicationSetupPanel;

  private ExecutorService executorService = Executors.newSingleThreadExecutor();

  public IncomingOutgoingCallPanel(RadioCommunicationSetupPanel radioCommunicationSetupPanel)
  {
    this.radioCommunicationSetupPanel = radioCommunicationSetupPanel;

    setLayout(new GridBagLayout());

    GridBagConstraints gbc = new GridBagConstraints();
    int top = 50;
    int left = 3;
    int bottom = 10;
    int right = 3;
    int rowNumber = 0;
    Insets insects = new Insets(top, left, bottom, right);

    Dimension buttonSize = new Dimension(300, 50);
    Dimension labelSize = new Dimension(300, 30);

    msgLabel = new CWLabel("Use PTT to speak with trainee", labelSize); //$NON-NLS-1$

    acceptCallBtn = new CWButton("Accept Call", buttonSize); //$NON-NLS-1$
    acceptCallBtn.addActionListener(new ActionListener() {
      @Override
      public void actionPerformed(ActionEvent arg0)
      {
        radioCommunicationSetupPanel.onAcceptCallBtnAction();
      }
    });

    endCallBtn = new CWButton("End Call", buttonSize); //$NON-NLS-1$

    endCallBtn.addActionListener(new ActionListener() {
      @Override
      public void actionPerformed(ActionEvent arg0)
      {
        radioCommunicationSetupPanel.onEndOrCancelCallBtnAction();
      }
    });

    gbc.fill = GridBagConstraints.HORIZONTAL;
    gbc.insets = insects;
    insects = new Insets(top, left, bottom, right);
    gbc.insets = insects;
    gbc.gridx = 0;
    gbc.gridy = rowNumber++;
    this.add(msgLabel, gbc);

    gbc.gridx = 0;
    gbc.gridy = rowNumber++;
    this.add(acceptCallBtn, gbc);

    top = 225;

    gbc.insets = new Insets(top, left, bottom, right);
    gbc.gridx = 0;
    gbc.gridy = rowNumber++;
    this.add(endCallBtn, gbc);

  }

  public void refresh()
  {
    if (radioCommunicationSetupPanel.getRadioCallDirection() == CallDirection.INCOMING
        || radioCommunicationSetupPanel.getCabOrSccCallDirection() == CallDirection.INCOMING)
    {
      showIncomingCallInfo();
    }
    else
    {
      showOutgoingCallInfo();
    }

  }

  private void showOutgoingCallInfo()
  {
    String msgLabelText = getCallMessage();
    String endCallBtnText = ""; //$NON-NLS-1$

    boolean isCallRequested = getIsCallRequested();

    endCallBtnText = isCallRequested ? "Cancel" : "End"; //$NON-NLS-1$ //$NON-NLS-2$

    msgLabel.setText(msgLabelText);
    acceptCallBtn.setVisible(false);
    endCallBtn.setText(endCallBtnText);

    if (radioCommunicationSetupPanel.getOhpCallStatus() == OHPCallStatus.MUTIPLE_OHP_CALLS)
    {
      endCallBtn.setVisible(Boolean.TRUE);
      endCallBtn.setText("End"); //$NON-NLS-1$
    }
  }

  private String getCallMessage()
  {
    String msgLabelText = ""; //$NON-NLS-1$
    if (IntercomCallType.RADIO_CALL == radioCommunicationSetupPanel.getIntercomCallType())
    {
      msgLabelText = radioCommunicationSetupPanel.getRadioCallType().getText();
    }
    else if (IntercomCallType.CAB_TO_CAB_CALL == radioCommunicationSetupPanel.getIntercomCallType()
        || IntercomCallType.SCC_TO_CAB_CALL == radioCommunicationSetupPanel.getIntercomCallType())
    {
      msgLabelText = radioCommunicationSetupPanel.getCabToCabCallStatus().getText();
    }
    else
    {
      msgLabelText = radioCommunicationSetupPanel.getOhpCallStatus().getText();
    }

    if (radioCommunicationSetupPanel.getOhpCallStatus() == OHPCallStatus.MUTIPLE_OHP_CALLS)
    {
      msgLabelText = radioCommunicationSetupPanel.getOhpCallStatus().getText();
    }
    return msgLabelText;
  }

  private void showIncomingCallInfo()
  {
    String msgLabelText = getCallMessage();
    String endCallBtnText = ""; //$NON-NLS-1$

    boolean isCallRequested = getIsCallRequested();

    if (IntercomCallType.RADIO_CALL == radioCommunicationSetupPanel.getIntercomCallType() && isCallRequested)
    {/*
      * // auto accept radio call executorService.submit(() -> {
      * radioCommunicationSetupPanel.onAcceptCallBtnAction(); }, 2500);
      */}

    endCallBtnText = isCallRequested ? "Decline" : "End"; //$NON-NLS-1$ //$NON-NLS-2$

    msgLabel.setText(msgLabelText);
    acceptCallBtn.setVisible(isCallRequested);
    endCallBtn.setText(endCallBtnText);

  }

  private boolean getIsCallRequested()
  {
    boolean isCallRequested = false;

    if (IntercomCallType.RADIO_CALL == radioCommunicationSetupPanel.getIntercomCallType())
    {
      isCallRequested = RadioCallStatus.CALL_REQUESTED == radioCommunicationSetupPanel.getRadioCallStatus();

      if (radioCommunicationSetupPanel.getOhpCallStatus() == OHPCallStatus.MUTIPLE_OHP_CALLS)
      {
        isCallRequested = OHPCallStatus.MUTIPLE_OHP_CALLS == radioCommunicationSetupPanel.getOhpCallStatus();
      }
    }
    else if (IntercomCallType.CAB_TO_CAB_CALL == radioCommunicationSetupPanel.getIntercomCallType()
        || IntercomCallType.SCC_TO_CAB_CALL == radioCommunicationSetupPanel.getIntercomCallType())
    {
      isCallRequested = CabToCabCallStatus.CALL_REQUESTED == radioCommunicationSetupPanel
          .getCabToCabCallStatus();
    }
    else if (IntercomCallType.ACTIVE_OHP_CALL == radioCommunicationSetupPanel.getIntercomCallType())
    {
      isCallRequested = (OHPCallStatus.CALLING == radioCommunicationSetupPanel.getOhpCallStatus());
    }
    return isCallRequested;
  }

}
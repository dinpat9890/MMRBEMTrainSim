/*
 * ================================================================== (C)
 * Copyright 2020 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.dmi.fe.gui.model;

import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;

import com.google.protobuf.InvalidProtocolBufferException;
import com.sydac.common.log.Tracer;
import com.sydac.mmrbem.cabscreens.fe.gui.model.AbstractScreenModel;
import com.sydac.mmrbem.cbtc.common.protos.CBTCProtos;
import com.sydac.mmrbem.cbtc.common.protos.CBTCProtos.AvailableModesList.DrivingMode;
import com.sydac.mmrbem.dmi.fe.gui.data.AvailableDrivingModesDO;

import javafx.beans.property.BooleanProperty;
import javafx.beans.property.IntegerProperty;
import javafx.beans.property.ListProperty;
import javafx.beans.property.LongProperty;
import javafx.beans.property.SimpleBooleanProperty;
import javafx.beans.property.SimpleIntegerProperty;
import javafx.beans.property.SimpleListProperty;
import javafx.beans.property.SimpleLongProperty;
import javafx.collections.FXCollections;

/**
 * A model to Main Screen Area C Right
 * 
 * @author mulukg
 *
 */
public class MainScreenAreaCRightModel extends AbstractScreenModel
{

  private static final Tracer LOGGER = Tracer.getInstance();

  private IntegerProperty currentDrivingMode = new SimpleIntegerProperty();

  private IntegerProperty localisationStatus = new SimpleIntegerProperty();

  private List<DrivingMode> availableModes = new ArrayList<>();

  private ListProperty<AvailableDrivingModesDO> availableModesDOList = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  private final LongProperty flashTime = new SimpleLongProperty();

  private BooleanProperty atcBypassState = new SimpleBooleanProperty();

  public MainScreenAreaCRightModel(int carIndex)
  {
    super(carIndex);
  }

  public ListProperty<AvailableDrivingModesDO> getAvailableModesDOList()
  {
    return availableModesDOList;
  }

  public List<DrivingMode> getAvailableModes()
  {
    return availableModes;
  }

  public void setCurrentDrivingMode(int value)
  {
    currentDrivingMode.set(value);
  }

  public IntegerProperty getCurrentDrivingMode()
  {
    return currentDrivingMode;
  }

  public IntegerProperty getLocalisationStatus()
  {
    return localisationStatus;
  }

  public void setLocalisationStatus(int value)
  {
    localisationStatus.set(value);
  }

  public void setAvailableModes(byte[] modes)
  {

    if (modes.length != 0)
    {
      try
      {
        CBTCProtos.AvailableModesList availableModesList = CBTCProtos.AvailableModesList.parseFrom(modes);
        availableModes.clear();
        availableModes.addAll(availableModesList.getAvailableDrivingModeList());

        this.availableModesDOList.clear();

        this.availableModesDOList.addAll(FXCollections
            .observableArrayList(CBTCProtos.AvailableModesList.parseFrom(modes).getAvailableDrivingModeList()
                .stream().map(drivingMode -> new AvailableDrivingModesDO(drivingMode.getNumber(),
                    DrivingMode.getDescriptor().getName()))
                .collect(Collectors.toList())));
      }
      catch (InvalidProtocolBufferException e)
      {
        LOGGER.info(e);
      }
    }

  }

  public void setFlashTime(Number dateTime)
  {
    flashTime.set((long)dateTime);
  }

  public LongProperty getFlashTime()
  {
    return flashTime;
  }

  /**
   * @return the atcBypassState
   */
  public BooleanProperty getAtcBypassState()
  {
    return atcBypassState;
  }

  /**
   * @param atcBypassState
   *          the atcBypassState to set
   */
  public void setAtcBypassState(Boolean atcBypassState)
  {
    this.atcBypassState.set(atcBypassState);
  }

}

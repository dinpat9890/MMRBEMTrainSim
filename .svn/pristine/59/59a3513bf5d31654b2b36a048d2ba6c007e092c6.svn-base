/*
 * ==================================================================
 *
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *
 * ==================================================================
 */
package com.sydac.mmrbem.tcms.fe.gui.model;

import com.google.protobuf.InvalidProtocolBufferException;
import com.sydac.common.febe.frontend.gui.AbstractScreenModel;
import com.sydac.common.log.Tracer;
import com.sydac.mmrbem.salooncctv.common.protos.SaloonCCTVProtos.CameraViewButtons;
import com.sydac.mmrbem.salooncctv.common.protos.SaloonCCTVProtos.CameraViewButtons.AssociatedView;
import com.sydac.mmrbem.salooncctv.common.protos.SaloonCCTVProtos.CameraViewButtons.Button;
import com.sydac.mmrbem.tcms.common.ScreenId;
import com.sydac.mmrbem.tcms.common.state.ApplicationConstants;
import com.sydac.mmrbem.tcms.fe.gui.data.CameraViewButtonDO;
import com.sydac.mmrbem.tcms.fe.gui.state.AutoRotationStatus;
import com.sydac.mmrbem.tcms.fe.gui.state.CCTVCameraId;
import com.sydac.mmrbem.tcms.fe.gui.state.InternalExternalViewStatus;

import javafx.beans.property.BooleanProperty;
import javafx.beans.property.IntegerProperty;
import javafx.beans.property.ListProperty;
import javafx.beans.property.SimpleBooleanProperty;
import javafx.beans.property.SimpleIntegerProperty;
import javafx.beans.property.SimpleListProperty;
import javafx.beans.property.SimpleStringProperty;
import javafx.beans.property.StringProperty;
import javafx.collections.FXCollections;

public class CCTVFooterPanelModel extends AbstractScreenModel
{

  private IntegerProperty autorotationProperty = new SimpleIntegerProperty(AutoRotationStatus.ON.getValue());

  private IntegerProperty screenIdProperty = new SimpleIntegerProperty(ScreenId.BLANK_SCREEN.getId());

  private IntegerProperty internalOrExternalViewProperty = new SimpleIntegerProperty(
      InternalExternalViewStatus.EXTERNAL_CAMERA_SELECTION.getValue());

  private IntegerProperty selectedVehicleIndexProperty = new SimpleIntegerProperty();

  private IntegerProperty alarmModeProperty = new SimpleIntegerProperty();

  private IntegerProperty alarmTypeActive = new SimpleIntegerProperty();

  private IntegerProperty selectedExternalCameraType = new SimpleIntegerProperty();

  private ListProperty<CameraViewButtonDO> cameraViewButtonsList = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  private StringProperty firstFeedViewLable = new SimpleStringProperty();

  private StringProperty secondFeedViewLable = new SimpleStringProperty();

  private StringProperty thirdFeedViewLable = new SimpleStringProperty();

  private StringProperty fourthFeedViewLable = new SimpleStringProperty();

  private StringProperty singleFeedViewLable = new SimpleStringProperty();

  private final StringProperty trainId = new SimpleStringProperty("Car01111-LN1/UP"); //$NON-NLS-1$

  private IntegerProperty numberOfCars = new SimpleIntegerProperty();

  private StringProperty currentLocation = new SimpleStringProperty(" "); //$NON-NLS-1$

  private StringProperty nextLocation = new SimpleStringProperty(" "); //$NON-NLS-1$

  private IntegerProperty firstFeedCameraId = new SimpleIntegerProperty();

  private IntegerProperty secondFeedCameraId = new SimpleIntegerProperty();

  private IntegerProperty thirdFeedCameraId = new SimpleIntegerProperty();

  private IntegerProperty fourthFeedCameraId = new SimpleIntegerProperty();

  private IntegerProperty firstFeedCarIndex = new SimpleIntegerProperty();

  private IntegerProperty secondFeedCarIndex = new SimpleIntegerProperty();

  private IntegerProperty thirdFeedCarIndex = new SimpleIntegerProperty();

  private IntegerProperty fourthFeedCarIndex = new SimpleIntegerProperty();

  private IntegerProperty alarmFire = new SimpleIntegerProperty();

  private IntegerProperty alarmObstacle = new SimpleIntegerProperty();

  private IntegerProperty alarmPecu = new SimpleIntegerProperty();

  private IntegerProperty alarmDoorUnlock = new SimpleIntegerProperty();

  private IntegerProperty alarmEmegencyDoorOpening = new SimpleIntegerProperty();

  private IntegerProperty alarmDriverDesk = new SimpleIntegerProperty();

  private IntegerProperty alarmObstructionDeflection = new SimpleIntegerProperty();

  private IntegerProperty alarmTrackEvent = new SimpleIntegerProperty();

  private IntegerProperty alarmEmergencyEvent = new SimpleIntegerProperty();

  private IntegerProperty alarmOheEvent = new SimpleIntegerProperty();

  private IntegerProperty alarmPantographEvent = new SimpleIntegerProperty();

  private StringProperty firstFeedAlarmViewLable = new SimpleStringProperty();

  private IntegerProperty firstFeedAlarmViewIcon = new SimpleIntegerProperty();

  private StringProperty secondFeedAlarmViewLable = new SimpleStringProperty();

  private IntegerProperty secondFeedAlarmViewIcon = new SimpleIntegerProperty();

  private StringProperty thirdFeedAlarmViewLable = new SimpleStringProperty();

  private IntegerProperty thirdFeedAlarmViewIcon = new SimpleIntegerProperty();

  private StringProperty fourthFeedAlarmViewLable = new SimpleStringProperty();

  private IntegerProperty fourthFeedAlarmViewIcon = new SimpleIntegerProperty();

  private StringProperty lineDetail = new SimpleStringProperty();

  private static BooleanProperty onEventSwitchButtonState = new SimpleBooleanProperty();

  private static BooleanProperty settingsPopupActive = new SimpleBooleanProperty();

  private IntegerProperty cctvDisplayHangedFault = new SimpleIntegerProperty();

  private IntegerProperty detrainmentDoorFault = new SimpleIntegerProperty();

  private IntegerProperty settingPanelQuitButton = new SimpleIntegerProperty();

  private IntegerProperty settingPanelButton = new SimpleIntegerProperty();

  private IntegerProperty normalEvenetSwitch = new SimpleIntegerProperty();

  private IntegerProperty detrailmentCameraId = new SimpleIntegerProperty();

  public CCTVFooterPanelModel(int carIndex)
  {
    super(carIndex);
  }

  public static BooleanProperty getSettingsPopupActive()
  {
    return settingsPopupActive;
  }

  public static void setSettingsPopupActive(Boolean isSettingsPopupActive)
  {
    settingsPopupActive.set(isSettingsPopupActive);
  }

  public static BooleanProperty getEventSwitchButtonState()
  {
    return onEventSwitchButtonState;
  }

  public static void setEventSwitchButtonState(Boolean isClicked)
  {
    onEventSwitchButtonState.set(isClicked);
  }

  public StringProperty getFirstFeedAlarmViewLable()
  {
    return firstFeedAlarmViewLable;
  }

  public void setFirstFeedAlarmViewLable(String value)
  {
    this.firstFeedAlarmViewLable.set(value);
  }

  public StringProperty getSecondFeedAlarmViewLable()
  {
    return secondFeedAlarmViewLable;
  }

  public void setSecondFeedAlarmViewLable(String secondFeedAlarmViewLable)
  {
    this.secondFeedAlarmViewLable.set(secondFeedAlarmViewLable);
  }

  public IntegerProperty getSecondFeedAlarmViewIcon()
  {
    return secondFeedAlarmViewIcon;
  }

  public void setSecondFeedAlarmViewIcon(Integer secondFeedAlarmViewIcon)
  {
    this.secondFeedAlarmViewIcon.set(secondFeedAlarmViewIcon);
  }

  public StringProperty getThirdFeedAlarmViewLable()
  {
    return thirdFeedAlarmViewLable;
  }

  public void setThirdFeedAlarmViewLable(String thirdFeedAlarmViewLable)
  {
    this.thirdFeedAlarmViewLable.set(thirdFeedAlarmViewLable);
  }

  public IntegerProperty getThirdFeedAlarmViewIcon()
  {
    return thirdFeedAlarmViewIcon;
  }

  public void setThirdFeedAlarmViewIcon(Integer thirdFeedAlarmViewIcon)
  {
    this.thirdFeedAlarmViewIcon.set(thirdFeedAlarmViewIcon);
  }

  public StringProperty getFourthFeedAlarmViewLable()
  {
    return fourthFeedAlarmViewLable;
  }

  public void setFourthFeedAlarmViewLable(String fourthFeedAlarmViewLable)
  {
    this.fourthFeedAlarmViewLable.set(fourthFeedAlarmViewLable);
  }

  public IntegerProperty getFourthFeedAlarmViewIcon()
  {
    return fourthFeedAlarmViewIcon;
  }

  public void setFourthFeedAlarmViewIcon(Integer fourthFeedAlarmViewIcon)
  {
    this.fourthFeedAlarmViewIcon.set(fourthFeedAlarmViewIcon);
  }

  public IntegerProperty getFirstFeedAlarmViewIcon()
  {
    return firstFeedAlarmViewIcon;
  }

  public void setFirstFeedAlarmViewIcon(Integer firstFeedAlarmViewIcon)
  {
    this.firstFeedAlarmViewIcon.set(firstFeedAlarmViewIcon);
  }

  public void setAutoRotationState(int state)
  {
    autorotationProperty.set(state);
  }

  public IntegerProperty getAutoRotationStatusProperty()
  {
    return autorotationProperty;
  }

  public void setScreenId(int screenId)
  {
    screenIdProperty.set(screenId);
  }

  public IntegerProperty getScreenIdProperty()
  {
    return screenIdProperty;
  }

  public void setExternalOrInternalView(int view)
  {
    internalOrExternalViewProperty.set(view);
  }

  public IntegerProperty getInternalOrExternalViewProperty()
  {
    return internalOrExternalViewProperty;
  }

  public IntegerProperty getNumberOfCars()
  {
    return numberOfCars;
  }

  public void setNumberOfCars(Integer numberOfCars)
  {
    this.numberOfCars.set(numberOfCars);
  }

  public IntegerProperty getSelectedVehicleIndexProperty()
  {
    return selectedVehicleIndexProperty;
  }

  public void setSelectedVehicleIndexProperty(Integer selectedVehicleIndexProperty)
  {
    this.selectedVehicleIndexProperty.set(selectedVehicleIndexProperty);
  }

  public IntegerProperty getAlarmModeProperty()
  {
    return alarmModeProperty;
  }

  public void setAlarmModeProperty(Integer alarmModeProperty)
  {
    this.alarmModeProperty.set(alarmModeProperty);
  }

  public void setTrainId(int value)
  {
    trainId.set(String.valueOf(value));
  }

  public StringProperty getTrainId()
  {
    return trainId;
  }

  private void resetFeedViewLables()
  {
    firstFeedViewLable.set(ApplicationConstants.BLANK_STRING);
    secondFeedViewLable.set(ApplicationConstants.BLANK_STRING);
    thirdFeedViewLable.set(ApplicationConstants.BLANK_STRING);
    fourthFeedViewLable.set(ApplicationConstants.BLANK_STRING);
    singleFeedViewLable.set(ApplicationConstants.BLANK_STRING);
  }

  public void updateCameraButtonList(byte[] cameraDetailList)
  {
    resetFeedViewLables();
    if (cameraDetailList.length != 0)
    {
      cameraViewButtonsList.clear();
      try
      {
        CameraViewButtons cameraViewButtons = CameraViewButtons.parseFrom(cameraDetailList);

        for (Button buttonStateDetail : cameraViewButtons.getButtonList())
        {
          CameraViewButtonDO cameraViewButtonDO = new CameraViewButtonDO();
          cameraViewButtonDO.setButtonId(buttonStateDetail.getId());
          if ((buttonStateDetail.getName()).equals("")) //$NON-NLS-1$
          {
            cameraViewButtonDO.setButtonName(""); //$NON-NLS-1$

          }
          else
          {
            cameraViewButtonDO.setButtonName(buttonStateDetail.getName());
          }

          cameraViewButtonDO.setButtonState(buttonStateDetail.getState().name().toLowerCase());
          cameraViewButtonDO.setAssociatedView(buttonStateDetail.getAssociatedView().getNumber());
          cameraViewButtonDO.setAlarmType(buttonStateDetail.getAlarmType());
          cameraViewButtonsList.add(cameraViewButtonDO);
        }
        for (CameraViewButtonDO cameraViewButtonDO : cameraViewButtonsList)
        {
          updateFeedViewLables(cameraViewButtonDO);
        }
      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
    }
  }

  private void updateFeedViewLables(CameraViewButtonDO cameraViewButtonDO)
  {
    AssociatedView associatedView = AssociatedView
        .forNumber(cameraViewButtonDO.cameraAssociatedViewProperty().get());

    String[] carNameArray = cameraViewButtonDO.getButtonName().get().split("-"); //$NON-NLS-1$

    String[] carIdArray = cameraViewButtonDO.getButtonName().get().split("_"); //$NON-NLS-1$

    String cameraName = CCTVCameraId.getCameraNameOf(cameraViewButtonDO.getSelectedCameraId()).getCamName();

    String carName = carNameArray.length > 1 ? carNameArray[0] : ""; //$NON-NLS-1$

    String carId = carIdArray.length > 1 ? carIdArray[1] : ""; //$NON-NLS-1$

    if (cameraViewButtonDO.getSelectedCameraId() == CCTVCameraId.DMC_CAB_CAMERA.getCameraEnumId())
    {
      detrainmentDoorFault.set(associatedView.getNumber());
    }

    boolean isCamNumberAvailable = !(cameraViewButtonDO.getSelectedCameraId() == 1
        || cameraViewButtonDO.getSelectedCameraId() == 2 || cameraViewButtonDO.getSelectedCameraId() == 16
        || (cameraViewButtonDO.getSelectedCameraId() >= 5 && cameraViewButtonDO.getSelectedCameraId() <= 7));

    String camDisplayName = carName.concat(carId).concat("-").concat(cameraName); //$NON-NLS-1$
    if (camDisplayName != null)
    {
      switch (associatedView)
      {
      case FIRST_VIEW:
      {
        if (isCamNumberAvailable)
        {
          firstFeedViewLable.set(camDisplayName.concat("1")); //$NON-NLS-1$
        }
        else
        {
          firstFeedViewLable.set(camDisplayName);
        }
        firstFeedCameraId.set(cameraViewButtonDO.getSelectedCameraId());
        firstFeedCarIndex.set(cameraViewButtonDO.getSelectedVehicleIndex());
        firstFeedAlarmViewLable.set(cameraName);
        firstFeedAlarmViewIcon.set(cameraViewButtonDO.getAlarmType().get());
        break;
      }

      case SECOND_VIEW:
      {
        if (isCamNumberAvailable)
        {
          secondFeedViewLable.set(camDisplayName.concat("2")); //$NON-NLS-1$
        }
        else
        {
          secondFeedViewLable.set(camDisplayName);
        }
        secondFeedCameraId.set(cameraViewButtonDO.getSelectedCameraId());
        secondFeedCarIndex.set(cameraViewButtonDO.getSelectedVehicleIndex());

        secondFeedAlarmViewLable.set(cameraName);
        secondFeedAlarmViewIcon.set(cameraViewButtonDO.getAlarmType().get());
        break;
      }

      case THIRD_VIEW:
      {
        if (isCamNumberAvailable)
        {
          thirdFeedViewLable.set(camDisplayName.concat("3")); //$NON-NLS-1$
        }
        else
        {
          thirdFeedViewLable.set(camDisplayName);
        }
        thirdFeedCameraId.set(cameraViewButtonDO.getSelectedCameraId());
        thirdFeedCarIndex.set(cameraViewButtonDO.getSelectedVehicleIndex());

        thirdFeedAlarmViewLable.set(cameraName);
        thirdFeedAlarmViewIcon.set(cameraViewButtonDO.getAlarmType().get());
        break;
      }

      case FOURTH_VIEW:
      {
        if (isCamNumberAvailable)
        {
          fourthFeedViewLable.set(camDisplayName.concat("4")); //$NON-NLS-1$
        }
        else
        {
          fourthFeedViewLable.set(camDisplayName);
        }
        fourthFeedCameraId.set(cameraViewButtonDO.getSelectedCameraId());
        fourthFeedCarIndex.set(cameraViewButtonDO.getSelectedVehicleIndex());

        fourthFeedAlarmViewLable.set(cameraName);
        fourthFeedAlarmViewIcon.set(cameraViewButtonDO.getAlarmType().get());
        break;
      }
      case SINGLE_FEED_VIEW:
        singleFeedViewLable.set(camDisplayName);
        firstFeedAlarmViewLable.set(cameraName);
        firstFeedAlarmViewIcon.set(cameraViewButtonDO.getAlarmType().get());
        break;
      default:
        break;
      }
    }
  }

  /**
   * Camera view button property.
   *
   * @return the list property
   */
  public ListProperty<CameraViewButtonDO> cameraViewButtonListProperty()
  {
    return cameraViewButtonsList;
  }

  public StringProperty getFirstFeedViewLable()
  {
    return firstFeedViewLable;
  }

  public StringProperty getSecondFeedViewLable()
  {
    return secondFeedViewLable;
  }

  public StringProperty getThirdFeedViewLable()
  {
    return thirdFeedViewLable;
  }

  public StringProperty getFourthFeedViewLable()
  {
    return fourthFeedViewLable;
  }

  public StringProperty getSingleFeedViewLable()
  {
    return singleFeedViewLable;
  }

  public IntegerProperty getSelectedExternalCameraType()
  {
    return selectedExternalCameraType;
  }

  public void setSelectedExternalCameraType(Integer selectedExternalCameraType)
  {
    this.selectedExternalCameraType.set(selectedExternalCameraType);
  }

  public IntegerProperty getAlarmTypeActive()
  {
    return alarmTypeActive;
  }

  public void setAlarmTypeActive(Integer alarmTypeActive)
  {
    this.alarmTypeActive.set(alarmTypeActive);
  }

  public StringProperty getCurrentLocation()
  {
    return currentLocation;
  }

  public void setCurrentLocation(byte[] currentLocation)
  {
    this.currentLocation.set(new String(currentLocation));
  }

  public StringProperty getNextLocation()
  {
    return nextLocation;
  }

  public void setNextLocation(byte[] nextLocation)
  {
    this.nextLocation.set(new String(nextLocation));
  }

  public IntegerProperty getFirstFeedCameraId()
  {
    return firstFeedCameraId;
  }

  public void setFirstFeedCameraId(Integer firstFeedCameraId)
  {
    this.firstFeedCameraId.set(firstFeedCameraId);
  }

  public IntegerProperty getSecondFeedCameraId()
  {
    return secondFeedCameraId;
  }

  public void setSecondFeedCameraId(Integer secondFeedCameraId)
  {
    this.secondFeedCameraId.set(secondFeedCameraId);
  }

  public IntegerProperty getThirdFeedCameraId()
  {
    return thirdFeedCameraId;
  }

  public void setThirdFeedCameraId(Integer thirdFeedCameraId)
  {
    this.thirdFeedCameraId.set(thirdFeedCameraId);
  }

  public IntegerProperty getFourthFeedCameraId()
  {
    return fourthFeedCameraId;
  }

  public void setFourthFeedCameraId(Integer fourthFeedCameraId)
  {
    this.fourthFeedCameraId.set(fourthFeedCameraId);
  }

  public IntegerProperty getFirstFeedCarIndex()
  {
    return firstFeedCarIndex;
  }

  public void setFirstFeedCarIndex(Integer firstFeedCarIndex)
  {
    this.firstFeedCarIndex.set(firstFeedCarIndex);
  }

  public IntegerProperty getSecondFeedCarIndex()
  {
    return secondFeedCarIndex;
  }

  public void setSecondFeedCarIndex(Integer secondFeedCarIndex)
  {
    this.secondFeedCarIndex.set(secondFeedCarIndex);
  }

  public IntegerProperty getThirdFeedCarIndex()
  {
    return thirdFeedCarIndex;
  }

  public void setThirdFeedCarIndex(Integer thirdFeedCarIndex)
  {
    this.thirdFeedCarIndex.set(thirdFeedCarIndex);
  }

  public IntegerProperty getFourthFeedCarIndex()
  {
    return fourthFeedCarIndex;
  }

  public void setFourthFeedCarIndex(Integer fourthFeedCarIndex)
  {
    this.fourthFeedCarIndex.set(fourthFeedCarIndex);
  }

  public void setAlarmFire(Integer alarmFire)
  {
    this.alarmFire.set(alarmFire);
  }

  public IntegerProperty getAlarmFire()
  {
    return alarmFire;
  }

  public void setAlarmObstacle(Integer newValue)
  {
    this.alarmObstacle.set(newValue);
  }

  public void setAlarmPecu(Integer newValue)
  {
    this.alarmPecu.set(newValue);
  }

  public void setAlarmDoorUnlock(Integer newValue)
  {
    this.alarmDoorUnlock.set(newValue);
  }

  public IntegerProperty getAlarmObstacle()
  {
    return alarmObstacle;
  }

  public IntegerProperty getAlarmPecu()
  {
    return alarmPecu;
  }

  public IntegerProperty getAlarmDoorUnlock()
  {
    return alarmDoorUnlock;
  }

  public void setAlarmEmergencyDoorOpen(Integer newValue)
  {
    this.alarmEmegencyDoorOpening.set(newValue);
  }

  public void setAlarmDriverDesk(Integer newValue)
  {
    this.alarmDriverDesk.set(newValue);
  }

  public void setAlarmObstructionDeflection(Integer newValue)
  {
    this.alarmObstructionDeflection.set(newValue);
  }

  public void setAlarmTrackEvent(Integer newValue)
  {
    this.alarmTrackEvent.set(newValue);
  }

  public IntegerProperty getAlarmEmegencyDoorOpening()
  {
    return alarmEmegencyDoorOpening;
  }

  public IntegerProperty getAlarmDriverDesk()
  {
    return alarmDriverDesk;
  }

  public IntegerProperty getAlarmObstructionDeflection()
  {
    return alarmObstructionDeflection;
  }

  public IntegerProperty getAlarmTrackEvent()
  {
    return alarmTrackEvent;
  }

  public void setAlarmEmergency(Integer newValue)
  {
    this.alarmEmergencyEvent.set(newValue);
  }

  public void setAlarmOheEvent(Integer newValue)
  {
    this.alarmOheEvent.set(newValue);
  }

  public void setAlarmPantographEvent(Integer newValue)
  {
    this.alarmPantographEvent.set(newValue);
  }

  public IntegerProperty getAlarmEmergencyEvent()
  {
    return alarmEmergencyEvent;
  }

  public IntegerProperty getAlarmOheEvent()
  {
    return alarmOheEvent;
  }

  public IntegerProperty getAlarmPantographEvent()
  {
    return alarmPantographEvent;
  }

  public StringProperty getLineDetail()
  {
    return lineDetail;
  }

  public void setLineDetail(byte[] lineDetail)
  {
    this.lineDetail.set(new String(lineDetail));
  }

  public IntegerProperty getCctvDisplayHangedFault()
  {
    return cctvDisplayHangedFault;
  }

  public void setCctvDisplayHangedFault(Integer cctvDisplayHangedFault)
  {
    this.cctvDisplayHangedFault.set(cctvDisplayHangedFault);
  }

  public IntegerProperty getDetrainmentDoorFault()
  {
    return detrainmentDoorFault;
  }

  public void setDetrainmentDoorFault(Integer detrainmentDoorFault)
  {
    this.detrainmentDoorFault.set(detrainmentDoorFault);
  }

  public void setSettingQuitButtonState(Integer newValue)
  {
    this.settingPanelQuitButton.set(newValue);

  }

  public IntegerProperty getSettingQuitButtonState()
  {
    return settingPanelQuitButton;
  }

  public void setSettingPanelState(Integer newValue)
  {
    this.settingPanelButton.set(newValue);

  }

  public IntegerProperty getSettingPanelState()
  {
    return settingPanelButton;
  }

  public void setNormalEventSwitchState(Integer newValue)
  {
    this.normalEvenetSwitch.set(newValue);

  }

  public IntegerProperty getNormalEventSwitchState()
  {
    return normalEvenetSwitch;
  }

  public void setDetraimentCameraId(Integer newValue)
  {
    this.detrailmentCameraId.set(newValue);

  }

  public IntegerProperty getDetraimentCameraId()
  {
    return detrailmentCameraId;
  }
}

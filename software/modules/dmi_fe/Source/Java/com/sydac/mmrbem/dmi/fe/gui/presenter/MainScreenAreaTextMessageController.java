package com.sydac.mmrbem.dmi.fe.gui.presenter;

import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

import com.sydac.mmrbem.cabscreens.fe.common.NodePseudoClassProperty;
import com.sydac.mmrbem.cabscreens.fe.utils.timer.CommsTimer;
import com.sydac.mmrbem.cbtc.common.protos.CBTCProtos.TextMessagePriority;
import com.sydac.mmrbem.dmi.common.protos.DMIProtos.TextMessages.AckState;
import com.sydac.mmrbem.dmi.common.state.DMIAckButtonStatus;
import com.sydac.mmrbem.dmi.common.state.DMIConstants;
import com.sydac.mmrbem.dmi.common.state.DMIHighPriorityPaneStatus;
import com.sydac.mmrbem.dmi.common.state.DMINewMessageStatus;
import com.sydac.mmrbem.dmi.common.state.DMITextMessaageDownButton;
import com.sydac.mmrbem.dmi.common.state.DMITextMessaageUpButton;
import com.sydac.mmrbem.dmi.fe.base.DMIFactory;
import com.sydac.mmrbem.dmi.fe.gui.AbstractDMIController;
import com.sydac.mmrbem.dmi.fe.gui.binder.MainScreenAreaCRightBinder;
import com.sydac.mmrbem.dmi.fe.gui.binder.MainScreenAreaTextMessageBinder;
import com.sydac.mmrbem.dmi.fe.gui.data.LowPriorityMsgTableTextCellFactory;
import com.sydac.mmrbem.dmi.fe.gui.data.TextMsgInfoDO;
import com.sydac.mmrbem.dmi.fe.gui.model.MainScreenAreaCRightModel;
import com.sydac.mmrbem.dmi.fe.gui.model.MainScreenAreaTextMessageModel;
import com.sydac.project.runtimedata.ProjectObjectConstants.DMIInputs;

import javafx.beans.property.ListProperty;
import javafx.beans.property.SimpleListProperty;
import javafx.beans.value.ChangeListener;
import javafx.collections.FXCollections;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TableColumn;
import javafx.scene.control.TableView;
import javafx.scene.control.cell.PropertyValueFactory;
import javafx.scene.layout.GridPane;

public class MainScreenAreaTextMessageController extends AbstractDMIController
{
  private static final int FLASH_EXECUTION_INTERVAL = 1000;

  private static final int FLASH_PAUSE_INTERVAL = 500;

  @FXML
  private GridPane mainGrid;

  @FXML
  private Label newMessageLabel;

  @FXML
  private TableView<TextMsgInfoDO> lowPriorityMsgTableView;

  @FXML
  private Button messageUpButton;

  @FXML
  private Button messageDownButton;

  @FXML
  private Button messageUpButton1;

  @FXML
  private Button messageDownButton1;

  @FXML
  private Button messageUpButton2;

  @FXML
  private Button messageDownButton2;

  @FXML
  private Button ackMessageButton;

  @FXML
  private Label highPriorityWithoutAckLabel;

  @FXML
  private Label highPriorityMsgWithAckLabel;

  @FXML
  private GridPane lowPriorityMessagePane;

  @FXML
  private GridPane highPriorityMessagePane;

  @FXML
  private GridPane highPriorityMessageWithAckPane;

  @FXML
  private GridPane highPriorityMessageWithAckChildPane;

  @FXML
  private GridPane noMessagePane;

  private MainScreenAreaTextMessageModel mainScreenAreaTextMessageModel;

  private ChangeListener<Boolean> upButtonListener;

  private ChangeListener<Boolean> downButtonListener;

  private ChangeListener<Boolean> newMsgLabelListener;

  private static final int CELL_HEIGHT = 33;

  private static final int COLUMN_WIDTH = 389;

  private static final int FIRST_COLUMN_WIDTH = 55;

  private long previousFlashTime;

  private ListProperty<TextMsgInfoDO> textMessageList = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  private MainScreenAreaCRightModel mainScreenAreaCRightModel;

  private CommsTimer highPriorityPaneTimer;

  private final static long STAY_TIME = 10000; // $NON-NLS-1$

  /** Runnable to perform show status screen */
  private Runnable highPriorityMessageRunnable = () -> {
    if (highPriorityPaneTimer != null)
    {
      highPriorityMessagePane.setVisible(false);
      lowPriorityMessagePane.setVisible(true);
      highPriorityPaneTimer.safeCancel();

    }
  };

  @Override
  public void initializeImpl()
  {

    AbstractDMIController.updateScaledPrefSize(mainGrid, mainGrid.getPrefWidth(), mainGrid.getPrefHeight());

    AbstractDMIController.updateScaledPrefSize(lowPriorityMsgTableView,
        lowPriorityMsgTableView.getPrefWidth(), lowPriorityMsgTableView.getPrefHeight());

    mainScreenAreaTextMessageModel = new MainScreenAreaTextMessageModel(scenarioCarIndex);
    dmiScreenBinders.add(new MainScreenAreaTextMessageBinder(mainScreenAreaTextMessageModel));

    mainScreenAreaCRightModel = new MainScreenAreaCRightModel(scenarioCarIndex);
    dmiScreenBinders.add(new MainScreenAreaCRightBinder(mainScreenAreaCRightModel));

    highPriorityPaneTimer = CommsTimer.newScheduledTimer(highPriorityMessageRunnable, STAY_TIME);

    ChangeListener<Number> flashLabelListener = (observable, oldVal,
        newVal) -> updateFlashLabel((long)newVal);
    mainScreenAreaCRightModel.getFlashTime().addListener(flashLabelListener);

    ChangeListener<List<TextMsgInfoDO>> newMessageListListener = (observable, oldVal,
        newVal) -> updateMessageList(mainScreenAreaTextMessageModel.getTextMessageList());
    mainScreenAreaTextMessageModel.getTextMessageList().addListener(newMessageListListener);

    upButtonListener = (observable, oldVal, newVal) -> updateUpButtonStatus(newVal);
    mainScreenAreaTextMessageModel.getUpButtonStatus().addListener(upButtonListener);

    downButtonListener = (observable, oldVal, newVal) -> updateDownButtonStatus(newVal);
    mainScreenAreaTextMessageModel.getDownButtonStatus().addListener(downButtonListener);

    newMsgLabelListener = (observable, oldVal, newVal) -> updateNewMessageStatus(newVal);
    mainScreenAreaTextMessageModel.getNewMessageIndicaton().addListener(newMsgLabelListener);

    updateMessageList(mainScreenAreaTextMessageModel.getTextMessageList());
    updateUpButtonStatus(mainScreenAreaTextMessageModel.getUpButtonStatus().get());
    updateDownButtonStatus(mainScreenAreaTextMessageModel.getDownButtonStatus().get());
    updateNewMessageStatus(mainScreenAreaTextMessageModel.getNewMessageIndicaton().get());
    // updateFlashLabel(mainScreenAreaCRightModel.getFlashTime().longValue());
  }

  private void updateFlashLabel(long flashTime)
  {

    if (flashTime - previousFlashTime > FLASH_EXECUTION_INTERVAL)
    {
      previousFlashTime = flashTime;
      highPriorityWithoutAckLabel.setStyle("-fx-border-width: 1.0px");

    }
    else if (flashTime - previousFlashTime > FLASH_PAUSE_INTERVAL)
    {
      highPriorityWithoutAckLabel.setStyle("-fx-border-width: 0.0px");

    }

  }

  private void updateNewMessageGridPane()
  {

    if (!textMessageList.isEmpty())
    {

      boolean isLowPriority = false;
      boolean isHighPriority = false;
      boolean isHighPriorityAck = false;

      TextMsgInfoDO firstMsg = textMessageList.get(0);

     

      if (firstMsg.getPriority().get() == TextMessagePriority.LOW_VALUE)
      {
        // if messages are low priority then this block will get executed

        setTableProperties(lowPriorityMsgTableView, CELL_HEIGHT * AbstractDMIController.HEIGHT_SCALE,
            textMessageList, FIRST_COLUMN_WIDTH, COLUMN_WIDTH * AbstractDMIController.WIDTH_SCALE);
        isLowPriority = true;
      }

      else if (firstMsg.getPriority().get() == TextMessagePriority.HIGH_VALUE
          && (firstMsg.getAckState().getNumber() == AckState.ACK_ENABLED_VALUE
              || firstMsg.getAckState().getNumber() == AckState.ACK_DISABLED_VALUE))
      {
        // if messages are high priority with acknowledgement then this block
        // will get executed

        setHighPriorityMessageWithAck(firstMsg.getDisplayText());

        // make high priority messages with acknowledgement gridPane visible and
        // others invisible
        isHighPriorityAck = true;
      }

      else if (firstMsg.getPriority().get() == TextMessagePriority.HIGH_VALUE
          && firstMsg.getAckState().getNumber() == AckState.NO_ACK_VALUE)
      {
        // if messages are high priority without acknowledgement then this block
        // will get executed

        setHighPriorityMessage(firstMsg.getDisplayText());

        // make high priority messages gridPane visible and others invisible
        isHighPriority = true;
      }

      // make low priority messages gridPane visible and others invisible
      lowPriorityMessagePane.setVisible(isLowPriority);
      highPriorityMessagePane.setVisible(isHighPriority);
      startTimerForHighPriorityMessage();

      highPriorityMessageWithAckPane.setVisible(isHighPriorityAck);
      noMessagePane.setVisible(false);
      updateAckButtonStatus(firstMsg.getAckState().getNumber());
      updateHighPriorityPaneStatus(firstMsg.getAckState().getNumber());
    }
    else
    {

      noMessagePane.setVisible(true);
    }
  }

  private void setHighPriorityMessageWithAck(String message)
  {
    highPriorityMsgWithAckLabel.setText(message);
  }

  private void setHighPriorityMessage(String message)
  {
    highPriorityWithoutAckLabel.setText(message);
  }

  private void updateMessageList(List<TextMsgInfoDO> msgList)
  {
  
    textMessageList.clear();
    textMessageList.addAll(msgList);
    updateNewMessageGridPane();
  }

  private void updateUpButtonStatus(Boolean newVal)
  {
    int upButtonStatus = newVal ? 1 : 0;
    // remove all the CSS
    messageUpButton.getStyleClass().removeAll(Arrays.asList(DMITextMessaageUpButton.values()).stream()
        .map(p -> p.getText()).collect(Collectors.toList()));

    messageUpButton.getStyleClass().add(DMITextMessaageUpButton.valueOf(upButtonStatus).getText());
  }

  private void updateDownButtonStatus(Boolean newVal)
  {
    int downButtonStatus = newVal ? 1 : 0;
    // remove all the CSS
    messageDownButton.getStyleClass().removeAll(Arrays.asList(DMITextMessaageDownButton.values()).stream()
        .map(p -> p.getText()).collect(Collectors.toList()));

    messageDownButton.getStyleClass().add(DMITextMessaageDownButton.valueOf(downButtonStatus).getText());
  }

  private void updateNewMessageStatus(Boolean newVal)
  {

    int status = newVal ? 1 : 0;
    // remove all the CSS
    newMessageLabel.getStyleClass().removeAll(Arrays.asList(DMINewMessageStatus.values()).stream()
        .map(p -> p.getText()).collect(Collectors.toList()));
   

    newMessageLabel.getStyleClass().add(DMINewMessageStatus.valueOf(status).getText());
  }

  private void updateAckButtonStatus(int newVal)
  {
    // remove all the CSS
    ackMessageButton.getStyleClass().removeAll(Arrays.asList(DMIAckButtonStatus.values()).stream()
        .map(p -> p.getText()).collect(Collectors.toList()));

    ackMessageButton.getStyleClass().add(DMIAckButtonStatus.valueOf(newVal).getText());
  }

  private void updateHighPriorityPaneStatus(int newVal)
  {
    // remove all the CSS
    highPriorityMessageWithAckChildPane.getStyleClass()
        .removeAll(Arrays.asList(DMIHighPriorityPaneStatus.values()).stream().map(p -> p.getText())
            .collect(Collectors.toList()));

    if (newVal > 1)
    {
      highPriorityMessageWithAckChildPane.getStyleClass()
          .add(DMIHighPriorityPaneStatus.valueOf(newVal).getText());

    }
  }

  private void setTableProperties(TableView<TextMsgInfoDO> lowPriorityMsgListTable, double cellHeight,
      ListProperty<TextMsgInfoDO> listProperty, double firstColumnWidth, double columnWidth)
  {

    lowPriorityMsgListTable.getSelectionModel().setCellSelectionEnabled(false);

    if (!listProperty.isEmpty())
    {
      lowPriorityMsgListTable.getSelectionModel().clearAndSelect(0);
    }

    lowPriorityMsgListTable.getColumns().add(getFirstColumn(firstColumnWidth));
    lowPriorityMsgListTable.getColumns().add(getTextColumn(columnWidth));
    lowPriorityMsgListTable.setItems(listProperty);
    lowPriorityMsgListTable.getStyleClass().add("noheader");

  }

  private TableColumn<TextMsgInfoDO, Object> getTextColumn(double width)
  {
    TableColumn<TextMsgInfoDO, Object> secondCol = new TableColumn<>();
    secondCol.setCellValueFactory(new PropertyValueFactory<>("displayText")); //$NON-NLS-1$
    secondCol.setCellFactory(tableColumn -> new LowPriorityMsgTableTextCellFactory());
    secondCol.setSortable(false);
    secondCol.setResizable(false);
    secondCol.setPrefWidth(width);
    return secondCol;
  }

  private TableColumn<TextMsgInfoDO, Object> getFirstColumn(double width)
  {
    TableColumn<TextMsgInfoDO, Object> firstCol = new TableColumn<>();
    firstCol.setCellValueFactory(new PropertyValueFactory<>("hourAndMinuteTimestamp")); //$NON-NLS-1$
    firstCol.setCellFactory(tableColumn -> new LowPriorityMsgTableTextCellFactory());
    firstCol.setSortable(false);
    firstCol.setResizable(false);
    firstCol.setPrefWidth(width);
    return firstCol;
  }

  @FXML
  void onUpButtonAction(ActionEvent event)
  {
    if (mainScreenAreaTextMessageModel.getUpButtonStatus().get())
    {
      DMIFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendButtonClickRequest(DMIInputs.TEXT_MESSAGE_UP_BUTTON_REQUEST);
    }
  }

  @FXML
  void onDownButonAction(ActionEvent event)
  {
    if (mainScreenAreaTextMessageModel.getDownButtonStatus().get())
    {
      DMIFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendButtonClickRequest(DMIInputs.TEXT_MESSAGE_DOWN_BUTTON_REQUEST);
    }
  }

  @FXML
  void onAckMessageAction(ActionEvent event)
  {
    if (!textMessageList.isEmpty())
    {
      TextMsgInfoDO firstMsg = textMessageList.get(0);

      if (firstMsg.getAckState().getNumber() == AckState.ACK_ENABLED_VALUE)
      {
        DMIFactory.getServiceRequestHandler(scenarioCarIndex)
            .sendRequest(DMIInputs.TEXT_MESSAGE_ACKNOWLEDGE_REQUEST, firstMsg.getUniqueId().get());
      }
    }
  }

  @Override
  public void detachListeners()
  {
    mainScreenAreaTextMessageModel.getDownButtonStatus().removeListener(downButtonListener);
    mainScreenAreaTextMessageModel.getUpButtonStatus().removeListener(upButtonListener);
    mainScreenAreaTextMessageModel.getNewMessageIndicaton().removeListener(newMsgLabelListener);
  }

  private void startTimerForHighPriorityMessage()
  {
    if (!highPriorityPaneTimer.isRunning())
    {
      highPriorityPaneTimer.start();

    }
  }
}

/*
 * ================================================================== (C)
 * Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.radio.fe.gui.presenter;

import static com.sydac.project.runtimedata.ProjectObjectConstants.RadioInputs.INBOX_MSG_LIST_SELECTED_ID;

import com.sydac.mmrbem.radio.common.data.MessageTableDO;
import com.sydac.mmrbem.radio.common.state.ApplicationConstants;
import com.sydac.mmrbem.radio.fe.base.RadioFactory;
import com.sydac.mmrbem.radio.fe.gui.AbstractRadioController;
import com.sydac.mmrbem.radio.fe.gui.binder.MessageScreenBinder;
import com.sydac.mmrbem.radio.fe.gui.data.MessageTableTextCellFactory;
import com.sydac.mmrbem.radio.fe.gui.model.MessageScreenModel;

import javafx.application.Platform;
import javafx.beans.property.ListProperty;
import javafx.beans.value.ChangeListener;
import javafx.beans.value.ObservableValue;
import javafx.collections.ObservableList;
import javafx.fxml.FXML;
import javafx.geometry.Insets;
import javafx.scene.control.Button;
import javafx.scene.control.TableColumn;
import javafx.scene.control.TableView;
import javafx.scene.control.cell.PropertyValueFactory;
import javafx.scene.layout.Pane;

public class MessageInBoxListController extends AbstractRadioController
{

  @FXML
  private TableView<MessageTableDO> messageTabel;

  @FXML
  private Button leftButton;

  @FXML
  private Button upButton;

  @FXML
  private Button rightButton;

  @FXML
  private Button downButton;

  private MessageScreenModel messageScreenModel;

  private static final double CELL_HEIGHT = 40.0;

  private static final double MESSAGE_TEXT_WIDTH = 350;

  private static final double MESSAGE_ID_WIDTH = 100;

  private static final double MESSAGE_DATE_TIME_WIDTH = 100;

  private ChangeListener<? super ObservableList<MessageTableDO>> messageListListener;

  private ChangeListener<Number> selectedMessageIdListener;



  @Override
  public void detachListeners()
  {
    messageScreenModel.getInBoxMessageList().removeListener(messageListListener);
    messageScreenModel.getSelectedInBoxMessageId().removeListener(selectedMessageIdListener);
  }

  @Override
  public void initializeImpl()
  {
    messageScreenModel = new MessageScreenModel(scenarioCarIndex);
    radioScreenBinders.add(new MessageScreenBinder(scenarioCarIndex, messageScreenModel));
    setTableProperties(messageScreenModel.getInBoxMessageList());

    messageListListener = ((observable, oldVal,
        newVal) -> updateScreenSelectedMessageCode(messageScreenModel.getSelectedInBoxMessageId().get()));
    messageScreenModel.getInBoxMessageList().addListener(messageListListener);

    selectedMessageIdListener = ((observable, oldVal,
        newVal) -> updateScreenSelectedMessageCode(messageScreenModel.getSelectedInBoxMessageId().get()));
    messageScreenModel.getSelectedInBoxMessageId().addListener(selectedMessageIdListener);

    updateScreenSelectedMessageCode(messageScreenModel.getSelectedInBoxMessageId().get());
  }

  private void updateScreenSelectedMessageCode(Number newVal)
  {

    MessageTableDO message = messageScreenModel.getInBoxMessageList().stream()
        .filter(s -> s.getMsgId() == newVal.intValue()).findFirst().orElse(null);

    if (message != null)
    {

      RadioFactory.getServiceRequestHandler(scenarioCarIndex).sendRequest(INBOX_MSG_LIST_SELECTED_ID,
          message.getMsgId());

      highLightSelectedMessage(message);

    }

  }

  private void highLightSelectedMessage(MessageTableDO message)
  {

    int index = message == null ? -1 : messageScreenModel.getInBoxMessageList().indexOf(message);

    if (index != -1 && !messageTabel.getItems().isEmpty() && messageTabel.getItems().size() >= index)
    {
      Platform.runLater(() -> {
        messageTabel.getSelectionModel().select(index);
      });
    }
  }

  private void setTableProperties(ListProperty<MessageTableDO> messageList)
  {

    messageTabel.setFixedCellSize(CELL_HEIGHT);

    messageTabel.getSelectionModel().setCellSelectionEnabled(false);
    messageTabel.getSelectionModel().clearAndSelect(0);
    messageTabel.setPadding(new Insets(0, 0, 0, 0));

    messageTabel.widthProperty().addListener((source, oldWidth, newWidth) -> {
      Pane header = (Pane)messageTabel.lookup("TableHeaderRow"); //$NON-NLS-1$
      if (header.isVisible())
      {
        header.setMaxHeight(0);
        header.setMinHeight(0);
        header.setPrefHeight(0);
        header.setVisible(false);
      }
    });

    messageTabel.getColumns().add(getColumn("msgId", MESSAGE_ID_WIDTH));
    messageTabel.getColumns().add(getColumn("msgText", MESSAGE_TEXT_WIDTH));
    messageTabel.getColumns().add(getColumn("dateTime", MESSAGE_DATE_TIME_WIDTH));

    messageTabel.setColumnResizePolicy(TableView.CONSTRAINED_RESIZE_POLICY);

    messageTabel.setItems(messageList);

    messageTabel.getSelectionModel().selectedIndexProperty()
        .addListener(new RowChangeHandler(messageTabel, messageList));

  }

  private class RowChangeHandler implements ChangeListener<Object>
  {
    private ListProperty<MessageTableDO> messageList;

    private TableView<MessageTableDO> messageTabel;

    public RowChangeHandler(TableView<MessageTableDO> messageTabel, ListProperty<MessageTableDO> messageList)
    {
      this.messageTabel = messageTabel;
      this.messageList = messageList;
    }

    @Override
    public void changed(ObservableValue<?> ov, Object oldVal, Object newVal)
    {

      int selectedRow = messageTabel.getSelectionModel().getSelectedIndex();

      if (selectedRow == -1)
      {
        return;
      }

      Platform.runLater(() -> {

        messageTabel.requestFocus();
        messageTabel.getSelectionModel().select(selectedRow);
        messageTabel.getFocusModel().focus(selectedRow);
        if (selectedRow > ApplicationConstants.MAX_VISIBLE)
        {
          messageTabel.scrollTo(selectedRow - ApplicationConstants.MAX_VISIBLE);

        }
        else
        {
          messageTabel.scrollTo(0);
        }
      });
      messageScreenModel.setSelectedInboxMessageId(messageList.get((int)newVal).getMsgId());

    }
  }

  private TableColumn<MessageTableDO, Object> getColumn(String columnName, double width)
  {
    TableColumn<MessageTableDO, Object> column = new TableColumn<>();
    column.setCellValueFactory(new PropertyValueFactory<>(columnName)); // $NON-NLS-1$
    column.setCellFactory(tableColumn -> new MessageTableTextCellFactory<MessageTableDO, Object>(columnName));
    column.setPrefWidth(width);
    column.setMinWidth(width);
    column.setMaxWidth(width);
    column.setSortable(false);
    column.setResizable(false);
    return column;

  }

}

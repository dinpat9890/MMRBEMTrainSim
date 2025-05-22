/*
 * ================================================================== (C)
 * Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.radio.fe.gui.presenter;

import static com.sydac.project.runtimedata.ProjectObjectConstants.RadioInputs.CONTACTS_BTN_REQUEST;
import static com.sydac.project.runtimedata.ProjectObjectConstants.RadioInputs.GROUP_LIST_BTN_REQUEST;
import static com.sydac.project.runtimedata.ProjectObjectConstants.RadioInputs.SELECTED_CONTACT_LIST_ID;

import com.sydac.mmrbem.cabscreens.fe.common.NodePseudoClassProperty;
import com.sydac.mmrbem.radio.common.data.ContactDO;
import com.sydac.mmrbem.radio.common.state.ApplicationConstants;
import com.sydac.mmrbem.radio.fe.base.RadioFactory;
import com.sydac.mmrbem.radio.fe.gui.AbstractRadioController;
import com.sydac.mmrbem.radio.fe.gui.binder.ContactsScreenBinder;
import com.sydac.mmrbem.radio.fe.gui.data.ContactTableTextCellFactory;
import com.sydac.mmrbem.radio.fe.gui.model.ContactsScreenModel;

import javafx.application.Platform;
import javafx.beans.property.ListProperty;
import javafx.beans.value.ChangeListener;
import javafx.beans.value.ObservableValue;
import javafx.collections.ObservableList;
import javafx.fxml.FXML;
import javafx.geometry.Insets;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TableColumn;
import javafx.scene.control.TableView;
import javafx.scene.control.cell.PropertyValueFactory;
import javafx.scene.input.MouseEvent;
import javafx.scene.input.TouchEvent;
import javafx.scene.layout.Pane;

public class ContactsScreenController extends AbstractRadioController
{

  @FXML
  private TableView<ContactDO> contactTable;

  @FXML
  private Button diagnosticBtn;

  @FXML
  private Button contactsBtn;

  @FXML
  private Button callHistoryBtn;

  @FXML
  private Button biteReportBtn;

  @FXML
  private Button groupListBtn;

  @FXML
  private Button modesBtn;

  @FXML
  private Label nameLbl;

  @FXML
  private Label numberLbl;

  private ContactsScreenModel contactListModel;

  private static final double CELL_HEIGHT = 35.6;

  private static final double CONTACT_TEXT_WIDTH = 350;

  private static final double CONTACT_ID_WIDTH = 200;

  private ChangeListener<? super ObservableList<ContactDO>> contactListListener;

  private ChangeListener<Number> selectedContactIdListener;

  private NodePseudoClassProperty contactsBtnProperty;

  private NodePseudoClassProperty groupListBtnProperty;

  private ChangeListener<Number> selectedBtnIdListener;

  private NodePseudoClassProperty diagnosticBtnProperty;

  private NodePseudoClassProperty callHistoryBtnProperty;

  private NodePseudoClassProperty biteReportBtnProperty;

  private NodePseudoClassProperty modesBtnProperty;

  private int maxRowsVisible = 6;

  @Override
  public void detachListeners()
  {
    contactListModel.getContactList().removeListener(contactListListener);
    contactListModel.getSelectedContactId().removeListener(selectedContactIdListener);
    contactListModel.getSelectedBtnId().removeListener(selectedBtnIdListener);

  }

  @Override
  public void initializeImpl()
  {
    contactListModel = new ContactsScreenModel(scenarioCarIndex);
    radioScreenBinders.add(new ContactsScreenBinder(contactListModel));

    contactsBtnProperty = new NodePseudoClassProperty(contactsBtn);
    groupListBtnProperty = new NodePseudoClassProperty(groupListBtn);

    diagnosticBtnProperty = new NodePseudoClassProperty(diagnosticBtn);

    callHistoryBtnProperty = new NodePseudoClassProperty(callHistoryBtn);
    biteReportBtnProperty = new NodePseudoClassProperty(biteReportBtn);

    modesBtnProperty = new NodePseudoClassProperty(modesBtn);

    diagnosticBtnProperty.set(ApplicationConstants.UNSELECTED_CSS);
    callHistoryBtnProperty.set(ApplicationConstants.UNSELECTED_CSS);
    biteReportBtnProperty.set(ApplicationConstants.UNSELECTED_CSS);
    modesBtnProperty.set(ApplicationConstants.UNSELECTED_CSS);

    selectedBtnIdListener = ((observable, oldVal,
        newVal) -> updateSelectedBtn(contactListModel.getSelectedBtnId().get()));
    contactListModel.getSelectedBtnId().addListener(selectedBtnIdListener);

    setTableProperties(contactListModel.getContactList());

    contactListListener = ((observable, oldVal, newVal) -> updateContactList());
    contactListModel.getContactList().addListener(contactListListener);

    selectedContactIdListener = ((observable, oldVal,
        newVal) -> updateScreenSelectedContact(contactListModel.getSelectedContactId().get()));
    contactListModel.getSelectedContactId().addListener(selectedContactIdListener);
    updateScreenSelectedContact(contactListModel.getSelectedContactId().get());
  }

  private void updateContactList()
  {
    if (contactListModel.getContactList().getSize() > 0)
    {
      updateScreenSelectedContact(contactListModel.getContactList().get(0).getContactId());
    }
  }

  private void updateSelectedBtn(int buttonId)
  {

    String diagnosticBtnState = buttonId == ApplicationConstants.DIAGNOSTIC_BTN
        ? ApplicationConstants.SELECTED_CSS
        : ApplicationConstants.UNSELECTED_CSS;

    String contactsBtnState = buttonId == ApplicationConstants.CONTACT_BTN ? ApplicationConstants.SELECTED_CSS
        : ApplicationConstants.UNSELECTED_CSS;

    String callHistoryBtnState = buttonId == ApplicationConstants.CALLHISTORY_BTN
        ? ApplicationConstants.SELECTED_CSS
        : ApplicationConstants.UNSELECTED_CSS;

    String biteBtnState = buttonId == ApplicationConstants.BITE_BTN ? ApplicationConstants.SELECTED_CSS
        : ApplicationConstants.UNSELECTED_CSS;

    String groupListBtnState = buttonId == ApplicationConstants.GROUP_BTN ? ApplicationConstants.SELECTED_CSS
        : ApplicationConstants.UNSELECTED_CSS;
    String modeBtnState = buttonId == ApplicationConstants.MODES_BTN ? ApplicationConstants.SELECTED_CSS
        : ApplicationConstants.UNSELECTED_CSS;

    diagnosticBtnProperty.set(diagnosticBtnState);
    contactsBtnProperty.set(contactsBtnState);
    callHistoryBtnProperty.set(callHistoryBtnState);
    biteReportBtnProperty.set(biteBtnState);
    groupListBtnProperty.set(groupListBtnState);

    modesBtnProperty.set(modeBtnState);

    if (buttonId == ApplicationConstants.CONTACT_BTN || buttonId == ApplicationConstants.GROUP_BTN)
    {
      contactTable.setVisible(true);
      nameLbl.setVisible(true);
      numberLbl.setVisible(true);

    }
    else
    {
      contactTable.setVisible(false);
      nameLbl.setVisible(false);
      numberLbl.setVisible(false);
    }

  }

  private void updateScreenSelectedContact(Number newVal)
  {
    ContactDO message = contactListModel.getContactList().stream()
        .filter(s -> s.getContactId() == newVal.intValue()).findFirst().orElse(null);
    if (message != null)
    {
      RadioFactory.getServiceRequestHandler(scenarioCarIndex).sendRequest(SELECTED_CONTACT_LIST_ID,
          message.getContactId());

      highLightSelectedMessage(message);
    }

  }

  private void highLightSelectedMessage(ContactDO message)
  {
    int index = message == null ? -1 : contactListModel.getContactList().indexOf(message);

    if (index != -1 && !contactTable.getItems().isEmpty() && contactTable.getItems().size() >= index)
    {
      Platform.runLater(() -> contactTable.getSelectionModel().select(index));
    }
  }

  private void setTableProperties(ListProperty<ContactDO> contactList)
  {

    contactTable.setFixedCellSize(CELL_HEIGHT);

    contactTable.getSelectionModel().setCellSelectionEnabled(false);
    contactTable.getSelectionModel().clearAndSelect(0);
    contactTable.setPadding(new Insets(0, 0, 0, 0));

    contactTable.widthProperty().addListener((source, oldWidth, newWidth) -> {
      Pane header = (Pane)contactTable.lookup("TableHeaderRow"); //$NON-NLS-1$
      if (header.isVisible())
      {
        header.setMaxHeight(0);
        header.setMinHeight(0);
        header.setPrefHeight(0);
        header.setVisible(false);
      }
    });

    contactTable.getColumns().add(getColumn("contactText", CONTACT_TEXT_WIDTH)); //$NON-NLS-1$
    contactTable.getColumns().add(getColumn("contactId", CONTACT_ID_WIDTH)); //$NON-NLS-1$

    contactTable.setColumnResizePolicy(TableView.CONSTRAINED_RESIZE_POLICY);

    contactTable.setItems(contactList);

    contactTable.getSelectionModel().selectedIndexProperty()
        .addListener(new RowChangeHandler(contactTable, contactList));

  }

  private class RowChangeHandler implements ChangeListener<Object>
  {
    private ListProperty<ContactDO> contactList;

    private TableView<ContactDO> contactsTable;

    public RowChangeHandler(TableView<ContactDO> contactTable, ListProperty<ContactDO> contactList)
    {
      this.contactsTable = contactTable;
      this.contactList = contactList;
    }

    @Override
    public void changed(ObservableValue<?> ov, Object oldVal, Object newVal)
    {

      int selectedRow = contactsTable.getSelectionModel().getSelectedIndex();

      if (selectedRow == -1)
      {
        return;
      }

      Platform.runLater(() -> {

        contactsTable.requestFocus();
        contactsTable.getSelectionModel().select(selectedRow);
        contactsTable.getFocusModel().focus(selectedRow);
        if (selectedRow > maxRowsVisible)
        {

          contactsTable.scrollTo(selectedRow - maxRowsVisible);
        }
        else
        {
          contactsTable.scrollTo(0);
        }
      });
      contactListModel.setSelectedContactId(contactList.get((int)newVal).getContactId());

    }
  }

  private TableColumn<ContactDO, Object> getColumn(String columnName, double width)
  {
    TableColumn<ContactDO, Object> column = new TableColumn<>();
    column.setCellValueFactory(new PropertyValueFactory<>(columnName));
    column.setCellFactory(tableColumn -> new ContactTableTextCellFactory<ContactDO, Object>(columnName));
    column.setPrefWidth(width);
    column.setMinWidth(width);
    column.setMaxWidth(width);
    column.setSortable(false);
    column.setResizable(false);
    return column;

  }

  @FXML
  void onContactsMousePressedAction(MouseEvent event)
  {
    if (!ApplicationConstants.IS_TOUCH_ENABLED)
    {
      setButtonState(CONTACTS_BTN_REQUEST);
    }
  }

  @FXML
  void onContactsMouseReleasedAction(MouseEvent event)
  {
    if (!ApplicationConstants.IS_TOUCH_ENABLED)
    {
      resetButtonState(CONTACTS_BTN_REQUEST);
    }
  }

  @FXML
  void onContactsTouchPressedAction(TouchEvent event)
  {
    if (!ApplicationConstants.IS_TOUCH_ENABLED)
    {
      setButtonState(CONTACTS_BTN_REQUEST);
    }
  }

  @FXML
  void onContactsTouchReleasedAction(TouchEvent event)
  {
    if (!ApplicationConstants.IS_TOUCH_ENABLED)
    {
      resetButtonState(CONTACTS_BTN_REQUEST);
    }
  }

  @FXML
  void onGroupListMousePressedAction(MouseEvent event)
  {
    if (!ApplicationConstants.IS_TOUCH_ENABLED)
    {
      setButtonState(GROUP_LIST_BTN_REQUEST);
    }
  }

  @FXML
  void onGroupListMouseReleasedAction(MouseEvent event)
  {
    if (!ApplicationConstants.IS_TOUCH_ENABLED)
    {
      resetButtonState(GROUP_LIST_BTN_REQUEST);
    }
  }

  @FXML
  void onGroupListTouchPressedAction(TouchEvent event)
  {
    if (!ApplicationConstants.IS_TOUCH_ENABLED)
    {
      setButtonState(GROUP_LIST_BTN_REQUEST);
    }
  }

  @FXML
  void onGroupListTouchReleasedAction(TouchEvent event)
  {
    if (!ApplicationConstants.IS_TOUCH_ENABLED)
    {
      resetButtonState(GROUP_LIST_BTN_REQUEST);
    }
  }

  private void resetButtonState(String key)
  {

    RadioFactory.getServiceRequestHandler(scenarioCarIndex).sendRequest(key,
        ApplicationConstants.RESET_VALUE);

  }

  private void setButtonState(String key)
  {
    RadioFactory.getServiceRequestHandler(scenarioCarIndex).sendRequest(key, ApplicationConstants.SET_VALUE);

  }

}

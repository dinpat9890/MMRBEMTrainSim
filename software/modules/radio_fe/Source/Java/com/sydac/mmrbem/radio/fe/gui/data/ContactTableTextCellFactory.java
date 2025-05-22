/*
 * ==================================================================
 * 
 * (C) Copyright 2020 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.radio.fe.gui.data;

import java.text.SimpleDateFormat;
import java.util.Date;

import com.sydac.mmrbem.radio.common.data.ContactDO;

import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.control.TableCell;
import javafx.scene.control.TableRow;

/**
 * Table cell factory to handle String type data
 * 
 * @author ext-tambet
 *
 */
public class ContactTableTextCellFactory<S, T> extends TableCell<S, T>
{
  private String columnName;

  public ContactTableTextCellFactory(String columnName)
  {
    this.columnName = columnName;
  }

  @SuppressWarnings("unchecked")
  @Override
  protected void updateItem(Object item, boolean empty)
  {
    super.updateItem((T)item, empty);

    this.setWrapText(true);

    this.setAlignment(Pos.CENTER);

    TableRow<T> currentRow = getTableRow();

    if ("level".equals(columnName))
    {
      setMessageRowStyle(item, currentRow);
    }

    updateEventRow(item, empty);

  }

  private void setMessageRowStyle(Object item, TableRow<T> currentRow)
  {

    if (currentRow.getItem() == null || ((ContactDO)currentRow.getItem()).getContactId() == -1)
    {
      currentRow.setDisable(true);
      return;
    }
    else
    {
      currentRow.setDisable(false);
    }

    if (item != null)
    {

      String rowStyle = "";// history event and minor fault
      /*
       * if (isCurrentEvent &&
       * !getTableView().getSelectionModel().getSelectedItems().contains(
       * getTableRow().getItem())) {
       * 
       * if (String.valueOf(FaultCatagory.MAJOR_FAULT.getValue()).equals(String.
       * valueOf(item))) { rowStyle = "-fx-background-color: -fx-red-color;"; }
       * else if
       * (String.valueOf(FaultCatagory.MEDIUM_FAULT.getValue()).equals(String.
       * valueOf(item))) { rowStyle = "-fx-background-color: -fx-yellow-color;";
       * }
       * 
       * }
       */

      currentRow.setStyle(rowStyle);

    }

  }

  private void updateEventRow(Object item, boolean empty)
  {
    this.setPadding(new Insets(0, 0, 0, 0));
    setText(empty ? "" : String.valueOf(item));
  }

  public String convertTime(long time)
  {
    Date date = new Date(time);
    SimpleDateFormat format = new SimpleDateFormat("dd/MM/yyyy  HH:mm:ss");
    return format.format(date);
  }

}

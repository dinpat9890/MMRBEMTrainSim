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

import javafx.geometry.Pos;
import javafx.scene.control.TableCell;

/**
 * Table cell factory to handle String type data
 * 
 * @author ext-tambet
 *
 */
public class MessageTableTextCellFactory<S, T> extends TableCell<S, T>
{
  private String columnName;

  public MessageTableTextCellFactory(String columnName)
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

    if ("dateTime".equals(columnName))
    {
      setText(empty ? "" : convertTime((long)item));
    }
    else
    {
      setText(empty ? "" : String.valueOf(item));
    }

  }

  public String convertTime(long time)
  {
    Date date = new Date(time);
    SimpleDateFormat format = new SimpleDateFormat("dd/MM/yyyy");
    return format.format(date);
  }

}

/*
 * ==================================================================
 * 
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.tcms.fe.gui.data;

import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.control.TableCell;
import javafx.scene.control.TableRow;

/**
 * Table cell factory to handle String type data
 * 
 * @author ext-savanjin
 *
 */
public class LowPriorityMsgTableTextCellFactory extends TableCell<TextMsgInfoDO, Object>
{
  @SuppressWarnings("unchecked")
  @Override
  protected void updateItem(Object item, boolean empty)
  {
    super.updateItem(item, empty);

    setText(empty ? "" : String.valueOf(item)); //$NON-NLS-1$

    TableRow<TextMsgInfoDO> currentRow = getTableRow();

    currentRow.setPadding(new Insets(0, 0, 0, 0));

    currentRow.setAlignment(Pos.CENTER);

  }

}

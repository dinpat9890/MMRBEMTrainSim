package com.sydac.mmrbem.tcms.fe.gui.data;

import java.text.SimpleDateFormat;
import java.util.Date;

import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.control.TableCell;
import javafx.scene.control.TableRow;

public class TextTableTextCellFactory<S, T> extends TableCell<S, T>
{
  private String columnName;

  private boolean isCurrentEvent;

  public TextTableTextCellFactory(String columnName)
  {
    this.columnName = columnName;
  }

  public TextTableTextCellFactory(String columnName, boolean isCurrentEvent)
  {
    this.columnName = columnName;
    this.isCurrentEvent = isCurrentEvent;
  }

  @SuppressWarnings("unchecked")
  @Override
  protected void updateItem(Object item, boolean empty)
  {
    super.updateItem((T)item, empty);

    this.setWrapText(true);

    this.setAlignment(Pos.CENTER);

    TableRow<T> currentRow = getTableRow();

    setEventRowStyle(item, currentRow);
    updateEventRow(item, empty);

  }

  private void setEventRowStyle(Object item, TableRow<T> currentRow)
  {

    if (item != null)
    {

      // String rowStyle = "";// history event and minor fault
      // rowStyle = "-fx-background-color: red;";
      // currentRow.setStyle(rowStyle);

      currentRow.getStyleClass().clear();

    }

  }

  private void updateEventRow(Object item, boolean empty)
  {

    if (isCurrentEvent)
    {
      this.setPadding(new Insets(0, 16, 0, 16));
    }
    else
    {
      this.setPadding(new Insets(0, 4, 0, 4));
    }

    setText(empty ? "" : String.valueOf(item));
  }

  public String convertTime(long time)
  {
    Date date = new Date(time);
    SimpleDateFormat format = new SimpleDateFormat("dd/MM/yyyy  HH:mm:ss");
    return format.format(date);
  }
}

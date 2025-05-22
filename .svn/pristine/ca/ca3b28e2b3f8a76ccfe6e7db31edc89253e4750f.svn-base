
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

import com.sydac.common.log.Tracer;
import com.sydac.gui.control.NodePseudoClassProperty;

import javafx.css.PseudoClass;
import javafx.geometry.Pos;
import javafx.scene.control.Label;
import javafx.scene.control.TableCell;
import javafx.scene.control.TableColumn;
import javafx.scene.control.TableView;
import javafx.scene.layout.HBox;
import javafx.scene.layout.Pane;
import javafx.util.Callback;

public class TableDataRenderer
{
  private final Tracer LOGGER = Tracer.getInstance();

  private TableView<StatusTableDO> statusTable;

  private final double firstColumnWidth;

  private final double carDataColumnWidth;

  private final double cellHeight;

  private static final String FIRST_COLUMN_PROPERTY_VALUE = "rowName"; //$NON-NLS-1$

  private final PseudoClass firstColumnAlignment;

  private static final String TABLE_CELL_LABLE = "status-table-label"; //$NON-NLS-1$

  private static final String CELL_SEPARATOR = "table-cell-box-separator"; //$NON-NLS-1$

  private int maxCars;

  // Instantiates a new table data renderer.
  public TableDataRenderer(TableView<StatusTableDO> statusTable, int aMaxCars, int cellHight,
      int firstColumnWidth, int columnWidth)
  {
    this(statusTable, aMaxCars, cellHight, firstColumnWidth, columnWidth, "center_left"); //$NON-NLS-1$
  }

  // With extra Parameter to set First Column text alignment. Instantiates a new
  // table data renderer.
  public TableDataRenderer(TableView<StatusTableDO> statusTable, int aMaxCars, int cellHight,
      int firstColumnWidth, int columnWidth, String firstColumAlignmentCSSValue)
  {
    this.firstColumnAlignment = PseudoClass.getPseudoClass(firstColumAlignmentCSSValue);
    this.statusTable = statusTable;
    this.maxCars = aMaxCars;
    this.cellHeight = cellHight;
    this.firstColumnWidth = firstColumnWidth;
    this.carDataColumnWidth = columnWidth;

    createStatusTable();
  }

  /**
   * Creates the status table for different screens with specified number of
   * columns. Boolean property is used for screens where we need to split the
   * row into total number of units. Width of column is managed based on the
   * total columns and boolean values.
   */
  private void createStatusTable()
  {
    double columnWidth = carDataColumnWidth;

    for (int column = 0; column < maxCars; column++)
    {
      TableColumn<StatusTableDO, String> carDataColumn = new TableColumn<>();
      carDataColumn.setCellFactory(new CellUpdateFactory(column));

      carDataColumn.setPrefWidth(columnWidth);
      statusTable.getColumns().add(carDataColumn);
    }

    setTableProperties();
  }

  /**
   * Sets the table properties.
   */
  private void setTableProperties()
  {
    statusTable.setFixedCellSize(cellHeight);
    statusTable.setPrefHeight(statusTable.getItems().size() * cellHeight);
    statusTable.getSelectionModel().select(0);
    statusTable.setPrefWidth((carDataColumnWidth * maxCars));
    statusTable.widthProperty().addListener((source, oldWidth, newWidth) -> {
      Pane header = (Pane)statusTable.lookup("TableHeaderRow"); //$NON-NLS-1$
      if (header.isVisible())
      {
        header.setMaxHeight(0);
        header.setMinHeight(0);
        header.setPrefHeight(0);
        header.setVisible(false);
      }
    });
  }

  /**
   * Gets the custom cell factory for first and last column. Takes care of first
   * column alternate row colors which is different than other columns and
   * aligning data in last column.
   *
   * @param alignmentClass
   *          the alignment class
   * @param styleClass
   *          the style class
   * @return the custom cell factory
   */
  private Callback<TableColumn<StatusTableDO, String>, TableCell<StatusTableDO, String>> getCustomCellFactory(
      PseudoClass alignmentClass)
  {
    // Create a customer cell factory so that cells can support editing.
    return new TableDataTableCell(alignmentClass);
  }

  private final class TableDataTableCell
      implements Callback<TableColumn<StatusTableDO, String>, TableCell<StatusTableDO, String>>
  {
    private final PseudoClass alignmentClass;

    public TableDataTableCell(PseudoClass alignmentClass)
    {
      this.alignmentClass = alignmentClass;
    }

    @Override
    public TableCell<StatusTableDO, String> call(TableColumn<StatusTableDO, String> param)
    {
      return new TableCell<StatusTableDO, String>() {
        @Override
        protected void updateItem(String item, boolean empty)
        {
          super.updateItem(item, empty);
          if (item != null)
          {
            setWrapText(true);
            setText(item);
            pseudoClassStateChanged(alignmentClass, true);
          }
        }
      };
    }
  }

  /**
   * A factory for creating Cell update objects, which takes care of data,
   * faulty cells and alignment of data.
   */
  private class CellUpdateFactory
      implements Callback<TableColumn<StatusTableDO, String>, TableCell<StatusTableDO, String>>
  {
    private final int cellIndex;

    /**
     * Instantiates a new cell update factory.
     *
     * @param index
     *          the car
     */
    public CellUpdateFactory(int index)
    {
      cellIndex = index;
    }

    @Override
    public TableCell<StatusTableDO, String> call(TableColumn<StatusTableDO, String> param)
    {
      return new RenderTableCell();
    }

    private final class RenderTableCell extends TableCell<StatusTableDO, String>
    {
      @Override
      protected void updateItem(String item, boolean empty)
      {
        super.updateItem(item, empty);
        if (getIndex() != -1 && !empty)
        {
          if (getIndex() >= getTableView().getItems().size())
          {
            return;
          }

          StatusTableDO statusTableDO = getTableView().getItems().get(getIndex());

          if (cellIndex >= statusTableDO.getAllCarData().size())
          {
            return;
          }

          StatusTableCellDO cellData = statusTableDO.getAllCarData().get(cellIndex);

          NodePseudoClassProperty alignmentPseudoClassProperty = new NodePseudoClassProperty(this);
          alignmentPseudoClassProperty.bind(cellData.textAlignmentProperty());

          // Bogie1 label to hold bogie1 data
          Label bogie1Label = new Label(cellData.getFirstBogieCellData());
          bogie1Label.getStyleClass().add(TABLE_CELL_LABLE);
          bogie1Label.setMinHeight(cellHeight - 1);
          bogie1Label.setMaxHeight(cellHeight - 1);

          // Bogie2 label to hold bogie2 data
          Label bogie2Label = new Label(cellData.getSecondBogieCellData());
          bogie2Label.getStyleClass().add(TABLE_CELL_LABLE);
          bogie2Label.setMinHeight(cellHeight - 1);
          bogie2Label.setMaxHeight(cellHeight - 1);

          // Outer box to hold bogie1 and bogie2 label
          HBox box = new HBox();
          box.setMinWidth(carDataColumnWidth - 1);
          box.setMaxWidth(carDataColumnWidth - 1);
          box.setAlignment(Pos.CENTER);

          // Bogie1 box to hold bogie1 label
          HBox bogie1Box = new HBox();
          bogie1Box.setMinWidth(box.getMinWidth() / 2);
          bogie1Box.setMaxWidth(box.getMinWidth() / 2);

          // Bogie2 box to hold bogie2 label
          HBox bogie2Box = new HBox();
          bogie2Box.setMinWidth(box.getMinWidth() / 2);
          bogie2Box.setMaxWidth(box.getMinWidth() / 2);

          updateCellFormation(cellData.secondBogieExistProperty().get(), bogie1Label, bogie2Label, box,
              bogie1Box, bogie2Box);
          setGraphic(box);

          cellData.secondBogieExistProperty().addListener((observable, oldVal, newVal) -> {
            updateCellFormation(newVal, bogie1Label, bogie2Label, box, bogie1Box, bogie2Box);
            setGraphic(box);
          });

          attachTextLabelBinder(cellData, bogie1Label, bogie2Label);
        }
      }

      private void updateCellFormation(boolean isSecondBigieExist, Label bogie1Label, Label bogie2Label,
          HBox outerBox, HBox bogie1Box, HBox bogie2Box)
      {
        if (isSecondBigieExist)
        {
          bogie1Label.setMinWidth((bogie1Box.getMinWidth()) - 1);
          bogie2Label.setMinWidth((bogie2Box.getMinWidth()) - 1);
          bogie1Label.setMaxWidth((bogie1Box.getMaxWidth()) - 1);
          bogie2Label.setMaxWidth((bogie2Box.getMaxWidth()) - 1);
          // Add white line separator between bogie1 and bogie2 box.
          bogie1Box.getStyleClass().add(CELL_SEPARATOR);
          bogie1Box.getChildren().add(bogie1Label);
          bogie2Box.getChildren().add(bogie2Label);
          outerBox.getChildren().clear();
          outerBox.getChildren().addAll(bogie1Box, bogie2Box);
        }
        else
        {
          bogie1Label.setMinWidth(outerBox.getMinWidth());
          bogie1Label.setMaxWidth(outerBox.getMaxWidth());
          outerBox.getChildren().clear();
          outerBox.getChildren().addAll(bogie1Label);
        }
      }

      private void attachTextLabelBinder(StatusTableCellDO cellData, Label label1, Label label2)
      {
        try
        {
          label1.textProperty().bind(cellData.firstBogieCellDataProperty());
          label2.textProperty().bind(cellData.secondBogieCellDataProperty());

          NodePseudoClassProperty bogie1LabelProperty = new NodePseudoClassProperty(label1);
          bogie1LabelProperty.set(cellData.firstBogieCellStateProperty().get());
          NodePseudoClassProperty bogie2LabelProperty = new NodePseudoClassProperty(label2);
          bogie2LabelProperty.set(cellData.secondBogieCellStateProperty().get());

          cellData.firstBogieCellStateProperty().addListener((observable, oldVal,
              newVal) -> bogie1LabelProperty.set(cellData.firstBogieCellStateProperty().get()));

          cellData.secondBogieCellStateProperty().addListener((observable, oldVal,
              newVal) -> bogie2LabelProperty.set(cellData.secondBogieCellStateProperty().get()));
        }
        catch (IllegalArgumentException e)
        {
          LOGGER.error(String.format("%s %s", e.getMessage(), cellData.toString())); //$NON-NLS-1$
          LOGGER.info(e);
        }

      }
    }
  }
}

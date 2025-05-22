
/*
 * ==================================================================
 * 
 * (C) Copyright 2020 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.dmi.fe.gui.data;

import com.sydac.mmrbem.cabscreens.fe.common.NodePseudoClassProperty;
import com.sydac.mmrbem.dmi.fe.common.DMIUIConstants;

import javafx.css.PseudoClass;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.control.Label;
import javafx.scene.control.TableCell;
import javafx.scene.control.TableColumn;
import javafx.scene.control.TableView;
import javafx.scene.control.cell.PropertyValueFactory;
import javafx.scene.layout.HBox;
import javafx.scene.text.TextAlignment;
import javafx.util.Callback;

/**
 * Status screens have table to show the data, this helper class renders the
 * data on the tables.
 * 
 */
public class TableDataRenderer
{
  private TableView<StatusTableDO> statusTable;

  private final double firstColumnWidth;

  private final double carDataColumnWidth;

  private final double cellHeight;

  private static final String FIRST_COLUMN_PROPERTY_VALUE = "rowName"; //$NON-NLS-1$

  private static final PseudoClass CENTER_ALIGNMENT = PseudoClass.getPseudoClass("center"); //$NON-NLS-1$

  private static final String CELL_SEPARATOR = "table-cell-box-separator"; //$NON-NLS-1$

  private int maxCars;

  /**
   * Instantiates a new table data renderer.
   * 
   * @param statusTable
   *          status table
   * @param aMaxCars
   *          max cars
   * @param cellHight
   *          cell height
   * @param firstColumnWidth
   *          first column width
   * @param columnWidth
   *          cell width
   */
  public TableDataRenderer(TableView<StatusTableDO> statusTable, int aMaxCars, double cellHight,
      double firstColumnWidth, double columnWidth)
  {
    this.statusTable = statusTable;
    maxCars = aMaxCars;
    this.cellHeight = cellHight;
    this.firstColumnWidth = firstColumnWidth;
    this.carDataColumnWidth = columnWidth;

  }

  /**
   * Creates the status table for different screens with specified number of
   * columns. Width of column is managed based on the total columns.
   * 
   * @param totalColumn
   *          number of column to be created
   */
  public void createStatusTable(int totalColumn)
  {
    double columnWidth = carDataColumnWidth;
    maxCars = totalColumn;
    statusTable.getColumns().clear();

    TableColumn<StatusTableDO, String> firstCol = new TableColumn<>();
    firstCol.setCellValueFactory(new PropertyValueFactory<>(FIRST_COLUMN_PROPERTY_VALUE));
    firstCol.setCellFactory(getCustomCellFactory(CENTER_ALIGNMENT));
    firstCol.setPrefWidth(firstColumnWidth);

    statusTable.getColumns().add(firstCol);

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
    statusTable.setPadding(new Insets(0, 0, 0, 0));
    statusTable.setFixedCellSize(cellHeight);
    statusTable.setPrefHeight(statusTable.getItems().size() * cellHeight);
    statusTable.getSelectionModel().select(0);
    statusTable.setPrefWidth(firstColumnWidth + (carDataColumnWidth * maxCars));
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
          setPadding(new Insets(0, 0, 0, 0));
          if (item != null)
          {
            setGraphic(null);
            setWrapText(true);
            setTextAlignment(TextAlignment.CENTER);
            setText(item);
            pseudoClassStateChanged(alignmentClass, true);
          }
          else
          {
            setText(DMIUIConstants.EMPTY_STATIC_STRING);
            setGraphic(null);
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
        super.setPadding(new Insets(0, 0, 0, 0));
        if (getIndex() != -1 && !empty)
        {
          setGraphic(null);
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
          bogie1Label.getStyleClass().add(cellData.getFirstBogieCellState());
          bogie1Label.setMinHeight(cellHeight - 1);
          bogie1Label.setMaxHeight(cellHeight - 1);
          bogie1Label.setPadding(new Insets(0, 0, 0, 0));

          // Bogie2 label to hold bogie2 data
          Label bogie2Label = new Label(cellData.getSecondBogieCellData());
          bogie2Label.getStyleClass().add(cellData.getSecondBogieCellState());
          bogie2Label.setMinHeight(cellHeight - 1);
          bogie2Label.setMaxHeight(cellHeight - 1);
          bogie2Label.setPadding(new Insets(0, 0, 0, 0));

          // Outer box to hold bogie1 and bogie2 label
          HBox box = new HBox();
          box.setPadding(new Insets(0, 0, 0, 0));
          box.setMinWidth(carDataColumnWidth - 1);
          box.setMaxWidth(carDataColumnWidth - 1);
          box.setAlignment(Pos.CENTER);

          // Bogie1 box to hold bogie1 label
          HBox bogie1Box = new HBox();
          bogie1Box.setPadding(new Insets(0, 0, 0, 0));
          bogie1Box.setMinWidth(box.getMinWidth() / 2);
          bogie1Box.setMaxWidth(box.getMinWidth() / 2);

          // Bogie2 box to hold bogie2 label
          HBox bogie2Box = new HBox();
          bogie2Box.setPadding(new Insets(0, 0, 0, 0));
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
        else
        {
          setText(DMIUIConstants.EMPTY_STATIC_STRING);
          setGraphic(null);
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
        label1.textProperty().bind(cellData.firstBogieCellDataProperty());
        label2.textProperty().bind(cellData.secondBogieCellDataProperty());

        NodePseudoClassProperty bogie1LabelProperty = new NodePseudoClassProperty(label1);
        bogie1LabelProperty.set(cellData.firstBogieCellStateProperty().get());
        NodePseudoClassProperty bogie2LabelProperty = new NodePseudoClassProperty(label2);
        bogie2LabelProperty.set(cellData.secondBogieCellStateProperty().get());

        cellData.firstBogieCellStateProperty().addListener((observable, oldVal, newVal) -> {
          bogie1LabelProperty.set(cellData.firstBogieCellStateProperty().get());
          label1.getStyleClass().clear();
          label1.getStyleClass().add(cellData.getFirstBogieCellState());
        });

        cellData.secondBogieCellStateProperty().addListener((observable, oldVal, newVal) -> {
          label2.getStyleClass().clear();
          label2.getStyleClass().add(cellData.getSecondBogieCellState());
        });

      }
    }
  }
}

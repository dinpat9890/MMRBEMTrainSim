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

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.ListIterator;

import javafx.beans.property.ListProperty;

public class TableDataProcesser
{
  private ListProperty<StatusTableDO> tableDataList;

  public TableDataProcesser(ListProperty<StatusTableDO> aTableDataList)
  {
    tableDataList = aTableDataList;
  }

  private void createData(ITableRowProperty rowProperty, int maxCars)
  {
    boolean create = false;

    if (tableDataList.size() > rowProperty.getIndex())
    {
      StatusTableDO trainStatusDO = tableDataList.get(rowProperty.getIndex());

      if (!rowProperty.getRowName().equals(trainStatusDO.getRowName()))
      {
        create = true;
      }
    }
    else
    {
      create = true;
    }

    if (create)
    {
      StatusTableDO trainStatusDO = new StatusTableDO();
      trainStatusDO.setRowName(rowProperty.getRowName());
      StatusTableCellDO[] listOfCar = new StatusTableCellDO[maxCars];

      for (int i = 0; i < maxCars; i++)
      {
        StatusTableCellDO tableCellDo = new StatusTableCellDO();
        tableCellDo.setCarIndex(i + 1);

        tableCellDo.setTextAlignment(rowProperty.getRowTextAlignment());
        tableCellDo.setRowName(rowProperty.getRowName());

        listOfCar[i] = tableCellDo;
      }

      trainStatusDO.setAllCarData(Arrays.asList(listOfCar));

      tableDataList.add(rowProperty.getIndex(), trainStatusDO);
    }
  }

  /**
   * Updates the data for each row.
   * 
   * @param rowProperty
   *          the row name
   * @param carIndex
   *          the car index
   * @param isSecondBogieExist
   *          set true if second bogie data need to display
   * @param firstBogieCellData
   *          first bogie data
   * @param firstBogieCellState
   *          first bogie state
   * @param secondBogieCellData
   *          second bogie data, if exist
   * @param secondBogieCellState
   *          second state data, if exist
   */
  public void updateData(ITableRowProperty rowProperty, int carIndex, boolean isSecondBogieExist,
      String firstBogieCellData, String firstBogieCellState, String secondBogieCellData,
      String secondBogieCellState)
  {
    StatusTableCellDO statusTableCellDO = new StatusTableCellDO(carIndex, rowProperty.getRowTextAlignment(),
        isSecondBogieExist, firstBogieCellData, firstBogieCellState, secondBogieCellData,
        secondBogieCellState);
    statusTableCellDO.setRowName(rowProperty.getRowName());
    if (tableDataList.size() > rowProperty.getIndex())
    {
      // Existing data for the row
      StatusTableDO trainStatusDO = tableDataList.get(rowProperty.getIndex());

      updateCarData(trainStatusDO.getAllCarData(), statusTableCellDO);
    }
    else
    {
      // Create new DO and update details
      List<StatusTableCellDO> carData = new ArrayList<>();
      StatusTableDO trainStatusDO = new StatusTableDO();
      trainStatusDO.setRowName(rowProperty.getRowName());
      trainStatusDO.setCarIndex(carIndex);
      trainStatusDO.setAllCarData(updateCarData(carData, statusTableCellDO));

      tableDataList.add(trainStatusDO);
    }
  }

  public void emptyData(ITableRowProperty rowProperty, int maxCars)
  {
    // this will only create it if it's necessary
    createData(rowProperty, maxCars);
  }

  /**
   * Updates the new car data in the List<StatusTableCellDO>.
   * 
   * @param carData
   *          list of {@link StatusTableCellDO}
   * @param statusTableCellDO
   *          data to be update into given list the car index
   * @return the list of {@link StatusTableCellDO}
   */
  private List<StatusTableCellDO> updateCarData(List<StatusTableCellDO> carData,
      StatusTableCellDO statusTableCellDO)
  {
    int indexOf = indexOf(carData, statusTableCellDO.getCarIndex());

    if (indexOf != -1)
    {
      carData.get(indexOf).setFirstBogieCellData(statusTableCellDO.getFirstBogieCellData());
      carData.get(indexOf).setSecondBogieCellData(statusTableCellDO.getSecondBogieCellData());
      carData.get(indexOf).setFirstBogieCellState(statusTableCellDO.getFirstBogieCellState());
      carData.get(indexOf).setSecondBogieCellState(statusTableCellDO.getSecondBogieCellState());
      carData.get(indexOf).setSecondBogieCellDataExist(statusTableCellDO.isSecondBogieCellDataExist());

      carData.get(indexOf).setTextAlignment(statusTableCellDO.getTextAlignment());
    }
    else
    {
      StatusTableCellDO customCellData = new StatusTableCellDO();
      customCellData.setCarIndex(statusTableCellDO.getCarIndex());
      customCellData.setFirstBogieCellData(statusTableCellDO.getFirstBogieCellData());
      customCellData.setSecondBogieCellData(statusTableCellDO.getSecondBogieCellData());
      customCellData.setFirstBogieCellState(statusTableCellDO.getFirstBogieCellState());
      customCellData.setSecondBogieCellState(statusTableCellDO.getSecondBogieCellState());
      customCellData.setSecondBogieCellDataExist(statusTableCellDO.isSecondBogieCellDataExist());
      customCellData.setTextAlignment(statusTableCellDO.getTextAlignment());
      customCellData.setRowName(statusTableCellDO.getRowName());

      carData.add(customCellData);

      carData.sort((StatusTableCellDO cell1, StatusTableCellDO cell2) -> {
        int compare = 0;

        if (cell1 == null && cell2 != null)
        {
          compare = -1;
        }
        else if (cell1 != null && cell2 == null)
        {
          compare = 1;
        }
        else if (cell1 != null && cell2 != null)
        {
          compare = Integer.compare(cell1.getCarIndex(), cell2.getCarIndex());
        }

        return compare;
      });
    }

    return carData;
  }

  /**
   * Return index of element in List<StatusTableCellDO> that matches with
   * incoming StatusTableCellDO object.
   *
   * @param allCarData
   *          the all car data
   * @param carIndex
   *          car index
   * @return the int
   */
  private int indexOf(List<StatusTableCellDO> allCarData, int carIndex)
  {
    for (int i = 0; i < allCarData.size(); i++)
    {
      StatusTableCellDO cellDO = allCarData.get(i);
      if (cellDO.getCarIndex() == carIndex)
      {
        return i;
      }
    }
    return -1;
  }

  @Override
  public String toString()
  {
    return tableDataList.toString();
  }

  /**
   * Removes the car data from each rows, which is not provided in given
   * carIndexList parameter.
   *
   * @param carIndexList
   *          the list of currently available all car index. 
   *          Other than these car index all other car data will be removed
   */
  public void removeCardata(List<Integer> carIndexList)
  {
    ListIterator<StatusTableDO> tabledataIter = tableDataList.getValue().listIterator();
    while (tabledataIter.hasNext())
    {
      ListIterator<StatusTableCellDO> cellDataIter = tabledataIter.next().getAllCarData().listIterator();
      while (cellDataIter.hasNext())
      {
        if (!carIndexList.contains(cellDataIter.next().getCarIndex()))
        {
          cellDataIter.remove();
        }
      }
    }
  }
}

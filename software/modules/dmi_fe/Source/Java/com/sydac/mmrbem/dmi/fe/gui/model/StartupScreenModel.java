package com.sydac.mmrbem.dmi.fe.gui.model;

import com.sydac.mmrbem.cabscreens.fe.gui.model.AbstractScreenModel;

import javafx.beans.property.DoubleProperty;
import javafx.beans.property.SimpleDoubleProperty;

public class StartupScreenModel extends AbstractScreenModel
{

  private final DoubleProperty progressBarValue = new SimpleDoubleProperty();

  public StartupScreenModel(int carIndex)
  {
    super(carIndex);
  }

  public void setProgressBarValue(Double progressValue)
  {
    progressBarValue.set(progressValue);
  }

  public DoubleProperty getProgressBarValue()
  {
    return progressBarValue;
  }
}

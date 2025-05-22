package com.sydac.mmrbem.dmi.fe.gui.model;

import com.sydac.mmrbem.cabscreens.fe.gui.model.AbstractScreenModel;

import javafx.beans.property.SimpleStringProperty;
import javafx.beans.property.StringProperty;

public class CrewIdPopupModel extends AbstractScreenModel
{

  private final StringProperty crewIdPanelEnteredNumber = new SimpleStringProperty();

  public CrewIdPopupModel(int carIndex)
  {
    super(carIndex);
  }

  public void setCrewIdPanelEnteredNumber(String num)
  {
    crewIdPanelEnteredNumber.set(num);
  }

  /**
   * @return the crewIdPanelEnteredNumber
   */
  public StringProperty getCrewIdPanelEnteredNumber()
  {
    return crewIdPanelEnteredNumber;
  }

}

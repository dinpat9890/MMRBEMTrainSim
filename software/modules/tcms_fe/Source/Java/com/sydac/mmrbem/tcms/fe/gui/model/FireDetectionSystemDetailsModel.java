
package com.sydac.mmrbem.tcms.fe.gui.model;

import com.sydac.mmrbem.cabscreens.fe.gui.model.AbstractScreenModel;

import javafx.beans.property.IntegerProperty;
import javafx.beans.property.SimpleIntegerProperty;

public class FireDetectionSystemDetailsModel extends AbstractScreenModel
{
  IntegerProperty carType = new SimpleIntegerProperty();

  IntegerProperty hvac1Status = new SimpleIntegerProperty();

  IntegerProperty saloonCabAreaStatus = new SimpleIntegerProperty();

  IntegerProperty edbSpareBoxStatus = new SimpleIntegerProperty();

  IntegerProperty hvac1buttonStatus = new SimpleIntegerProperty();

  IntegerProperty saloonCabAreaButtonStatus = new SimpleIntegerProperty();

  IntegerProperty edbSpareBoxButtonStatus = new SimpleIntegerProperty();

  IntegerProperty shdSaloonR1Status = new SimpleIntegerProperty();

  IntegerProperty shdSaloonR2Status = new SimpleIntegerProperty();

  IntegerProperty shdSaloonR3Status = new SimpleIntegerProperty();

  IntegerProperty shdSaloonL1Status = new SimpleIntegerProperty();

  IntegerProperty shdSaloonL2Status = new SimpleIntegerProperty();

  IntegerProperty shdSaloonL3Status = new SimpleIntegerProperty();

  IntegerProperty hdHvac2Status = new SimpleIntegerProperty();

  IntegerProperty auxillaryStatus = new SimpleIntegerProperty();

  IntegerProperty endCubicleRR1 = new SimpleIntegerProperty();

  IntegerProperty endCubicleRR2 = new SimpleIntegerProperty();

  IntegerProperty endCubicleRL1 = new SimpleIntegerProperty();

  IntegerProperty endCubicleRL2 = new SimpleIntegerProperty();

  IntegerProperty currentCarIndex = new SimpleIntegerProperty();

  IntegerProperty lhdDriverDeskDisable = new SimpleIntegerProperty();

  IntegerProperty lhdCIDisable = new SimpleIntegerProperty();

  IntegerProperty lhdLtjbDIsable = new SimpleIntegerProperty();

  public FireDetectionSystemDetailsModel(int carIndex)
  {
    super(carIndex);
  }

  public IntegerProperty getCarType()
  {
    return carType;
  }

  public void setCarType(int carType)
  {
    this.carType.set(carType);
  }

  public IntegerProperty getHvac1Status()
  {
    return hvac1Status;
  }

  public void setHvac1Status(Integer hvac1Status)
  {
    this.hvac1Status.set(hvac1Status);
  }

  public IntegerProperty getSaloonCabAreaStatus()
  {
    return saloonCabAreaStatus;
  }

  public void setSaloonCabAreaStatus(Integer saloonCabAreaStatus)
  {
    this.saloonCabAreaStatus.set(saloonCabAreaStatus);
  }

  public IntegerProperty getEdbSpareBoxStatus()
  {
    return edbSpareBoxStatus;
  }

  public void setEdbSpareBoxStatus(Integer edbSpareBoxStatus)
  {
    this.edbSpareBoxStatus.set(edbSpareBoxStatus);
  }

  public IntegerProperty getHvac1buttonStatus()
  {
    return hvac1buttonStatus;
  }

  public void setHvac1buttonStatus(Integer hvac1buttonStatus)
  {
    this.hvac1buttonStatus.set(hvac1buttonStatus);
  }

  public IntegerProperty getSaloonCabAreaButtonStatus()
  {
    return saloonCabAreaButtonStatus;
  }

  public void setSaloonCabAreaButtonStatus(Integer saloonCabAreaButtonStatus)
  {
    this.saloonCabAreaButtonStatus.set(saloonCabAreaButtonStatus);
  }

  public IntegerProperty getEdbSpareBoxButtonStatus()
  {
    return edbSpareBoxButtonStatus;
  }

  public void setEdbSpareBoxButtonStatus(Integer edbSpareBoxButtonStatus)
  {
    this.edbSpareBoxButtonStatus.set(edbSpareBoxButtonStatus);
  }

  public IntegerProperty getCurrentCarIndex()
  {
    return currentCarIndex;
  }

  public void setCurrentCarIndex(Integer currentCarIndex)
  {
    this.currentCarIndex.set(currentCarIndex);
  }

  public IntegerProperty getShdSaloonR1Status()
  {
    return shdSaloonR1Status;
  }

  public void setShdSaloonR1Status(Integer shdSaloonR1Status)
  {
    this.shdSaloonR1Status.set(shdSaloonR1Status);
  }

  public IntegerProperty getShdSaloonR2Status()
  {
    return shdSaloonR2Status;
  }

  public void setShdSaloonR2Status(Integer shdSaloonR2Status)
  {
    this.shdSaloonR2Status.set(shdSaloonR2Status);
  }

  public IntegerProperty getShdSaloonR3Status()
  {
    return shdSaloonR3Status;
  }

  public void setShdSaloonR3Status(Integer shdSaloonR3Status)
  {
    this.shdSaloonR3Status.set(shdSaloonR3Status);
  }

  public IntegerProperty getShdSaloonL1Status()
  {
    return shdSaloonL1Status;
  }

  public void setShdSaloonL1Status(Integer shdSaloonL1Status)
  {
    this.shdSaloonL1Status.set(shdSaloonL1Status);
  }

  public IntegerProperty getShdSaloonL2Status()
  {
    return shdSaloonL2Status;
  }

  public void setShdSaloonL2Status(Integer shdSaloonL2Status)
  {
    this.shdSaloonL2Status.set(shdSaloonL2Status);
  }

  public IntegerProperty getShdSaloonL3Status()
  {
    return shdSaloonL3Status;
  }

  public void setShdSaloonL3Status(Integer shdSaloonL3Status)
  {
    this.shdSaloonL3Status.set(shdSaloonL3Status);
  }

  public IntegerProperty getHdHvac2Status()
  {
    return hdHvac2Status;
  }

  public void setHdHvac2Status(Integer hdHvac2Status)
  {
    this.hdHvac2Status.set(hdHvac2Status);
  }

  public IntegerProperty getAuxillaryStatus()
  {
    return auxillaryStatus;
  }

  public void setAuxillaryStatus(Integer auxillaryStatus)
  {
    this.auxillaryStatus.set(auxillaryStatus);
  }

  public IntegerProperty getEndCubicleRR1()
  {
    return endCubicleRR1;
  }

  public void setEndCubicleRR1(Integer endCubicleRR1)
  {
    this.endCubicleRR1.set(endCubicleRR1);
  }

  public IntegerProperty getEndCubicleRR2()
  {
    return endCubicleRR2;
  }

  public void setEndCubicleRR2(Integer endCubicleRR2)
  {
    this.endCubicleRR2.set(endCubicleRR2);
  }

  public IntegerProperty getEndCubicleRL1()
  {
    return endCubicleRL1;
  }

  public void setEndCubicleRL1(Integer endCubicleRL1)
  {
    this.endCubicleRL1.set(endCubicleRL1);
  }

  public IntegerProperty getEndCubicleRL2()
  {
    return endCubicleRL2;
  }

  public void setEndCubicleRL2(Integer endCubicleRL2)
  {
    this.endCubicleRL2.set(endCubicleRL2);
  }

  public IntegerProperty getLhdDriverDeskDisable()
  {
    return lhdDriverDeskDisable;
  }

  public void setLhdDriverDeskDisable(Integer lhdDriverDeskDisable)
  {
    this.lhdDriverDeskDisable.set(lhdDriverDeskDisable);
  }

  public IntegerProperty getLhdCIDisable()
  {
    return lhdCIDisable;
  }

  public void setLhdCIDisable(Integer lhdCIDisable)
  {
    this.lhdCIDisable.set(lhdCIDisable);
  }

  public IntegerProperty getLhdLtjbDIsable()
  {
    return lhdLtjbDIsable;
  }

  public void setLhdLtjbDIsable(Integer lhdLtjbDIsable)
  {
    this.lhdLtjbDIsable.set(lhdLtjbDIsable);
  }
}

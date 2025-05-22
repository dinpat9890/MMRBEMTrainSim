package com.sydac.mmrbem.tcms.fe.gui.binder;

import com.sydac.foundation.PropertyKey;
import com.sydac.mmrbem.tcms.common.io.properties.IAppOutputsFireDetailsScreenProperties;
import com.sydac.mmrbem.tcms.fe.base.AbstractCommsListener;
import com.sydac.mmrbem.tcms.fe.gui.model.FireDetectionSystemDetailsModel;

public class FireDetectionSystemDetailsBinder extends AbstractCommsListener
{

  FireDetectionSystemDetailsModel fireDetectionSystemDetailsModel;

  public FireDetectionSystemDetailsBinder(FireDetectionSystemDetailsModel fireDetectionSystemDetailsModel)
  {
    super();
    this.fireDetectionSystemDetailsModel = fireDetectionSystemDetailsModel;
    propertyKeyDefinitions.add(IAppOutputsFireDetailsScreenProperties.class);
  }

  @Override
  protected <T> void appOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue)
  {
    if (IAppOutputsFireDetailsScreenProperties.FIRE_DETECTION_SELECTED_CAR_INDEX.equals(key))
    {
      fireDetectionSystemDetailsModel.setCurrentCarIndex((Integer)newValue);
      fireDetectionSystemDetailsModel.setCarType((Integer)newValue);
    }
    else if (IAppOutputsFireDetailsScreenProperties.HVAC_1_FIRE_SMOKE_ACTIVE_STATUS.equals(key))
    {
      fireDetectionSystemDetailsModel.setHvac1Status((Integer)newValue);
    }
    else if (IAppOutputsFireDetailsScreenProperties.EDB_HEAT_ALARM_ACTIVE_STATUS.equals(key))
    {
      fireDetectionSystemDetailsModel.setEdbSpareBoxStatus((Integer)newValue);
    }
    else if (IAppOutputsFireDetailsScreenProperties.CAB_SMOKE_ALARM_ACTIVE_STATUS.equals(key))
    {
      fireDetectionSystemDetailsModel.setSaloonCabAreaStatus((Integer)newValue);
    }
    else if (IAppOutputsFireDetailsScreenProperties.HVAC_1_BUTTON_STATUS.equals(key))
    {
      fireDetectionSystemDetailsModel.setHvac1buttonStatus((Integer)newValue);
    }
    else if (IAppOutputsFireDetailsScreenProperties.EDB_HEAT_BUTTON_STATUS.equals(key))
    {
      fireDetectionSystemDetailsModel.setEdbSpareBoxButtonStatus((Integer)newValue);
    }
    else if (IAppOutputsFireDetailsScreenProperties.CAB_SMOKE_BUTTON_STATUS.equals(key))
    {
      fireDetectionSystemDetailsModel.setSaloonCabAreaButtonStatus((Integer)newValue);
    }
    else if (IAppOutputsFireDetailsScreenProperties.SHD_SALOON_L1_BUTTON_STATUS.equals(key))
    {
      fireDetectionSystemDetailsModel.setShdSaloonL1Status((Integer)newValue);
    }
    else if (IAppOutputsFireDetailsScreenProperties.SHD_SALOON_L2_BUTTON_STATUS.equals(key))
    {
      fireDetectionSystemDetailsModel.setShdSaloonL2Status((Integer)newValue);
    }
    else if (IAppOutputsFireDetailsScreenProperties.SHD_SALOON_L3_BUTTON_STATUS.equals(key))
    {
      fireDetectionSystemDetailsModel.setShdSaloonL3Status((Integer)newValue);
    }
    else if (IAppOutputsFireDetailsScreenProperties.SHD_SALOON_R1_BUTTON_STATUS.equals(key))
    {
      fireDetectionSystemDetailsModel.setShdSaloonR1Status((Integer)newValue);
    }
    else if (IAppOutputsFireDetailsScreenProperties.SHD_SALOON_R2_BUTTON_STATUS.equals(key))
    {
      fireDetectionSystemDetailsModel.setShdSaloonR2Status((Integer)newValue);
    }
    else if (IAppOutputsFireDetailsScreenProperties.SHD_SALOON_R3_BUTTON_STATUS.equals(key))
    {
      fireDetectionSystemDetailsModel.setShdSaloonR3Status((Integer)newValue);
    }
    else if (IAppOutputsFireDetailsScreenProperties.HD_HVAC_2_BUTTON_STATUS.equals(key))
    {
      fireDetectionSystemDetailsModel.setHdHvac2Status((Integer)newValue);
    }
    else if (IAppOutputsFireDetailsScreenProperties.AUXILLARY_DESK_BUTTON_STATUS.equals(key))
    {
      fireDetectionSystemDetailsModel.setAuxillaryStatus((Integer)newValue);
    }
    else if (IAppOutputsFireDetailsScreenProperties.END_CUBICLE_RL1_BUTTON_STATUS.equals(key))
    {
      fireDetectionSystemDetailsModel.setEndCubicleRL1((Integer)newValue);
    }
    else if (IAppOutputsFireDetailsScreenProperties.END_CUBICLE_RL2_BUTTON_STATUS.equals(key))
    {
      fireDetectionSystemDetailsModel.setEndCubicleRL2((Integer)newValue);
    }
    else if (IAppOutputsFireDetailsScreenProperties.END_CUBICLE_RR1_BUTTON_STATUS.equals(key))
    {
      fireDetectionSystemDetailsModel.setEndCubicleRR1((Integer)newValue);
    }
    else if (IAppOutputsFireDetailsScreenProperties.END_CUBICLE_RR2_BUTTON_STATUS.equals(key))
    {
      fireDetectionSystemDetailsModel.setEndCubicleRR2((Integer)newValue);
    }
    else if (IAppOutputsFireDetailsScreenProperties.LHD_CI_DISABLE_STATUS.equals(key))
    {
      fireDetectionSystemDetailsModel.setLhdCIDisable((Integer)newValue);
    }
    else if (IAppOutputsFireDetailsScreenProperties.LHD_DRIVER_DESK_DISABLE_STATUS.equals(key))
    {
      fireDetectionSystemDetailsModel.setLhdDriverDeskDisable((Integer)newValue);
    }
    else if (IAppOutputsFireDetailsScreenProperties.LHD_LTJB_DISABLE_STATUS.equals(key))
    {
      fireDetectionSystemDetailsModel.setLhdLtjbDIsable((Integer)newValue);
    }
  }
}
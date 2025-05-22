package com.sydac.mmrbem.tcms.common.io.properties;

import static com.sydac.foundation.PropertyKey.create;

import com.sydac.common.febe.binding.CommsBinding;
import com.sydac.foundation.PropertyKey;
import com.sydac.project.runtimedata.ProjectObjectConstants.VDUOutputs;

public interface IAppOutputsMediumVoltageSystemScreenProperties
{
  @CommsBinding(property = VDUOutputs.MV_PEC_SWITCH_STATUS_LIST)
  PropertyKey<byte[]> MV_PEC_SWITCH_STATUS_LIST = create();

  @CommsBinding(property = VDUOutputs.MV_AUX_COMP_STATUS_LIST)
  PropertyKey<byte[]> MV_AUX_COMP_STATUS_LIST = create();

  @CommsBinding(property = VDUOutputs.MV_MAIN_COMP_STATUS_LIST)
  PropertyKey<byte[]> MV_MAIN_COMP_STATUS_LIST = create();
}

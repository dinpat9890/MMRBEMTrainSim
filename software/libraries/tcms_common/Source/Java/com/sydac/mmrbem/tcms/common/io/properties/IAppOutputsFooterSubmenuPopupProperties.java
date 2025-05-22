package com.sydac.mmrbem.tcms.common.io.properties;

import static com.sydac.foundation.PropertyKey.create;

import com.sydac.common.febe.binding.CommsBinding;
import com.sydac.foundation.PropertyKey;
import com.sydac.project.runtimedata.ProjectObjectConstants.VDUOutputs;

public interface IAppOutputsFooterSubmenuPopupProperties
{

  @CommsBinding(property = VDUOutputs.FOOTER_POPUP_ID)
  PropertyKey<Integer> FOOTER_POPUP_ID = create();

}

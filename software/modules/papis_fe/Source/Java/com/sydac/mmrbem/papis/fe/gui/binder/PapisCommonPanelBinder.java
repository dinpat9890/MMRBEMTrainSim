package com.sydac.mmrbem.papis.fe.gui.binder;

import com.sydac.foundation.PropertyKey;
import com.sydac.mmrbem.papis.common.io.properties.IAppOutputsScreenChangeProperties;
import com.sydac.mmrbem.papis.fe.base.AbstractCommsListener;
import com.sydac.mmrbem.papis.fe.gui.model.PapisCommonPanelModel;

public class PapisCommonPanelBinder extends AbstractCommsListener
{

  private PapisCommonPanelModel papisCommonPanelModel;

  public PapisCommonPanelBinder(PapisCommonPanelModel papisCommonPanelModel)
  {
    this.papisCommonPanelModel = papisCommonPanelModel;
    propertyKeyDefinitions.add(IAppOutputsScreenChangeProperties.class);

  }

  @Override
  protected <T> void appOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue)
  {
    if (IAppOutputsScreenChangeProperties.CURRENT_SCREEN_ID.equals(key))
    {
      papisCommonPanelModel.setCurrentScreenId((Integer)newValue);
    }
  }

}

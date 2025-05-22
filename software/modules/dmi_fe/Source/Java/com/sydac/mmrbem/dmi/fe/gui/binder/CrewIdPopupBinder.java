package com.sydac.mmrbem.dmi.fe.gui.binder;

import com.sydac.foundation.PropertyKey;
import com.sydac.mmrbem.dmi.common.io.properties.IAppOutputsCrewIdPopupProperties;
import com.sydac.mmrbem.dmi.fe.base.AbstractCommsListener;
import com.sydac.mmrbem.dmi.fe.gui.model.CrewIdPopupModel;

/**
 * The Class CrewIdPopupBinder used to read Crew Id Popup values from comms and
 * assign it to the model {@link CrewIdPopupModel}
 **/
public class CrewIdPopupBinder extends AbstractCommsListener
{

  private CrewIdPopupModel crewIdPopupModel;

  public CrewIdPopupBinder(CrewIdPopupModel crewIdPopupModel)
  {
    this.crewIdPopupModel = crewIdPopupModel;
    propertyKeyDefinitions.add(IAppOutputsCrewIdPopupProperties.class);
  }

  @Override
  protected <T> void appInputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue)
  {
    if (key == IAppOutputsCrewIdPopupProperties.CREW_ID_PANEL_ENTERED_NUMBER)
    {
      crewIdPopupModel.setCrewIdPanelEnteredNumber(new String((byte[])newValue));
    }

  }
}

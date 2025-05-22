package com.sydac.mmrbem.dmi.common.utils;

import com.sydac.common.registry.Registry;
import com.sydac.mmrbem.dmi.common.state.ApplicationConstants;

public class DMIPropertiesReader
{
  /** The Constant instance. */
  private static final DMIPropertiesReader instance = new DMIPropertiesReader();

  private String papisStationListPath;

  static
  {
    instance.loadPsiStationListPath();
  }

  private void loadPsiStationListPath()
  {
    papisStationListPath = Registry.getInstance().getString(ApplicationConstants.DOMAIN_NAME,
        ApplicationConstants.PIS_STATION_LIST_PATH);
  }

  public static String getPAPISStationListFilePath()
  {
    return instance.papisStationListPath;
  }
}

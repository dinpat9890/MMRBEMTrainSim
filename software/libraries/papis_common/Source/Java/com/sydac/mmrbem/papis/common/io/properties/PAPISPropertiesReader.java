package com.sydac.mmrbem.papis.common.io.properties;

import com.sydac.common.registry.Registry;
import com.sydac.mmrbem.papis.common.state.ApplicationConstants;

public class PAPISPropertiesReader
{
  /** The Constant instance. */
  private static final PAPISPropertiesReader instance = new PAPISPropertiesReader();

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

package com.sydac.mmrbem.tcms.common.utils;

import com.sydac.common.registry.Registry;
import com.sydac.mmrbem.tcms.common.state.ApplicationConstants;

public class TCMSPropertiesReader
{

  /** The Constant instance. */
  private static final TCMSPropertiesReader instance = new TCMSPropertiesReader();

  private String papisStationListPath;

  private String testScreenListPath;

  static
  {
    instance.loadPISStationListPath();
    instance.loadTestScreenDataPath();
  }

  private void loadPISStationListPath()
  {
    papisStationListPath = Registry.getInstance().getString(ApplicationConstants.DOMAIN_NAME,
        ApplicationConstants.STATION_LIST_PATH);
  }

  public static String getPAPISStationListFilePath()
  {
    return instance.papisStationListPath;
  }

  private void loadTestScreenDataPath()
  {
    testScreenListPath = Registry.getInstance().getString(ApplicationConstants.DOMAIN_NAME,
        ApplicationConstants.TEST_DATA_PATH);
  }

  public static String getLoadTestScreenDataFilePath()
  {
    return instance.testScreenListPath;
  }
}

package com.sydac.mmrbem.psd.common.utils;

import com.sydac.common.registry.Registry;
import com.sydac.mmrbem.psd.common.data.ApplicationConstants;

public class PSDPropertiesReader
{
 
  /** The Constant instance. */
  private static final PSDPropertiesReader instance = new PSDPropertiesReader();

  private String psdRouteListPath;

  static
  {

    instance.loadPapisRouteListPath();

  }

  private void loadPapisRouteListPath()
  {

    psdRouteListPath = Registry.getInstance().getString(ApplicationConstants.DOMAIN_NAME, "pisFolderPath");//$NON-NLS-1$ //$NON-NLS-2$
  }

  public static String getPSDRouteListFilePath()
  {
    return instance.psdRouteListPath;
  }
}

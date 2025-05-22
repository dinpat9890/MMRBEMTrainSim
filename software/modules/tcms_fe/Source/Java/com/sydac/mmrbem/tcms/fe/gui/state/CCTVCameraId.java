/*
 * ==================================================================
 *
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *
 * ==================================================================
 */
package com.sydac.mmrbem.tcms.fe.gui.state;

/**
 * CameraId enum represent the status of CCTV Camera Id
 * 
 * @author ext-vp
 *
 */
public enum CCTVCameraId
{
  NO_CAMERA(0, "", ""), //$NON-NLS-1$ //$NON-NLS-2$
  DMC_FRONT_CAMERA(1, "DMC-1", "FCAM"), //$NON-NLS-1$ //$NON-NLS-2$
  DMC_TRACK_CAMERA(2, "DMC-2", "TCAM"), //$NON-NLS-1$ //$NON-NLS-2$
  DMC_LEFT_EXT_CAMERA(3, "DMC-3", "ECAM"), //$NON-NLS-1$ //$NON-NLS-2$
  DMC_RIGHT_EXT_CAMERA(4, "DMC-4", "ECAM"), //$NON-NLS-1$ //$NON-NLS-2$
  DMC_DTRNMNT_CAMERA(5, "DMC-5", "TCAM"), //$NON-NLS-1$ //$NON-NLS-2$
  DMC_ODD_CAMERA(6, "DMC-6", "OCAM"), //$NON-NLS-1$ //$NON-NLS-2$
  DMC_CAB_CAMERA(7, "DMC-7", "DCAM"), //$NON-NLS-1$ //$NON-NLS-2$
  DMC_SALOON_CAMERA_1(8, "DMC-8", "SCAM"), //$NON-NLS-1$ //$NON-NLS-2$
  DMC_SALOON_CAMERA_2(9, "DMC-9", "SCAM"), //$NON-NLS-1$ //$NON-NLS-2$
  DMC_SALOON_CAMERA_3(10, "DMC-10", "SCAM"), //$NON-NLS-1$ //$NON-NLS-2$
  DMC_SALOON_CAMERA_4(11, "DMC-11", "SCAM"), //$NON-NLS-1$ //$NON-NLS-2$
  TC_SALOON_CAMERA_1(12, "TC-1", "SCAM"), //$NON-NLS-1$ //$NON-NLS-2$
  TC_SALOON_CAMERA_2(13, "TC-2", "SCAM"), //$NON-NLS-1$ //$NON-NLS-2$
  TC_SALOON_CAMERA_3(14, "TC-3", "SCAM"), //$NON-NLS-1$ //$NON-NLS-2$
  TC_SALOON_CAMERA_4(15, "TC-4", "SCAM"), //$NON-NLS-1$ //$NON-NLS-2$
  TC_PANTO_CAMERA(16, "TC-5", "PCAM"), //$NON-NLS-1$ //$NON-NLS-2$
  MC_SALOON_CAMERA_1(17, "MC-1", "SCAM"), //$NON-NLS-1$ //$NON-NLS-2$
  MC_SALOON_CAMERA_2(18, "MC-2", "SCAM"), //$NON-NLS-1$ //$NON-NLS-2$
  MC_SALOON_CAMERA_3(19, "MC-3", "SCAM"), //$NON-NLS-1$ //$NON-NLS-2$
  MC_SALOON_CAMERA_4(20, "MC-4", "SCAM"), //$NON-NLS-1$ //$NON-NLS-2$
  MC_LEFT_EXT_CAMERA(21, "MC-5", "ECAM"), //$NON-NLS-1$ //$NON-NLS-2$
  MC_RIGHT_EXT_CAMERA(22, "MC-6", "ECAM"); //$NON-NLS-1$ //$NON-NLS-2$

  private int cameraEnumId;

  private String name;

  private String camName;

  CCTVCameraId(int cameraEnumId, String name, String camName)
  {
    this.cameraEnumId = cameraEnumId;
    this.name = name;
    this.camName = camName;
  }

  public static CCTVCameraId getCameraNameOf(int aValue)
  {
    for (CCTVCameraId status : values())
    {
      if (status.cameraEnumId == aValue)
      {
        return status;
      }
    }
    return null;
  }

  public static CCTVCameraId getCameraIdOf(String cameraName)
  {
    for (CCTVCameraId status : values())
    {
      if ((status.name).equals(cameraName))
      {
        return status;
      }
    }
    return null;
  }

  public int getCameraEnumId()
  {
    return cameraEnumId;
  }

  public String getName()
  {
    return name;
  }

  public String getCamName()
  {
    return camName;
  }
}

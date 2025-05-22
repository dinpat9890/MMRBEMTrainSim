package com.sydac.mmrbem.tcms.common.state;

public enum HybridPanelImageIdEnum
{
  EXTERNAL_CAM_1(0, "external_cam_1"), //$NON-NLS-1$
  INTERNAL_CAM_1(1, "internal_cam_1"), //$NON-NLS-1$
  INTERNAL_CAM_2(2, "internal_cam_2"), //$NON-NLS-1$
  INTERNAL_CAM_3(3, "internal_cam_3"), //$NON-NLS-1$
  EXTERNAL_CAM_2(4, "external_cam_2"); //$NON-NLS-1$

  private final int imageId;

  private final String pseudoClass;

  HybridPanelImageIdEnum(int imageId, String pseudoClass)
  {
    this.imageId = imageId;
    this.pseudoClass = pseudoClass;
  }

  public int getImageId()
  {
    return imageId;
  }

  public String getPseudoClass()
  {
    return pseudoClass;
  }

  public static HybridPanelImageIdEnum valueOf(int imageId)
  {
    for (HybridPanelImageIdEnum i : values())
    {
      if (i.getImageId() == imageId)
      {
        return i;
      }
    }
    return null;
  }
}

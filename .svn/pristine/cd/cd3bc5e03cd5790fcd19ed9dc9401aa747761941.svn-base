package  com.sydac.mmrbem.tcms.common.state;

public enum VDUDataCatagory
{
  PROGRESS_1_MESSAGE("Loading User Profiles...", 0),  //$NON-NLS-1$
  PROGRESS_2_MESSAGE("Loading Systems...", 1),  //$NON-NLS-1$
  PROGRESS_3_MESSAGE("Loading Locations...", 2),  //$NON-NLS-1$
  PROGRESS_4_MESSAGE("Loading Signals...", 3),  //$NON-NLS-1$
  PROGRESS_5_MESSAGE("Loading Events...", 4),  //$NON-NLS-1$
  PROGRESS_6_MESSAGE("Loading Messages...", 5),  //$NON-NLS-1$
  PROGRESS_7_MESSAGE("Loading Layouts...", 6); //$NON-NLS-1$

  private final int value;

  private final String text;

  private VDUDataCatagory(String text, int value)
  {
    this.text = text;
    this.value = value;
  }

  public int getValue()
  {
    return value;
  }

  public String getText()
  {
    return text;
  }

  public static VDUDataCatagory valueOf(int intValue)
  {
    for (VDUDataCatagory i : values())
    {
      if (i.getValue() == intValue)
      {
        return i;
      }
    }
    return null;
  }
}

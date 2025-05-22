package com.sydac.mmrbem.tcms.common.state;

/** This enum provides the different header panel title **/

public enum HeaderPanelTitleEnum {
	EMPTY("PLEASE SELECT USER PROFILE AND LOGIN >>", 0), //$NON-NLS-1$
	WELCOME("Welcome", 1), //$NON-NLS-1$
	ACCESS_DENIED("Access Denied", 2); //$NON-NLS-1$
	

	private final int value;

	private final String text;
	
	HeaderPanelTitleEnum(String text, int value) {
		this.text = text;
		this.value = value;
	}

	public int getValue() {
		return value;
	}
	
	public String getText() {
		return text;
	}

	public static HeaderPanelTitleEnum valueOf(int intValue) {
		for (HeaderPanelTitleEnum i : values()) {
			if (i.getValue() == intValue) {
				return i;
			}
		}
		throw new IllegalArgumentException("Invalid value for Header panel Title:" + intValue); //$NON-NLS-1$
	}
	
}

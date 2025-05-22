/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.tcms.common.state;

public enum PecuCallStatus {
	CALL_NORMAL(0, "normal", "PECU"), //$NON-NLS-1$ //$NON-NLS-2$
	CALL_FAULTY(1, "faulty", "FAULTY"), //$NON-NLS-1$ //$NON-NLS-2$
	CALL_ONGOING(2, "ongoing", "CALL"), //$NON-NLS-1$ //$NON-NLS-2$
	CALL_TALKING(3, "talking", "TALK"), //$NON-NLS-1$ //$NON-NLS-2$
	CALL_ISOLATED(4, "isolated", "ISOLATED"), CALL_DEISOLATED(5, "normal", "PECU"), //$NON-NLS-3$ //$NON-NLS-4$
	CALL_UNKNOWN(6, "unknown", "UNKNOWN"), //$NON-NLS-1$ //$NON-NLS-2$
	CALL_RESET(7, "enable", "RESET"), //$NON-NLS-1$ //$NON-NLS-2$
	CALL_RESET_DISABLE(8, "disable", "PECU");

	private final int value;

	private final String css;

	private String buttonText;

	private PecuCallStatus(int value, String css, String text) {
		this.css = css;
		this.value = value;
		this.buttonText = text;

	}

	public int getValue() {
		return value;
	}

	public String getButtonText() {
		return buttonText;
	}

	public String getCss() {
		return css;
	}

	public static PecuCallStatus valueOf(int intValue) {
		for (PecuCallStatus i : values()) {
			if (i.getValue() == intValue) {
				return i;
			}
		}
		return null;
	}
}

/*
 * ==================================================================
 * 
 * (C) Copyright 2020 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.dmi.common.state;

/**
 * This enum for High priority message pane status
 * 
 * @author potdars
 *
 */

public enum DMIHighPriorityPaneStatus {
	HIGH_PRIORITY_MESSAGE_PANE_ENABLED("high-priority-message-pane-yellow", 2), // $NON-NLS-1
	HIGH_PRIORITY_MESSAGE_PANE_DISABLED("high-priority-message-pane-gray", 3); // $NON-NLS-1
	

	private final int value;

	private final String text;

	private DMIHighPriorityPaneStatus(String text, int value) {
		this.text = text;
		this.value = value;
	}

	public int getValue() {
		return value;
	}

	/**
	 * Get text to display
	 * 
	 * @return text
	 */
	public String getText() {
		return text;
	}

	public static DMIHighPriorityPaneStatus valueOf(int intValue) {
		for (DMIHighPriorityPaneStatus i : values()) {
			if (i.getValue() == intValue) {
				return i;
			}
		}
		throw new IllegalArgumentException("Invalid value for High Priority message pane Status:" + intValue); //$NON-NLS-1$
	}
}

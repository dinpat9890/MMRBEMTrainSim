/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.radio.backend.radiointercom.properties;

import static com.sydac.foundation.PropertyKey.create;

import com.sydac.common.febe.binding.CommsBinding;
import com.sydac.foundation.PropertyKey;
import com.sydac.project.runtimedata.ProjectObjectConstants.RadioIntercomInputsValues;;

public interface IRadioIntercomInputProperties
{
  @CommsBinding(property = RadioIntercomInputsValues.RADIO_EMRGNCY_CALL_REQ)
  PropertyKey<Integer> RADIO_EMRGNCY_CALL_REQ = create();

  @CommsBinding(property = RadioIntercomInputsValues.RADIO_FULL_DUPLEX_CALL_REQ)
  PropertyKey<Integer> RADIO_FULL_DUPLEX_CALL_REQ = create();

  @CommsBinding(property = RadioIntercomInputsValues.RADIO_HALF_DUPLEX_CALL_REQ)
  PropertyKey<Integer> RADIO_HALF_DUPLEX_CALL_REQ = create();

  @CommsBinding(property = RadioIntercomInputsValues.RADIO_SCC_CANCEL)
  PropertyKey<Integer> RADIO_SCC_CANCEL = create();

  @CommsBinding(property = RadioIntercomInputsValues.RADIO_STAT_MSG)
  PropertyKey<Integer> RADIO_STAT_MSG = create();

  @CommsBinding(property = RadioIntercomInputsValues.RADIO_GROUP_CALL_REQ)
  PropertyKey<Integer> RADIO_GROUP_CALL_REQ = create();

  @CommsBinding(property = RadioIntercomInputsValues.RADIO_CAB_CANCEL)
  PropertyKey<Integer> RADIO_CAB_CANCEL = create();

  @CommsBinding(property = RadioIntercomInputsValues.RADIO_CAB_INTERCOM)
  PropertyKey<Integer> RADIO_CAB_INTERCOM = create();

}

/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.radio.common.state;

import java.util.Map;

import com.sydac.foundation.PropertyKey;
import com.sydac.mmrbem.radio.common.io.properties.IAppInputsKeyPadPanelProperties;
/**
 * This class is used to set input property key and Map of characters based on
 * touch/click count The key returns of map characters and need to get character
 * based on click/touch count
 * 
 * @author mulukg
 *
 */
public enum KeyPadEnum
{
  KEY_1(IAppInputsKeyPadPanelProperties.BTN_1_REQUEST, KeyPadKeysMap.getKey1Map()), 
  KEY_2ABC(IAppInputsKeyPadPanelProperties.BTN_2_ABC_REQUEST, KeyPadKeysMap.getKey2AbcMap()), 
  KEY_3DEF(IAppInputsKeyPadPanelProperties.BTN_3_DEF_REQUEST, KeyPadKeysMap.getKey3DefMap()), 
  KEY_4GHI(IAppInputsKeyPadPanelProperties.BTN_4_GHI_REQUEST, KeyPadKeysMap.getKey4GhiMap()), 
  KEY_5JKL(IAppInputsKeyPadPanelProperties.BTN_5_JKL_REQUEST, KeyPadKeysMap.getKey5JklMap()), 
  KEY_6MNO(IAppInputsKeyPadPanelProperties.BTN_6_MNO_REQUEST, KeyPadKeysMap.getKey6MnoMap()), 
  KEY_7PQRS(IAppInputsKeyPadPanelProperties.BTN_7_PQRS_REQUEST, KeyPadKeysMap.getKey7PqrsMap()), 
  KEY_8TUV(IAppInputsKeyPadPanelProperties.BTN_8_TUV_REQUEST, KeyPadKeysMap.getKey8TuvMap()), 
  KEY_9XYZ(IAppInputsKeyPadPanelProperties.BTN_9_WXYZ_REQUEST, KeyPadKeysMap.getKey9XyzMap()), 
  KEY_0(IAppInputsKeyPadPanelProperties.BTN_0_REQUEST, KeyPadKeysMap.getKey0Map()),
  KEY_STAR(IAppInputsKeyPadPanelProperties.BTN_STAR_REQUEST, KeyPadKeysMap.getKeyStarMap()),
  KEY_HASH(IAppInputsKeyPadPanelProperties.BTN_HASH_REQUEST, KeyPadKeysMap.getKeyHashMap()),
  ;

  private final PropertyKey<Integer> key;

  private final Map<Integer, String> clickCountAndCharMap;

  private KeyPadEnum(PropertyKey<Integer> key, Map<Integer, String> clickCountAndCharMap)
  {
    this.key = key;
    this.clickCountAndCharMap = clickCountAndCharMap;
  }

  public static KeyPadEnum valueOf(PropertyKey<Integer> key)
  {
    for (KeyPadEnum i : values())
    {
      if (i.getKey().equals(key))
      {
        return i;
      }
    }
    return null;
  }

  public PropertyKey<Integer> getKey()
  {
    return key;
  }

  public Map<Integer, String> getClickCountAndCharMap()
  {
    return clickCountAndCharMap;
  }

}

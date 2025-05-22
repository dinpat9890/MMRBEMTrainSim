/*
 * ==================================================================
 *
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *
 * ==================================================================
 */
package com.sydac.mmrbem.dmi.common.utils;

import java.io.File;
import java.util.ArrayList;
import java.util.LinkedHashMap;
import java.util.List;
import java.util.Map;

import javax.xml.parsers.ParserConfigurationException;
import javax.xml.parsers.SAXParser;
import javax.xml.parsers.SAXParserFactory;

import org.xml.sax.Attributes;
import org.xml.sax.SAXException;
import org.xml.sax.helpers.DefaultHandler;

import com.sydac.common.log.Tracer;
import com.sydac.mmrbem.dmi.common.data.StationDetailModel;

/**
 * All the XMLs present at the locations are one by one parsed and relevant data
 * is stored in the model. Finally we get a list of models referring to each
 * parsed XML.
 */
public class XMLParser extends DefaultHandler
{
  /** Logger. */
  private static final Tracer LOGGER = Tracer.getInstance();

  private static final String STATION_ELEMENT = "Station"; //$NON-NLS-1$

  private static final String STATION_ID = "ID"; //$NON-NLS-1$

  private static final String STATION_NAME = "Name_EN"; //$NON-NLS-1$

  private static final String STATION_CODE = "StationCode"; //$NON-NLS-1$

  private int stationId;

  private String stationName;

  private String stationCode;

  private List<StationDetailModel> stationModelList = new ArrayList<>();

  private Map<Integer, String> stationListMap = new LinkedHashMap<>();

  private Map<String, StationDetailModel> stationCodeMap = new LinkedHashMap<>();

  private Map<Integer, String> stationIdCodeMap = new LinkedHashMap<>();

  private StationDetailModel stationXmlModel;

  /**
   * Instantiates a new XML parser.
   */
  public XMLParser()
  {
    parseDocument();
  }

  /**
   * Parses the document.
   *
   * @return true, if successfully parse XML file
   */
  public boolean parseDocument()
  {
    File file = new File(DMIPropertiesReader.getPAPISStationListFilePath());
    if (!file.exists())
    {
      LOGGER.error("PIS_Station_List.xml file not found in this path " + file.getAbsolutePath() //$NON-NLS-1$
          + " Please give correct path in PAPIS.properties file"); //$NON-NLS-1$
      return false;
    }
    SAXParserFactory spf = SAXParserFactory.newInstance();
    try
    {
      SAXParser sp = spf.newSAXParser();
      sp.parse(file.getAbsoluteFile(), this); // $NON-NLS-1$
    }
    catch (SAXException se)
    {
      LOGGER.error(se);
      return false;
    }
    catch (ParserConfigurationException pce)
    {
      LOGGER.error(pce);
      return false;
    }
    catch (Exception e)
    {
      LOGGER.error(e);
      return false;
    }
    return true;
  }

  @Override
  public void startDocument() throws SAXException
  {
    // do nothing
  }

  @Override
  public void startElement(String uri, String localName, String qName, Attributes attributes)
      throws SAXException
  {
    if (STATION_ELEMENT.equalsIgnoreCase(qName))
    {
      stationXmlModel = new StationDetailModel();
      stationId = Integer.parseInt(attributes.getValue(STATION_ID));
      stationName = attributes.getValue(STATION_NAME);
      stationCode = attributes.getValue(STATION_CODE);
    }
  }

  @Override
  public void endElement(String uri, String localName, String qName) throws SAXException
  {
    if (STATION_ELEMENT.equalsIgnoreCase(qName))
    {

      stationXmlModel.setStationId(stationId);
      stationXmlModel.setStationName(stationName);
      stationXmlModel.setStationCode(stationCode);
      stationXmlModel.setStationSkip(false);
      stationModelList.add(stationXmlModel);
      stationListMap.put(stationId, stationName);
      stationCodeMap.put(stationCode, stationXmlModel);
      stationIdCodeMap.put(stationId, stationCode);
    }
  }

  public String getStationName(int stationId)
  {
    return stationListMap.get(stationId);
  }

  public String getStationCode(int stationId)
  {
    return stationIdCodeMap.get(stationId);
  }

}

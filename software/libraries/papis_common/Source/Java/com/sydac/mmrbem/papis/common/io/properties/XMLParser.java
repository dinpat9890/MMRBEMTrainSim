/*
 * ==================================================================
 *
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *
 * ==================================================================
 */
package com.sydac.mmrbem.papis.common.io.properties;

import java.io.File;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
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
import com.sydac.mmrbem.papis.common.data.EmergencyInfoDetailModel;
import com.sydac.mmrbem.papis.common.data.LineDetailModel;
import com.sydac.mmrbem.papis.common.data.RouteDetailModel;
import com.sydac.mmrbem.papis.common.data.SpecialInfoDetailModel;
import com.sydac.mmrbem.papis.common.data.StationDetailModel;
import com.sydac.mmrbem.papis.common.state.ApplicationConstants;

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

  private static final String ROUTE_ID = "ID"; //$NON-NLS-1$

  private static final String ROUTE_ELEMENT = "Route"; //$NON-NLS-1$

  private static final String ROUTE_CODE = "Code"; //$NON-NLS-1$

  private static final String ROUTE_LINE_CODE = "LineCode"; //$NON-NLS-1$

  private static final String STATION_SEQUENCE = "StationSequence"; //$NON-NLS-1$

  private static final String LINE_ID = "ID"; //$NON-NLS-1$

  private static final String LINE_ELEMENT = "Line"; //$NON-NLS-1$

  private static final String LINE_NAME = "Name"; //$NON-NLS-1$

  private static final String LINE_CODE = "Code"; //$NON-NLS-1$

  private static final String SPC_INFO_ELEMENT = "SpecialMessage"; //$NON-NLS-1$

  private static final String SPC_INFO_ID = "ID"; //$NON-NLS-1$

  private static final String SPC_INFO_CODE = "Code"; //$NON-NLS-1$

  private static final String EMG_INFO_ELEMENT = "EmergencyMessage"; //$NON-NLS-1$

  private static final String EMG_INFO_ID = "ID"; //$NON-NLS-1$

  private static final String EMG_INFO_CODE = "Code"; //$NON-NLS-1$

  private int stationId;

  private String stationName;

  private String stationCode;

  private int lineId;

  private String lineName;

  private String lineCode;

  private int routeId;

  private String routeCode;

  private String routeLineCode;

  private int spcInfoId;

  private String spcInfoCode;

  private int emgInfoId;

  private String emgInfoCode;

  private List<StationDetailModel> stationModelList = new ArrayList<>();

  private List<LineDetailModel> lineModelList = new ArrayList<>();

  private List<RouteDetailModel> routeModelList = new ArrayList<>();

  private List<SpecialInfoDetailModel> spcInfoModelList = new ArrayList<>();

  private List<EmergencyInfoDetailModel> emgInfoModelList = new ArrayList<>();

  private Map<Integer, String> stationListMap = new LinkedHashMap<Integer, String>();

  private Map<String, StationDetailModel> stationCodeMap = new LinkedHashMap<String, StationDetailModel>();

  private Map<Integer, String> stationIdCodeMap = new LinkedHashMap<Integer, String>();

  private Map<String, String> lineMap = new LinkedHashMap<String, String>();

  private ArrayList<String> routeStationSequenceList;

  private String[] stationSequence;

  private StationDetailModel stationXmlModel;

  private LineDetailModel lineDetailModel;

  private RouteDetailModel routeDetailModel;

  private SpecialInfoDetailModel spcInfoDetailModel;

  private EmergencyInfoDetailModel emergencyInfoDetailModel;

  private Map<String, String> lineNameMap = new HashMap<>();

  /**
   * Instantiates a new XML parser.
   */
  public XMLParser()
  {
    parseDocument();
    displayLineName();
  }

  /**
   * Parses the document.
   *
   * @return true, if successfully parse XML file
   */
  public boolean parseDocument()
  {
    File file = new File(PAPISPropertiesReader.getPAPISStationListFilePath());
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
    // stationModelList.clear();
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
    else if (LINE_ELEMENT.equals(qName))
    {
      lineDetailModel = new LineDetailModel();
      lineId = Integer.parseInt(attributes.getValue(LINE_ID));
      lineName = attributes.getValue(LINE_NAME);
      lineCode = attributes.getValue(LINE_CODE);
    }
    else if (ROUTE_ELEMENT.equals(qName))
    {
      routeDetailModel = new RouteDetailModel();
      routeId = Integer.parseInt(attributes.getValue(ROUTE_ID));
      routeCode = attributes.getValue(ROUTE_CODE);
      routeLineCode = attributes.getValue(ROUTE_LINE_CODE);
      stationSequence = attributes.getValue(STATION_SEQUENCE).split(","); //$NON-NLS-1$
      routeStationSequenceList = new ArrayList<>(Arrays.asList(stationSequence));
    }
    else if (SPC_INFO_ELEMENT.equals(qName))
    {
      spcInfoDetailModel = new SpecialInfoDetailModel();
      spcInfoId = Integer.parseInt(attributes.getValue(SPC_INFO_ID));
      spcInfoCode = attributes.getValue(SPC_INFO_CODE);
    }
    else if (EMG_INFO_ELEMENT.equals(qName))
    {
      emergencyInfoDetailModel = new EmergencyInfoDetailModel();
      emgInfoId = Integer.parseInt(attributes.getValue(EMG_INFO_ID));
      emgInfoCode = attributes.getValue(EMG_INFO_CODE);
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
    else if (LINE_ELEMENT.equals(qName))
    {
      lineDetailModel.setLineId(lineId);
      lineDetailModel.setLineCode(lineCode);
      lineDetailModel.setLineName(lineName);
      lineModelList.add(lineDetailModel);
      lineMap.put(lineCode, lineName);
    }
    else if (ROUTE_ELEMENT.equals(qName))
    {
      routeDetailModel.setRouteId(routeId);
      routeDetailModel.setRouteCode(routeCode);
      routeDetailModel.setRouteLineCode(routeLineCode);
      routeDetailModel.setStationSequece(routeStationSequenceList);
      routeModelList.add(routeDetailModel);
    }
    else if (SPC_INFO_ELEMENT.equals(qName))
    {
      spcInfoDetailModel.setSpecialInfoId(spcInfoId);
      spcInfoDetailModel.setSpecialInfoCode(spcInfoCode);
      spcInfoModelList.add(spcInfoDetailModel);
    }
    else if (EMG_INFO_ELEMENT.equals(qName))
    {
      emergencyInfoDetailModel.setEmgInfoId(emgInfoId);
      emergencyInfoDetailModel.setEmgInfoCode(emgInfoCode);
      emgInfoModelList.add(emergencyInfoDetailModel);
    }
  }

  public List<StationDetailModel> getStationList()
  {
    List<StationDetailModel> stationList = new ArrayList<>();
    stationList.addAll(stationModelList);
    return stationList;
  }

  public String getStationName(int stationId)
  {
    return stationListMap.get(stationId);
  }

  public String getStationCode(int stationId)
  {
    return stationIdCodeMap.get(stationId);
  }

  public List<StationDetailModel> getStationList(List<String> stationSequence)
  {
    List<StationDetailModel> stationList = new ArrayList<>();
    int index = 0;
    if (!stationSequence.get(0).equals(ApplicationConstants.BLANK))
    {
      index = stationSequence.size();
    }
    for (int i = 0; i < index; i++)
    {
      stationList.add(stationCodeMap.get(stationSequence.get(i)));
    }
    return stationList;
  }

  public List<StationDetailModel> getUnskippedStationList(List<String> stationSequence)
  {
    List<StationDetailModel> stationList = new ArrayList<>();
    int index = 0;
    if (!stationSequence.get(0).equals(ApplicationConstants.BLANK))
    {
      index = stationSequence.size();
    }
    for (int i = 0; i < index; i++)
    {
      if (!stationCodeMap.get(stationSequence.get(i)).isStationSkip())
      {
        stationList.add(stationCodeMap.get(stationSequence.get(i)));
      }
    }
    return stationList;
  }

  public List<StationDetailModel> getSkippedStationList(List<String> stationSequence)
  {
    List<StationDetailModel> stationList = new ArrayList<>();
    int index = 0;
    if (!stationSequence.get(0).equals(ApplicationConstants.BLANK))
    {
      index = stationSequence.size();
    }
    for (int i = 0; i < index; i++)
    {
      if (stationCodeMap.get(stationSequence.get(i)).isStationSkip())
      {
        stationList.add(stationCodeMap.get(stationSequence.get(i)));
      }
    }
    return stationList;
  }

  public List<LineDetailModel> getLineList()
  {
    ArrayList<LineDetailModel> lineList = new ArrayList<LineDetailModel>();
    lineList.addAll(lineModelList);
    return lineList;
  }

  public List<RouteDetailModel> getRouteList()
  {
    ArrayList<RouteDetailModel> routeList = new ArrayList<RouteDetailModel>();
    routeList.addAll(routeModelList);
    return routeList;
  }

  public String getCurrentLine(int routeId)
  {
    if (routeId - 1 < routeModelList.size())
    {
      String name = lineMap.get(routeModelList.get(routeId - 1).getRouteLineCode());
      return getDisplayLineName(name);
    }
    else
    {
      return ApplicationConstants.BLANK;
    }
  }

  public void updateSkipStation(int stationid)
  {
    if (stationModelList.get(stationid - 1).isStationSkip())
    {
      stationModelList.get(stationid - 1).setStationSkip(false);
    }
    else
    {
      stationModelList.get(stationid - 1).setStationSkip(true);
    }
  }

  public List<SpecialInfoDetailModel> getSpcInfoList()
  {
    List<SpecialInfoDetailModel> spcInfoList = new ArrayList<>();
    spcInfoList.addAll(spcInfoModelList);
    return spcInfoList;
  }

  public List<EmergencyInfoDetailModel> getEmgInfoList()
  {
    List<EmergencyInfoDetailModel> emgInfoList = new ArrayList<>();
    emgInfoList.addAll(emgInfoModelList);
    return emgInfoList;
  }

  private void displayLineName()
  {
    lineNameMap.put("Line L7", "Line7");
    lineNameMap.put("Line L2A", "Line2A");
    lineNameMap.put("Line L2B", "Line2B");
    lineNameMap.put("Line L2 and 7", "Line2A&7");

  }

  public String getDisplayLineName(String lineName)
  {

    return lineNameMap.get(lineName);
  }
}

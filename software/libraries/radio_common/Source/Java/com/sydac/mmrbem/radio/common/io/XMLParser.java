/*
 * ==================================================================
 *
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *
 * ==================================================================
 */
package com.sydac.mmrbem.radio.common.io;

import java.io.File;
import java.util.LinkedList;
import java.util.List;

import javax.xml.parsers.ParserConfigurationException;
import javax.xml.parsers.SAXParser;
import javax.xml.parsers.SAXParserFactory;

import org.xml.sax.Attributes;
import org.xml.sax.SAXException;
import org.xml.sax.helpers.DefaultHandler;

import com.sydac.common.log.Tracer;

/**
 * All the XMLs present at the locations are one by one parsed and relevant data
 * is stored in the model. Finally we get a list of models referring to each
 * parsed XML.
 */
public class XMLParser extends DefaultHandler
{
  /** Logger. */
  private static final Tracer LOGGER = Tracer.getInstance();

  private static final String ROUTE_ID = "ID"; //$NON-NLS-1$

  private static final String ROUTE_ELEMENT = "Route"; //$NON-NLS-1$

  private static final String ROUTE_CODE = "Code"; //$NON-NLS-1$

  private static final String LINE_CODE = "LineCode"; //$NON-NLS-1$

  private int routeId;

  private String routeCode;

  private String lineCode;

  List<LineDetailModel> routeModelList = new LinkedList<>();

  private LineDetailModel lineDetailModel;

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
    File file = new File(RadioPropertiesReader.getRouteListFilePath());
    if (!file.exists())
    {
      LOGGER.error("PIS_Station_List.xml file not found in this path " + file.getAbsolutePath() //$NON-NLS-1$
          + " Please give correct path in PSD.properties file"); //$NON-NLS-1$
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
  {}

  @Override
  public void startElement(String uri, String localName, String qName, Attributes attributes)
      throws SAXException
  {
    if (ROUTE_ELEMENT.equalsIgnoreCase(qName))
    {
      lineDetailModel = new LineDetailModel();
      routeId = Integer.parseInt(attributes.getValue(ROUTE_ID));
      routeCode = attributes.getValue(ROUTE_CODE);
      lineCode = attributes.getValue(LINE_CODE);
    }

  }

  @Override
  public void endElement(String uri, String localName, String qName) throws SAXException
  {
    if (ROUTE_ELEMENT.equalsIgnoreCase(qName))
    {
      lineDetailModel.setRouteId(routeId);
      lineDetailModel.setRouteCode(routeCode);
      lineDetailModel.setLineCode(lineCode);
      routeModelList.add(lineDetailModel);
    }

  }

  public String getLineCode(int routeId)
  {
    String code = ""; //$NON-NLS-1$
    for (LineDetailModel route : routeModelList)
    {
      if (route.getRouteId() == routeId)
      {
        code = route.getLineCode();
      }
    }
    return code;
  }
}

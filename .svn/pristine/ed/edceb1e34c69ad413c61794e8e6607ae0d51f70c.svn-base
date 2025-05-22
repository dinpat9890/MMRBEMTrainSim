//**************************************************************************************************
//
//  File:           SignalFeature.us.cpp
//
//  Description:    SignalFeature class definition.
//
//  Reference:      Crossrail
//
//  Author:         Andy Cooper
//
//  (C) Copyright:  SYDAC Pty Ltd, 2015
//
//***************************************************************************************************

#ifndef SignalFeature_CPP
#define SignalFeature_CPP

// Paths not specified here since they are contained within this directory
#include <PoleFeature.us.cpp>
#include <AdjustablePart.us.cpp>

namespace Features
{
    class SignalFeature : PoleFeature
    {
        private:
            string m_regexp_pattern = "([A-Za-z]+)([0-9]+)(.*)";
            RegExp m_regex = new RegExp(m_regexp_pattern);

            // Create an Adjustable Part for the ID Plates Node.
            ProjUtil::AdjustablePart m_sig_id_plates;

            // Create an Adjustable Part for the Head Node.
            ProjUtil::AdjustablePart m_sig_head;

            // Create an Adjustable Part for the SPT Node.
            ProjUtil::AdjustablePart m_spt;

            // Create an Adjustable Part for the Platform Node.
            ProjUtil::AdjustablePart m_plat;

        public:

        //  Function:     SignalFeature
        //
        //  Description:  Constructor for the class
        //

        SignalFeature(FeatureInfoExtern info, Properties properties, Node parent_node)
        {
            // NOTE - You cannot use anything built in the Constructor in the setNumber or setString callbacks as they get
            //        called by the stupid Base Constructors before all of this has taken place!
            m_sig_id_plates = new ProjUtil::AdjustablePart(this,"Pole/SIGIDPlates");

            m_sig_head = new ProjUtil::AdjustablePart(this,"Pole/Head");

            m_spt = new ProjUtil::AdjustablePart(this,"Pole/SPT");

            m_plat = new ProjUtil::AdjustablePart(this,"Pole/Platforms");

            // Unless you call the base Constructors after creating the things you need first
            // i.e. (Remove the : Polefeature call above and replace with __PoleFeature__(info, properties, parent_node) here.
            __PoleFeature__(info, properties, parent_node);

        }

        //  Function:     ~SignalFeature
        //
        //  Description:  Destructor for the class
        //
        ~SignalFeature()
        {
            if (m_regex != 0) delete m_regex;
        }

        //  Function:       isValid
        //
        //  Description:    Returns 1 if this is a valid SignalFeature Feature, 0 otherwise.
        //
        //  Return value:
        //      int              - As above.

        int isValid()
        {
           return PoleFeature::isValid();
        }


        //  Function:       setNumber
        //
        //  Description:    Sets a number property associated with this Feature.
        //
        //  Parameters:
        //      string property  - The property name
        //      double value     - The property value

        void setNumber(string property, double value)
        {

            //log.warning("%s (line %d): setNumber : Feature %s(%d) : Property '%s' : value %f\n",  __FILE__, __LINE__, getName(), getID(), property, value);
            if (m_sig_id_plates == 0)
            {
                log.error("%s (line %d): setNumber : Feature %s(%d) : m_sig_id_plates is NULL!\n",  __FILE__, __LINE__, getName(), getID());
                return;
            }

            if (m_sig_head == 0)
            {
                log.error("%s (line %d): setNumber : Feature %s(%d) : m_sig_head is NULL!\n",  __FILE__, __LINE__, getName(), getID());
                return;
            }

            // If we know about this property then use it. Otherwise call down to the parent.
            // Note - ID Plate and Head adjustments should only be declared on Signal types that require it.
            // i.e. On Gantry Signals and Pole Signals with Large Platforms.
            if (property == "SPTEnable")
            {
                // Signal Post telephone can be enabled/disabled
                ProjUtil::enablePathChildNode(getParentNode(), "Pole", "SPT", value);
            }
            else if(property == "SPTOffset")
            {
                // Signal Post Telephone
                m_spt.setVerticalOffset(value);
            }
            else if(property == "RIMount")
            {
                // Mounting Bracket on PLS Signals
                ProjUtil::enablePathChildSurface(getParentNode(), "Pole/Head", "Bracket", value);
            }
            else if(property == "IDHor")
            {
                m_sig_id_plates.setHorizontalOffset(value);
            }
            else if(property == "IDLat")
            {
                m_sig_id_plates.setLateralOffset(value);
            }
            else if(property == "IDVert")
            {
                m_sig_id_plates.setVerticalOffset(value);
            }
            else if(property == "HeadHor")
            {
                m_sig_head.setHorizontalOffset(value);
            }
            else if(property == "HeadLat")
            {
                m_sig_head.setLateralOffset(value);
            }
            else if(property == "HeadVert")
            {
                m_sig_head.setVerticalOffset(value);
            }
            else if(property == "PlatHor")
            {
                m_plat.setHorizontalOffset(value);
            }
            else
            {
                // Pass all other number properties to the Base class.
                PoleFeature::setNumber(property, value);
            }
        }

        //  Function:       setString
        //
        //  Description:    Sets a string property associated with this Feature.
        //
        //  Parameters:
        //      string property  - The property name
        //      string value     - The property value
        //
        void setString(string property, string value)
        {
            //log.warning("%s (line %d): setString : Feature %s(%d) : Property '%s' : value %s\n",  __FILE__, __LINE__, getName(), getID(), property, value);
            if(value == "xxx")
               PoleFeature::setString(property, "");
            // Else Pass the parameter down to PoleFeature Class.
            else
                PoleFeature::setString(property, value);

        }
    };

    //  Class:          Features::SignalFeatureType
    //
    //  Description:    Representation of a feature Type Class. Contains the binding between
    //                  a feature type Class name and a factory function to create the associated
    //                  feature type Class.
    class SignalFeatureType : FeatureType
    {
    public:

        //  Function:       getName
        //
        //  Description:    Constructs a feature properties object caching
        //                  data members based on Unigine engine config.
        //
        //  Return value:
        //      string - The name of the feature type Class

        string getName()
        {
            return "SignalFeature";
        }

        //  Function:       createFeature
        //
        //  Description:    Factory function - creates a Feature using
        //                  FeatureInfo and Properties.
        //
        //  Parameters:
        //      FeatureInfoExtern info - Structure containing information about the feature instance
        //                               to be created.
        //      Properties       - Configuration information about this feature.
        //      Node parent      - The node parent.
        //
        //  Return value:
        //      Feature - The feature created - ownership is now with the caller.

        Feature createFeature(FeatureInfoExtern info, Properties properties, Node parent)
        {
            return new SignalFeature(info, properties, parent);
        }
    };
}
#endif

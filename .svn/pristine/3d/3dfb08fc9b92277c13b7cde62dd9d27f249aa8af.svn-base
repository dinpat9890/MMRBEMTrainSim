//**************************************************************************************************
//
//  File:           ObstructionFixedFlood.us.cpp
//
//  Description:    ObstructionFixedFlood class definition
//
//  Author:         Yogesh Kanade
//
//  (C) Copyright:  SYDAC Pty Ltd, 2020
//
//***************************************************************************************************

#ifndef OBSTRUCTION_FIXEDFLOOD_CPP
#define OBSTRUCTION_FIXEDFLOOD_CPP

#include <Sydac/Core/Scripts/World/Features/Feature.us.cpp>

namespace Features
{
    //  Class:          Features::ObstructionFixedFlood
    //
    //  Description:    This class is a representation of ObstructionFixedFlood that has three states - none, low, medium & high
    //                  Based on the state, child nodes of the feature node are enabled / disabled
    //                  The name of the Flood node in the world must be used as the name of the Feature for this to work.
    class ObstructionFixedFlood : Feature
    {
    private:
        enum
        {
            NONE = 1,
            LOW = 2,
            MED = 3,
            HIGH = 4
        };

        void enableChild(string child_name, int enable)
        {
            Node node = m_node.getNode(0);

            int child_id = node.findChild(child_name);

            if(-1 != child_id)
            {
                Node child_node = node.getChild(child_id);
                child_node.setEnabled(enable);
            }
            else
                log.error("ObstructionFixedFlood: Child node not found when enabling child!\n");
        }

    public:

        //  Function:     ObstructionFixedFlood
        //
        //  Description:  Constructor for the ObstructionFixedFlood class
        //

        ObstructionFixedFlood(FeatureInfoExtern info, Properties properties)
        {
            __Feature__(info, new SingleNodeWrapper(engine.editor.getNodeByName(info.getName())), properties);
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
            // If we know about this property then use it. Otherwise call down to the parent.
            if(property == "State")
            {
                //log.error("setNumber called prop = %s value = %f\n", property, value);
                if(value == NONE)
                {
                    enableChild("high", 0);
                    enableChild("low", 0);
                    enableChild("medium", 0);
                }
                else if(value == LOW)
                {
                    enableChild("high", 0);
                    enableChild("low", 1);
                    enableChild("medium", 0);
                }
                else if(value == MED)
                {
                    enableChild("high", 0);
                    enableChild("low", 0);
                    enableChild("medium", 1);
                }
                else if(value == HIGH)
                {
                    enableChild("high", 1);
                    enableChild("low", 0);
                    enableChild("medium", 0);
                }
            }
            else
               Feature::setNumber(property, value);
        }

        //  Function:       setString
        //
        //  Description:    Sets a string property associated with this Feature.
        //                  Initial values for properties are always sent as strings so we
        //                  forward to setNumber.
        //
        //  Parameters:
        //      string property  - The property name
        //      string value     - The property value

        void setString(string property, string value)
        {
            setNumber(property, double(value));
        }
    };

    //  Class:          Features::ObstructionFixedFlood
    //
    //  Description:    Representation of a feature type. Contains the binding between
    //                  a feature type name and a factory function to create the associated
    //                  feature type (ExampleFeature).
    class ObstructionFixedFloodType : FeatureType
    {
    public:

        //  Function:       getName
        //
        //  Description:    Constructs a feature properties object caching
        //                  data members based on Unigine engine config.
        //
        //  Return value:
        //      string - The name of the feature type

        string getName()
        {
            return "ObstructionFixedFlood";
        }

        //  Function:       createFeature
        //
        //  Description:    Factory function - creates a ExampleFeature using
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
            return new ObstructionFixedFlood(info, properties);
        }
    };
}
#endif

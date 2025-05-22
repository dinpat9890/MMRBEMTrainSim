//**************************************************************************************************
//
//  File:           ObstructionFixedOLE.us.cpp
//
//  Description:    ObstructionFixedOLE class definition
//
//  Author:         Yogesh Kanade
//
//  (C) Copyright:  SYDAC Pty Ltd, 2020
//
//***************************************************************************************************

#ifndef OBSTRUCTION_FIXEDOLE_CPP
#define OBSTRUCTION_FIXEDOLE_CPP

#include <Sydac/Core/Scripts/World/Features/Feature.us.cpp>

namespace Features
{
    //  Class:          Features::ObstructionFixedOLE
    //
    //  Description:    This class is a representation of ObstructionFixedOLE that has three states - none, Low, Medium & High
    //                  Based on the state, child nodes of the feature node are enabled / disabled
    class ObstructionFixedOLE : Feature
    {
    private:
        enum
        {
            NOT_VISIBLE = 1,
            //OBSTRUCTED = 2,
            DAMAGED = 3
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
                log.error("ObstructionFixedOLE: Child node %s not found when enabling child!\n", child_name);
        }

    public:

        //  Function:     ObstructionFixedOLE
        //
        //  Description:  Constructor for the ObstructionFixedOLE class
        //

        ObstructionFixedOLE(FeatureInfoExtern info, Properties properties)
        {
            __Feature__(info, new SingleNodeWrapper(engine.editor.getNodeByName("fixed_features")), properties);
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
                if(value == NOT_VISIBLE)
                {
                    enableChild("OLE", 1);
                    enableChild("OLE_broken", 0);
                    //enableChild("OLE_obstruction", 0);
                }
                /*else if(value == OBSTRUCTED)
                {
                    enableChild("OLE", 1);
                    enableChild("OLE_broken", 0);
                    enableChild("OLE_obstruction", 1);
                }*/
                else if(value == DAMAGED)
                {
                    enableChild("OLE", 0);
                    enableChild("OLE_broken", 1);
                    //enableChild("OLE_obstruction", 0);
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

    //  Class:          Features::ObstructionFixedOLE
    //
    //  Description:    Representation of a feature type. Contains the binding between
    //                  a feature type name and a factory function to create the associated
    //                  feature type (ExampleFeature).
    class ObstructionFixedOLEType : FeatureType
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
            return "ObstructionFixedOLE";
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
            return new ObstructionFixedOLE(info, properties);
        }
    };
}
#endif

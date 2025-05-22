//**************************************************************************************************
//
//  File:           MarkerPin.us.cpp
//
//  Description:    MarkerPin class definition.       
//
//  Reference:      Crossrail
//
//  Author:         Andy Cooper
//
//  (C) Copyright:  SYDAC Pty Ltd, 2015
//
//***************************************************************************************************

#ifndef MarkerPin_CPP
#define MarkerPin_CPP

// Paths not specified here since they are contained within this directory
#include <PoleFeature.us.cpp>

namespace Features
{
    class MarkerPin : PoleFeature
    {
    public:

        //  Function:     MarkerPin
        //
        //  Description:  Constructor for the class
        //

        MarkerPin(FeatureInfoExtern info, Properties properties, Node parent_node) : PoleFeature(info, properties, parent_node)
        {
        }
		
		//  Function:       isValid
        //
        //  Description:    Returns 1 if this is a valid MarkerPin Feature, 0 otherwise.
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
			
            // Handle Marker Pin Specific Propertied here, otherwise call down to the parent.
            if(property == "BallEnable")
			{
				ProjUtil::enablePathChildNode(getParentNode(), "Pole", "Head", value);
			}
            else
               PoleFeature::setNumber(property, value);

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
		   
		   // Process the Label
		   if (property == "MarkerLabel" && value != "XXXXXX")
		   {
				Node sign_node = ProjUtil::enablePathChildNode(getParentNode(), "Pole", "Sign", 1);

				if(sign_node == 0)
				{
					log.warning("%s (line %d): Feature %s(%d) : Property '%s' : value %s - Does not have a Pole/Sign Node\n",__FILE__, __LINE__, getName(), getID(), property, value);
				}
				else
				{
					// Labels processed by SwitchablePartFeature - Go straight there. 
				    SwitchablePartFeature::setString("MarkerLabel", value);
				}
			}
			// Properties that are specific to this Class, but are Double need to be cast to double and called again
			else if(property == "BallEnable")
		    {
			    setNumber(property, double(value));
		    }
		    else
			    PoleFeature::setString(property, value);

		}
    };

    //  Class:          Features::MarkerPinType
    //
    //  Description:    Representation of a feature Type Class. Contains the binding between
    //                  a feature type Class name and a factory function to create the associated
    //                  feature type Class.
    class MarkerPinType : FeatureType
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
            return "MarkerPin";
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
            return new MarkerPin(info, properties, parent);
        }
    };
}
#endif

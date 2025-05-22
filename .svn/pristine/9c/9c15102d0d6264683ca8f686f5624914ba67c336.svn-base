//**************************************************************************************************
//
//  File:           PoleFeature.us.cpp
//
//  Description:    PoleFeature class definition. 
//  
//                  This Class is for any Feature type that is mounted on a pole.
//                  The Feature Node is expected to have a Node called Pole at the top level of the hierarchy.
//                  The Entire Pole is to be contained in a mesh Surface called Body
//                  All components mounted on the pole must be Child Nodes of the Pole Node.
//
//                  This Class is designed to be used as a Base Class for other Pole Based Features. It makes
//                  functions available to get the Base or Parent Node.
//
//                  Supported Feature Properties:
//                  
//                  1/ HeightAdjust     - Moves the Pole and all Child Nodes Up or Down.   +ve = Up -ve = Down
//                  2/ HorizontalAdjust - Moves the Pole and all Child Nodes Left/Right.   +ve = Left -ve = Right
//                  3/ LateralAdjust    - Moves the Pole and all Child Nodes Away/Towards. +ve = Towards -ve = Away
//                  3/ PoleEnable       - Makes the Pole Visible/Invisible                  0 = Invisible anything else = Visible
//
//                  Note: Options 1 to 3 are to allow the Feature Graphics to be repositioned in the world without changing the Track Placement position.
//                        i.e. if a speed board is visible BEFORE a crossover, but must only be active at the start of the crossover, place it at the crossover, 
//                             and move it to the visible point with the options above.
//
//  Reference:      Crossrail
//
//  Author:         Andy Cooper
//
//  (C) Copyright:  SYDAC Pty Ltd, 2015
//
//***************************************************************************************************

#ifndef PoleFeature_CPP
#define PoleFeature_CPP

// Paths not specified here since they are contained within this directory
#include <Sydac/Core/Scripts/World/Features/SwitchablePartFeature.us.cpp>
#include <Utilities.us.cpp>
#include <AdjustablePart.us.cpp>

namespace Features
{
    class PoleFeature : SwitchablePartFeature
    {
	private:
	
        // Create an Adjustable Part for the Pole Child Node.
        ProjUtil::AdjustablePart m_pole;

    public:

        //  Function:     PoleFeature
        //
        //  Description:  Constructor for the class
        //

        PoleFeature(FeatureInfoExtern info, Properties properties, Node parent_node)
        {
			m_pole = new ProjUtil::AdjustablePart(this,"Pole");
			
			// Delay Construction until AdjustablePart has been constructed!
			__SwitchablePartFeature__(info, properties, parent_node);
        }
		
        //  Function:     ~PoleFeature
        //
        //  Description:  Destructor for the class
        //		
		~PoleFeature()
		{
			if (m_pole != 0) delete m_pole;
		}
		
		//  Function:       isValid
        //
        //  Description:    Returns 1 if this is a valid PoleFeature Feature, 0 otherwise.
        //
        //  Return value:
        //      int              - As above.

        int isValid()
        {
			if (m_pole != 0 && SwitchablePartFeature::isValid() == 1)
			{
               return 1;
			}
		   
		   return 0;
        }
		
		//  Function:       getParentNode
        //
        //  Description:    Gets the Parent Node associated with this Feature.
		//
		//  Note : This should be a Base Class Member Function.
        //
        Node getParentNode()
		{
			NodeWrapper nw   = getNode();
		    if (nw != 0)
			{
				return nw.getNode(0);
			}
			
			log.error("%s (line %d): Feature %s(%d) : Has a Bad NodeWrapper!\n",  __FILE__, __LINE__, getName(), getID());
			return 0;
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
			if (m_pole == 0)
			{
				log.error("%s (line %d): setNumber : Feature %s(%d) : m_pole is NULL!\n",  __FILE__, __LINE__, getName(), getID());
				return;
			}
			
		    //log.warning("%s (line %d): setNumber : Feature %s(%d) : Property '%s' : value %f\n",  __FILE__, __LINE__, getName(), getID(), property, value);
			
            // If we know about this property then use it. Otherwise call down to the parent.
            if(property == "HeightAdjust")
			{
                m_pole.setVerticalOffset(value);
			}
			else if(property == "HorizontalAdjust")
			{
                m_pole.setHorizontalOffset(value);
			}
			else if(property == "LateralAdjust")
			{
                m_pole.setLateralOffset(value);
			}
			else if(property == "PoleEnable")
			{
				ProjUtil::enablePathChildSurface(getParentNode(), "Pole", "body", value);
			}
            else
			{
			    // Pass all other number properties to the Base class. 
                SwitchablePartFeature::setNumber(property, value);
			}
        }

		//  Function:       setString
        //
        //  Description:    Sets a string property associated with this Feature.
		//
		//  HACK! = This assumes that any String property that casts to a number needs to be handled as a number!!!
		//          This will need looking into - Its a crash waiting to happen!
        //
        //  Parameters:
        //      string property  - The property name
        //      string value     - The property value
		void setString(string property, string value)
		{
		   //log.warning("%s (line %d): setString : Feature %s(%d) : Property '%s' : value %s\n",  __FILE__, __LINE__, getName(), getID(), property, value);

			 // Properties that are specific to this Class, but are Double need to be cast to double and called again 
			 if (property == "HeightAdjust" ||
			     property == "LateralAdjust" ||
				 property == "HorizontalAdjust" ||
				 property == "PoleEnable" )
			 {
				setNumber(property, double(value));
			 }
			 else
			 {
				 // Pass all other String properties to the Base class.
				 SwitchablePartFeature::setString(property, value); 
			 }
		
		}
    };

    //  Class:          Features::PoleFeatureType
    //
    //  Description:    Representation of a feature Type Class. Contains the binding between
    //                  a feature type Class name and a factory function to create the associated
    //                  feature type Class.
    class PoleFeatureType : FeatureType
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
            return "PoleFeature";
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
            return new PoleFeature(info, properties, parent);
        }
    };
}
#endif

//**************************************************************************************************
//
//  File:           BaliseFeature.us.cpp
//
//  Description:    BaliseFeature class definition
//
//  Reference:      tel_aviv
//
//  Author:         Andy Cooper
//
//  (C) Copyright:  SYDAC Pty Ltd, 2020
//
//***************************************************************************************************

#ifndef BALISE_FEATURE_CPP
#define BALISE_FEATURE_CPP

#include <RaycastableFeature.us.cpp>
#include <SingleNodeWrapper.us.cpp>

namespace Features
{
    //  Class:          Features::BaliseFeature
    //
    //  Description:    Represents the definition of a BaliseFeature, whose lighting can be controlled based on a Tunnel Parameter being defined for the feature.
    //
    class BaliseFeature : RaycastableFeature
    {

    public:

        //  Function:       BaliseFeature
        //
        //  Description:    Constructs a BaliseFeature with given properties and raycaster.
        //
        //  Parameters:
        //      FeatureInfoExtern info - The initial data for this BaliseFeature.
        //      Properties properties - The configuration used to create this object.
        //      Node parent_node - The parent node to this feature object.

        BaliseFeature(FeatureInfoExtern info, Properties properties, Node parent_node)
        {
            __RaycastableFeature__(info, new SingleNodeWrapper(info.getNodeFileName(), info.getName(), parent_node), properties);

            if(isValid() == 0)
                log.error("Unable to correctly load node %s - Feature construction for feature id %d failed\n", info.getNodeFileName(), info.getID());
            else
            {
                // Don't allow intersection for this feature type
                NodeWrapper(getNode()).setIntersection(0);
            }
        }

        //  Function:       ~BaliseFeature
        //
        //  Description:    Destructor. Cleans up if necessary.

        ~BaliseFeature()
        {
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
            //log.warning("%s (line %d): setNumber : Feature %s(%d) : Property '%s' : value %d\n",  __FILE__, __LINE__, getName(), getID(), property, value);

            {
              // Pass all other number properties to the Base class.
              RaycastableFeature::setNumber(property, value);
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
            // Pass all other number properties to the Base class.
            RaycastableFeature::setString(property, value);
        }

    };

    //  Class:          Features::BaliseFeatureType
    //
    //  Description:    Logically abstract definition of a feature type, this class contains
    //                  methods required to bind a feature type name with a factory function
    //                  used to create a feature.
    //
    class BaliseFeatureType : FeatureType
    {
    public:
        string getName()
        {
            return "BaliseFeature";
        }

        BaliseFeature createFeature(FeatureInfoExtern info, Properties properties, Node parent)
        {
            return new BaliseFeature(info, properties, parent);
        }
    };
}

#endif

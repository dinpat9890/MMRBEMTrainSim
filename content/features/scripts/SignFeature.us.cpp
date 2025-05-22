//**************************************************************************************************
//
//  File:           SignFeature.us.cpp
//
//  Description:    SignFeature class definition.       
//
//  Reference:      Tekl Aviv
//
//  Author:         Andy Cooper
//
//  (C) Copyright:  SYDAC Pty Ltd, 2020
//
//***************************************************************************************************

#ifndef SignFeature_CPP
#define SignFeature_CPP

// Paths not specified here since they are contained within this directory
#include <PoleFeature.us.cpp>

namespace Features
{
    class SignFeature : PoleFeature
    {   
        private:
            
            
        public:

        //  Function:     SignFeature
        //
        //  Description:  Constructor for the class
        //

        SignFeature(FeatureInfoExtern info, Properties properties, Node parent_node)
        {
            
            // Unless you call the base Constructors after creating the things you need first 
            // i.e. (Remove the : Polefeature call above and replace with __PoleFeature__(info, properties, parent_node) here.
            __PoleFeature__(info, properties, parent_node);
            
        }
        
        //  Function:     ~SignFeature
        //
        //  Description:  Destructor for the class
        //      
        ~SignFeature()
        {
        }
        
        //  Function:       isValid
        //
        //  Description:    Returns 1 if this is a valid SignFeature Feature, 0 otherwise.
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
            
            if(property == "XXX")
            {
                
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

            if (property == "Arrows")
            {
                if (value == "Left" || value == "Right" || value == "None")
                {
                   // Find the Mount Node
                   Node arrows_node = ProjUtil::findPathNode(getParentNode(), "Pole/Arrows");
                   
                  // Idiot Proof
                  if (arrows_node == 0) 
                  {
                     log.warning("%s (line %d): Feature %s(%d) : Property '%s' : value %s - Does not have a Pole/Arrows Node\n",__FILE__, __LINE__, getName(), getID(), property, value);
                  }
                      
                   else
                   {
                        // Disable both
                        ProjUtil::enableChildSurface(arrows_node, "LeftArrow", 0);
                        ProjUtil::enableChildSurface(arrows_node, "RightArrow", 0);
                         
                        // Enable the Arrow Surfaces specified (Note this is an Enable Only option. The Default is disabled)
                        if (value == "Left")
                        {    
                            ProjUtil::enableChildSurface(arrows_node, "LeftArrow", 1);
                            ProjUtil::enableChildSurface(arrows_node, "RightArrow", 0);
                        }
                        else if (value == "Right")
                        {
                            ProjUtil::enableChildSurface(arrows_node, "RightArrow", 1);
                            ProjUtil::enableChildSurface(arrows_node, "LeftArrow", 0);
                        }
                   }    
                }
                else
                {
                    log.warning("%s (line %d): Feature %s(%d) : Property '%s' has unknown value of %s. Valid Values are Left, Right, None\n",__FILE__, __LINE__, getName(), getID(), property, value);  
                }
            }
            // Handle Side Property
            if(property == "Mount")
            {
                if (value == "Left" || value == "Right" || value == "LeftTunnel" || value == "RightTunnel" || value == "None")
                {
                   // Find the Sign and Bracket Nodes
                   Node mount_node = ProjUtil::findPathNode(getParentNode(), "Pole/Mount");
                   
                  // Idiot Proof
                  if (mount_node == 0) 
                  {
                     log.warning("%s (line %d): Feature %s(%d) : Property '%s' : value %s - Does not have a Pole/Mount Node\n",__FILE__, __LINE__, getName(), getID(), property, value);
                  }
                      
                   else
                   {
                        // Disable all
                        ProjUtil::enableChildSurface(mount_node,"Left_Tunnel", 0);
                        ProjUtil::enableChildSurface(mount_node,"Right_Tunnel", 0); 
                        ProjUtil::enableChildSurface(mount_node,"Left", 0);
                        ProjUtil::enableChildSurface(mount_node,"Right", 0);
                         
                        // Enable the Mount Surfaces specified (Note this is an Enable Only option. The Default is disabled)
                        if (value == "Left")
                        {    
                            ProjUtil::enableChildSurface(mount_node,"Left_Tunnel", 0);
                            ProjUtil::enableChildSurface(mount_node,"Right_Tunnel", 0); 
                            ProjUtil::enableChildSurface(mount_node,"Left", 1);
                            ProjUtil::enableChildSurface(mount_node,"Right", 0);
                        }
                        if (value == "LeftTunnel")
                        {    
                            ProjUtil::enableChildSurface(mount_node,"Left_Tunnel", 1);
                            ProjUtil::enableChildSurface(mount_node,"Right_Tunnel", 0); 
                            ProjUtil::enableChildSurface(mount_node,"Left", 0);
                            ProjUtil::enableChildSurface(mount_node,"Right", 0);
                        }
                        else if (value == "Right")
                        {
                            ProjUtil::enableChildSurface(mount_node,"Right_Tunnel", 0);
                            ProjUtil::enableChildSurface(mount_node,"Left_Tunnel", 0);
                            ProjUtil::enableChildSurface(mount_node,"Left", 0);
                            ProjUtil::enableChildSurface(mount_node,"Right", 1);
                        }
                        else if (value == "RightTunnel")
                        {
                            ProjUtil::enableChildSurface(mount_node,"Right_Tunnel", 1);
                            ProjUtil::enableChildSurface(mount_node,"Left_Tunnel", 0);
                            ProjUtil::enableChildSurface(mount_node,"Left", 0);
                            ProjUtil::enableChildSurface(mount_node,"Right", 0);
                        }
                   }    
                }
                else
                {
                    log.warning("%s (line %d): Feature %s(%d) : Property '%s' has unknown value of %s. Valid Values are Left, Right, LeftTunnel, RightTunnel, None\n",__FILE__, __LINE__, getName(), getID(), property, value);  
                }
            }
            else if (property == "XXX")
            {
                SignFeature::setNumber(property, double(value));       
            }
            // Else Pass the parameter down to PoleFeature Class.
            else
            {
                PoleFeature::setString(property, value);
            }

        }
    };

    //  Class:          Features::SignFeatureType
    //
    //  Description:    Representation of a feature Type Class. Contains the binding between
    //                  a feature type Class name and a factory function to create the associated
    //                  feature type Class.
    class SignFeatureType : FeatureType
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
            return "SignFeature";
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
            return new SignFeature(info, properties, parent);
        }
    };
}
#endif

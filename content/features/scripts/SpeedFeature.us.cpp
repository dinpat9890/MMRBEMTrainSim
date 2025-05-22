//**************************************************************************************************
//
//  File:           SpeedFeature.us.cpp
//
//  Description:    SpeedFeature class definition.       
//
//  Reference:      Crossrail
//
//  Author:         Andy Cooper
//
//  (C) Copyright:  SYDAC Pty Ltd, 2017
//
//***************************************************************************************************

#ifndef SpeedFeature_CPP
#define SpeedFeature_CPP

// Paths not specified here since they are contained within this directory
#include <PoleFeature.us.cpp>
#include <AdjustablePart.us.cpp>

namespace Features
{
    class SpeedFeature : PoleFeature
    {   
        private:    
            // Create an Adjustable Part for the Head Node.
         ProjUtil::AdjustablePart m_sig_head;
       
        public:

        //  Function:     SpeedFeature
        //
        //  Description:  Constructor for the class
        //

        SpeedFeature(FeatureInfoExtern info, Properties properties, Node parent_node)
        {
            // NOTE - You cannot use anything built in the Constructor in the setNumber or setString callbacks as they get
            //        called by the stupid Base Constructors before all of this has taken place!    
           m_sig_head = new ProjUtil::AdjustablePart(this,"Pole/Head");
        
            // Unless you call the base Constructors after creating the things you need first 
            // i.e. (Remove the : Polefeature call above and replace with __PoleFeature__(info, properties, parent_node) here.
            __PoleFeature__(info, properties, parent_node);
            
        }
        
        //  Function:     ~SpeedFeature
        //
        //  Description:  Destructor for the class
        //      
        ~SpeedFeature()
        {
        }
        
        //  Function:       isValid
        //
        //  Description:    Returns 1 if this is a valid SpeedFeature Feature, 0 otherwise.
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
            //log.message("%s (line %d): setString : Feature %s(%d) : Property '%s' : value %d\n",  __FILE__, __LINE__, getName(), getID(), property, value);
            
            // If we know about this property then use it. Otherwise call down to the parent.
            if (property == "Virtual")
            {
                  // Turn off the whole lot to make it invisible
                  ProjUtil::enableChildNode(getParentNode(), "Pole", (value == 0)); 
            }
            else if (property =="State")
            {
                     
                // NB! This Requires that the State ID is the Speed in kph!!!!
                 
                // Convert number to text string 
                string txt = format("%u",value);
                 
                 // Pad the value to 2 characters (leading zero's)
                if (strlen(txt) < 2)
                {
                   txt = "0" + txt;
                }
                   
                // Speed limited to 2 characters
                if (strlen(txt) > 2)
                {
                    txt = substr(txt,0,2);
                }

                // Send the 1st character to Label1   
                SwitchablePartFeature::setString("Label1", substr(txt,0,1));
                // Send the 2nd character to Label2   
                SwitchablePartFeature::setString("Label2", substr(txt,1,1));
                    
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
            //log.message("%s (line %d): setString : Feature %s(%d) : Property '%s' : value %s\n",  __FILE__, __LINE__, getName(), getID(), property, value);
            
            // TODO - "Initial State" comes through as a String (As does the default state in Manual Vision!) 
            //        Convert the string "xx km/h" to the number xx and call setNumber("State", xx) to initialise Labels in Manual Vision.
            //        Need to test this with database session!
           
            // Handle Side Property
            if(property == "Mount")
            {
                if (value == "Left" || value == "Right" || value == "None")
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
                        ProjUtil::enableChildSurface(mount_node,"Left_tunnel", 0);
                        ProjUtil::enableChildSurface(mount_node,"Right_tunnel", 0); 
                        ProjUtil::enableChildSurface(mount_node,"Left", 0);
                        ProjUtil::enableChildSurface(mount_node,"Right", 0);
                         
                        // Enable the Sign Surfaces specified (Note this is an Enable Only option. The Default is disabled)
                        if (value == "Left")
                        {    
                            ProjUtil::enableChildSurface(mount_node,"Left_tunnel", 1);
                            ProjUtil::enableChildSurface(mount_node,"Right_tunnel", 0); 
                            ProjUtil::enableChildSurface(mount_node,"Left", 0);
                            ProjUtil::enableChildSurface(mount_node,"Right", 0);
                        }
                        else if (value == "Right")
                        {
                            ProjUtil::enableChildSurface(mount_node,"Right_tunnel", 1);
                            ProjUtil::enableChildSurface(mount_node,"Left_tunnel", 0);
                            ProjUtil::enableChildSurface(mount_node,"Left", 0);
                            ProjUtil::enableChildSurface(mount_node,"Right", 0);
                        }
                   }    
                }
                else
                {
                    log.warning("%s (line %d): Feature %s(%d) : Property '%s' has unknown value of %s. Valid Values are Left, Right, None\n",__FILE__, __LINE__, getName(), getID(), property, value);  
                }
            }
            else if (property == "Speed")
            {
                string txt = value;
                
                if (strlen(txt) >= 1)
                {
                    
                    // Pad the value to 2 characters (leading zero's)
                    if (strlen(txt) < 2)
                    {
                       txt = "0" + txt;
                    }
                       
                       // Speed limited to 2 characters
                    if (strlen(txt) > 2)
                    {
                        txt = substr(txt,0,2);
                    }

                    // Send the 1st character to Label1   
                    SwitchablePartFeature::setString("Label1", substr(txt,0,1));
                    // Send the 2nd character to Label2   
                    SwitchablePartFeature::setString("Label2", substr(txt,1,1));
                }
                
            }
         
            // Properties that are specific to this Class, but are Double need to be cast to double and called again
            else if (property == "Virtual")
            {
                SpeedFeature::setNumber(property, double(value));        
            }

            // Else Pass the parameter down to PoleFeature Class.
            else
            {
                PoleFeature::setString(property, value);
            }

        }
    };

    //  Class:          Features::SpeedFeatureType
    //
    //  Description:    Representation of a feature Type Class. Contains the binding between
    //                  a feature type Class name and a factory function to create the associated
    //                  feature type Class.
    class SpeedFeatureType : FeatureType
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
            return "SpeedFeature";
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
            return new SpeedFeature(info, properties, parent);
        }
    };
}
#endif

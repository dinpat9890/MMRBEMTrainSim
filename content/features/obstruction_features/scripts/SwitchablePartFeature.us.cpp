//**************************************************************************************************
//
//  File:           SwitchablePartFeature.us.cpp
//
//  Description:    SwitchablePartFeature class definition
//
//  Reference:      95809A9A
//
//  Author:         Craig Biggs
//
//  (C) Copyright:  SYDAC Pty Ltd, 2013
//
//***************************************************************************************************

#ifndef SWITCHABLE_PART_FEATURE_CPP
#define SWITCHABLE_PART_FEATURE_CPP

// Paths not specified here since they are contained within this directory
#include <features/RaycastableFeature.us.cpp>
#include <features/Label.us.cpp>
#include <core/scripts/tuple.h>
#include <core/scripts/array.h>

namespace Features
{
    string TIME_ON_PARAMETER    = "TimeOn";
    string TIME_OFF_PARAMETER   = "TimeOff";
    string START_TIME_PARAMETER = "StartTime";
    string FLASHING_PROPERTY    = "FlashingLight";
    
    //  Class:          Features::SwitchablePartFeature
    //
    //  Description:    This class is a representation of a feature that has one
    //                  or more parts that can be switched on and off. This is akin
    //                  to switching surfaces on and off in a Unigine mesh.
    class SwitchablePartFeature : RaycastableFeature
    {
    private:
    
        //  Class:          FlashingContent
        //
        //  Description:    Logically a struct, this class allows us to store
        //                  information about content that is relevant to setting
        //                  flashing information.
        class FlashingContent
        {
            WorldExpression expression;
            int             on_property;
            int             off_property;
            int             start_property;
            
            //  Function:       FlashingContent
            //
            //  Description:    Constructor. Initialises all member data.
            //
            FlashingContent(WorldExpression expr, int on, int off, int start)
            {
                expression      = expr;
                on_property     = on;
                off_property    = off;
                start_property  = start;
            }
        };

        //  Class:          PartContent
        //
        //  Description:    Logically a struct, this class allows us to store
        //                  information about content that is relevant to setting
        //                  part information.
        class PartContent
        {
            string           part_name;
            ObjectMeshStatic mesh;
            int              surface;
            FlashingContent  flashing_content;
            
            //  Function:       PartContent
            //
            //  Description:    Constructor. Initialises all member data.
            //
            PartContent(string part, ObjectMeshStatic om, int surf, FlashingContent fc)
            {
                part_name           = part;
                mesh                = om;
                surface             = surf;
                flashing_content    = fc;
            }
        };
    
        //  Class:          FlashingContent
        //
        //  Description:    Logically a struct, this class allows us to store
        //                  information about a state's surface settings including
        //                  the flashing information for the state.
        class SurfaceStateInfo
        {
            string          part_name;
            int             flashing;
            double          pulse_delay;
            double          pulse_on_time;
            double          pulse_off_time;
            
            //  Function:       PartContent
            //
            //  Description:    Constructor. Initialises all member data.
            //
            SurfaceStateInfo(string part, int flash, double delay, double on_time, double off_time)
            {
                part_name       = part;
                flashing        = flash;
                pulse_delay     = delay;
                pulse_on_time   = on_time;
                pulse_off_time  = off_time;
            }
        };
    
        PartContent             m_contents[];       // Part name to part content
        Unigine::Pair           m_surface_access[]; // Maps from a xpath'd surface name to a ObjectMesh, surface pair
        Unigine::Vector         m_states[];         // Map from state id to a vector of SurfaceStateInfo
        int                     m_valid;
        World::Features::Label  m_labels[];
    
        //  Function:       initialiseSurfaceAccess
        //
        //  Description:    Populates this feature's surface hierarchy information into an xpath
        //                  so that we can access surfaces via xpath notation in a quick fashion. 
        //
        //  Parameters:
        //      FeatureInfoExtern info - The FeatureInfoExtern containing state information.
        
        void initialiseSurfaceAccess()
        {
            NodeWrapper nw = getNode();
            Node master    = nw.getNode(0);
            
            // This helper function recursively traverses the node hierarchy under this
            // feature node, building up a map of surface number/mesh pairs based on
            // xpath string to access them
            void populate(string path, Node current)
            {
                if(current.getType() == NODE_OBJECT_MESH_STATIC)
                {
                    // Add the xpath for each surface under the mesh
                    ObjectMeshStatic om = node_cast(current);
                    forloop(int i = 0; om.getNumSurfaces())
                        m_surface_access[format("%s%s", path, om.getSurfaceName(i))] = new Unigine::Pair(om, i);
                }
                
                // Populate surface access children - recursive traversal
                forloop(int i = 0; current.getNumChildren())
                {
                    Node child = current.getChild(i);
                    populate(format("%s%s/", path, child.getName()), child);
                }
            }
            
            // Initiate population from the master node
            populate("", master);
        }
        
        //  Function:       initialiseContent
        //
        //  Description:    Populates this features surface information based on the info struct
        //                  passed in.
        //
        //  Parameters:
        //      FeatureInfoExtern info - The FeatureInfoExtern containing state information.
        
        int initialiseContent(FeatureInfoExtern info)
        {
            int success    = 1;
            
            initialiseSurfaceAccess();
            
            // Check that all required switchable parts have associated surfaces
            string part_names[0];
            info.getPartNames(part_names);
            
            foreach(string part_name; part_names)
            {
                Unigine::Pair surface_access = m_surface_access.check(part_name, 0);
                if(surface_access != 0)
                {
                    FlashingContent flashing_content = 0;
                    ObjectMeshStatic om              = surface_access.first;
                    int surface_number               = surface_access.second;
               
                    // In the case where we have flashing nodes, there'll be a WorldExpression representing the flashing behaviour
                    // of the same name as the surface. Find this if possible
                    int we_index  = om.findChild(om.getSurfaceName(surface_number));
                
                    // If the WorldExpression node was found, we need to check that the WorldExpression node has the appropriate
                    // Property with the correct parameters. If it does, then we can create the FlashingContent object to represent
                    // the flashing content information
                    if(we_index != -1)
                    {
                        Node n        = om.getChild(we_index);
                        Property prop = n.getProperty();
                        if(n.getType() == NODE_WORLD_EXPRESSION && prop != 0 && prop.getName() == FLASHING_PROPERTY)
                            flashing_content = new FlashingContent(node_cast(n), prop.findParameter(TIME_ON_PARAMETER), prop.findParameter(TIME_OFF_PARAMETER), prop.findParameter(START_TIME_PARAMETER));
                    }
     
                    // Establish a relationship between part name and the content information. So that when instructed to
                    // turn a part on/off we can easily enable/disable the corresponding surface and set the WorldExpression
                    // parameters.
                    m_contents[part_name] = new PartContent(part_name, om, surface_number, flashing_content);
                }
                else
                {
                    success = 0;
                    log.error("Unable to find part %s for feature id %d in node file %s\n", part_name, getID(), info.getNodeFileName());
                    break;
                }
            }
            return success;
        }
        
        //  Function:       disableAllPartContent
        //
        //  Description:    Disables all surfaces on the meshes associated with this feature.
        //                  Also disables WorldExpression nodes if necessary.
        //
        void disableAllPartContent()
        {
            // Disable surfaces and WorldExpression nodes
            foreach(PartContent content; m_contents)
            {
                content.mesh.setEnabled(0, content.surface);
                if(content.flashing_content != 0)
                    content.flashing_content.expression.setEnabled(0);
            }
        }
        
        //  Function:       initialiseStates
        //
        //  Description:    Populates this SwitchablePartFeature with state information as specified
        //                  by the FeatureInfoExtern.
        //
        //  Parameters:
        //      FeatureInfoExtern info - The FeatureInfoExtern containing state information.
        
        int initialiseStates(FeatureInfoExtern info)
        {
            int success = 1;
            FeaturePartExtern feature_parts[] = ();
            
            info.getModelStateParts(feature_parts);
            
            // Essentially translates the FeaturePartExtern structure which contains state-part mappings
            // into our internal SurfaceStateInfo structure
            foreach(FeaturePartExtern fp; feature_parts)
            {
                int state                = fp.getStateID();
                int flashing             = fp.getFlashing(); 
                PartContent part_content = m_contents[fp.getPartName()];
                
                // If the flashing state doesn't match our content then this is an error
                if(flashing && part_content.flashing_content == 0)
                {
                    log.error("Unable to find correct world expression child for part with name %s in feature with id %d. Please fix your content\n", part_content.part_name, getID()); 
                    success = 0;
                    break;
                }
                
                // For the current state, append the SurfaceStateInfo to the vector of objects for the current state (creating the vector if necessary).
                SurfaceStateInfo state_info = new SurfaceStateInfo(part_content.part_name, flashing, fp.getPulseDelay(), fp.getPulseOnTime(), fp.getPulseOffTime());
                if(m_states.check(state))
                    m_states[state].append(state_info);
                else
                    m_states[state] = new Unigine::Vector((state_info));
            }    
            return success;
        }
         
        //  Function:       initialiseLabels
        //
        //  Description:    Initialize all labels of the given mesh.
        //
        //  Return value:
        //      int             - Returns 1 if this function was successful,
        //                        0 otherwise.

        int initialiseLabels()
        {
            int success = 1;
            
            foreachkey(string part_name; m_surface_access)
            {
                Unigine::Pair surface_access = m_surface_access[part_name];
                ObjectMeshStatic mesh        = surface_access.first;
                int surface_number           = surface_access.second;
                
                // make a Label class instance for each surface with a "Label" 
                // property.
                Geometry::SurfaceRef surface = Geometry::getSurfaceRef(mesh, surface_number);
                Property property = surface.getPropertyInherit();
                if(property != 0 && property.getName() == "Label")
                {
                    World::Features::Label label = new World::Features::Label(surface);
                    
                    // Only keep the label object if it is valid - otherwise discard and log the error to the user
                    if(label.isValid())
                        m_labels[part_name] = label;
                    else
                    {
                       log.error("Failed to create label for surface %s for node %s feature %d\n", mesh.getSurfaceName(surface_number), mesh.getName(), getID());
                       success = 0;
                       break;
                    }
                }
            }
            return success;
        }

        //  Function:       setLabelString
        //
        //  Description:    Sets a label string property associated with this Feature.
        //
        //  Parameters:
        //      string property  - The label name
        //      double value     - The label value

        void setLabelString(string property, string value)
        { 
            // Iterates over all labels and sets the property for each label
            foreach(World::Features::Label label; m_labels)
            {
                label.setString(property, value);
            }
        }
        
    public:

        //  Function:     SwitchablePartFeature
        //
        //  Description:  Constructor for the SwitchablePartFeature class
        //

        SwitchablePartFeature(FeatureInfoExtern info, Properties properties, Node parent_node)
        {
            __RaycastableFeature__(info, new SingleNodeWrapper(info.getNodeFileName(), Features::makeDescriptorForFeature(info), parent_node), properties);
            
            m_valid = 0;
            NodeWrapper single_node = getNode();

            // Ensure that the feature node is loaded and the node type is an object mesh
            if (single_node.isValid() == 1)
                m_valid = Feature::isValid() && initialiseContent(info) && initialiseStates(info) && initialiseLabels(); 
                
            // The use of this success boolean is quite annoying but the lack of exceptions
            // in Unigine script mandate it (unless you want to use something like a goto,
            // which is even more gross)
            if (m_valid == 0)
            {
                log.error("Unable to correctly load node %s - Feature construction for feature id %d failed\n", info.getNodeFileName(), info.getID());
            }
            else
            {
                // Turn off all parts as well cant assume they are not enabled at loading
                disableAllPartContent();
                
                // Don't allow switchable part features to raycast to themselves
                single_node.setIntersection(0);
            }
        }

        //  Function:       ~SwitchablePartFeature
        //
        //  Description:    Cleans up allocated resources.
        
        ~SwitchablePartFeature()
        {
            m_labels.delete();
            m_contents.delete();
            m_surface_access.delete();
            m_states.delete();
        }

        //  Function:       isValid
        //
        //  Description:    Returns 1 if this is a valid SwitchablePartFeature, 0 otherwise.
        //
        //  Return value:
        //      int              - As above.

        int isValid()
        {
            return m_valid;
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
            if(property == "State")
            {
                disableAllPartContent();
                
                Unigine::Vector surfaces = m_states.check(int(value), 0);
                double time              = Timing::getTime();
                
                // If this is the case then it may be still valid eg when all parts are off
                if(surfaces != 0)
                {
                    // For each part that needs to be turned on, enable the relevant surfaces.
                    foreach(SurfaceStateInfo state_info; surfaces.data)
                    {
                        PartContent part_content = m_contents[state_info.part_name];
                        
                        // If there's flashing, surface enable/disable is performed by the WorldExpression.
                        // Otherwise, surface control is performed by this script.
                        if(state_info.flashing)
                        {
                            FlashingContent fc = part_content.flashing_content;
                            Property prop      = fc.expression.getProperty();
                            
                            // Set the parameters for the WorldExpression and enable the WorldExpression
                            prop.setParameterFloat(fc.on_property, state_info.pulse_on_time);
                            prop.setParameterFloat(fc.off_property, state_info.pulse_off_time);
                            prop.setParameterFloat(fc.start_property, state_info.pulse_delay + time);
                            fc.expression.setEnabled(1);
                        }
                        else
                            part_content.mesh.setEnabled(1, part_content.surface);

                        // Please see https://adls0021.corp.knorr-bremse.com/jira/browse/CHLTRN-1518 as to why
                        // this is necessary. Bascially it seems that Unigine have put a hack in their own editor
                        // when a surface is enabled and disabled via the Editor UI. This seems to ensure that the
                        // materials are correctly refreshed when a surface is enabled and disabled. There seems
                        // no reason why this should happen, but by inserting this line of code, it resolves a bug
                        // in the visual appearance of a surface when impacted by headlights at night time.
                        part_content.mesh.setSpatial(part_content.mesh.isSpatial());
                    }
                }
            }
            // note: value is double so we must convert it to string.
            setLabelString(property, string(value));
        }
        
        //  Function:       setString
        //
        //  Description:    Sets a string property associated with this Feature.
        //
        //  Parameters:
        //      string property  - The property name
        //      double value     - The property value

        void setString(string property, string value)
        {
            setLabelString(property, value);
        }
    };

    //  Class:          Features::SwitchablePartFeatureType
    //
    //  Description:    Representation of a feature type. Contains the binding between
    //                  a feature type name and a factory function to create the associated
    //                  feature type (SwitchablePartFeature).
    class SwitchablePartFeatureType : FeatureType
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
            return "SwitchablePartFeature";
        }

        //  Function:       createFeature
        //
        //  Description:    Factory function - creates a SwitchablePartFeature using
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
            return new SwitchablePartFeature(info, properties, parent);
        }
    };
}
#endif

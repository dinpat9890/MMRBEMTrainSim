///
/// @file       ProjectUtilities.us.cpp
///
/// @ingroup    95809A9A
///
/// @author     Andy Cooper
///
/// @copyright  SYDAC Pty Ltd, 2015
///

#ifndef PROJECT_UTILITIES_US_CPP
#define PROJECT_UTILITIES_US_CPP

namespace ProjUtil
{
    
    /// @brief Adds Character c between each character in the base_string.
    ///
    /// This function adds a character between each character if a base string.
    /// This is used for adding the character separator to vertical text
    ///
    /// @code
    ///    string new = insertCharsBetween("|", textstring);
    
    /// @param c
    ///        The character to insert (As a string)
    /// @param base_string
    ///        The string to use as a base
    /// @return Copy of Base String with c inserted between each pair of characters
    string insertCharsBetween(string c, string base_string)
    {
        string return_value = "";
        int size = strlen(base_string);

        forloop(int i = 0; size)
        {
            return_value += substr(base_string, i, 1);
        
            if(i < size-1)
                return_value += c;
        }

        return return_value;
    }
    
    /// @brief Sets the enable state of a Child of a node, identified by name
    //         Returns a child of a node, or <code>NULL</code> if the child does
    ///        not exist.
    ///
    /// @param node Node object to search.
    /// @param name Name of the child node to find.
    /// @param enable = 0 to disable, 1 to enable
    ///
    /// @return The child node, or <code>NULL</code> if the direct child does not exist.
    Node enableChildNode(Node parent_node, string name, int enable)
    {
        int id = parent_node.findChild(name);
			   
		if (id != -1)
	    {			   
	       Node child = parent_node.getChild(id);
		   
           if (enable > 1)
		   {
			   enable = 1;
		   }
		   
		   if (enable < 0)
		   {
			   enable = 0;
		   }
		   
		   child.setEnabled(enable);
		  
           return child;           
	    }
        else
        {
           //log.warning("%s (line %d): Child node %s not found\n",__FILE__, __LINE__, name);
        }
        
        return NULL;
    }
	
	// Utility Function to Find an immediate Child Node of the supplied Node
    // Return null if the child does not exist (Or if the Supplied Node is Null)
    // This is designed to be used in recursive fashion to find nodes in a hierarchy
    // e.g. Node child_node  = findChildNode(findChildNode(findChildNode(parent_node, "Pole"),"SignalLabel"), property);
    // can be used to find the Node Pole/SignalLabel/property
    //
    Node findChildNode(Node node, string name)
    {
        if(node != 0)
        {
            int CHILD_ID = node.findChild(name);
            if(CHILD_ID != -1)
                return node.getChild(CHILD_ID);
        }
    
        return NULL;
    }
	
    /// This function will search a named Node path for a matching end child node.
	/// The function returns 0 if none is found. 
    ///
    /// @param parent_node  The node under which to search.
    /// @param node_path    The Path of child node names separated by '\' characters.
	///
	Node findPathNode(Node parent_node, string node_path)
	{
		
		Node n = parent_node;
		
		if (n != 0)
		{
		   	string tokens[0];
			int num_tokens = strsplit(node_path, "/", tokens );
			
			for(int i = 0; i < num_tokens; i++)
            {
                int child_id = n.findChild(tokens[i]);    
                if (child_id == -1)
                {
					//log.warning("%s (line %d): Child node '%s' not found in path %s\n",__FILE__, __LINE__, tokens[i], node_path);
					return NULL;
				}
                else				
				{
					n = n.getChild(child_id);
				}
            }
		}
		else
		{
			log.warning("%s (line %d): The Parent node of path '%s' is not valid\n",__FILE__, __LINE__, node_path);
		}
		
		return n;
	}
	
	// Search a Node path for a child node and Enable/Disable it.
	Node enablePathChildNode(Node parent_node, string path, string child_node_name, int value)
	{
		if (value == 0 || value == 1)
        {
			Node n = findPathNode(parent_node, path);
			
			if (n != 0)
			{
				return enableChildNode(n, child_node_name, value);
			}
		}
		
		return NULL;
	}
	
	// Turn a Surface of the parent Node On/Off
	void enableChildSurface(Node parent_node, string child_surface_name, int value)
	{
		// Idiot Proof it 
	   if (value > 1)
	   {
		   value = 1;
	   }
	   if (value < 0)
	   {
		   value = 0;
	   }
	   
	   if(parent_node != 0)
	   {
		   if (parent_node.isObject())
		   {
			   Object obj = node_cast(parent_node);
			   
			   if (obj != 0)
			   {
				  int index = obj.findSurface(child_surface_name);
			   
				  if (index != -1)
				  {
					 obj.setEnabled(value, index);
				  }
				  else
				  {
					 log.error("%s (line %d): Could not find Surface '%s' in Node %s\n",__FILE__, __LINE__, child_surface_name, parent_node.getName());
				  }
			   }
			   else
			   {
				  log.error("%s (line %d): Could not cast node %s to ObjectMesh\n",__FILE__, __LINE__, parent_node.getName());
			   }
		   }
		   else
		   {
			   log.error("%s (line %d): Node %s is not an Object Mesh Node\n",__FILE__, __LINE__, parent_node.getName());
		   }
	   }
	}
	
	// Turn a Path Node Surface on/off
	void enablePathChildSurface(Node parent_node, string path, string child_surface_name, int value)
	{	
	   
	   // NB - The Node at the end of the path must be an Object Mesh node.
	   enableChildSurface(findPathNode(parent_node, path), child_surface_name, value);
	   
	}

} // namespace ProjectUtilities

#endif

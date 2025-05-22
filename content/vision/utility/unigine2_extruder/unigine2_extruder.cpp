#include <utilities/Namespaces.us.cpp>

#include <core/unigine.h>

using Unigine::Widgets;

extruder g_extruder;
int      g_updating_splines = FALSE;

string getName()
{
	return "unigine2_extruder";
}

namespace unigine2_extruder
{
    PluginMeta meta;

    Window 	window;
    
    string  last_template_node_path = "";

    void cancel_clicked()
	{
		windowHide(window, meta.name);
	}

    void create_clicked()
    {
        // Select the template node
        
        // Initialize the file dialog
		
        string current_path = absname(engine.getDataPath(), last_template_node_path);

		DialogFile file_dialog = new DialogFile("Select the template node");
        file_dialog.setFile(current_path);
        file_dialog.setFilter(".node");
		
		// Show model
		
		addChild(file_dialog, ALIGN_OVERLAP | ALIGN_CENTER);
		file_dialog.setPermanentFocus();
		while(file_dialog.isDone() == false) wait;
		removeChild(file_dialog);
		
		// Extract the template path and create the node hierarchy
		
		if(file_dialog.isOkClicked() == true)
		{
            string new_file_path = file_dialog.getFile();
            string template_node_path = relname(pathname(engine.getDataPath()), new_file_path);
            
            NodeDummy extrude_node = new NodeDummy();
            extrude_node.setName("new_extrude");
            extrude_node.setProperty("extrude");
            
            Player editor_player = engine.editor.getPlayer();
            extrude_node.setWorldPosition(editor_player.getWorldPosition());
            
            NodeReference template_node = new NodeReference(template_node_path);
            template_node.setName("template");
            template_node.setEnabled(false);
            extrude_node.addChild(template_node);

            NodeDummy spline_node = new NodeDummy();
            spline_node.setName("spline");
            extrude_node.addChild(spline_node);
            
            NodeDummy knot0_node = new NodeDummy();
            knot0_node.setName("knot0");
            spline_node.addChild(knot0_node);
            knot0_node.setPosition(Vec3(editor_player.getWorldForward() + editor_player.getWorldLeft())); 

            NodeDummy knot1_node = new NodeDummy();
            knot1_node.setName("knot1");
            spline_node.addChild(knot1_node);
            knot1_node.setPosition(Vec3(editor_player.getWorldForward() - editor_player.getWorldLeft())); 

            engine.editor.addNode(extrude_node);
            
            last_template_node_path = template_node_path;
		}
    }
}

/******************************************************************************\
*
* Main functions
*
\******************************************************************************/

void init(PluginMeta meta)
{	
    g_extruder = new extruder();
	string error_message = g_extruder.get_error_message();
	if(error_message != NULL)
	{
		WidgetDialogMessage dialog = new WidgetDialogMessage(engine.getGui(), "Extruder import error");
		WidgetButton cancel_button = dialog.getCancelButton();
		Widget parent = cancel_button.getParent();
		parent.removeChild(cancel_button);
		dialog.setMessageText(error_message);
		engine.gui.addChild(dialog, GUI_ALIGN_OVERLAP | GUI_ALIGN_CENTER);
		dialog.setPermanentFocus();
		while(dialog.isOkClicked() != 1)
		{
			wait;
		}
		
		engine.gui.removeChild(dialog);
		delete dialog;
	}
    
    Window window = new Window(meta.title);
    window.setFlags(ALIGN_OVERLAP);
    
    HBox button_h_box = new HBox(10);
	window.addChild(button_h_box, ALIGN_EXPAND);

    Button build_button = new Button("Create New");
    build_button.setCallback(CLICKED, Utilities::Namespaces::getGlobalNamespace() + "unigine2_extruder::create_clicked");
    button_h_box.addChild(build_button, ALIGN_RIGHT);

    Button cancel_button = new Button("Cancel");
    cancel_button.setCallback(CLICKED, Utilities::Namespaces::getGlobalNamespace() + "unigine2_extruder::cancel_clicked");
    button_h_box.addChild(cancel_button, ALIGN_RIGHT);
    
    pluginsAddWindow(window, meta.title, meta.name);
    
    unigine2_extruder::meta   = meta;
    unigine2_extruder::window = window;
}

void shutdown()
{
    delete g_extruder;
    g_extruder = NULL;
    
    pluginsRemoveWindow(unigine2_extruder::window, unigine2_extruder::meta.name);

    removeChild(unigine2_extruder::window);
    
    delete unigine2_extruder::window;
    unigine2_extruder::window = 0;
}

void save() 
{
}

void update(int need_reload)
{
	// plugin update callback
    if(g_updating_splines == TRUE)
        g_extruder.update();
}

/******************************************************************************\
*
* Node callbacks
*
\******************************************************************************/

void nodeInit()
{
    // Begin extrude if a node is found with the "extrude" property in the hierarchy
    
    Node extrude_node = ::Nodes::node;
    while(!is_null(extrude_node))
    {
        if(extrude_node.getPropertyName() == "extrude")
        {
            g_extruder.begin_extrude(extrude_node);
            g_updating_splines = TRUE;
            return;
        }
        
        extrude_node = extrude_node.getParent();
    }
    
    // Didn't find the "extrude" property, begin extrude using "_extrudes" parent
    
    Node ancestor = ::Nodes::node;
    while(!is_null(ancestor.getParent()))
    {
        ancestor = ancestor.getParent();
        if(ancestor.getName() == "_extrudes")
        {
            // Something is happening with the extruder
            // Find which spline is being updated

            Node spline = ::Nodes::node;
            if(spline != ancestor)
            {
                while(spline.getParent() != ancestor)
                    spline = spline.getParent();

                // Begin updating the spline
                g_extruder.begin_extrude(spline);
                g_updating_splines = TRUE;
                return;
            }
        }
    }
}

void nodeUpdate()
{
}

void nodeShutdown()
{
    // End updating any splines
    if(g_updating_splines == TRUE)
    {
        g_extruder.end_extrude();
        g_updating_splines = FALSE;
    }
}

void nodesUpdate()
{
}

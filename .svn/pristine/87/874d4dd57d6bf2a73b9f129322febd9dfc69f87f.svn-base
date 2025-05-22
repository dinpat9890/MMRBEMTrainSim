============================================================
This project has been setup to allow Debugging directly from Visual Studio.
Follow these steps to debug the project DLL with an active Simulation/CommsShow/other-modules.
============================================================

1. Check the VS Debugging parameters for the "Project Properties Tab" (i.e. the "Command", "Command Arguments" & "Environment" settings)
-> NB: The "*.vcxproj.user" have been committed to SVN with these properties

2. Edit the "CBTCUnits_d.ini" (file properties used for debugging) as follows:
-> Replace the [Database] settings in the ini-file from the Deploy/Environment/Database.ini (replace the existing sections)
	The Database.ini is auto-generated during Setup PC scripts.
-> Replace the [Liveliness], [Multicast Logging], [System.1] settings in the ini-file from the Deploy/Environment/System.ini (replace the existing sections)
	The System.ini is auto-generated during Setup PC scripts.

3. Run the Simulator as per normal, excluding the Unit under test
-> eg. Make sure the Setup_PC.ini is using a "[Computer] Execute" line without this module-under-test in it.

4. Once Simulator/CommsShow is initialised, run the VS debugger (F5) to start the plugin_moduled.exe which will load in the require unit.
-> You'll notice the module added to CommsShow under "Session Control".

5. Debug as normal. Stop the debugger once your debugging session is complete.
-> You'll notice that CommsShow displays "Dropped" indicating that the module has been lost.

6. Make any necessary changes to your code

7. Repeat 4-6 to reconnect and test the updated code

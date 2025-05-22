function prj_buses_load()

%For a large project, there may already be a prj_bus_names function on the 
%path.  To ensure we're calling the version in the local project, we need
%to change our directory to the local context
%http://au.mathworks.com/help/matlab/matlab_prog/function-precedence-order.html
original_dir = pwd;
m_dir = fileparts(mfilename('fullpath'));
cd(m_dir)

[bus_names, bus_prefix, bus_dir] = prj_bus_names();
buses_load(bus_names, bus_prefix, bus_dir);
cd(original_dir)
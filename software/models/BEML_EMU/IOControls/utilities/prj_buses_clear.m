function prj_buses_clear()


%For a large project, there may already be a prj_bus_names function on the 
%path.  To ensure we're calling the version in the local project, we need
%to change our directory to the local context
%http://au.mathworks.com/help/matlab/matlab_prog/function-precedence-order.html
original_dir = pwd;
m_dir = fileparts(mfilename('fullpath'));
cd(m_dir)

[bus_names, bus_prefix, bus_dir] = prj_bus_names();

disp('Clearing Bus definitions...')
for i=1:numel(bus_names)
        % Clear the bus out of the workspace as we go to clean things up.
        evalin('base', ['clear ' bus_names{i}])
end
cd(original_dir)
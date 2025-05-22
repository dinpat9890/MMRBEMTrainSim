function build(varargin)
t_start = clock;
%For now this script is expected to be run by opening the ControlStates.prj
%so that workspace is set properly with correct variants. The final version
%of this script will be modified so that it can be called from a batch file
%to enable it to run as part of the simulator build process

sec2hmsstr = @(ts) sprintf('%dh %dm %ds', fix(ts / 3600), fix(mod(ts, 3600) / 60), fix(mod(ts, 60)));

prj_name = 'BEML_EMU';
model_name = 'BEML_EMU';

CloseAfterBuild = false; 
if nargin == 1 && islogical(varargin{1}) && varargin{1} == true 
    CloseAfterBuild = true; 
elseif nargin > 1 
    error('Invalid input argument(s) encountered'); 
end

if(CloseAfterBuild && ~isempty(find_system('SearchDepth', 0)))
    prompt = 'There appears to be some models already open, however this function has been called such that it will close without save on completion. Are you sure you want to continue?';
    if(~strcmp(questdlg(prompt, '', 'Yes', 'No', 'No'), 'Yes'))
        return;
    end 
end

build_dir = fileparts(mfilename('fullpath'));
prj_dir = fullfile(build_dir, '..');
zip_dir = fullfile(prj_dir,'..\built\');
work_dir = fullfile(prj_dir, 'work');
mdl_dir = fullfile(prj_dir,'models');

do_open = false;
try
    proj = simulinkproject();
    if(~strcmp(proj.Name, prj_name))
        do_open = true;
    end
catch e
    do_open = true;
end

if(do_open)
    proj = simulinkproject(fullfile(prj_dir, [prj_name '.prj']));
end

fprintf('Load time = %s\n', sec2hmsstr(etime(clock, t_start)));



t_check = clock;
if(~run_model_checks(model_name))
    error('Model checks failed - please check the error log for details')
    return
end
fprintf('Check time = %s\n', sec2hmsstr(etime(clock, t_check)));

%cd ..\work
fprintf('Generating C++ code for %s ...\n', model_name);
slbuild(model_name);
fprintf('Finished generating C++ code for %s', model_name)
pause(2)

zip_file = fullfile(zip_dir, [model_name '.zip']);
if isequal(exist(zip_file,'file'),2)
    delete(zip_file)
end
if try_copy_file([model_name '.zip'],work_dir, zip_dir)
    disp([zip_file ' created.'])
end
disp(sprintf('\n'))

cd(prj_dir)


fprintf('Build time = %s\n', sec2hmsstr(etime(clock, t_start)));
fprintf('\n\n\n\n\n\n\n\n');

if CloseAfterBuild
    open_systems = find_system('SearchDepth', 0);
    close_system(open_systems, 0);
    
    close(proj)
    evalin('base', 'who')
    exit
end
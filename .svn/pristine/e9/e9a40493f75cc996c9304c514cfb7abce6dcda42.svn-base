function build(varargin)

%For now this script is expected to be run by opening the ControlStates.prj
%so that workspace is set properly with correct variants. The final version
%of this script will be modified so that it can be called from a batch file
%to enable it to run as part of the simulator build process

CloseAfterBuild = false; 
if nargin == 1 && islogical(varargin{1}) && varargin{1} == true 
    CloseAfterBuild = true; 
elseif nargin > 1 
    error('Invalid input argument(s) encountered'); 
end

build_dir = fileparts(mfilename('fullpath'));
prj_dir = fullfile(build_dir, '..');
zip_dir = fullfile(prj_dir,'..\..\Build\');
work_dir = fullfile(prj_dir, 'work');

%Provide the file path to the Model IO csv file relative to the IOControls Simulink project folder
model_io_csv_location = '..\..\..\..\config\source\trains\BEML_EMU\config\BEML_EMU Model IO.csv';

proj = openProject(fullfile(prj_dir, 'IOControls.prj'));

disp('Generating IO Controls Model...');
create_io_controls('IOControls', 'IOControlsTemplate.slx', model_io_csv_location);
disp('Finished generating IO Controls Model.')
pause(2)


cd(prj_dir)

if CloseAfterBuild
    close(proj)
    exit
end
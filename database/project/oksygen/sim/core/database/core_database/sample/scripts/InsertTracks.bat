echo off
call SetDatabaseProperties.bat
echo Using properties = %DATABASE%

set PATH=%~dp0..\cots\xerces\Bin\Win32;%PATH%

REM Check that we have the file
if exist ".\population\tracks\tracks.txt" (
  mkdir logs
  for /F "tokens=1,2" %%i in (.\population\tracks\tracks.txt) do (
    ..\bin\import_track.exe -s .\population\tracks\%%i.xml .\population\tracks\%%j.xml .\population\tracks %DATABASE% /dbmapping .\population\db_mapping.xml /xmldir .\population\tracks
    move /Y import_track.log logs/import_track_%%j.log
    move /Y ImportTrack_xml2db.log logs/ImportTrack_xml2db_%%j.log
  )
) else (
  echo Can't import tracks as tracks.txt does not exist
)

pause;


REM DB Connection details 
REM DSW SITE
REM set SCHEMA_OWNER=mmrbem_1_0_0
REM set SCHEMA_PASSWORD=mmrbemschemamgr
REM set SYS_PASSWORD=oraclexe 
REM set SYSTEM_PASSWORD=oraclexe
REM set TNSNAME=LOCAL

REM FSTDS SITE
set SCHEMA_OWNER=mmrbem_1_0_0
set SCHEMA_PASSWORD=mmrbemschemamgr
set SYS_PASSWORD=mmrbemsystemmgr 
set SYSTEM_PASSWORD=mmrbemsystemmgr
set TNSNAME=XE

set DATABASE=%SCHEMA_OWNER%/%SCHEMA_PASSWORD%@%TNSNAME%
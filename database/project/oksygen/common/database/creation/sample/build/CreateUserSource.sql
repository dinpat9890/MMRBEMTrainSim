/**********************************************************************************************************************
*    Filename:      CreateUserSource.sql                                                                              *
*                                                                                                                     *
*    Description:   Build Script for database source                                                                  *
*                   This is a script for calling a package's entry point source compilation scripts                   *
*                   Place all entry point build scripts for creating your package source here.                        *
*                                                                                                                     *
*    Example:       If you also depend on the core database package then, after CreateCommonLibrariesSource.sql add   *
*                   CreateCoreSource.sql                                                                              *
*                                                                                                                     *
*                   Then add any other dependencies e.g.                                                              *
*                   CreateTrainSource.sql                                                                             *
*                   CreateTruckSource.sql                                                                             *
*                   CreateProjectSource.sql                                                                           *
*                                                                                                                     *
*                   Ensure that you fully qualify the paths to those files with respect to your master build folder.  *
*                                                                                                                     *
*                   The last script in the file must be:                                                              *
*                   CreateCommonUtilitiesSource.sql                                                                   *
**********************************************************************************************************************/

PROMPT Calling CreateCommonLibrariesSource.sql
@build\common\database\libraries\CreateCommonLibrariesSource.sql

-- Add source creation scripts here
PROMPT Calling CreateCoreSource.sql
@build\sim\core\database\core_database\CreateCoreSource.sql

PROMPT Calling CreateCoreSource.sql
@build\sim\train\database\train_database\CreateTrainSource.sql

PROMPT Calling CreateCoreUtilitiesListSource.sql
@build\sim\core\database\utilities\CreateCoreUtilitiesListSource.sql

PROMPT Calling CreateTrainUtilitiesListSource.sql
@build\sim\train\database\utilities\CreateTrainUtilitiesListSource.sql

PROMPT Calling CreateCommonUtilitiesSource.sql
@build\common\database\utilities\CreateCommonUtilitiesListSource.sql

PROMPT Calling CreateCoreUtilitiesSource.sql
@build\sim\core\database\utilities\CreateCoreUtilitiesSource.sql

PROMPT Calling CreateCommonUtilitiesSource.sql
@build\common\database\utilities\CreateCommonUtilitiesSource.sql


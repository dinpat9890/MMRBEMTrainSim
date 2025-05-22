/**********************************************************************************************************************
*    Filename:      CreateUserSchema.sql                                                                              *
*                                                                                                                     *
*    Description:   Build Script for database schemas                                                                 *
*                   This is a script for calling a package's entry point table creation scripts                       *
*                   Place all entry point build scripts for creating your package schemas here.                       *
*                                                                                                                     *
*    Example:       If you depend on the core schema then add                                                         *
*                   CreateCoreSchema.sql                                                                              *
*                                                                                                                     *
*                   Then add any other dependencies e.g.                                                              *
*                   CreateTrainSchema.sql                                                                             * 
*                   CreateProjectSchema.sql                                                                           *
*                   CreateTruckSchema.sql                                                                             *
*                                                                                                                     *
*                   Ensure that you fully qualify the paths to those files with respect to your master build folder.  *
**********************************************************************************************************************/

PROMPT Creating Core Schema
@build\sim\core\database\core_database\CreateCoreSchema.sql

PROMPT Creating Train Schema
@build\sim\train\database\train_database\CreateTrainSchema.sql

PROMPT Creating Project Schema
@build\sim\project\database\project_database\CreateProjectSchema.sql
 
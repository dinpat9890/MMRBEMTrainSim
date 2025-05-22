CREATE OR REPLACE PACKAGE BODY CommonListBuilder IS
/**********************************************************************************************************************
* Package Name:     CommonListBuilder
*
* Description:      Contains sample procedures to add elements to lists  
**********************************************************************************************************************/

    /******************************************************************************************************************
    * Procedure Name:   SequencesAdd
    *
    * Description:      The entry point for building a list of sequences and their details for passing to
    *                   other procedures, namely commondbautilitiespackage.resetsequences
    * Parameters        p_sequence_tab   - the table array object of sequence detail elements
    *                   p_debug          - whether or not you wish for the output to be written if serveroutput is 
    *                                      turned on                              
    ******************************************************************************************************************/
    PROCEDURE SequencesAdd(p_sequence_tab IN OUT CommonUtilities.sequence_tabtype, p_debug IN VARCHAR) IS
    
    BEGIN             
        CoreListBuilder.SequencesAdd(p_sequence_tab, p_debug);
        TrainListBuilder.SequencesAdd(p_sequence_tab, p_debug);
            
    END; -- CommonSequencesAdd;
    
    /******************************************************************************************************************
    * Procedure Name:   SessionCleanupTableAdd
    *
    * Description:      The entry point for building a list of tabLes and their details for passing to
    *                   CoreSessionUtilities.SessionCleanup
    * Parameters        p_table_tab      - the table array object of table detail elements
    *                   p_debug          - whether or not you wish for the output to be written if serveroutput is 
    *                                      turned on                           
    ******************************************************************************************************************/
    PROCEDURE SessionCleanupTableAdd(p_table_tab IN OUT CommonUtilities.tabledel_tabtype, p_debug IN VARCHAR) IS
    
    BEGIN
        TrainListBuilder.SessionCleanupTableAdd(p_table_tab, p_debug);
        CoreListBuilder.SessionCleanupTableAdd(p_table_tab, p_debug);
        
    END; -- SessionCleanupTableAdd
    
    /******************************************************************************************************************
    * Procedure Name:   SessionCleanupBaseTableAdd
    *
    * Description:      The entry point for building a list of base tables and their details for passing to
    *                   CoreSessionUtilities.SessionCleanup
    * Parameters        p_table_tab      - the table array object of table detail elements
    *                   p_debug          - whether or not you wish for the output to be written if serveroutput is 
    *                                      turned on                           
    ******************************************************************************************************************/
    PROCEDURE SessionCleanupBaseTableAdd(p_table_tab IN OUT CommonUtilities.tabledel_tabtype, p_debug IN VARCHAR) IS
    
    BEGIN
        TrainListBuilder.SessionCleanupBaseTableAdd(p_table_tab, p_debug);    
        CoreListBuilder.SessionCleanupBaseTableAdd(p_table_tab, p_debug);
        
    END; -- SessionCleanupBaseTableAdd   
    
    /******************************************************************************************************************
    * Procedure Name:   SimSessionDeleteTableAdd
    *
    * Description:      The entry point for building a list of tabLes and their details for passing to
    *                   CoreSessionUtilities.SimSessionDelete.
    * Parameters        p_table_tab      - the table array object of table detail elements
    *                   p_debug          - whether or not you wish for the output to be written if serveroutput is 
    *                                      turned on                             
    ******************************************************************************************************************/
    PROCEDURE SimSessionDeleteTableAdd(p_table_tab IN OUT CommonUtilities.tabledel_tabtype, p_debug IN VARCHAR) IS
    
    BEGIN
        TrainListBuilder.SimSessionDeleteTableAdd(p_table_tab, p_debug);
        CoreListBuilder.SimSessionDeleteTableAdd(p_table_tab, p_debug);
        
    END; -- SimSessionDeleteTableAdd
    
    /******************************************************************************************************************
    * Procedure Name:   SimSessionDeleteBaseTableAdd
    *
    * Description:      The entry point for building a list of base tables and their details for passing to
    *                   CoreSessionUtilities.SimSessionDelete.
    * Parameters        p_table_tab      - the table array object of table detail elements
    *                   p_debug          - whether or not you wish for the output to be written if serveroutput is 
    *                                      turned on                            
    ******************************************************************************************************************/
    PROCEDURE SimSessionDeleteBaseTableAdd(p_table_tab IN OUT CommonUtilities.tabledel_tabtype, p_debug IN VARCHAR) IS
    
    BEGIN
        TrainListBuilder.SimSessionDeleteBaseTableAdd(p_table_tab, p_debug);    
        CoreListBuilder.SimSessionDeleteBaseTableAdd(p_table_tab, p_debug);
        
    END; -- SimSessionDeleteBaseTableAdd   
    
    /******************************************************************************************************************
    * Procedure Name:   SimSessDeleteBaseLogTableAdd
    *
    * Description:      The entry point for building a list of base log tables and their details for passing to
    *                   CoreSessionUtilities.SimSessionDelete.
    * Parameters        p_table_tab      - the table array object of table detail elements
    *                   p_debug          - whether or not you wish for the output to be written if serveroutput is 
    *                                      turned on                           
    ******************************************************************************************************************/
    PROCEDURE SimSessDeleteBaseLogTableAdd(p_table_tab IN OUT CommonUtilities.tabledel_tabtype, p_debug IN VARCHAR) IS
    
    BEGIN
        TrainListBuilder.SimSessDeleteBaseLogTableAdd(p_table_tab, p_debug);    
        CoreListBuilder.SimSessDeleteBaseLogTableAdd(p_table_tab, p_debug);
        
    END; -- SimSessDeleteBaseLogTableAdd    
    
    /******************************************************************************************************************
    * Procedure Name:   ScenarioDeleteConstraintAdd
    *
    * Description:      The entry point for building a list of constraints and their details for passing to
    *                   CoreScenarioUtilities.ScenarioDeleteAll.
    * Parameters        p_table_tab      - the table array object of table detail elements
    *                   p_debug          - whether or not you wish for the output to be written if serveroutput is 
    *                                      turned on                              
    ******************************************************************************************************************/
    PROCEDURE ScenarioDeleteConstraintAdd(p_constraint_tab IN OUT CommonUtilities.constraint_tabtype, p_debug IN VARCHAR) IS
    
    BEGIN
        TrainListBuilder.ScenarioDeleteConstraintAdd(p_constraint_tab, p_debug);
        CoreListBuilder.ScenarioDeleteConstraintAdd(p_constraint_tab, p_debug);
        
    END; -- ScenarioDeleteConstraintAdd    
    
    /******************************************************************************************************************
    * Procedure Name:   ScenarioDeleteTableAdd
    *
    * Description:      The entry point for building a list of tabLes and their details for passing to
    *                   CoreScenarioUtilities.ScenarioDelete.
    * Parameters        p_table_tab      - the table array object of table detail elements
    *                   p_debug          - whether or not you wish for the output to be written if serveroutput is 
    *                                      turned on                              
    ******************************************************************************************************************/
    PROCEDURE ScenarioDeleteTableAdd(p_table_tab IN OUT CommonUtilities.tabledel_tabtype, p_debug IN VARCHAR) IS
    
    BEGIN
        TrainListBuilder.ScenarioDeleteTableAdd(p_table_tab, p_debug);
        CoreListBuilder.ScenarioDeleteTableAdd(p_table_tab, p_debug);
        
    END; -- ScenarioDeleteTableAdd
    
  /******************************************************************************************************************
    * Procedure Name:   ScenarioDeleteAllTableAdd
    *
    * Description:      The entry point for building a list of tabLes and their details for passing to
    *                   CoreScenarioUtilties.ScenarioDeleteAll.
    * Parameters        p_table_tab      - the table array object of table detail elements
    *                   p_debug          - whether or not you wish for the output to be written if serveroutput is 
    *                                      turned on                              
    ******************************************************************************************************************/
    PROCEDURE ScenarioDeleteAllTableAdd(p_table_tab IN OUT CommonUtilities.tabledel_tabtype, p_debug IN VARCHAR) IS
    
    BEGIN
        TrainListBuilder.ScenarioDeleteAllTableAdd(p_table_tab, p_debug);
        CoreListBuilder.ScenarioDeleteAllTableAdd(p_table_tab, p_debug);
        
    END; -- ScenarioDeleteTableAdd   
    
    /******************************************************************************************************************
    * Procedure Name:   TrackDeleteConstraintAdd
    *
    * Description:      The entry point for building a list of constraints and their details for passing to
    *                       CoreTrackUtilities.TrackDeleteAll.
    * Parameters        p_constraint_tab - the table array object of table detail elements
    *                   p_debug          - whether or not you wish for the output to be written if serveroutput is 
    *                                      turned on                           
    ******************************************************************************************************************/
    PROCEDURE TrackDeleteConstraintAdd(p_constraint_tab IN OUT CommonUtilities.constraint_tabtype, p_debug IN VARCHAR) IS
    
    BEGIN
        TrainListBuilder.TrackDeleteConstraintAdd(p_constraint_tab, p_debug);
        CoreListBuilder.TrackDeleteConstraintAdd(p_constraint_tab, p_debug);
        
    END; -- TrackDeleteConstraintAdd        
    
    /******************************************************************************************************************
    * Procedure Name:   TrackDeleteTableAdd
    *
    * Description:      The entry point for building a list of tabLes and their details for passing to
    *                   CoreSessionUtilities.TrackDelete.
    * Parameters        p_table_tab      - the table array object of table detail elements
    *                   p_debug          - whether or not you wish for the output to be written if serveroutput is 
    *                                      turned on                              
    ******************************************************************************************************************/
    PROCEDURE TrackDeleteTableAdd(p_table_tab IN OUT CommonUtilities.tabledel_tabtype, p_debug IN VARCHAR) IS
    
    BEGIN
        TrainListBuilder.TrackDeleteTableAdd(p_table_tab, p_debug);
        CoreListBuilder.TrackDeleteTableAdd(p_table_tab, p_debug);
        
    END; -- TrackDeleteTableAdd               
        
         
END; -- CommonListBuilder Package Body
/

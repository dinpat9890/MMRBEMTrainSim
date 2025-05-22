CREATE OR REPLACE PACKAGE BODY CoreListBuilder IS
/**********************************************************************************************************************
* Package Name:     CoreListBuilder
*
* Description:      Contains procedures to add elements to lists  
**********************************************************************************************************************/

    /******************************************************************************************************************
    * Procedure Name:   SequencesAdd
    *
    * Description:      The entry point in Core for building a list of sequences and their details for passing to
    *                   other procedures, namely CommonDBAUtilities.ResetSequences
    * Parameters        p_sequence_tab   - the table array object of sequence detail elements
    *                   p_debug          - whether or not you wish for the output to be written if serveroutput is 
    *                                      turned on                              
    ******************************************************************************************************************/
    PROCEDURE SequencesAdd(p_sequence_tab IN OUT CommonUtilities.sequence_tabtype, p_debug IN VARCHAR) IS
    
    BEGIN
        CoreSimUserListBuilder.SequencesAdd(p_sequence_tab, p_debug);
        CoreScoringListBuilder.SequencesAdd(p_sequence_tab, p_debug);
        CoreFeatureTypeListBuilder.SequencesAdd(p_sequence_tab, p_debug);  
        CoreTrackListBuilder.SequencesAdd(p_sequence_tab, p_debug);
        CoreTimetableListBuilder.SequencesAdd(p_sequence_tab, p_debug);    
        CoreScenarioListBuilder.SequencesAdd(p_sequence_tab, p_debug);    
        CoreFSLListBuilder.SequencesAdd(p_sequence_tab, p_debug);    
        CoreEventScriptingListBuilder.SequencesAdd(p_sequence_tab, p_debug);         
        CoreSimSessionListBuilder.SequencesAdd(p_sequence_tab, p_debug);          
    END; -- SequencesAdd;
    
    /******************************************************************************************************************
    * Procedure Name:   SessionCleanupTableAdd
    *
    * Description:      The entry point in Core for building a list of tables and their details for passing to
    *                   CoreSessionUtilities.SessionCleanup
    * Parameters        p_table_tab      - the table array object of table detail elements
    *                   p_debug          - whether or not you wish for the output to be written if serveroutput is 
    *                                      turned on                                                    
    ******************************************************************************************************************/
    PROCEDURE SessionCleanupTableAdd(p_table_tab IN OUT CommonUtilities.tabledel_tabtype, p_debug IN VARCHAR) IS
    
    BEGIN
        CoreSimSessionListBuilder.SessionCleanupTableAdd(p_table_tab, p_debug);   
    
    END; -- CoreSessionCleanupTableAdd;    
        
    /******************************************************************************************************************
    * Procedure Name:   SessionCleanupBaseTableAdd
    *
    * Description:      The entry point in Core for building a list of base tables and their details for passing to
    *                   CoreSessionUtilities.SessionCleanup
    * Parameters        p_table_tab      - the table array object of table detail elements
    *                   p_debug          - whether or not you wish for the output to be written if serveroutput is 
    *                                      turned on                                                      
    ******************************************************************************************************************/
    PROCEDURE SessionCleanupBaseTableAdd(p_table_tab IN OUT CommonUtilities.tabledel_tabtype, p_debug IN VARCHAR) IS
    
    BEGIN
        CoreSimSessionListBuilder.SessionCleanupBaseTableAdd(p_table_tab, p_debug);   
    
    END; -- CoreSessionCleanupTableAdd;    
    
    /******************************************************************************************************************
    * Procedure Name:   SimSessionDeleteTableAdd
    *
    * Description:      The entry point in Core for building a list of tables and their details for passing to
    *                   CoreSessionUtilities.SimSessionDelete
    * Parameters        p_table_tab      - the table array object of table detail elements
    *                   p_debug          - whether or not you wish for the output to be written if serveroutput is 
    *                                      turned on                                                     
    ******************************************************************************************************************/
    PROCEDURE SimSessionDeleteTableAdd(p_table_tab IN OUT CommonUtilities.tabledel_tabtype, p_debug IN VARCHAR) IS
    
    BEGIN
        CoreSimSessionListBuilder.SimSessionDeleteTableAdd(p_table_tab, p_debug);   
    
    END; -- SimSessionDeleteTableAdd;    
        
    /******************************************************************************************************************
    * Procedure Name:   SimSessionDeleteBaseTableAdd
    *
    * Description:      The entry point in Core for building a list of base tables and their details for passing to
    *                   CoreSessionUtilities.SimSessionDelete
    * Parameters        p_table_tab      - the table array object of table detail elements
    *                   p_debug          - whether or not you wish for the output to be written if serveroutput is 
    *                                      turned on                                                    
    ******************************************************************************************************************/
    PROCEDURE SimSessionDeleteBaseTableAdd(p_table_tab IN OUT CommonUtilities.tabledel_tabtype, p_debug IN VARCHAR) IS
    
    BEGIN
        CoreSimSessionListBuilder.SimSessionDeleteBaseTableAdd(p_table_tab, p_debug);   
    
    END; -- SimSessionDeleteBaseTableAdd;      
    
    /******************************************************************************************************************
    * Procedure Name:   SimSessDeleteBaseLogTableAdd
    *
    * Description:      The entry point in Core for building a list of base log tables and their details for passing to
    *                   CoreSessionUtilities.SimSessionDelete
    * Parameters        p_table_tab      - the table array object of table detail elements
    *                   p_debug          - whether or not you wish for the output to be written if serveroutput is 
    *                                      turned on                                                    
    ******************************************************************************************************************/
    PROCEDURE SimSessDeleteBaseLogTableAdd(p_table_tab IN OUT CommonUtilities.tabledel_tabtype, p_debug IN VARCHAR) IS
    
    BEGIN
        CoreSimSessionListBuilder.SimSessDeleteBaseLogTableAdd(p_table_tab, p_debug);   
    
    END; -- SimSessDeleteBaseLogTableAdd;   
    
    /******************************************************************************************************************
    * Procedure Name:   ScenarioDeleteConstraintAdd
    *
    * Description:      The entry point in Core for building a list of constraints and their details for passing to
    *                       CoreScenarioUtilities.ScenarioDeleteAll
    * Parameters        p_constraint_tab - the table array object of constraints and their details 
    *                   p_debug          - whether or not you wish for the output to be written if serveroutput is 
    *                                      turned on                             
    ******************************************************************************************************************/
    PROCEDURE ScenarioDeleteConstraintAdd(p_constraint_tab IN OUT CommonUtilities.constraint_tabtype, p_debug IN VARCHAR) IS
    
    BEGIN
        CoreTrackListBuilder.ScenarioDeleteConstraintAdd(p_constraint_tab, p_debug);
        CoreTimetableListBuilder.ScenarioDeleteConstraintAdd(p_constraint_tab, p_debug);
        CoreScenarioListBuilder.ScenarioDeleteConstraintAdd(p_constraint_tab, p_debug);
        CoreFSLListBuilder.ScenarioDeleteConstraintAdd(p_constraint_tab, p_debug);
        CoreEventScriptingListBuilder.ScenarioDeleteConstraintAdd(p_constraint_tab, p_debug);        
        CoreSimSessionListBuilder.ScenarioDeleteConstraintAdd(p_constraint_tab, p_debug);
    
    END; -- ScenarioDeleteTableAdd;     
    
    /******************************************************************************************************************
    * Procedure Name:   ScenarioDeleteTableAdd
    *
    * Description:      The entry point in Core for building a list of tables and their details for passing to
    *                       CoreScenarioUtilities.ScenarioDelete
    * Parameters        p_table_tab      - the table array object of table detail elements
    *                   p_debug          - whether or not you wish for the output to be written if serveroutput is 
    *                                      turned on
    *                              
    ******************************************************************************************************************/
    PROCEDURE ScenarioDeleteTableAdd(p_table_tab IN OUT CommonUtilities.tabledel_tabtype, p_debug IN VARCHAR) IS
    
    BEGIN
        CoreSimSessionListBuilder.ScenarioDeleteTableAdd(p_table_tab, p_debug);           
        CoreFSLListBuilder.ScenarioDeleteTableAdd(p_table_tab, p_debug);
        CoreEventScriptingListBuilder.ScenarioDeleteTableAdd(p_table_tab, p_debug);
        CoreTimetableListBuilder.ScenarioDeleteTableAdd(p_table_tab, p_debug);        
        CoreTrackListBuilder.ScenarioDeleteTableAdd(p_table_tab, p_debug);
        CoreScenarioListBuilder.ScenarioDeleteTableAdd(p_table_tab, p_debug);
    
    END; -- ScenarioDeleteTableAdd; 
    
    /******************************************************************************************************************
    * Procedure Name:   ScenarioDeleteAllTableAdd
    *
    * Description:      The entry point in Core for building a list of tables and their details for passing to
    *                       CoreScenarioUtilities.ScenarioDeleteAll
    * Parameters        p_table_tab      - the table array object of table detail elements
    *                   p_debug          - whether or not you wish for the output to be written if serveroutput is 
    *                                      turned on
    *                              
    ******************************************************************************************************************/
    PROCEDURE ScenarioDeleteAllTableAdd(p_table_tab IN OUT CommonUtilities.tabledel_tabtype, p_debug IN VARCHAR) IS
    
    BEGIN
        CoreSimSessionListBuilder.ScenarioDeleteTableAdd(p_table_tab, p_debug);           
        CoreFSLListBuilder.ScenarioDeleteTableAdd(p_table_tab, p_debug);
        CoreEventScriptingListBuilder.ScenarioDeleteTableAdd(p_table_tab, p_debug);
        CoreTimetableListBuilder.ScenarioDeleteTableAdd(p_table_tab, p_debug);        
        CoreTrackListBuilder.ScenarioDeleteAllTableAdd(p_table_tab, p_debug);
        CoreScenarioListBuilder.ScenarioDeleteTableAdd(p_table_tab, p_debug);
    
    END; -- ScenarioDeleteAllTableAdd;
    
    /******************************************************************************************************************
    * Procedure Name:   TrackDeleteConstraintAdd
    *
    * Description:      The entry point in Core for building a list of constraints and their details for passing to
    *                       CoreTrackUtilities.TrackDeleteAll
    * Parameters        p_constraint_tab - the table array object of constraints and their details 
    *                   p_debug          - whether or not you wish for the output to be written if serveroutput is 
    *                                      turned on                             
    ******************************************************************************************************************/
    PROCEDURE TrackDeleteConstraintAdd(p_constraint_tab IN OUT CommonUtilities.constraint_tabtype, p_debug IN VARCHAR) IS
    
    BEGIN
        CoreTrackListBuilder.TrackDeleteConstraintAdd(p_constraint_tab, p_debug);
        CoreTimetableListBuilder.TrackDeleteConstraintAdd(p_constraint_tab, p_debug);
        CoreScenarioListBuilder.TrackDeleteConstraintAdd(p_constraint_tab, p_debug);
        CoreFSLListBuilder.TrackDeleteConstraintAdd(p_constraint_tab, p_debug);
        CoreEventScriptingListBuilder.TrackDeleteConstraintAdd(p_constraint_tab, p_debug);        
        CoreSimSessionListBuilder.ScenarioDeleteConstraintAdd(p_constraint_tab, p_debug);
    
    END; -- TrackDeleteConstraintAdd;           
    
    /******************************************************************************************************************
    * Procedure Name:   TrackDeleteTableAdd
    *
    * Description:      The entry point in Core for building a list of tables and their details for passing to
    *                       CoreScenarioUtilities.TrackDelete
    * Parameters        p_table_tab      - the table array object of table detail elements
    *                   p_debug          - whether or not you wish for the output to be written if serveroutput is 
    *                                      turned on                             
    ******************************************************************************************************************/
    PROCEDURE TrackDeleteTableAdd(p_table_tab IN OUT CommonUtilities.tabledel_tabtype, p_debug IN VARCHAR) IS
    
    BEGIN
        CoreSimSessionListBuilder.TrackDeleteTableAdd(p_table_tab, p_debug);  
        CoreEventScriptingListBuilder.TrackDeleteTableAdd(p_table_tab, p_debug); 
        CoreFSLListBuilder.TrackDeleteTableAdd(p_table_tab, p_debug);         
        CoreScenarioListBuilder.TrackDeleteTableAdd(p_table_tab, p_debug);
        CoreTimetableListBuilder.TrackDeleteTableAdd(p_table_tab, p_debug);        
        CoreTrackListBuilder.TrackDeleteTableAdd(p_table_tab, p_debug);
    END; -- TrackDeleteTableAdd;                     
    
    
END; -- CoreListBuilder Package Body
/
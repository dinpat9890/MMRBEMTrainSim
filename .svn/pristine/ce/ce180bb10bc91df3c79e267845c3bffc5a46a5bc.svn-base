CREATE OR REPLACE PACKAGE CoreListBuilder IS
/**********************************************************************************************************************
* Package Name:     CoreListBuilder
*
* Description:      Contains procedures to add elements to lists  
**********************************************************************************************************************/

    /******************************************************************************************************************
    * Procedure Name:   SequencesAdd
    *
    * Description:      The entry point in Core for building a list of sequences and their details for passing to
    *                   other procedures, namely CommonDBUutilitiesPackage.ResetSequences
    * Parameters        p_sequence_tab   - the table array object of sequence detail elements
    *                   p_debug          - whether or not you wish for the output to be written if serveroutput is 
    *                                      turned on                           
    ******************************************************************************************************************/
    PROCEDURE SequencesAdd(p_sequence_tab IN OUT CommonUtilities.sequence_tabtype, p_debug IN VARCHAR:='ERROR');  


    /******************************************************************************************************************
    * Procedure Name:   SessionCleanupTableAdd
    *
    * Description:      The entry point in Core for building a list of tables and their details for passing to
    *                       CoreSessionUtilities.SessionCleanup
    * Parameters        p_table_tab      - the table array object of table detail elements
    *                   p_debug          - whether or not you wish for the output to be written if serveroutput is 
    *                                      turned on                            
    ******************************************************************************************************************/
    PROCEDURE SessionCleanupTableAdd(p_table_tab IN OUT CommonUtilities.tabledel_tabtype, p_debug IN VARCHAR);  
    
    /******************************************************************************************************************
    * Procedure Name:   SessionCleanupBaseTableAdd
    *
    * Description:      The entry point in Core for building a list of tables and their details for passing to
    *                       CoreSessionUtilities.SessionCleanup
    * Parameters        p_table_tab      - the table array object of table detail elements
    *                   p_debug          - whether or not you wish for the output to be written if serveroutput is 
    *                                      turned on                            
    ******************************************************************************************************************/
    PROCEDURE SessionCleanupBaseTableAdd(p_table_tab IN OUT CommonUtilities.tabledel_tabtype, p_debug IN VARCHAR);   
    
    /******************************************************************************************************************
    * Procedure Name:   SimSessionDeleteTableAdd
    *
    * Description:      The entry point in Core for building a list of tables and their details for passing to
    *                       CoreSessionUtilities.SimSessionDelete
    * Parameters        p_table_tab      - the table array object of table detail elements
    *                   p_debug          - whether or not you wish for the output to be written if serveroutput is 
    *                                      turned on                             
    ******************************************************************************************************************/
    PROCEDURE SimSessionDeleteTableAdd(p_table_tab IN OUT CommonUtilities.tabledel_tabtype, p_debug IN VARCHAR);  
    
    /******************************************************************************************************************
    * Procedure Name:   SimSessionDeleteBaseTableAdd
    *
    * Description:      The entry point in Core for building a list of base tables and their details for passing to
    *                       CoreSessionUtilities.SimSessionDelete
    * Parameters        p_table_tab      - the table array object of table detail elements
    *                   p_debug          - whether or not you wish for the output to be written if serveroutput is 
    *                                      turned on                             
    ******************************************************************************************************************/
    PROCEDURE SimSessionDeleteBaseTableAdd(p_table_tab IN OUT CommonUtilities.tabledel_tabtype, p_debug IN VARCHAR);       
    
    /******************************************************************************************************************
    * Procedure Name:   SimSessDeleteBaseLogTableAdd
    *
    * Description:      The entry point in Core for building a list of base tables and their details for passing to
    *                       CoreSessionUtilities.SimSessionDelete
    * Parameters        p_table_tab      - the table array object of table detail elements
    *                   p_debug          - whether or not you wish for the output to be written if serveroutput is 
    *                                      turned on
    *                              
    ******************************************************************************************************************/
    PROCEDURE SimSessDeleteBaseLogTableAdd(p_table_tab IN OUT CommonUtilities.tabledel_tabtype, p_debug IN VARCHAR);    
    
    /******************************************************************************************************************
    * Procedure Name:   ScenarioDeleteConstraintAdd
    *
    * Description:      The entry point in Core for building a list of constraints and their details for passing to
    *                       CoreScenarioUtilities.ScenarioDeleteAll
    * Parameters        p_constraint_tab - the table array object of constraints and their details 
    *                   p_debug          - whether or not you wish for the output to be written if serveroutput is 
    *                                      turned on                            
    ******************************************************************************************************************/
    PROCEDURE ScenarioDeleteConstraintAdd(p_constraint_tab IN OUT CommonUtilities.constraint_tabtype, p_debug IN VARCHAR);          
    
    /******************************************************************************************************************
    * Procedure Name:   ScenarioDeleteTableAdd
    *
    * Description:      The entry point in Core for building a list of tables and their details for passing to
    *                       CoreScenarioUtilities.ScenarioDelete
    * Parameters        p_table_tab      - the table array object of table detail elements
    *                   p_debug          - whether or not you wish for the output to be written if serveroutput is 
    *                                      turned on                            
    ******************************************************************************************************************/
    PROCEDURE ScenarioDeleteTableAdd(p_table_tab IN OUT CommonUtilities.tabledel_tabtype, p_debug IN VARCHAR); 
    
    /******************************************************************************************************************
    * Procedure Name:   ScenarioDeleteAllTableAdd
    *
    * Description:      The entry point in Core for building a list of tables and their details for passing to
    *                       CoreScenarioUtilities.ScenarioDeleteAll
    * Parameters        p_table_tab      - the table array object of table detail elements
    *                   p_debug          - whether or not you wish for the output to be written if serveroutput is 
    *                                      turned on                            
    ******************************************************************************************************************/
    PROCEDURE ScenarioDeleteAllTableAdd(p_table_tab IN OUT CommonUtilities.tabledel_tabtype, p_debug IN VARCHAR);  
    
    /******************************************************************************************************************
    * Procedure Name:   TrackDeleteConstraintAdd
    *
    * Description:      The entry point in Core for building a list of constraints and their details for passing to
    *                       CoreTrackUtilities.TrackDeleteAll
    * Parameters        p_constraint_tab - the table array object of constraints and their details 
    *                   p_debug          - whether or not you wish for the output to be written if serveroutput is 
    *                                      turned on                            
    ******************************************************************************************************************/
    PROCEDURE TrackDeleteConstraintAdd(p_constraint_tab IN OUT CommonUtilities.constraint_tabtype, p_debug IN VARCHAR);        
    
    /******************************************************************************************************************
    * Procedure Name:   TrackDeleteTableAdd
    *
    * Description:      The entry point in Core for building a list of tables and their details for passing to
    *                       CoreTrackUtilities.TrackDelete
    * Parameters        p_table_tab      - the table array object of table detail elements
    *                   p_debug          - whether or not you wish for the output to be written if serveroutput is 
    *                                      turned on                             
    ******************************************************************************************************************/
    PROCEDURE TrackDeleteTableAdd(p_table_tab IN OUT CommonUtilities.tabledel_tabtype, p_debug IN VARCHAR);       
                 
    
END; -- CoreListBuilder Package Spec
/
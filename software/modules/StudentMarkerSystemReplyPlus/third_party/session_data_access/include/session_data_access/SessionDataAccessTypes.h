#ifndef SESSION_DATA_ACCESS_TYPES_H
#define SESSION_DATA_ACCESS_TYPES_H

// Include core types so that we can pull in the name space below
#include <core_data_access/CoreDataAccessTypes.h>

#include <string>

namespace Session
{
    namespace Data
    {
        // Make all core types available just using the Train::Data namespace
        using namespace Core::Data;

        struct LogEvent
        {
            int             property_id;
            double          delta_time;
            double          delta_value;
        };

        struct LogSummary
        {
            int             log_summary_id;
            int             property_id;
            std::string     function_type_name;
            std::string     summary_type_name;
        };

        struct SessionData
        {
            int             sim_session_id;
            int             hub_id;
            int             property_id;
            int             element;
            double          position;
            double          time;
            double          value;
        };

        struct SessionSummary
        {
            int             sim_session_id;
            int             hub_id;
            int             log_summary_id;
            int             element;
            double          position;
            double          time;
            double          value;
        };

        struct SessionFeature
        {
            int             sim_session_id;
            int             hub_id;
            int             network_id;
            int             feature_id;
            int             feature_type_id;
            bool            has_state;
            int             feature_state_id;
            double          passed_time;
            double          position;
        };

        struct SessionInfraction
        {
            int             sim_session_id;
            int             hub_id;
            int             infraction_id;
            int             category_id;
            int             rule_id;
            double          position;
            double          elapsed_time;
            double          demerits;
        };

        struct PremiershipDetail
        {
            int             session_id;
            int             hub_id;
            int             category_id;
            int             score;
        };

        struct SimSession
        {
            int             session_id;
            int             ref_session_id;
            int             hub_id;
            int             hub_mode_id;
            int             scenario_id;
            int             scenario_train_id;
            int             network_id;
            int             driver_id;
            int             instructor_id;

            int             start_position;
            int             end_position;

            int             location_type_id;
            int             vehicle_index;
            double          x_offset;
            double          y_offset;
            double          z_offset;
            double          h_offset;
            double          p_offset;
            double          r_offset;

            unsigned long   start_date;
            unsigned long   end_date;
            bool            is_replay;
            double          duration;
            bool            is_protected;
            unsigned long   date_time;

            int             start_segment_id;
            double          start_segment_offset;
            int             end_segment_id;
            double          end_segment_offset;

            std::string     session_code;
            std::string     course_code;

            bool            is_deleted;

            int             resumed_snapshot_id;

            // Unused from this interface
            unsigned long   expired;
        };

        struct SessionSnapshot
        {
            int                  snapshot_id;
            int                  session_id;
            int                  scenario_id;
            double               elapsed_time;
            std::string          tag;
        };
    }
}

#endif

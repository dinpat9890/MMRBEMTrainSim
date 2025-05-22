//**************************************************************************************************
//
//  File:           PassengerInfo.us.cpp
//
//  Description:    PassengerInfo class definition
//
//  Reference:      95809A9A
//
//  Author:         Craig Biggs
//
//  (C) Copyright:  SYDAC Pty Ltd, 2012
//
//***************************************************************************************************

#ifndef PASSENGER_INFO_CPP
#define PASSENGER_INFO_CPP

#include <passengers/PassengerInfoManager.us.cpp>
#include <utilities/PRNG.us.cpp>

using TimeUtils;

namespace Passengers
{
    void registerPassengerInfo()
    {
        PassengerInfoManager info_manager = getPassengerInfoManager();


        TimeUtils::Season cool_months[]    = ( new Season(TimeUtils::MAY, TimeUtils::SEP) );
        TimeUtils::Season warm_months[]    = ( new Season(TimeUtils::SEP, TimeUtils::MAY) );
        TimeUtils::Season all_year_round[] = ( new Season(TimeUtils::JAN, TimeUtils::DEC) );

        // We will use a pseudo-random number generator to create some variance in walking
        // and running speed and animation speed. By specifying the seed, we ensure the same values are used
        // every time the simulator is run.
        float MIN_WALKING_SPEED = 1.35f; // m/s
        float MAX_WALKING_SPEED = 1.65f; // m/s
        float MIN_RUNNING_SPEED = 2.8f;  // m/s (approx 10 km/h)
        float MAX_RUNNING_SPEED = 4.2f;  // m/s (approx 15 km/h)
        float TURNING_SPEED     = 4.5;   // radians per second
        float MIN_ANIM_SPEED    = 30.0;   // scale, 30 is standard speed
        float MAX_ANIM_SPEED    = 50.0;   // scale, 30 is standard speed

        Utilities::PRNG speed_rng = new Utilities::PRNG(12345);

        class PassengerAnimations
        {
            string walking;
            string running;
            string idle;
            string sitting;

            PassengerAnimations(string walking, string running, string idle, string sitting)
            {
                this.walking = walking;
                this.running = running;
                this.idle    = idle;
                this.sitting = sitting;
            }
        };

        PassengerAnimations male_animations_1           = new PassengerAnimations("core/graphics/characters/graphics/animations/ma_walking.anim",       "core/graphics/characters/graphics/animations/ma_running.anim",         "core/graphics/characters/graphics/animations/ma_idle_1.anim",       "core/graphics/characters/graphics/animations/ma_seated.anim");
        PassengerAnimations male_animations_2           = new PassengerAnimations("core/graphics/characters/graphics/animations/ma_walking.anim",       "core/graphics/characters/graphics/animations/ma_running.anim",         "core/graphics/characters/graphics/animations/ma_idle_2.anim",       "core/graphics/characters/graphics/animations/ma_seated.anim");
        PassengerAnimations female_animations_1         = new PassengerAnimations("core/graphics/characters/graphics/animations/fa_walking.anim",       "core/graphics/characters/graphics/animations/fa_running.anim",         "core/graphics/characters/graphics/animations/fa_idle_1.anim",       "core/graphics/characters/graphics/animations/fa_seated.anim");
        PassengerAnimations female_animations_2         = new PassengerAnimations("core/graphics/characters/graphics/animations/fa_walking.anim",       "core/graphics/characters/graphics/animations/fa_running.anim",         "core/graphics/characters/graphics/animations/fa_idle_2.anim",       "core/graphics/characters/graphics/animations/fa_seated.anim");
        PassengerAnimations female_heels_animations_1   = new PassengerAnimations("core/graphics/characters/graphics/animations/fa_heels_walking.anim", "core/graphics/characters/graphics/animations/fa_heels_running.anim",   "core/graphics/characters/graphics/animations/fa_heels_idle_1.anim", "core/graphics/characters/graphics/animations/fa_heels_seated.anim");
        PassengerAnimations female_heels_animations_2   = new PassengerAnimations("core/graphics/characters/graphics/animations/fa_heels_walking.anim", "core/graphics/characters/graphics/animations/fa_heels_running.anim",   "core/graphics/characters/graphics/animations/fa_heels_idle_2.anim", "core/graphics/characters/graphics/animations/fa_heels_seated.anim");
        PassengerAnimations female_old_animations       = new PassengerAnimations("core/graphics/characters/graphics/animations/fa_old_walking.anim",   "core/graphics/characters/graphics/animations/fa_old_walking.anim",     "core/graphics/characters/graphics/animations/fa_old_idle.anim",     "core/graphics/characters/graphics/animations/fa_old_seated.anim");
        PassengerAnimations male_child_animations       = new PassengerAnimations("core/graphics/characters/graphics/animations/mc_walking.anim",       "core/graphics/characters/graphics/animations/mc_running.anim",         "core/graphics/characters/graphics/animations/mc_idle.anim",         "core/graphics/characters/graphics/animations/mc_seated.anim");
        PassengerAnimations female_child_animations     = new PassengerAnimations("core/graphics/characters/graphics/animations/fc_walking.anim",       "core/graphics/characters/graphics/animations/fc_running.anim",         "core/graphics/characters/graphics/animations/fc_idle.anim",         "core/graphics/characters/graphics/animations/fc_seated.anim");

        // Please see the constructor for the meaning of the parameters for PassengerInfo. However for convenience sake the parameters are listed here:
        // passenger type (matches passenger feature class name), model name, walk anim, run anim, idle anim, sit anim, walk speed (m/s), run speed (m/s), turn speed (radians per second)
        void addPassenger(string MODEL_NAME, PassengerAnimations animations, TimeUtils::Season seasons[], int late_arriving = 1)
        {
            float WALKING_SPEED = speed_rng.nextBetween(MIN_WALKING_SPEED, MAX_WALKING_SPEED);
            float RUNNING_SPEED = speed_rng.nextBetween(MIN_RUNNING_SPEED, MAX_RUNNING_SPEED);
            float ANIM_SPEED    = speed_rng.nextBetween(MIN_ANIM_SPEED,    MAX_ANIM_SPEED);

            // Scale the animation speed based on the walking and running speed.
            float WALKING_SCALE = MIN_ANIM_SPEED + (((WALKING_SPEED - MIN_WALKING_SPEED) / (MAX_WALKING_SPEED - MIN_WALKING_SPEED)) * (MAX_ANIM_SPEED - MIN_ANIM_SPEED));
            float RUNNING_SCALE = MIN_ANIM_SPEED + (((RUNNING_SPEED - MIN_RUNNING_SPEED) / (MAX_RUNNING_SPEED - MIN_RUNNING_SPEED)) * (MAX_ANIM_SPEED - MIN_ANIM_SPEED));

            foreach(Season season; seasons)
            {
                info_manager.registerPassengerInfo(new PassengerInfo(PassengerType::BOARDING,
                                                                     MODEL_NAME,
                                                                     (new AnimationInfo(animations.walking, WALKING_SPEED, WALKING_SCALE),
                                                                      new AnimationInfo(animations.running, RUNNING_SPEED, RUNNING_SCALE),
                                                                      new AnimationInfo(animations.idle,    0.0, ANIM_SPEED),
                                                                      new AnimationInfo(animations.sitting, 0.0, ANIM_SPEED)),
                                                                     TURNING_SPEED,
                                                                     season));

                if(late_arriving)
                {
                    info_manager.registerPassengerInfo(new PassengerInfo(PassengerType::ARRIVING,
                                                                     MODEL_NAME,
                                                                     (new AnimationInfo(animations.walking, WALKING_SPEED, WALKING_SCALE),
                                                                      new AnimationInfo(animations.running, RUNNING_SPEED, RUNNING_SCALE),
                                                                      new AnimationInfo(animations.idle,    0.0, ANIM_SPEED),
                                                                      new AnimationInfo(animations.sitting, 0.0, ANIM_SPEED)),
                                                                     TURNING_SPEED,
                                                                     season));
                }
            }
        }

        int TOO_OLD_TO_RUN = 0;

        // Female

        addPassenger("fa_business_asian_01a",   female_heels_animations_1, all_year_round);
        addPassenger("fa_business_asian_01b",   female_heels_animations_1, all_year_round);
        addPassenger("fa_business_asian_01c",   female_heels_animations_1, all_year_round);
        addPassenger("fa_business_asian_01d",   female_heels_animations_1, all_year_round);
        addPassenger("fa_business_asian_04a",   female_heels_animations_1, all_year_round);
        addPassenger("fa_business_asian_04b",   female_heels_animations_1, all_year_round);
        addPassenger("fa_business_asian_04c",   female_heels_animations_1, all_year_round);
        addPassenger("fa_business_asian_04d",   female_heels_animations_1, all_year_round);

        addPassenger("FA_casual_indian_01",     female_heels_animations_1, all_year_round);
        addPassenger("FA_casual_indian_02",     female_heels_animations_1, all_year_round);
        addPassenger("FA_casual_indian_03",     female_heels_animations_1, all_year_round);
        addPassenger("FA_casual_indian_04",     female_heels_animations_1, all_year_round);
        addPassenger("FA_casual_indian_05",     female_heels_animations_1, all_year_round);
        addPassenger("FA_casual_indian_06",     female_heels_animations_1, all_year_round);
        addPassenger("FA_casual_indian_07",     female_heels_animations_1, all_year_round);
        addPassenger("FA_casual_indian_08",     female_heels_animations_1, all_year_round);
        addPassenger("FA_casual_indian_09",     female_heels_animations_1, all_year_round);
        addPassenger("FA_casual_indian_10",     female_heels_animations_1, all_year_round);

        addPassenger("FA_casual_indian_01",     female_animations_1, all_year_round);
        addPassenger("FA_casual_indian_02",     female_animations_1, all_year_round);
        addPassenger("FA_casual_indian_03",     female_animations_1, all_year_round);
        addPassenger("FA_casual_indian_04",     female_animations_1, all_year_round);
        addPassenger("FA_casual_indian_05",     female_animations_1, all_year_round);
        addPassenger("FA_casual_indian_06",     female_animations_1, all_year_round);
        addPassenger("FA_casual_indian_07",     female_animations_1, all_year_round);
        addPassenger("FA_casual_indian_08",     female_animations_1, all_year_round);
        addPassenger("FA_casual_indian_09",     female_animations_1, all_year_round);
        addPassenger("FA_casual_indian_10",     female_animations_1, all_year_round);

        addPassenger("FA_casual_indian_01",     female_animations_2, all_year_round);
        addPassenger("FA_casual_indian_02",     female_animations_2, all_year_round);
        addPassenger("FA_casual_indian_03",     female_animations_2, all_year_round);
        addPassenger("FA_casual_indian_04",     female_animations_2, all_year_round);
        addPassenger("FA_casual_indian_05",     female_animations_2, all_year_round);
        addPassenger("FA_casual_indian_06",     female_animations_2, all_year_round);
        addPassenger("FA_casual_indian_07",     female_animations_2, all_year_round);
        addPassenger("FA_casual_indian_08",     female_animations_2, all_year_round);
        addPassenger("FA_casual_indian_09",     female_animations_2, all_year_round);
        addPassenger("FA_casual_indian_10",     female_animations_2, all_year_round);

        addPassenger("fa_casual_asian_01a",     female_animations_1, all_year_round);
        addPassenger("fa_casual_asian_01b",     female_animations_1, all_year_round);
        addPassenger("fa_casual_asian_01c",     female_animations_1, all_year_round);
        addPassenger("fa_casual_asian_01d",     female_animations_1, all_year_round);
        addPassenger("fa_casual_asian_25a",     female_animations_1, all_year_round);
        addPassenger("fa_casual_asian_25b",     female_animations_1, all_year_round);
        addPassenger("fa_casual_asian_25c",     female_animations_1, all_year_round);
        addPassenger("fa_sport_asian_07a",      female_animations_1, all_year_round);
        addPassenger("fa_sport_asian_07b",      female_animations_1, all_year_round);
        addPassenger("fa_sport_asian_07c",      female_animations_1, all_year_round);
        addPassenger("fa_sport_asian_07d",      female_animations_1, all_year_round);
        addPassenger("fa_sport_asian_07e",      female_animations_1, all_year_round);

        addPassenger("fa_old_asian_01a",        female_old_animations, all_year_round, TOO_OLD_TO_RUN);

        addPassenger("fa_business_asian_01a",   female_heels_animations_2, all_year_round);
        addPassenger("fa_business_asian_01b",   female_heels_animations_2, all_year_round);
        addPassenger("fa_business_asian_01c",   female_heels_animations_2, all_year_round);
        addPassenger("fa_business_asian_01d",   female_heels_animations_2, all_year_round);
        addPassenger("fa_business_asian_04a",   female_heels_animations_2, all_year_round);
        addPassenger("fa_business_asian_04b",   female_heels_animations_2, all_year_round);
        addPassenger("fa_business_asian_04c",   female_heels_animations_2, all_year_round);
        addPassenger("fa_business_asian_04d",   female_heels_animations_2, all_year_round);

        addPassenger("FA_casual_indian_01",     female_heels_animations_2, all_year_round);
        addPassenger("FA_casual_indian_02",     female_heels_animations_2, all_year_round);
        addPassenger("FA_casual_indian_03",     female_heels_animations_2, all_year_round);
        addPassenger("FA_casual_indian_04",     female_heels_animations_2, all_year_round);
        addPassenger("FA_casual_indian_05",     female_heels_animations_2, all_year_round);
        addPassenger("FA_casual_indian_06",     female_heels_animations_2, all_year_round);
        addPassenger("FA_casual_indian_07",     female_heels_animations_2, all_year_round);

        addPassenger("fa_casual_asian_01a",     female_animations_2, all_year_round);
        addPassenger("fa_casual_asian_01b",     female_animations_2, all_year_round);
        addPassenger("fa_casual_asian_01c",     female_animations_2, all_year_round);
        addPassenger("fa_casual_asian_01d",     female_animations_2, all_year_round);
        addPassenger("fa_casual_asian_25a",     female_animations_2, all_year_round);
        addPassenger("fa_casual_asian_25b",     female_animations_2, all_year_round);
        addPassenger("fa_casual_asian_25c",     female_animations_2, all_year_round);
        addPassenger("fa_sport_asian_07a",      female_animations_2, all_year_round);
        addPassenger("fa_sport_asian_07b",      female_animations_2, all_year_round);
        addPassenger("fa_sport_asian_07c",      female_animations_2, all_year_round);
        addPassenger("fa_sport_asian_07d",      female_animations_2, all_year_round);
        addPassenger("fa_sport_asian_07e",      female_animations_2, all_year_round);

        // Male

        addPassenger("MA_casual_indian_01",     male_animations_1, all_year_round);
        addPassenger("MA_casual_indian_02",     male_animations_1, all_year_round);
        addPassenger("MA_casual_indian_03",     male_animations_1, all_year_round);
        addPassenger("MA_casual_indian_04",     male_animations_1, all_year_round);
        addPassenger("MA_casual_indian_05",     male_animations_1, all_year_round);
        addPassenger("MA_casual_indian_06",     male_animations_1, all_year_round);
        addPassenger("MA_casual_indian_07",     male_animations_1, all_year_round);
        addPassenger("MA_casual_indian_08",     male_animations_1, all_year_round);
        addPassenger("MA_casual_indian_09",     male_animations_1, all_year_round);
        addPassenger("MA_casual_indian_10",     male_animations_1, all_year_round);

        addPassenger("MA_casual_indian_01",     male_animations_2, all_year_round);
        addPassenger("MA_casual_indian_02",     male_animations_2, all_year_round);
        addPassenger("MA_casual_indian_03",     male_animations_2, all_year_round);
        addPassenger("MA_casual_indian_04",     male_animations_2, all_year_round);
        addPassenger("MA_casual_indian_05",     male_animations_2, all_year_round);
        addPassenger("MA_casual_indian_06",     male_animations_2, all_year_round);
        addPassenger("MA_casual_indian_07",     male_animations_2, all_year_round);
        addPassenger("MA_casual_indian_08",     male_animations_2, all_year_round);
        addPassenger("MA_casual_indian_09",     male_animations_2, all_year_round);
        addPassenger("MA_casual_indian_10",     male_animations_2, all_year_round);

        addPassenger("ma_business_asian_01a",   male_animations_1, all_year_round);
        addPassenger("ma_business_asian_01b",   male_animations_1, all_year_round);
        addPassenger("ma_business_asian_01c",   male_animations_1, all_year_round);
        addPassenger("ma_business_asian_01d",   male_animations_1, all_year_round);
        addPassenger("ma_business_asian_03a",   male_animations_1, all_year_round);
        addPassenger("ma_business_asian_03b",   male_animations_1, all_year_round);
        addPassenger("ma_business_asian_03c",   male_animations_1, all_year_round);
        addPassenger("ma_business_asian_03d",   male_animations_1, all_year_round);
        addPassenger("ma_casual_asian_02a",     male_animations_1, all_year_round);
        addPassenger("ma_casual_asian_02b",     male_animations_1, all_year_round);
        addPassenger("ma_casual_asian_02c",     male_animations_1, all_year_round);
        addPassenger("ma_casual_asian_02d",     male_animations_1, all_year_round);
        addPassenger("ma_casual_asian_02e",     male_animations_1, all_year_round);
        addPassenger("ma_casual_asian_05a",     male_animations_1, all_year_round);
        addPassenger("ma_casual_asian_05b",     male_animations_1, all_year_round);
        addPassenger("ma_casual_asian_05c",     male_animations_1, all_year_round);
        addPassenger("ma_casual_asian_05d",     male_animations_1, all_year_round);
        addPassenger("ma_casual_asian_16a",     male_animations_1, all_year_round);
        addPassenger("ma_casual_asian_16b",     male_animations_1, all_year_round);
        addPassenger("ma_casual_asian_16c",     male_animations_1, all_year_round);
        addPassenger("ma_casual_asian_16d",     male_animations_1, all_year_round);
        addPassenger("ma_casual_asian_28b",     male_animations_1, all_year_round);
        addPassenger("ma_casual_asian_28c",     male_animations_1, all_year_round);
        addPassenger("ma_casual_asian_28d",     male_animations_1, all_year_round);
        addPassenger("ma_casual_asian_old_28a", male_animations_1, all_year_round, TOO_OLD_TO_RUN);
        addPassenger("ma_sport_asian_03a",      male_animations_1, all_year_round);
        addPassenger("ma_sport_asian_03b",      male_animations_1, all_year_round);
        addPassenger("ma_sport_asian_03c",      male_animations_1, all_year_round);
        addPassenger("ma_sport_asian_03d",      male_animations_1, all_year_round);

        addPassenger("ma_business_asian_01a",   male_animations_2, all_year_round);
        addPassenger("ma_business_asian_01b",   male_animations_2, all_year_round);
        addPassenger("ma_business_asian_01c",   male_animations_2, all_year_round);
        addPassenger("ma_business_asian_01d",   male_animations_2, all_year_round);
        addPassenger("ma_business_asian_03a",   male_animations_2, all_year_round);
        addPassenger("ma_business_asian_03b",   male_animations_2, all_year_round);
        addPassenger("ma_business_asian_03c",   male_animations_2, all_year_round);
        addPassenger("ma_business_asian_03d",   male_animations_2, all_year_round);
        addPassenger("ma_casual_asian_02a",     male_animations_2, all_year_round);
        addPassenger("ma_casual_asian_02b",     male_animations_2, all_year_round);
        addPassenger("ma_casual_asian_02c",     male_animations_2, all_year_round);
        addPassenger("ma_casual_asian_02d",     male_animations_2, all_year_round);
        addPassenger("ma_casual_asian_02e",     male_animations_2, all_year_round);
        addPassenger("ma_casual_asian_05a",     male_animations_2, all_year_round);
        addPassenger("ma_casual_asian_05b",     male_animations_2, all_year_round);
        addPassenger("ma_casual_asian_05c",     male_animations_2, all_year_round);
        addPassenger("ma_casual_asian_05d",     male_animations_2, all_year_round);
        addPassenger("ma_casual_asian_16a",     male_animations_2, all_year_round);
        addPassenger("ma_casual_asian_16b",     male_animations_2, all_year_round);
        addPassenger("ma_casual_asian_16c",     male_animations_2, all_year_round);
        addPassenger("ma_casual_asian_16d",     male_animations_2, all_year_round);
        addPassenger("ma_casual_asian_28b",     male_animations_2, all_year_round);
        addPassenger("ma_casual_asian_28c",     male_animations_2, all_year_round);
        addPassenger("ma_casual_asian_28d",     male_animations_2, all_year_round);
        addPassenger("ma_casual_asian_old_28a", male_animations_2, all_year_round, TOO_OLD_TO_RUN);
        addPassenger("ma_sport_asian_03a",      male_animations_2, all_year_round);
        addPassenger("ma_sport_asian_03b",      male_animations_2, all_year_round);
        addPassenger("ma_sport_asian_03c",      male_animations_2, all_year_round);
        addPassenger("ma_sport_asian_03d",      male_animations_2, all_year_round);

        // Children

        addPassenger("fc_asian_01a",    female_child_animations, all_year_round);
        addPassenger("fc_asian_01b",    female_child_animations, all_year_round);
        addPassenger("mc_asian_01a",    male_child_animations, all_year_round);
        addPassenger("mc_asian_01b",    male_child_animations, all_year_round);

        // We need to map each passenger type to the locations that they are able to occupy on vehicle. The parameters for LocationInfo are listed here:
        // location type, passenger type, animation type
        info_manager.registerLocationInfo(new Passengers::Vehicle::LocationInfo(Passengers::VehicleLocationType::STANDING, new Unigine::Vector((PassengerType::ARRIVING, PassengerType::BOARDING)), Passengers::AnimType::STAND));
        info_manager.registerLocationInfo(new Passengers::Vehicle::LocationInfo(Passengers::VehicleLocationType::SITTING, new Unigine::Vector((PassengerType::ARRIVING, PassengerType::BOARDING)), Passengers::AnimType::SIT));

        // We can register custom feature types here. Whilst it is nicer from a design perspective to have the registration associated with a feature script
        // and this would be a relatively simple change that doesn't distribute this custom_feature_type string, the ability to have all node information for passengers
        // in the one location is a key requirement for user configurability and as a result I've put these registrations with the other passenger registrations.
        Unigine::Vector special_passenger_infos = new Unigine::Vector();
        Unigine::Vector feature_types           = new Unigine::Vector();
        special_passenger_infos.append(new Passengers::PassengerInfo("Features::PlatformPassengerWheelchair",   "wheelchair_man",           "core/graphics/characters/graphics/animations/wheelchair_man_push.anim",    "core/graphics/characters/graphics/animations/wheelchair_man_push.anim",    "core/graphics/characters/graphics/animations/wheelchair_man_idle.anim",  "core/graphics/characters/graphics/animations/wheelchair_man_idle.anim",    1.0, 1.0, 4.5));
        special_passenger_infos.append(new Passengers::PassengerInfo("Features::PlatformPassengerPram",         "fa_pram_01",               "core/graphics/characters/graphics/animations/fa_pram_push.anim",           "core/graphics/characters/graphics/animations/fa_pram_push.anim",           "core/graphics/characters/graphics/animations/fa_pram_idle.anim",         "core/graphics/characters/graphics/animations/fa_pram_idle.anim",           1.0, 1.0, 4.5));
        special_passenger_infos.append(new Passengers::PassengerInfo("Features::PlatformPassengerIntoxicated",  "ma_business_asian_01a",    "core/graphics/characters/graphics/animations/ma_walking_drunk.anim",       "core/graphics/characters/graphics/animations/ma_walking_drunk.anim",       "core/graphics/characters/graphics/animations/ma_idle_drunk.anim",        "core/graphics/characters/graphics/animations/ma_idle_drunk.anim",          0.5, 0.5, 4.5));

        foreach(Passengers::PassengerInfo info; special_passenger_infos.data)
        {
            feature_types.append(info.getType());
            info_manager.registerPassengerInfo(info);
        }

        // All special passengers can go in the same location. If you need something different here, then modify the code to suit your project needs
        info_manager.registerLocationInfo(new Passengers::Vehicle::LocationInfo(Passengers::VehicleLocationType::SPECIAL, feature_types, Passengers::AnimType::STAND));
    }
}

#endif

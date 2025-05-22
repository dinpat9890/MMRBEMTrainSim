#pragma once

#include "glm\mat3x3.hpp"
#include "glm\vec3.hpp"

namespace MotionBase
{
    class Parameters final
    {
    public:
        Parameters() 
            : m_is_valid(false)
        {}

        /// @note Values are in the simulator coordinate system.
        /// @param simulator_platform_manual_position
        ///        Units are millimetres.
        /// @param simulator_platform_manual_orientation
        ///        Orientation around each axis, in radians.
        Parameters(const glm::dvec3 &vehicle_velocity,
                   const glm::dvec3 &vehicle_acceleration,
                   const glm::dmat3 &rotation_matrix,
                   const glm::dvec3 &vehicle_angular_velocity,
                   const glm::dvec3 &vehicle_angular_acceleration,
                   const glm::dvec3 &simulator_platform_manual_position,
                   const glm::dvec3 &simulator_platform_manual_orientation,
                   const glm::dvec3 &vehicle_gravity_acceleration_projection)
          : m_vehicle_velocity(vehicle_velocity),
            m_vehicle_acceleration(vehicle_acceleration),
            m_rotation_matrix(rotation_matrix),
            m_vehicle_angular_velocity(vehicle_angular_velocity),
            m_vehicle_angular_acceleration(vehicle_angular_acceleration),
            m_simulator_platform_manual_position(simulator_platform_manual_position),
            m_simulator_platform_manual_orientation(simulator_platform_manual_orientation),
            m_vehicle_gravity_acceleration_projection(vehicle_gravity_acceleration_projection)
        {
            m_is_valid = Validate();   
        }

        const glm::dvec3 &GetVehicleVelocity() const { return m_vehicle_velocity; }
        double GetVehicleVelocityX() const { return m_vehicle_velocity.x; }
        double GetVehicleVelocityY() const { return m_vehicle_velocity.y; }
        double GetVehicleVelocityZ() const { return m_vehicle_velocity.z; }

        const glm::dvec3 &GetVehicleAcceleration() const { return m_vehicle_acceleration; }
        double GetVehicleAccelerationX() const { return m_vehicle_acceleration.x; }
        double GetVehicleAccelerationY() const { return m_vehicle_acceleration.y; }
        double GetVehicleAccelerationZ() const { return m_vehicle_acceleration.z; }

        const glm::dmat3 &GetRotationMatrix() const { return m_rotation_matrix; }
        double GetRotationMatrix11() const { return m_rotation_matrix[0][0]; }
        double GetRotationMatrix12() const { return m_rotation_matrix[0][1]; }
        double GetRotationMatrix13() const { return m_rotation_matrix[0][2]; }
        double GetRotationMatrix21() const { return m_rotation_matrix[1][0]; }
        double GetRotationMatrix22() const { return m_rotation_matrix[1][1]; }
        double GetRotationMatrix23() const { return m_rotation_matrix[1][2]; }
        double GetRotationMatrix31() const { return m_rotation_matrix[2][0]; }
        double GetRotationMatrix32() const { return m_rotation_matrix[2][1]; }
        double GetRotationMatrix33() const { return m_rotation_matrix[2][2]; }

        const glm::dvec3 &GetVehicleAngularVelocity() const { return m_vehicle_angular_velocity; }
        double GetVehicleAngularVelocityX() const { return m_vehicle_angular_velocity.x; }
        double GetVehicleAngularVelocityY() const { return m_vehicle_angular_velocity.y; }
        double GetVehicleAngularVelocityZ() const { return m_vehicle_angular_velocity.z; }

        const glm::dvec3 &GetVehicleAngularAcceleration() const { return m_vehicle_angular_acceleration; }
        double GetVehicleAngularAccelerationX() const { return m_vehicle_angular_acceleration.x; }
        double GetVehicleAngularAccelerationY() const { return m_vehicle_angular_acceleration.y; }
        double GetVehicleAngularAccelerationZ() const { return m_vehicle_angular_acceleration.z; }

        const glm::dvec3 &GetSimulatorPlatformManualPosition() const { return m_simulator_platform_manual_position; }
        double GetSimulatorPlatformManualPositionX() const { return m_simulator_platform_manual_position.x; }
        double GetSimulatorPlatformManualPositionY() const { return m_simulator_platform_manual_position.y; }
        double GetSimulatorPlatformManualPositionZ() const { return m_simulator_platform_manual_position.z; }
        
        const glm::dvec3 &GetSimulatorPlatformManualOrientation() const { return m_simulator_platform_manual_orientation; }
        double GetSimulatorPlatformManualOrientationYaw() const { return m_simulator_platform_manual_orientation.x; }
        double GetSimulatorPlatformManualOrientationPitch() const { return m_simulator_platform_manual_orientation.y; }
        double GetSimulatorPlatformManualOrientationRoll() const { return m_simulator_platform_manual_orientation.z; }

        const glm::dvec3 &GetVehicleGravityAccelerationProjection() const { return m_vehicle_gravity_acceleration_projection; }
        double GetVehicleGravityAccelerationProjectionX() const { return m_vehicle_gravity_acceleration_projection.x; }
        double GetVehicleGravityAccelerationProjectionY() const { return m_vehicle_gravity_acceleration_projection.y; }
        double GetVehicleGravityAccelerationProjectionZ() const { return m_vehicle_gravity_acceleration_projection.z; }

        bool    IsValid() const { return m_is_valid; }

    private:
        bool        m_is_valid;

        glm::dvec3 m_vehicle_velocity;
        glm::dvec3 m_vehicle_acceleration;
        glm::dmat3 m_rotation_matrix;
        glm::dvec3 m_vehicle_angular_velocity;
        glm::dvec3 m_vehicle_angular_acceleration;
        glm::dvec3 m_simulator_platform_manual_position;
        glm::dvec3 m_simulator_platform_manual_orientation;
        glm::dvec3 m_vehicle_gravity_acceleration_projection;

        bool    Validate() const;
    };
}
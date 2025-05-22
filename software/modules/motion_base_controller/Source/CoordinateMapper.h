///
/// @file       CoordinateMapper.h
///
///             Convert between simulator and GenIII coordinate systems.
///
/// @ingroup    KSRTC Simulator
///
/// @author     Peter Byrne
///
/// @copyright  (C) Copyright:  SYDAC Pty Ltd, 2018
///

#include "glm\mat3x3.hpp"
#include "glm\vec3.hpp"

namespace ckas_interface
{
    namespace
    {
        /// 3x3 transform matrix, from the simulator coordinate system to the Gen III
        /// Motion Base coordinate system.
        static const auto g_sim_to_gen3 = []
        {
            glm::dmat3 M(
                1.0,    0.0,    0.0,    // First Column
                0.0,   -1.0,    0.0,    // Second Column
                0.0,    0.0,   -1.0);   // Third Column
            return M;
        }();

        /// Inverse of the above.
        static const auto g_gen3_to_sim = []
        {
            // This matrix is its own inverse! I have a feeling there's a special
            // term for that... oooo, the term is "involutory"! Thanks, Google.
            glm::dmat3 M(
                1.0,    0.0,    0.0,    // First Column
                0.0,   -1.0,    0.0,    // Second Column
                0.0,    0.0,   -1.0);   // Third Column
            return M;
        }();
    }

    /// Convert vectors & matrices between the simulator coordinate system and
    /// the GenIII coordinate system
    class CoordinateMapper
    {
    public:
        /// Convert a 3D vector from simulator coordinates to GenIII coordinates
        static glm::dvec3     sim_to_gen3(const glm::dvec3 &v) { return g_sim_to_gen3 * v; }

        /// Convert a 3D vector from GenIII coordinates to simulator coordinates
        static glm::dvec3     gen3_to_sim(const glm::dvec3 &v) { return g_gen3_to_sim * v; }
        
        /// Convert a 3x3 matrix from simulator coordinates to GenIII coordinates
        static glm::dmat3     sim_to_gen3(const glm::dmat3 &m) { return g_sim_to_gen3 * m * g_gen3_to_sim; }
        
        /// Convert a 3x3 matrix from GenIII coordinates to simulator coordinates
        static glm::dmat3    gen3_to_sim(const glm::dmat3 &m) { return g_gen3_to_sim * m * g_sim_to_gen3; }
    };
}
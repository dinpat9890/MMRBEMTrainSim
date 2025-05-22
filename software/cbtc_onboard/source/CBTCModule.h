///
/// @file       CBTCModule.h
///
///             Declares the base CBTC Module class.
///
/// @author     Luke Errington
///
/// @copyright  (C) Copyright:  SYDAC Pty Ltd, 2017
///

#pragma once

#include "common\Utilities.h"

namespace Project
{
    namespace CBTCOnBoard
    {
        /// The base model class, using the CRTP, which ensures that models have a common form
        /// This is made unique because we use indirection to store state, which will break with a
        /// shallow copy.
        ///
        /// @tparam M The derived model class, with the Step function
        /// @tparam T The traits class that defines the initialisation, inputs, outputs and state
        ///           structures

        template <class M, class T>
        class CBTCModule : private Common::Unique
        {
        public:
            typedef typename T::Initialisation Initialisation;
            typedef typename T::Inputs         Inputs;
            typedef typename T::Outputs        Outputs;
            typedef typename T::State          State;

        public:
            /// Constructor, which just initializes the members

            CBTCModule(const typename Initialisation& init)
              : m_init(init), m_inputs(), m_outputs(), m_state(), m_state_pointer(&m_state)
            {
            }

            // This is really just to provide a common entrance function, and to standardize that all
            // child models will provide the step function

            /// The standard modelling entry function. It presumes that the derived class has a Step
            /// function. It supports providing the inputs and getting the outputs in the one function.
            ///
            /// @param time_step The amount of time that this cycle corresponds to
            /// @param inputs    The inputs to apply prior to modelling the cycle
            ///
            /// @return The output of the model after the cycle has been run

            const Outputs& RunCycle(double time_step, const Inputs& inputs)
            {
                GetInputs() = inputs;
                return RunCycle(time_step);
            }

            /// The alternative entry function for when the inputs have already been set.
            ///
            /// @param time_step The amount of time that this cycle corresponds to
            ///
            /// @return The output of the model after the cycle has been run

            const Outputs& RunCycle(double time_step)
            {
                static_cast<M&>(*this).Step(time_step);
                return GetOutputs();
            }

            /// Sets the state object that should be used. This allows us to be configured to use an
            /// external state object, which allows us to update the entire model's state at the one
            /// time. Updates the new state to match our current state.
            ///
            /// @param s A reference to the state object that should be used.

            void SetStateObject(State& s)
            {
				// Perform a copy of the existing state data (*m_state_pointer) into the external memory.
                s               = *m_state_pointer;

				// Then update the m_state_pointer to point to the external memory instead
                m_state_pointer = &s;
            }

            // Child classes will be expected to provide a Step function
            // void Step(double time_step);

            // Public accessors for querying, primarily used to get outputs but could be used out of
            // interest for the others as well
            inline const Initialisation& GetInit() const { return m_init; }
            inline const Inputs&         GetInputs() const { return m_inputs; }
            inline const Outputs&        GetOutputs() const { return m_outputs; }

            // Inputs and state can be accessed by non-const reference so that they can be modified in
            // place
            inline Inputs& GetInputs() { return m_inputs; }
            inline State&  GetState() { return *m_state_pointer; }

        protected:
            // Protected accessors for derived models so that the manner of access is hidden
            // Objects are returned non-const so that they can be modified
            // Just a note that short function names are provided for ease of us, to discourage the
            // reading in to local variables.
            // Also, the names K, U, Y and X were chosen based on the standardized expression of a
            // state space representation. K is used for 'constants', as this essentially comprises
            // the constants in the matrices A, B, C and D (in state space representation).
            inline const Initialisation& K() { return m_init; }
            inline Inputs&               U() { return m_inputs; }
            inline Outputs&              Y() { return m_outputs; }
            inline State&                X() { return *m_state_pointer; }

        private:
            // We have tried both composition and inheritance. Composition makes access to the variables
            // more verbose, but it does make it clearer. Additionally, it avoids name clashes between
            // inputs and outputs, or state, for instance, so is better.
            const Initialisation m_init;
            Inputs               m_inputs;
            Outputs              m_outputs;
            State                m_state;

            // Use a pointer so that we can change the state object that we use
            State* m_state_pointer;
        };
    }
}

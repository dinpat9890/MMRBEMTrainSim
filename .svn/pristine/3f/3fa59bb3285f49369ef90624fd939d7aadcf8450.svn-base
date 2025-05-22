/// @file IScenarioTrainLengthService.h
/// An interface for a service that supplies the length of a train based on
/// Scenario Train ID.
///
/// @author    Simon Wade (simon.wade@sydac.com.au)
/// @copyright © SYDAC Pty Ltd, 2016
#pragma once;

/// An interface for getting the length of a train within a simulator scenario.
class IScenarioTrainLengthService
{
public:
    virtual ~IScenarioTrainLengthService() { }

    /// @brief Returns the total length of a train, given its Scenario Train ID.
    ///
    /// @param scenario_train_id
    ///        The Scenario Train ID of the train in question. There are no
    ///        constraints on this parameter; the service will return a length
    ///        if it can.
    ///
    /// @return The length of the train, in metres, or 0.0 if the train
    ///         is not known.
    virtual double GetTrainLength(int scenario_train_id) = 0;
};

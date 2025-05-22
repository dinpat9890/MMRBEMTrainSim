/// @file IScenarioTrainTypeService.h
/// An interface for a service that supplies the train type for a given
/// Scenario Train ID.
///
/// @author    Simon Wade (simon.wade@sydac.com.au)
/// @copyright © SYDAC Pty Ltd, 2016
#pragma once;

/// An interface for getting the type of a train within a simulator scenario.
class IScenarioTrainTypeService
{
public:
    virtual ~IScenarioTrainTypeService() { }

    /// @brief Returns the type ID of a train, given its Scenario Train ID.
    ///
    /// @param scenario_train_id
    ///        The Scenario Train ID of the train in question. There are no
    ///        constraints on this parameter; the service will return a type
    ///        if it can.
    ///
    /// @return The type ID of the train, or -1 is the train is unknown.
    virtual int GetTrainType(int scenario_train_id) = 0;
};

///
/// @file       ModelSpecific.h
///
///             A file that is model-specific. This is an entry point for parameters specific to
///             this model.
///
/// @copyright  (C) Copyright:  SYDAC Pty Ltd, 2015
///

#ifndef MODEL_SPECIFIC_H
#define MODEL_SPECIFIC_H

#include "Matlab\BEML_EMU.h"
#include "common\LexicalCast.h"
#include <map>
#include <string>

/// Resources associated with the model
class ModelResource
{
public:
    /// Wraps up a model
    ModelResource(BEML_EMUModelClass &model)
        : m_model(model)
    {
    }

    BEML_EMUModelClass &Model()
    {
        return m_model;
    }

    ExtU_BEML_EMU_T &ModelInputs()
    {
        return m_model.BEML_EMU_U;
    }

    ExtY_BEML_EMU_T &ModelOutputs()
    {
        return m_model.BEML_EMU_Y;
    }

    //
    // Unmapped not working properly
    //

    // Variables mapped to the same name are shared
    double *Unmapped(const char *var_name)
    {
        return &m_unmapped_variables[var_name];
    }

    // No std::initializer_list is available yet
    double *Unmapped(const char *var_name, int index)
    {
        return &m_unmapped_variables[std::string(var_name) + "_" + Common::LexicalCast<std::string>(index)];
    }

    // External variables mapped to the same name are shared
    double *ExternallyModelled(const char *var_name)
    {
        return &m_unmapped_variables[var_name];
    }

private:
    BEML_EMUModelClass &m_model;

    // Unmapped variables still need a unique value
    std::map<std::string, double> m_unmapped_variables;
};

#endif // MODEL_SPECIFIC_H

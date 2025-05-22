#pragma once
#include "DataConnectionFactory.h"

namespace Project { class MotionBaseProperties; }

class MotionBaseDataConnectionFactory :  public DataConnectionFactory
{
    public:
        MotionBaseDataConnectionFactory(const Project::MotionBaseProperties &properties);
        ~MotionBaseDataConnectionFactory(void);

        std::unique_ptr<DataConnection> GetDataConnection() override;

    private:
        const Project::MotionBaseProperties &m_properties;
};


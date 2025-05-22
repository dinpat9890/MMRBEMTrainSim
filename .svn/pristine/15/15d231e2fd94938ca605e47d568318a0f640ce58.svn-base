//******************************************************************************
//
//  File:           MappableObject.h
//
//  Description:    Declares the MappableObject class, which allows properties of
//                  an object to be mapped easily to local variables.
//
//                  Based in James Erringtons MappedObject, simplified to keep the Numbers
//                  internal and doing away with one of the Base Classes.
//
//  Reference:      Shanghai Metro
//
//  Author:         Andy Cooper
//
//  (C) Copyright:  SYDAC Pty Ltd, 2014
//
//******************************************************************************
#pragma once

#include "sim_comms/OperationsInterfaces.h"

#include <memory>
#include <string>
#include <vector>

#undef GetObject

class MappableObject
{
public:
    Comms::Object GetObject() { return m_object; };
    Comms::Object GetObject() const { return m_object; };

    int GetObjectID()
    {
        if (m_object.IsValid())
            return m_object.GetID();
        else
            return Sim::INVALID_NUMBER;
    };

    int GetObjectID() const
    {
        return GetObjectID();
    };

    void Set();
    void Get();

protected:

    void MapObject(Comms::Object object, double request_frequency);
    void UnMapObject();
    void RequestAndRetrieve();

    // Mapping possibilites - Currently only numbers to Double, int and Bool. Raws to come.
    // Returns Number ID for Registering Callbacks later
    int MapNumber(double *pvalue, const std::string &name);
    int MapNumber(int    *pvalue, const std::string &name);
    int MapNumber(bool   *pvalue, const std::string &name);

    int MapRaw(std::string *pvalue, const std::string &name);
    int MapRaw(std::vector<std::string> *pvalue, const std::string &name);

    Sim::Tray MapTray(const std::string &name);

private:
    Comms::Object m_object;
    double        m_request_frequency;

    // Stored mappings for each type.
    // Note: Using a Shared Pointer here.
    std::vector<std::pair<std::shared_ptr<Sim::Number>, double *> > m_mapped_numbers;
    std::vector<std::pair<std::shared_ptr<Sim::Number>, int *> >    m_mapped_numbers_int;
    std::vector<std::pair<std::shared_ptr<Sim::Number>, bool *> >   m_mapped_numbers_bool;

    std::vector<std::pair<std::shared_ptr<Sim::Raw>, std::string *> >               m_mapped_raws_string;
    std::vector<std::pair<std::shared_ptr<Sim::Raw>, std::vector<std::string> *> >  m_mapped_raws_vector_string;

    // The Actual Numbers are maintained in a Vector of unique pointers
    // The Vector of Number ID's is kept to keep Requests Simple
    std::vector<std::shared_ptr<Sim::Number> >  m_numbers;
    std::vector<Sim::Number::ID>                m_number_ids;

    std::vector<std::shared_ptr<Sim::Raw> >     m_raws;
    std::vector<Sim::Raw::ID>                   m_raw_ids;

    std::vector<Sim::Tray::ID>                  m_tray_ids;
};

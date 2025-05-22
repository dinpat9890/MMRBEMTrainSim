///
/// @file       IVisionInterface.h
///
///             Store Vision Properties.
///             It is abstract class for Production Vision Interface & Test Vision Interface
///
/// @ingroup    Mumbai L2-L7 CCTV
///
/// @author     Yatendra Gupta
///
/// @copyright  (C) Copyright:  OKTAL SYDAC Pvt Ltd, 2022
///
#pragma once
#include <string>
#include <vector>
#include "core_data_access/CoreDataAccessTypes.h"
#include "core_services/CanvasObjectPerspectiveControl.h"
#include "Utility/CallbackCollection.h"

#ifndef IVISIONINTERFACE_H
#define IVISIONINTERFACE_H

typedef Callback<void, size_t>   Object_Callback_t;
typedef std::map<size_t, std::vector<Object_Callback_t *>>   Comms_Callback_Container_t;

namespace SaloonCCTV
{
    const std::string ENGINE_NAME = "Saloon_CCTV";
    const std::string ENGINE_NAME_INST = "Saloon_CCTV_inst";  // ENGINE_NAME_INST, Instructor vision engine is directly added in CCTVVisionManager.cpp
}

class IVisionInterface
{
public:
    virtual void Start() = 0;
    virtual void AddViews(const std::string &mode_name, std::vector<Core::View> views) = 0;
    virtual void UpdateView(const std::string &mode_name, size_t view_id, size_t perspective_id) = 0;
    virtual void UpdateView(const std::string &mode_name, std::vector<size_t> &perspective_id) = 0;
    virtual int GetPerspectiveId(const std::string &perspective_name) = 0;
    virtual int GetPerspectiveOfView(const std::string &mode_name, int view_id) = 0;
    virtual std::vector<Core::View> & GetView(const std::string &mode_name) = 0;
    virtual const std::vector<Core::Data::VisionEngineMode>& GetAllVisionEngineModes() const = 0;
    virtual void AddObjectCreationCallback(size_t class_id, const Object_Callback_t &cb) = 0;
};
#endif
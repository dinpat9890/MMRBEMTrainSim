/**
 * @file           Declares the base class of all the announcement types
 *  
 * @author         Nand Kumar sharma
 *
 * @copyright  (C) Copyright:  SYDAC Pty Ltd, 2020
 */

#pragma once

namespace PIS
{
namespace Audio
{

/**
 * Base class of all announcement types which is playable in the AudioController
 */

class Announcement
{
public:
    virtual ~Announcement() {};

    /**
     * Returns the type of the announcement as defined in the type in the priority matrix.
     * @return The type of the announcement
     */

    virtual int GetType() const = 0;
};

}
}

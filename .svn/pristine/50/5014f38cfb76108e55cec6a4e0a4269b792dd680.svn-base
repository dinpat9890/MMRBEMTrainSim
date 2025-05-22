/** 
 * @file       PublicAnnouncement class declaration
 *
 * @author     Nand Kumar sharma
 *
 * @copyright  (C) Copyright:  SYDAC Pty Ltd, 2020
 */ 

#pragma once

#include "Announcement.h"

#include <string>

namespace PIS
{
namespace Audio
{

/** 
 * PublicAnnouncement is an announcement which is NOT pre recorded.
 * This usually realized using audio routing and that functionality
 * is implemented outside the audio controller.
 * 
 * In addition to the main functionality above, AudioController supports 
 * playback of a pre-recorded audio file (jingle) just before the audio routing
 * connection is made.
 */ 

class PublicAnnouncement: public Announcement
{
public:

    /**
     * Constructor
     * @param type    The type of the public announcement
     */
    PublicAnnouncement(int type);
    
    /**
     * Destructor
     */

    ~PublicAnnouncement() override;

    /**
     * Returns the type of the announcement as defined in the priority matrix.
     * @return The type of the announcement
     */

    int GetType() const override;
    
    /**
     * Set tye type of the announcement as defined in the priority matrix.
     * @param type The type of the announcement
     */

    void SetType(int type);

    /**
     * Returns the name of the audio file to be played as the jingle.
     * @return The name of the jingle audio file
     */

    const std::string& GetJingle() const;
    
    /**
     * Sets the name of the audio file to be played as the jingle.
     * @param jingle The name of the jingle audio file
     */

    void SetJingle(const std::string &jingle);

private:

    int         m_type;
    std::string m_jingle;
};

}
}

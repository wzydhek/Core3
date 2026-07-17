/*
 * NewbieTutorialRequest.h
 *
 *  Created on: Nov 20, 2008
 *      Author: swgemu
 */

#pragma once

#include "engine/service/proto/BaseMessage.h"
#include "server/zone/packets/MessageCallback.h"


/* Valid action strings found:
 * openCharacterSheet
 * closeCharacterSheet
 * openInventory
 * closeInventory
 * openStatMigration
 * closeStatMigration
 * openHolocron
 * closeHolocron
 * zoomCamera
 * overlayMap
 * changeLookAtTarget
 * changeMouseMode
 * equipToolbar
 */

namespace server {
namespace zone {
namespace packets {
namespace player {

class NewbieTutorialRequest : public BaseMessage {
public:
   /**
    * Sets a trigger on certain actions.
    *
    * The client can have multiple triggers set at once.
    *
    * Once a trigger is activated, a NewbieTutorialRequest
    * packet is sent echoing the request and the trigger is reset.
    *
    * NOTE: there is a bug in the client which causes the
    *       closeInventory trigger to never reset
    *
    * See list above for valid action strings
    *
    * @param action action to be monitored
    */
	NewbieTutorialRequest(const String& action);

};

/**
 * Sends clientReady on zone.
 * Echos string sent by NewbieTutorialRequest, when action is triggered.
 */

class NewbieTutorialResponseCallback : public MessageCallback {
	String response;
public:
	NewbieTutorialResponseCallback(ZoneClientSession* client, ZoneProcessServer* server);

	void parse(Message* message);

	void run();

};

} // namespace player
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::player;

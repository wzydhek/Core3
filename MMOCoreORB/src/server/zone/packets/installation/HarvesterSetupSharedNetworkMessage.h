/*
 * HarvesterSetupSharedNetworkMessage.h
 *
 *  Created on: Oct 7, 2008
 *      Author: swgemu
 */

#pragma once

#include "server/zone/packets/object/ObjectControllerMessage.h"
#include "server/zone/objects/installation/InstallationObject.h"

namespace server {
namespace zone {
namespace packets {
namespace installation {

class HarvesterSetupSharedNetworkMessage : public ObjectControllerMessage {
public:
	HarvesterSetupSharedNetworkMessage(InstallationObject* inso);
};

} // namespace installation
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::installation;

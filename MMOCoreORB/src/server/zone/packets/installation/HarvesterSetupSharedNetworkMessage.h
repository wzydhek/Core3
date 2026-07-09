/*
 * HarvesterSetupSharedNetworkMessage.h
 *
 *  Created on: Oct 7, 2008
 *      Author: swgemu
 */

#pragma once

#include "server/zone/packets/object/ObjectControllerMessage.h"
#include "server/zone/objects/installation/InstallationObject.h"

class HarvesterSetupSharedNetworkMessage : public ObjectControllerMessage {
public:
	HarvesterSetupSharedNetworkMessage(InstallationObject* inso);
};

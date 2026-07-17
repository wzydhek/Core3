/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/packets/DeltaMessage.h"
#include "server/zone/objects/installation/harvester/HarvesterObject.h"

namespace server {
namespace zone {
namespace packets {
namespace harvester {

class HarvesterObjectDeltaMessage3 : public DeltaMessage {
	HarvesterObject* haro;
	
public:
	HarvesterObjectDeltaMessage3(HarvesterObject* ho);

	void updateDamage(uint32 value);
	
};

} // namespace harvester
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::harvester;

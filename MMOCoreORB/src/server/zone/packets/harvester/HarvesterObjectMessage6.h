/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/packets/BaseLineMessage.h"
#include "server/zone/objects/installation/harvester/HarvesterObject.h"

namespace server {
namespace zone {
namespace packets {
namespace harvester {

class HarvesterObjectMessage6 : public BaseLineMessage {
public:
	HarvesterObjectMessage6(HarvesterObject* hino);
};

} // namespace harvester
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::harvester;

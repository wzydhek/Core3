/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/packets/DeltaMessage.h"
#include "server/zone/objects/creature/CreatureObject.h"

namespace server {
namespace zone {
namespace packets {
namespace creature {

class CreatureObjectDeltaMessage1 : public DeltaMessage {
	CreatureObjectImplementation* creo;

public:
	CreatureObjectDeltaMessage1(CreatureObjectImplementation* cr);

	void updateBankCredits();

	void updateCashCredits();

};

} // namespace creature
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::creature;

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

class CreatureObjectDeltaMessage3 : public DeltaMessage {
	CreatureObject* creo;

public:
	CreatureObjectDeltaMessage3(CreatureObject* cr);

	void updateCharacterAppearance();

	void updateCreatureBitmask(uint32 value);

	void updateIncapacitationRecoveryTime(uint32 duration);

	void updateConditionDamage();

	void updateMaxCondition();

	// 0x0A ??

	void updatePosture();

	void updateFactionRank();

	void updateCreatureLinkID();

	void updateHeight();

	void updateShockWounds();

	void updateStatesBitmask();

	// 0x11 - Wounds update handled in CreatureObjectImplementation
};

} // namespace creature
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::creature;

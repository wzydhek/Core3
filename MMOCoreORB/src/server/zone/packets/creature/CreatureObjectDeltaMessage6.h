/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions. */

#pragma once

#include "server/zone/packets/tangible/TangibleObjectDeltaMessage6.h"
#include "server/zone/objects/creature/CreatureObject.h"

namespace server {
namespace zone {
namespace packets {
namespace creature {

class CreatureObjectDeltaMessage6 : public TangibleObjectDeltaMessage6 {
	CreatureObject* creo;

public:
	CreatureObjectDeltaMessage6(CreatureObject* cr);

	void updateLevel(uint16 value);

	void updatePerformanceAnimation(const String& pAnimation);

	void updateMoodStr();

	void updateWeapon();

	void updateGroupID();

	void updateInviterId();

	void updateGuildID();

	void updateTarget();

	void updateMoodID();

	void updatePerformanceStartTime(uint32 startTime);

	void updatePerformanceType(int value);

	void updateAlternateAppearance();
};

} // namespace creature
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::creature;

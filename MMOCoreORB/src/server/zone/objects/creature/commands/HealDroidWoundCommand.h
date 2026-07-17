/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "QueueCommand.h"
#include "server/zone/objects/creature/ai/DroidObject.h"
#include "server/zone/objects/tangible/pharmaceutical/WoundPack.h"

namespace server {
namespace zone {
namespace objects {
namespace creature {
namespace commands {

class HealDroidWoundCommand : public QueueCommand {
	int mindCost;
	float range;
public:

	HealDroidWoundCommand(const String& name, ZoneProcessServer* server);

	void deactivateWoundTreatment(CreatureObject* creature) const;

	void doAnimations(CreatureObject* creature, CreatureObject* droid) const;

	void sendWoundMessage(CreatureObject* creature, DroidObject* droid, uint32 woundsHealed) const;

	bool canPerformSkill(CreatureObject* creature, CreatureObject* droid, WoundPack* woundPack, int mindCostNew) const;

	void parseModifier(const String& modifier, uint64& objectId) const;

	uint8 findAttribute(CreatureObject* creature) const;

	WoundPack* findWoundPack(CreatureObject* creature) const;

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const;

};

} // namespace commands
} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature::commands;

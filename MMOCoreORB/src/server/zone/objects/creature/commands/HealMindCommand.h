/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "QueueCommand.h"

namespace server {
namespace zone {
namespace objects {
namespace creature {
namespace commands {

class HealMindCommand : public QueueCommand {
	float mindCost;
	float mindWoundCost;
	float range;
public:

	HealMindCommand(const String& name, ZoneProcessServer* server);

	void doAnimations(CreatureObject* creature, CreatureObject* creatureTarget) const;

	void sendHealMessage(CreatureObject* creature, CreatureObject* creatureTarget, int mindDamage) const;

	int calculateWound(int wound, int poolWounds, int poolMax) const;

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const;

};

} // namespace commands
} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature::commands;

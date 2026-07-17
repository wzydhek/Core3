/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "QueueCommand.h"
#include "server/zone/objects/tangible/pharmaceutical/StimPack.h"
#include "server/zone/objects/creature/ai/DroidObject.h"

namespace server {
namespace zone {
namespace objects {
namespace creature {
namespace commands {

class HealDroidDamageCommand : public QueueCommand {
	float range;
	float mindCost;

public:

	HealDroidDamageCommand(const String& name, ZoneProcessServer* server);

	void deactivateInjuryTreatment(CreatureObject* creature) const;

	void doAnimations(CreatureObject* creature, CreatureObject* droid) const;

	StimPack* findStimPack(CreatureObject* creature) const;

	bool canPerformSkill(CreatureObject* creature, CreatureObject* droid, StimPack* stimPack, int mindCostNew) const;

	void sendHealMessage(CreatureObject* creature, DroidObject* droid, int healthDamage, int actionDamage, int mindDamage) const;

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const;

};

} // namespace commands
} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature::commands;

/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "QueueCommand.h"
#include "server/zone/objects/tangible/pharmaceutical/StimPack.h"

namespace server {
namespace zone {
namespace objects {
namespace creature {
namespace commands {

class HealPetCommand : public QueueCommand {
	float range;
	float mindCost;

public:

	HealPetCommand(const String& name, ZoneProcessServer* server);

	void deactivateInjuryTreatment(CreatureObject* creature) const;

	void doAnimations(CreatureObject* creature, CreatureObject* pet) const;

	StimPack* findStimPack(CreatureObject* creature) const;

	bool canPerformSkill(CreatureObject* creature, CreatureObject* pet, StimPack* stimPack, int mindCostNew) const;

	void sendHealMessage(CreatureObject* creature, CreatureObject* pet, int healthDamage, int actionDamage, int mindDamage) const;

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const;

};

} // namespace commands
} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature::commands;

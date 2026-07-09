/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "QueueCommand.h"
#include "server/zone/objects/tangible/pharmaceutical/StimPack.h"


class HealDamageCommand : public QueueCommand {
	float range;
	float mindCost;

public:
	HealDamageCommand(const String& name, ZoneProcessServer* server);

	void deactivateInjuryTreatment(CreatureObject* creature, bool isRangedStim) const;

	void doAnimations(CreatureObject* creature, CreatureObject* creatureTarget) const;

	void doAnimationsRange(CreatureObject* creature, CreatureObject* creatureTarget, int oid, float range) const;

	StimPack* findStimPack(CreatureObject* creature) const;

	bool checkTarget(CreatureObject* creature, CreatureObject* creatureTarget) const;

	bool canPerformSkill(CreatureObject* creature, CreatureObject* creatureTarget, StimPack* stimPack, int mindCostNew) const;

	void sendHealMessage(CreatureObject* creature, CreatureObject* creatureTarget, int healthDamage, int actionDamage, int mindDamage) const;

	void awardXp(CreatureObject* creature, const String& type, int power) const;

	void doAreaMedicActionTarget(CreatureObject* creature, CreatureObject* targetCreature, StimPack* stimPack) const;

	void handleArea(CreatureObject* creature, CreatureObject* areaCenter, StimPack* pharma, float range) const;

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const;

};


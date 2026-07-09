/*
 * CureStateCommand.h
 *
 *  Created on: 10/08/2010
 *      Author: victor
 */

#pragma once

#include "QueueCommand.h"
#include "server/zone/objects/tangible/pharmaceutical/CurePack.h"


class CurePackCommand : public QueueCommand {
protected:
	int mindCost;
	float range;
	uint64 state;
public:
	CurePackCommand(const String& name, ZoneProcessServer* server);

	void doAnimations(CreatureObject* creature, CreatureObject* creatureTarget) const;

	uint64 parseObjectID(const String& objectIDString) const;

	CurePack* findCurePack(CreatureObject* creature) const;

	void sendCureMessage(CreatureObject* object, CreatureObject* target) const;

	void deactivateConditionTreatment(CreatureObject* creature) const;

	void awardXp(CreatureObject* creature, const String& type, int power) const;

	bool checkTarget(CreatureObject* creature, CreatureObject* creatureTarget) const;

	void handleArea(CreatureObject* creature, CreatureObject* areaCenter, CurePack* pharma, float range) const;

	void doAreaMedicActionTarget(CreatureObject* creature, CreatureObject* creatureTarget, PharmaceuticalObject* pharma) const;

	bool canPerformSkill(CreatureObject* creature, CreatureObject* creatureTarget, CurePack* curePack, int mindCostNew) const;

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const;
};


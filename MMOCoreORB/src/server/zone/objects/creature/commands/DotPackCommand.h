/*
 * DotPackCommand.h
 *
 *  Created on: 11/08/2010
 *      Author: victor
 */

#pragma once

#include "QueueCommand.h"
#include "server/zone/objects/tangible/pharmaceutical/DotPack.h"


class DotPackCommand : public QueueCommand {
protected:
	String effectName;
	String skillName;
public:
	DotPackCommand(const String& name, ZoneProcessServer* server);

	void doAnimationsRange(CreatureObject* creature, CreatureObject* targetCreature, uint64 oid, float range, bool area, bool isPoisonDot) const;

	DotPack* findDotPack(CreatureObject* creature, uint8 pool, bool poolGiven) const;

	void parseModifier(const String& modifier, uint8& pool, uint64& objectId) const;

	bool checkTarget(CreatureObject* creature, CreatureObject* targetCreature, uint32 dotType) const;

	void awardXp(CreatureObject* creature, const String& type, int power) const;

	void handleArea(CreatureObject* attackerCreo, CreatureObject* targetCreature, DotPack* pharma, float range) const;

	void doAreaMedicActionTarget(CreatureObject* creature, CreatureObject* targetCreature, DotPack* dotPack) const;

	int hasCost(CreatureObject* creature) const;

	void applyCost(CreatureObject* creature, int mindDamage) const;

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const;

};


/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "QueueCommand.h"
#include "server/zone/objects/tangible/pharmaceutical/RevivePack.h"

class RevivePlayerCommand : public QueueCommand {
	float mindCost;
	float range;
public:

	RevivePlayerCommand(const String& name, ZoneProcessServer* server);

	bool canPerformSkill(CreatureObject* creature, CreatureObject* creatureTarget, RevivePack* revivePack, int mindCostNew) const;

	void parseModifier(const String& modifier, uint64& objectId) const;

	void awardXp(CreatureObject* creature, const String& type, int power) const;

	void applyDebuff(CreatureObject* creature) const;

	RevivePack* findRevivePack(CreatureObject* creature) const;

	void doAnimations(CreatureObject* creature, CreatureObject* creatureTarget) const;

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const;

};


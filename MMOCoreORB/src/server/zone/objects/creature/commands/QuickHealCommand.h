/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "QueueCommand.h"

class QuickHealCommand : public QueueCommand {
	int mindCost;
	int mindWoundCost;

	int healthHealed;
	int actionHealed;
	int mindHealed;

	float speed;
	float range;
public:

	QuickHealCommand(const String& name, ZoneProcessServer* server);

	void doAnimations(CreatureObject* creature, CreatureObject* creatureTarget) const;

	void sendHealMessage(CreatureObject* creature, CreatureObject* creatureTarget, int healthDamage, int actionDamage) const;

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const;

};


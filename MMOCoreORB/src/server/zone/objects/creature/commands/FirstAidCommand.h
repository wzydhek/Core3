/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "QueueCommand.h"

class FirstAidCommand : public QueueCommand {
	float mindCost;
	float range;
public:

	FirstAidCommand(const String& name, ZoneProcessServer* server);

	void doAnimations(CreatureObject* creature, CreatureObject* creatureTarget) const;

	void sendCureMessage(CreatureObject* object, CreatureObject* target) const;

	bool canPerformSkill(CreatureObject* creature, CreatureObject* creatureTarget) const;

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const;

};


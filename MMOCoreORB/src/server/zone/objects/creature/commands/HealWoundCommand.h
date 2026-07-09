/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "QueueCommand.h"
#include "server/zone/objects/tangible/pharmaceutical/WoundPack.h"

class HealWoundCommand : public QueueCommand {
	int mindCost;
	float range;
public:

	HealWoundCommand(const String& name, ZoneProcessServer* server);

	void deactivateWoundTreatment(CreatureObject* creature) const;

	void doAnimations(CreatureObject* creature, CreatureObject* creatureTarget) const;

	void awardXp(CreatureObject* creature, const String& type, int power) const;

	void sendWoundMessage(CreatureObject* object, CreatureObject* target, uint8 attribute, uint32 woundsHealed) const;

	bool canPerformSkill(CreatureObject* creature, CreatureObject* creatureTarget, WoundPack* woundPack, int mindCostNew) const;

	void parseModifier(const String& modifier, uint8& attribute, uint64& objectId) const;

	uint8 findAttribute(CreatureObject* creature, uint8 startAttribute = 0) const;


	WoundPack* findWoundPack(CreatureObject* creature, uint8 attribute) const;

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const;

};


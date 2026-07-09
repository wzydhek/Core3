/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "QueueCommand.h"
#include "server/zone/objects/tangible/pharmaceutical/EnhancePack.h"
#include "server/zone/objects/creature/buffs/Buff.h"

class HealEnhanceCommand : public QueueCommand {
	float mindCost;
	float range;

public:
	HealEnhanceCommand(const String& name, ZoneProcessServer* server);

	void deactivateWoundTreatment(CreatureObject* creature) const;

	EnhancePack* findEnhancePack(CreatureObject* enhancer, uint8 attribute) const;

	bool canPerformSkill(CreatureObject* enhancer, CreatureObject* patient, EnhancePack* enhancePack, int mindCostNew) const;

	void parseModifier(const String& modifier, uint8& attribute, uint64& objectId) const;

	void sendEnhanceMessage(CreatureObject* enhancer, CreatureObject* patient, uint8 attribute, uint32 buffApplied) const;

	uint32 getEnhancePackStrength(EnhancePack* enhancePack, CreatureObject* enhancer, CreatureObject* patient) const;

	uint32 getBuffStrength(Buff* existingbuff, int attribute) const;

	void awardXp(CreatureObject* creature, const String& type, int power) const;

	void doAnimations(CreatureObject* enhancer, CreatureObject* patient) const;

	int doQueueCommand(CreatureObject* enhancer, const uint64& target, const UnicodeString& arguments) const;
};


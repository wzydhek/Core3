/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "JediQueueCommand.h"

namespace server {
namespace zone {
namespace objects {
namespace creature {
namespace commands {

class ForceHealQueueCommand : public JediQueueCommand {
public:
	// Introducing our own enums since those will support being used in bitsets
	enum {
		HEALTH = 1,
		STRENGTH = 2,
		CONSTITUTION = 4,
		ACTION = 8,
		QUICKNESS = 16,
		STAMINA = 32,
		MIND = 64,
		FOCUS = 128,
		WILLPOWER = 256,
		BATTLE_FATIGUE = 512
	};

	enum {
		STUN = 1,
		DIZZY = 2,
		BLIND = 4,
		INTIMIDATE = 8,
	};

	enum {
		DISEASED = 1,
		POISONED = 2,
		BLEEDING = 4,
		ONFIRE   = 8
	};

	enum {
		HEAL_DAMAGE,
		HEAL_WOUNDS,
		HEAL_STATES,
		HEAL_BLEEDING,
		HEAL_POISON,
		HEAL_DISEASE,
		HEAL_FIRE,
		HEAL_FATIGUE
	};

	// these two enums are used for skills that allow healing on self and
	// others.
	enum {
		TARGET_AUTO = 0, // go by range !=0 for ranged / this is default
		TARGET_SELF = 1,
		TARGET_OTHER = 2
	};
protected:
	int speed;
	unsigned int allowedTarget;
	float forceCostMultiplier; // Value to be added to base force cost per point healed

	int statesToHeal; // bitmask of states to heal (STUN | DIZZY | BLINDED | INITIMDATED )
	int healStateCost; // Cost per state healed

	int healDiseaseCost; // > 0 heals given amount of dot damage
	int healPoisonCost; // > 0 heals given amount of poison
	int healBleedingCost; // > 0 heals given amount of bleeds
	int healFireCost; // > 0 heals given amount of fire dot

	int attributesToHeal; // bitmask of which attributes to heal, HEALTH etc..
	int woundAttributesToHeal; // bitmask of which attributes to heal, HEALTH etc..

	int healBattleFatigue; // amount of BF to heal
	int healAmount; // amount to heal (HAM pools)
	int healWoundAmount; // amount of wounds to heal

	int bleedHealIterations;
	int poisonHealIterations;
	int diseaseHealIterations;
	int fireHealIterations;

	int range; // range to heal up to, if <= 0 it heals the user

public:
	ForceHealQueueCommand(const String& name, ZoneProcessServer* server);

	void sendHealMessage(CreatureObject* creature, CreatureObject* target, int healType, int healSpec, int amount) const;

	int runCommandWithTarget(CreatureObject* creature, CreatureObject* targetCreature) const;

	int runCommand(CreatureObject* creature, CreatureObject* targetCreature) const;

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const override;

	bool isForceHealCommand() const override;

	void setForceCostMultiplier(float fcm);

	void setHealStateCost(unsigned int cost);

	void setStatesToHeal(unsigned int states);

	void setHealDiseaseCost(unsigned int cost);

	void setHealPoisonCost(unsigned int cost);

	void setHealBleedingCost(unsigned int cost);

	void setHealFireCost(unsigned int cost);

	void setAttributesToHeal(unsigned int attributes);

	void setWoundAttributesToHeal(unsigned int attributes);

	void setHealBattleFatigue(unsigned int amount);

	void setHealAmount(unsigned int amount);

	void setHealWoundAmount(unsigned int amount);

	void setBleedHealIterations(unsigned int amount);

	void setPoisonHealIterations(unsigned int amount);

	void setDiseaseHealIterations(unsigned int amount);

	void setFireHealIterations(unsigned int amount);

	void setRange(int r);

	void setSpeed(int s);

	void setAllowedTarget(unsigned int t);

};

} // namespace commands
} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature::commands;

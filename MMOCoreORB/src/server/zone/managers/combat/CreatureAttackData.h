/*
 * CreatureAttackData.h
 *
 *  Created on: Sep 27, 2010
 *      Author: dannuic
 */

#pragma once

#include "server/zone/objects/creature/commands/effect/StateEffect.h"
#include "server/zone/objects/creature/commands/effect/DotEffect.h"

class CombatQueueCommand;

class CreatureAttackData {
protected:
	const CombatQueueCommand* baseCommand;

	float minDamage;
	float maxDamage;
	int damageType;
	float damageMultiplier;
	float healthDamageMultiplier;
	float actionDamageMultiplier;
	float mindDamageMultiplier;
	int accuracyBonus;
	float speedMultiplier;
	int poolsToDamage;

	float healthCostMultiplier;
	float actionCostMultiplier;
	float mindCostMultiplier;
	float forceCostMultiplier;
	float frsLightMinDamageModifier;
	float frsLightMaxDamageModifier;
	float frsDarkMinDamageModifier;
	float frsDarkMaxDamageModifier;

	int range;
	int coneRange;
	int coneAngle;
	int areaRange;

	bool splashDamage;
	bool hitIncapTarget;

	uint64 targetID;

	const VectorMap<uint8, StateEffect>* stateEffects;
	const Vector<DotEffect>* dotEffects;

	bool forceAttack;
	uint8 trails;

	String combatSpam;

	int stateAccuracyBonus;

public:
	CreatureAttackData(const UnicodeString & dataString, const CombatQueueCommand *base, uint64 target);
	CreatureAttackData(const CreatureAttackData& data);
	virtual ~CreatureAttackData() {}

	void fillFromBase();
	void setVariable(const String& var, const String& val);

	const String& getCommandName() const;
	uint32 getCommandCRC() const;

	float getActionDamageMultiplier() const;

	void setActionDamageMultiplier(float actionDamageMultiplier);

	float getHealthDamageMultiplier() const;

	void setHealthDamageMultiplier(float healthDamageMultiplier);

	float getMindDamageMultiplier() const;

	void setMindDamageMultiplier(float mindDamageMultiplier);

	const CombatQueueCommand* getCommand() const;

	float getMinDamage() const;

	float getMaxDamage() const;

	int getDamageType() const;

	int getAccuracyBonus() const;

	float getActionCostMultiplier() const;

	void setSplashDamage(bool b);

	bool isSplashDamage() const;

	bool getHitIncapTarget() const;

	int getAreaRange() const;

	int getConeAngle() const;

	float getDamageMultiplier() const;

	float getForceCostMultiplier() const;

	float getHealthCostMultiplier() const;

	float getMindCostMultiplier() const;

	int getPoolsToDamage() const;

	int getConeRange() const;

	int getRange() const;

	float getSpeedMultiplier() const;

	const VectorMap<uint8, StateEffect>* getStateEffects() const;

	const Vector<DotEffect>* getDotEffects() const;

	bool isForceAttack() const;

	float getFrsLightMinDamageModifier() const;

	float getFrsLightMaxDamageModifier() const;

	float getFrsDarkMinDamageModifier() const;

	float getFrsDarkMaxDamageModifier() const;

	void setForceAttack(bool forceAttack);

	uint8 getTrails() const;

	uint64 getPrimaryTarget() const;

	void setTrails(uint8 trails);

	const String& getCombatSpam() const;

	void setCombatSpam(const String& spam);

	bool isStateOnlyAttack() const;

	int getStateAccuracyBonus() const;

	void setStateAccuracyBonus(int stateAccuracyBonus);

	bool changesDefenderPosture() const;
	bool changesAttackerPosture() const;
};

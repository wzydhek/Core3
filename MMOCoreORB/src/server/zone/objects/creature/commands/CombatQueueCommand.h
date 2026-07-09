/*
 * CombatQueueCommand.h
 *
 *  Created on: 24/05/2010
 *      Author: victor
 */

#pragma once

#include "QueueCommand.h"
#include "server/zone/objects/creature/commands/effect/StateEffect.h"
#include "server/zone/objects/creature/commands/effect/DotEffect.h"
#include "server/zone/objects/tangible/weapon/WeaponObject.h"
#include "server/zone/managers/combat/CreatureAttackData.h"

class CombatQueueCommand : public QueueCommand {
protected:
	float minDamage;
	float maxDamage;
	int damageType;
	float damageMultiplier;
	int accuracyBonus;
	float speedMultiplier;
	float speed;
	int poolsToDamage;

	float healthCostMultiplier;
	float actionCostMultiplier;
	float mindCostMultiplier;
	float forceCostMultiplier;
	float forceCost;
	int visMod;
	float frsLightForceCostModifier;
	float frsDarkForceCostModifier;
	float frsLightMinDamageModifier;
	float frsLightMaxDamageModifier;
	float frsDarkMinDamageModifier;
	float frsDarkMaxDamageModifier;

	int coneRange;
	int range;

	String accuracySkillMod;

	bool splashDamage;
	bool areaAction;
	bool coneAction;
	int coneAngle;
	int areaRange;

	String combatSpam;
	String stateSpam;
	String animation;
	String effectString;

	VectorMap<uint8, StateEffect> stateEffects;
	Vector<DotEffect> dotEffects;

	bool forceAttack;
	uint8 trails;
	uint8 animType;

	uint32 weaponType;

public:
	enum AnimGenTypes {
		GENERATE_NONE, // Uses animation as given - Default
		GENERATE_RANGED, // Generates _light|_medium as well as appends _face with headshots
		GENERATE_INTENSITY // generates _light|_medium only
	};

	CombatQueueCommand(const String& name, ZoneProcessServer* server);

	void onFail(uint32 actioncntr, CreatureObject* creature, uint32 errorNumber) const;

	int doCombatAction(CreatureObject* creature, const uint64& target, const UnicodeString& arguments = "", ManagedReference<WeaponObject*> weapon = nullptr) const;

	float getCommandDuration(CreatureObject* object, const UnicodeString& arguments) const;

	float getHealthCostMultiplier() const;

	float getActionCostMultiplier() const;

	float getMindCostMultiplier() const;

	int getConeRange() const;

	int getRange() const;

	const String& getAccuracySkillMod() const;

	float getDamageMultiplier() const;

	int getAccuracyBonus() const;

	float getSpeedMultiplier() const;

	float getSpeed() const;

	bool isSplashDamage() const;

	bool isAreaAction() const;

	bool isConeAction() const;

	int getConeAngle() const;

	int getAreaRange() const;

	float getForceCostMultiplier() const;

	float getForceCost() const;

	void setDamageMultiplier(float damageMultiplier);

	void setAccuracyBonus(int accuracyBonus);

	void setHealthCostMultiplier(float f);

	void setActionCostMultiplier(float f);

	void setMindCostMultiplier(float f);

	void setForceCostMultiplier(float f);

	void setForceCost(float f);

	void setConeAngle(int i);

	void setSplashDamage(bool b);

	void setAreaAction(bool b);

	void setConeAction(bool b);

	void setAreaRange(int i);

	void setEffectString(const String& s);

	void setSpeedMultiplier(float speedMultiplier);

	void setSpeed(float speedd);

	void setAnimType(uint8 type);

	uint8 getAnimType() const;

	const String& getAnimationString() const;

	static String getIntensity(int threshold, int damage);

	String getDefaultAttackAnimation(TangibleObject* attacker, WeaponObject* weapon, uint8 hitLocation, int damage) const;

	String generateAnimation(uint8 hitLocation, int weaponThreshold, int damage) const;

	virtual String getAnimation(TangibleObject* attacker, TangibleObject* defender, WeaponObject* weapon, uint8 hitLocation, int damage) const;

	const String& getEffectString() const;

	const String& getCombatSpam() const;

	int getPoolsToDamage() const;

	const VectorMap<uint8, StateEffect>* getStateEffects() const;

	const Vector<DotEffect>* getDotEffects() const;

	void setAnimationString(const String& anim);

	void setCombatSpam(const String& combatSpam);

	void setPoolsToDamage(int poolsToDamage);

	void setStateEffects(VectorMap<uint8, StateEffect> stateEffects);

	void addStateEffect(const StateEffect& stateEffect);

	const StateEffect& getStateEffect(uint8 type) const;

	void setDotEffects(const Vector<DotEffect>& dotEffects);

	float getMinDamage() const;

	void setMinDamage(float dm);

	float getMaxDamage() const;

	void setMaxDamage(float dm);

	int getDamageType() const;

	void setDamageType(float dm);

	void addDotEffect(const DotEffect& dotEffect);

	void setConeRange(int i);

	void setRange(int i);

	void setAccuracySkillMod(const String& acc);

	bool hasCombatSpam() const;

	bool isCombatCommand() const;

	virtual bool isSquadLeaderCommand();

	// this goes in command in order to allow for overriding for special commands
	virtual void applyEffect(CreatureObject* attacker, CreatureObject* defender, uint8 effectType, uint32 mod) const;

	//Override for special cases (skills like Taunt that don't have 5 result strings)
	virtual void sendAttackCombatSpam(TangibleObject* attacker, TangibleObject* defender, int attackResult, int damage, const CreatureAttackData& data) const;

	bool isForceAttack() const;

	void setForceAttack(bool forceAttack);

	uint8 getTrails() const;

	void setTrails(uint8 trails);

	uint32 getWeaponType() const;

	void setWeaponType(uint32 weaponType);

	bool validateWeapon(WeaponObject* weapon);

	void setVisMod(int vm);

	int getVisMod() const;

	void setFrsLightForceCostModifier(float val);

	void setFrsDarkForceCostModifier(float val);

	void setFrsLightMinDamageModifier(float val);

	void setFrsLightMaxDamageModifier(float val);

	void setFrsDarkMinDamageModifier(float val);

	void setFrsDarkMaxDamageModifier(float val);

	float getFrsLightMinDamageModifier() const;

	float getFrsLightMaxDamageModifier() const;

	float getFrsDarkMinDamageModifier() const;

	float getFrsDarkMaxDamageModifier() const;
};


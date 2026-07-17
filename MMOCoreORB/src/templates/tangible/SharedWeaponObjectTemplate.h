/*
 * SharedWeaponObjectTemplate.h
 *
 *  Created on: 05/05/2010
 *      Author: victor
 */

#pragma once

#include "templates/SharedTangibleObjectTemplate.h"

namespace templates {
namespace tangible {

class SharedWeaponObjectTemplate: public SharedTangibleObjectTemplate {
protected:
	StringParam weaponEffect;
	IntegerParam weaponEffectIndex;
	IntegerParam attackType;

	int damageType;

	int armorPiercing;

	int healthAttackCost;
	int actionAttackCost;
	int mindAttackCost;
	float forceCost;

	int pointBlankAccuracy;
	int pointBlankRange;

	int idealRange;
	int idealAccuracy;

	int maxRange;
	int maxRangeAccuracy;

	int minDamage;
	int maxDamage;

	float woundsRatio;

	int area;

	float attackSpeed;

	String combatSpam;
	String animationType;

	Vector<String> damageModifiers;
	Vector<String> speedModifiers;
	Vector<String> creatureAccuracyModifiers;
	Vector<String> creatureAimModifiers;
	Vector<String> defenderDefenseModifiers;
	Vector<String> defenderSecondaryDefenseModifiers;
	Vector<String> defenderToughnessModifiers;

	String xpType;

	uint32 weaponType;

public:
	enum APType {
		NONE,
		LIGHT,
		MEDIUM,
		HEAVY
	};
	enum DamageType {
		KINETIC = 1,
		ENERGY = 2,
		BLAST = 4,
		STUN = 8,
		LIGHTSABER = 16,
		HEAT = 32,
		COLD = 64,
		ACID = 128,
		ELECTRICITY = 256
	};

	// multiple weapon type scenarios
	enum WeaponClass {
		MELEEWEAPON = 0xF0,
		RANGEDWEAPON = 0x1F0B, // these are all weapons derived from ranged in the client
		JEDIWEAPON = 0xE000,
	};

	enum WeaponAttackType {
		MELEEATTACK = 0,
		RANGEDATTACK = 1,
		FORCEATTACK = 2,
		TRAPATTACK = 3,
		GRENADEATTACK = 4,
		HEAVYACIDBEAMATTACK = 14,
		HEAVYLIGHTNINGBEAMATTACK = 15,
		HEAVYPARTICLEBEAMATTACK = 17,
		HEAVYROCKETLAUNCHERATTACK = 18,
		HEAVYLAUNCHERATTACK = 19
	};

	enum WeaponType {
		ANYWEAPON = 0xFFFFFFFF,
		THROWNWEAPON = 0x1,
		HEAVYWEAPON = 0x2,
		MINEWEAPON = 0x4,
		SPECIALHEAVYWEAPON = 0x8,
		UNARMEDWEAPON = 0x10,
		ONEHANDMELEEWEAPON = 0x20,
		TWOHANDMELEEWEAPON = 0x40,
		POLEARMWEAPON = 0x80,
		PISTOLWEAPON = 0x100,
		CARBINEWEAPON = 0x200,
		RIFLEWEAPON = 0x400,
		GRENADEWEAPON = 0x800,
		LIGHTNINGRIFLEWEAPON = 0x1000,
		ONEHANDJEDIWEAPON = 0x2000,
		TWOHANDJEDIWEAPON = 0x4000,
		POLEARMJEDIWEAPON = 0x8000
	};


	SharedWeaponObjectTemplate();

	~SharedWeaponObjectTemplate();

	void readObject(LuaObject* templateData);
	void readObject(IffStream* iffStream);

	void parseVariableData(const String& varName, Chunk* data);
	void parseVariableData(const String& varName, LuaObject* templateData);

	void parseFileData(IffStream* iffStream);

	String getXpType() const;

	int getActionAttackCost() const;

	int getArea() const;

	int getArmorPiercing() const;

	float getAttackSpeed() const;

	float getForceCost() const;

	int getHealthAttackCost() const;

	int getIdealAccuracy() const;

	int getIdealRange() const;

	int getMaxDamage() const;

	int getMaxRange() const;

	int getMaxRangeAccuracy() const;

	int getMinDamage() const;

	int getMindAttackCost() const;

	int getPointBlankAccuracy() const;

	int getPointBlankRange() const;

	float getWoundsRatio() const;

	void setActionAttackCost(int actionAttackCost);

	void setArea(int area);

	void setArmorPiercing(int armorPiercing);

	void setAttackSpeed(float attackSpeed);

	void setForceCost(float forceCost);

	void setHealthAttackCost(int healthAttackCost);

	void setIdealAccuracy(int idealAccuracy);

	void setIdealRange(int idealRange);

	void setMaxDamage(int maxDamage);

	void setMaxRange(int maxRange);

	void setMaxRangeAccuracy(int maxRangeAccuracy);

	void setMinDamage(int minDamage);

	void setMindAttackCost(int mindAttackCost);

	void setPointBlankAccuracy(int pointBlankAccuracy);

	void setPointBlankRange(int pointBlankRange);

	void setWoundsRatio(float woundsRatio);

	const Vector<String>* getCertificationsRequired() const;

	const Vector<String>* getCreatureAccuracyModifiers() const;

	const Vector<String>* getCreatureAimModifiers() const;

	const Vector<String>* getDamageModifiers() const;

	int getDamageType() const;

	const Vector<String>* getDefenderDefenseModifiers() const;

	const Vector<String>* getDefenderSecondaryDefenseModifiers() const;

	const Vector<String>* getDefenderToughnessModifiers() const;

	const Vector<String>* getSpeedModifiers() const;

	void setCertificationsRequired(Vector<String> certificationsRequired);

	void setCreatureAccuracyModifiers(Vector<String> creatureAccuracyModifiers);

	void setCreatureAimModifiers(Vector<String> creatureAimModifiers);

	void setDamageModifiers(Vector<String> damageModifiers);

	void setDamageType(int damageType);

	void setDefenderDefenseModifiers(Vector<String> defenderDefenseModifiers);

	void setDefenderSecondaryDefenseModifiers(Vector<String> defenderSecondaryDefenseModifiers);

	void setDefenderToughnessModifiers(Vector<String> defenderToughnessModifiers);

	void setSpeedModifiers(Vector<String> speedModifiers);

	int getAttackType() const;

	const String& getWeaponEffect() const;

	int getWeaponEffectIndex() const;

	void setAttackType(int attackType);

	void setWeaponEffect(String weaponEffect);

	void setWeaponEffectIndex(int weaponEffectIndex);

	const String& getCombatSpam() const;

	const String& getAnimationType() const;

	uint32 getWeaponType() const;

	void setWeaponType(uint32 weaponType);
};

} // namespace tangible
} // namespace templates

using namespace templates::tangible;

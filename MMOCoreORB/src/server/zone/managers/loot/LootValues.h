#pragma once

#include "server/zone/objects/manufactureschematic/craftingvalues/CraftingValues.h"
#include "server/zone/objects/tangible/TangibleObject.h"
#include "server/zone/managers/loot/LootAttributeType.h"
#include "templates/LootItemTemplate.h"

#ifndef LOOTVALUES_DEBUG
	//#define LOOTVALUES_DEBUG
#endif // LOOTVALUES_DEBUG

class LootValues: public CraftingValues, public LootAttributeType {
public:
	constexpr static float EPSILON = 5e-7f;
	constexpr static float DISTMAX = 0.95f;
	constexpr static float DISTMIN = 0.15f;
	constexpr static float LEVELMAX = 350;
	constexpr static float LEVELMIN = 0;
	constexpr static float DISTNORMAL = 2.82333f;

	enum BonusType : int {
		LEGENDARY = 9,
		EXCEPTIONAL = 8,
		ENHANCED = 2,
		EXPERIMENTAL = 1,
		STATIC = 0,
	};

protected:
	AttributesMap staticValues;
	uint32 objectType;

	int dynamicValues;
	int modifier;
	int level;

public:
	LootValues(const LootItemTemplate* lootTemplate, int lootLevel, float lootModifier);

	uint32 getObjectType() const;

	int getDynamicValues() const;

	int getModifier() const;

	int getLevel() const;

	void setModifier(int lootModifier);

	void setLevel(int lootLevel);

	void setModifier(const LootItemTemplate* lootTemplate, float lootModifier);

	void setLevel(const LootItemTemplate* lootTemplate, int lootLevel);

	void recalculateValues(bool initial);

private:
	inline void setStaticValues();

	inline void setRandomValues();

	inline void setDamageValues();

	inline void setStaticValue(const String& attribute);

	template<typename Auto = float>
	inline void setUniformValue(const String& attribute);

	template<typename Auto = float>
	inline void setNormalValue(const String& attribute);

	template<typename Auto = float>
	inline void setDynamicValue(const String& attribute, float percentageMax);

	inline void setModifierValue(const String& attribute, float percentageMax);

public:
	static float getModifierValue(float min, float max, float percentageMax);

	static int getModifierValue(int min, int max, float percentageMax);

	static float getPercentageValue(float min, float max, float percentage);

	static int getPercentageValue(int min, int max, float percentage);

	static float getValuePercentage(float min, float max, float value);

	static float getRandomValue(float min, float max);

	static int getRandomValue(int min, int max);

	static float getNormalValue(float minValue, float maxValue);

	static int getNormalValue(int minValue, int maxValue);

	static float getDistributedValue(float min, float max, int level, float distMin = 0.f, float distMax = 1.f);

	static int getDistributedValue(int min, int max, int level, float distMin = 0.f, float distMax = 1.f);

	static float getLevelRankValue(int level, float distMin = 0.f, float distMax = 1.f);

#ifdef LOOTVALUES_DEBUG
	void debugAttributes(TangibleObject* prototype, const LootItemTemplate* itemTemplate);

	String toDebugString();
#endif // LOOTVALUES_DEBUG
};

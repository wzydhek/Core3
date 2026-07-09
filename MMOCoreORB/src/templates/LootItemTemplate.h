/*
 * LootItemTemplate.h
 *
 *  Created on: 18/12/2011
 *      Author: victor
 */

#pragma once

#include "templates/LuaTemplate.h"
#include "templates/crafting/AttributesMap.h"
#include "templates/manager/TemplateManager.h"
#include "templates/SharedTangibleObjectTemplate.h"
#include "server/zone/objects/scene/SceneObjectType.h"
#include "server/zone/managers/loot/LootAttributeType.h"

class LootItemTemplate: public LuaTemplate, public Logger {
protected:
	String templateName;
	String customObjectName;
	String directObjectTemplate;

	int junkDealerTypeNeeded;
	int junkMinValue;
	int junkMaxValue;

	AttributesMap attributesMap;
	bool suppressSerialNumber;

	Vector<String> customizationStringNames;
	Vector<Vector<int> > customizationValues;

	float randomDotChance;
	float staticDotChance;
	int staticDotType;

	int levelMax;
	int levelMin;

	uint32 objectType;

	bool isRandomResource;

	VectorMap<String, SortedVector<int> > staticDotValues;

	VectorMap<String, int> skillMods;

public:
	LootItemTemplate(const String& name);

	void readObject(LuaObject* templateData);

	const String& getTemplateName() const;

	const String& getDirectObjectTemplate() const;

	const String& getCustomObjectName() const;

	const Vector<String>* getCustomizationStringNames() const;

	const Vector<Vector<int>>* getCustomizationValues() const;

	bool getSuppressSerialNumber() const;

	AttributesMap getAttributesMapCopy() const;

	const VectorMap<String, int>* getSkillMods() const;

	float getRandomDotChance() const;

	float getStaticDotChance() const;

	int getStaticDotType() const;

	int getJunkDealerTypeNeeded() const;

	int getJunkMinValue() const;

	int getJunkMaxValue() const;

	int getLevelMax() const;

	int getLevelMin() const;

	bool isRandomResourceContainer() const;

	bool isShipComponent() const;

	uint32 getObjectType() const;

	const VectorMap<String, SortedVector<int>>* getStaticDotValues() const;
};

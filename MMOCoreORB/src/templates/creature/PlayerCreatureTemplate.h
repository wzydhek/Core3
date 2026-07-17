/*
 * PlayerCreatureTemplate.h
 *
 *  Created on: Feb 15, 2011
 *      Author: crush
 */

#pragma once

#include "templates/creature/SharedCreatureObjectTemplate.h"
#include "templates/customization/CustomizationDataMap.h"

namespace templates {
namespace creature {

class PlayerCreatureTemplate : public SharedCreatureObjectTemplate {
	CustomizationDataMap dataMap;
	Vector<String> startingSkills;
	Vector<String> startingItems;

protected:
	uint8 defaultLanguage;

public:
	PlayerCreatureTemplate();

	~PlayerCreatureTemplate();

	const CustomizationDataMap& getCustomizationDataMap() const;

	CustomizationDataMap& getCustomizationDataMap();

	const Vector<CustomizationData>& getCustomizationData(const String& customizationName) const;

	const Vector<String>& getStartingSkills() const;

	const Vector<String>& getStartingItems() const;

	uint8 getDefaultLanguage() const;

	void setCustomizationDataMap(const CustomizationDataMap& map);

	void parseVariableData(const String& varName, LuaObject* templateData);

	void readObject(LuaObject* templateData) override;

	bool isPlayerCreatureTemplate() const override;
};

} // namespace creature
} // namespace templates

using namespace templates::creature;

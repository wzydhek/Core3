/**
 * Droid Module Crafting Template
 * 11/10/2014
 */

#pragma once

#include "templates/SharedTangibleObjectTemplate.h"

class DroidCraftingModuleTemplate : public SharedTangibleObjectTemplate {

protected:
	int craftingType;
	String craftingStationTemplate;
	String attributeListString;

public:
	DroidCraftingModuleTemplate();

	~DroidCraftingModuleTemplate();

	void readObject(LuaObject* templateData);

	int getCraftingType();

	String& getCraftingStationTemplate();

	String& getAttributeListString();

	bool isDroidCraftingModuleTemplate();
};

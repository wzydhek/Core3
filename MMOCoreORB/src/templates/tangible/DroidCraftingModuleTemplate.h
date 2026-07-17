/**
 * Droid Module Crafting Template
 * 11/10/2014
 */

#pragma once

#include "templates/SharedTangibleObjectTemplate.h"

namespace templates {
namespace tangible {

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

} // namespace tangible
} // namespace templates

using namespace templates::tangible;
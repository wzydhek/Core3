/*
 * SharedResourceContainerObjectTemplate.h
 *
 *  Created on: 06/05/2010
 *      Author: kyle
 */

#pragma once

#include "templates/SharedTangibleObjectTemplate.h"

namespace templates {
namespace tangible {
namespace tool {

class CraftingStationTemplate : public SharedTangibleObjectTemplate {
private:
	int stationType;
	int complexityLevel;

public:
	CraftingStationTemplate();

	~CraftingStationTemplate();

	void readObject(LuaObject* templateData) override;

	int getStationType() const;

	int getComplexityLevel() const;

	bool isCraftingStationTemplate() const override;
};

} // namespace tool
} // namespace tangible
} // namespace templates

using namespace templates::tangible::tool;

/*
 * SharedResourceContainerObjectTemplate.h
 *
 *  Created on: 06/05/2010
 *      Author: kyle
 */

#pragma once

#include "templates/SharedTangibleObjectTemplate.h"

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

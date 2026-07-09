/*
 * SharedResourceContainerObjectTemplate.h
 *
 *  Created on: 06/05/2010
 *      Author: kyle
 */

#pragma once

#include "templates/SharedTangibleObjectTemplate.h"

class CraftingToolTemplate : public SharedTangibleObjectTemplate {
private:

	int toolType, complexityLevel, forceCritAssembly, forceCritExperiment;
	Vector<uint32> tabs;

public:
	CraftingToolTemplate();

	~CraftingToolTemplate();

	void readObject(LuaObject* templateData) override;

	int getToolType() const;

	int getComplexityLevel() const;

	int getForceCriticalAssembly() const;

	int getForceCriticalExperiment() const;

	const Vector<uint32>& getTabs() const;

};

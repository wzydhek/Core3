/*
 * LootSchematicTemplate.h
 *
 *  Created on: Dec 29, 2011
 *      Author: kyle
 */

#pragma once

#include "templates/SharedTangibleObjectTemplate.h"

class LootSchematicTemplate: public SharedTangibleObjectTemplate {
protected:

	String targetDraftSchematic;
	int targetUseCount;
	String requiredSkill;


public:
	LootSchematicTemplate();

	~LootSchematicTemplate();

	void readObject(LuaObject* templateData);

	const String& getTargetDraftSchematic();

	const String& getRequiredSkill();

	int getTargetUseCount();

};

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
	LootSchematicTemplate() {
		targetDraftSchematic = "";
		targetUseCount = 1;
		requiredSkill = "";
	}

	~LootSchematicTemplate() {

	}

	void readObject(LuaObject* templateData) {
		SharedTangibleObjectTemplate::readObject(templateData);

		targetDraftSchematic = templateData->getStringField("targetDraftSchematic");
		targetUseCount = templateData->getIntField("targetUseCount");
		requiredSkill = templateData->getStringField("requiredSkill");

	}

	const String& getTargetDraftSchematic() {
		return targetDraftSchematic;
	}

	const String& getRequiredSkill() {
		return requiredSkill;
	}

	int getTargetUseCount() {
		return targetUseCount;
	}

};

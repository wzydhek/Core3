/**
 * Droid Module Effects Template
 * 11/26/2014
 */

#pragma once

#include "templates/SharedTangibleObjectTemplate.h"

class DroidPersonalityModuleTemplate : public SharedTangibleObjectTemplate {

protected:
	String reactionName;
	String attrName;
	String convTemplate;
	String personalityStf;

public:
	DroidPersonalityModuleTemplate();

	~DroidPersonalityModuleTemplate();

	void readObject(LuaObject* templateData);

	String& getReactionName();

	String& getChipName();

	String& getConversationTemplate();

	String& getPersonalityStf();

	bool isDroidPersonalityModuleTemplate();
};

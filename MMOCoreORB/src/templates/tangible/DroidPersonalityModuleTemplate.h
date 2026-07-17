/**
 * Droid Module Effects Template
 * 11/26/2014
 */

#pragma once

#include "templates/SharedTangibleObjectTemplate.h"

namespace templates {
namespace tangible {

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

} // namespace tangible
} // namespace templates

using namespace templates::tangible;

/**
 * Droid Module Effects Template
 * 11/26/2014
 */

#pragma once

#include "templates/SharedTangibleObjectTemplate.h"

namespace templates {
namespace tangible {

class DroidEffectsModuleTemplate : public SharedTangibleObjectTemplate {

protected:
	String effectName;
	String animation;

public:
	DroidEffectsModuleTemplate();

	~DroidEffectsModuleTemplate();

	void readObject(LuaObject* templateData);

	String& getEffectName();

	String& getAnimation();

	bool isDroidEffectsModuleTemplate();
};

} // namespace tangible
} // namespace templates

using namespace templates::tangible;
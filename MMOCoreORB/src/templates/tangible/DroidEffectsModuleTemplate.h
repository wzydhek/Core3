/**
 * Droid Module Effects Template
 * 11/26/2014
 */

#pragma once

#include "templates/SharedTangibleObjectTemplate.h"

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

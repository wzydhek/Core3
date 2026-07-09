#include "DroidEffectsModuleTemplate.h"

DroidEffectsModuleTemplate::DroidEffectsModuleTemplate() {
}
DroidEffectsModuleTemplate::~DroidEffectsModuleTemplate() {
}

void DroidEffectsModuleTemplate::readObject(LuaObject* templateData) {
	SharedTangibleObjectTemplate::readObject(templateData);
	effectName = templateData->getStringField("effectName");
	animation = templateData->getStringField("animation");
}

String& DroidEffectsModuleTemplate::getEffectName() {
	return effectName;
}

String& DroidEffectsModuleTemplate::getAnimation() {
	return animation;
}

bool DroidEffectsModuleTemplate::isDroidEffectsModuleTemplate() {
	return true;
}
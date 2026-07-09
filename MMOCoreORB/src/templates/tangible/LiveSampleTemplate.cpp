#include "LiveSampleTemplate.h"

LiveSampleTemplate::LiveSampleTemplate() {
	animation = "";
}

LiveSampleTemplate::~LiveSampleTemplate() {
}

void LiveSampleTemplate::readObject(LuaObject* templateData) {
	SharedTangibleObjectTemplate::readObject(templateData);
	animation = templateData->getStringField("animation");
}

String LiveSampleTemplate::getAnimation() {
	return animation;
}
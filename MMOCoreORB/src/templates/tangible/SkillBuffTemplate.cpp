#include "SkillBuffTemplate.h"

SkillBuffTemplate::SkillBuffTemplate() : duration(0), buffCRC(0) {
}

SkillBuffTemplate::~SkillBuffTemplate() {
}

void SkillBuffTemplate::readObject(LuaObject* templateData) {
	SharedTangibleObjectTemplate::readObject(templateData);

	duration = templateData->getIntField("duration");

	modifiers.removeAll();
	LuaObject mods = templateData->getObjectField("modifiers");

	for (int i = 1; i <= mods.getTableSize(); i += 2) {
		String attribute = mods.getStringAt(i);
		float value = mods.getFloatAt(i + 1);

		modifiers.put(attribute, value);
	}
	mods.pop();

	buffName = templateData->getStringField("buffName");

	buffCRC = templateData->getIntField("buffCRC");
}

String& SkillBuffTemplate::getBuffName() {
	return buffName;
}

int SkillBuffTemplate::getDuration() const {
	return duration;
}

VectorMap<String, float>* SkillBuffTemplate::getModifiers() {
	return &modifiers;
}

bool SkillBuffTemplate::isSkillBuffTemplate() {
	return true;
}

unsigned int SkillBuffTemplate::getBuffCRC() {
	return buffCRC;
}
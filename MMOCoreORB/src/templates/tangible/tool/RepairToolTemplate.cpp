#include "RepairToolTemplate.h"

RepairToolTemplate::RepairToolTemplate() {
	mask = 0;
	boostSkill = "";
	boostSkillMod = "";
	stationType = 0;
}

RepairToolTemplate::~RepairToolTemplate() {
}

void RepairToolTemplate::readObject(LuaObject* templateData) {
	SharedTangibleObjectTemplate::readObject(templateData);
	mask = templateData->getIntField("canRepairType");
	boostSkill = templateData->getStringField("boostSkill");
	boostSkillMod = templateData->getStringField("boostSkillMod");
	stationType = templateData->getIntField("stationType");
}

uint32 RepairToolTemplate::getRepairType() const {
	return mask;
}

const String& RepairToolTemplate::getSkill() const {
	return boostSkill;
}

const String& RepairToolTemplate::getSkillMod() const {
	return boostSkillMod;
}

int RepairToolTemplate::getStationType() const {
	return stationType;
}

bool RepairToolTemplate::isRepairToolTemplate() const {
	return true;
}
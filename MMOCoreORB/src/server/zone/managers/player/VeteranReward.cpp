#include "VeteranReward.h"

VeteranReward::VeteranReward() {
	milestone = 0;
	oneTime = false;
	jtlReward = false;
}

VeteranReward::VeteranReward(const VeteranReward& obj) : Object() {
	templateFile = obj.templateFile;
	milestone = obj.milestone;
	oneTime = obj.oneTime;
	description = obj.description;
	jtlReward = obj.jtlReward;
}

VeteranReward& VeteranReward::operator=(const VeteranReward& obj) {
	if (this == &obj)
		return *this;

	templateFile = obj.templateFile;
	milestone = obj.milestone;
	oneTime = obj.oneTime;
	description = obj.description;
	jtlReward = obj.jtlReward;

	return *this;
}

void VeteranReward::parseFromLua(LuaObject* luaObject) {
	templateFile = luaObject->getStringField("templateFile");
	milestone = luaObject->getIntField("milestone");
	oneTime = luaObject->getBooleanField("oneTime");
	description = luaObject->getStringField("description");
	jtlReward = luaObject->getBooleanField("jtlReward");
}

void VeteranReward::setTemplateFile(const String& file) {
	templateFile = file;
}

void VeteranReward::setMilestone(unsigned int days) {
	milestone = days;
}

void VeteranReward::setOneTime(bool flag) {
	oneTime = flag;
}

void VeteranReward::setDescription(const String& desc) {
	description = desc;
}

void VeteranReward::setJtlReward(bool val) {
	jtlReward = val;
}

String& VeteranReward::getTemplateFile() {
	return templateFile;
}

unsigned int VeteranReward::getMilestone() {
	return milestone;
}

bool VeteranReward::isOneTime() {
	return oneTime;
}

String& VeteranReward::getDescription() {
	return description;
}

bool VeteranReward::isJtlReward() {
	return jtlReward;
}
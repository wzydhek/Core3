#include "SignTemplate.h"

SignTemplate::SignTemplate() : ChildObject() {
}

SignTemplate::SignTemplate(const SignTemplate& obj) : ChildObject(obj) {
	requiredSkill = obj.requiredSkill;
	suiItem = obj.suiItem;
}

SignTemplate& SignTemplate::operator=(const SignTemplate& obj) {
	if (this == &obj)
		return *this;

	position = obj.position;
	direction = obj.direction;
	templateFile = obj.templateFile;
	cellid = obj.cellid;
	containmentType = obj.containmentType;
	requiredSkill = obj.requiredSkill;
	suiItem = obj.suiItem;

	return *this;
}

void SignTemplate::parseFromLua(LuaObject* luaObject) {
	ChildObject::parseFromLua(luaObject);
	requiredSkill = luaObject->getStringField("requiredSkill");
	suiItem = luaObject->getStringField("suiItem");
}

const String& SignTemplate::getSuiItem() const {
	return suiItem;
}

const String& SignTemplate::getRequiredSkill() const {
	return requiredSkill;
}
#include "ChildObject.h"

ChildObject::ChildObject() {
	cellid = 0;
	containmentType = 0;
	componentSlot = -2;
}

ChildObject::ChildObject(const Vector3 pos, const Quaternion& dir, const String& templateF, int cellID, int contType, int shipCompSlot) {
	position = pos;
	direction = dir;
	templateFile = templateF;
	cellid = cellID;
	containmentType = contType;
	componentSlot = shipCompSlot;
}

ChildObject::ChildObject(const ChildObject& obj) : Object() {
	position = obj.position;
	direction = obj.direction;
	templateFile = obj.templateFile;
	cellid = obj.cellid;
	containmentType = obj.containmentType;
	componentSlot = obj.componentSlot;
}

ChildObject& ChildObject::operator=(const ChildObject& obj) {
	if (this == &obj) {
		return *this;
	}

	position = obj.position;
	direction = obj.direction;
	templateFile = obj.templateFile;
	cellid = obj.cellid;
	containmentType = obj.containmentType;
	componentSlot = obj.componentSlot;

	return *this;
}

void ChildObject::parseFromLua(LuaObject* luaObject) {
	templateFile = luaObject->getStringField("templateFile");
	position.setX(luaObject->getFloatField("x"));
	position.setZ(luaObject->getFloatField("z"));
	position.setY(luaObject->getFloatField("y"));

	direction.set(luaObject->getFloatField("ow"), luaObject->getFloatField("ox"), luaObject->getFloatField("oy"), luaObject->getFloatField("oz"));

	cellid = luaObject->getIntField("cellid");

	containmentType = luaObject->getIntField("containmentType");

	componentSlot = (int)luaObject->getFloatField("componentSlot", -2.f);
}

void ChildObject::setPosition(float x, float z, float y) {
	position.set(x, z, y);
}

void ChildObject::setDirection(float fw, float fx, float fy, float fz) {
	direction.set(fw, fx, fy, fz);
}

void ChildObject::setCellId(int id) {
	cellid = id;
}

void ChildObject::setContainmentType(int containment) {
	containmentType = containment;
}

void ChildObject::setTemplateFile(const String& file) {
	templateFile = file;
}

const Vector3& ChildObject::getPosition() const {
	return position;
}

const Quaternion& ChildObject::getDirection() const {
	return direction;
}

const String& ChildObject::getTemplateFile() const {
	return templateFile;
}

int ChildObject::getCellId() const {
	return cellid;
}

int ChildObject::getContainmentType() const {
	return containmentType;
}

int ChildObject::getComponentSlot() const {
	return componentSlot;
}
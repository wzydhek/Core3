#include "MobileOutfit.h"

OutfitTangibleObject::OutfitTangibleObject() {
}

OutfitTangibleObject::OutfitTangibleObject(const OutfitTangibleObject& o) : Object() {
	objectTemplate = o.objectTemplate;
	customizationVariables = o.customizationVariables;
}

OutfitTangibleObject& OutfitTangibleObject::operator=(const OutfitTangibleObject& o) {
	if (this == &o)
		return *this;

	objectTemplate = o.objectTemplate;
	customizationVariables = o.customizationVariables;

	return *this;
}

void OutfitTangibleObject::readObject(LuaObject* luaObject) {
	objectTemplate = luaObject->getStringField("objectTemplate");

	LuaObject table = luaObject->getObjectField("customizationVariables");

	for (int i = 1; i <= table.getTableSize(); ++i) {
		LuaObject var = table.getObjectAt(i);

		String name = var.getStringAt(1);
		uint8 val = var.getIntAt(2);

		customizationVariables.put(name, val);

		var.pop();
	}

	table.pop();
}

String OutfitTangibleObject::getObjectTemplate() {
	return objectTemplate;
}

VectorMap<String, uint8>* OutfitTangibleObject::getCustomizationVariables() {
	return &customizationVariables;
}

MobileOutfit::MobileOutfit() {
}

MobileOutfit::MobileOutfit(const MobileOutfit& o) : Object() {
	objects = o.objects;
}

MobileOutfit& MobileOutfit::operator=(const MobileOutfit& o) {
	if (this == &o)
		return *this;

	objects = o.objects;

	return *this;
}

void MobileOutfit::readObject(LuaObject* luaObject) {
	for (int i = 1; i <= luaObject->getTableSize(); ++i) {
		LuaObject obj = luaObject->getObjectAt(i);

		OutfitTangibleObject outfit;
		outfit.readObject(&obj);

		objects.add(outfit);

		obj.pop();
	}
}

Vector<OutfitTangibleObject>* MobileOutfit::getObjects() {
	return &objects;
}
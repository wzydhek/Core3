#include "CitySpecialization.h"

CitySpecialization::CitySpecialization() {
	cost = 0;
	skillMods.setNoDuplicateInsertPlan();
	skillMods.setNullValue(0);
}

CitySpecialization::CitySpecialization(const String& name, int cost) {
	this->name = name;
	this->cost = cost;
}

CitySpecialization::CitySpecialization(const CitySpecialization& spec) : Object() {
	name = spec.name;
	cost = spec.cost;
	skillMods = spec.skillMods;
}

CitySpecialization& CitySpecialization::operator=(const CitySpecialization& spec) {
	if (this == &spec)
		return *this;

	name = spec.name;
	cost = spec.cost;
	skillMods = spec.skillMods;

	return *this;
}

void CitySpecialization::readObject(LuaObject* luaObject) {
	name = luaObject->getStringField("name");
	cost = luaObject->getIntField("cost");

	LuaObject smods = luaObject->getObjectField("skillMods");

	for (int i = 1; i <= smods.getTableSize(); ++i) {
		LuaObject mod = smods.getObjectAt(i);

		if (mod.isValidTable()) {
			String k = mod.getStringAt(1);
			int v = mod.getIntAt(2);

			skillMods.put(k, v);
		}

		mod.pop();
	}

	smods.pop();
}

const String& CitySpecialization::getName() const {
	return name;
}

int CitySpecialization::getCost() const {
	return cost;
}

const VectorMap<String, int>* CitySpecialization::getSkillMods() const {
	return &skillMods;
}
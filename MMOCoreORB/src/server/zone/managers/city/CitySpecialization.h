/*
 * CitySpecialization.h
 *
 *  Created on: Jul 20, 2012
 *      Author: swgemu
 */

#pragma once

#include "engine/lua/LuaObject.h"

namespace server {
namespace zone {
namespace managers {
namespace city {

class CitySpecialization : public Object {
	String name;
	int cost;
	VectorMap<String, int> skillMods;

public:
	CitySpecialization();

	CitySpecialization(const String& name, int cost);

	CitySpecialization(const CitySpecialization& spec);

	CitySpecialization& operator=(const CitySpecialization& spec);

	void readObject(LuaObject* luaObject);

	const String& getName() const;

	int getCost() const;

	const VectorMap<String, int>* getSkillMods() const;
};

} // namespace city
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::city;

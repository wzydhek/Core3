/*
 * CitySpecializationMap.h
 *
 *  Created on: Jul 20, 2012
 *      Author: swgemu
 */

#pragma once

#include "CitySpecialization.h"

namespace server {
namespace zone {
namespace managers {
namespace city {

class CitySpecializationMap : public HashTable<String, CitySpecialization> {
public:
	void readObject(LuaObject* luaObject);
};

} // namespace city
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::city;

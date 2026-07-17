/*
 * CityTaxMap.h
 *
 *  Created on: Jul 25, 2012
 *      Author: swgemu
 */

#pragma once

#include "CityTax.h"

namespace server {
namespace zone {
namespace managers {
namespace city {

class CityTaxMap : public Vector<CityTax> {
public:
	void readObject(LuaObject* luaObject);
};

} // namespace city
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::city;

/*
 * CityTaxMap.h
 *
 *  Created on: Jul 25, 2012
 *      Author: swgemu
 */

#pragma once

#include "CityTax.h"

class CityTaxMap : public Vector<CityTax> {
public:
	void readObject(LuaObject* luaObject);
};

/*
 * CitySpecializationMap.h
 *
 *  Created on: Jul 20, 2012
 *      Author: swgemu
 */

#pragma once

#include "CitySpecialization.h"

class CitySpecializationMap : public HashTable<String, CitySpecialization> {
public:
	void readObject(LuaObject* luaObject);
};

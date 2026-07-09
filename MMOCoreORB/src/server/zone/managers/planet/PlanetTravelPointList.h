/*
 * PlanetTravelPointList.h
 *
 *  Created on: May 13, 2011
 *      Author: crush
 */

#pragma once

#include "PlanetTravelPoint.h"

class PlanetTravelPointList : public VectorMap<String, Reference<PlanetTravelPoint*> >, public ReadWriteLock {
	String zoneName;
public:

	PlanetTravelPointList();

	Reference<PlanetTravelPoint*> get(int index);

	Reference<PlanetTravelPoint*> get(const String& name);

	void insertToMessage(BaseMessage* message, PlanetTravelPoint* origin);

	void readLuaObject(LuaObject* luaObject);

	void setZoneName(const String& name);

	void addPlayerCityTravelPoint(PlanetTravelPoint* planetTravelPoint);

	void removePlayerCityTravelPoint(const String& pointName);
};

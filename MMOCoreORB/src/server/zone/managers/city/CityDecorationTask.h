/*
 * CityDecorationTask.h
 *
 *  Created on: Aug 26, 2013
 *      Author: root
 */

#pragma once

#include "server/zone/objects/region/CityRegion.h"
#include "server/zone/managers/planet/PlanetManager.h"
#include "server/zone/objects/scene/SceneObject.h"
#include "server/zone/objects/player/PlayerObject.h"

class CityDecorationTask : public Task {
	ManagedReference<CreatureObject*> mayor;
	ManagedReference<TangibleObject*> obj;
	byte option;

public:
	enum {
		PLACE = 0,
		REMOVE = 1
	};

	CityDecorationTask(CreatureObject* creature, TangibleObject* object, byte function);

	void run();

	void placeDecoration();

	void removeDecoration();

};

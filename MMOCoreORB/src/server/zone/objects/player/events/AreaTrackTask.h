/*
 				Copyright <SWGEmu>
		See file COPYING for copying conditions. */

/**
 * AreaTrackTask.h
 *
 *  Created: Sat Feb 5
 *   Author: Kyle
 *
 */

#pragma once

#include "engine/engine.h"
#include "server/zone/objects/creature/CreatureObject.h"

class AreaTrackTask: public Task {
	ManagedReference<CreatureObject*> player;
	int type;
	Coordinate initialPosition;

public:
	AreaTrackTask(CreatureObject* cr, int index);

	void run();

	String getDirection(CreatureObject* tracker, CreatureObject* trackee);

	String getDistance(CreatureObject* tracker, CreatureObject* trackee);
};

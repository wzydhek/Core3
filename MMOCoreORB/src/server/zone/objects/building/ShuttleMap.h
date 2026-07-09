/*
 * ShuttleMap.h
 *
 *  Created on: Aug 19, 2011
 *      Author: crush
 */

#pragma once

#include "server/zone/objects/building/tasks/ShuttleDepartureTask.h"
#include "engine/engine.h"

class ShuttleMap : public VectorMap<uint64, Reference<ShuttleDepartureTask*> > {
public:
	ShuttleMap();
};

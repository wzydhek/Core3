/*
 * CityStructureInventory.h
 *
 *  Created on: 17/04/2012
 *      Author: victor
 */

#pragma once

#include "engine/engine.h"

class CityStructureInventory : public VectorMap<byte, SortedVector<ManagedReference<SceneObject* > > > {

};

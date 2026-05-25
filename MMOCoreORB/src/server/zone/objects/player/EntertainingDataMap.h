/*
 * EntertainingDataMap.h
 *
 *  Created on: 22/09/2010
 *      Author: victor
 */

#pragma once

#include "engine/engine.h"
#include "EntertainingData.h"

class EntertainingDataMap : public VectorMap<ManagedReference<CreatureObject*>, EntertainingData > {

};

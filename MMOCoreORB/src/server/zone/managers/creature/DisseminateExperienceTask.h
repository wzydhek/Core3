/*
 * DisseminateExperienceTask.h
 *
 *  Created on: Oct 27, 2013
 *      Author: swgemu
 */

#pragma once

#include "server/zone/managers/player/PlayerManager.h"
#include "server/zone/objects/tangible/TangibleObject.h"
#include "system/util/SynchronizedVector.h"

namespace server {
namespace zone {
namespace managers {
namespace creature {

class DisseminateExperienceTask : public Task {
	ManagedWeakReference<TangibleObject*> lair;

	ThreatMap copyThreatMap;

	SynchronizedVector<ManagedReference<CreatureObject*> > spawnedCreatures;

	Zone* lairZone;

public:

	DisseminateExperienceTask(TangibleObject* obj, ThreatMap* threatMap, SynchronizedVector<ManagedReference<CreatureObject*>>* creatures, Zone* lairZone);

	void run();
};

} // namespace creature
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::creature;

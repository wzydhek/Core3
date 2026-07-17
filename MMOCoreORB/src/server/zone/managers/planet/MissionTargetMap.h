/*
 * MissionTargetMap.h
 *
 *  Created on: Aug 22, 2010
 *      Author: dannuic
 */

#pragma once

#include "server/zone/Zone.h"
#include "server/zone/objects/scene/SceneObject.h"

namespace server {
namespace zone {
namespace managers {
namespace planet {

class MissionTargetMap : public Object {
	SynchronizedSortedVector<Reference<SceneObject*> > missions;

public:
	MissionTargetMap();

	/*int put(SceneObject* mission) {
		return missions.put(mission);
	}*/

	bool add(SceneObject* mission);

	bool remove(SceneObject* mission);

	int size();

	SceneObject* getRandomTarget(SceneObject* origin, int diff);
};

} // namespace planet
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::planet;

/*
 * NAVMESHJOB.h
 *
 *  Created on: 10/01/2016
 *      Author: gslomin
 */

#pragma once

#include "server/zone/objects/pathfinding/NavArea.h"
#include "engine/util/u3d/AABB.h"

namespace server {
namespace zone {
namespace managers {
namespace collision {

class NavMeshJob : public Object {
protected:
	WeakReference<NavArea*> area;
	Vector<AABB> areas;
	RecastSettings settings;
	String queue;
	AtomicBoolean running;
	Mutex mutex;

public:
	NavMeshJob(NavArea* area, const RecastSettings& config, const String& targetQueue);

	Vector<AABB>& getAreas();

	const Vector<AABB>& getAreas() const;

	Reference<NavArea*> getNavArea();

	RecastSettings& getRecastConfig();

	const RecastSettings& getRecastConfig() const;

	Mutex* getMutex();

	const String& getQueue() const;

	void cancel();

	const AtomicBoolean* getJobStatus();

	void addArea(const AABB& area);

};

} // namespace collision
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::collision;

#include "NavMeshJob.h"
#include "NavMeshManager.h"

NavMeshJob::NavMeshJob(NavArea* area, const RecastSettings& config, const String& targetQueue) : queue(targetQueue), running(true) {
	this->area = area;
	settings = config;
}

Vector<AABB>& NavMeshJob::getAreas() {
	return areas;
}

const Vector<AABB>& NavMeshJob::getAreas() const {
	return areas;
}

Reference<NavArea*> NavMeshJob::getNavArea() {
	return area.get();
}

RecastSettings& NavMeshJob::getRecastConfig() {
	return settings;
}

const RecastSettings& NavMeshJob::getRecastConfig() const {
	return settings;
}

Mutex* NavMeshJob::getMutex() {
	return &mutex;
}

const String& NavMeshJob::getQueue() const {
	return queue;
}

void NavMeshJob::cancel() {
	running.set(false);
}

const AtomicBoolean* NavMeshJob::getJobStatus() {
	return &running;
}

void NavMeshJob::addArea(const AABB& area) {
    float size = area.extents().getX() * area.extents().getZ();

    Locker locker(&mutex);

    if(areas.size() > 0) {
        for (int i = areas.size() - 1; i >= 0; i--) {
            const AABB& existing = areas.get(i);
            float existingSize = existing.extents().getX() * existing.extents().getZ();

            if (existingSize > size) {
                // check to see if an existing AABB completely encompasses the one we are adding
                if(NavMeshManager::AABBEncompasessAABB(existing, area))
                    return;
            } else if(NavMeshManager::AABBEncompasessAABB(area, existing)) {
                // Check to see if the AABB we are adding encompasses one already in the list
                areas.remove(i);
                continue;
            }
        }
    }

    areas.add(area);
}

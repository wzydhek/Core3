#pragma once

#include "server/zone/objects/scene/SceneObject.h"

namespace server {
	namespace zone {
		namespace objects {
			namespace ship {
				class ShipObject;

class ShipTargetVector : public Object, public Logger {
public:
	const static int UPDATE_INTERVAL = 2000;
	const static int TARGETVECTORMAX = 32;

	const static int TARGET_DISTANCE_MAX = 2048;
	const static int TARGET_DISTANCE_SQR = TARGET_DISTANCE_MAX * TARGET_DISTANCE_MAX;

protected:
	VectorMap<float, ManagedWeakReference<SceneObject*>> targetMap;
	uint64 serverTime;

	mutable ReadWriteLock targetLock;

public:
	ShipTargetVector(ShipObject* ship);

	void update(ShipObject* ship);

	void safeCopyTo(Vector<ManagedReference<SceneObject*>>& vector) const;

	void safeCopyTo(Vector<ManagedReference<ShipObject*>>& vector) const;

	int size() const;

private:
	float getTargetDistanceSqr(ShipObject* ship, SceneObject* target) const;

	bool isTargetValid(ShipObject* ship, SceneObject* target) const;

	bool isScheduled() const;

	void setServerTime();

	bool isCollidableType(uint32 objectType) const;

	String toDebugString() const;
};

} // namespace ship
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::ship;

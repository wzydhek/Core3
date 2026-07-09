#pragma once

#include "engine/engine.h"
#include "server/zone/objects/ship/ShipObject.h"

class ShipUniqueIdMap : public Object, public Logger {
private:
	const static int INDEXMAX = std::numeric_limits<uint16>::max();
	const static int INDEXMIN = 1;

protected:
	VectorMap<uint16, ManagedWeakReference<ShipObject*>> shipIdMap;
	mutable ReadWriteLock mutex;
	int index;

public:
	ShipUniqueIdMap();

	uint16 getUniqueID();

	uint16 setUniqueID(ShipObject* ship);

	void dropUniqueID(ShipObject* ship);

	void safeCopyTo(Vector<ManagedWeakReference<ShipObject*>>& vector) const;

	int size() const;
};

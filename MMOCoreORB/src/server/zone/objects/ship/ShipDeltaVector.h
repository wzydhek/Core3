#pragma once

#include "server/zone/packets/DeltaMessage.h"
#include "server/zone/objects/tangible/TangibleObject.h"

namespace server {
namespace zone {
namespace objects {
namespace ship {
class ShipObject;
}
} // namespace objects
} // namespace zone
} // namespace server

class ShipDeltaVector : public Object {
protected:
	VectorMap<uint32, DeltaMessage*> deltaVector;

	uint64 objectID;
	uint64 playerID;

	mutable ReadWriteLock deltaMutex;

	enum DeltaTypeID : uint32 {
		None = 0,
		Delta1 = 1,
		Delta3 = 3,
		Delta4 = 4,
		Delta6 = 6,
	};

	enum DeltaType : uint32 {
		Private = 1,
		Public = 2,
	};

	int getDeltaType(uint32 deltaID);

public:
	ShipDeltaVector(SceneObject* ship, SceneObject* player = nullptr);

	~ShipDeltaVector();

	void sendMessages(ShipObject* ship);

	void reset(SceneObject* player = nullptr);

	DeltaMessage* getMessage(uint32 deltaID);

	int size();
};

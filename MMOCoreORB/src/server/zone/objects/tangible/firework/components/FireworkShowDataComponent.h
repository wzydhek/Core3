#pragma once

#include "server/zone/objects/scene/components/DataObjectComponent.h"
#include "server/zone/objects/tangible/firework/FireworkObject.h"
#include "engine/engine.h"
#include "system/util/VectorMap.h"

namespace server {
namespace zone {
namespace objects {
namespace tangible {
namespace firework {
namespace components {

class FireworkShowDataComponent : public DataObjectComponent {

private:
	VectorMap<ManagedReference<FireworkObject*>, int> fireworkList;

public:
	FireworkShowDataComponent();

	virtual ~FireworkShowDataComponent();

	void writeJSON(nlohmann::json& j) const;

	bool toBinaryStream(ObjectOutputStream* stream);

	int writeObjectMembers(ObjectOutputStream* stream);

	bool readObjectMember(ObjectInputStream* stream, const String& name);

	bool parseFromBinaryStream(ObjectInputStream* stream);

	bool isFireworkShowData();

	int getTotalFireworkCount();

	int getIndexOfFirework(FireworkObject* firework);

	FireworkObject* getFirework(int index);

	int getFireworkDelay(int index);

	void setFireworkDelay(int index, int delay);

	void addFirework(int index, FireworkObject* firework, int delay);

	void removeFirework(int index);

	void swapFireworkPositions(int index, int index2);
};

} // namespace components
} // namespace firework
} // namespace tangible
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::tangible::firework::components;

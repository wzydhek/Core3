
#pragma once

#include "server/zone/objects/scene/components/DataObjectComponent.h"
#include "server/zone/objects/tangible/deed/eventperk/EventPerkDeed.h"
#include "server/zone/objects/creature/CreatureObject.h"

namespace server {
namespace zone {
namespace objects {
namespace tangible {
namespace components {

class EventPerkDataComponent : public DataObjectComponent {
protected:
	ManagedReference<EventPerkDeed*> deed;
	ManagedReference<CreatureObject*> actor;

public:
	EventPerkDataComponent();

	virtual ~EventPerkDataComponent();

	void writeJSON(nlohmann::json& j) const;

	bool toBinaryStream(ObjectOutputStream* stream);

	int writeObjectMembers(ObjectOutputStream* stream);

	bool readObjectMember(ObjectInputStream* stream, const String& name);

	bool parseFromBinaryStream(ObjectInputStream* stream);

	void setDeed(EventPerkDeed* de);

	void setActor(CreatureObject* npcActor);

	EventPerkDeed* getDeed();

	CreatureObject* getActor();

	bool isEventPerkData();
};

} // namespace components
} // namespace tangible
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::tangible::components;


#pragma once

#include "server/zone/objects/structure/StructureObject.h"

namespace server {
namespace zone {
namespace objects {
namespace structure {
namespace events {

class StructureSetOwnerTask : public Task {
	ManagedReference<StructureObject*> structure;
	uint64 newOwnerID;

public:
	StructureSetOwnerTask(StructureObject* structureObject, uint64 newID);

	void run();
};

} // namespace events
} // namespace structure
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::structure::events;

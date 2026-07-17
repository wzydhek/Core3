#pragma once

#include "engine/engine.h"
#include "server/zone/objects/intangible/PetControlDevice.h"

namespace server {
namespace zone {
namespace objects {
namespace intangible {
namespace tasks {

class PetControlDeviceStoreTask : public Task {
	ManagedWeakReference<PetControlDevice*> device;
	ManagedWeakReference<CreatureObject*> playerCreo;
	bool force;

public:
	PetControlDeviceStoreTask(PetControlDevice* device, CreatureObject* playerCreo, bool force);

	void run();
};

} // namespace tasks
} // namespace intangible
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::intangible::tasks;

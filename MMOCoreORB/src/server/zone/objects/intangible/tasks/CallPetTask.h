
#pragma once

#include "server/zone/objects/creature/CreatureObject.h"
#include "server/zone/objects/intangible/ControlDevice.h"
#include "server/zone/objects/intangible/PetControlDevice.h"

namespace server {
namespace zone {
namespace objects {
namespace intangible {
namespace tasks {

class CallPetTask : public Task {
	ManagedReference<CreatureObject*> player;
	ManagedReference<PetControlDevice*> device;
	String taskName;

public:
	CallPetTask(PetControlDevice* controlDevice, CreatureObject* creo, const String& task);

	void run();
};

} // namespace tasks
} // namespace intangible
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::intangible::tasks;

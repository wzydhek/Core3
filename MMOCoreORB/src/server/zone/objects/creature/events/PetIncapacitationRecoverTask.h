
#pragma once

#include "templates/params/creature/CreatureAttribute.h"
#include "server/zone/objects/creature/ai/AiAgent.h"
#include "server/zone/objects/intangible/PetControlDevice.h"
#include "server/zone/objects/intangible/tasks/PetControlDeviceStoreTask.h"

namespace server {
namespace zone {
namespace objects {
namespace creature {
namespace events {

class PetIncapacitationRecoverTask : public Task {
	ManagedReference<AiAgent*> pet;
	bool autostore;

public:
	PetIncapacitationRecoverTask(AiAgent* pl, bool store);

	~PetIncapacitationRecoverTask();

	void run();
};

} // namespace events
} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature::events;

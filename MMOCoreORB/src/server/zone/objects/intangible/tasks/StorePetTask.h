/*
 * StorePetTask.h
 *
 *  Created on: Dec 11, 2013
 *      Author: TheAnswer
 */

#pragma once

#include "engine/engine.h"

namespace server {
namespace zone {
namespace objects {
namespace creature {
namespace ai {
class AiAgent;
}

class CreatureObject;
} // namespace creature

} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature;
using namespace server::zone::objects::creature::ai;

namespace server {
namespace zone {
namespace objects {
namespace intangible {
namespace tasks {

class StorePetTask : public Task {
	WeakReference<CreatureObject*> play;
	WeakReference<AiAgent*> pt;

public:
	StorePetTask(CreatureObject* player, AiAgent* pet);

	void run();
};

} // namespace tasks
} // namespace intangible
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::intangible::tasks;

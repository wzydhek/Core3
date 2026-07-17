/*
 * InjuryTreatmentTask.h
 *
 *  Created on: 09/08/2010
 *      Author: victor
 */

#pragma once

#include "server/zone/objects/creature/CreatureObject.h"

namespace server {
namespace zone {
namespace objects {
namespace creature {
namespace events {

class InjuryTreatmentTask : public Task {
	ManagedReference<CreatureObject*> creature;
	StringIdChatParameter message;
	String pendingTask;

public:
	InjuryTreatmentTask(CreatureObject* creo, const StringIdChatParameter& msg, const String& task);

	void run();
};

} // namespace events
} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature::events;

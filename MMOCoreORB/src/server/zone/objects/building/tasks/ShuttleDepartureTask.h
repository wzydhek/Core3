/*
 * ShuttleDepartureTask.h
 *
 *  Created on: Aug 19, 2011
 *      Author: crush
 */

#pragma once

#include "server/zone/objects/creature/CreatureObject.h"
#include "engine/engine.h"

//#define SHUTTLE_TIMER_DEBUG

namespace server {
namespace zone {
namespace objects {
namespace building {
namespace tasks {

class ShuttleDepartureTask : public Task, public Logger {
	ManagedWeakReference<CreatureObject*> shuttleObject;

protected:
	int landedTime; //In seconds
	int landingTime; //How long the landing animation takes to complete in seconds.
	int departedTime; //In seconds
	int shuttleType; // Type of Shuttle

public:
	ShuttleDepartureTask(CreatureObject* shuttle);

	void run();

	int getSecondsRemaining();

	bool isLanded();

	bool isLanding();

	int getLandingTime();

	int getLandedTime();

	int getDepartedTime();

	int getShuttleType();

	void setLandingTime(int landing);

	void setLandedTime(int landed);

	void setDepartedTime(int departed);

	void setShuttleType(int type);
};

} // namespace tasks
} // namespace building
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::building::tasks;

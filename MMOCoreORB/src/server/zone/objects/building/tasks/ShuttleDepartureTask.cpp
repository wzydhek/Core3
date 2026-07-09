#include "ShuttleDepartureTask.h"
#include "server/zone/ZoneServer.h"

ShuttleDepartureTask::ShuttleDepartureTask(CreatureObject* shuttle) : Task() {
	shuttleObject = shuttle;
	departedTime = 300;
	landingTime = 11;
	landedTime = 120;
	shuttleType = 0;

	Logger::setLoggingName("ShuttleDepartureTask");
}

void ShuttleDepartureTask::run() {
	ManagedReference<CreatureObject*> strongReference = shuttleObject.get();

	if (strongReference == nullptr) {
		error() << " run() - shuttle strongReference has a nullptr.";
		return;
	}

	ZoneServer* zoneServer = strongReference->getZoneServer();

	if (zoneServer != nullptr && zoneServer->isServerShuttingDown()) {
		cancel();
		return;
	}

	Locker _lock(strongReference);

	if (strongReference->isStanding()) {
		strongReference->setPosture(CreaturePosture::PRONE);
		reschedule(getDepartedTime() * 1000);
	} else {
		strongReference->setPosture(CreaturePosture::UPRIGHT);
		reschedule(getLandedTime() * 1000);
	}
}

int ShuttleDepartureTask::getSecondsRemaining() {
	int seconds = (int)(getNextExecutionTime().miliDifference() / 1000.f * -1) + 1;

	return seconds;
}

bool ShuttleDepartureTask::isLanded() {
	ManagedReference<CreatureObject*> strongReference = shuttleObject.get();

	if (strongReference == nullptr) {
		error() << " isLanded - shuttle strongReference has a nullptr.";
		return false;
	}

	if (!strongReference->isStanding())
		return false;

	int landedCalc = landedTime - getSecondsRemaining();

#ifdef SHUTTLE_TIMER_DEBUG
	info(true) << " isLanded - landing time = " << landingTime << " landed calc = " << landedCalc;
#endif

	// Make sure the shuttle isn't still landing
	if (landingTime >= landedCalc)
		return false;

	return true;
}

bool ShuttleDepartureTask::isLanding() {
	ManagedReference<CreatureObject*> strongReference = shuttleObject.get();

	if (strongReference == nullptr) {
		error() << "ShuttleDepartureTask::isLanding - shuttle strongReference has a nullptr.";
		return false;
	}

	int landedCalc = landedTime - getSecondsRemaining();

#ifdef SHUTTLE_TIMER_DEBUG
	info(true) << " isLanded - landing time = " << landingTime << " landed calc = " << landedCalc;
#endif

	if (strongReference->isStanding() && landedCalc <= landingTime)
		return true;

	return false;
}

int ShuttleDepartureTask::getLandingTime() {
	return landingTime;
}

int ShuttleDepartureTask::getLandedTime() {
	// Landed Time is 120s for all shuttle
	// Shuttleports = 11s	Startports = 14s
	int timeLanded = landedTime + landingTime;

#ifdef SHUTTLE_TIMER_DEBUG
	info(true) << " Shuttle Type = " << getShuttleType() << " Setting time landed to " << timeLanded << " seconds.";
#endif

	return timeLanded;
}

int ShuttleDepartureTask::getDepartedTime() {
	// Startport departedTime is 60s and shuttleport departedTime is 300s

#ifdef SHUTTLE_TIMER_DEBUG
	info(true) << " Shuttle Type = " << getShuttleType() << " Setting departed time to " << departedTime << " seconds.";
#endif

	return departedTime;
}

int ShuttleDepartureTask::getShuttleType() {
	return shuttleType;
}

void ShuttleDepartureTask::setLandingTime(int landing) {
	landingTime = landing;
}

void ShuttleDepartureTask::setLandedTime(int landed) {
	landedTime = landed;
}

void ShuttleDepartureTask::setDepartedTime(int departed) {
	departedTime = departed;
}

void ShuttleDepartureTask::setShuttleType(int type) {
	shuttleType = type;
}
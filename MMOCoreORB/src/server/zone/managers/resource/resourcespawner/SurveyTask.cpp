#include "SurveyTask.h"

SurveyTask::SurveyTask(ManagedReference<CreatureObject*> play, SurveyMessage* surveyM, ManagedReference<WaypointObject*> way, float density, ManagedReference<ResourceSpawn*> resourceSpawn) {
	playerCreature = play;
	surveyMessage = surveyM;
	waypoint = way;
	this->density = density;
	this->resourceSpawn = resourceSpawn;
}

void SurveyTask::run() {
	Locker playerLocker(playerCreature);

	// Send Survey Results
	playerCreature->sendMessage(surveyMessage);

	if (waypoint != nullptr) {
		playerCreature->getPlayerObject()->addWaypoint(waypoint, false, true);

		// Send Waypoint System Message
		playerCreature->sendSystemMessage("@survey:survey_waypoint");

		// Notify any survey mission observers.
		playerCreature->notifyObservers(ObserverEventType::SURVEY, resourceSpawn, density);
	}

	playerCreature->removePendingTask("survey");
}
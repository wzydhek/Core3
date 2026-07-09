#include "SetWaypointActiveStatusCommand.h"
#include "server/zone/ZoneServer.h"
#include "server/zone/objects/player/PlayerObject.h"
#include "server/zone/objects/scene/SceneObject.h"

SetWaypointActiveStatusCommand::SetWaypointActiveStatusCommand(const String& name, ZoneProcessServer* server) : QueueCommand(name, server) {
}

int SetWaypointActiveStatusCommand::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	ManagedReference<SceneObject*> wp = server->getZoneServer()->getObject(target);

	if (wp == nullptr || !wp->isWaypointObject())
		return INVALIDPARAMETERS;

	PlayerObject* ghost = creature->getPlayerObject();

	if (ghost == nullptr)
		return GENERALERROR;

	WaypointObject* waypoint = cast<WaypointObject*>(wp.get());

	if (!ghost->hasWaypoint(waypoint->getObjectID()))
		return GENERALERROR;

	Locker clocker(waypoint, creature);

	waypoint->toggleStatus();

	ghost->updateWaypoint(waypoint->getObjectID());

	return SUCCESS;
}
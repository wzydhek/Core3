#include "RequestBadgesCommand.h"
#include "server/zone/ZoneServer.h"
#include "server/zone/objects/player/PlayerObject.h"
#include "server/zone/objects/scene/SceneObject.h"

RequestBadgesCommand::RequestBadgesCommand(const String& name, ZoneProcessServer* server) : QueueCommand(name, server) {
}

int RequestBadgesCommand::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	ManagedReference<SceneObject*> object = server->getZoneServer()->getObject(target);

	if (object == nullptr)
		return GENERALERROR;

	if (!object->isPlayerCreature())
		return GENERALERROR;

	CreatureObject* playerCreature = cast<CreatureObject*>(object.get());

	Reference<PlayerObject*> playerObject = playerCreature->getSlottedObject("ghost").castTo<PlayerObject*>();

	if (playerObject != nullptr)
		playerObject->sendBadgesResponseTo(creature);

	return SUCCESS;
}
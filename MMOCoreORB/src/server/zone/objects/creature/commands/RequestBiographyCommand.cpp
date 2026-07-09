#include "RequestBiographyCommand.h"
#include "server/zone/ZoneServer.h"
#include "server/zone/objects/player/PlayerObject.h"
#include "server/zone/objects/scene/SceneObject.h"
#include "server/zone/packets/object/Biography.h"

RequestBiographyCommand::RequestBiographyCommand(const String& name, ZoneProcessServer* server) : QueueCommand(name, server) {
}

int RequestBiographyCommand::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	ManagedReference<SceneObject*> object = server->getZoneServer()->getObject(target);

	if (object == nullptr)
		return GENERALERROR;

	if (!object->isPlayerCreature())
		return GENERALERROR;

	if (!creature->isPlayerCreature())
		return GENERALERROR;

	CreatureObject* playerCreature = cast<CreatureObject*>(object.get());

	PlayerObject* ghost = playerCreature->getPlayerObject();

	if (ghost == nullptr)
		return GENERALERROR;

	Biography* bio = new Biography(creature, playerCreature);
	creature->sendMessage(bio);

	return SUCCESS;
}
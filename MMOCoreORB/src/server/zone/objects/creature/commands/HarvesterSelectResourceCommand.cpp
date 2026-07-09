#include "HarvesterSelectResourceCommand.h"
#include "server/zone/ZoneServer.h"
#include "server/zone/objects/installation/InstallationObject.h"
#include "server/zone/objects/scene/SceneObject.h"

HarvesterSelectResourceCommand::HarvesterSelectResourceCommand(const String& name, ZoneProcessServer* server) : QueueCommand(name, server) {
}

int HarvesterSelectResourceCommand::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	if (!creature->isPlayerCreature())
		return GENERALERROR;

	CreatureObject* player = cast<CreatureObject*>(creature);

	ManagedReference<SceneObject*> object = server->getZoneServer()->getObject(target);

	if (object == nullptr || !object->isInstallationObject())
		return GENERALERROR;

	InstallationObject* inso = cast<InstallationObject*>(object.get());

	uint64 spawnId = Long::valueOf(arguments.toString());

	try {
		Locker clocker(object, player);

		if (inso->isOnAdminList(player) && inso->isInRange(player, 20))
			inso->changeActiveResourceID(spawnId);
		else
			player->sendSystemMessage("You are too far.");

	} catch (Exception& e) {
	}

	return SUCCESS;
}
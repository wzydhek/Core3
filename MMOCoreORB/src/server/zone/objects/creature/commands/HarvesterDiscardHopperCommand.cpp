#include "HarvesterDiscardHopperCommand.h"
#include "server/zone/ZoneServer.h"
#include "server/zone/objects/installation/InstallationObject.h"
#include "server/zone/objects/scene/SceneObject.h"

HarvesterDiscardHopperCommand::HarvesterDiscardHopperCommand(const String& name, ZoneProcessServer* server) : QueueCommand(name, server) {
}

int HarvesterDiscardHopperCommand::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	CreatureObject* player = cast<CreatureObject*>(creature);

	ManagedReference<SceneObject*> object = server->getZoneServer()->getObject(target);

	if (object == nullptr || !object->isInstallationObject())
		return GENERALERROR;

	InstallationObject* inso = cast<InstallationObject*>(object.get());

	if (!inso->isHarvesterObject())
		return GENERALERROR;

	try {
		Locker clocker(inso, player);

		if (inso->isOnAdminList(player) && inso->isInRange(player, 20))
			inso->clearResourceHopper();
		else
			player->sendSystemMessage("You are too far.");

	} catch (Exception& e) {
	}

	return SUCCESS;
}
#include "HarvesterGetResourceDataCommand.h"
#include "server/zone/ZoneServer.h"
#include "server/zone/objects/installation/InstallationObject.h"
#include "server/zone/objects/scene/SceneObject.h"
#include "server/zone/packets/harvester/HarvesterResourceDataMessage.h"

HarvesterGetResourceDataCommand::HarvesterGetResourceDataCommand(const String& name, ZoneProcessServer* server) : QueueCommand(name, server) {
}

int HarvesterGetResourceDataCommand::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
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

	auto zone = inso->getZone();

	if (zone == nullptr)
		return GENERALERROR;

	try {
		Locker clocker(object, player);

		HarvesterResourceDataMessage* msg = new HarvesterResourceDataMessage(player, inso, zone);
		player->sendMessage(msg);

	} catch (Exception& e) {
	}

	return SUCCESS;
}
#include "HarvesterDeactivateCommand.h"
#include "server/zone/ZoneServer.h"
#include "server/zone/objects/installation/InstallationObject.h"
#include "server/zone/objects/scene/SceneObject.h"

HarvesterDeactivateCommand::HarvesterDeactivateCommand(const String& name, ZoneProcessServer* server) : QueueCommand(name, server) {
}

int HarvesterDeactivateCommand::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature)) {
		return INVALIDSTATE;
	}

	if (!checkInvalidLocomotions(creature)) {
		return INVALIDLOCOMOTION;
	}

	auto zoneServer = server->getZoneServer();

	if (zoneServer == nullptr) {
		return GENERALERROR;
	}

	ManagedReference<SceneObject*> object = zoneServer->getObject(target);

	if (object == nullptr || (!object->isHarvesterObject() && !object->isGeneratorObject())) {
		return GENERALERROR;
	}

	if (!object->isInRange(creature, 20.f)) {
		return TOOFAR;
	}

	InstallationObject* insO = cast<InstallationObject*>(object.get());

	if (insO == nullptr || !insO->isActive() || !insO->isOnAdminList(creature)) {
		return GENERALERROR;
	}

	try {
		Locker clocker(insO, creature);

		insO->setActive(false);
	} catch (Exception& e) {
	}

	return SUCCESS;
}
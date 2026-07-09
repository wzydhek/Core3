#include "GrantPadawanTrialsEligibilityCommand.h"
#include "server/zone/ZoneServer.h"
#include "server/zone/managers/player/PlayerManager.h"
#include "server/zone/objects/scene/SceneObject.h"

GrantPadawanTrialsEligibilityCommand::GrantPadawanTrialsEligibilityCommand(const String& name, ZoneProcessServer* server) : QueueCommand(name, server) {
}

int GrantPadawanTrialsEligibilityCommand::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	ManagedReference<SceneObject*> object = server->getZoneServer()->getObject(target);

	if (object == nullptr || !object->isCreatureObject())
		return INVALIDTARGET;

	CreatureObject* targetCreature = cast<CreatureObject*>(object.get());

	Locker clocker(targetCreature, creature);

	PlayerManager* pman = server->getPlayerManager();
	pman->finishHologrind(targetCreature);

	return SUCCESS;
}
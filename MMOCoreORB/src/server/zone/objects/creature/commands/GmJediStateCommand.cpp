#include "GmJediStateCommand.h"
#include "server/zone/ZoneServer.h"
#include "server/zone/objects/player/PlayerObject.h"
#include "server/zone/objects/scene/SceneObject.h"

GmJediStateCommand::GmJediStateCommand(const String& name, ZoneProcessServer* server) : QueueCommand(name, server) {
}

int GmJediStateCommand::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	ManagedReference<SceneObject*> object = server->getZoneServer()->getObject(target);

	if (object == nullptr || !object->isCreatureObject())
		return INVALIDTARGET;

	CreatureObject* targetCreature = cast<CreatureObject*>(object.get());

	Locker clocker(targetCreature, creature);

	ManagedReference<PlayerObject*> targetGhost = targetCreature->getPlayerObject();
	if (targetGhost == nullptr)
		return INVALIDTARGET;

	StringTokenizer args(arguments.toString());

	int jediState = args.getIntToken();

	targetGhost->setJediState(jediState);

	return SUCCESS;
}
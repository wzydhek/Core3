#include "SurpriseShotCommand.h"
#include "server/zone/ZoneServer.h"

SurpriseShotCommand::SurpriseShotCommand(const String& name, ZoneProcessServer* server) : CombatQueueCommand(name, server) {
}

int SurpriseShotCommand::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	if (!creature->hasState(CreatureState::COVER))
		return GENERALERROR;

	ZoneServer* zoneServer = creature->getZoneServer();

	if (zoneServer == nullptr)
		return GENERALERROR;

	ManagedReference<SceneObject*> targetObject = zoneServer->getObject(target);

	if (targetObject == nullptr)
		return GENERALERROR;

	if (targetObject->isCreatureObject()) {
		CreatureObject* tarCreo = targetObject->asCreatureObject();

		if (tarCreo == nullptr)
			return GENERALERROR;

		/* TODO: Implement check against alertness for either failure chance or damage bonus. This was broken Pre-CU */

		return doCombatAction(creature, target);
	} else {
		return doCombatAction(creature, target);
	}
}
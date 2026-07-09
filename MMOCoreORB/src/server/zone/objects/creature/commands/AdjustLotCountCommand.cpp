#include "AdjustLotCountCommand.h"
#include "server/zone/objects/player/PlayerObject.h"
#include "server/zone/objects/scene/SceneObject.h"

AdjustLotCountCommand::AdjustLotCountCommand(const String& name, ZoneProcessServer* server) : QueueCommand(name, server) {
}

int AdjustLotCountCommand::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	ManagedReference<SceneObject*> targetObject = creature->getZoneServer()->getObject(target);

	if (targetObject == nullptr || !targetObject->isCreatureObject())
		return INVALIDTARGET;

	CreatureObject* targetCreature = cast<CreatureObject*>(targetObject.get());

	ManagedReference<PlayerObject*> ghost = targetCreature->getPlayerObject();

	if (ghost == nullptr)
		return INVALIDPARAMETERS;

	Locker _lock(targetCreature);

	int lotCount = 0;

	try {
		UnicodeTokenizer tokenizer(arguments);

		lotCount = tokenizer.getIntToken();

	} catch (Exception& e) {
		creature->sendSystemMessage("SYNTAX: /adjustLotCount <lots>");
	}

	ghost->setMaximumLots(ghost->getMaximumLots() + lotCount);

	return SUCCESS;
}
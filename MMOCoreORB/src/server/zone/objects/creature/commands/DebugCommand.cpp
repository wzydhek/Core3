#include "DebugCommand.h"
#include "server/zone/objects/player/PlayerObject.h"

int DebugCommand::executeCommand(CreatureObject* creature, uint64 target, const UnicodeString& arguments) {
	if (!creature->isPlayerCreature())
		return 1;

	StringTokenizer args(arguments.toString());

	ManagedReference<PlayerObject*> ghost = creature->getPlayerObject();

	if (ghost == nullptr) {
		return 0;
	}

	try {
		String status;
		args.getStringToken(status);

		if (status.toLowerCase() == "on") {
			ghost->setDebug(true);
			creature->sendSystemMessage("Debug Output ON");
		} else {
			ghost->setDebug(false);
			creature->sendSystemMessage("Debug Output OFF");
		}

	} catch (Exception& e) {
		creature->sendSystemMessage("SYNTAX: /server debug <on|off>");

		return 0;
	}

	auto targetObject = creature->getZoneServer()->getObject(creature->getTargetID());

	if (targetObject != nullptr) {
		if (targetObject->isAiAgent()) {
			Locker clocker(targetObject, creature);

			AiAgent* aiAgent = targetObject->asAiAgent();

			aiAgent->setAIDebug(true);
		}
	}

	return 0;
}
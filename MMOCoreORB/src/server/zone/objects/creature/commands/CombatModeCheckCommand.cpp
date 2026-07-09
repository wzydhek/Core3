#include "CombatModeCheckCommand.h"
#include "server/zone/Zone.h"
#include "server/zone/managers/gcw/GCWManager.h"

CombatModeCheckCommand::CombatModeCheckCommand(const String& name, ZoneProcessServer* server) : QueueCommand(name, server) {
}

int CombatModeCheckCommand::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	auto zone = creature->getZone();
	if (zone != nullptr) {
		auto gcwManager = zone->getGCWManager();
		if (gcwManager != nullptr) {
			creature->sendSystemMessage(gcwManager->getCrackdownInfo(creature));
			return SUCCESS;
		} else {
			creature->sendSystemMessage("No GCWManager available.");
		}
	} else {
		creature->sendSystemMessage("No zone available.");
	}
	return GENERALERROR;
}
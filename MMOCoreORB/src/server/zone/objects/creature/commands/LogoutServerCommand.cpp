#include "LogoutServerCommand.h"
#include "server/zone/ZoneServer.h"
#include "server/zone/managers/player/PlayerManager.h"
#include "server/zone/objects/player/events/LogoutTask.h"

LogoutServerCommand::LogoutServerCommand(const String& name, ZoneProcessServer* server) : QueueCommand(name, server) {
}

int LogoutServerCommand::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	if (creature->isInCombat()) {
		StringIdChatParameter notincombatMsg("client", "you_cannot_log_out_while_in_combat");
		creature->sendSystemMessage(notincombatMsg); // You cannot log out while in combat.

		return INVALIDSTATE;
	}

	Reference<Task*> logoutTask = creature->getPendingTask("logout");

	if (logoutTask != nullptr) {
		creature->error("WARNING: LogoutServer command called while logout task already pending!");
		return GENERALERROR;
	}

	// Initiate new LogoutTask
	creature->addPendingTask("logout", new LogoutTask(creature), 5000);

	// Register to see POSTURECHANGE events
	PlayerManager* playerManager = server->getZoneServer()->getPlayerManager();
	creature->registerObserver(ObserverEventType::POSTURECHANGED, playerManager);

	return SUCCESS;
}
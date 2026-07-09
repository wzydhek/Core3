#include "PlanetsayCommand.h"
#include "server/zone/ZoneServer.h"
#include "server/chat/ChatManager.h"

PlanetsayCommand::PlanetsayCommand(const String& name, ZoneProcessServer* server) : QueueCommand(name, server) {
}

int PlanetsayCommand::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	ChatManager* chatManager = server->getZoneServer()->getChatManager();
	chatManager->handlePlanetChat(creature, arguments);

	return SUCCESS;
}
/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

class ResendLoginMessageToAllCommand : public QueueCommand {
public:

	ResendLoginMessageToAllCommand(const String& name, ZoneProcessServer* server)
		: QueueCommand(name, server) {

	}

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {

		if (!checkStateMask(creature))
			return INVALIDSTATE;

		if (!checkInvalidLocomotions(creature))
			return INVALIDLOCOMOTION;

		ManagedReference<PlayerManager*> playerManager = server->getPlayerManager();

		if (playerManager != nullptr)
			playerManager->resendLoginMessageToAll();

		return SUCCESS;
	}

};

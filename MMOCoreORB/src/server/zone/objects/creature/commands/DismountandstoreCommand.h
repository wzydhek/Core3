/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

class DismountandstoreCommand : public QueueCommand {
public:

	DismountandstoreCommand(const String& name, ZoneProcessServer* server)
		: QueueCommand(name, server) {

	}

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
		if (!checkStateMask(creature))
			return INVALIDSTATE;

		if (!checkInvalidLocomotions(creature))
			return INVALIDLOCOMOTION;

		/*ManagedReference<CreatureObject*> mount = nullptr;

		if (creature->isRidingMount()) {
			mount = cast<CreatureObject*>( creature->getParent());

			creature->executeObjectControllerAction(STRING_HASHCODE("dismount"));
		}*/

		return SUCCESS;
	}

};

/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "CombatQueueCommand.h"
#include "server/zone/objects/ship/events/DestroyShipTask.h"

class EscapePodCommand : public CombatQueueCommand {
public:
	EscapePodCommand(const String& name, ZoneProcessServer* server) : CombatQueueCommand(name, server) {
	}

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
		auto root = creature->getRootParent();

		if (root == nullptr || !root->isShipObject()) {
			return GENERALERROR;
		}

		auto ship = root->asShipObject();

		if (ship == nullptr) {
			return GENERALERROR;
		}

		if (ship->isPobShip()) {
			creature->sendSystemMessage("@space/space_interaction:use_escape_hatch");
			return GENERALERROR;
		}

		Locker sLock(ship);

		if (ship->getOptionsBitmask() & OptionBitmask::EJECT) {
			auto destroyTask = new DestroyShipTask(ship);

			if (destroyTask != nullptr) {
				destroyTask->execute();
			}

			ship->clearOptionBit(OptionBitmask::EJECT, true);
		} else {
			ship->setOptionBit(OptionBitmask::EJECT, true);
		}

		return SUCCESS;
	}
};

/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "QueueCommand.h"
#include "server/zone/objects/building/BuildingObject.h"

namespace server {
namespace zone {
namespace objects {
namespace creature {
namespace commands {

class RegisterWithLocationCommand : public QueueCommand {
public:

	RegisterWithLocationCommand(const String& name, ZoneProcessServer* server);

	int doQueueCommand(CreatureObject* player, const uint64& target, const UnicodeString& arguments) const;

	void addPlayerToBuilding(CreatureObject* player, BuildingObject* building) const;

	bool isNoviceDoctor(CreatureObject* player) const;

	bool isNoviceEntertainer(CreatureObject* player) const;

	bool isInMedicalBuilding(CreatureObject* player, BuildingObject* building) const;

	bool isInEntertainingBuilding(CreatureObject* player, BuildingObject* building) const;

};

} // namespace commands
} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature::commands;

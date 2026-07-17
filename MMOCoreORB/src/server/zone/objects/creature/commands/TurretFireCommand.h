/*
 * TurretFireCommand.h
 *
 *  Created on: Dec 21, 2012
 *      Author: root
 */

#pragma once

#include "CombatQueueCommand.h"

namespace server {
namespace zone {
namespace objects {
namespace creature {
namespace commands {

class TurretFireCommand : public CombatQueueCommand {
public:
	TurretFireCommand(const String& name, ZoneProcessServer* server);

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const;
};

} // namespace commands
} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature::commands;

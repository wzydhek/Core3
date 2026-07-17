/*
 * CreatureRangedAttackCommand.h
 *
 *  Created on: Jan 13, 2013
 *      Author: root
 */

#pragma once

#include "CombatQueueCommand.h"

namespace server {
namespace zone {
namespace objects {
namespace creature {
namespace commands {

class CreatureRangedAttackCommand : public CombatQueueCommand {
public:

	CreatureRangedAttackCommand(const String& name, ZoneProcessServer* server);

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const;
};

} // namespace commands
} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature::commands;

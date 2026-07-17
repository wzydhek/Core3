/*
 * DefaultDroidAttackCommand.h
 *
 *  Created on: Jan 14, 2013
 *      Author: root
 */

#pragma once

#include "CombatQueueCommand.h"

namespace server {
namespace zone {
namespace objects {
namespace creature {
namespace commands {

class DefaultDroidAttackCommand : public CombatQueueCommand {
public:

	DefaultDroidAttackCommand(const String& name, ZoneProcessServer* server);

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const;

};

} // namespace commands
} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature::commands;

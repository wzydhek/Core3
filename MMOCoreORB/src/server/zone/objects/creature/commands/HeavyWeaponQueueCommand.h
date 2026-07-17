/*
 * HeavyWeaponQueueCommand.h
 *
 *  Created on: 13/05/2012
 *      Author: chris.rush
 */

#pragma once

#include "CombatQueueCommand.h"

namespace server {
namespace zone {
namespace objects {
namespace creature {
namespace commands {

class HeavyWeaponQueueCommand : public CombatQueueCommand {
public:

	HeavyWeaponQueueCommand(const String& name, ZoneProcessServer* server);

	int doCombatAction(CreatureObject* creature, const uint64& target, const UnicodeString& arguments = "") const;

	float getCommandDuration(CreatureObject* object, const UnicodeString& arguments) const;

};

} // namespace commands
} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature::commands;

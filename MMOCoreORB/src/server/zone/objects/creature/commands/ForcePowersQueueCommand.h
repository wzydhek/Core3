/*
 * ForcePowersQueueCommand.h
 *
 *  Created on: 24/05/2010
 *      Author: Valkyra
 */

#pragma once

#include "CombatQueueCommand.h"

namespace server {
namespace zone {
namespace objects {
namespace creature {
namespace commands {

class ForcePowersQueueCommand : public CombatQueueCommand {
public:

	ForcePowersQueueCommand(const String& name, ZoneProcessServer* server);

	int doCombatAction(CreatureObject* creature, const uint64& target, const UnicodeString& arguments = "") const;

	int getFrsModifiedForceCost(CreatureObject* creature) const;

	float getCommandDuration(CreatureObject* object, const UnicodeString& arguments) const;

	virtual bool isJediCombatQueueCommand();

};

} // namespace commands
} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature::commands;

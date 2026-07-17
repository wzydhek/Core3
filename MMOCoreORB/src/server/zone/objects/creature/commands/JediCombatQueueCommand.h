/*
 * JediCombatQueueCommand.h
 *
 *  Created on: 1/11/2016
 *      Author: Greg Slomin
 */

#pragma once

#include "CombatQueueCommand.h"

namespace server {
namespace zone {
namespace objects {
namespace creature {
namespace commands {

class JediCombatQueueCommand : public CombatQueueCommand {

public:

	JediCombatQueueCommand(const String& name, ZoneProcessServer* server);

	virtual bool isJediCombatCommand() const override;
};

} // namespace commands
} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature::commands;

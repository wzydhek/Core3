/*
 * MakeMasterLooterCommand.h
 *
 *  Modified on: March 4, 2015
 *      Author: Anakis
 */

#pragma once

#include "QueueCommand.h"

namespace server {
namespace zone {
namespace objects {
namespace creature {
namespace commands {

class MakeMasterLooterCommand : public QueueCommand {
public:

	MakeMasterLooterCommand(const String& name, ZoneProcessServer* server);

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const;

};

} // namespace commands
} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature::commands;

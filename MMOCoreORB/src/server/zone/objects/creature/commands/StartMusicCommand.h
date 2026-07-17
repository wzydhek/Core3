/*
 				Copyright <SWGEmu>
		See file COPYING for copying conditions. */

#pragma once

#include "QueueCommand.h"

namespace server {
namespace zone {
namespace objects {
namespace creature {
namespace commands {

class StartMusicCommand: public QueueCommand {
public:

	StartMusicCommand(const String& name, ZoneProcessServer* server);

	static void startMusic(CreatureObject* creature, int performanceIndex, Instrument* instrument);

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const;

};

} // namespace commands
} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature::commands;

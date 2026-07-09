/*
 				Copyright <SWGEmu>
		See file COPYING for copying conditions. */

#pragma once

#include "QueueCommand.h"

class StartMusicCommand: public QueueCommand {
public:

	StartMusicCommand(const String& name, ZoneProcessServer* server);

	static void startMusic(CreatureObject* creature, int performanceIndex, Instrument* instrument);

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const;

};


/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

/**
 * \file RequestCoreSampleCommand.h
 * \author Kyle Burkhardt
 * \date 5-27-10
 */

#pragma once

#include "QueueCommand.h"

class RequestCoreSampleCommand : public QueueCommand {
public:

	RequestCoreSampleCommand(const String& name, ZoneProcessServer* server);

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const;
};


/*
 * RequestQuestTimersAndCountersCommand.h
 *
 *  Created on: Oct 6, 2010
 *      Author: oru
 */

#pragma once

#include "QueueCommand.h"

class RequestQuestTimersAndCountersCommand : public QueueCommand {
public:

	RequestQuestTimersAndCountersCommand(const String& name, ZoneProcessServer* server);

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const;

};


/*
 * CloseLotteryContainerCommand.h
 *
 *  Created on: Aug 26, 2011
 *      Author: da
 */

#pragma once

#include "QueueCommand.h"

class CloseLotteryContainerCommand : public QueueCommand {
public:

	CloseLotteryContainerCommand(const String& name, ZoneProcessServer* server);

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const;

};


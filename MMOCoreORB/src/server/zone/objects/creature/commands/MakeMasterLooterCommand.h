/*
 * MakeMasterLooterCommand.h
 *
 *  Modified on: March 4, 2015
 *      Author: Anakis
 */

#pragma once

#include "QueueCommand.h"

class MakeMasterLooterCommand : public QueueCommand {
public:

	MakeMasterLooterCommand(const String& name, ZoneProcessServer* server);

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const;

};


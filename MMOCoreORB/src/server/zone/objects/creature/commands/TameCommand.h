/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#ifndef TAMECOMMAND_H_
#define TAMECOMMAND_H_

#include "QueueCommand.h"

class TameCommand : public QueueCommand {
public:

	TameCommand(const String& name, ZoneProcessServer* server);

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const;

};

#endif //TAMECOMMAND_H_


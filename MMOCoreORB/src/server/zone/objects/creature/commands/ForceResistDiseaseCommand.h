/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "JediQueueCommand.h"

class ForceResistDiseaseCommand : public JediQueueCommand {
public:

	ForceResistDiseaseCommand(const String& name, ZoneProcessServer* server);

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const;

};

/*
 * MildDiseaseCommand.h
 *
 *  Created on: Oct 9, 2010
 *      Author: da
 */

#pragma once

#include "CombatQueueCommand.h"

class MildDiseaseCommand : public CombatQueueCommand {
public:

	MildDiseaseCommand(const String& name, ZoneProcessServer* server);

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const;

};

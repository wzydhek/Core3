/*
 * JediCombatQueueCommand.h
 *
 *  Created on: 1/11/2016
 *      Author: Greg Slomin
 */

#pragma once

#include "CombatQueueCommand.h"

class JediCombatQueueCommand : public CombatQueueCommand {

public:

	JediCombatQueueCommand(const String& name, ZoneProcessServer* server);

	virtual bool isJediCombatCommand() const override;
};

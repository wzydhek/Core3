/*
 *	Copyright <SWGEmu>
 *	See file COPYING for copying conditions.
 *
 *	InspectCommand.h
 *
 *	Created on: 2025-10-14
 *	Author: Hakry
 *
*/

#pragma once

#include "SpaceQueueCommand.h"

class InspectCommand : public SpaceQueueCommand {
	constexpr static float INSPECT_RANGE = 150.f;
	constexpr static uint32 INSPECT_COOLDOWN = 5000;

public:
	InspectCommand(const String& name, ZoneProcessServer* server);

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const;
};

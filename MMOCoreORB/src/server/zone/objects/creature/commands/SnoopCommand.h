/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions. */

#pragma once

#include "QueueCommand.h"

namespace server {
namespace zone {
namespace objects {
namespace creature {
namespace commands {

class SnoopCommand : public QueueCommand {
public:
	SnoopCommand(const String& name, ZoneProcessServer* server);

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const;

	int sendLuaEvents(CreatureObject* creature, CreatureObject* target) const;

	String getTimeString(uint64 timestamp) const;

	int sendVeteranRewardInfo(CreatureObject* creature, CreatureObject* target) const;

	int sendFactionInfo(CreatureObject* creature, CreatureObject* target) const;

	int sendVendorInfo(CreatureObject* creature, CreatureObject* target) const;

	int sendLots(CreatureObject* creature, CreatureObject* target) const;

	int sendHam(CreatureObject* creature, CreatureObject* target) const;

	int sendBuffs(CreatureObject* creature, CreatureObject* target) const;

	int sendSkillModifiers(CreatureObject* creature, CreatureObject* targetCreature) const;
};

} // namespace commands
} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature::commands;

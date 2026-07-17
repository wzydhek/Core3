/*
 * SquadLeaderCommand.h
 *
 *  Created on: Aug 21, 2010
 *      Author: swgemu
 */

#pragma once

#include "CombatQueueCommand.h"
#include "server/zone/objects/group/GroupObject.h"

namespace server {
namespace zone {
namespace objects {
namespace creature {
namespace commands {

class SquadLeaderCommand : public CombatQueueCommand {
protected:
	String action;
	uint32 actionCRC;

public:

	SquadLeaderCommand(const String& name, ZoneProcessServer* server);

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const;

	bool checkGroupLeader(CreatureObject* player, GroupObject* group) const;

	static bool isValidGroupAbilityTarget(CreatureObject* leader, CreatureObject* target, bool allowPet);

	float calculateGroupModifier(GroupObject* group) const;

	bool inflictHAM(CreatureObject* player, int health, int action, int mind) const;

	void sendCombatSpam(CreatureObject* player) const;

	bool isSquadLeaderCommand();

	float getCommandDuration(CreatureObject* object, const UnicodeString& arguments) const;

	const String& getAction() const;

	void setAction(String action);
};

} // namespace commands
} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature::commands;

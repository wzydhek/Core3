/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "QueueCommand.h"

namespace server {
namespace zone {
namespace objects {
namespace creature {
namespace commands {

class RotateFurnitureCommand : public QueueCommand {
public:

	RotateFurnitureCommand(const String& name, ZoneProcessServer* server);

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const;

	bool isValidMoveable(CreatureObject* player, SceneObject* object, bool rotateYaw, bool rotatePitch, bool rotateRoll, bool resetRotate, bool enhancedRotate) const;

};

} // namespace commands
} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature::commands;

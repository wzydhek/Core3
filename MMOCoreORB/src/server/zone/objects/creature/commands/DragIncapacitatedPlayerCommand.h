/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "QueueCommand.h"
#include "server/zone/objects/scene/SceneObject.h"
#include "server/zone/objects/scene/WorldCoordinates.h"

namespace server {
namespace zone {
namespace objects {
namespace creature {
namespace commands {

class DragIncapacitatedPlayerCommand : public QueueCommand {
	float maxMovement;
	bool needsConsent;
public:

	DragIncapacitatedPlayerCommand(const String& name, ZoneProcessServer* server);

	void getCoordinates(SceneObject* object, SceneObject* targetObject, float maxMove, WorldCoordinates* newPosition) const;

	bool drag(CreatureObject* player, CreatureObject* targetPlayer, float maxRange, float maxMovement, bool needsConsent) const;

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const;

};

} // namespace commands
} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature::commands;

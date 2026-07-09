/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/objects/creature/CreatureObject.h"
#include "server/zone/objects/mission/BountyMissionObjective.h"
#include "server/zone/managers/creature/CreatureTemplateManager.h"
#include "server/zone/managers/player/PlayerManager.h"
#include "server/zone/managers/mission/MissionManager.h"
#include "server/zone/Zone.h"

namespace server {
namespace zone {
namespace objects {
namespace mission {
namespace bountyhunter {
namespace events {

class FindTargetTask : public Task, public Logger {
	ManagedWeakReference<CreatureObject*> weakDroid;
	ManagedWeakReference<CreatureObject*> weakPlayer;
	ManagedWeakReference<BountyMissionObjective*> weakObjective;
	int timeLeft;
	bool success;
	bool track;
	bool arakyd;
	int trackingsLeft;
	String zoneName;

	enum states { Init, DroidSent, Searching, Tracking, Completed };

	states state;

	void init(CreatureObject* player, CreatureObject* droid);

	void droidSent(CreatureObject* droid);

	void searching(CreatureObject* player, BountyMissionObjective* objective);

	void tracking(CreatureObject* player, BountyMissionObjective* objective);

	bool findAndTrackSuccess(CreatureObject* player, BountyMissionObjective* objective);

	bool getSuccess(CreatureObject* player, BountyMissionObjective* objective);

	int calculateTime(CreatureObject* player);

	int getTargetLevel(CreatureObject* player, BountyMissionObjective* objective);

	int getDistanceToTarget(CreatureObject* player, BountyMissionObjective* objective);

	String getDirectionToTarget(CreatureObject* player, BountyMissionObjective* objective);

public:
	FindTargetTask(CreatureObject* droid, CreatureObject* player, BountyMissionObjective* objective, bool track, bool arakyd);

	~FindTargetTask();

	bool isArakydTask();

	bool isCompleted();

	void run();
};

} // namespace events
} // namespace bountyhunter
} // namespace mission
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::mission::bountyhunter::events;

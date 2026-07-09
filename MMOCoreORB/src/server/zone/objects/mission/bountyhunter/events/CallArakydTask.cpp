#include "CallArakydTask.h"

CallArakydTask::CallArakydTask(CreatureObject* player, BountyMissionObjective* objective) : Logger("FindTargetTask") {
	this->player = player;
	this->objective = objective;
	time = 20;
	droid = nullptr;
}

CallArakydTask::~CallArakydTask() {
}

void CallArakydTask::run() {
	ManagedReference<CreatureObject*> playerRef = player.get();
	ManagedReference<BountyMissionObjective*> objectiveRef = objective.get();

	if (playerRef == nullptr || objectiveRef == nullptr) {
		return;
	}

	Locker locker(playerRef);

	switch (time) {
		case 20:
			playerRef->sendSystemMessage("@mission/mission_generic:probe_droid_launch_prep");
			time -= 15;
			reschedule(15 * 1000);
			break;
		case 3: {
			droidPosition = getLandingCoordinates(playerRef);
			PlayClientEffectLoc* effect = new PlayClientEffectLoc("clienteffect/probot_delivery.cef", playerRef->getZone()->getZoneName(), droidPosition.getX(), droidPosition.getZ(), droidPosition.getY(), 0, 0);
			playerRef->sendMessage(effect);
		}
		case 5:
		case 4:
		case 2:
		case 1:
			playerRef->sendSystemMessage("@mission/mission_generic:probe_droid_arrival_" + String::valueOf(time));
			time -= 1;
			reschedule(1 * 1000);
			break;
		case 0: {
			playerRef->sendSystemMessage("@mission/mission_generic:probe_droid_arrival");
			droid = cast<AiAgent*>(playerRef->getZone()->getCreatureManager()->spawnCreature(STRING_HASHCODE("probot"), 0, droidPosition.getX(), droidPosition.getZ(), droidPosition.getY(), 0));

			Locker olocker(objectiveRef);
			objectiveRef->setArakydDroid(droid);
			olocker.release();

			Locker lock(droid);
			droid->addObjectFlag(ObjectFlag::STATIC);
			droid->setAITemplate();
			time -= 1;
			reschedule(300 * 1000);
		} break;
		case -1: {
			Locker olocker2(objectiveRef);
			objectiveRef->setArakydDroid(nullptr);
			olocker2.release();

			if (droid != nullptr) {
				Locker clocker(droid, playerRef);
				droid->destroyObjectFromWorld(true);
			}
		} break;
		default:
			error("Unknowns state.");
			break;
	}
}

Vector3 CallArakydTask::getLandingCoordinates(CreatureObject* player) {
	Vector3 position = player->getPosition();
	auto zone = player->getZone();

	if (zone == nullptr) {
		return position;
	}

	auto planetManager = zone->getPlanetManager();

	if (planetManager == nullptr)
		return position;

	return planetManager->getInSightSpawnPoint(player, 30, 120, 15);
}
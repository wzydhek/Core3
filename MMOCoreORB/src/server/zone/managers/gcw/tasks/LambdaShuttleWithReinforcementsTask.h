/*
 * LambdaShuttleWithReinforcementsTask.h
 *
 * Created on: Dec 7, 2016
 * Author: loshult
 */

#pragma once

#include "server/chat/ChatManager.h"
#include "server/zone/objects/creature/ai/AiAgent.h"
#include "server/zone/objects/creature/CreatureObject.h"
#include "server/zone/objects/player/PlayerObject.h"
#include "server/zone/managers/combat/CombatManager.h"
#include "server/zone/managers/collision/CollisionManager.h"
#include "server/zone/managers/creature/CreatureManager.h"
#include "server/zone/managers/gcw/GCWManager.h"
#include "server/zone/managers/gcw/observers/SquadObserver.h"
#include "server/zone/objects/player/FactionStatus.h"
#include "templates/faction/Factions.h"

namespace server {
namespace zone {
namespace managers {
namespace gcw {
namespace tasks {

class LambdaShuttleWithReinforcementsTask : public Task {
public:
	enum ReinforcementType { LAMBDASHUTTLEATTACK, LAMBDASHUTTLESCAN, LAMBDASHUTTLEONLY, CONTAINMENTTEAM };

private:
	WeakReference<CreatureObject*> weakPlayer;
	WeakReference<SceneObject*> weakLambdaShuttle;
	ManagedReference<SquadObserver*> squadObserver;
	int difficulty;
	int spawnNumber;
	String chatMessageId;
	Vector3 spawnPosition;
	Quaternion spawnDirection;
	int closingInTime;
	int timeToDespawnLambdaShuttle;
	int cleanUpTime;
	float spawnOffset;
	unsigned int faction;
	int delayTime;
	ReinforcementType reinforcementType;

	const String LAMBDATEMPLATE = "object/creature/npc/theme_park/lambda_shuttle.iff";
	const int LANDINGTIME = 18000;
	const int SPAWNDELAY = 750;
	const int TASKDELAY = 1000;
	const int LAMBDATAKEOFFDESPAWNTIME = 17;

	const int TROOPSSPAWNPERDIFFICULTY = 5;

	const int MAXDIFFICULTY = 2;
	const int MINDIFFICULTY = 1;

	struct LambdaTroop {
		const String troopTemplate;
		bool singleSpawn;
	};

	LambdaTroop IMPERIALTROOPS[11] = {
		{"crackdown_stormtrooper_squad_leader", true},
		{"crackdown_stormtrooper", false},
		{"crackdown_stormtrooper", false},
		{"crackdown_stormtrooper_sniper", false},
		{"crackdown_stormtrooper", false},
		{"crackdown_stormtrooper_rifleman", false},
		{"crackdown_stormtrooper_medic", false},
		{"crackdown_stormtrooper_sniper", false},
		{"crackdown_stormtrooper_rifleman", false},
		{"crackdown_stormtrooper", false},
		{"crackdown_stormtrooper_bombardier", false}
	};

	LambdaTroop REBELTROOPS[11] = {
		{"crackdown_rebel_guard_captain", true},
		{"crackdown_rebel_cadet", false},
		{"crackdown_rebel_soldier", false},
		{"crackdown_rebel_liberator", false},
		{"crackdown_rebel_soldier", false},
		{"crackdown_rebel_guardsman", false},
		{"crackdown_rebel_elite_sand_rat", false},
		{"crackdown_rebel_command_security_guard", false},
		{"crackdown_rebel_commando", false},
		{"crackdown_rebel_comm_operator", false},
		{"crackdown_rebel_soldier", false}
	};

	enum LamdaShuttleState {
		SPAWNSHUTTLE,
		UPRIGHT,
		ZONEIN,
		LAND,
		SPAWNTROOPS,
		TAKEOFF,
		CLOSINGIN,
		DELAY,
		PICKUPSPAWN,
		PICKUPUPRIGHT,
		PICKUPZONEIN,
		PICKUPLAND,
		DESPAWN,
		PICKUPTAKEOFF,
		PICKUPDESPAWN,
		FINISHED
	};

	LamdaShuttleState state;

	LambdaTroop* troops;

	void spawnSingleTroop(SceneObject* lambdaShuttle, CreatureObject* player, const String& creatureTemplate, float xOffset, float yOffset);

	void spawnOneSetOfTroops(SceneObject* lambdaShuttle, CreatureObject* player);

	void setupMovement(CreatureObject* player);

	void spawnTroops(SceneObject* lambdaShuttle, CreatureObject* player);

	void lambdaShuttleSpawn(SceneObject* lambdaShuttle, CreatureObject* player);

	void lambdaShuttleLanding(SceneObject* lambdaShuttle);

	void lambdaShuttleUpright(SceneObject* lambdaShuttle);

	void lambdaShuttleTakeoff(SceneObject* lambdaShuttle);

	void closingInOnPlayer(CreatureObject* player);

	void delay();

	void despawnNpcs(SceneObject* lambdaShuttle);

	bool transferLambdaShuttle(CreatureObject* player, SceneObject* lambdaShuttle);

	SceneObject* getLambdaShuttle(CreatureObject* player);

public:
	LambdaShuttleWithReinforcementsTask(CreatureObject* player, unsigned int faction, unsigned int difficulty, String chatMessageId, Vector3 position, Quaternion direction, ReinforcementType reinforcementType);

	void run();
};

} // namespace tasks
} // namespace gcw
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::gcw::tasks;

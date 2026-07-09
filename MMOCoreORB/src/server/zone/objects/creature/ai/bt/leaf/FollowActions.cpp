#include "FollowActions.h"
#include "server/zone/managers/creature/PetManager.h"

GetProspectFromThreatMap::GetProspectFromThreatMap(const String& className, const uint32 id, const LuaObject& args) : Behavior(className, id, args) {
}

GetProspectFromThreatMap::GetProspectFromThreatMap(const GetProspectFromThreatMap& a) : Behavior(a) {
}

Behavior::Status GetProspectFromThreatMap::execute(AiAgent* agent, unsigned int startIdx) const {
	agent->eraseBlackboard("targetProspect");

	ManagedReference<SceneObject*> tar = agent->getThreatMap()->getHighestThreatAttacker();
	if (tar == nullptr)
		return FAILURE;

	Locker clocker(tar, agent);

	agent->writeBlackboard("targetProspect", tar);

	return SUCCESS;
}

GetProspectFromDefenders::GetProspectFromDefenders(const String& className, const uint32 id, const LuaObject& args) : Behavior(className, id, args) {
}

GetProspectFromDefenders::GetProspectFromDefenders(const GetProspectFromDefenders& a) : Behavior(a) {
}

Behavior::Status GetProspectFromDefenders::execute(AiAgent* agent, unsigned int startIdx) const {
	agent->eraseBlackboard("targetProspect");

	ManagedReference<SceneObject*> tar = agent->getMainDefender();
	if (tar == nullptr)
		return FAILURE;

	Locker clocker(tar, agent);

	agent->writeBlackboard("targetProspect", tar);

	return SUCCESS;
}

GetProspectFromTarget::GetProspectFromTarget(const String& className, const uint32 id, const LuaObject& args) : Behavior(className, id, args) {
}

GetProspectFromTarget::GetProspectFromTarget(const GetProspectFromTarget& a) : Behavior(a) {
}

Behavior::Status GetProspectFromTarget::execute(AiAgent* agent, unsigned int startIdx) const {
	ManagedReference<SceneObject*> followCopy = agent->getFollowObject();

	if (followCopy == nullptr || !followCopy->isCreatureObject()) {
		return FAILURE;
	}

	Locker fLocker(followCopy, agent);

	if (agent->hasDefender(followCopy)) {
		return SUCCESS;
	}

	ManagedReference<CreatureObject*> followCreo = followCopy->asCreatureObject();

	if (followCreo == nullptr || !followCreo->isInCombat())
		return FAILURE;

	ManagedReference<SceneObject*> target = agent->getTargetFromTargetsMap(followCreo);

	if (target == nullptr) {
		return FAILURE;
	}

	Locker clocker(target, agent);

	agent->sendReactionChat(target, ReactionManager::ALLY);

	agent->writeBlackboard("targetProspect", target);

	return SUCCESS;
}

GetProspectFromCommand::GetProspectFromCommand(const String& className, const uint32 id, const LuaObject& args) : Behavior(className, id, args) {
}

GetProspectFromCommand::GetProspectFromCommand(const GetProspectFromCommand& a) : Behavior(a) {
}

Behavior::Status GetProspectFromCommand::execute(AiAgent* agent, unsigned int startIdx) const {
	if (agent == nullptr || !agent->isPet())
		return FAILURE;

	agent->eraseBlackboard("targetProspect");

	Reference<PetControlDevice*> cd = agent->getControlDevice().castTo<PetControlDevice*>();
	if (cd == nullptr)
		return FAILURE;

	ManagedReference<SceneObject*> tar = cd->getLastCommandTarget().get();
	if (tar == nullptr)
		return FAILURE;

	Locker clocker(tar, agent);

	agent->writeBlackboard("targetProspect", tar);

	return SUCCESS;
}

RestoreFollow::RestoreFollow(const String& className, const uint32 id, const LuaObject& args) : Behavior(className, id, args) {
}

RestoreFollow::RestoreFollow(const RestoreFollow& a) : Behavior(a) {
}

Behavior::Status RestoreFollow::execute(AiAgent* agent, unsigned int startIdx) const {
	agent->restoreFollowObject();
	return agent->getFollowObject() != nullptr ? SUCCESS : FAILURE;
}

DropProspectFromDefenders::DropProspectFromDefenders(const String& className, const uint32 id, const LuaObject& args) : Behavior(className, id, args) {
}

DropProspectFromDefenders::DropProspectFromDefenders(const DropProspectFromDefenders& a) : Behavior(a) {
}

Behavior::Status DropProspectFromDefenders::execute(AiAgent* agent, unsigned int startIdx) const {
	if (!agent->peekBlackboard("targetProspect"))
		return SUCCESS;

	ManagedReference<SceneObject*> tar = agent->readBlackboard("targetProspect").get<ManagedReference<SceneObject*>>();
	if (tar == nullptr) {
		agent->eraseBlackboard("targetProspect");
		return SUCCESS;
	}

	Locker clocker(tar, agent);

	agent->removeDefender(tar);
	agent->eraseBlackboard("targetProspect");

	return agent->hasDefender(tar) ? FAILURE : SUCCESS;
}

SetDefenderFromProspect::SetDefenderFromProspect(const String& className, const uint32 id, const LuaObject& args) : Behavior(className, id, args) {
}

SetDefenderFromProspect::SetDefenderFromProspect(const SetDefenderFromProspect& a) : Behavior(a) {
}

Behavior::Status SetDefenderFromProspect::execute(AiAgent* agent, unsigned int startIdx) const {
	if (!agent->peekBlackboard("targetProspect"))
		return FAILURE;

	ManagedReference<SceneObject*> tar = agent->readBlackboard("targetProspect").get<ManagedReference<SceneObject*>>();
	if (tar == nullptr) {
		agent->eraseBlackboard("targetProspect");
		return FAILURE;
	}

	Locker clocker(tar, agent);

	agent->setDefender(tar);

	return agent->getMainDefender() == tar ? SUCCESS : FAILURE;
}

KillProspect::KillProspect(const String& className, const uint32 id, const LuaObject& args) : Behavior(className, id, args) {
}

KillProspect::KillProspect(const KillProspect& a) : Behavior(a) {
}

Behavior::Status KillProspect::execute(AiAgent* agent, unsigned int startIdx) const {
	if (!agent->peekBlackboard("targetProspect")) {
		return FAILURE;
	}

	ManagedReference<SceneObject*> tar = agent->readBlackboard("targetProspect").get<ManagedReference<SceneObject*>>();

	if (tar == nullptr) {
		agent->eraseBlackboard("targetProspect");
		return FAILURE;
	}

	Locker clocker(tar, agent);

	return agent->killPlayer(tar) ? SUCCESS : FAILURE;
}

UpdateRangeToFollow::UpdateRangeToFollow(const String& className, const uint32 id, const LuaObject& args) : Behavior(className, id, args) {
}

UpdateRangeToFollow::UpdateRangeToFollow(const UpdateRangeToFollow& a) : Behavior(a) {
}

Behavior::Status UpdateRangeToFollow::execute(AiAgent* agent, unsigned int startIdx) const {
	ManagedReference<SceneObject*> followCopy = agent->getFollowObject().get();

	if (followCopy == nullptr) {
		return FAILURE;
	}

	Locker clocker(followCopy, agent);

	float agentRadius = agent->getTemplateRadius();
	float followRadius = followCopy->getTemplateRadius();
	float followRange = agent->getWorldPosition().squaredDistanceTo2d(followCopy->getWorldPosition()) - (followRadius * followRadius) - (agentRadius * agentRadius);

#ifdef DEBUG_AI
	if (agent->peekBlackboard("aiDebug") && agent->readBlackboard("aiDebug") == true) {
		agent->info(true) << "UpdateRangeToFollow -- followRange: " << followRange;
	}
#endif // DEBUG_AI

	agent->writeBlackboard("followRange", BlackboardData(followRange));

	return SUCCESS;
}

SetMovementState::SetMovementState(const String& className, const uint32 id, const LuaObject& args) : Behavior(className, id, args), state(0) {
	parseArgs(args);
}

SetMovementState::SetMovementState(const SetMovementState& a) : Behavior(a), state(a.state) {
}

SetMovementState& SetMovementState::operator=(const SetMovementState& a) {
	if (this == &a)
		return *this;
	Behavior::operator=(a);
	state = a.state;
	return *this;
}

Behavior::Status SetMovementState::execute(AiAgent* agent, unsigned int startIdx) const {
	ManagedReference<SceneObject*> tar = nullptr;

	if (agent->peekBlackboard("targetProspect"))
		tar = agent->readBlackboard("targetProspect").get<ManagedReference<SceneObject*>>();

	if (tar == nullptr && !(agent->getCreatureBitmask() & ObjectFlag::FOLLOW) && (state == AiAgent::WATCHING || state == AiAgent::STALKING || state == AiAgent::FOLLOWING)) {
		agent->setFollowObject(nullptr);
		return FAILURE;
	}

	switch (state) {
		case AiAgent::OBLIVIOUS:
			agent->setOblivious();
			break;
		case AiAgent::WATCHING: {
			if (tar != nullptr) {
				Locker clocker(tar, agent);
				agent->setWatchObject(tar);
			}
			break;
		}
		case AiAgent::STALKING: {
			if (tar != nullptr) {
				Locker clocker(tar, agent);
				agent->setStalkObject(tar);
			}
			break;
		}
		case AiAgent::FOLLOWING:
		case AiAgent::PATROLLING:
		case AiAgent::FLEEING:
		case AiAgent::LEASHING:
		default:
			agent->setMovementState(state);
			break;
	};

	return SUCCESS;
}

void SetMovementState::parseArgs(const LuaObject& args) {
	state = getArg<int32>()(args, "state");
}

String SetMovementState::print() const {
	StringBuffer msg;
	msg << className << "-" << state;

	return msg.toString();
}

CalculateAggroMod::CalculateAggroMod(const String& className, const uint32 id, const LuaObject& args) : Behavior(className, id, args) {
}

Behavior::Status CalculateAggroMod::execute(AiAgent* agent, unsigned int startIdx) const {
	ManagedReference<SceneObject*> tar = nullptr;
	if (agent->peekBlackboard("targetProspect"))
		tar = agent->readBlackboard("targetProspect").get<ManagedReference<SceneObject*>>();

	if (tar == nullptr || !tar->isCreatureObject())
		return FAILURE;

	CreatureObject* tarCreo = tar->asCreatureObject();

	if (tarCreo == nullptr)
		return FAILURE;

	float minMod = Math::min(1.f - (tarCreo->getLevel() - agent->getLevel()) / 8.f, 1.5f);
	float mod = Math::max(0.75f, minMod);

	agent->writeBlackboard("aggroMod", mod);

	return agent->peekBlackboard("aggroMod") ? SUCCESS : FAILURE;
}

RunAway::RunAway(const String& className, const uint32 id, const LuaObject& args) : Behavior(className, id, args), delay(15), dist(0.f) {
	parseArgs(args);
}

RunAway::RunAway(const RunAway& b) : Behavior(b), delay(b.delay), dist(b.dist) {
}

RunAway& RunAway::operator=(const RunAway& b) {
	if (this == &b)
		return *this;
	Behavior::operator=(b);
	delay = b.delay;
	dist = b.dist;
	return *this;
}

Behavior::Status RunAway::execute(AiAgent* agent, unsigned int startIdx) const {
	if (agent == nullptr || !agent->isMonster() || agent->getPvpStatusBitmask() & ObjectFlag::AGGRESSIVE)
		return FAILURE;

	ManagedReference<SceneObject*> tar = nullptr;

	if (agent->peekBlackboard("targetProspect"))
		tar = agent->readBlackboard("targetProspect").get<ManagedReference<SceneObject*>>();

	if (tar == nullptr || !tar->isCreatureObject())
		return FAILURE;

	Locker clocker(tar, agent);

	float aggroMod = 1.f;

	if (agent->peekBlackboard("aggroMod"))
		aggroMod = agent->readBlackboard("aggroMod").get<float>();

	int radius = agent->getAggroRadius();

	if (radius == 0)
		radius = AiAgent::DEFAULTAGGRORADIUS;

	float distance = Math::max(dist, dist - radius * aggroMod);

	Time* fleeDelay = agent->getFleeDelay();

	if (fleeDelay != nullptr) {
		fleeDelay->updateToCurrentTime();
		fleeDelay->addMiliTime(delay * 1000);
	}

	agent->writeBlackboard("fleeRange", distance);
	agent->runAway(tar->asCreatureObject(), distance, false);
	agent->showFlyText("npc_reaction/flytext", "afraid", 0xFF, 0, 0);

	return SUCCESS;
}

void RunAway::parseArgs(const LuaObject& args) {
	delay = getArg<float>()(args, "delay");
	dist = getArg<float>()(args, "dist");
}

String RunAway::print() const {
	StringBuffer msg;
	msg << className << "-" << dist;

	return msg.toString();
}

Evade::Evade(const String& className, const uint32 id, const LuaObject& args) : Behavior(className, id, args), minEvadeChance(0.015), maxEvadeChance(0.05) {
	parseArgs(args);
}

Evade::Evade(const Evade& a) : Behavior(a), minEvadeChance(a.minEvadeChance), maxEvadeChance(a.maxEvadeChance) {
}

Evade& Evade::operator=(const Evade& a) {
	if (this == &a)
		return *this;
	Behavior::operator=(a);
	minEvadeChance = a.minEvadeChance;
	maxEvadeChance = a.maxEvadeChance;
	return *this;
}

void Evade::parseArgs(const LuaObject& args) {
	minEvadeChance = getArg<float>()(args, "minEvadeChance");
	maxEvadeChance = getArg<float>()(args, "maxEvadeChance");
}

Behavior::Status Evade::execute(AiAgent* agent, unsigned int startIdx) const {
	if (!agent->isInCombat() || agent->isPet())
		return FAILURE;

	if (agent->getMovementState() == AiAgent::EVADING)
		return SUCCESS;

	Zone* zone = agent->getZoneUnsafe();

	if (zone == nullptr)
		return FAILURE;

	// TODO: Change when we can do interior pathing
	if (agent->getParentID() != 0)
		return FAILURE;

	float minDist = 15.f;
	float maxDist = 20.f;

	float minChance = minEvadeChance;
	float maxChance = maxEvadeChance;

	float primaryRange = 0;
	float secondaryRange = 0;

	if (agent->getPrimaryWeapon() != nullptr)
		primaryRange = agent->getPrimaryWeapon()->getMaxRange();

	if (agent->getSecondaryWeapon() != nullptr)
		secondaryRange = agent->getSecondaryWeapon()->getMaxRange();

	// No need to evade if creature is melee only
	if (primaryRange < 10.f && secondaryRange < 10.f)
		return FAILURE;

	// Current weapon is melee. We do not need to evade when melee
	if (agent->getWeapon() != nullptr) {
		float idealRange = agent->getWeapon()->getIdealRange();

		if (idealRange < 10.f) {
			return FAILURE;
		}
	}

	ManagedReference<SceneObject*> tar = nullptr;

	if (agent->peekBlackboard("targetProspect"))
		tar = agent->readBlackboard("targetProspect").get<ManagedReference<SceneObject*>>();

	if (tar == nullptr || !tar->isCreatureObject())
		return FAILURE;

	CreatureObject* tarCreo = tar->asCreatureObject();

	if (tarCreo == nullptr)
		return FAILURE;

	Locker clocker(tarCreo, agent);

	if (tarCreo->isPlayerCreature()) {
		float playerWeaponRange = 0;

		if (tarCreo->getWeapon() != nullptr)
			playerWeaponRange = tarCreo->getWeapon()->getMaxRange();

		if (playerWeaponRange < 10.f) {
			minDist = 5.f;

			if (System::random(100) < 30)
				maxDist = playerWeaponRange + 5;
			else
				maxDist = playerWeaponRange - 1;

			if (minDist > maxDist)
				minDist = maxDist;
		}
	}

	if (minChance > maxChance)
		minChance = maxChance;

	float finalChance = maxChance;
	float chanceDiff = maxChance - minChance;
	float diffModifier = chanceDiff * (agent->getHAM(CreatureAttribute::HEALTH) / agent->getMaxHAM(CreatureAttribute::HEALTH));
	finalChance -= chanceDiff * diffModifier;
	finalChance *= 100;

	int randRoll = System::random(100);

	if (finalChance < 100 && randRoll > finalChance)
		return FAILURE;

	float distance = minDist + System::random(maxDist - minDist);
	float angle = System::random(360) * Math::DEG2RAD;

	float newX = tarCreo->getPositionX() + (cos(angle) * distance);
	float newY = tarCreo->getPositionY() + (sin(angle) * distance);

	float newZ = zone->getHeight(newX, newY);

	Vector3 position = Vector3(newX, newY, newZ);

	if (CollisionManager::checkSphereCollision(position, 5, zone))
		return FAILURE;

	agent->setMovementState(AiAgent::EVADING);
	agent->setNextPosition(position.getX(), position.getZ(), position.getY(), agent->getParent().get().castTo<CellObject*>());

	return SUCCESS;
}

String Evade::print() const {
	StringBuffer msg;
	msg << className << "-";

	return msg.toString();
}

StalkProspect::StalkProspect(const String& className, const uint32 id, const LuaObject& args) : Behavior(className, id, args) {
}

StalkProspect::StalkProspect(const StalkProspect& a) : Behavior(a) {
}

Behavior::Status StalkProspect::execute(AiAgent* agent, unsigned int startIdx) const {
	Time* alert = agent->getAlertedTime();

	if (alert == nullptr || !alert->isPast())
		return FAILURE;

	ManagedReference<SceneObject*> tar = nullptr;

	if (agent->peekBlackboard("targetProspect"))
		tar = agent->readBlackboard("targetProspect").get<ManagedReference<SceneObject*>>().get();

	if (tar == nullptr)
		return FAILURE;

	int stalkRad = agent->getAggroRadius();

	if (stalkRad == 0)
		stalkRad = AiAgent::DEFAULTAGGRORADIUS;

	float aggroMod = agent->readBlackboard("aggroMod").get<float>();
	stalkRad *= aggroMod * 2;
	agent->writeBlackboard("stalkRadius", stalkRad);

	Locker clocker(tar, agent);

	if (!tar->isInRange(agent, stalkRad)) {
		return FAILURE;
	}

	if (!agent->stalkProspect(tar))
		return FAILURE;

	return SUCCESS;
}

String StalkProspect::print() const {
	StringBuffer msg;
	msg << className << "-";

	return msg.toString();
}

Flee::Flee(const String& className, const uint32 id, const LuaObject& args) : Behavior(className, id, args), delay(0) {
	parseArgs(args);
}

Flee::Flee(const Flee& a) : Behavior(a), delay(a.delay) {
}

Flee& Flee::operator=(const Flee& a) {
	if (this == &a)
		return *this;
	Behavior::operator=(a);
	delay = a.delay;
	return *this;
}

void Flee::parseArgs(const LuaObject& args) {
	delay = getArg<float>()(args, "delay");
}

Behavior::Status Flee::execute(AiAgent* agent, unsigned int startIdx) const {
	ManagedReference<SceneObject*> target = nullptr;

	if (agent->peekBlackboard("targetProspect"))
		target = agent->readBlackboard("targetProspect").get<ManagedReference<SceneObject*>>().get();

	if (target != nullptr && target->isCreatureObject()) {
		CreatureObject* targetCreo = target->asCreatureObject();
		Time* fleeDelay = agent->getFleeDelay();

		if (targetCreo != nullptr && fleeDelay != nullptr) {
			Locker clocker(targetCreo, agent);

			fleeDelay->updateToCurrentTime();
			fleeDelay->addMiliTime(delay * 1000);

			if (!agent->isInRange(target, 40.f))
				return FAILURE;

			float distance = System::random(20) + 25;

			agent->clearQueueActions(true);
			agent->writeBlackboard("fleeRange", distance);

			agent->runAway(targetCreo, distance, false);
			return SUCCESS;
		}
	}

	return FAILURE;
}

String Flee::print() const {
	StringBuffer msg;
	msg << className << "-";

	return msg.toString();
}

PetReturn::PetReturn(const String& className, const uint32 id, const LuaObject& args) : Behavior(className, id, args) {
}

PetReturn::PetReturn(const PetReturn& a) : Behavior(a) {
}

Behavior::Status PetReturn::execute(AiAgent* agent, unsigned int startIdx) const {
	if (agent == nullptr || !agent->isPet()) {
		return FAILURE;
	}

	Reference<PetControlDevice*> controlDevice = agent->getControlDevice().castTo<PetControlDevice*>();

	if (controlDevice == nullptr) {
		return FAILURE;
	}

	ManagedReference<SceneObject*> newFollow = controlDevice->getLastCommander();
	uint32 lastCommand = controlDevice->getLastCommand();

	Locker clocker(controlDevice, agent);

	if (lastCommand == PetManager::PATROL) {
		if (controlDevice->getPatrolPointSize() == 0) {
			return FAILURE;
		}

		controlDevice->setLastCommandTarget(nullptr);

		agent->setFollowObject(nullptr);
		agent->setMovementState(AiAgent::PATROLLING);
		agent->clearSavedPatrolPoints();

		for (int i = 0; i < controlDevice->getPatrolPointSize(); i++) {
			PatrolPoint point = controlDevice->getPatrolPoint(i);
			agent->addPatrolPoint(point);
		}

		return SUCCESS;
	} else if (lastCommand == PetManager::GUARD || lastCommand == PetManager::FOLLOWOTHER) {
		newFollow = controlDevice->getLastCommandTarget();
	} else {
		newFollow = agent->getLinkedCreature().get();
	}

	if (newFollow == nullptr) {
		return FAILURE;
	}

	controlDevice->setLastCommandTarget(newFollow);

	clocker.release();

	agent->setFollowObject(newFollow);

	return SUCCESS;
}

String PetReturn::print() const {
	StringBuffer msg;
	msg << className << "-";

	return msg.toString();
}

FollowSquadLeader::FollowSquadLeader(const String& className, const uint32 id, const LuaObject& args) : Behavior(className, id, args) {
}

FollowSquadLeader::FollowSquadLeader(const FollowSquadLeader& a) : Behavior(a) {
}

Behavior::Status FollowSquadLeader::execute(AiAgent* agent, unsigned int startIdx) const {
	if (agent == nullptr)
		return FAILURE;

	ManagedReference<SquadObserver*> squadObserver = nullptr;
	SortedVector<ManagedReference<Observer*>> observers = agent->getObservers(ObserverEventType::SQUAD);

	for (int i = 0; i < observers.size(); i++) {
		squadObserver = cast<SquadObserver*>(observers.get(i).get());
		if (squadObserver != nullptr)
			break;
	}

	if (squadObserver == nullptr)
		return FAILURE;

	AiAgent* squadLeader = squadObserver->getMember(0);

	if (squadLeader == nullptr)
		return FAILURE;

	uint64 squadLeaderID = squadLeader->getObjectID();

	if (squadLeaderID == agent->getObjectID())
		return FAILURE;

	ManagedReference<SceneObject*> followCopy = agent->getFollowObject().get();

	if (followCopy != nullptr && followCopy->getObjectID() == squadLeaderID) {
		return FAILURE;
	}

	Locker clocker(squadLeader, agent);

	agent->addObjectFlag(ObjectFlag::FOLLOW);
	agent->setFollowObject(squadLeader);

	return SUCCESS;
}

String FollowSquadLeader::print() const {
	StringBuffer msg;
	msg << className << "-";

	return msg.toString();
}

FollowHerd::FollowHerd(const String& className, const uint32 id, const LuaObject& args) : Behavior(className, id, args) {
}

FollowHerd::FollowHerd(const FollowHerd& a) : Behavior(a) {
}

Behavior::Status FollowHerd::execute(AiAgent* agent, unsigned int startIdx) const {
	if (agent == nullptr)
		return FAILURE;

	ManagedReference<CreatureHerdObserver*> herdObserver = agent->getHerdObserver();

	if (herdObserver == nullptr)
		return FAILURE;

	AiAgent* herdLeader = herdObserver->getHerdLeader();

	if (herdLeader == nullptr)
		return FAILURE;

	uint64 herdLeaderID = herdLeader->getObjectID();

	if (herdLeaderID == agent->getObjectID())
		return FAILURE;

	ManagedReference<SceneObject*> followCopy = agent->getFollowObject().get();

	if (followCopy != nullptr && followCopy->getObjectID() == herdLeaderID) {
		return FAILURE;
	}

	Locker clocker(herdLeader, agent);

	// agent->info(true) << "calling FollowHerd -- current follow target: " << (followCopy != nullptr ? followCopy->getDisplayedName() : "nullptr") << " MovementState: " << agent->getMovementState();

	agent->setFollowObject(herdLeader);

	return SUCCESS;
}

String FollowHerd::print() const {
	StringBuffer msg;
	msg << className << "-";

	return msg.toString();
}

GetHealTarget::GetHealTarget(const String& className, const uint32 id, const LuaObject& args) : Behavior(className, id, args), range(0.f) {
	parseArgs(args);
}

GetHealTarget::GetHealTarget(const GetHealTarget& a) : Behavior(a), range(a.range) {
}

GetHealTarget& GetHealTarget::operator=(const GetHealTarget& a) {
	if (this == &a) {
		return *this;
	}

	Behavior::operator=(a);
	range = a.range;
	return *this;
}

Behavior::Status GetHealTarget::execute(AiAgent* agent, unsigned int startIdx) const {
	// agent->info(true) << "ID: " << agent->getObjectID() << " calling --- GetHealTarget!";

	ManagedReference<SceneObject*> targetProspect = nullptr;

	if (agent->peekBlackboard("targetProspect")) {
		targetProspect = agent->readBlackboard("targetProspect").get<ManagedReference<SceneObject*>>().get();
	}

	if (targetProspect == nullptr || !targetProspect->isCreatureObject()) {
		return FAILURE;
	}

	auto targetTanO = targetProspect->asTangibleObject();

	if (targetTanO == nullptr) {
		return FAILURE;
	}

	const DeltaVector<ManagedReference<SceneObject*>>* defenderList = targetTanO->getDefenderList();

	if (defenderList == nullptr || defenderList->size() < 1) {
		return FAILURE;
	}

	int healTar = System::random(defenderList->size() - 1);

	ManagedReference<SceneObject*> defenderSceneO = defenderList->get(healTar);

	if (defenderSceneO == nullptr || !defenderSceneO->isCreatureObject()) {
		return FAILURE;
	}

	ManagedReference<TangibleObject*> healTarget = defenderSceneO->asTangibleObject();

	if (healTarget == nullptr) {
		return FAILURE;
	}

	if (healTarget->getObjectID() == agent->getObjectID()) {
		// agent->info(true) << "ID: " << agent->getObjectID() << " Agent setting self as heal target";

		agent->writeBlackboard("healTarget", healTarget);
		return SUCCESS;
	}

	auto healCreo = healTarget->asCreatureObject();

	if (healCreo == nullptr || healCreo->isDead()) {
		// agent->info(true) << "blocked adding a CreO to healTarget";
		return FAILURE;
	}

	Locker clocker(healCreo, agent);

	if (healCreo->isAggressiveTo(agent) || agent->isAggressiveTo(healCreo)) {
		return FAILURE;
	}

	if (healCreo->getFaction() > 0 && (healCreo->getFaction() != agent->getFaction() && healCreo->getFactionStatus() > FactionStatus::ONLEAVE)) {
		return FAILURE;
	}

	if (!agent->isInRange3d(healCreo, range)) {
		return FAILURE;
	}

	agent->setMovementState(AiAgent::MOVING_TO_HEAL);

	// This must set the Tangible Object as the target to heal
	agent->writeBlackboard("healTarget", healTarget);

	// agent->info(true) << "ID: " << agent->getObjectID() << "    Set up a healTarget ---- " << healCreo->getDisplayedName();

	return SUCCESS;
}

void GetHealTarget::parseArgs(const LuaObject& args) {
	range = (float)(getArg<float>()(args, "range"));
}

String GetHealTarget::print() const {
	StringBuffer msg;
	msg << className << "-" << range;

	return msg.toString();
}

RestorePetPatrols::RestorePetPatrols(const String& className, const uint32 id, const LuaObject& args) : Behavior(className, id, args) {
}

RestorePetPatrols::RestorePetPatrols(const RestorePetPatrols& a) : Behavior(a) {
}

Behavior::Status RestorePetPatrols::execute(AiAgent* agent, unsigned int startIdx) const {
	if (agent == nullptr || !agent->isPet())
		return FAILURE;

	ManagedReference<PetControlDevice*> pcd = agent->getControlDevice().get().castTo<PetControlDevice*>();

	if (pcd == nullptr)
		return FAILURE;

	for (int i = 0; i < pcd->getPatrolPointSize(); ++i) {
		PatrolPoint patrolPoint = pcd->getPatrolPoint(i);

		agent->addPatrolPoint(patrolPoint);
	}

	return SUCCESS;
}

String RestorePetPatrols::print() const {
	StringBuffer msg;
	msg << className << "-";

	return msg.toString();
}

DroidHarvest::DroidHarvest(const String& className, const uint32 id, const LuaObject& args) : Behavior(className, id, args) {
}

DroidHarvest::DroidHarvest(const DroidHarvest& a) : Behavior(a) {
}

Behavior::Status DroidHarvest::execute(AiAgent* agent, unsigned int startIdx) const {
	if (agent == nullptr || agent->isDead() || agent->isIncapacitated() || !agent->isDroid())
		return FAILURE;

	ManagedReference<DroidObject*> droid = cast<DroidObject*>(agent);

	if (droid == nullptr)
		return FAILURE;

	auto module = droid->getModule("harvest_module").castTo<DroidHarvestModuleDataComponent*>();

	if (module == nullptr)
		return FAILURE;

	ManagedReference<SceneObject*> target = nullptr;

	if (!agent->peekBlackboard("harvestTarget")) {
		if (!module->hasMoreTargets())
			return FAILURE;

		uint64 targetID = module->getNextHarvestTarget();

		ZoneServer* zoneServer = agent->getZoneServer();

		if (zoneServer == nullptr)
			return FAILURE;

		target = zoneServer->getObject(targetID, true);
	} else {
		target = agent->readBlackboard("harvestTarget").get<ManagedReference<SceneObject*>>();
	}

	if (target == nullptr || !target->isCreature())
		return FAILURE;

	Locker cLocker(target, agent);

	agent->writeBlackboard("harvestTarget", target);

	CreatureObject* tarCreo = target->asCreatureObject();

	if (tarCreo == nullptr || !tarCreo->isDead())
		return FAILURE;

	ManagedReference<CreatureObject*> owner = agent->getLinkedCreature().get();

	if (owner == nullptr) {
		return FAILURE;
	}

	Locker olock(owner, agent);

	// Droid must have power move to module itself.
	if (!droid->hasPower()) {
		droid->showFlyText("npc_reaction/flytext", "low_power", 204, 0, 0); // "*Low Power*

		return FAILURE;
	}

	if (!tarCreo->isInRange(owner, 64.0f)) {
		agent->eraseBlackboard("harvestTarget");

		agent->setFollowObject(owner);
		agent->storeFollowObject();
		agent->setMovementState(AiAgent::FOLLOWING);

		return FAILURE;
	}

	if (!tarCreo->isInRange(droid, 7.0f + tarCreo->getTemplateRadius() + droid->getTemplateRadius())) {
		agent->setMovementState(AiAgent::HARVESTING);
		agent->setNextPosition(tarCreo->getPositionX(), tarCreo->getPositionZ(), tarCreo->getPositionY(), tarCreo->getParent().get().castTo<CellObject*>());

		droid->notifyObservers(ObserverEventType::STARTCOMBAT, owner);

		return SUCCESS;
	}

	Reference<Task*> task = new DroidHarvestTask(module, tarCreo);
	Core::getTaskManager()->executeTask(task);

	agent->eraseBlackboard("harvestTarget");

	if (!module->hasMoreTargets()) {
		agent->setFollowObject(owner);
		agent->storeFollowObject();
		agent->setMovementState(AiAgent::FOLLOWING);
	}

	return SUCCESS;
}

String DroidHarvest::print() const {
	StringBuffer msg;
	msg << className << "-";

	return msg.toString();
}
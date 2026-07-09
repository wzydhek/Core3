#include "FollowActionsSpace.h"

CalculateAggroMod::CalculateAggroMod(const String& className, const uint32 id, const LuaObject& args) : BehaviorSpace(className, id, args) {
}

BehaviorSpace::Status CalculateAggroMod::execute(ShipAiAgent* agent, unsigned int startIdx) const {
#ifdef DEBUG_SHIP_AI
	if (agent->peekBlackboard("aiDebug") && agent->readBlackboard("aiDebug") == true)
		agent->info(true) << agent->getDisplayedName() << " - CalculateAggroMod  called";
#endif // DEBUG_SHIP_AI

	ManagedReference<ShipObject*> targetShip = nullptr;

	if (agent->peekBlackboard("targetShipProspect")) {
#ifdef DEBUG_SHIP_AI
		if (agent->peekBlackboard("aiDebug") && agent->readBlackboard("aiDebug") == true)
			agent->info(true) << agent->getDisplayedName() << " - CalculateAggroMod  readBlackboard";
#endif // DEBUG_SHIP_AI
		targetShip = agent->readBlackboard("targetShipProspect").get<ManagedReference<ShipObject*>>();
	}

#ifdef DEBUG_SHIP_AI
	if (agent->peekBlackboard("aiDebug") && agent->readBlackboard("aiDebug") == true)
		agent->info(true) << agent->getDisplayedName() << " - CalculateAggroMod  target check";
#endif // DEBUG_SHIP_AI

	if (targetShip == nullptr)
		return FAILURE;

	float minMod = 1.5f; // Math::min(1.f - (tarCreo->getLevel() - agent->getLevel()) / 8.f, 1.5f);
	float mod = Math::max(0.75f, minMod);

	agent->writeBlackboard("aggroMod", mod);

#ifdef DEBUG_SHIP_AI
	if (agent->peekBlackboard("aiDebug") && agent->readBlackboard("aiDebug") == true)
		agent->info(true) << agent->getDisplayedName() << " - CalculateAggroMod  complete";
#endif // DEBUG_SHIP_AI

	return agent->peekBlackboard("aggroMod") ? SUCCESS : FAILURE;
}

SetMovementState::SetMovementState(const String& className, const uint32 id, const LuaObject& args) : BehaviorSpace(className, id, args), state(0) {
	parseArgs(args);
}

SetMovementState::SetMovementState(const SetMovementState& a) : BehaviorSpace(a), state(a.state) {
}

SetMovementState& SetMovementState::operator=(const SetMovementState& a) {
	if (this == &a)
		return *this;
	BehaviorSpace::operator=(a);
	state = a.state;
	return *this;
}

BehaviorSpace::Status SetMovementState::execute(ShipAiAgent* agent, unsigned int startIdx) const {
	ManagedReference<ShipObject*> targetShip = nullptr;

	if (agent->peekBlackboard("targetShipProspect")) {
		targetShip = agent->readBlackboard("targetShipProspect").get<ManagedReference<ShipObject*>>();
	}

	// agent->info(true) << agent->getDisplayedName() << " set movement state: " << state;

	switch (state) {
		case ShipAiAgent::OBLIVIOUS:
		case ShipAiAgent::WATCHING:
		case ShipAiAgent::PATROLLING: {
			agent->clearOptionBit(OptionBitmask::WINGS_OPEN, true);
			break;
		}
		case ShipAiAgent::ATTACKING: {
			if (targetShip != nullptr) {
				Locker clocker(targetShip, agent);

				agent->setTargetShipObject(targetShip);
			}

			agent->setOptionBit(OptionBitmask::WINGS_OPEN, true);
			agent->clearPatrolPoints();

			break;
		}
		case ShipAiAgent::EVADING: {
			agent->clearPatrolPoints();
			break;
		}
		case ShipAiAgent::FLEEING:
		case ShipAiAgent::LEASHING:
		case ShipAiAgent::FOLLOWING:
		case ShipAiAgent::PATHING_HOME:
		case ShipAiAgent::FOLLOW_FORMATION:
		default: {
			agent->clearOptionBit(OptionBitmask::WINGS_OPEN, true);
			agent->clearPatrolPoints();
			break;
		}
	};

	agent->setMovementState(state);

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

SetDefenderFromProspect::SetDefenderFromProspect(const String& className, const uint32 id, const LuaObject& args) : BehaviorSpace(className, id, args) {
}

SetDefenderFromProspect::SetDefenderFromProspect(const SetDefenderFromProspect& a) : BehaviorSpace(a) {
}

BehaviorSpace::Status SetDefenderFromProspect::execute(ShipAiAgent* agent, unsigned int startIdx) const {
	if (!agent->peekBlackboard("targetShipProspect"))
		return FAILURE;

	ManagedReference<ShipObject*> targetShip = agent->readBlackboard("targetShipProspect").get<ManagedReference<ShipObject*>>();

	if (targetShip == nullptr) {
		agent->eraseBlackboard("targetShipProspect");
		return FAILURE;
	}

	Locker clocker(targetShip, agent);

	agent->setDefender(targetShip);

	// agent->info(true) << " DEFENDER SET FROM targetShipProspect ---  " << targetShip->getDisplayedName();

#ifdef DEBUG_SHIP_AI
	if (agent->peekBlackboard("aiDebug") && agent->readBlackboard("aiDebug") == true)
		agent->info(true) << agent->getDisplayedName() << " - SetDefenderFromProspect";
#endif // DEBUG_SHIP_AI

	return agent->getMainDefender() == targetShip ? SUCCESS : FAILURE;
}

Evade::Evade(const String& className, const uint32 id, const LuaObject& args) : BehaviorSpace(className, id, args), evadeDelay(5000) {
	parseArgs(args);
}

Evade::Evade(const Evade& a) : BehaviorSpace(a), evadeDelay(a.evadeDelay) {
}

Evade& Evade::operator=(const Evade& a) {
	if (this == &a)
		return *this;
	BehaviorSpace::operator=(a);

	evadeDelay = a.evadeDelay;

	return *this;
}

void Evade::parseArgs(const LuaObject& args) {
	evadeDelay = getArg<uint64>()(args, "evadeDelay");
}

BehaviorSpace::Status Evade::execute(ShipAiAgent* agent, unsigned int startIdx) const {
	Time* evadeTime = agent->getEvadeDelay();

	if (evadeTime != nullptr && evadeTime->isPast()) {
		evadeTime->updateToCurrentTime();

		uint64 randomEvade = evadeDelay + System::random(evadeDelay);

		evadeTime->addMiliTime(randomEvade);

		// agent->info(true) << agent->getDisplayedName() << " Evade delay set for " << randomEvade;
	}

	// agent->info(true) << agent->getDisplayedName() << " Evade Success";

	return SUCCESS;
}

String Evade::print() const {
	StringBuffer msg;
	msg << className << " - Evade Delay: " << evadeDelay;

	return msg.toString();
}

EngageSingleTarget::EngageSingleTarget(const String& className, const uint32 id, const LuaObject& args) : BehaviorSpace(className, id, args) {
}

EngageSingleTarget::EngageSingleTarget(const EngageSingleTarget& a) : BehaviorSpace(a) {
}

EngageSingleTarget& EngageSingleTarget::operator=(const EngageSingleTarget& a) {
	if (this == &a) {
		return *this;
	}

	BehaviorSpace::operator=(a);

	return *this;
}

BehaviorSpace::Status EngageSingleTarget::execute(ShipAiAgent* agent, unsigned int startIdx) const {
	if (!agent->peekBlackboard("targetShipProspect")) {
		return FAILURE;
	}

	ManagedReference<ShipObject*> targetShip = agent->readBlackboard("targetShipProspect").get<ManagedReference<ShipObject*>>();

	if (targetShip == nullptr) {
		return FAILURE;
	}

	Vector<uint32> weaponVector = agent->getActiveWeaponVector();

	if (weaponVector.size() == 0) {
		return FAILURE;
	}

	Locker clock(targetShip, agent);

	for (int i = 0; i < weaponVector.size(); i++) {
		int slot = weaponVector.get(i);

		agent->fireWeaponAtTarget(targetShip, slot, Components::CHASSIS);
	}

	uint64 timeNow = System::getMiliTime();
	agent->writeBlackboard("refireInterval", timeNow);

	return SUCCESS;
}

String EngageSingleTarget::print() const {
	StringBuffer msg;
	msg << className << "-";

	return msg.toString();
}

EngageTurrets::EngageTurrets(const String& className, const uint32 id, const LuaObject& args) : BehaviorSpace(className, id, args) {
}

EngageTurrets::EngageTurrets(const EngageTurrets& a) : BehaviorSpace(a) {
}

EngageTurrets& EngageTurrets::operator=(const EngageTurrets& a) {
	if (this == &a) {
		return *this;
	}

	BehaviorSpace::operator=(a);

	return *this;
}

BehaviorSpace::Status EngageTurrets::execute(ShipAiAgent* agent, unsigned int startIdx) const {
	auto targetVector = agent->getTargetVector();

	if (targetVector == nullptr || targetVector->size() == 0) {
		return FAILURE;
	}

	auto weaponVector = agent->getActiveWeaponVector();

	if (weaponVector.size() == 0) {
		return FAILURE;
	}

	int weaponsFiredMax = 10;
	int weaponsFired = 0;

	Vector<ManagedReference<ShipObject*>> targetVectorCopy;
	targetVector->safeCopyTo(targetVectorCopy);

	for (int i = 0; i < targetVectorCopy.size(); ++i) {
		auto targetEntry = targetVectorCopy.get(i);

		if (targetEntry == nullptr || !targetEntry->isAttackableBy(agent) || !agent->isAggressiveTo(targetEntry)) {
			continue;
		}

		Locker cLock(targetEntry, agent);

		for (int ii = weaponVector.size(); -1 < --ii;) {
			int key = System::random(ii);
			int slot = weaponVector.get(key);

			if (agent->fireWeaponAtTarget(targetEntry, slot, Components::CHASSIS)) {
				weaponVector.remove(key);
				weaponsFired += 1;
			}

			if (weaponVector.size() == 0 || weaponsFired >= weaponsFiredMax) {
				break;
			}
		}

		if (weaponVector.size() == 0 || weaponsFired >= weaponsFiredMax) {
			break;
		}
	}

	uint64 timeNow = System::getMiliTime();
	agent->writeBlackboard("refireInterval", timeNow);

	return SUCCESS;
}

String EngageTurrets::print() const {
	StringBuffer msg;
	msg << className << "-";

	return msg.toString();
}

GetProspectFromThreatMap::GetProspectFromThreatMap(const String& className, const uint32 id, const LuaObject& args) : BehaviorSpace(className, id, args) {
}

GetProspectFromThreatMap::GetProspectFromThreatMap(const GetProspectFromThreatMap& a) : BehaviorSpace(a) {
}

BehaviorSpace::Status GetProspectFromThreatMap::execute(ShipAiAgent* agent, unsigned int startIdx) const {
	agent->eraseBlackboard("targetShipProspect");

	auto threatMap = agent->getThreatMap();

	if (threatMap == nullptr) {
		return FAILURE;
	}

	ManagedReference<TangibleObject*> topThreat = threatMap->getHighestThreatAttacker();

	// Make sure top threat is not null and is a ship
	if (topThreat == nullptr || !topThreat->isShipObject()) {
		return FAILURE;
	}

	ManagedReference<ShipObject*> targetShip = topThreat->asShipObject();

	if (targetShip == nullptr)
		return FAILURE;

	Locker lock(targetShip, agent);

	// agent->info(true) << " NEW THREAT SET ---  Top Threat setting targetShipProspect: " << targetShip->getShipName();

	agent->writeBlackboard("targetShipProspect", targetShip);

	return SUCCESS;
}

GetProspectFromDefenders::GetProspectFromDefenders(const String& className, const uint32 id, const LuaObject& args) : BehaviorSpace(className, id, args) {
}

GetProspectFromDefenders::GetProspectFromDefenders(const GetProspectFromDefenders& a) : BehaviorSpace(a) {
}

BehaviorSpace::Status GetProspectFromDefenders::execute(ShipAiAgent* agent, unsigned int startIdx) const {
	ManagedReference<SceneObject*> defender = agent->getMainDefender();

	if (defender == nullptr || !defender->isShipObject())
		return FAILURE;

	ManagedReference<ShipObject*> defenderShip = defender->asShipObject();

	if (defenderShip == nullptr)
		return FAILURE;

	ManagedReference<ShipObject*> targetShip = nullptr;

	if (agent->peekBlackboard("targetShipProspect")) {
		targetShip = agent->readBlackboard("targetShipProspect").get<ManagedReference<ShipObject*>>();

		if (targetShip != nullptr && targetShip->getObjectID() == defenderShip->getObjectID())
			return SUCCESS;
	}

	Locker clocker(defenderShip, agent);

	agent->eraseBlackboard("targetShipProspect");
	agent->writeBlackboard("targetShipProspect", defenderShip);

	return SUCCESS;
}
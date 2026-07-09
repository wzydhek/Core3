#include "SimpleActions.h"
#include "server/zone/Zone.h"
#include "templates/params/creature/CreatureAttribute.h"
#include "server/zone/managers/creature/CreatureManager.h"

Dummy::Dummy(const String& className, const uint32 id, const LuaObject& args) : Behavior(className, id, args) {
}

Dummy::Dummy(const Dummy& d) : Behavior(d) {
}

Behavior::Status Dummy::execute(AiAgent*, unsigned int) const {
	return SUCCESS; // this is meant to be decorated with AlwaysXX, so this return won't matter.
}

GeneratePatrol::GeneratePatrol(const String& className, const uint32 id, const LuaObject& args) : Behavior(className, id, args), numPoints(0), distFromHome(0.0) {
	parseArgs(args);
}

GeneratePatrol::GeneratePatrol(const GeneratePatrol& a) : Behavior(a), numPoints(a.numPoints), distFromHome(a.distFromHome) {
}

GeneratePatrol& GeneratePatrol::operator=(const GeneratePatrol& a) {
	if (this == &a)
		return *this;
	Behavior::operator=(a);
	numPoints = a.numPoints;
	distFromHome = a.distFromHome;
	return *this;
}

void GeneratePatrol::parseArgs(const LuaObject& args) {
	numPoints = getArg<int>()(args, "numPoints");
	distFromHome = getArg<float>()(args, "distFromHome");
}

Behavior::Status GeneratePatrol::execute(AiAgent* agent, unsigned int startIdx) const {
	return agent->generatePatrol(numPoints, distFromHome) ? SUCCESS : FAILURE;
}

String GeneratePatrol::print() const {
	StringBuffer msg;
	msg << className << "-" << numPoints << ":" << distFromHome;

	return msg.toString();
}

ExitCombat::ExitCombat(const String& className, const uint32 id, const LuaObject& args) : Behavior(className, id, args), clearDefenders(false) {
	parseArgs(args);
}

ExitCombat::ExitCombat(const ExitCombat& a) : Behavior(a), clearDefenders(a.clearDefenders) {
}

ExitCombat& ExitCombat::operator=(const ExitCombat& a) {
	if (this == &a)
		return *this;
	Behavior::operator=(a);
	clearDefenders = a.clearDefenders;
	return *this;
}

void ExitCombat::parseArgs(const LuaObject& args) {
	clearDefenders = getArg<bool>()(args, "clearDefenders");
}

Behavior::Status ExitCombat::execute(AiAgent* agent, unsigned int startIdx) const {
	if (!agent->isInCombat())
		return FAILURE;

	agent->clearQueueActions(true);
	agent->clearCombatState(clearDefenders);

	return !agent->isInCombat() ? SUCCESS : FAILURE;
}

String ExitCombat::print() const {
	StringBuffer msg;
	msg << className << "-" << clearDefenders;

	return msg.toString();
}

EquipStagedWeapon::EquipStagedWeapon(const String& className, const uint32 id, const LuaObject& args) : Behavior(className, id, args) {
}

EquipStagedWeapon::EquipStagedWeapon(const EquipStagedWeapon& a) : Behavior(a) {
}

Behavior::Status EquipStagedWeapon::execute(AiAgent* agent, unsigned int startIdx) const {
	if (!agent->peekBlackboard("stagedWeapon"))
		return FAILURE;

	uint32 weapon = agent->readBlackboard("stagedWeapon").get<uint32>();

	if (weapon == DataVal::PRIMARYWEAPON) {
		agent->equipPrimaryWeapon();
	} else if (weapon == DataVal::SECONDARYWEAPON) {
		agent->equipSecondaryWeapon();
	}

	return SUCCESS;
}

WriteBlackboard::WriteBlackboard(const String& className, const uint32 id, const LuaObject& args) : Behavior(className, id, args) {
	parseArgs(args);
}

WriteBlackboard::WriteBlackboard(const WriteBlackboard& a) : Behavior(a), key(a.key), val(a.val) {
}

WriteBlackboard& WriteBlackboard::operator=(const WriteBlackboard& a) {
	if (this == &a)
		return *this;
	Behavior::operator=(a);
	key = a.key;
	val = a.val;
	return *this;
}

void WriteBlackboard::parseArgs(const LuaObject& args) {
	key = getArg<String>()(args, "key");
	val = getArg<uint32>()(args, "val");
}

Behavior::Status WriteBlackboard::execute(AiAgent* agent, unsigned int startIdx) const {
	agent->writeBlackboard(key, val);

	return SUCCESS;
}

String WriteBlackboard::print() const {
	StringBuffer msg;
	msg << className << "-" << key << ":" << val;

	return msg.toString();
}

EraseBlackboard::EraseBlackboard(const String& className, const uint32 id, const LuaObject& args) : Behavior(className, id, args), param("") {
	parseArgs(args);
}

EraseBlackboard::EraseBlackboard(const EraseBlackboard& a) : Behavior(a), param(a.param) {
}

EraseBlackboard& EraseBlackboard::operator=(const EraseBlackboard& a) {
	if (this == &a)
		return *this;
	Behavior::operator=(a);
	param = a.param;
	return *this;
}

void EraseBlackboard::parseArgs(const LuaObject& args) {
	param = getArg<String>()(args, "param");
}

Behavior::Status EraseBlackboard::execute(AiAgent* agent, unsigned int startIdx) const {
	agent->eraseBlackboard(param);
	return SUCCESS;
}

String EraseBlackboard::print() const {
	StringBuffer msg;
	msg << className << "-" << param;

	return msg.toString();
}

SelectAttack::SelectAttack(const String& className, const uint32 id, const LuaObject& args) : Behavior(className, id, args), attackNum(-1) {
	parseArgs(args);
}

SelectAttack::SelectAttack(const SelectAttack& a) : Behavior(a), attackNum(a.attackNum) {
}

SelectAttack& SelectAttack::operator=(const SelectAttack& a) {
	if (this == &a)
		return *this;
	Behavior::operator=(a);
	attackNum = a.attackNum;
	return *this;
}

void SelectAttack::parseArgs(const LuaObject& args) {
	attackNum = getArg<int>()(args, "attackNum", -1);
}

Behavior::Status SelectAttack::execute(AiAgent* agent, unsigned int startIdx) const {
	// agent->info("SelectAttack::execute", true);

	if (agent->isDead()) {
		return FAILURE;
	}

	WeaponObject* weapon = agent->getCurrentWeapon();

	if (weapon != nullptr && weapon->getAttackType() == SharedWeaponObjectTemplate::FORCEATTACK) {
		return agent->selectSpecialAttack(-1) ? SUCCESS : FAILURE;
	}

	if (agent->peekBlackboard("attackType")) {
		// agent->info("SelectAttack::execute has attackType", true);

		if (agent->readBlackboard("attackType").get<uint32>() == static_cast<uint32>(DataVal::DEFAULT)) {
			// agent->info("SelectAttack::execute has attackType DEFAULT", true);

			return agent->selectDefaultAttack() ? SUCCESS : FAILURE;
		}

		if (agent->readBlackboard("attackType").get<uint32>() == static_cast<uint32>(DataVal::RANDOM)) {
			// agent->info("SelectAttack::execute has attackType RANDOM", true);

			return agent->selectSpecialAttack(-1) ? SUCCESS : FAILURE;
		}
	}

	// agent->info("SelectAttack::execute has attackType attackNum", true);

	return agent->selectSpecialAttack(attackNum) ? SUCCESS : FAILURE;
}

String SelectAttack::print() const {
	StringBuffer msg;
	msg << className << "-" << attackNum;

	return msg.toString();
}

EnqueueAttack::EnqueueAttack(const String& className, const uint32 id, const LuaObject& args) : Behavior(className, id, args) {
}

EnqueueAttack::EnqueueAttack(const EnqueueAttack& a) : Behavior(a) {
}

EnqueueAttack& EnqueueAttack::operator=(const EnqueueAttack& a) {
	if (this == &a)
		return *this;
	Behavior::operator=(a);

	return *this;
}

Behavior::Status EnqueueAttack::execute(AiAgent* agent, unsigned int startIdx) const {
	// Using Normal (2) Priority
	int res = agent->enqueueAttack(2);
	Behavior::Status returnRes = FAILURE;

	if (!res)
		returnRes = SUCCESS;

	return returnRes;
}

String EnqueueAttack::print() const {
	StringBuffer msg;
	msg << className;

	return msg.toString();
}

FindNextPosition::FindNextPosition(const String& className, const uint32 id, const LuaObject& args) : Behavior(className, id, args) {
}

FindNextPosition::FindNextPosition(const FindNextPosition& a) : Behavior(a) {
}

Behavior::Status FindNextPosition::execute(AiAgent* agent, unsigned int startIdx) const {
	DataVal mode = DataVal::WALK;

	if (agent->peekBlackboard("moveMode"))
		mode = static_cast<DataVal>(agent->readBlackboard("moveMode").get<uint32>());

	uint32 movementState = agent->getMovementState();

	if (movementState == AiAgent::FOLLOWING) {
		return agent->findNextPosition(agent->getMaxDistance(), mode == DataVal::WALK) ? SUCCESS : FAILURE;
	}

	return agent->findNextPosition(agent->getMaxDistance(), mode == DataVal::WALK) ? RUNNING : SUCCESS;
}

Leash::Leash(const String& className, const uint32 id, const LuaObject& args) : Behavior(className, id, args) {
}

Leash::Leash(const Leash& a) : Behavior(a) {
}

Behavior::Status Leash::execute(AiAgent* agent, unsigned int startIdx) const {
	agent->leash();
	return SUCCESS;
}

Wait::Wait(const String& className, const uint32 id, const LuaObject& args) : Behavior(className, id, args), durationMin(-1), durationMax(-1) {
	parseArgs(args);
}

Wait::Wait(const Wait& a) : Behavior(a), durationMin(a.durationMin), durationMax(a.durationMax) {
}

Wait& Wait::operator=(const Wait& a) {
	if (this == &a)
		return *this;

	Behavior::operator=(a);

	durationMin = a.durationMin;
	durationMax = a.durationMax;

	return *this;
}

void Wait::parseArgs(const LuaObject& args) {
	durationMin = (int)(getArg<float>()(args, "durationMin") * 1000);
	durationMax = (int)(getArg<float>()(args, "durationMax") * 1000);
}

Behavior::Status Wait::execute(AiAgent* agent, unsigned int startIdx) const {
	// we don't need to check a value. Just checking to see if this value
	// exists on the blackboard is fine since it can never be false
	if (agent->isWaiting() || durationMin < 0) { // < 0 means indefinite wait
		return RUNNING;
	}

	uint64 totalWait = System::random(abs(durationMax - durationMin)) + durationMin;

	// agent->info(true) << "setting wait: " << totalWait << " Num of players in range: " << agent->getNumberOfPlayersInRange();

	agent->setWait(totalWait);
	agent->writeBlackboard("isWaiting", true);

	return SUCCESS;
}

String Wait::print() const {
	StringBuffer msg;
	msg << className << "- durationMin: " << durationMin << " durationMax: " << durationMax;

	return msg.toString();
}

SetAlert::SetAlert(const String& className, const uint32 id, const LuaObject& args) : Behavior(className, id, args), duration(0.f), show(true) {
	parseArgs(args);
}

SetAlert::SetAlert(const SetAlert& b) : Behavior(b), duration(b.duration), show(b.show) {
}

SetAlert& SetAlert::operator=(const SetAlert& b) {
	if (this == &b)
		return *this;
	Behavior::operator=(b);
	duration = b.duration;
	show = b.show;
	return *this;
}

Behavior::Status SetAlert::execute(AiAgent* agent, unsigned int startIdx) const {
	Time* alert = agent->getAlertedTime();

	if (alert == nullptr || !alert->isPast())
		return FAILURE;

	alert->updateToCurrentTime();
	alert->addMiliTime(duration);

	Time* delay = agent->getAggroDelay();
	if (delay != nullptr && delay->isPast()) {
		delay->updateToCurrentTime();
		uint32 newDelay = 5000;
		delay->addMiliTime(newDelay);
	}

	if (agent->getPosture() != CreaturePosture::UPRIGHT)
		agent->setPosture(CreaturePosture::UPRIGHT, true);

	ManagedReference<SceneObject*> target = nullptr;

	if (agent->peekBlackboard("targetProspect"))
		target = agent->readBlackboard("targetProspect").get<ManagedReference<SceneObject*>>().get();

	if (show && target != nullptr && target->isPlayerCreature()) {
		agent->showFlyText("npc_reaction/flytext", "alert", 255, 0, 0);

		if (agent->isNpc() && agent->getFaction() > 0 && agent->isAggressiveTo(target->asCreatureObject()))
			agent->doAnimation("search");

		agent->sendReactionChat(target, ReactionManager::ALERT);
	}

	return SUCCESS;
}

void SetAlert::parseArgs(const LuaObject& args) {
	duration = (int)(getArg<float>()(args, "duration") * 1000);
	show = getArg<bool>()(args, "show");
}

String SetAlert::print() const {
	StringBuffer msg;
	msg << className << "-" << duration << ":" << show;

	return msg.toString();
}

SetAttackPosture::SetAttackPosture(const String& className, const uint32 id, const LuaObject& args) : Behavior(className, id, args) {
}

SetAttackPosture::SetAttackPosture(const SetAttackPosture& b) : Behavior(b) {
}

SetAttackPosture& SetAttackPosture::operator=(const SetAttackPosture& b) {
	if (this == &b)
		return *this;
	Behavior::operator=(b);
	return *this;
}

Behavior::Status SetAttackPosture::execute(AiAgent* agent, unsigned int startIdx) const {
	Time* postureSet = agent->getPostureSet();

	if (postureSet == nullptr || !postureSet->isPast())
		return FAILURE;

	if (System::random(100) > 98 && !agent->isDizzied()) {
		WeaponObject* weapon = agent->getCurrentWeapon();

		if (weapon == nullptr || !weapon->isRangedWeapon())
			return FAILURE;

		ManagedReference<SceneObject*> target = nullptr;

		if (agent->peekBlackboard("targetProspect"))
			target = agent->readBlackboard("targetProspect").get<ManagedReference<SceneObject*>>().get();

		if (target == nullptr)
			return FAILURE;

		postureSet->updateToCurrentTime();
		postureSet->addMiliTime(20 * 1000);

		Locker clocker(target, agent);

		float sqrDist = agent->getPosition().squaredDistanceTo(target->getPosition());

		if (sqrDist > 25 * 25) {
			agent->enqueueCommand(STRING_HASHCODE("prone"), 0, 0, "");
		} else {
			agent->enqueueCommand(STRING_HASHCODE("kneel"), 0, 0, "");
		}
		return SUCCESS;
	}

	return FAILURE;
}

String SetAttackPosture::print() const {
	StringBuffer msg;
	msg << className;

	return msg.toString();
}

ContrabandScan::ContrabandScan(const String& className, const uint32 id, const LuaObject& args) : Behavior(className, id, args) {
}

ContrabandScan::ContrabandScan(const ContrabandScan& b) : Behavior(b) {
}

ContrabandScan& ContrabandScan::operator=(const ContrabandScan& b) {
	if (this == &b)
		return *this;
	Behavior::operator=(b);

	return *this;
}

Behavior::Status ContrabandScan::execute(AiAgent* agent, unsigned int startIdx) const {
	ManagedReference<SceneObject*> target = nullptr;

	if (agent->peekBlackboard("targetProspect"))
		target = agent->readBlackboard("targetProspect").get<ManagedReference<SceneObject*>>().get();

	if (target == nullptr)
		return FAILURE;

	if (!agent->checkCooldownRecovery("crackdown_scan"))
		return FAILURE;

	Zone* zone = agent->getZone();

	if (zone == nullptr)
		return FAILURE;

	GCWManager* gcwMan = zone->getGCWManager();

	if (gcwMan == nullptr)
		return FAILURE;

	Locker clocker(target, agent);

	return gcwMan->runCrackdownScan(agent, target->asCreatureObject()) ? SUCCESS : FAILURE;
}

String ContrabandScan::print() const {
	StringBuffer msg;
	msg << className;

	return msg.toString();
}

HealTarget::HealTarget(const String& className, const uint32 id, const LuaObject& args) : Behavior(className, id, args) {
}

HealTarget::HealTarget(const HealTarget& b) : Behavior(b) {
}

HealTarget& HealTarget::operator=(const HealTarget& b) {
	if (this == &b)
		return *this;
	Behavior::operator=(b);

	return *this;
}

Behavior::Status HealTarget::execute(AiAgent* agent, unsigned int startIdx) const {
	// agent->info(true) << "ID: " << agent->getObjectID() << "  SimpleAction - HealTarget called";

	ManagedReference<TangibleObject*> healTarget = nullptr;

	if (agent->peekBlackboard("healTarget")) {
		healTarget = agent->readBlackboard("healTarget").get<ManagedReference<TangibleObject*>>().get();
	}

	// Check if heal target exists
	if (healTarget == nullptr) {
		agent->eraseBlackboard("healTarget");
		agent->setMovementState(AiAgent::FOLLOWING);
		return FAILURE;
	}

	bool healExecuted = false;
	float range = 7.5f;
	uint32 healerType = agent->getHealerType().toLowerCase().hashCode();

	if (healerType == STRING_HASHCODE("force")) {
		range = 32.f;
	}

	// Creature Object heal target
	if (healTarget->isCreatureObject()) {
		// agent->info(true) << "ID: " << agent->getObjectID() << " healTarget is a creature -- Target: " << healTarget->getDisplayedName();

		auto healTargetCreO = healTarget->asCreatureObject();

		if (healTargetCreO == nullptr || healTargetCreO->isDead()) {
			agent->eraseBlackboard("healTarget");
			agent->setMovementState(AiAgent::FOLLOWING);

			return FAILURE;
		}

		if (healTargetCreO->getHAM(CreatureAttribute::HEALTH) < healTargetCreO->getMaxHAM(CreatureAttribute::HEALTH) || healTargetCreO->getHAM(CreatureAttribute::ACTION) < healTargetCreO->getMaxHAM(CreatureAttribute::ACTION)) {
			agent->clearQueueActions(true);

			if (healTargetCreO == agent) {
				agent->healCreatureTarget(healTargetCreO);
				healExecuted = true;
			} else if (agent->isInRange(healTarget, range)) {
				Locker clocker(healTargetCreO, agent);

				agent->healCreatureTarget(healTargetCreO);

				healExecuted = true;
			}
		}
		// Tangible Object heal target (Lairs, etc)
	} else {
		// agent->info(true) << "ID: " << agent->getObjectID() << " healTarget is a Tangible Object -- Target: " << healTarget->getDisplayedName();

		if (healTarget->getZone() == nullptr || healTarget->getConditionDamage() < 1) {
			agent->eraseBlackboard("healTarget");
			agent->setMovementState(AiAgent::FOLLOWING);

			return FAILURE;
		}

		if (agent->isInRange(healTarget, 2.0f)) {
			Locker clocker(healTarget, agent);

			agent->healTangibleTarget(healTarget);

			healExecuted = true;
		}
	}

	if (healExecuted == true) {
		Time* healDelay = agent->getHealDelay();

		if (healDelay != nullptr) {
			healDelay->updateToCurrentTime();
			healDelay->addMiliTime(20 * 1000);
		}

		agent->eraseBlackboard("healTarget");
	}

	return SUCCESS;
}

String HealTarget::print() const {
	StringBuffer msg;
	msg << className;

	return msg.toString();
}

SendChatGreeting::SendChatGreeting(const String& className, const uint32 id, const LuaObject& args) : Behavior(className, id, args) {
}

SendChatGreeting::SendChatGreeting(const SendChatGreeting& b) : Behavior(b) {
}

SendChatGreeting& SendChatGreeting::operator=(const SendChatGreeting& b) {
	if (this == &b)
		return *this;
	Behavior::operator=(b);

	return *this;
}

Behavior::Status SendChatGreeting::execute(AiAgent* agent, unsigned int startIdx) const {
	ManagedReference<SceneObject*> target = nullptr;

	if (agent->peekBlackboard("targetProspect"))
		target = agent->readBlackboard("targetProspect").get<ManagedReference<SceneObject*>>().get();

	if (target == nullptr || !target->isPlayerCreature()) {
		return FAILURE;
	}

	CreatureObject* creoTarget = target->asCreatureObject();

	if (creoTarget == nullptr || (creoTarget->getCurrentSpeed() < creoTarget->getWalkSpeed() * 0.5))
		return FAILURE;

	Locker clocker(target, agent);

	if (!agent->hasReactionChatMessages() || agent->getParentUnsafe() != target->getParentUnsafe())
		return FAILURE;

	float sqrDist = agent->getWorldPosition().squaredDistanceTo(target->getWorldPosition());

	if (sqrDist > 35 * 35 || sqrDist < 25 * 25) // Between 35m and 25m
		return FAILURE;

	if (!(agent->getCreatureBitmask() & ObjectFlag::STATIC))
		agent->faceObject(target, true);

	if (target->isFacingObject(agent))
		agent->sendReactionChat(target, ReactionManager::HI);
	else
		agent->sendReactionChat(target, ReactionManager::BYE);

	return SUCCESS;
}

String SendChatGreeting::print() const {
	StringBuffer msg;
	msg << className;

	return msg.toString();
}

CallForHelp::CallForHelp(const String& className, const uint32 id, const LuaObject& args) : Behavior(className, id, args) {
}

CallForHelp::CallForHelp(const CallForHelp& b) : Behavior(b) {
}

CallForHelp& CallForHelp::operator=(const CallForHelp& b) {
	if (this == &b)
		return *this;
	Behavior::operator=(b);

	return *this;
}

Behavior::Status CallForHelp::execute(AiAgent* agent, unsigned int startIdx) const {
	ManagedReference<SceneObject*> ally = nullptr;

	if (agent->peekBlackboard("allyProspect"))
		ally = agent->readBlackboard("allyProspect").get<ManagedReference<SceneObject*>>().get();

	if (ally == nullptr) {
		agent->eraseBlackboard("allyProspect");
		return FAILURE;
	}

	CreatureObject* allyCreo = ally->asCreatureObject();

	if (allyCreo == nullptr || allyCreo->isDead() || !allyCreo->isAiAgent()) {
		agent->eraseBlackboard("allyProspect");
		return FAILURE;
	}

	Locker clock(allyCreo, agent);

	Vector3 agentPosition = agent->getPosition();
	Vector3 allyPosition = allyCreo->getPosition();

	float sqrDistance = agentPosition.squaredDistanceTo(allyPosition);

	if (sqrDistance > 50 * 50) {
		agent->eraseBlackboard("allyProspect");
		return FAILURE;
	}

#ifdef DEBUG_CALLFORHELP
	ZoneServer* zoneServer = agent->getZoneServer();

	ChatManager* chatManager = nullptr;

	if (zoneServer != nullptr)
		chatManager = zoneServer->getChatManager();
#endif

	agent->clearPatrolPoints();
	agent->faceObject(ally, true);

	agent->setMovementState(AiAgent::NOTIFY_ALLY);
	agent->setNextPosition(allyPosition.getX(), allyPosition.getZ(), allyPosition.getY(), allyCreo->getParent().get().castTo<CellObject*>());

#ifdef DEBUG_CALLFORHELP
	if (chatManager != nullptr)
		chatManager->broadcastChatMessage(agent, "Heading to notify my ally", 0, 0, agent->getMoodID());
#endif

	AiAgent* allyAgent = allyCreo->asAiAgent();

	if (allyAgent == nullptr) {
		agent->eraseBlackboard("allyProspect");
		return FAILURE;
	}

	Time* allyTime = allyAgent->getLastCallForHelp();

	if (allyTime != nullptr) {
		allyTime->updateToCurrentTime();
		allyTime->addMiliTime(90 * 1000);
	}

	if (sqrDistance < 10 * 10) {
		Time* callForHelp = agent->getLastCallForHelp();

		if (callForHelp == nullptr)
			return FAILURE;

		callForHelp->updateToCurrentTime();
		callForHelp->addMiliTime(90 * 1000);

		ManagedReference<SceneObject*> enemyTarget = nullptr;

		if (agent->peekBlackboard("targetProspect"))
			enemyTarget = agent->readBlackboard("targetProspect").get<ManagedReference<SceneObject*>>().get();

		if (enemyTarget != nullptr) {
#ifdef DEBUG_CALLFORHELP
			if (chatManager != nullptr)
				chatManager->broadcastChatMessage(agent, "Notifying my ally", 0, 0, agent->getMoodID());
#endif

			Core::getTaskManager()->executeTask(
				[allyAgent, enemyTarget]() {
					Locker lock(allyAgent);
					Locker enlocker(enemyTarget, allyAgent);

					allyAgent->addDefender(enemyTarget);
				},
				"CallForHelpLambda");
		}

		agent->eraseBlackboard("allyProspect");
		agent->setMovementState(AiAgent::FOLLOWING);
	}

	return SUCCESS;
}

String CallForHelp::print() const {
	StringBuffer msg;
	msg << className;

	return msg.toString();
}

Rest::Rest(const String& className, const uint32 id, const LuaObject& args) : Behavior(className, id, args) {
}

Rest::Rest(const Rest& a) : Behavior(a) {
}

Rest& Rest::operator=(const Rest& a) {
	if (this == &a)
		return *this;
	Behavior::operator=(a);
	return *this;
}

Behavior::Status Rest::execute(AiAgent* agent, unsigned int startIdx) const {
	if (agent == nullptr)
		return FAILURE;

	Time* restDelay = agent->getRestDelay();

	if (restDelay == nullptr) {
		return FAILURE;
	}

	// Wait 5 minutes until we check if we should rest again
	int delay = 300 * 1000;

	restDelay->updateToCurrentTime();
	restDelay->addMiliTime(delay);

	agent->setMovementState(AiAgent::RESTING);

	// Chance to stop resting from 45s up to 2 minutes stored in ms
	int restingTime = delay - ((45 + System::random(45)) * 1000);
	agent->writeBlackboard("restingTime", restingTime);

	int speciesID = agent->getSpecies();
	bool canSitDown = false;

	Zone* zone = agent->getZone();

	// We are returning Success here since we have the state and delays set
	if (zone == nullptr)
		return SUCCESS;

	ManagedReference<CreatureManager*> creoManager = zone->getCreatureManager();

	if (creoManager != nullptr) {
		AiSpeciesData* speciesData = creoManager->getAiSpeciesData(speciesID);

		if (speciesData != nullptr) {
			canSitDown = speciesData->canSitDown();
		}
	}

	if (agent->isNpc() || (canSitDown && System::random(2) > 0)) {
		agent->setPosture(CreaturePosture::SITTING, true);
	} else {
		agent->setPosture(CreaturePosture::LYINGDOWN, true);
	}

	return SUCCESS;
}

String Rest::print() const {
	StringBuffer msg;
	msg << className;

	return msg.toString();
}

StopResting::StopResting(const String& className, const uint32 id, const LuaObject& args) : Behavior(className, id, args) {
}

StopResting::StopResting(const StopResting& a) : Behavior(a) {
}

StopResting& StopResting::operator=(const StopResting& a) {
	if (this == &a)
		return *this;
	Behavior::operator=(a);
	return *this;
}

Behavior::Status StopResting::execute(AiAgent* agent, unsigned int startIdx) const {
	if (agent == nullptr)
		return FAILURE;

	agent->setPosture(CreaturePosture::UPRIGHT, true);
	agent->setMovementState(AiAgent::PATROLLING);

	return SUCCESS;
}

String StopResting::print() const {
	StringBuffer msg;
	msg << className;

	return msg.toString();
}

RestHerd::RestHerd(const String& className, const uint32 id, const LuaObject& args) : Behavior(className, id, args) {
}

RestHerd::RestHerd(const RestHerd& a) : Behavior(a) {
}

RestHerd& RestHerd::operator=(const RestHerd& a) {
	if (this == &a)
		return *this;
	Behavior::operator=(a);
	return *this;
}

Behavior::Status RestHerd::execute(AiAgent* agent, unsigned int startIdx) const {
	if (agent == nullptr)
		return FAILURE;

	ManagedReference<CreatureHerdObserver*> herdObserver = agent->getHerdObserver();

	if (herdObserver == nullptr)
		return FAILURE;

	// Set rest delay on the leader (calling agent)
	Time* restDelay = agent->getRestDelay();

	if (restDelay == nullptr)
		return FAILURE;

	// Wait 5 minutes until we check if we should rest again
	int delay = 300 * 1000;

	restDelay->updateToCurrentTime();
	restDelay->addMiliTime(delay);

	return herdObserver->restHerd() ? SUCCESS : FAILURE;
}

String RestHerd::print() const {
	StringBuffer msg;
	msg << className;

	return msg.toString();
}

StopHerdRest::StopHerdRest(const String& className, const uint32 id, const LuaObject& args) : Behavior(className, id, args) {
}

StopHerdRest::StopHerdRest(const StopHerdRest& a) : Behavior(a) {
}

StopHerdRest& StopHerdRest::operator=(const StopHerdRest& a) {
	if (this == &a)
		return *this;
	Behavior::operator=(a);
	return *this;
}

Behavior::Status StopHerdRest::execute(AiAgent* agent, unsigned int startIdx) const {
	if (agent == nullptr)
		return FAILURE;

	ManagedReference<CreatureHerdObserver*> herdObserver = agent->getHerdObserver();

	if (herdObserver == nullptr)
		return FAILURE;

	return herdObserver->stopHerdRest() ? SUCCESS : FAILURE;
}

String StopHerdRest::print() const {
	StringBuffer msg;
	msg << className;

	return msg.toString();
}
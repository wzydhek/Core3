#include "SimpleActionsSpace.h"

DummySpace::DummySpace(const String& className, const uint32 id, const LuaObject& args) : BehaviorSpace(className, id, args) {
}

DummySpace::DummySpace(const DummySpace& d) : BehaviorSpace(d) {
}

BehaviorSpace::Status DummySpace::execute(ShipAiAgent*, unsigned int) const {
	return SUCCESS; // this is meant to be decorated with AlwaysXX, so this return won't matter.
}

FindNextPosition::FindNextPosition(const String& className, const uint32 id, const LuaObject& args) : BehaviorSpace(className, id, args) {
}

FindNextPosition::FindNextPosition(const FindNextPosition& a) : BehaviorSpace(a) {
}

BehaviorSpace::Status FindNextPosition::execute(ShipAiAgent* agent, unsigned int startIdx) const {
	uint32 movementState = agent->getMovementState();

	if (movementState == ShipAiAgent::FOLLOWING || movementState == ShipAiAgent::ATTACKING) {
		return agent->findNextPosition(agent->getMaxDistance()) ? SUCCESS : FAILURE;
	}

	return agent->findNextPosition(agent->getMaxDistance()) ? RUNNING : SUCCESS;
}

Wait::Wait(const String& className, const uint32 id, const LuaObject& args) : BehaviorSpace(className, id, args), duration(-1) {
	parseArgs(args);
}

Wait::Wait(const Wait& a) : BehaviorSpace(a), duration(a.duration) {
}

Wait& Wait::operator=(const Wait& a) {
	if (this == &a)
		return *this;

	BehaviorSpace::operator=(a);
	duration = a.duration;

	return *this;
}

void Wait::parseArgs(const LuaObject& args) {
	duration = (int)(getArg<float>()(args, "duration") * 1000);
}

BehaviorSpace::Status Wait::execute(ShipAiAgent* agent, unsigned int startIdx) const {
	// we don't need to check a value. Just checking to see if this value
	// exists on the blackboard is fine since it can never be false
	if (agent->peekBlackboard("isWaiting")) {
		if (agent->isWaiting() || duration < 0) // < 0 means indefinite wait
			return RUNNING;
		else {
			agent->eraseBlackboard("isWaiting");
			return SUCCESS;
		}
	}

	agent->setWait(duration);
	agent->writeBlackboard("isWaiting", true);

	return RUNNING;
}

String Wait::print() const {
	StringBuffer msg;
	msg << className << "-" << duration;

	return msg.toString();
}

GeneratePatrol::GeneratePatrol(const String& className, const uint32 id, const LuaObject& args) : BehaviorSpace(className, id, args), numPoints(0), distFromHome(0.0) {
	parseArgs(args);
}

GeneratePatrol::GeneratePatrol(const GeneratePatrol& a) : BehaviorSpace(a), numPoints(a.numPoints), distFromHome(a.distFromHome) {
}

GeneratePatrol& GeneratePatrol::operator=(const GeneratePatrol& a) {
	if (this == &a)
		return *this;
	BehaviorSpace::operator=(a);
	numPoints = a.numPoints;
	distFromHome = a.distFromHome;
	return *this;
}

void GeneratePatrol::parseArgs(const LuaObject& args) {
	numPoints = getArg<int>()(args, "numPoints");
	distFromHome = getArg<float>()(args, "distFromHome");
}

BehaviorSpace::Status GeneratePatrol::execute(ShipAiAgent* agent, unsigned int startIdx) const {
	return agent->generatePatrol(numPoints, distFromHome) ? SUCCESS : FAILURE;
}

String GeneratePatrol::print() const {
	StringBuffer msg;
	msg << className << "-" << numPoints << ":" << distFromHome;

	return msg.toString();
}

ExitCombat::ExitCombat(const String& className, const uint32 id, const LuaObject& args) : BehaviorSpace(className, id, args) {
}

ExitCombat::ExitCombat(const ExitCombat& a) : BehaviorSpace(a) {
}

ExitCombat& ExitCombat::operator=(const ExitCombat& a) {
	if (this == &a)
		return *this;
	BehaviorSpace::operator=(a);
	return *this;
}

BehaviorSpace::Status ExitCombat::execute(ShipAiAgent* agent, unsigned int startIdx) const {
	agent->removeDefenders();
	agent->setTargetShipObject(nullptr);

	return SUCCESS;
}

String ExitCombat::print() const {
	StringBuffer msg;
	msg << className << "- called";

	return msg.toString();
}

WriteBlackboard::WriteBlackboard(const String& className, const uint32 id, const LuaObject& args) : BehaviorSpace(className, id, args) {
	parseArgs(args);
}

WriteBlackboard::WriteBlackboard(const WriteBlackboard& a) : BehaviorSpace(a), key(a.key), val(a.val) {
}

WriteBlackboard& WriteBlackboard::operator=(const WriteBlackboard& a) {
	if (this == &a)
		return *this;
	BehaviorSpace::operator=(a);
	key = a.key;
	val = a.val;
	return *this;
}

void WriteBlackboard::parseArgs(const LuaObject& args) {
	key = getArg<String>()(args, "key");
	val = getArg<uint32>()(args, "val");
}

BehaviorSpace::Status WriteBlackboard::execute(ShipAiAgent* agent, unsigned int startIdx) const {
	agent->writeBlackboard(key, val);

	return SUCCESS;
}

String WriteBlackboard::print() const {
	StringBuffer msg;
	msg << className << "-" << key << ":" << val;

	return msg.toString();
}

WriteBlackboardFloat::WriteBlackboardFloat(const String& className, const uint32 id, const LuaObject& args) : BehaviorSpace(className, id, args) {
	parseArgs(args);
}

WriteBlackboardFloat::WriteBlackboardFloat(const WriteBlackboardFloat& a) : BehaviorSpace(a), key(a.key), val(a.val) {
}

WriteBlackboardFloat& WriteBlackboardFloat::operator=(const WriteBlackboardFloat& a) {
	if (this == &a) {
		return *this;
	}

	BehaviorSpace::operator=(a);
	key = a.key;
	val = a.val;

	return *this;
}

void WriteBlackboardFloat::parseArgs(const LuaObject& args) {
	key = getArg<String>()(args, "key");
	val = getArg<float>()(args, "val");
}

BehaviorSpace::Status WriteBlackboardFloat::execute(ShipAiAgent* agent, unsigned int startIdx) const {
	agent->writeBlackboard(key, val);

	return SUCCESS;
}

String WriteBlackboardFloat::print() const {
	StringBuffer msg;
	msg << className << "-" << key << ":" << val;

	return msg.toString();
}

EraseBlackboard::EraseBlackboard(const String& className, const uint32 id, const LuaObject& args) : BehaviorSpace(className, id, args), param("") {
	parseArgs(args);
}

EraseBlackboard::EraseBlackboard(const EraseBlackboard& a) : BehaviorSpace(a), param(a.param) {
}

EraseBlackboard& EraseBlackboard::operator=(const EraseBlackboard& a) {
	if (this == &a)
		return *this;
	BehaviorSpace::operator=(a);
	param = a.param;
	return *this;
}

void EraseBlackboard::parseArgs(const LuaObject& args) {
	param = getArg<String>()(args, "param");
}

BehaviorSpace::Status EraseBlackboard::execute(ShipAiAgent* agent, unsigned int startIdx) const {
	agent->eraseBlackboard(param);
	return SUCCESS;
}

String EraseBlackboard::print() const {
	StringBuffer msg;
	msg << className << "-" << param;

	return msg.toString();
}

Leash::Leash(const String& className, const uint32 id, const LuaObject& args) : BehaviorSpace(className, id, args) {
}

Leash::Leash(const Leash& a) : BehaviorSpace(a) {
}

BehaviorSpace::Status Leash::execute(ShipAiAgent* agent, unsigned int startIdx) const {
	agent->leash();

	return SUCCESS;
}

SetAlert::SetAlert(const String& className, const uint32 id, const LuaObject& args) : BehaviorSpace(className, id, args), aggroDelay(0.f) {
	parseArgs(args);
}

SetAlert::SetAlert(const SetAlert& b) : BehaviorSpace(b), aggroDelay(b.aggroDelay) {
}

SetAlert& SetAlert::operator=(const SetAlert& b) {
	if (this == &b)
		return *this;

	BehaviorSpace::operator=(b);

	aggroDelay = b.aggroDelay;
	return *this;
}

BehaviorSpace::Status SetAlert::execute(ShipAiAgent* agent, unsigned int startIdx) const {
	Time* alert = agent->getAlertedTime();

	if (alert == nullptr || !alert->isPast())
		return FAILURE;

	alert->updateToCurrentTime();
	alert->addMiliTime(duration);

	Time* delay = agent->getAggroDelay();

	if (delay != nullptr && delay->isPast()) {
		delay->updateToCurrentTime();
		delay->addMiliTime(aggroDelay);
		// agent->info(true) << " SetAlert Complete! Delay: " << aggroDelay;
	}

	return SUCCESS;
}

void SetAlert::parseArgs(const LuaObject& args) {
	aggroDelay = (int)(getArg<float>()(args, "aggroDelay") * 1000);
}

String SetAlert::print() const {
	StringBuffer msg;
	msg << className << "- Aggro Delay: " << aggroDelay;

	return msg.toString();
}

SetDisabledEngineSpeed::SetDisabledEngineSpeed(const String& className, const uint32 id, const LuaObject& args) : BehaviorSpace(className, id, args) {
}

SetDisabledEngineSpeed::SetDisabledEngineSpeed(const FindNextPosition& a) : BehaviorSpace(a) {
}

BehaviorSpace::Status SetDisabledEngineSpeed::execute(ShipAiAgent* agent, unsigned int startIdx) const {
	return agent->setDisabledEngineSpeed() ? RUNNING : SUCCESS;
}

UpdateHomePosition::UpdateHomePosition(const String& className, const uint32 id, const LuaObject& args) : BehaviorSpace(className, id, args) {
	parseArgs(args);
}

UpdateHomePosition::UpdateHomePosition(const UpdateHomePosition& a) : BehaviorSpace(a) {
}

void UpdateHomePosition::parseArgs(const LuaObject& args) {
	useTargetPosition = getArg<bool>()(args, "useTargetPosition");
}

BehaviorSpace::Status UpdateHomePosition::execute(ShipAiAgent* agent, unsigned int startIdx) const {
	uint32 shipFlag = agent->getShipBitmask();

	auto newHome = agent->getPosition();

	if (useTargetPosition) {
		ManagedReference<ShipObject*> targetShip = agent->getTargetShipObject().get();

		if (targetShip != nullptr) {
			Locker clock(targetShip, agent);

			newHome = targetShip->getPosition();
		}
	}

	agent->setHomeLocation(newHome.getX(), newHome.getZ(), newHome.getY(), Quaternion::IDENTITY);

	return SUCCESS;
}
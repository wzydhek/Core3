#pragma once

#include "server/zone/objects/creature/ai/bt/Behavior.h"
#include "server/zone/objects/creature/ai/bt/BlackboardData.h"
#include "server/zone/objects/creature/ai/AiAgent.h"
#include "server/zone/managers/gcw/GCWManager.h"
#include "server/zone/managers/reaction/ReactionManager.h"
#include "server/zone/managers/creature/observers/CreatureHerdObserver.h"

namespace server {
namespace zone {
namespace objects {
namespace creature {
namespace ai {
namespace bt {
namespace leaf {

class Dummy : public Behavior {
public:
	Dummy(const String& className, const uint32 id, const LuaObject& args);

	Dummy(const Dummy& d);

	Behavior::Status execute(AiAgent*, unsigned int) const;
};

class GeneratePatrol : public Behavior {
public:
	GeneratePatrol(const String& className, const uint32 id, const LuaObject& args);

	GeneratePatrol(const GeneratePatrol& a);

	GeneratePatrol& operator=(const GeneratePatrol& a);

	void parseArgs(const LuaObject& args);

	Behavior::Status execute(AiAgent* agent, unsigned int startIdx = 0) const;

	String print() const;

private:
	int numPoints;
	float distFromHome;
};

class ExitCombat : public Behavior {
public:
	ExitCombat(const String& className, const uint32 id, const LuaObject& args);

	ExitCombat(const ExitCombat& a);

	ExitCombat& operator=(const ExitCombat& a);

	void parseArgs(const LuaObject& args);

	Behavior::Status execute(AiAgent* agent, unsigned int startIdx = 0) const;

	String print() const;

private:
	bool clearDefenders;
};

class EquipStagedWeapon : public Behavior {
public:
	EquipStagedWeapon(const String& className, const uint32 id, const LuaObject& args);

	EquipStagedWeapon(const EquipStagedWeapon& a);

	Behavior::Status execute(AiAgent* agent, unsigned int startIdx = 0) const;
};

class WriteBlackboard : public Behavior {
public:
	WriteBlackboard(const String& className, const uint32 id, const LuaObject& args);

	WriteBlackboard(const WriteBlackboard& a);

	WriteBlackboard& operator=(const WriteBlackboard& a);

	void parseArgs(const LuaObject& args);

	Behavior::Status execute(AiAgent* agent, unsigned int startIdx = 0) const;

	String print() const;

private:
	String key;
	uint32 val;
};

class EraseBlackboard : public Behavior {
public:
	EraseBlackboard(const String& className, const uint32 id, const LuaObject& args);

	EraseBlackboard(const EraseBlackboard& a);

	EraseBlackboard& operator=(const EraseBlackboard& a);

	void parseArgs(const LuaObject& args);

	Behavior::Status execute(AiAgent* agent, unsigned int startIdx = 0) const;

	String print() const;

private:
	String param;
};

class SelectAttack : public Behavior {
public:
	SelectAttack(const String& className, const uint32 id, const LuaObject& args);

	SelectAttack(const SelectAttack& a);

	SelectAttack& operator=(const SelectAttack& a);

	void parseArgs(const LuaObject& args);

	Behavior::Status execute(AiAgent* agent, unsigned int startIdx = 0) const;

	String print() const;

private:
	int attackNum;
};

class EnqueueAttack : public Behavior {
public:
	EnqueueAttack(const String& className, const uint32 id, const LuaObject& args);

	EnqueueAttack(const EnqueueAttack& a);

	EnqueueAttack& operator=(const EnqueueAttack& a);

	Behavior::Status execute(AiAgent* agent, unsigned int startIdx = 0) const;

	String print() const;

};

class FindNextPosition : public Behavior {
public:
	FindNextPosition(const String& className, const uint32 id, const LuaObject& args);

	FindNextPosition(const FindNextPosition& a);

	Behavior::Status execute(AiAgent* agent, unsigned int startIdx = 0) const;
};

class Leash : public Behavior {
public:
	Leash(const String& className, const uint32 id, const LuaObject& args);

	Leash(const Leash& a);

	Behavior::Status execute(AiAgent* agent, unsigned int startIdx = 0) const;
};

class Wait : public Behavior {
public:
	Wait(const String& className, const uint32 id, const LuaObject& args);

	Wait(const Wait& a);

	Wait& operator=(const Wait& a);

	void parseArgs(const LuaObject& args);

	Behavior::Status execute(AiAgent* agent, unsigned int startIdx = 0) const;

	String print() const;

private:
	int durationMin;
	int durationMax;
};

class SetAlert : public Behavior {
public:
	SetAlert(const String& className, const uint32 id, const LuaObject& args);

	SetAlert(const SetAlert& b);

	SetAlert& operator=(const SetAlert& b);

	Behavior::Status execute(AiAgent* agent, unsigned int startIdx = 0) const;

	void parseArgs(const LuaObject& args);

	String print() const;

private:
	int duration;
	bool show;
};

class SetAttackPosture : public Behavior {
public:
	SetAttackPosture(const String& className, const uint32 id, const LuaObject& args);

	SetAttackPosture(const SetAttackPosture& b);

	SetAttackPosture& operator=(const SetAttackPosture& b);

	Behavior::Status execute(AiAgent* agent, unsigned int startIdx = 0) const;

	String print() const;
};

class ContrabandScan : public Behavior {
public:
	ContrabandScan(const String& className, const uint32 id, const LuaObject& args);

	ContrabandScan(const ContrabandScan& b);

	ContrabandScan& operator=(const ContrabandScan& b);

	Behavior::Status execute(AiAgent* agent, unsigned int startIdx = 0) const;

	String print() const;

};

class HealTarget : public Behavior {
public:
	HealTarget(const String& className, const uint32 id, const LuaObject& args);

	HealTarget(const HealTarget& b);

	HealTarget& operator=(const HealTarget& b);

	Behavior::Status execute(AiAgent* agent, unsigned int startIdx = 0) const;

	String print() const;
};

class SendChatGreeting : public Behavior {
public:
	SendChatGreeting(const String& className, const uint32 id, const LuaObject& args);

	SendChatGreeting(const SendChatGreeting& b);

	SendChatGreeting& operator=(const SendChatGreeting& b);

	Behavior::Status execute(AiAgent* agent, unsigned int startIdx = 0) const;

	String print() const;
};

class CallForHelp : public Behavior {
public:
	CallForHelp(const String& className, const uint32 id, const LuaObject& args);

	CallForHelp(const CallForHelp& b);

	CallForHelp& operator=(const CallForHelp& b);

	Behavior::Status execute(AiAgent* agent, unsigned int startIdx = 0) const;

	String print() const;
};

class Rest : public Behavior {
public:
	Rest(const String& className, const uint32 id, const LuaObject& args);

	Rest(const Rest& a);

	Rest& operator=(const Rest& a);

	Behavior::Status execute(AiAgent* agent, unsigned int startIdx = 0) const;

	String print() const;
};

class StopResting : public Behavior {
public:
	StopResting(const String& className, const uint32 id, const LuaObject& args);

	StopResting(const StopResting& a);

	StopResting& operator=(const StopResting& a);

	Behavior::Status execute(AiAgent* agent, unsigned int startIdx = 0) const;

	String print() const;
};

class RestHerd : public Behavior {
public:
	RestHerd(const String& className, const uint32 id, const LuaObject& args);

	RestHerd(const RestHerd& a);

	RestHerd& operator=(const RestHerd& a);

	Behavior::Status execute(AiAgent* agent, unsigned int startIdx = 0) const;

	String print() const;
};

class StopHerdRest : public Behavior {
public:
	StopHerdRest(const String& className, const uint32 id, const LuaObject& args);

	StopHerdRest(const StopHerdRest& a);

	StopHerdRest& operator=(const StopHerdRest& a);

	Behavior::Status execute(AiAgent* agent, unsigned int startIdx = 0) const;

	String print() const;
};


}
}
}
}
}
}
}

using namespace server::zone::objects::creature::ai::bt::leaf;

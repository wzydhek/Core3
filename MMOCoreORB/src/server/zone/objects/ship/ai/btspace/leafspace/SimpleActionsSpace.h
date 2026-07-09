#pragma once

#include "server/zone/objects/ship/ai/btspace/BehaviorSpace.h"
#include "server/zone/objects/ship/ai/btspace/BlackboardDataSpace.h"
#include "server/zone/objects/ship/ai/ShipAiAgent.h"

namespace server {
namespace zone {
namespace objects {
namespace ship {
namespace ai {
namespace btspace {
namespace leafspace {

class DummySpace : public BehaviorSpace {
public:
	DummySpace(const String& className, const uint32 id, const LuaObject& args);

	DummySpace(const DummySpace& d);

	BehaviorSpace::Status execute(ShipAiAgent*, unsigned int) const;
};

class FindNextPosition : public BehaviorSpace {
public:
	FindNextPosition(const String& className, const uint32 id, const LuaObject& args);

	FindNextPosition(const FindNextPosition& a);

	BehaviorSpace::Status execute(ShipAiAgent* agent, unsigned int startIdx = 0) const;
};

class Wait : public BehaviorSpace {
public:
	Wait(const String& className, const uint32 id, const LuaObject& args);

	Wait(const Wait& a);

	Wait& operator=(const Wait& a);

	void parseArgs(const LuaObject& args);

	BehaviorSpace::Status execute(ShipAiAgent* agent, unsigned int startIdx = 0) const;

	String print() const;

private:
	int duration;
};

class GeneratePatrol : public BehaviorSpace {
public:
	GeneratePatrol(const String& className, const uint32 id, const LuaObject& args);

	GeneratePatrol(const GeneratePatrol& a);

	GeneratePatrol& operator=(const GeneratePatrol& a);

	void parseArgs(const LuaObject& args);

	BehaviorSpace::Status execute(ShipAiAgent* agent, unsigned int startIdx = 0) const;

	String print() const;

private:
	int numPoints;
	float distFromHome;
};


class ExitCombat : public BehaviorSpace {
public:
	ExitCombat(const String& className, const uint32 id, const LuaObject& args);

	ExitCombat(const ExitCombat& a);

	ExitCombat& operator=(const ExitCombat& a);

	BehaviorSpace::Status execute(ShipAiAgent* agent, unsigned int startIdx = 0) const;

	String print() const;
};

class WriteBlackboard : public BehaviorSpace {
public:
	WriteBlackboard(const String& className, const uint32 id, const LuaObject& args);

	WriteBlackboard(const WriteBlackboard& a);

	WriteBlackboard& operator=(const WriteBlackboard& a);

	void parseArgs(const LuaObject& args);

	BehaviorSpace::Status execute(ShipAiAgent* agent, unsigned int startIdx = 0) const;

	String print() const;

private:
	String key;
	uint32 val;
};

class WriteBlackboardFloat : public BehaviorSpace {
public:
	WriteBlackboardFloat(const String& className, const uint32 id, const LuaObject& args);

	WriteBlackboardFloat(const WriteBlackboardFloat& a);

	WriteBlackboardFloat& operator=(const WriteBlackboardFloat& a);

	void parseArgs(const LuaObject& args);

	BehaviorSpace::Status execute(ShipAiAgent* agent, unsigned int startIdx = 0) const;

	String print() const;

private:
	String key;
	float val;
};

class EraseBlackboard : public BehaviorSpace {
public:
	EraseBlackboard(const String& className, const uint32 id, const LuaObject& args);

	EraseBlackboard(const EraseBlackboard& a);

	EraseBlackboard& operator=(const EraseBlackboard& a);

	void parseArgs(const LuaObject& args);

	BehaviorSpace::Status execute(ShipAiAgent* agent, unsigned int startIdx = 0) const;

	String print() const;

private:
	String param;
};

class Leash : public BehaviorSpace {
public:
	Leash(const String& className, const uint32 id, const LuaObject& args);

	Leash(const Leash& a);

	BehaviorSpace::Status execute(ShipAiAgent* agent, unsigned int startIdx = 0) const;
};

class SetAlert : public BehaviorSpace {
public:
	SetAlert(const String& className, const uint32 id, const LuaObject& args);

	SetAlert(const SetAlert& b);

	SetAlert& operator=(const SetAlert& b);

	BehaviorSpace::Status execute(ShipAiAgent* agent, unsigned int startIdx = 0) const;

	void parseArgs(const LuaObject& args);

	String print() const;

private:
	int duration;
	int aggroDelay;
};

class SetDisabledEngineSpeed : public BehaviorSpace {
public:
	SetDisabledEngineSpeed(const String& className, const uint32 id, const LuaObject& args);

	SetDisabledEngineSpeed(const FindNextPosition& a);

	BehaviorSpace::Status execute(ShipAiAgent* agent, unsigned int startIdx = 0) const;
};

class UpdateHomePosition : public BehaviorSpace {
	public:
	UpdateHomePosition(const String& className, const uint32 id, const LuaObject& args);

		UpdateHomePosition(const UpdateHomePosition& a);

		void parseArgs(const LuaObject& args);

		BehaviorSpace::Status execute(ShipAiAgent* agent, unsigned int startIdx = 0) const;

	private:
		bool useTargetPosition;
};

} // namespace leafspace
} // namespace btspace
} // namespace ai
} // namespace ship
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::ship::ai::btspace::leafspace;

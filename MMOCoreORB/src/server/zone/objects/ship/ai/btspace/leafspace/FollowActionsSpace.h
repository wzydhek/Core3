#pragma once

#include "server/zone/objects/ship/ai/ShipAiAgent.h"
#include "server/zone/objects/ship/ai/btspace/BehaviorSpace.h"
#include "server/zone/objects/ship/ai/btspace/BlackboardDataSpace.h"
#include "server/zone/SpaceZone.h"
#include "templates/faction/Factions.h"
#include "server/zone/managers/spacecombat/SpaceCombatManager.h"
#include "server/zone/managers/spacecollision/SpaceCollisionManager.h"
#include "server/zone/objects/tangible/threat/ThreatMap.h"
#include "server/zone/objects/ship/ShipComponentFlag.h"

namespace server {
namespace zone {
namespace objects {
namespace ship {
namespace ai {
namespace btspace {
namespace leafspace {

class CalculateAggroMod : public BehaviorSpace {
public:
	CalculateAggroMod(const String& className, const uint32 id, const LuaObject& args);

	BehaviorSpace::Status execute(ShipAiAgent* agent, unsigned int startIdx = 0) const;
};

class SetMovementState : public BehaviorSpace {
public:
	SetMovementState(const String& className, const uint32 id, const LuaObject& args);

	SetMovementState(const SetMovementState& a);

	SetMovementState& operator=(const SetMovementState& a);

	BehaviorSpace::Status execute(ShipAiAgent* agent, unsigned int startIdx = 0) const;

	void parseArgs(const LuaObject& args);

	String print() const;

private:
	uint32 state;
};

class SetDefenderFromProspect : public BehaviorSpace {
public:
	SetDefenderFromProspect(const String& className, const uint32 id, const LuaObject& args);

	SetDefenderFromProspect(const SetDefenderFromProspect& a);

	BehaviorSpace::Status execute(ShipAiAgent* agent, unsigned int startIdx = 0) const;
};

class Evade : public BehaviorSpace {
public:
	Evade(const String& className, const uint32 id, const LuaObject& args);

	Evade(const Evade& a);

	Evade& operator=(const Evade& a);

	void parseArgs(const LuaObject& args);

	BehaviorSpace::Status execute(ShipAiAgent* agent, unsigned int startIdx = 0) const;

	String print() const;

	private:
	uint64 evadeDelay;
};

class EngageSingleTarget : public BehaviorSpace {
public:
	EngageSingleTarget(const String& className, const uint32 id, const LuaObject& args);

	EngageSingleTarget(const EngageSingleTarget& a);

	EngageSingleTarget& operator=(const EngageSingleTarget& a);

	BehaviorSpace::Status execute(ShipAiAgent* agent, unsigned int startIdx = 0) const;

	String print() const;
};

class EngageTurrets : public BehaviorSpace {
public:
	EngageTurrets(const String& className, const uint32 id, const LuaObject& args);

	EngageTurrets(const EngageTurrets& a);

	EngageTurrets& operator=(const EngageTurrets& a);

	BehaviorSpace::Status execute(ShipAiAgent* agent, unsigned int startIdx = 0) const;

	String print() const;
};

class GetProspectFromThreatMap : public BehaviorSpace {
public:
	GetProspectFromThreatMap(const String& className, const uint32 id, const LuaObject& args);

	GetProspectFromThreatMap(const GetProspectFromThreatMap& a);

	BehaviorSpace::Status execute(ShipAiAgent* agent, unsigned int startIdx = 0) const;
};

class GetProspectFromDefenders : public BehaviorSpace {
public:
	GetProspectFromDefenders(const String& className, const uint32 id, const LuaObject& args);

	GetProspectFromDefenders(const GetProspectFromDefenders& a);

	BehaviorSpace::Status execute(ShipAiAgent* agent, unsigned int startIdx = 0) const;
};

} // namespace leafspace
} // namespace btspace
} // namespace ai
} // namespace ship
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::ship::ai::btspace::leafspace;

#pragma once

#include "server/zone/objects/creature/ai/AiAgent.h"
#include "server/zone/objects/creature/ai/bt/Behavior.h"
#include "server/zone/objects/creature/ai/bt/BlackboardData.h"
#include "templates/params/creature/CreatureAttribute.h"
#include "server/zone/managers/collision/CollisionManager.h"
#include "server/zone/Zone.h"
#include "server/zone/objects/intangible/PetControlDevice.h"
#include "server/zone/objects/tangible/threat/ThreatMap.h"
#include "server/chat/ChatManager.h"
#include "server/zone/managers/gcw/observers/SquadObserver.h"
#include "server/zone/managers/creature/observers/CreatureHerdObserver.h"
#include "server/zone/objects/player/FactionStatus.h"
#include "server/zone/managers/reaction/ReactionManager.h"
#include "server/zone/objects/creature/events/DroidHarvestTask.h"

namespace server {
namespace zone {
namespace objects {
namespace creature {
namespace ai {
namespace bt {
namespace leaf {

class GetProspectFromThreatMap : public Behavior {
public:
	GetProspectFromThreatMap(const String& className, const uint32 id, const LuaObject& args);

	GetProspectFromThreatMap(const GetProspectFromThreatMap& a);

	Behavior::Status execute(AiAgent* agent, unsigned int startIdx = 0) const;
};

class GetProspectFromDefenders : public Behavior {
public:
	GetProspectFromDefenders(const String& className, const uint32 id, const LuaObject& args);

	GetProspectFromDefenders(const GetProspectFromDefenders& a);

	Behavior::Status execute(AiAgent* agent, unsigned int startIdx = 0) const;
};

class GetProspectFromTarget : public Behavior {
public:
	GetProspectFromTarget(const String& className, const uint32 id, const LuaObject& args);

	GetProspectFromTarget(const GetProspectFromTarget& a);

	Behavior::Status execute(AiAgent* agent, unsigned int startIdx = 0) const;
};

class GetProspectFromCommand : public Behavior {
public:
	GetProspectFromCommand(const String& className, const uint32 id, const LuaObject& args);

	GetProspectFromCommand(const GetProspectFromCommand& a);

	Behavior::Status execute(AiAgent* agent, unsigned int startIdx = 0) const;
};

class RestoreFollow : public Behavior {
public:
	RestoreFollow(const String& className, const uint32 id, const LuaObject& args);

	RestoreFollow(const RestoreFollow& a);

	Behavior::Status execute(AiAgent* agent, unsigned int startIdx = 0) const;
};

class DropProspectFromDefenders : public Behavior {
public:
	DropProspectFromDefenders(const String& className, const uint32 id, const LuaObject& args);

	DropProspectFromDefenders(const DropProspectFromDefenders& a);

	Behavior::Status execute(AiAgent* agent, unsigned int startIdx = 0) const;
};

class SetDefenderFromProspect : public Behavior {
public:
	SetDefenderFromProspect(const String& className, const uint32 id, const LuaObject& args);

	SetDefenderFromProspect(const SetDefenderFromProspect& a);

	Behavior::Status execute(AiAgent* agent, unsigned int startIdx = 0) const;
};

class KillProspect : public Behavior {
public:
	KillProspect(const String& className, const uint32 id, const LuaObject& args);

	KillProspect(const KillProspect& a);

	Behavior::Status execute(AiAgent* agent, unsigned int startIdx = 0) const;
};

class UpdateRangeToFollow : public Behavior {
public:
	UpdateRangeToFollow(const String& className, const uint32 id, const LuaObject& args);

	UpdateRangeToFollow(const UpdateRangeToFollow& a);

	Behavior::Status execute(AiAgent* agent, unsigned int startIdx = 0) const;
};

class SetMovementState : public Behavior {
public:
	SetMovementState(const String& className, const uint32 id, const LuaObject& args);

	SetMovementState(const SetMovementState& a);

	SetMovementState& operator=(const SetMovementState& a);

	Behavior::Status execute(AiAgent* agent, unsigned int startIdx = 0) const;

	void parseArgs(const LuaObject& args);

	String print() const;

private:
	uint32 state;
};

class CalculateAggroMod : public Behavior {
public:
	CalculateAggroMod(const String& className, const uint32 id, const LuaObject& args);

	Behavior::Status execute(AiAgent* agent, unsigned int startIdx = 0) const;
};

class RunAway : public Behavior {
public:
	RunAway(const String& className, const uint32 id, const LuaObject& args);

	RunAway(const RunAway& b);

	RunAway& operator=(const RunAway& b);

	Behavior::Status execute(AiAgent* agent, unsigned int startIdx = 0) const;

	void parseArgs(const LuaObject& args);

	String print() const;

private:
	int delay;
	float dist;
};

class Evade : public Behavior {
public:
	Evade(const String& className, const uint32 id, const LuaObject& args);

	Evade(const Evade& a);

	Evade& operator=(const Evade& a);

	void parseArgs(const LuaObject& args);

	Behavior::Status execute(AiAgent* agent, unsigned int startIdx = 0) const;

	String print() const;

	private:
	float minEvadeChance;
	float maxEvadeChance;
};

class StalkProspect : public Behavior {
public:
	StalkProspect(const String& className, const uint32 id, const LuaObject& args);

	StalkProspect(const StalkProspect& a);

	Behavior::Status execute(AiAgent* agent, unsigned int startIdx = 0) const;

	String print() const;
};

class Flee : public Behavior {
public:
	Flee(const String& className, const uint32 id, const LuaObject& args);

	Flee(const Flee& a);

	Flee& operator=(const Flee& a);

	void parseArgs(const LuaObject& args);

	Behavior::Status execute(AiAgent* agent, unsigned int startIdx = 0) const;

	String print() const;

	private:
	int delay;
};

class PetReturn : public Behavior {
public:
	PetReturn(const String& className, const uint32 id, const LuaObject& args);

	PetReturn(const PetReturn& a);

	Behavior::Status execute(AiAgent* agent, unsigned int startIdx = 0) const;

	String print() const;
};

class FollowSquadLeader : public Behavior {
public:
	FollowSquadLeader(const String& className, const uint32 id, const LuaObject& args);

	FollowSquadLeader(const FollowSquadLeader& a);

	Behavior::Status execute(AiAgent* agent, unsigned int startIdx = 0) const;

	String print() const;
};

class FollowHerd : public Behavior {
public:
	FollowHerd(const String& className, const uint32 id, const LuaObject& args);

	FollowHerd(const FollowHerd& a);

	Behavior::Status execute(AiAgent* agent, unsigned int startIdx = 0) const;

	String print() const;
};

class GetHealTarget : public Behavior {
public:
	GetHealTarget(const String& className, const uint32 id, const LuaObject& args);

	GetHealTarget(const GetHealTarget& a);

	GetHealTarget& operator=(const GetHealTarget& a);

	Behavior::Status execute(AiAgent* agent, unsigned int startIdx = 0) const;

	void parseArgs(const LuaObject& args);

	String print() const;

private:
	float range;
};

class RestorePetPatrols : public Behavior {
public:
	RestorePetPatrols(const String& className, const uint32 id, const LuaObject& args);

	RestorePetPatrols(const RestorePetPatrols& a);

	Behavior::Status execute(AiAgent* agent, unsigned int startIdx = 0) const;

	String print() const;
};

class DroidHarvest : public Behavior {
public:
	DroidHarvest(const String& className, const uint32 id, const LuaObject& args);

	DroidHarvest(const DroidHarvest& a);

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

/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/engine.h"
#include "engine/util/json_utils.h"
#include "server/zone/objects/scene/variables/DeltaVector.h"

namespace server {
namespace zone {
namespace objects {
namespace creature {
namespace variables {

class Skill;

class SkillList : public DeltaVector<Reference<Skill*> > {
#ifdef ODB_SERIALIZATION
	Vector<String> skills;
#endif
public:
	bool add(Skill* skill, DeltaMessage* message = nullptr);
	void remove(Skill* skill, DeltaMessage* message = nullptr);

	bool containsSkill(const String& skill) const;

	bool toBinaryStream(ObjectOutputStream* stream) override;
	bool parseFromBinaryStream(ObjectInputStream* stream) override;

	void getStringList(Vector<String>& skills) const;
	void loadFromNames(Vector<String>& skills);

	void insertToMessage(BaseMessage* msg) const override;

	friend void to_json(nlohmann::json& j, const SkillList& s);
};

} // namespace variables
} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature::variables;

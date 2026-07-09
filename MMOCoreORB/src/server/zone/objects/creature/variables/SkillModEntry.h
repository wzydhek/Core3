/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/engine.h"
#include "engine/util/json_utils.h"

class SkillModEntry : public virtual Object {
private:
	int skillMod;
	int skillBonus;

public:
	SkillModEntry();

	SkillModEntry(const SkillModEntry& mod);

	SkillModEntry& operator=(const SkillModEntry& mod);

	bool operator==(SkillModEntry mod);

	void setSkillMod(int mod);

	int getSkillMod() const;

	void setSkillBonus(int bonus);

	int getSkillBonus() const;

	int getTotalSkill() const;

	bool toBinaryStream(ObjectOutputStream* stream);

	friend void to_json(nlohmann::json& j, const SkillModEntry& e);

	bool parseFromBinaryStream(ObjectInputStream* stream);
};

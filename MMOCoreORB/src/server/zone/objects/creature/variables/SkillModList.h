/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/engine.h"
#include "SkillModEntry.h"
#include "server/zone/objects/scene/variables/DeltaVectorMap.h"
#include "server/zone/managers/skill/SkillModManager.h"

class SkillModGroup : public VectorMap<String, int> {
public:
	SkillModGroup();

	SkillModGroup(const SkillModGroup& m);

	SkillModGroup& operator=(const SkillModGroup& m);
};

class SkillModList : public DeltaVectorMap<String, SkillModEntry> {
protected:
	VectorMap<uint32, SkillModGroup> mods;

public:

	SkillModList();

	SkillModList(const SkillModList& l);

	SkillModList& operator=(const SkillModList& l);

	void addSerializableVariables();

	friend void to_json(nlohmann::json& j, const SkillModList& map);

	bool add(const uint32 modType, const String& skillMod, int value);

	SkillModEntry getVisibleSkillMod(const String& skillMod) const;

	SkillModGroup* getSkillModGroup(const uint32 type);

	int getSkillMod(const String& skillMod) const;

	int getSkillModOfType(const String& skillMod, const uint32 modType);

	String getPrintableSkillModList() const;
};

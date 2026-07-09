#include "SkillModEntry.h"

SkillModEntry::SkillModEntry() : Object() {
	skillMod = 0;
	skillBonus = 0;
}

SkillModEntry::SkillModEntry(const SkillModEntry& mod) : Object() {
	skillMod = mod.skillMod;
	skillBonus = mod.skillBonus;
}

SkillModEntry& SkillModEntry::operator=(const SkillModEntry& mod) {
	if (this == &mod)
		return *this;

	skillMod = mod.skillMod;
	skillBonus = mod.skillBonus;

	return *this;
}

bool SkillModEntry::operator==(SkillModEntry mod) {
	return skillMod == mod.skillMod && skillBonus == mod.skillBonus;
}

void SkillModEntry::setSkillMod(int mod) {
	skillMod = mod;
}

int SkillModEntry::getSkillMod() const {
	return skillMod;
}

void SkillModEntry::setSkillBonus(int bonus) {
	skillBonus = bonus;
}

int SkillModEntry::getSkillBonus() const {
	return skillBonus;
}

int SkillModEntry::getTotalSkill() const {
	return getSkillMod() + getSkillBonus();
}

bool SkillModEntry::toBinaryStream(ObjectOutputStream* stream) {
	return TypeInfo<int>::toBinaryStream(&skillMod, stream) && TypeInfo<int>::toBinaryStream(&skillBonus, stream);
}

void to_json(nlohmann::json& j, const SkillModEntry& e) {
	j["skillMod"] = e.skillMod;
	j["skillBonus"] = e.skillBonus;
}

bool SkillModEntry::parseFromBinaryStream(ObjectInputStream* stream) {
	TypeInfo<int>::parseFromBinaryStream(&skillMod, stream);
	TypeInfo<int>::parseFromBinaryStream(&skillBonus, stream);

	return true;
}
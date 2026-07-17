/*
 * SkillInfo.h
 *
 *  Created on: Apr 25, 2011
 *      Author: crush
 */

#pragma once

#include "templates/datatables/DataTableRow.h"

namespace server {
namespace zone {
namespace managers {
namespace skill {

class SkillInfo : public Object {
	WeakReference<SkillInfo*> parentSkill;

	SortedVector<String> speciesRequired;
	SortedVector<String> skillsRequired;
	SortedVector<String> preclusionSkills;
	SortedVector<String> missionsRequired;

	SortedVector<String> commands;
	SortedVector<String> schematicsGranted;
	SortedVector<String> schematicsRevoked;

	VectorMap<String, int> skillMods;

	String xpType;
	String skillName;

	int skillsRequiredCount;
	int jediStateRequired;
	int apprenticeshipsRequired;
	int xpCost;
	int xpCap;
	int moneyRequired;
	int pointsRequired;
	int graphType;

	bool searchable;
	bool godOnly;
	bool isTitle;
	bool isProfession;
	bool isHidden;

public:
	SkillInfo();

	SkillInfo(const String& name, SkillInfo* parent);

	SkillInfo(const SkillInfo& si);

	SkillInfo& operator=(const SkillInfo& si);

	void parseFromDataTableRow(DataTableRow* row);
};

} // namespace skill
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::skill;

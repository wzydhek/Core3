/*
 * ProfessionDefaultsInfo.h
 *
 *  Created on: Aug 26, 2011
 *      Author: crush
 */

#pragma once

#include "server/zone/objects/creature/variables/Skill.h"
#include "server/zone/managers/skill/SkillManager.h"

namespace server {
namespace zone {
namespace managers {
namespace player {
namespace creation {

class ProfessionDefaultsInfo : public Object {
	Reference<Skill*> skill;
	VectorMap<String, SortedVector<String> > professionItems;
	VectorMap<uint8, int> professionMods;
	Vector<String> startingItems;

public:
	ProfessionDefaultsInfo();

	~ProfessionDefaultsInfo();

	void readObject(IffStream* iffStream);

	void setAttributeMod(uint8 idx, int value);

	const SortedVector<String>* getProfessionItems(const String& clientTemplate) const;

	const Skill* getSkill() const;

	int getAttributeMod(uint8 idx) const;

	const Vector<String>* getStartingItems() const;

	Vector<String>* getStartingItems();
};

}
}
}
}
}

using namespace server::zone::managers::player::creation;

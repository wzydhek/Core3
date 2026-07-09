/*
 * SkillInfo.h
 *
 *  Created on: Apr 21, 2011
 *      Author: crush
 */

#pragma once

#include "templates/IffTemplate.h"

namespace server {
namespace zone {
namespace managers {
namespace player {
namespace creation {

class SkillInfo : public IffTemplate {
	Vector<String> skills;
	VectorMap<String, SortedVector<String> > items;
	Vector<int> attributeMods;

	void addItem(const String& templateName, const String& itemName);

public:
	SkillInfo();

	SkillInfo(const SkillInfo& pi);

	SkillInfo& operator=(const SkillInfo& pi);

	void setAttributeMod(int idx, int value);

	int getAttributeMod(int idx);

	void readObject(IffStream* iffStream);
};

}
}
}
}
}

using namespace server::zone::managers::player::creation;

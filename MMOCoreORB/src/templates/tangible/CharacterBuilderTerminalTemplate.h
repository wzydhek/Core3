/*
 * CharacterBuildterTerminalTemplate.h
 *
 *  Created on: 06/05/2010
 *      Author: victor
 */

#pragma once

#include "templates/SharedTangibleObjectTemplate.h"
#include "templates/tangible/CharacterBuilderMenuNode.h"

namespace templates {
namespace tangible {

class CharacterBuilderTerminalTemplate : public SharedTangibleObjectTemplate {
	Reference<CharacterBuilderMenuNode*> rootNode;
	Vector<int> glowyBadgeIds;
	Vector<String> villageBranchUnlocks;

public:
	CharacterBuilderTerminalTemplate();

	~CharacterBuilderTerminalTemplate();

	void readObject(LuaObject* templateData);

    const CharacterBuilderMenuNode* getItemList() const;

    const Vector<int>& getGlowyBadgeIds() const;

    const Vector<String>& getVillageBranchUnlocks() const;
};

} // namespace tangible
} // namespace templates

using namespace templates::tangible;
/*
 * CharacterBuildterTerminalTemplate.h
 *
 *  Created on: 06/05/2010
 *      Author: victor
 */

#pragma once

#include "templates/SharedTangibleObjectTemplate.h"
#include "templates/tangible/CharacterBuilderMenuNode.h"

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

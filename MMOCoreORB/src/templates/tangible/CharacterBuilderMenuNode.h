/*
 * CharacterBuilderMenuNode.h
 *
 *  Created on: Jun 6, 2010
 *      Author: crush
 */

#pragma once

#include "engine/lua/LuaObject.h"

namespace templates {
namespace tangible {

class CharacterBuilderMenuNode : public Object {
	WeakReference<CharacterBuilderMenuNode*> parentNode;

	String displayName;
	String templatePath;
	uint32 templateCRC;

	SortedVector<Reference<CharacterBuilderMenuNode*> > childNodes;

public:
	CharacterBuilderMenuNode(const String& name);

	CharacterBuilderMenuNode(const String& name, const String& tplPath);

	int readLuaObject(LuaObject& luaObject, bool recursive);

	int compareTo(CharacterBuilderMenuNode* obj);

	void setTemplatePath(const String& tplPath);

	void setParentNode(CharacterBuilderMenuNode* parent);

	CharacterBuilderMenuNode* getParentNode();

	const CharacterBuilderMenuNode* getParentNode() const;

	bool hasParentNode() const;

	bool hasChildNodes() const;

	const String& getDisplayName() const;

	const String& getTemplatePath() const;

	uint32 getTemplateCRC() const;

	int getChildNodeSize() const;

	const CharacterBuilderMenuNode* getChildNodeAt(int index) const;

	CharacterBuilderMenuNode* getChildNodeAt(int index);
};

} // namespace tangible
} // namespace templates

using namespace templates::tangible;
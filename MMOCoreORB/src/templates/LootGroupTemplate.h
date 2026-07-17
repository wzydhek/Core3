/*
 * LootGroupTemplate.h
 *
 *  Created on: Jan 30, 2012
 *      Author: xyborn
 */

#pragma once

#include "system/lang.h"
#include "engine/lua/LuaObject.h"

namespace templates {

class LootGroupTemplate : public Object {
	String templateName;

	VectorMap<String, int> entryMap;

public:
	LootGroupTemplate(const String& name);

	LootGroupTemplate(const LootGroupTemplate& lgt);

	LootGroupTemplate& operator=(const LootGroupTemplate& lgt);

	String getLootGroupEntryForRoll(int roll) const;

	int getLootGroupIntEntryForRoll(int roll) const;

	int size() const;

	String getLootGroupEntryAt(int i) const;

	void readObject(LuaObject* lua);

	const String& getTemplateName() const;
};

} // namespace templates

using namespace templates;
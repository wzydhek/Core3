/*
 * LootGroupMap.h
 *
 *  Created on: Jun 24, 2011
 *      Author: xyborn
 */

#pragma once

class LootItemTemplate;

#include "templates/LootGroupTemplate.h"
#include "engine/log/Logger.h"
#include "engine/util/Singleton.h"
#include "engine/lua/Lua.h"

class LootGroupMap : public Singleton<LootGroupMap>, public Object, public Logger {
public:
	static Lua* lua;

#ifdef PLATFORM_WIN
#undef NO_ERROR
#endif

	enum LUA_ERROR_CODE { NO_ERROR = 0, GENERAL_ERROR };
	static int ERROR_CODE;

	HashTable<String, Reference<LootItemTemplate*> > itemTemplates;
	HashTable<String, Reference<LootGroupTemplate*> > groupTemplates;

public:
	LootGroupMap();
	virtual ~LootGroupMap();

	int initialize();

	void putLootItemTemplate(const String& name, LootItemTemplate* item);

	void putLootGroupTemplate(const String& name, LootGroupTemplate* group);

	const LootGroupTemplate* getLootGroupTemplate(const String& name) const;

	const LootItemTemplate* getLootItemTemplate(const String& name) const;

	int countLootItemTemplates() const;

	int countLootGroupTemplates() const;

	bool lootGroupExists(const String& group) const;

	bool lootItemExists(const String& item) const;

private:
	static String currentFilename;

	void registerFunctions();
	void registerGlobals();

	static int includeFile(lua_State* L);

	static int addLootGroupTemplate(lua_State* L);
	static int addLootItemTemplate(lua_State* L);
};

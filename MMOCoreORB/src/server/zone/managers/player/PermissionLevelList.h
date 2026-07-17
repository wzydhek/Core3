/*
 * PermissionLevelList.h
 *
 *  Created on: May 10, 2012
 *      Author: Itac
 */

#pragma once

#include "engine/engine.h"

namespace server {
namespace zone {
namespace managers {
namespace player {

class PermissionLevel : public Object{
protected:
	int permissionLevel, priviledgeFlag;
	String name;
	UnicodeString tag;
	Vector<String> skillList;

public:
	PermissionLevel();

	PermissionLevel(int staffLev, String levelName, String staffTag, int flag, Vector<String> skills);

	~PermissionLevel();

	PermissionLevel(const PermissionLevel& al);

	int getPermissionLevel();

	int getPriviledgeFlag();

	String getName();

	UnicodeString getTag();

	Vector<String>* getSkillList();

};

class PermissionLevelList : public Singleton<PermissionLevelList>, public VectorMap<uint32, Reference< PermissionLevel*> > {
protected:
	static Lua lua;
	VectorMap<String, int> permissionNames;

public:

	PermissionLevelList();

	~PermissionLevelList();

	static void loadLevels();

	static int addLevel(lua_State* L);

	static int includeFile(lua_State* L);

	void loadLevel(LuaObject* luaLevel);

	UnicodeString getPermissionTag(uint32 permissionLevel);

	Vector<String>* getPermissionSkills(uint32 permissionLevel);

	int getPriviledgeFlag(uint32 permissionLevel);

	int getLevelNumber(String name);

	bool containsLevel(String name);
};

} // namespace player
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::player;

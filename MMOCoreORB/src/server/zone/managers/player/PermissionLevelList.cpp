#include "PermissionLevelList.h"

Lua PermissionLevelList::lua;

PermissionLevel::PermissionLevel() {
	permissionLevel = 0;
	priviledgeFlag = 0;
}

PermissionLevel::PermissionLevel(int staffLev, String levelName, String staffTag, int flag, Vector<String> skills) : Object() {
	permissionLevel = staffLev;
	name = levelName;
	tag = staffTag;
	priviledgeFlag = flag;
	skillList = skills;
}

PermissionLevel::~PermissionLevel() {
}

PermissionLevel::PermissionLevel(const PermissionLevel& al) : Object() {
	permissionLevel = al.permissionLevel;
	tag = al.tag;
	priviledgeFlag = al.priviledgeFlag;
	skillList = al.skillList;
	name = al.name;
}

int PermissionLevel::getPermissionLevel() {
	return permissionLevel;
}

int PermissionLevel::getPriviledgeFlag() {
	return priviledgeFlag;
}

String PermissionLevel::getName() {
	return name;
}

UnicodeString PermissionLevel::getTag() {
	return tag;
}

Vector<String>* PermissionLevel::getSkillList() {
	return &skillList;
}

PermissionLevelList::PermissionLevelList() {
}

PermissionLevelList::~PermissionLevelList() {
}

void PermissionLevelList::loadLevels() {
	lua.init();
	lua.registerFunction("includeFile", &includeFile);
	lua.registerFunction("addLevel", &addLevel);
	lua.runFile("scripts/staff/levels/serverobjects.lua");
}

int PermissionLevelList::addLevel(lua_State* L) {
	LuaObject obj(L);
	PermissionLevelList::instance()->loadLevel(&obj);
	obj.pop();

	return 0;
}

int PermissionLevelList::includeFile(lua_State* L) {
	String filename = lua.getStringParameter(L);
	lua.runFile("scripts/staff/" + filename, L);

	return 0;
}

void PermissionLevelList::loadLevel(LuaObject* luaLevel) {
	if (!luaLevel->isValidTable()) {
		return;
	}

	Vector<String> skills;

	uint32 levelNum = luaLevel->getIntField("level");

	String name = luaLevel->getStringField("name");

	String tag = luaLevel->getStringField("tag");

	int priviledgeFlag = luaLevel->getIntField("flag");

	LuaObject skillsTable = luaLevel->getObjectField("skills");
	for (int i = 1; i <= skillsTable.getTableSize(); ++i) {
		skills.add(skillsTable.getStringAt(i));
	}
	skillsTable.pop();
	put(levelNum, new PermissionLevel(levelNum, name, tag, priviledgeFlag, skills));
	permissionNames.put(name, levelNum);
}

UnicodeString PermissionLevelList::getPermissionTag(uint32 permissionLevel) {
	if (!contains(permissionLevel))
		return "";
	else
		return get(permissionLevel)->getTag();
}

Vector<String>* PermissionLevelList::getPermissionSkills(uint32 permissionLevel) {
	if (!contains(permissionLevel))
		return nullptr;
	else
		return get(permissionLevel)->getSkillList();
}

int PermissionLevelList::getPriviledgeFlag(uint32 permissionLevel) {
	if (!contains(permissionLevel))
		return 0;
	else
		return get(permissionLevel)->getPriviledgeFlag();
}

int PermissionLevelList::getLevelNumber(String name) {
	return permissionNames.get(name);
}

bool PermissionLevelList::containsLevel(String name) {
	return permissionNames.contains(name);
}
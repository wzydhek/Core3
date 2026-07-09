#pragma once

#include "engine/lua/Lua.h"

class NameRules: public Object {
	int nameChance;
	int minSyllables, maxSyllables;
	int minChars, maxChars;
	int specialCharChance;
	int maxSpecialChars;
	int chanceBeginsSpecial, chanceMiddleSpecial, chanceEndsSpecial;
	int maxSpecialSyllables;
	int uniqueChance;

	String specialChars;

public:
	NameRules();

	NameRules(const NameRules& rules);

	NameRules& operator=(const NameRules& rules);

	void readObject(LuaObject* luaObject);

	int getNameChance() const;

	int getUniqueChance() const;

	int getMinSyllables() const;

	int getMaxSyllables() const;

	int getMinChars() const;

	int getMaxChars() const;

	int getSpecialCharChance() const;

	int getMaxSpecialChars() const;

	int getChanceBeginsSpecial() const;

	int getChanceMiddleSpecial() const;

	int getChanceEndsSpecial() const;

	int getMaxSpecialSyllables() const;

	String getRandomSpecialChar() const;

	const String& getSpecialChars() const;
};

#include "NameRules.h"

NameRules::NameRules() {
	nameChance = 0;
	minSyllables = 0;
	maxSyllables = 0;
	minChars = 0;
	maxChars = 0;
	specialCharChance = 0;
	maxSpecialChars = 0;
	chanceBeginsSpecial = 0;
	chanceMiddleSpecial = 0;
	chanceEndsSpecial = 0;
	maxSpecialSyllables = 0;
	uniqueChance = 0;

	specialChars = "";
}

NameRules::NameRules(const NameRules& rules) : Object() {
	nameChance = rules.nameChance;
	minSyllables = rules.minSyllables;
	maxSyllables = rules.maxSyllables;
	minChars = rules.minChars;
	maxChars = rules.maxChars;
	specialCharChance = rules.specialCharChance;
	maxSpecialChars = rules.maxSpecialChars;
	chanceBeginsSpecial = rules.chanceBeginsSpecial;
	chanceMiddleSpecial = rules.chanceMiddleSpecial;
	chanceEndsSpecial = rules.chanceEndsSpecial;
	maxSpecialSyllables = rules.maxSpecialSyllables;
	uniqueChance = rules.uniqueChance;

	specialChars = rules.specialChars;
}

NameRules& NameRules::operator=(const NameRules& rules) {
	if (this == &rules)
		return *this;

	nameChance = rules.nameChance;
	minSyllables = rules.minSyllables;
	maxSyllables = rules.maxSyllables;
	minChars = rules.minChars;
	maxChars = rules.maxChars;
	specialCharChance = rules.specialCharChance;
	maxSpecialChars = rules.maxSpecialChars;
	chanceBeginsSpecial = rules.chanceBeginsSpecial;
	chanceMiddleSpecial = rules.chanceMiddleSpecial;
	chanceEndsSpecial = rules.chanceEndsSpecial;
	maxSpecialSyllables = rules.maxSpecialSyllables;
	uniqueChance = rules.uniqueChance;

	specialChars = rules.specialChars;

	return *this;
}

void NameRules::readObject(LuaObject* luaObject) {
	if (!luaObject->isValidTable())
		return;

	nameChance = luaObject->getIntField("nameChance");
	minSyllables = luaObject->getIntField("minSyllables");
	maxSyllables = luaObject->getIntField("maxSyllables");
	minChars = luaObject->getIntField("minChars");
	maxChars = luaObject->getIntField("maxChars");
	specialCharChance = luaObject->getIntField("specialCharChance");
	maxSpecialChars = luaObject->getIntField("maxSpecialChars");
	chanceBeginsSpecial = luaObject->getIntField("chanceBeginsSpecial");
	chanceMiddleSpecial = luaObject->getIntField("chanceMiddleSpecial");
	chanceEndsSpecial = luaObject->getIntField("chanceEndsSpecial");
	maxSpecialSyllables = luaObject->getIntField("maxSpecialSyllables");
	uniqueChance = luaObject->getIntField("uniqueChance");

	specialChars = luaObject->getStringField("specialChars");
}

int NameRules::getNameChance() const {
	return nameChance;
}

int NameRules::getUniqueChance() const {
	return uniqueChance;
}

int NameRules::getMinSyllables() const {
	return minSyllables;
}

int NameRules::getMaxSyllables() const {
	return maxSyllables;
}

int NameRules::getMinChars() const {
	return minChars;
}

int NameRules::getMaxChars() const {
	return maxChars;
}

int NameRules::getSpecialCharChance() const {
	return specialCharChance;
}

int NameRules::getMaxSpecialChars() const {
	return maxSpecialChars;
}

int NameRules::getChanceBeginsSpecial() const {
	return chanceBeginsSpecial;
}

int NameRules::getChanceMiddleSpecial() const {
	return chanceMiddleSpecial;
}

int NameRules::getChanceEndsSpecial() const {
	return chanceEndsSpecial;
}

int NameRules::getMaxSpecialSyllables() const {
	return maxSpecialSyllables;
}

String NameRules::getRandomSpecialChar() const {
	int strLen = specialChars.length() - 1;
	int randIndex = System::random(strLen);
	String randChar = specialChars.subString(randIndex, randIndex + 1);
	return randChar;
}

const String& NameRules::getSpecialChars() const {
	return specialChars;
}
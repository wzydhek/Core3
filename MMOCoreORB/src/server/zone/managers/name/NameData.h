#pragma once

#include "server/zone/managers/name/NameRules.h"
#include "server/zone/managers/name/NameUnique.h"
#include "engine/lua/Lua.h"

class NameData: public Object {
	NameRules* firstNameRules;
	NameRules* lastNameRules;

	VectorMap<String, int> beginningConsonants;
	VectorMap<String, int> middleConsonants;
	VectorMap<String, int> endingConsonants;
	VectorMap<String, int> vowels;
	VectorMap<String, int> specialSyllables;

	Vector<Reference<NameUnique*> > uniques;
	VectorMap<String, int> uniquePatterns;

	int beginningConsonantOdds, middleConsonantOdds, endingConsonantOdds;
	int vowelOdds, specialSyllableOdds, uniquePatternOdds;

public:
	NameData();

	~NameData();

	NameData(const NameData& data);

	NameData& operator=(const NameData& data);

	void readObject(LuaObject* luaObject);

	const NameRules* getFirstNameRules() const;

	const NameRules* getLastNameRules() const;

	String getRandomBeginningConsonant() const;

	bool beginningConsonantContains(const String& fragment) const;

	String getRandomMiddleConsonant() const;

	bool middeConsonantContains(const String& fragment) const;

	String getRandomEndingConsonant() const;

	bool endingConsonantContains(const String& fragment) const;

	String getRandomVowel() const;

	bool vowelsContains(const String& fragment) const;

	String getRandomSpecialSyllable() const;

	String getRandomUniquePattern() const;

	String getRandomUnique(const String& type, String& root) const;

	bool specialSyllablesContains(const String& fragment) const;
};

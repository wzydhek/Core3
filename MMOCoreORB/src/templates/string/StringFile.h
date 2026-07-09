/*
 * StringFile.h
 *
 *  Created on: 25/12/2011
 *      Author: victor
 */

#pragma once

#include "system/lang.h"
#include "engine/log/Logger.h"

class StringFile : public Logger {
	HashTable<String, UnicodeString> stringMap;

public:
	StringFile();
	~StringFile();

	bool load(ObjectInputStream* inputFile);

	const HashTable<String, UnicodeString>& getStringMap() const;

	UnicodeString getValue(const String& id) const;

protected:
	bool checkHeader(ObjectInputStream* inputFile);
};

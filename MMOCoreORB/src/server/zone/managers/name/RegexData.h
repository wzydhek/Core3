#pragma once

#include "engine/engine.h"
#include <regex>

class RegexData : public Object {

protected:
	std::regex* regexEntry;
	String phrase;
	int type;

public:
	RegexData(String filter, int filterType);

	~RegexData();

	std::regex* getRegexEntry() const;

	int getFilterType() const;

	String getRegexPhrase() const;
};

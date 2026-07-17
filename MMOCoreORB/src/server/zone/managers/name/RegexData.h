#pragma once

#include "engine/engine.h"
#include <regex>

namespace server {
namespace zone {
namespace managers {
namespace name {

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

} // namespace name
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::name;

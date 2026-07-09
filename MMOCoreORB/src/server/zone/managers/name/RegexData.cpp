#include "RegexData.h"

RegexData::RegexData(String filter, int filterType) {
	regexEntry = new std::regex(filter.toCharArray(), std::regex_constants::icase);

	type = filterType;
	phrase = filter;
}

RegexData::~RegexData() {
	delete regexEntry;
	regexEntry = nullptr;
}

std::regex* RegexData::getRegexEntry() const {
	return regexEntry;
}

int RegexData::getFilterType() const {
	return type;
}

String RegexData::getRegexPhrase() const {
	return phrase;
}
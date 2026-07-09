#include "StringList.h"

StringList::StringList(CreatureObject* creo) : ObjectControllerMessage(creo->getObjectID(), 0x0B, 0xE0) {
	optionCount = 0;
	insertByte(0);
}

void StringList::insertOption(const String& file, const String& str) {
	insertUnicode(UnicodeString("@" + file + ":" + str));
	updateOptionCount();
}

void StringList::insertOption(const String& option) {
	insertUnicode(UnicodeString(option));
	updateOptionCount();
}

void StringList::insertOption(const UnicodeString& option) {
	insertUnicode(option);
	updateOptionCount();
}

void StringList::updateOptionCount() {
	insertByte(30, ++optionCount);
}

int StringList::getOptionCount() {
	return optionCount;
}
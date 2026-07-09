#include "NonPlayerCreatureObjectTemplate.h"

NonPlayerCreatureObjectTemplate::NonPlayerCreatureObjectTemplate() {
}

NonPlayerCreatureObjectTemplate::~NonPlayerCreatureObjectTemplate() {
}

void NonPlayerCreatureObjectTemplate::readObject(LuaObject* templateData) {
	SharedCreatureObjectTemplate::readObject(templateData);
}

bool NonPlayerCreatureObjectTemplate::isNonPlayerCreatureObjectTemplate() {
	return true;
}
#include "CreatureHabitatTemplate.h"

CreatureHabitatTemplate::CreatureHabitatTemplate() {
}

CreatureHabitatTemplate::~CreatureHabitatTemplate() {
}

void CreatureHabitatTemplate::readObject(LuaObject* templateData) {
	SharedTangibleObjectTemplate::readObject(templateData);
}

bool CreatureHabitatTemplate::isCreatureHabitatTemplate() const {
	return true;
}
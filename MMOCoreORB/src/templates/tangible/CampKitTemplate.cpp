#include "CampKitTemplate.h"

void CampKitTemplate::readObject(LuaObject* templateData) {
	SharedTangibleObjectTemplate::readObject(templateData);

	spawnObjectTemplate = templateData->getStringField("spawnObjectTemplate");
}

const String& CampKitTemplate::getSpawnObjectTemplate() {
	return spawnObjectTemplate;
}

bool CampKitTemplate::isCampKitTemplate() {
	return true;
}
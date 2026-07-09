#include "CamoKitTemplate.h"

CamoKitTemplate::CamoKitTemplate() {
	effectiveZone = "";
}

CamoKitTemplate::~CamoKitTemplate() {
}

void CamoKitTemplate::readObject(LuaObject* templateData) {
	SharedTangibleObjectTemplate::readObject(templateData);

	effectiveZone = templateData->getStringField("effectiveZone");
}

String& CamoKitTemplate::getEffectiveZone() {
	return effectiveZone;
}

bool CamoKitTemplate::isCamoKitTemplate() {
	return true;
}
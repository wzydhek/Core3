#include "EventPerkDeedTemplate.h"

EventPerkDeedTemplate::EventPerkDeedTemplate() {
	perkType = UNKNOWN;
	generatedTimeToLive = 0;
	allowedZones.removeAll();
}

EventPerkDeedTemplate::~EventPerkDeedTemplate() {
}

void EventPerkDeedTemplate::readObject(LuaObject* templateData) {
	DeedTemplate::readObject(templateData);
	perkType = templateData->getIntField("perkType");
	generatedTimeToLive = templateData->getLongField("generatedTimeToLive");

	LuaObject allowzones = templateData->getObjectField("allowedZones");

	if (allowzones.isValidTable()) {
		for (int i = 1; i <= allowzones.getTableSize(); ++i) {
			allowedZones.put(allowzones.getStringAt(i));
		}
	}

	allowzones.pop();
}

int EventPerkDeedTemplate::getPerkType() {
	return perkType;
}

uint64 EventPerkDeedTemplate::getGeneratedTimeToLive() {
	return generatedTimeToLive;
}

bool EventPerkDeedTemplate::isAllowedZone(const String& zoneName) {
	return allowedZones.isEmpty() || allowedZones.contains(zoneName);
}
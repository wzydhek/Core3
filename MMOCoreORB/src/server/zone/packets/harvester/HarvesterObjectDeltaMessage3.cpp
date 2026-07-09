#include "HarvesterObjectDeltaMessage3.h"

HarvesterObjectDeltaMessage3::HarvesterObjectDeltaMessage3(HarvesterObject* ho) : DeltaMessage(ho->getObjectID(), 0x4F4E5449, 3) {
	haro = ho;
}

void HarvesterObjectDeltaMessage3::updateDamage(uint32 value) {
	haro->setConditionDamage(value);
	addIntUpdate(0x0A, value);
}
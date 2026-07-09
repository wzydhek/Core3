#include "CreatureObjectDeltaMessage4.h"

CreatureObjectDeltaMessage4::CreatureObjectDeltaMessage4(CreatureObject* cr) : DeltaMessage(cr->getObjectID(), 'CREO', 0x04) {
	creo = cr;
}

void CreatureObjectDeltaMessage4::updateAccelerationMultiplierBase() {
	addFloatUpdate(0x00, creo->getAccelerationMultiplierBase());
}

void CreatureObjectDeltaMessage4::updateAccelerationMultiplierMod() {
	addFloatUpdate(0x01, creo->getAccelerationMultiplierMod());
}

void CreatureObjectDeltaMessage4::updateSpeedMultiplierBase() {
	addFloatUpdate(0x04, creo->getSpeedMultiplierBase());
}

void CreatureObjectDeltaMessage4::updateSpeedMultiplierMod() {
	addFloatUpdate(0x05, creo->getSpeedMultiplierMod());
}

void CreatureObjectDeltaMessage4::updateListenToID(uint64 objectid) {
	startUpdate(0x06);
	insertLong(objectid);
}

void CreatureObjectDeltaMessage4::updateRunSpeed() {
	addFloatUpdate(0x07, creo->getRunSpeed());
}

void CreatureObjectDeltaMessage4::updateSlopeModAngle() {
	addFloatUpdate(0x08, creo->getSlopeModAngle());
}

void CreatureObjectDeltaMessage4::updateSlopeModPercent() {
	addFloatUpdate(0x09, creo->getSlopeModPercent());
}

void CreatureObjectDeltaMessage4::updateTurnScale() {
	addFloatUpdate(0x0A, creo->getTurnScale());
}

void CreatureObjectDeltaMessage4::updateWalkSpeed() {
	addFloatUpdate(0x0B, creo->getWalkSpeed());
}

void CreatureObjectDeltaMessage4::updateWaterModPercent() {
	addFloatUpdate(0x0C, creo->getWaterModPercent());
}

void CreatureObjectDeltaMessage4::updateSpeedAndAccelerationMods(bool sendSelf) {
	float aScale = creo->getAccelerationMultiplierMod();
	float mScale = creo->getSpeedMultiplierMod();
	float tScale = creo->getTurnScale();

	if (aScale == 0.f && mScale == 0.f) {
		aScale = 0.1f;
	}

	if (mScale == 0.f && !sendSelf) {
		mScale = 0.1f;
	}

	addFloatUpdate(0x01, aScale); // accelerationMultiplierMod
	addFloatUpdate(0x05, mScale); // speedMultiplierMod
	addFloatUpdate(0x0A, tScale); // turnScale
}
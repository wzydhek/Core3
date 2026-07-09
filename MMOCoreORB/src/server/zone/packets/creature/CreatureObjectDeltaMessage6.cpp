#include "CreatureObjectDeltaMessage6.h"

CreatureObjectDeltaMessage6::CreatureObjectDeltaMessage6(CreatureObject* cr) : TangibleObjectDeltaMessage6(cr, 0x4352454F) {
	creo = cr;
}

void CreatureObjectDeltaMessage6::updateLevel(uint16 value) {
	startUpdate(0x02);
	insertShort(value);
}

void CreatureObjectDeltaMessage6::updatePerformanceAnimation(const String& pAnimation) {
	startUpdate(0x03);
	insertAscii(pAnimation);
}

void CreatureObjectDeltaMessage6::updateMoodStr() {
	addAsciiUpdate(0x04, creo->getMoodString());
}

void CreatureObjectDeltaMessage6::updateWeapon() {
	addLongUpdate(0x05, creo->getWeaponID());
}

void CreatureObjectDeltaMessage6::updateGroupID() {
	addLongUpdate(0x06, creo->getGroupID());
}

void CreatureObjectDeltaMessage6::updateInviterId() {
	startUpdate(0x07);

	insertLong(creo->getGroupInviterID());
	insertLong(creo->getGroupInviteCounter());
}

void CreatureObjectDeltaMessage6::updateGuildID() {
	addIntUpdate(0x08, creo->getGuildID());
}

void CreatureObjectDeltaMessage6::updateTarget() {
	addLongUpdate(0x09, creo->getTargetID());
}

void CreatureObjectDeltaMessage6::updateMoodID() {
	addByteUpdate(0x0A, creo->getMoodID());
}

void CreatureObjectDeltaMessage6::updatePerformanceStartTime(uint32 startTime) {
	startUpdate(0x0B);
	insertInt(startTime);
}

void CreatureObjectDeltaMessage6::updatePerformanceType(int value) {
	startUpdate(0x0C);
	insertInt(value);
}

void CreatureObjectDeltaMessage6::updateAlternateAppearance() {
	startUpdate(0x10);
	insertAscii(creo->getAlternateAppearance());
}
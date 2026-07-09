#include "CreatureObjectDeltaMessage3.h"

CreatureObjectDeltaMessage3::CreatureObjectDeltaMessage3(CreatureObject* cr) : DeltaMessage(cr->getObjectID(), 0x4352454F, 3) {
	creo = cr;
}

void CreatureObjectDeltaMessage3::updateCharacterAppearance() {
	String appearance;
	creo->getCustomizationString(appearance);
	addAsciiUpdate(0x04, appearance);
}

void CreatureObjectDeltaMessage3::updateCreatureBitmask(uint32 value) {
	addIntUpdate(0x06, value);
}

void CreatureObjectDeltaMessage3::updateIncapacitationRecoveryTime(uint32 duration) {
	addIntUpdate(0x07, duration);
}

void CreatureObjectDeltaMessage3::updateConditionDamage() {
	addIntUpdate(0x08, creo->getConditionDamage());
}

void CreatureObjectDeltaMessage3::updateMaxCondition() {
	addIntUpdate(0x09, creo->getMaxCondition());
}

// 0x0A ??

void CreatureObjectDeltaMessage3::updatePosture() {
	addByteUpdate(0x0B, creo->getPosture());
}

void CreatureObjectDeltaMessage3::updateFactionRank() {
	addByteUpdate(0x0C, creo->getFactionRank());
}

void CreatureObjectDeltaMessage3::updateCreatureLinkID() {
	addLongUpdate(0x0D, creo->getCreatureLinkID());
}

void CreatureObjectDeltaMessage3::updateHeight() {
	addFloatUpdate(0x0E, creo->getHeight());
}

void CreatureObjectDeltaMessage3::updateShockWounds() {
	addIntUpdate(0x0F, (int)creo->getShockWounds());
}

void CreatureObjectDeltaMessage3::updateStatesBitmask() {
	addLongUpdate(0x10, creo->getStateBitmask());
}
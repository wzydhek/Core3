#include "TangibleObjectDeltaMessage3.h"
#include "server/zone/objects/player/PlayerObject.h"

TangibleObjectDeltaMessage3::TangibleObjectDeltaMessage3(TangibleObject* ta, uint32 objType) : DeltaMessage(ta->getObjectID(), objType, 3) {
	tano = ta;
}

void TangibleObjectDeltaMessage3::updateCustomizationString() {
	String app;
	tano->getCustomizationString(app);
	addAsciiUpdate(4, app);
}

void TangibleObjectDeltaMessage3::updateComplexity() {
	addFloatUpdate(0, tano->getComplexity());
}

void TangibleObjectDeltaMessage3::updateObjectName(const StringId& name) {
	addStringIdUpdate(1, name);
}

void TangibleObjectDeltaMessage3::updateCustomName(const UnicodeString& name, const UnicodeString& tag) {
	if (tano->isPlayerCreature()) {
		CreatureObject* player = cast<CreatureObject*>(tano.get());

		if (player->getPlayerObject()->hasGodMode() && tag != "") {
			UnicodeString customName = name + " \\#ffff00[" + tag + "]\\#.";
			addUnicodeUpdate(2, customName);
			return;
		}
	}

	addUnicodeUpdate(2, name);
}

void TangibleObjectDeltaMessage3::updateCountdownTimer() {
	addIntUpdate(7, tano->getUseCount());
}

void TangibleObjectDeltaMessage3::updateConditionDamage() {
	addIntUpdate(8, int(tano->getConditionDamage()));
}

void TangibleObjectDeltaMessage3::updateMaxCondition() {
	addIntUpdate(9, tano->getMaxCondition());
}

void TangibleObjectDeltaMessage3::updateOptionsBitmask() {
	addIntUpdate(0x06, tano->getOptionsBitmask());
}
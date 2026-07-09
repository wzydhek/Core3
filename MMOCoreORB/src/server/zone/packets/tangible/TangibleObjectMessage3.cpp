#include "TangibleObjectMessage3.h"
#include "server/zone/objects/scene/variables/StringId.h"
#include "server/zone/objects/player/PlayerObject.h"
#include "server/zone/objects/creature/CreatureObject.h"
#include "server/zone/managers/player/PermissionLevelList.h"

TangibleObjectMessage3::TangibleObjectMessage3(TangibleObject* tano, uint32 objType, uint16 opcnt) : BaseLineMessage(tano, objType, 3, opcnt) {
	insertFloat(tano->getComplexity());

	const StringId* stringId = tano->getObjectName();

	insertStringId(stringId);

	if (tano->isPlayerCreature()) {
		auto ghost = (static_cast<CreatureObject*>(tano))->getPlayerObject();

		if (ghost != nullptr && ghost->hasGodMode()) {
			UnicodeString name = tano->getCustomObjectName();
			UnicodeString tag = PermissionLevelList::instance()->getPermissionTag(ghost->getAdminLevel());
			insertUnicode(name + " \\#ffff00[" + tag + "]\\#.");
		} else {
			insertUnicode(tano->getCustomObjectName());
		}

	} else {
		insertUnicode(tano->getCustomObjectName());
	}

	insertInt(tano->getVolume());

	String app;
	tano->getCustomizationString(app);
	insertAscii(app);

	auto visibleComponents = tano->getVisibleComponents();
	visibleComponents->insertToMessage(this);

	insertInt(tano->getOptionsBitmask());

	insertInt(tano->getUseCount()); // item count

	insertInt(int(tano->getConditionDamage()));
	insertInt(tano->getMaxCondition());

	insertByte(tano->getObjectVisible());

	setSize();
}
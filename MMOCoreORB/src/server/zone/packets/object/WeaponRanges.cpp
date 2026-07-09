#include "WeaponRanges.h"

WeaponRanges::WeaponRanges(CreatureObject* creo, WeaponObject* weao) : ObjectControllerMessage(creo->getObjectID(), 0x1B, 0x140) {
	insertLong(weao->getObjectID());
	insertFloat(weao->getIdealRange());
	insertFloat(weao->getMaxRange());
	insertInt(weao->getPointBlankAccuracy());
	insertInt(weao->getIdealAccuracy());
	insertInt(weao->getMaxRangeAccuracy());
}
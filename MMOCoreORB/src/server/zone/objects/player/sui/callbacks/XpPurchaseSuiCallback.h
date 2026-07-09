#pragma once

#include "server/zone/objects/player/sui/SuiCallback.h"
#include "server/zone/managers/skill/SkillManager.h"
#include "server/zone/objects/player/PlayerObject.h"
#include "templates/tangible/XpPurchaseTemplate.h"
#include "server/zone/managers/stringid/StringIdManager.h"
#include "server/zone/managers/crafting/schematicmap/SchematicMap.h"

class XpPurchaseSuiCallback : public SuiCallback {
public:
	XpPurchaseSuiCallback(ZoneServer* server);

	void run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args);
};

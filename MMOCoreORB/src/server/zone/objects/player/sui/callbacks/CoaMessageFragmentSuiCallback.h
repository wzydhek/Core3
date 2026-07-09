
#pragma once

#include "server/zone/objects/player/sui/SuiCallback.h"
#include "server/zone/objects/tangible/components/generic/CoaMessageDataComponent.h"

class CoaMessageFragmentSuiCallback : public SuiCallback {

public:
	CoaMessageFragmentSuiCallback(ZoneServer* serv);

	void run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args);
};

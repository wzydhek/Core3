#pragma once

#include "server/zone/objects/player/sui/SuiCallback.h"
#include "server/zone/objects/player/FactionStatus.h"
#include "server/zone/objects/creature/CreatureObject.h"

class FieldFactionChangeSuiCallback : public SuiCallback {
private:
	int newStatus;
public:
	virtual ~FieldFactionChangeSuiCallback() { }

	FieldFactionChangeSuiCallback(ZoneServer* server, int status);

	void run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args);
};

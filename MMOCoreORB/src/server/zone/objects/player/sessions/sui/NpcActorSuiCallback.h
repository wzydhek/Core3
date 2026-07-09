/*
 * NpcActorSuiCallback.h
 *
 * Created: 2024-04-22
 * By: Hakry
 *
*/

#pragma once

#include "server/zone/objects/player/sui/SuiCallback.h"
#include "server/zone/objects/player/sui/listbox/SuiListBox.h"
#include "server/zone/objects/tangible/deed/eventperk/EventPerkDeed.h"
#include "server/zone/objects/player/sessions/NpcActorCreationSession.h"

class NpcActorSuiCallback : public SuiCallback {
public:
	NpcActorSuiCallback(ZoneServer* server);

	void run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args);

	void clearSession(CreatureObject* player);
};

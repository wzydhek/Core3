/*
 * NameNpcActorSuiCallback.h
 *
 * Created: 2024-04-23
 * By: Hakry
 *
 */

#pragma once

#include "server/zone/objects/player/sui/SuiCallback.h"
#include "server/zone/objects/player/sessions/NpcActorCreationSession.h"

class NameNpcActorSuiCallback : public SuiCallback {
public:
	NameNpcActorSuiCallback(ZoneServer* server);

	void run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args);

	void clearSession(CreatureObject* player);
};

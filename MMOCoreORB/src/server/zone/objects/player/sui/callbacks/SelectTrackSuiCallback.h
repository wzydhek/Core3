/*
 * DroidPlaybackSuiCallback.h
 *
 */

#pragma once

#include "server/zone/objects/player/sui/SuiCallback.h"
#include "server/zone/objects/tangible/components/droid/DroidPlaybackModuleDataComponent.h"
#include "server/zone/objects/player/sui/messagebox/SuiMessageBox.h"
#include "server/zone/objects/player/sui/callbacks/DeleteTrackConfirmationSuiCallback.h"
#include "server/zone/objects/player/PlayerObject.h"

class SelectTrackSuiCallback : public SuiCallback {
public:
	SelectTrackSuiCallback(ZoneServer* server);

	void run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args);
};

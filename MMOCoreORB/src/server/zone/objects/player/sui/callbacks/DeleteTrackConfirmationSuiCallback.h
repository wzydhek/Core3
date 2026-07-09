/*
 * DroidPlaybackSuiCallback.h
 *
 */

#pragma once

#include "server/zone/objects/player/sui/SuiCallback.h"
#include "server/zone/objects/tangible/components/droid/DroidPlaybackModuleDataComponent.h"
#include "server/zone/objects/player/sui/messagebox/SuiMessageBox.h"
#include "server/zone/objects/creature/ai/DroidObject.h"

class DeleteTrackConfirmationSuiCallback : public SuiCallback {
public:
	Reference<DroidPlaybackModuleDataComponent*> module;
	int track;

	DeleteTrackConfirmationSuiCallback(ZoneServer* server, DroidPlaybackModuleDataComponent* m, int index);

	void run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args);
};

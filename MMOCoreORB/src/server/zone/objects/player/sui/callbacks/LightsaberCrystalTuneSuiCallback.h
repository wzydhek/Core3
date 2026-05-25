/*
 * LightsaberCrystalTuneSuiCallback.h
 *
 *  Created on: Apr 12, 2012
 *      Author: katherine
 */

#pragma once

#include "server/zone/objects/player/sui/SuiCallback.h"

class LightsaberCrystalTuneSuiCallback: public SuiCallback {

public:
	LightsaberCrystalTuneSuiCallback(ZoneServer* serv) :
		SuiCallback(serv) {
	}

	void run(CreatureObject* creature, SuiBox* sui, uint32 eventIndex, Vector<UnicodeString>* args) {
		bool cancelPressed = (eventIndex == 1);

		if (!sui->isMessageBox() || cancelPressed)
			return;

		SuiMessageBox* messageBox = cast<SuiMessageBox*>(sui);

		if (!creature->isPlayerCreature())
			return;

		if (!cancelPressed) {
			ManagedReference<LightsaberCrystalComponent*> crystal = cast<LightsaberCrystalComponent*>(sui->getUsingObject().get().get());

			crystal->tuneCrystal(creature);
		}
	}
};

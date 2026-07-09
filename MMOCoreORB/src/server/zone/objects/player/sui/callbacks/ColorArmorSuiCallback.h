/*
 * ColorArmorSuiCallback.h
 *
 *  Created on: 2/4/2013
 *      Author: bluree
 *		Credits: TA & Valk
 */

#pragma once

#include "server/zone/objects/player/sui/SuiCallback.h"

class ColorArmorSuiCallback : public SuiCallback {
public:
	ColorArmorSuiCallback(ZoneServer* serv);

	void run(CreatureObject* creature, SuiBox* sui, uint32 eventIndex, Vector<UnicodeString>* args);
};

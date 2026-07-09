/*
 * ConfirmDivorceSuiCallback.h
 *
 *  Created on: 6/8/2014
 *      Author: Klivian
 */

#pragma once

#include "server/zone/objects/player/sui/SuiCallback.h"

class ConfirmDivorceSuiCallback : public SuiCallback {

public:

	ConfirmDivorceSuiCallback(ZoneServer* server);

	void run(CreatureObject* creature, SuiBox* sui, uint32 eventIndex, Vector<UnicodeString>* args);
};

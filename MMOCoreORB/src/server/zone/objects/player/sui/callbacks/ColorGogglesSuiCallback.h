/*
 * ColorGogglesSuiCallback.h
 *
 *  Created on: Feb 5, 2012
 *      Author: Kyle
 */

#pragma once

#include "server/zone/objects/player/sui/SuiCallback.h"

class ColorGogglesSuiCallback : public SuiCallback {
	String nodeName;

public:
	ColorGogglesSuiCallback(ZoneServer* serv);

	void run(CreatureObject* creature, SuiBox* sui, uint32 eventIndex, Vector<UnicodeString>* args);
};

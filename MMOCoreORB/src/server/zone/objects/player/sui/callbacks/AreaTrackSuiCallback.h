/*
 * AreaTrackSuiCallback.h
 *
 *  Created on: Feb 5, 2012
 *      Author: Kyle
 */

#pragma once

#include "server/zone/objects/player/sui/SuiCallback.h"
#include "server/zone/objects/player/events/AreaTrackTask.h"
#include "server/zone/packets/object/Emote.h"

class AreaTrackSuiCallback : public SuiCallback {
	String nodeName;

public:
	AreaTrackSuiCallback(ZoneServer* serv, const String& name);

	void run(CreatureObject* creature, SuiBox* sui, uint32 eventIndex, Vector<UnicodeString>* args);
};

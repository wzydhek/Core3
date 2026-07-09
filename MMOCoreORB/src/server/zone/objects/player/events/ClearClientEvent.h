/*
 * ClearClientEvent.h
 *
 *  Created on: Feb 14, 2010
 *      Author: oru
 */

#pragma once

#include "server/zone/objects/creature/CreatureObject.h"

class ClearClientEvent : public Task {
	ManagedReference<CreatureObject*> player;
	ManagedReference<ZoneClientSession*> client;

public:
	ClearClientEvent(CreatureObject* pl, ZoneClientSession* cl);

	void run();

};

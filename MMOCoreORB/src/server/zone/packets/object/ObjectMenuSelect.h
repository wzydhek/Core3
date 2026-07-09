/*
 * ObjectMenuSelect.h
 *
 *  Created on: 12/08/2009
 *      Author: victor
 */

#pragma once

#include "server/zone/packets/MessageCallback.h"

class ObjectMenuSelectCallback : public MessageCallback {
	uint64 objectID;
	uint8 radialID;
public:
	ObjectMenuSelectCallback(ZoneClientSession* client, ZoneProcessServer* server);

	void parse(Message* message);

	void run();
};

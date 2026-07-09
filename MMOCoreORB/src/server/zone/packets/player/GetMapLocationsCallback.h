/*
 * GetMapLocationsCallback.h
 *
 *  Created on: 18/06/2010
 *      Author: victor
 */

#pragma once

#include "server/zone/packets/MessageCallback.h"

class GetMapLocationsCallback : public MessageCallback {
	String zoneName;

public:
	GetMapLocationsCallback(ZoneClientSession* client, ZoneProcessServer* server);

	void parse(Message* message);

	void run();
};

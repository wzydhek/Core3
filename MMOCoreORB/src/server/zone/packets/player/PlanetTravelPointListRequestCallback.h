/*
 * PlanetTravelPointListRequestCallback.h
 *
 *  Created on: 31/05/2010
 *      Author: victor
 */

#pragma once

#include "server/zone/packets/MessageCallback.h"

class PlanetTravelPointListRequestCallback : public MessageCallback {
	String zoneName;

public:
	PlanetTravelPointListRequestCallback(ZoneClientSession* client, ZoneProcessServer* server);

	void parse(Message* message);

	void run();
};

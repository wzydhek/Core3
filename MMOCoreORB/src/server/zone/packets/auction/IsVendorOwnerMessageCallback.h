/*
 * IsVendorOwnerMessageCallback.h
 *
 *  Created on: 30/01/2010
 *      Author: victor
 */

#pragma once

#include "server/zone/packets/MessageCallback.h"

class IsVendorOwnerMessageCallback : public MessageCallback {
	uint64 oid;

public:
	IsVendorOwnerMessageCallback(ZoneClientSession* client, ZoneProcessServer* server);

	void parse(Message* message);

	void run();
};

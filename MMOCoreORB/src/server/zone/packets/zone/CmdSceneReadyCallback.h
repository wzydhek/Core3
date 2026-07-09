/*
 * CmdSceneReadyCallback.h
 *
 *  Created on: Sep 6, 2009
 *      Author: theanswer
 */

#pragma once

#include "server/zone/packets/MessageCallback.h"

class CmdSceneReadyCallback : public MessageCallback {
public:
	CmdSceneReadyCallback(ZoneClientSession* client, ZoneProcessServer* server);

	void parse(Message* message);

	void run();
};

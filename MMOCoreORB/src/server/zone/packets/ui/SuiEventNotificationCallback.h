/*
 * SuiEventNotificationCallback.h
 *
 *  Created on: 30/01/2010
 *      Author: victor
 */

#pragma once

#include "server/zone/packets/MessageCallback.h"

class SuiEventNotificationCallback : public MessageCallback {
	uint32 pageId;
	uint32 eventIndex;
	uint32 listSize1;
	uint32 listSize2;
	Vector<UnicodeString> arguments;

public:
	SuiEventNotificationCallback(ZoneClientSession* client, ZoneProcessServer* server);

	void parse(Message* message);

	void run();
};

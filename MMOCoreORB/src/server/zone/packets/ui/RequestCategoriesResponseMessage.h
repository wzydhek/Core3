/*
 * RequestCategoriesResponseMessage.h
 *
 *  Created on: Nov 25, 2008
 *      Author: swgemu
 */

#pragma once

#include "server/zone/managers/holocron/BugCategory.h"
#include "engine/service/proto/BaseMessage.h"
#include "server/zone/packets/MessageCallback.h"

namespace server {
namespace zone {
namespace packets {
namespace ui {

class RequestCategoriesResponseMessage : public BaseMessage {
public:
	RequestCategoriesResponseMessage(SortedVector<BugCategory>* categories);
};

class RequestCategoriesMessageCallback : public MessageCallback {
	String language;

public:
	RequestCategoriesMessageCallback(ZoneClientSession* client, ZoneProcessServer* server);

	void parse(Message* message);

	void run();
};

} // namespace ui
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::ui;

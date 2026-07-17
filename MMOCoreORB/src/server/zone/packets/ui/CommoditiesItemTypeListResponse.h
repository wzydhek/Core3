/*
 * CommoditiesItemTypeListResponse.h
 *
 *  Created on: Nov 28, 2008
 *      Author: swgemu
 */

#pragma once

#include "engine/service/proto/BaseMessage.h"
#include "../MessageCallback.h"

namespace server {
namespace zone {
namespace packets {
namespace ui {

class CommoditiesItemTypeListResponse : public BaseMessage {
public:
	CommoditiesItemTypeListResponse();

};

class CommoditiesItemTypeListRequestCallback : public MessageCallback {
	String request;
public:
	CommoditiesItemTypeListRequestCallback(ZoneClientSession* client, ZoneProcessServer* server);

	void parse(Message* message);

	void run();
};

} // namespace ui
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::ui;

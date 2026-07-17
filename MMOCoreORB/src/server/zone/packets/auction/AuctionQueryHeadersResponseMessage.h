/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/service/proto/BaseMessage.h"
#include "server/zone/objects/auction/AuctionItem.h"
#include "server/zone/objects/creature/CreatureObject.h"

namespace server {
namespace zone {
namespace packets {
namespace auction {

class AuctionQueryHeadersResponseMessage : public BaseMessage {

	Vector<ManagedReference<AuctionItem*> > itemList;

	SortedVector<String> locationList;

	ManagedReference<CreatureObject*> player;

public:
	AuctionQueryHeadersResponseMessage(int screen, int counter, CreatureObject* player);

	void addItemToList(AuctionItem* ai);

	void dumpLocationList();

	void dumpItemNameList();

	void dumpItemInfoList();

	void createMessage(int offset = 0, bool continues = false);

	int getListSize();

};

} // namespace auction
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::auction;

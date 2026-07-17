/*
 * ObjectMenuRequest.h
 *
 *  Created on: 03/08/2009
 *      Author: victor
 */

#pragma once

#include "../MessageCallback.h"
#include "ObjectControllerMessageCallback.h"
#include "ObjectMenuResponse.h"

namespace server {
namespace zone {
namespace packets {
namespace object {

class RadialClientItem {
	uint8 index;
	uint8 parentid;
	uint8 radialid;
	uint8 callback;

	UnicodeString command;

public:
	RadialClientItem();

	RadialClientItem(uint8 i, uint8 p, uint8 r, uint8 call, UnicodeString& c);

	RadialClientItem(const RadialClientItem& c);

	RadialClientItem& operator=(const RadialClientItem& c);

	void addToResponse(ObjectMenuResponse* menuResponse);

	bool toBinaryStream(ObjectOutputStream* stream);

	bool parseFromBinaryStream(ObjectInputStream* stream);
};

class ObjectMenuRequestCallback : public MessageCallback {
	int unknownSize;
	uint64 objectID;
	uint64 playerID;

	uint8 counter;

	//Reference<ObjectMenuResponse*> menuResponse;

	ObjectControllerMessageCallback* objectControllerMain;
	Vector<RadialClientItem> radialItems;

public:
	ObjectMenuRequestCallback(ObjectControllerMessageCallback* objectControllerCallback);

	void parse(Message* message);

	void run();
};

} // namespace object
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::object;

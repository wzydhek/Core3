#include "ConnectPlayerResponseMessage.h"

ConnectPlayerResponseMessage::ConnectPlayerResponseMessage() : BaseMessage() {
	insertShort(0x02);
	insertInt(0x6137556F);

	insertInt(0);
}

ConnectPlayerMessageCallback::ConnectPlayerMessageCallback(ZoneClientSession* client, ZoneProcessServer* server) : MessageCallback(client, server) {
}

void ConnectPlayerMessageCallback::parse(Message* message) {
}

void ConnectPlayerMessageCallback::run() {
	ConnectPlayerResponseMessage* cprm = new ConnectPlayerResponseMessage();
	client->sendMessage(cprm);
}
#include "MessageCallback.h"

MessageCallback::MessageCallback(ZoneClientSession* client, ZoneProcessServer* server) {
	MessageCallback::client = client;
	MessageCallback::server = server;

	setLoggingName("MessageCallback");
}

MessageCallback::~MessageCallback() {
}

bool MessageCallback::parseMessage(Message* packet) {
	try {
		parse(packet);

	} catch (const Exception& e) {
		error("exception while parsing message in ZonePacketHandler");
		error(e.getMessage());
		e.printStackTrace();

		return false;
	}

	return true;
}

ZoneClientSession* MessageCallback::getClient() const {
	return client.get();
}

ZoneProcessServer* MessageCallback::getServer() const {
	return server;
}
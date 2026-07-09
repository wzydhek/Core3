#include "ZoneHandler.h"

ZoneSessionMap::ZoneSessionMap(int maxconn) : HashTable<uint64, Reference<ZoneClientSession*>>((int)(maxconn * 1.25f)) {
	maxConnections = maxconn;
}

bool ZoneSessionMap::add(ZoneClientSession* client) {
	if (HashTable<uint64, Reference<ZoneClientSession*>>::put(client->getSession()->getNetworkID(), client) == nullptr) {
		return true;
	} else
		return false;
}

bool ZoneSessionMap::remove(ZoneClientSession* client) {
	if (HashTable<uint64, Reference<ZoneClientSession*>>::remove(client->getSession()->getNetworkID()) != nullptr) {
		return true;
	} else
		return false;
}

ZoneHandler::ZoneHandler(ZoneServer* server) {
	zoneServerRef = server;
}

void ZoneHandler::initialize() {
	ZoneServer* server = zoneServerRef.getForUpdate();

	server->initialize();
}

ServiceClient* ZoneHandler::createConnection(Socket* sock, SocketAddress& addr) {
	ZoneServer* server = zoneServerRef.getForUpdate();

	Reference<ZoneClientSession*> client = server->createConnection(sock, addr);

	Locker locker(&guard);

	clients.add(client);

	return client->getSession();
}

bool ZoneHandler::deleteConnection(ServiceClient* session) {
	Reference<ZoneClientSession*> client = getClientSession(session);

	client->disconnect();
	client->disconnect(true);

	Locker locker(&guard);

	clients.remove(client);

	return false;
}

void ZoneHandler::handleMessage(ServiceClient* session, Packet* message) {
	ZoneServer* server = zoneServerRef.getForUpdate();

	ManagedReference<ZoneClientSession*> client = getClientSession(session);

	if (client != nullptr)
		server->handleMessage(client, message);
}

void ZoneHandler::processMessage(Message* message) {
	ZoneServer* server = zoneServerRef.getForUpdate();

	return server->processMessage(message);
}

bool ZoneHandler::handleError(ServiceClient* session, Exception& e) {
	ZoneServer* server = zoneServerRef.getForUpdate();

	Reference<ZoneClientSession*> client = getClientSession(session);

	return server->handleError(client, e);
}

Reference<ZoneClientSession*> ZoneHandler::getClientSession(ServiceClient* session) {
	ReadLocker locker(&guard);
	return clients.get(session->getNetworkID());
}
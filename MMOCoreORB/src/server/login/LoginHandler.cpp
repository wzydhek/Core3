#include "LoginHandler.h"

LoginSessionMap::LoginSessionMap(int maxconn) : HashTable<uint64, Reference<LoginClient*>>((int)(maxconn * 1.25f)) {
	maxConnections = maxconn;
}

bool LoginSessionMap::add(LoginClient* client) {
	if (HashTable<uint64, Reference<LoginClient*>>::put(client->getSession()->getNetworkID(), client) == nullptr) {
		return true;
	} else
		return false;
}

bool LoginSessionMap::remove(LoginClient* client) {
	if (HashTable<uint64, Reference<LoginClient*>>::remove(client->getSession()->getNetworkID()) != nullptr) {
		return true;
	} else
		return false;
}

LoginClient* LoginSessionMap::get(uint64 id) {
	return HashTable<uint64, Reference<LoginClient*>>::get(id);
}

LoginHandler::LoginHandler() {
}

void LoginHandler::initialize() {
	server->initialize();
}

ServiceClient* LoginHandler::createConnection(Socket* sock, SocketAddress& addr) {
	LoginClient* client = server->createConnection(sock, addr);

	clients.add(client);

	return client->getSession();
}

bool LoginHandler::deleteConnection(ServiceClient* session) {
	Reference<LoginClient*> client = getClient(session);

	if (client != nullptr) {
		client->disconnect();

		clients.remove(client);
	}

	return false;
}

void LoginHandler::handleMessage(ServiceClient* session, Packet* message) {
	Reference<LoginClient*> client = getClient(session);

	server->handleMessage(client, message);
}

void LoginHandler::processMessage(Message* message) {
	return server->processMessage(message);
}

bool LoginHandler::handleError(ServiceClient* client, Exception& e) {
	return server->handleError(client, e);
}

void LoginHandler::setLoginSerrver(LoginServer* server) {
	this->server = server;
}

LoginClient* LoginHandler::getClient(ServiceClient* session) {
	return clients.get(session->getNetworkID());
}
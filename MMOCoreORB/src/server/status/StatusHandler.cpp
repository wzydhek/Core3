#include "StatusHandler.h"

StatusHandler::StatusHandler(StatusServer* server) {
	statusServerRef = server;
}

void StatusHandler::initialize() {
}

ServiceClient* StatusHandler::createConnection(Socket* sock, SocketAddress& addr) {
	return statusServerRef->createConnection(sock, addr);
}

bool StatusHandler::deleteConnection(ServiceClient* client) {
	return false;
}

void StatusHandler::handleMessage(ServiceClient* client, Packet* message) {
}

void StatusHandler::processMessage(Message* message) {
}

bool StatusHandler::handleError(ServiceClient* client, Exception& e) {
	return false;
}
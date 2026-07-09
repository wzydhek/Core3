/*
 * StatusHandler.h
 *
 *  Created on: Oct 5, 2010
 *      Author: oru
 */

#pragma once

#include "StatusServer.h"

class StatusHandler: public ServiceHandler {
	StatusServer* statusServerRef;

public:
	StatusHandler(StatusServer* server);

	void initialize();

	ServiceClient* createConnection(Socket* sock, SocketAddress& addr);

	bool deleteConnection(ServiceClient* client);

	void handleMessage(ServiceClient* client, Packet* message);

	void processMessage(Message* message);

	bool handleError(ServiceClient* client, Exception& e);

};

using namespace server::zone;

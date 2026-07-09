/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/ZoneServer.h"
#include "server/zone/ZoneClientSession.h"

namespace server {
  namespace zone {

	class ZoneSessionMap : public HashTable<uint64, Reference<ZoneClientSession*> > {

		int maxConnections;

	public:
		ZoneSessionMap(int maxconn = 10000);

		bool add(ZoneClientSession* client);

		bool remove(ZoneClientSession* client);

	};

	class ZoneHandler: public ServiceHandler {
		ManagedReference<ZoneServer*> zoneServerRef;

		ZoneSessionMap clients;

		ReadWriteLock guard;

	public:
		ZoneHandler(ZoneServer* server);

		void initialize();

		ServiceClient* createConnection(Socket* sock, SocketAddress& addr);

		bool deleteConnection(ServiceClient* session);

		void handleMessage(ServiceClient* session, Packet* message);

		void processMessage(Message* message);

		bool handleError(ServiceClient* session, Exception& e);

		Reference<ZoneClientSession*> getClientSession(ServiceClient* session);
	};

  } // namespace zone
} // namespace server

using namespace server::zone;

/*
 * LoginHandler.h
 *
 *  Created on: Oct 13, 2010
 *      Author: crush
 */

#pragma once

#include "server/login/LoginClient.h"
#include "server/login/LoginServer.h"

namespace server {
  namespace login {

	class LoginSessionMap : private HashTable<uint64, Reference<LoginClient*> > {
		int maxConnections;

	public:
		LoginSessionMap(int maxconn = 10000);

		bool add(LoginClient* client);

		bool remove(LoginClient* client);

		LoginClient* get(uint64 id);

	};

	class LoginHandler: public ServiceHandler {
		Reference<LoginServer*> server;

		LoginSessionMap clients;

	public:
		LoginHandler();

		void initialize();

		ServiceClient* createConnection(Socket* sock, SocketAddress& addr);

		bool deleteConnection(ServiceClient* session);

		void handleMessage(ServiceClient* session, Packet* message);

		void processMessage(Message* message);

		bool handleError(ServiceClient* client, Exception& e);

		void setLoginSerrver(LoginServer* server);

		LoginClient* getClient(ServiceClient* session);
	};

  } // namespace login
} // namespace server

using namespace server::login;

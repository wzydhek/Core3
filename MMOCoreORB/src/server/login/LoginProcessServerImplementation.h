/*
 * LoginProcessServerImplementation.h
 *
 *  Created on: Oct 13, 2010
 *      Author: crush
 */

#pragma once

#include "engine/engine.h"

namespace server {
	namespace login {

		class LoginPacketHandler;
		class LoginServer;

		class LoginProcessServerImplementation : public Object {
			WeakReference<LoginServer*> server;

			UniqueReference<LoginPacketHandler*> loginPacketHandler;

		public:
			LoginProcessServerImplementation(LoginServer* serv);
			~LoginProcessServerImplementation();

			void initialize();

			WeakReference<LoginServer*> getLoginServer();

			LoginPacketHandler* getPacketHandler();
		};

	} // namspace login
} // namespace server

using namespace server::login;

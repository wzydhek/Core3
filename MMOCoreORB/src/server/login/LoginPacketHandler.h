/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "LoginClient.h"

namespace server {
namespace login {

	class LoginServer;
	class LoginProcessServerImplementation;

	class LoginPacketHandler : public Logger {
		LoginProcessServerImplementation* processServer;
		Reference<LoginServer*> server;

	public:

		LoginPacketHandler();

		LoginPacketHandler(const String& s, LoginProcessServerImplementation* serv);

		~LoginPacketHandler() {
		}

		void handleMessage(Message* pack);

		void handleClientPermissionsMessage(Message* pack);
		void handleSelectCharacter(Message* pack);
		void handleCmdSceneReady(Message* packet);
		void handleLoginClientID(LoginClient* client, Message* packet);
		void handleDeleteCharacterMessage(LoginClient* client, Message* pack);

	};
}
}

using namespace server::login;

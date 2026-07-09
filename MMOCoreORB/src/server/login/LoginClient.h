/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/engine.h"
#include "engine/service/proto/packets/DisconnectMessage.h"
#include "packets/ErrorMessage.h"
#include "engine/log/Logger.h"

namespace server {
namespace login {

	class LoginClient : public Object {
		Reference<BaseClientProxy*> session;
		uint32 accountID = -1;

	public:
		LoginClient(BaseClientProxy* session);

		~LoginClient();

		void disconnect(bool doLock = true);

		String getIPAddress() const;

		void sendMessage(BasePacket* msg);

		void sendErrorMessage(const String& title, const String& text, bool fatal = false, bool sendDisconnect = true);

		void info(const String& msg, bool doLog = true) const;

		LoggerHelper error() const;

		LoggerHelper info(bool val) const;

		LoggerHelper warning() const;

		LoggerHelper debug() const;

		ServiceClient* getSession();

		const ServiceClient* getSession() const;

		uint32 getAccountID() const;

		void setAccountID(uint32 account);

		bool hasAccount() const;
	};

  } // namespace login
} // namespace server

using namespace server::login;

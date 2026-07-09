/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "LoginPacketHandler.h"

namespace server {
	namespace login {

		class LoginMessageProcessorTask : public Task {
			Reference<Message*> message;

			LoginPacketHandler* packetHandler;

		public:
			LoginMessageProcessorTask(Message* msg, LoginPacketHandler* handler);

			~LoginMessageProcessorTask();

			void run();

		};

	} // namespace login
} // namespace server

using namespace server::login;

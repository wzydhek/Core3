/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/service/proto/BaseMessage.h"

namespace server {
namespace login {
namespace packets {

class ErrorMessage : public BaseMessage {
public:
	ErrorMessage(const String& errorType, const String& errorMsg, uint8 fatal);
};

} // namespace packets
} // namespace login
} // namespace server

using namespace server::login::packets;

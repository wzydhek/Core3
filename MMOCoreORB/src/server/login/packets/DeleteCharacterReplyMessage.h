/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/service/proto/BaseMessage.h"

namespace server {
namespace login {
namespace packets {

class DeleteCharacterReplyMessage : public BaseMessage {
public:
	DeleteCharacterReplyMessage(int Failure);
};

} // namespace packets
} // namespace login
} // namespace server

using namespace server::login::packets;

/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/service/proto/BaseMessage.h"

//This packet is sent when we verify the data (namely the charname) when the client sends ClientCreateCharacter
//If it fails we are sending the failure notice here:

class ClientCreateCharacterFailed : public BaseMessage {
public:
	ClientCreateCharacterFailed(String error_String);
};

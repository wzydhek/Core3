/*
 				Copyright <SWGEmu>
		See file COPYING for copying conditions. */

#pragma once

#include "ObjectControllerMessage.h"
#include "server/chat/StringIdChatParameter.h"

class SpatialChat: public ObjectControllerMessage {
public:
	SpatialChat(uint64 senderID, uint64 targetID, uint64 chatTargetID, const UnicodeString& message, uint16 volume, uint32 spatialChatType, uint32 moodType, uint32 chatFlags, uint8 languageID);

	SpatialChat(uint64 senderID, uint64 targetID, uint64 chatTargetID, const String& file, const String& stringid, uint16 volume, uint32 spatialChatType, uint32 moodType, uint32 chatFlags, uint8 languageID);

	SpatialChat(uint64 senderID, uint64 targetID, uint64 chatTargetID, const StringIdChatParameter& stringid, uint16 volume, uint16 spatialChatType, uint16 moodType, uint32 chatFlags, uint8 languageID);
};

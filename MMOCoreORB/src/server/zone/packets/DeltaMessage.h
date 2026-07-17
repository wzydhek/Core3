/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/service/proto/BaseMessage.h"
#include "server/zone/objects/scene/variables/StringId.h"

namespace server {
namespace zone {
namespace packets {

class DeltaMessage : public BaseMessage {
	int updateCount;

public:
	DeltaMessage(uint64 oid, uint32 name, uint8 type);

	void startUpdate(uint16 type);

	void addByteUpdate(uint16 type, uint8 value);

	void addShortUpdate(uint16 type, uint16 value);

	void addIntUpdate(uint16 type, uint32 value);

	void addLongUpdate(uint16 type, uint64 value);

	void addFloatUpdate(uint16 type, float value);

	void addAsciiUpdate(uint16 type, const String& val);

	void addStringIdUpdate(uint16 type, const StringId& val);

	void addUnicodeUpdate(uint16 type, const String& val);

	void addUnicodeUpdate(uint16 type, const UnicodeString& val);

	void startList(uint32 cnt, uint32 updcnt);

	void addListIntElement(uint16 index, uint32 value);

	void addListFloatElement(uint16 index, float value);

	void addListLongElement(uint16 index, uint64 value);

	void addListAsciiElement(const String& value);

	void removeListIntElement(uint16 index, uint32 value);

	void removeListFloatElement(uint16 index, float value);

	void removeListLongElement(uint16 index, uint64 value);

	void removeListLongElement(uint16 index);

	void removeListAsciiElement(const String& value);

	void close();

};

} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets;

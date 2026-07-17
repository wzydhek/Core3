/*
 				Copyright <SWGEmu>
		See file COPYING for copying conditions. */

#pragma once

#include "engine/service/proto/BaseMessage.h"
#include "server/zone/objects/scene/variables/StringId.h"
#include "server/zone/objects/scene/SceneObject.h"

namespace server {
namespace zone {
namespace packets {

class BaseLineMessage: public BaseMessage {
public:
	BaseLineMessage(const SceneObject* obj, uint32 name, uint8 type, uint16 opcnt);

	BaseLineMessage(uint64 oid, uint32 name, uint8 type, uint16 opcnt);

	void setSize();

	void insertStringId(const StringId* id);

	void insertCustomName(const UnicodeString& name);

};

} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets;

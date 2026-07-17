/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions. */

#pragma once

#include "engine/service/proto/BaseMessage.h"

namespace server {
namespace zone {
namespace packets {
namespace ui {

class PermissionListCreateMessage : public BaseMessage {
	Vector<String> nameList;
	UnicodeString cellName;

public:
	PermissionListCreateMessage(const String& cell);

	void addName(const String& name);

	//Dumps the list, finishes packet.
	void generateMessage();

};

} // namespace ui
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::ui;

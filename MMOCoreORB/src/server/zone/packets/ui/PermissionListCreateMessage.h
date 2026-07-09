/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions. */

#pragma once

#include "engine/service/proto/BaseMessage.h"

class PermissionListCreateMessage : public BaseMessage {
	Vector<String> nameList;
	UnicodeString cellName;

public:
	PermissionListCreateMessage(const String& cell);

	void addName(const String& name);

	//Dumps the list, finishes packet.
	void generateMessage();

};

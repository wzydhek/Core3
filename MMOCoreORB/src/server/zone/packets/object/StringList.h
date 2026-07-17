/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "ObjectControllerMessage.h"
#include "server/zone/objects/creature/CreatureObject.h"

namespace server {
namespace zone {
namespace packets {
namespace object {

class StringList : public ObjectControllerMessage {
	uint8 optionCount;

public:

	StringList(CreatureObject* creo);

	void insertOption(const String& file, const String& str);

	void insertOption(const String& option);

	void insertOption(const UnicodeString& option);

	void updateOptionCount();

	int getOptionCount();
};

} // namespace object
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::object;

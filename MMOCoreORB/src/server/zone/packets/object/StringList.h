/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "ObjectControllerMessage.h"
#include "server/zone/objects/creature/CreatureObject.h"

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

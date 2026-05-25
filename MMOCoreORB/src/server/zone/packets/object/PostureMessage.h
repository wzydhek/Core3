/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "ObjectControllerMessage.h"

class PostureMessage : public ObjectControllerMessage {
public:
	PostureMessage(CreatureObject* creo) : ObjectControllerMessage(creo->getObjectID(), 0x1B, 0x131) {
		insertByte(creo->getPosture());
		insertByte(0x01);
	}
};

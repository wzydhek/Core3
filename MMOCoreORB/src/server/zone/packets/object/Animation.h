/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "ObjectControllerMessage.h"

class Animation : public ObjectControllerMessage {
public:
	Animation(CreatureObject* creo, const String& anim) 
			: ObjectControllerMessage(creo->getObjectID(), 0x1B, 0xF2, false) {
				
			insertAscii(anim.toCharArray());
	}

};

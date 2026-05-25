/*
 * GenericResponse.h
 *
 *  Created on: Oct 11, 2008
 *      Author: swgemu
 */

#pragma once

#include "server/zone/packets/object/ObjectControllerMessage.h"

class GenericResponse : public ObjectControllerMessage {
public:
	GenericResponse(CreatureObject* play, uint32 msg, uint8 byte1, uint8 byte2)
			: ObjectControllerMessage(play->getObjectID(), 0x0B, 0xEE) {
		insertInt(msg);
		insertByte(byte1);
		insertByte(byte2);
		//setSize();
	}

};

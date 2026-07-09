/*
 * GenericResponse.h
 *
 *  Created on: Oct 11, 2008
 *      Author: swgemu
 */

#pragma once

#include "server/zone/packets/object/ObjectControllerMessage.h"
#include "server/zone/objects/creature/CreatureObject.h"

class GenericResponse : public ObjectControllerMessage {
public:
	GenericResponse(CreatureObject* play, uint32 msg, uint8 byte1, uint8 byte2);

};

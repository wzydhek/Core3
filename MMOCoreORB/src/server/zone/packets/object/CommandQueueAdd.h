/*
 * CommandQueueAdd.h
 *
 *  Created on: Apr 14, 2015
 *      Author: swgemu
 */

#pragma once

#include "ObjectControllerMessage.h"
#include "server/zone/objects/creature/CreatureObject.h"

class CommandQueueAdd : public ObjectControllerMessage {
public:
	CommandQueueAdd(CreatureObject* creo, uint32 actionCRC, uint32 actioncnt);

};

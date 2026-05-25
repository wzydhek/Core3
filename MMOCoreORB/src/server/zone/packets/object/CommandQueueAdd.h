/*
 * CommandQueueAdd.h
 *
 *  Created on: Apr 14, 2015
 *      Author: swgemu
 */

#pragma once

#include "ObjectControllerMessage.h"

class CommandQueueAdd : public ObjectControllerMessage {
public:
	CommandQueueAdd(CreatureObject* creo, uint32 actionCRC, uint32 actioncnt)
			: ObjectControllerMessage(creo->getObjectID(), 0x0B, 0x167) {
		insertInt(actioncnt);
		insertInt(actionCRC);
	}

};

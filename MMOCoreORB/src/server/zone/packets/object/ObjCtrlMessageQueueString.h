/*
 * ObjCtrlMessageQueueString.h
 *
 *  Created on: 10/01/2012
 *      Author: victor
 */

#pragma once

#include "ObjectControllerMessage.h"

class ObjCtrlMessageQueueString : public ObjectControllerMessage {
public:
	ObjCtrlMessageQueueString(SceneObject* creo, const String& data, uint32 type)
			: ObjectControllerMessage(creo->getObjectID(), 0x1B, type, false) {

			insertAscii(data.toCharArray());
	}
};

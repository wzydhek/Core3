/*
 * ObjCtrlMessageQueueString.h
 *
 *  Created on: 10/01/2012
 *      Author: victor
 */

#pragma once

#include "ObjectControllerMessage.h"
#include "server/zone/objects/scene/SceneObject.h"

class ObjCtrlMessageQueueString : public ObjectControllerMessage {
public:
	ObjCtrlMessageQueueString(SceneObject* creo, const String& data, uint32 type);
};

/*
 * PlayClientEventObjectMessage.h
 *
 *  Created on: 09/01/2012
 *      Author: victor
 */

#pragma once

#include "engine/service/proto/BaseMessage.h"
#include "server/zone/objects/scene/SceneObject.h"

class PlayClientEventObjectMessage : public BaseMessage {
public:
	PlayClientEventObjectMessage(SceneObject* obj, const String& file, const String& aux);

};

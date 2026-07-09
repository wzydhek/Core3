/*
 * ShipUpdateTransformCollisionMessage.h
 *
 *  Created on: 01/09/2011
 *      Author: TheAnswer
 */

#pragma once

#include "server/zone/objects/scene/SceneObject.h"

class ShipUpdateTransformCollisionMessage : public BaseMessage {
public:
	ShipUpdateTransformCollisionMessage(SceneObject* scno);
};

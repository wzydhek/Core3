/*
 * JtlShipListResponse.h
 *
 *  Created on: Apr 25, 2011
 *      Author: crush
 */

#pragma once

#include "ObjectControllerMessage.h"
#include "server/zone/objects/creature/CreatureObject.h"
#include "server/zone/objects/scene/SceneObject.h"

class JtlShipListResponse: public ObjectControllerMessage {
public:
	JtlShipListResponse(CreatureObject* player, SceneObject* terminal);
};

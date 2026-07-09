/*
 * OpenLotteryWindow.h
 *
 *  Created on: Mar 16, 2015
 *      Author: swgemu
 */

#pragma once

#include "ObjectControllerMessage.h"
#include "server/zone/objects/scene/SceneObject.h"
#include "server/zone/objects/creature/CreatureObject.h"

class OpenLotteryWindow : public ObjectControllerMessage {
public:
	OpenLotteryWindow(CreatureObject* creo, SceneObject* inventory);

};

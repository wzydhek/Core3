/*
 * TargetUpdate.h
 *
 *  Created on: 10/08/2009
 *      Author: victor
 */

#pragma once

#include "../MessageCallback.h"
#include "ObjectControllerMessageCallback.h"
#include "server/zone/objects/creature/CreatureObject.h"

class TargetUpdateCallback : public MessageCallback {
	int size;
	uint64 targetID;

	ObjectControllerMessageCallback* objectControllerMain;
public:
	TargetUpdateCallback(ObjectControllerMessageCallback* objectControllerCallback);

	void parse(Message* message);

	void run();

	void setPlayerTargetID(CreatureObject* object);

	void setShipTargetID(CreatureObject* object);
};

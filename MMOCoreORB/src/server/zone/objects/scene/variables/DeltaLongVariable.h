/*
 * DeltaLongVariable.h
 *
 *  Created on: 18/10/2013
 *      Author: victor
 */

#pragma once

#include "DeltaBasicVariable.h"

template<int BaselineName, uint8 Type, int DeltaID>
class DeltaLongVariable : public DeltaBasicVariable<uint64> {
public:
	void update(int newValue, bool broadcastStandalone = false, server::zone::objects::scene::SceneObject* obj = nullptr) {
		set(newValue);

		if (broadcastStandalone) {
			broadcastStandaloneDeltaMessage(obj);
		}
	}

	void broadcastStandaloneDeltaMessage(server::zone::objects::scene::SceneObject* obj) {
		DeltaMessage* msg = new DeltaMessage(obj->getObjectID(), BaselineName, Type);
		addToDeltaMessage(msg);
		msg->close();

		obj->broadcastMessage(msg, true);
	}

	void addToDeltaMessage(DeltaMessage* msg) {
		msg->addLongUpdate(DeltaID, object);
	}
};

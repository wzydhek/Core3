/*
 * DeltaIntVariable.h
 *
 *  Created on: 18/10/2013
 *      Author: victor
 */

#pragma once

#include "DeltaBasicVariable.h"

namespace server {
namespace zone {
namespace objects {
namespace scene {
namespace variables {

template<int BaselineName, uint8 Type, int DeltaID>
class DeltaIntVariable : public DeltaBasicVariable<int> {
public:
	void update(int newValue, bool broadcastStandalone = false, SceneObject* obj = nullptr) {
		set(newValue);

		if (broadcastStandalone) {
			broadcastStandaloneDeltaMessage(obj);
		}
	}

	void broadcastStandaloneDeltaMessage(SceneObject* obj) {
		DeltaMessage* msg = new DeltaMessage(obj->getObjectID(), BaselineName, Type);
		addToDeltaMessage(msg);
		msg->close();

		obj->broadcastMessage(msg, true);
	}

	void addToDeltaMessage(DeltaMessage* msg) {
		msg->addIntUpdate(DeltaID, object);
	}
};

} // namespace variables
} // namespace scene
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::scene::variables;

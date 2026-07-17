/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions. */

#pragma once

#include "server/zone/packets/object/ObjectControllerMessage.h"
#include "server/zone/packets/object/ObjectControllerMessageCallback.h"
#include "server/zone/objects/scene/SceneObject.h"
#include "server/zone/objects/player/ValidatedPosition.h"
#include "server/zone/packets/object/transform/Transform.h"
#include "server/zone/objects/creature/CreatureObject.h"

namespace server {
namespace zone {
namespace packets {
namespace object {

class DataTransformWithParent : public ObjectControllerMessage {
public:
	DataTransformWithParent(SceneObject* sceneO);
};

class DataTransformWithParentCallback : public MessageCallback {
	ObjectControllerMessageCallback* objectControllerMain;

	ValidatedPosition playerPosition;
	ValidatedPosition* validPosition = nullptr;

	Transform transform;

	long deltaTime;

public:
	DataTransformWithParentCallback(ObjectControllerMessageCallback* objectControllerCallback);

	void parse(Message* message);

	void updateError(CreatureObject* creO, const String& message, bool bounceBack = false) const;

	void run();

	void updatePosition(CreatureObject* creO, SceneObject* parent);

	void updateStatic(CreatureObject* creO, SceneObject* parent);

	void broadcastTransform(CreatureObject* creO, SceneObject* parent, const Vector3& position, bool lightUpdate) const;
};

} // namespace object
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::object;

/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/packets/object/ObjectControllerMessage.h"
#include "server/zone/packets/object/ObjectControllerMessageCallback.h"
#include "server/zone/objects/scene/SceneObject.h"
#include "server/zone/objects/player/ValidatedPosition.h"
#include "server/zone/packets/object/transform/Transform.h"
#include "server/zone/objects/creature/CreatureObject.h"


class DataTransform : public ObjectControllerMessage {
public:
	DataTransform(SceneObject* sceneO);

	DataTransform(SceneObject* sceneO, const Vector3& position);
};

class DataTransformCallback : public MessageCallback {
	ObjectControllerMessageCallback* objectControllerMain;

	ValidatedPosition playerPosition;
	ValidatedPosition* validPosition = nullptr;

	Transform transform;

	long deltaTime;

public:
	DataTransformCallback(ObjectControllerMessageCallback* objectControllerCallback);

	void parse(Message* message);

	void updateError(CreatureObject* creO, const String& message, bool bounceBack = false, float bounceDistance = 0.f) const;

	void run();

	void updatePosition(CreatureObject* creO, SceneObject* parent);

	void updateStatic(CreatureObject* creO, SceneObject* parent);

	void updateTransform(CreatureObject* creO, SceneObject* parent, const Vector3& position) const;
};

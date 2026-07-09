
#pragma once

#include "RecycleResourceTask.h"
#include "server/zone/objects/scene/components/ContainerComponent.h"

class RecycleToolContainerComponent : public ContainerComponent {
public:
	int notifyObjectInserted(SceneObject* sceneObject, SceneObject* object) const;

	bool removeObject(SceneObject* sceneObject, SceneObject* object, SceneObject* destination, bool notifyClient, bool nullifyParent) const;

	int canAddObject(SceneObject* sceneObject, SceneObject* object, int containmentType, String& errorDescription) const;
};

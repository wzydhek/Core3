#pragma once

#include "server/zone/objects/scene/components/ContainerComponent.h"

class ScavengerChestContainerComponent: public ContainerComponent {
public:
	bool checkContainerPermission(SceneObject* container, CreatureObject* creature, uint16 permission) const;
	int notifyObjectRemoved(SceneObject* container, SceneObject*, SceneObject* destination) const;
	int canAddObject(SceneObject* sceneObject, SceneObject* object, int containmentType, String& errorDescription) const;
};

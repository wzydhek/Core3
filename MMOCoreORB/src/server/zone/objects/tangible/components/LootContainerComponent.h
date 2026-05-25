/*
 * LootContainerComponent.h
 *
 *  Created on: Jan 24, 2012
 *      Author: xyborn
 */

#pragma once

#include "server/zone/objects/scene/components/ContainerComponent.h"

class LootContainerComponent: public ContainerComponent {
public:
	int notifyObjectRemoved(SceneObject* sceneObject, SceneObject* object, SceneObject* destination) const;
	bool checkContainerPermission(SceneObject* sceneObject, CreatureObject* creature, uint16 permission) const;
	int canAddObject(SceneObject* sceneObject, SceneObject* object, int containmentType, String& errorDescription) const;
};

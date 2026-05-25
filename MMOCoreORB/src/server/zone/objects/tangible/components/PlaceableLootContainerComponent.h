/*
 * PlacableLootContainerComponent.h
 *
 *  Created on: Mar 13, 2013
 *      Author: root
 */

#pragma once

#include "server/zone/objects/scene/components/ContainerComponent.h"

class PlaceableLootContainerComponent: public ContainerComponent {
public:
	bool checkContainerPermission(SceneObject* sceneObject, CreatureObject* creature, uint16 permission) const;
	int canAddObject(SceneObject* sceneObject, SceneObject* object, int containmentType, String& errorDescription) const;
};

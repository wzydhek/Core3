/*
 * ContainerObjectComponent.h
 *
 *  Created on: 07/02/2012
 *      Author: victor
 */

#pragma once

#include "server/zone/objects/scene/components/ContainerComponent.h"

class ContainerObjectComponent : public ContainerComponent {
public:
	bool checkContainerPermission(SceneObject* sceneObject, CreatureObject* creature, uint16 permission) const;
};

/*
 * EventPerkActorContainerComponent.h
 *
 * Created on: 2024-04-26
 * By: Hakry
 */

#pragma once

#include "server/zone/objects/scene/components/ContainerComponent.h"

class EventPerkActorContainerComponent : public ContainerComponent {
public:
	virtual bool checkContainerPermission(SceneObject* sceneObject, CreatureObject* creature, uint16 permission) const;
};

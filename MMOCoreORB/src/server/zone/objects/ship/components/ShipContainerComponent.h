/*
 * PobShipContainerComponent.h
 */

#pragma once

#include "server/zone/objects/scene/components/ContainerComponent.h"

class ShipContainerComponent : public ContainerComponent, public Logger {
public:
	ShipContainerComponent() {
		setLoggingName("ShipContainerComponent");
	}

	virtual bool checkContainerPermission(SceneObject* sceneObject, CreatureObject* creature, uint16 permission) const;
	virtual bool transferObject(SceneObject* sceneObject, SceneObject* object, int containmentType, bool notifyClient = false, bool allowOverflow = false, bool notifyRoot = true) const;
};

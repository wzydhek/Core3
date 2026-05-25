#pragma once

#include "server/zone/objects/scene/components/GroundZoneComponent.h"

class PersonnelPerkZoneComponent : public GroundZoneComponent {

public:
	void notifyInsertToZone(SceneObject* sceneObject, Zone* zne) const;
};

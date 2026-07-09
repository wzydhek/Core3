/*
 * VendorZoneComponent.h
 *
 *  Created on: Jul 24, 2012
 *      Author: kyle
 */

#pragma once

#include "server/zone/objects/scene/components/GroundZoneComponent.h"
#include "server/zone/objects/tangible/components/vendor/VendorDataComponent.h"
#include "server/zone/TreeEntry.h"

class VendorZoneComponent : public GroundZoneComponent {

public:
	void notifyPositionUpdate(SceneObject* sceneObject, TreeEntry* entry) const;
};

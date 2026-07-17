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

namespace server {
namespace zone {
namespace objects {
namespace tangible {
namespace components {
namespace vendor {

class VendorZoneComponent : public GroundZoneComponent {

public:
	void notifyPositionUpdate(SceneObject* sceneObject, TreeEntry* entry) const;
};

} // namespace vendor
} // namespace components
} // namespace tangible
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::tangible::components::vendor;

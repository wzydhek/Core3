/*
 * StructureZoneComponent.h
 *
 *  Created on: Apr 15, 2012
 *      Author: TragD
 */

#pragma once

#include "engine/engine.h"
#include "server/zone/objects/scene/components/GroundZoneComponent.h"

namespace server {
 namespace zone {
  namespace objects {
   namespace scene {
    class SceneObject;
   }

   namespace structure {
    class StructureObject;
   }
  }

  class Zone;
 }
}

using namespace server::zone::objects::scene;
using namespace server::zone::objects::structure;
using namespace server::zone;

namespace server {
namespace zone {
namespace objects {
namespace structure {
namespace components {

class StructureZoneComponent : public GroundZoneComponent {

public:
	void notifyInsertToZone(SceneObject* sceneObject, Zone* zone) const;
	void notifyRemoveFromZone(SceneObject* sceneObject) const;
};

} // namespace components
} // namespace structure
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::structure::components;

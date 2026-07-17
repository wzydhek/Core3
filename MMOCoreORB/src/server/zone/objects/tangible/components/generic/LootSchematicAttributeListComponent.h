/*
 * LootSchematicAttributeListComponent.h
 *
 *  Created on: 1/29/2012
 *      Author: kyle
 */

#pragma once

#include "templates/tangible/LootSchematicTemplate.h"
#include "server/zone/managers/stringid/StringIdManager.h"
#include "server/zone/objects/creature/CreatureObject.h"
#include "server/zone/objects/scene/SceneObject.h"
#include "server/zone/objects/scene/components/AttributeListComponent.h"

namespace server {
namespace zone {
namespace objects {
namespace tangible {
namespace components {
namespace generic {

class LootSchematicAttributeListComponent: public AttributeListComponent {
public:

	/**
	 * Fills the Attributes
	 * @pre { this object is locked }
	 * @post { this object is locked, menuResponse is complete}
	 * @param menuResponse ObjectMenuResponse that will be sent to the client
	 */
	void fillAttributeList(AttributeListMessage* alm, CreatureObject* creature, SceneObject* object) const;

};

} // namespace generic
} // namespace components
} // namespace tangible
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::tangible::components::generic;

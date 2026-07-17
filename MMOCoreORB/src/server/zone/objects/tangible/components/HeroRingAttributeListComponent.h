
#pragma once

#include "server/zone/objects/scene/components/AttributeListComponent.h"
#include "server/zone/objects/tangible/TangibleObject.h"
#include "server/zone/objects/creature/CreatureObject.h"
#include "server/zone/objects/tangible/components/HeroRingDataComponent.h"

namespace server {
namespace zone {
namespace objects {
namespace tangible {
namespace components {

class HeroRingAttributeListComponent : public AttributeListComponent {
public:
	/**
	 * Fills the Attributes
	 * @pre { this object is locked }
	 * @post { this object is locked, menuResponse is complete}
	 * @param menuResponse ObjectMenuResponse that will be sent to the client
	 */
	void fillAttributeList(AttributeListMessage* alm, CreatureObject* creature, SceneObject* object) const;

	static String getCooldownString(uint32 delta);
};

} // namespace components
} // namespace tangible
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::tangible::components;

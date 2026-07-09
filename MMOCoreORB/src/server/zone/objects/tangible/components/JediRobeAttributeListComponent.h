
#pragma once

#include "server/zone/objects/tangible/wearables/RobeObject.h"
#include "server/zone/objects/scene/components/AttributeListComponent.h"

class JediRobeAttributeListComponent: public AttributeListComponent {
public:

	/**
	 * Fills the Attributes
	 * @pre { this object is locked }
	 * @post { this object is locked, menuResponse is complete}
	 * @param menuResponse ObjectMenuResponse that will be sent to the client
	 */
	void fillAttributeList(AttributeListMessage* alm, CreatureObject* creature, SceneObject* object) const;
};

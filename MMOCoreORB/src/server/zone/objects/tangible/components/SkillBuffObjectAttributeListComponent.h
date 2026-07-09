#pragma once

#pragma once

#include "templates/tangible/SkillBuffTemplate.h"
#include "server/zone/objects/scene/components/AttributeListComponent.h"
#include "server/zone/objects/scene/SceneObject.h"
#include "server/zone/objects/creature/CreatureObject.h"
#include "server/zone/packets/scene/AttributeListMessage.h"

class SkillBuffObjectAttributeListComponent: public AttributeListComponent {
public:

	/**
	 * Fills the Attributes
	 * @pre { this object is locked }
	 * @post { this object is locked, menuResponse is complete}
	 * @param menuResponse ObjectMenuResponse that will be sent to the client
	 */
	void fillAttributeList(AttributeListMessage* alm, CreatureObject* creature, SceneObject* object) const;

};

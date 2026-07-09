/*
 * EventPerkAttributeListComponent.h
 *
 *  Created on: 9/20/2014
 *      Author: Klivian
 */

#pragma once

#include "server/zone/objects/scene/components/AttributeListComponent.h"
#include "server/zone/objects/tangible/components/EventPerkDataComponent.h"
#include "server/zone/objects/tangible/deed/eventperk/EventPerkDeed.h"
#include "server/zone/objects/creature/CreatureObject.h"
#include "server/zone/objects/scene/SceneObject.h"

class EventPerkAttributeListComponent : public AttributeListComponent {
public:
	/**
	 * Fills the Attributes
	 * @pre { this object is locked }
	 * @post { this object is locked, menuResponse is complete}
	 * @param menuResponse ObjectMenuResponse that will be sent to the client
	 */
	void fillAttributeList(AttributeListMessage* alm, CreatureObject* player, SceneObject* sceneObject) const;
};

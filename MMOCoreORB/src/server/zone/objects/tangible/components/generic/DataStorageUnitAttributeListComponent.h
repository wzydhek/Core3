/*
 * DataStorageUnitAttributeListComponent.h
 *
 *  Created on: 11/8/2014
 *      Author: Klivian
 */

#pragma once

#include "server/zone/objects/tangible/components/generic/DataStorageUnitDataComponent.h"
#include "server/zone/objects/creature/CreatureObject.h"
#include "server/zone/objects/scene/components/AttributeListComponent.h"

class DataStorageUnitAttributeListComponent: public AttributeListComponent {
public:

	/**
	 * Fills the Attributes
	 * @pre { this object is locked }
	 * @post { this object is locked, menuResponse is complete}
	 * @param menuResponse ObjectMenuResponse that will be sent to the client
	 */
	void fillAttributeList(AttributeListMessage* alm, CreatureObject* player, SceneObject* sceneObject) const;

};

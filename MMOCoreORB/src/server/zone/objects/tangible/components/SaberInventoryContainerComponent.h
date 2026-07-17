/*
 * SaberInventoryContainerComponent.h
 *
 *  Created on: Apr 14, 2012
 *      Author: katherine
 */

#pragma once

#include "server/zone/objects/scene/components/ContainerComponent.h"

namespace server {
namespace zone {
namespace objects {
namespace tangible {
namespace components {

class SaberInventoryContainerComponent : public ContainerComponent {
public:

	/**
	 * Evaluates if this object has the necessary free slots to be able to add the specified SceneObject
	 * @pre { this object is locked, object is locked }
	 * @post {this object is locked, object is locked }
	 * @param object SceneObject that will be checked
	 * @param error error string that the player will receive on error
	 * @return returns 0 on success, or error code
	 */
	virtual int canAddObject(SceneObject* sceneObject, SceneObject* object, int containmentType, String& errorDescription) const;

	virtual bool checkContainerPermission(SceneObject* sceneObject, CreatureObject* creature, uint16 permission) const;

	/**
	 * Is called when this object has been inserted with an object
	 * @param object object that has been inserted
	 */
	virtual int notifyObjectInserted(SceneObject* sceneObject, SceneObject* object) const;

	/**
	 * Is called when an object was removed
	 * @param object object that has been inserted
	 */
	virtual int notifyObjectRemoved(SceneObject* sceneObject, SceneObject* object, SceneObject* destination) const;

};

} // namespace components
} // namespace tangible
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::tangible::components;

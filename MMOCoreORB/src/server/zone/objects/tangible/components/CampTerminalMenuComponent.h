/*
 * CampTerminalMenuComponent
 *
 *  Created on: 1/1/2012
 *      Author: kyle
 */

#pragma once

#include "TangibleObjectMenuComponent.h"
#include "server/zone/objects/area/CampSiteActiveArea.h"

namespace server {
namespace zone {
namespace objects {
namespace tangible {
namespace components {

class CampTerminalMenuComponent : public TangibleObjectMenuComponent {
public:
	/**
	 * Fills the radial options, needs to be overriden
	 * @pre { this object is locked }
	 * @post { this object is locked, menuResponse is complete}
	 * @param menuResponse ObjectMenuResponse that will be sent to the client
	 */
	virtual void fillObjectMenuResponse(SceneObject* sceneObject, ObjectMenuResponse* menuResponse, CreatureObject* player) const;

	/**
	 * Handles the radial selection sent by the client, must be overriden by inherited objects
	 * @pre { this object is locked, player is locked }
	 * @post { this object is locked, player is locked }
	 * @param player PlayerCreature that selected the option
	 * @param selectedID selected menu id
	 * @returns 0 if successfull
	 */
	virtual int handleObjectMenuSelect(SceneObject* sceneObject, CreatureObject* player, byte selectedID) const;

	void disbandCamp(SceneObject* sceneObject, CreatureObject* player) const;

	void assumeCampOwnership(SceneObject* sceneObject, CreatureObject* player) const;

	void showCampStatus(SceneObject* sceneObject, CreatureObject* player) const;

	void awardCampExperience(PlayerObject* ghost, CampSiteActiveArea* campArea) const;
};

} // namespace components
} // namespace tangible
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::tangible::components;

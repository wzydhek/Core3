/*
 * CityVotingMenuComponent.h
 *
 *  Created on: Feb 12, 2012
 *      Author: xyborn
 */

#pragma once

#include "server/zone/objects/scene/components/ObjectMenuComponent.h"

class CityVotingMenuComponent : public ObjectMenuComponent {
public:
	virtual void fillObjectMenuResponse(SceneObject* sceneObject, ObjectMenuResponse* menuResponse, CreatureObject* player) const;
	virtual int handleObjectMenuSelect(SceneObject* sceneObject, CreatureObject* player, byte selectedID) const;
};

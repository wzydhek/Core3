/*
 * ForceCrystalMenuComponent.h
 */

#pragma once

#include "TangibleObjectMenuComponent.h"

class ForceCrystalMenuComponent : public TangibleObjectMenuComponent {
public:
	virtual int handleObjectMenuSelect(SceneObject* sceneObject, CreatureObject* player, byte selectedID) const;

	virtual void fillObjectMenuResponse(SceneObject* sceneObject, ObjectMenuResponse* menuResponse, CreatureObject* player) const;

};

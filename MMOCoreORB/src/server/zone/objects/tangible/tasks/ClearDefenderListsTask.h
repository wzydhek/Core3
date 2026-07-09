/*
 * ClearDefenderLists.h
 *
 *  Created on: 10/04/2012
 *      Author: victor
 */

#pragma once

#include "server/zone/objects/tangible/TangibleObject.h"

class ClearDefenderListsTask : public Task {
	DeltaVector<ManagedReference<SceneObject* > > defenderList;
	ManagedReference<TangibleObject*> tangibleObject;
public:
	ClearDefenderListsTask(const DeltaVector<ManagedReference<SceneObject*>>& list, TangibleObject* tano);

	void run();
};

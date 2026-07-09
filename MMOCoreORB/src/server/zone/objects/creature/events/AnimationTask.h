/*
 * AnimationTask.h
 *
 *  Created on: 08/08/2010
 *      Author: victor
 */

#pragma once

#include "server/zone/objects/creature/CreatureObject.h"

class AnimationTask : public Task {
	ManagedReference<CreatureObject*> creature;
	String animation;
public:
	AnimationTask(CreatureObject* creo, const String& anim);

	void run();
};

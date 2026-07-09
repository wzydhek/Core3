/*
 				Copyright <SWGEmu>
		See file COPYING for copying conditions. */


#pragma once

#include "engine/engine.h"
#include "server/zone/objects/creature/CreatureObject.h"

class ForceMeditateTask: public Task {
	ManagedReference<CreatureObject*> player;
	String moodString;

public:
	ForceMeditateTask(CreatureObject* pl);

	void setMoodString(const String& ms);

	String getMoodString();

	void run();

};

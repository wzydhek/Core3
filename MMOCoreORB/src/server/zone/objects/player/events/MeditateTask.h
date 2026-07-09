/*
 				Copyright <SWGEmu>
		See file COPYING for copying conditions. */

/**
 * \file MeditateTask.h
 * \author Polonel
 * \date 08.04.2010
 */

#pragma once

#include "engine/engine.h"
#include "server/chat/StringIdChatParameter.h"
#include "server/zone/objects/creature/CreatureObject.h"
#include "templates/params/creature/CreatureAttribute.h"

class MeditateTask: public Task {
	ManagedReference<CreatureObject*> player;
	String moodString;

public:
	MeditateTask(CreatureObject* pl);

	void setMoodString(const String& ms);

	String getMoodString();

	void run();

};

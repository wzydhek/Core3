/*
 * MissionTerminalTemplate.h
 *
 *  Created on: 21/06/2010
 *      Author: victor
 */

#pragma once

#include "templates/SharedTangibleObjectTemplate.h"

class MissionTerminalTemplate : public SharedTangibleObjectTemplate {
	String missionTerminalType;

public:
	MissionTerminalTemplate();

	~MissionTerminalTemplate();

	void readObject(LuaObject* templateData);

	String& getMissionTerminalType();

	bool isMissionTerminalTemplate();
};

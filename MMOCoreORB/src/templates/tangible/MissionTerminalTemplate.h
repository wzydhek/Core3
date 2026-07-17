/*
 * MissionTerminalTemplate.h
 *
 *  Created on: 21/06/2010
 *      Author: victor
 */

#pragma once

#include "templates/SharedTangibleObjectTemplate.h"

namespace templates {
namespace tangible {

class MissionTerminalTemplate : public SharedTangibleObjectTemplate {
	String missionTerminalType;

public:
	MissionTerminalTemplate();

	~MissionTerminalTemplate();

	void readObject(LuaObject* templateData);

	String& getMissionTerminalType();

	bool isMissionTerminalTemplate();
};

} // namespace tangible
} // namespace templates

using namespace templates::tangible;

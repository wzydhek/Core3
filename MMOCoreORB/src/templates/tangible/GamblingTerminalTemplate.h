/*
 * GamblingTerminalTemplate.h
 *
 *  Created on: May 7, 2010
 *      Author: swgemu
 */

#pragma once

#include "templates/SharedTangibleObjectTemplate.h"

namespace templates {
namespace tangible {

class GamblingTerminalTemplate : public SharedTangibleObjectTemplate {
	int machineType;

public:
	GamblingTerminalTemplate();

	~GamblingTerminalTemplate();

	void readObject(LuaObject* templateData);

    int getMachineType() const;

    void setMachineType(int machineType);

	bool isGamblingTerminalTemplate();
};


} // namespace tangible
} // namespace templates

using namespace templates::tangible;

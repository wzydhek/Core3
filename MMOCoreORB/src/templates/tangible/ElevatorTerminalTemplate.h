/*
 * ElevatorTerminalTemplate.h
 *
 *  Created on: March 15, 2011
 *      Author: crush
 */

#pragma once

#include "templates/SharedTangibleObjectTemplate.h"

namespace templates {
namespace tangible {

class ElevatorTerminalTemplate : public SharedTangibleObjectTemplate {
	byte movementType;

public:
	enum {
		UPONLY    = 0x00,
		DOWNONLY  = 0x01,
		UPANDDOWN = 0x02
	};

public:
	ElevatorTerminalTemplate();

	~ElevatorTerminalTemplate();

	void readObject(LuaObject* templateData);

	byte getMovementType();

	bool isMovingUp();

	bool isMovingDown();
};

} // namespace tangible
} // namespace templates

using namespace templates::tangible;

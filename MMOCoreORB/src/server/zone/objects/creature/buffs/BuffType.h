/*
 * BuffType.h
 *
 *  Created on: 03/06/2010
 *      Author: victor
 */

#pragma once

#include "../BuffAttribute.h"
#include "BuffCRC.h"

class BuffType {
public:
	enum {
		OTHER,
		FOOD,
		MEDICAL,
		PERFORMANCE,
		SPICE,
		SKILL,
		JEDI,
		INNATE,
		STATE,
		TRAP
	};
};

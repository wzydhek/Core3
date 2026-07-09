/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/engine.h"

class BuffAttribute {
public:
	enum {
		HEALTH,
		STRENGTH,
		CONSTITUTION,
		ACTION,
		QUICKNESS,
		STAMINA,
		MIND,
		FOCUS,
		WILLPOWER,
		POISON,
		DISEASE,
		UNKNOWN
	};

	//TODO: This entire class needs to be removed. Posion and Disease are not attributes.
	//THEY ARE SKILLMODS
	static const uint8 ARRAYSIZE = 11;

	static bool isHAM(uint8 attribute);

	static bool isProtection(uint8 attribute);

	static String getProtectionString(uint8 attribute);

	static String getAbsorptionString(uint8 attribute);

	static uint8 getAttribute(String attribute);

	static String getName(const uint8 attribute, bool initialCap = false);
};

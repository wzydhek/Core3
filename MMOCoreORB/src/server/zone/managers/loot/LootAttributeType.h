#pragma once

#include "server/zone/objects/tangible/TangibleObject.h"

class LootAttributeType {
public:
	enum RandomType : uint32 {
		STATIC,
		UNIFORM,
		DYNAMIC,
		NORMAL,
		SIZE,
	};

	static String randomTypeToString(uint32 type);

	static int getAttributeType(uint32 objectType, const String& attribute);

	static int getComponentAttributeType(uint32 objectType, const String& attribute);

	static int getObjectAttributeType(uint32 objectType, const String& attribute);
};
